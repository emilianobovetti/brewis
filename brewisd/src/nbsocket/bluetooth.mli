
module Protocol : sig
    type t = Protocol.t

    val l2cap : t
    val hci : t
    val sco : t
    val rfcomm : t
    val bnep : t
    val cmtp : t
    val hidp : t
    val avdtp : t
end

val connect : Unix.file_descr -> Address.t -> [ `Error of Errno.t | `Ok ]
