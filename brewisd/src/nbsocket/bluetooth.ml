
external bluetooth_BTPROTO_L2CAP : unit -> int = "bluetooth_BTPROTO_L2CAP"
external bluetooth_BTPROTO_HCI : unit -> int = "bluetooth_BTPROTO_HCI"
external bluetooth_BTPROTO_SCO : unit -> int = "bluetooth_BTPROTO_SCO"
external bluetooth_BTPROTO_RFCOMM : unit -> int = "bluetooth_BTPROTO_RFCOMM"
external bluetooth_BTPROTO_BNEP : unit -> int = "bluetooth_BTPROTO_BNEP"
external bluetooth_BTPROTO_CMTP : unit -> int = "bluetooth_BTPROTO_CMTP"
external bluetooth_BTPROTO_HIDP : unit -> int = "bluetooth_BTPROTO_HIDP"
external bluetooth_BTPROTO_AVDTP : unit -> int = "bluetooth_BTPROTO_AVDTP"

module Protocol = struct
    type t = Protocol.t

    let l2cap = bluetooth_BTPROTO_L2CAP ()
    let hci = bluetooth_BTPROTO_HCI ()
    let sco = bluetooth_BTPROTO_SCO ()
    let rfcomm = bluetooth_BTPROTO_RFCOMM ()
    let bnep = bluetooth_BTPROTO_BNEP ()
    let cmtp = bluetooth_BTPROTO_CMTP ()
    let hidp = bluetooth_BTPROTO_HIDP ()
    let avdtp = bluetooth_BTPROTO_AVDTP ()
end

external bluetooth_connect : Unix.file_descr -> string -> int -> int = "bluetooth_connect"

let connect desc = function
    | `Bluetooth (dev, chan) -> bluetooth_connect desc dev chan |> Errno.of_int
    | _ -> raise (Invalid_argument "Invalid address type for bluetooth connection")
