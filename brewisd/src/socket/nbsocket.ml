
type t =
    { dom : Domain.t;
      typ : Type.t;
      proto : Protocol.t;
      desc : Unix.file_descr;
    }

external nbsocket_create : int -> int -> int -> int * Unix.file_descr = "nbsocket_create"
external nbsocket_get_errno : Unix.file_descr -> int = "nbsocket_get_errno"
external nbsocket_readable : Unix.file_descr -> int = "nbsocket_readable"
external nbsocket_writable : Unix.file_descr -> int = "nbsocket_writable"
external nbsocket_read : Unix.file_descr -> int -> int * int * string = "nbsocket_read"
external nbsocket_write : Unix.file_descr -> string -> int -> int * int = "nbsocket_write"
external nbsocket_close : Unix.file_descr -> unit = "nbsocket_close"

open Async.Std

let create dom typ proto =
    let e, desc = nbsocket_create (Domain.to_int dom) (Type.to_int typ) proto in
    match Errno.of_int e with
    | `Error _ as e -> e
    | `Ok -> `Ok { dom; typ; proto; desc }

let errno { desc; _ } =
    Errno.of_int (nbsocket_get_errno desc)

let readable { desc; _ } =
    match nbsocket_readable desc with
    | -1 -> `Failed
    | 0 -> `Idle
    | n -> `Ok

let writable { desc; _ } =
    match nbsocket_writable desc with
    | -1 -> `Failed
    | 0 -> `Idle
    | n -> `Ok

let connect { desc; dom; _ } addr =
    let open Domain in
    match dom with
    | PF_BLUETOOTH -> Bluetooth.connect desc addr
    | _ -> failwith "not implemented" (* TODO *)

let read ?(buffer_size=63) { desc; _ } =
    let e, len, msg = nbsocket_read desc buffer_size in
    match Errno.of_int e, len, msg with
    | `Error _ as e, _, _ -> e
    | `Ok, 0, _ -> `EOF
    | `Ok, _, msg -> `Ok msg

let read_until ?(buffer_size=63) ?(poll_interval=Core.Std.Time.Span.second) t terminator =
    let rec delayed_loop acc=
        after poll_interval >>= fun () -> loop acc
    and loop acc =
        let open Errno in
        match read t ~buffer_size with
        | `EOF | `Error EAGAIN | `Error EWOULDBLOCK -> delayed_loop acc
        | `Error _ as e -> return e
        | `Ok msg ->
            let acc = acc ^ msg in
            if Util.String.contains acc terminator then
                return (`Ok acc)
            else
                delayed_loop acc
    in
    loop ""

let rec write ?(poll_interval=Core.Std.Time.Span.millisecond) t msg =
    let { desc; _ } = t in
    let len = String.length msg in
    let e, out_len = nbsocket_write desc msg len in
    match Errno.of_int e with
    | `Error _ as e -> return e
    | `Ok ->
        if len = out_len then
            return `Ok
        else
            after poll_interval >>= fun () ->
            String.sub msg out_len (len - out_len)
            |> write ~poll_interval t

let close { desc; _ } =
    nbsocket_close desc

let renew = function { dom; typ; proto; _ } as t ->
    let () = close t in create dom typ proto

let connection_loop t addr connection_interval =
    let open Errno in
    let rec retry t =
        match renew t with
        | `Ok t -> connection_attempt t
        | `Error _ as e -> return e
    and connection_attempt t =
        match connect t addr with
        | `Ok | `Error EINPROGRESS ->
            after connection_interval
            >>= fun () -> writability_check t
        | `Error _ -> retry t
    and writability_check t =
        match writable t with
        | `Failed -> retry t
        | `Idle ->
            after connection_interval
            >>= fun () -> writability_check t
        | `Ok ->
            after Core.Time.Span.second (*TODO how much delay?*)
            >>= fun () -> status_check t
    and status_check t =
        match errno t with
        | `Error _ -> retry t
        | `Ok -> return `Ok
    in
    connection_attempt t
