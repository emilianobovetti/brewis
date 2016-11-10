open Async.Std

type t

val create : Domain.t -> Type.t -> Protocol.t -> [ `Error of Errno.t | `Ok of t ]

val renew : t -> [ `Error of Errno.t | `Ok of t ]

val errno : t -> [ `Error of Errno.t | `Ok ]

val readable : t -> [ `Failed | `Ok | `Idle ]

val writable : t -> [ `Failed | `Ok | `Idle ]

val connect : t -> Address.t -> [ `Error of Errno.t | `Ok ]

val connection_loop :
    t -> Address.t -> Core.Std.Time.Span.t -> [ `Error of Errno.t | `Ok ] Deferred.t

val read :
    ?buffer_size:int ->
    t -> [ `Error of Errno.t | `EOF | `Ok of string ]

val read_until :
    ?buffer_size:int ->
    ?poll_interval:Core.Std.Time.Span.t ->
    t -> string -> [ `Error of Errno.t | `Ok of string ] Deferred.t

val write :
    ?poll_interval:Core.Std.Time.Span.t ->
    t -> string -> [ `Error of Errno.t | `Ok ] Deferred.t

val close : t -> unit
