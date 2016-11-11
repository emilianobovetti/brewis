
exception Fatal_error

(*
 * Create daemon working directory
 *)
let rec mkdir_p dir perm =
    if Sys.file_exists dir then ()
    else (mkdir_p (Filename.dirname dir) perm; Unix.mkdir dir perm)

let () = mkdir_p Config.working_directory 0o700

(*
 * Create pidfile
 *)
let _ = Async.Std.Lock_file.create ~unlink_on_exit:true Config.daemon_pidfile

(*
 * log system
 *)
let log output_fn msg =
    let open Unix in
    let t = gettimeofday () |> localtime in
    let datetime = Printf.sprintf "%d/%d/%d %d:%d:%d"
        t.tm_mday (1 + t.tm_mon) (1900 + t.tm_year) t.tm_hour t.tm_min t.tm_sec in
    Printf.sprintf "[%s] %s" datetime msg
    |> output_fn

let log_message = log print_endline

let log_error = log prerr_endline

let log_errno description errno =
    log_error (description ^ ": " ^ Errno.to_string errno)

let debug =
    if Config.debugging_mode then log_message else fun msg -> ()

(*
 * Signal handling
 *)
let handle_signal (s : int) (f : int -> unit) =
    let open Sys in set_signal s (Signal_handle f)

let () = begin
    handle_signal Sys.sigterm (fun _ -> log_message "SIGTERM caught"; exit 0);
    handle_signal Sys.sigint (fun _ -> log_message "SIGINT caught"; exit 0);

    at_exit (fun () -> log_message "exiting");
end

(*
 * TODO target_name/target_address approach
 *
 * https://people.csail.mit.edu/albert/bluez-intro/c404.html
 *)

open Async.Std

type base_state = [ `Offline | `Listening | `Forwarding ]

type arduino_state = [ base_state | `WaitForACK | `WaitForResponse ]

type web_state = base_state

type a_dev = Nbsocket.t

type w_dev = Jwt_session.t

type app_state =
    { a_state   : arduino_state;
      a_dev     : a_dev;
      a_command : string option;
      w_state   : web_state;
      w_dev     : w_dev;
    }

type event =
    | ArduinoDisconnected
    | ArduinoConnected
    | ArduinoReceived of string
    | ArduinoForwardCompleted
    | WebAuthenticated of w_dev
    | WebReceived of string
    | WebForwardCompleted
    | WebExpired
    | WebRefreshed of w_dev

type task = event Deferred.t

let bt_address = `Bluetooth (Config.bluetooth_address, Config.bluetooth_channel)
let bt_connection_interval = Core.Span.create ~sec:3 () (* TODO default: 6 *)
let web_authentication_interval = Core.Span.create ~sec:5 ()

(*
 * Web tasks
 *)
let rec web_listen = function { w_dev; _ } as s ->
    Jwt_session.get w_dev "longpolling/command/dequeue"
    >>= fun (response, body) ->
    Cohttp_async.Body.to_string body
    >>= fun body ->
    let open Yojson in let open Basic in
    let json = try from_string body with Json_error _ -> `Assoc [] in
    match Util.member "command" json with
    | `String cmd ->
        debug ("longpolling/command/dequeue response body: " ^ body);
        return (WebReceived cmd)
    | _ -> web_listen s

let rec web_authenticate = function { w_dev; _ } as s ->
    Jwt_session.authenticate w_dev "authenticate"
    >>= function
    | `Ok w_dev -> return (WebAuthenticated w_dev)
    | `Error e ->
        log_error ("Error during web authentication: " ^ e ^ ", retrying...");
        after web_authentication_interval >>= fun () -> web_authenticate s

let web_timeout s =
    after Config.jwt_refresh_interval >>| fun () -> WebExpired

let web_refresh = function { w_dev; _ } as s ->
    Jwt_session.refresh w_dev "token/refresh"
    >>= function
    | `Ok w_dev -> return (WebRefreshed w_dev)
    | `Error e ->
        log_error ("Error during token/refresh request: " ^ e ^ ", reauthenticating...");
        web_authenticate s

(*
 * Web event handlers
 *)
let web_on_authenticate s =
    let s = { s with w_state = `Listening } in
    s, [ web_listen s; web_timeout s ]

let web_on_receive s cmd =
    let { a_state; a_dev; _ } = s in
    match a_state with
    | `Listening ->
        (* send GET_ACK command and wait for response *)
        ignore (Nbsocket.write a_dev "0\r");
        { s with
            a_state = `WaitForACK;
            w_state = `Forwarding;
            a_command = Some cmd;
        }, []
    | _ ->
        debug "Web received, but Arduino is not listening";
        let s = { s with w_state = `Listening } in
        s, [ web_listen s ]

let web_on_forward_completed s =
    let s = { s with w_state = `Listening } in
    s, [ web_listen s ]

let web_on_expire s =
    s, [ web_refresh s ]

let web_on_refresh s =
    s, [ web_timeout s ]

(*
 * Arduino tasks
 *)
let arduino_connect { a_dev; _ } =
    Nbsocket.connection_loop a_dev bt_address bt_connection_interval
    >>| function
    | `Ok -> ArduinoConnected
    | `Error _ as e ->
        log_errno "Error during arduino connection" e;
        ArduinoDisconnected

let arduino_listen { a_dev; _ } =
    Nbsocket.read_until a_dev Config.message_terminator
    >>| function
    | `Ok msg -> ArduinoReceived msg
    | `Error _ as e ->
        log_errno "Error during arduino listening" e;
        ArduinoDisconnected

let forward_measurements_to_web { w_dev; _ } msg =
    let json = `Assoc [ "measurements", `String msg ] in
    Jwt_session.post ~body:json w_dev "measurements/upload"
    >>= fun (response, body) ->
    Cohttp_async.Body.to_string body
    >>| fun body ->
    debug ("measurements/upload response body:" ^ body);
    ArduinoForwardCompleted

let forward_response_to_web { w_dev; _ } msg =
    let json = `Assoc [ "response", `String msg ] in
    Jwt_session.post ~body:json w_dev "command/response"
    >>= fun (response, body) ->
    Cohttp_async.Body.to_string body
    >>| fun body ->
    debug ("command/response response body:" ^ body);
    WebForwardCompleted

