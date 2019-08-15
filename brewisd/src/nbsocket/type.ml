
type t =
    | SOCK_STREAM | SOCK_DGRAM | SOCK_RAW | SOCK_RDM
    | SOCK_SEQPACKET | SOCK_DCCP | SOCK_PACKET
    | SOCK_CLOEXEC | SOCK_NONBLOCK

external type_SOCK_STREAM : unit -> int = "type_SOCK_STREAM"
external type_SOCK_DGRAM : unit -> int = "type_SOCK_DGRAM"
external type_SOCK_RAW : unit -> int = "type_SOCK_RAW"
external type_SOCK_RDM : unit -> int = "type_SOCK_RDM"
external type_SOCK_SEQPACKET : unit -> int = "type_SOCK_SEQPACKET"
external type_SOCK_DCCP : unit -> int = "type_SOCK_DCCP"
external type_SOCK_PACKET : unit -> int = "type_SOCK_PACKET"
external type_SOCK_CLOEXEC : unit -> int = "type_SOCK_CLOEXEC"
external type_SOCK_NONBLOCK : unit -> int = "type_SOCK_NONBLOCK"

let to_int = function
    | SOCK_STREAM -> type_SOCK_STREAM ()
    | SOCK_DGRAM -> type_SOCK_DGRAM ()
    | SOCK_RAW -> type_SOCK_RAW ()
    | SOCK_RDM -> type_SOCK_RDM ()
    | SOCK_SEQPACKET -> type_SOCK_SEQPACKET ()
    | SOCK_DCCP -> type_SOCK_DCCP ()
    | SOCK_PACKET -> type_SOCK_PACKET ()
    | SOCK_CLOEXEC -> type_SOCK_CLOEXEC ()
    | SOCK_NONBLOCK -> type_SOCK_NONBLOCK ()
