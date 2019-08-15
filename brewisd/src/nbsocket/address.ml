
type t =
    [ `Bluetooth of string * int
    | `Inet of Unix.inet_addr * int
    | `Unix of string ]