(*
 * Arduino event handlers
 *)
let arduino_on_connect s =
    let s = { s with a_state = `Listening } in
    s, [ arduino_listen s ]

let arduino_on_disconnect s =
    let s = { s with a_state = `Offline } in
    s, [ arduino_connect s ]

let arduino_on_receive s msg =
    let { a_state; a_dev; a_command; _ } = s in
    match a_state, a_command with
    | `WaitForACK, Some cmd when Util.String.contains msg "ACK" ->
        (* Send command to Arduino *)
        ignore (Nbsocket.write a_dev cmd);
        let s = { s with
                  a_state = `WaitForResponse;
                  a_command = None;
                }
        in s, [ arduino_listen s ]
    | `WaitForACK, Some cmd ->
        debug "Waiting for ACK, keep listening";
        s, [ arduino_listen s ]
    | `WaitForACK, None ->
        debug "ACK received, but no command enqueued";
        let s = { s with
                  a_state = `Listening;
                  w_state = `Listening;
                }
        in s, [ arduino_listen s; web_listen s ]
    | `WaitForResponse, _ ->
        let s = { s with a_state = `Listening } in
        s, [ forward_response_to_web s msg; arduino_listen s ]
    | `Listening, _ ->
        let s = { s with a_state = `Forwarding } in
        s, [ forward_measurements_to_web s msg ]
    | `Forwarding, _ ->
        debug "Arduino received, but is already forwarding";
        s, [ arduino_listen s ]
    | `Offline, _ ->
        log_error "Arduino received but with offline state";
        raise Fatal_error

let arduino_on_forward_completed s =
    let s = { s with a_state = `Listening } in
    s, [ arduino_listen s ]

(*Test system*)
let string_of_event = function
    | ArduinoConnected -> "Arduino connected"
    | ArduinoDisconnected -> "Arduino disconnected"
    | ArduinoReceived _ -> "Arduino received"
    | ArduinoForwardCompleted -> "Arduino forward completed"
    | WebAuthenticated _ -> "Web authenticated"
    | WebReceived _ -> "Web received"
    | WebForwardCompleted -> "Web forward completed"
    | WebExpired -> "Web session expired"
    | WebRefreshed _ -> "Web session refreshed"
(*
 * runtime system
 *)
let rec main_loop s event task_lst =
    debug ("Event log: " ^ string_of_event event);
    let s, tasks = match event with
    | ArduinoConnected -> arduino_on_connect s
    | ArduinoDisconnected -> arduino_on_disconnect s
    | ArduinoReceived msg -> arduino_on_receive s msg
    | ArduinoForwardCompleted -> arduino_on_forward_completed s
    | WebAuthenticated w_dev -> web_on_authenticate { s with w_dev }
    | WebReceived msg -> web_on_receive s msg
    | WebForwardCompleted -> web_on_forward_completed s
    | WebExpired -> web_on_expire s
    | WebRefreshed w_dev -> web_on_refresh { s with w_dev }
    in
    schedule s (task_lst@tasks)
and schedule state task_lst =
    debug ("Scheduled tasks: " ^ string_of_int (List.length task_lst));
    let rec loop = function
    | [], [] -> log_error "No tasks to schedule"; raise Fatal_error
    | [], acc -> []
    | hd::tl, acc ->
        let call_main_loop event =
            main_loop state event (acc@tl) |> ignore
        in
        choice hd call_main_loop :: loop (tl, hd::acc)
    in
    loop (task_lst, []) |> choose

(* Bootstrap *)

let a_dev =
    let open Domain in let open Type in let open Bluetooth in
    match Nbsocket.create PF_BLUETOOTH SOCK_STREAM Protocol.rfcomm with
    | `Error _ as e -> log_errno "Failed to create bluetooth socket" e; raise Fatal_error
    | `Ok a_dev -> a_dev

let w_dev =
    let open Config in
    Jwt_session.create base_url [ "name", auth_name; "password", auth_password ]

let state =
    { a_state = `Offline; a_dev; a_command = None;
      w_state = `Offline; w_dev;
    }

let _ = schedule state [ arduino_connect state; web_authenticate state ]

(* Async scheduler *)
let _ = Scheduler.go ()
