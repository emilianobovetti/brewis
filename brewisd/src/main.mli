open Async
open Nbsocket

exception Fatal_error

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

(*
 * log system
 *)
val log_message : string -> unit
val log_error : string -> unit
val log_errno : string -> [ `Ok | `Error of Errno.t ] -> unit
val debug : string -> unit

(*
 * Web tasks
 *)
val web_listen : app_state -> task
val web_authenticate : app_state -> task
val web_refresh : app_state -> task

(*
 * Web event handlers
 *)
val web_on_authenticate : app_state -> app_state * task list
val web_on_receive : app_state -> string -> app_state * task list
val web_on_forward_completed : app_state -> app_state * task list
val web_on_expire : app_state ->  app_state * task list
val web_on_refresh : app_state ->  app_state * task list

(*
 * Arduino tasks
 *)
val arduino_connect : app_state -> task
val arduino_listen : app_state -> task
val forward_measurements_to_web : app_state -> string -> task
val forward_response_to_web : app_state -> string -> task

(*
 * Arduino event handlers
 *)
val arduino_on_connect : app_state -> app_state * task list
val arduino_on_disconnect : app_state -> app_state * task list
val arduino_on_receive : app_state -> string -> app_state * task list
val arduino_on_forward_completed : app_state -> app_state * task list

(*
 * runtime system
 *)
val main_loop : app_state -> event -> task list -> unit Deferred.t

val schedule : app_state -> task list -> unit Deferred.t
