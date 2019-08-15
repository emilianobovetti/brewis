
type t =
    | PF_UNSPEC | PF_LOCAL | PF_UNIX | PF_FILE | PF_INET
    | PF_AX25 | PF_IPX | PF_APPLETALK | PF_NETROM | PF_BRIDGE
    | PF_ATMPVC | PF_X25 | PF_INET6 | PF_ROSE | PF_DECnet
    | PF_NETBEUI | PF_SECURITY | PF_KEY | PF_NETLINK | PF_ROUTE
    | PF_PACKET | PF_ASH | PF_ECONET | PF_ATMSVC | PF_RDS
    | PF_SNA | PF_IRDA | PF_PPPOX | PF_WANPIPE | PF_LLC
    | PF_CAN | PF_TIPC | PF_BLUETOOTH | PF_IUCV | PF_RXRPC
    | PF_ISDN | PF_PHONET | PF_IEEE802154 | PF_CAIF | PF_ALG
    | PF_NFC | PF_VSOCK

external domain_PF_UNSPEC : unit -> int = "domain_PF_UNSPEC"
external domain_PF_LOCAL : unit -> int = "domain_PF_LOCAL"
external domain_PF_UNIX : unit -> int = "domain_PF_UNIX"
external domain_PF_FILE : unit -> int = "domain_PF_FILE"
external domain_PF_INET : unit -> int = "domain_PF_INET"
external domain_PF_AX25 : unit -> int = "domain_PF_AX25"
external domain_PF_IPX : unit -> int = "domain_PF_IPX"
external domain_PF_APPLETALK : unit -> int = "domain_PF_APPLETALK"
external domain_PF_NETROM : unit -> int = "domain_PF_NETROM"
external domain_PF_BRIDGE : unit -> int = "domain_PF_BRIDGE"
external domain_PF_ATMPVC : unit -> int = "domain_PF_ATMPVC"
external domain_PF_X25 : unit -> int = "domain_PF_X25"
external domain_PF_INET6 : unit -> int = "domain_PF_INET6"
external domain_PF_ROSE : unit -> int = "domain_PF_ROSE"
external domain_PF_DECnet : unit -> int = "domain_PF_DECnet"
external domain_PF_NETBEUI : unit -> int = "domain_PF_NETBEUI"
external domain_PF_SECURITY : unit -> int = "domain_PF_SECURITY"
external domain_PF_KEY : unit -> int = "domain_PF_KEY"
external domain_PF_NETLINK : unit -> int = "domain_PF_NETLINK"
external domain_PF_ROUTE : unit -> int = "domain_PF_ROUTE"
external domain_PF_PACKET : unit -> int = "domain_PF_PACKET"
external domain_PF_ASH : unit -> int = "domain_PF_ASH"
external domain_PF_ECONET : unit -> int = "domain_PF_ECONET"
external domain_PF_ATMSVC : unit -> int = "domain_PF_ATMSVC"
external domain_PF_RDS : unit -> int = "domain_PF_RDS"
external domain_PF_SNA : unit -> int = "domain_PF_SNA"
external domain_PF_IRDA : unit -> int = "domain_PF_IRDA"
external domain_PF_PPPOX : unit -> int = "domain_PF_PPPOX"
external domain_PF_WANPIPE : unit -> int = "domain_PF_WANPIPE"
external domain_PF_LLC : unit -> int = "domain_PF_LLC"
external domain_PF_CAN : unit -> int = "domain_PF_CAN"
external domain_PF_TIPC : unit -> int = "domain_PF_TIPC"
external domain_PF_BLUETOOTH : unit -> int = "domain_PF_BLUETOOTH"
external domain_PF_IUCV : unit -> int = "domain_PF_IUCV"
external domain_PF_RXRPC : unit -> int = "domain_PF_RXRPC"
external domain_PF_ISDN : unit -> int = "domain_PF_ISDN"
external domain_PF_PHONET : unit -> int = "domain_PF_PHONET"
external domain_PF_IEEE802154 : unit -> int = "domain_PF_IEEE802154"
external domain_PF_CAIF : unit -> int = "domain_PF_CAIF"
external domain_PF_ALG : unit -> int = "domain_PF_ALG"
external domain_PF_NFC : unit -> int = "domain_PF_NFC"
external domain_PF_VSOCK : unit -> int = "domain_PF_VSOCK"

let to_int = function
    | PF_UNSPEC -> domain_PF_UNSPEC ()
    | PF_LOCAL -> domain_PF_LOCAL ()
    | PF_UNIX -> domain_PF_UNIX ()
    | PF_FILE -> domain_PF_FILE ()
    | PF_INET -> domain_PF_INET ()
    | PF_AX25 -> domain_PF_AX25 ()
    | PF_IPX -> domain_PF_IPX ()
    | PF_APPLETALK -> domain_PF_APPLETALK ()
    | PF_NETROM -> domain_PF_NETROM ()
    | PF_BRIDGE -> domain_PF_BRIDGE ()
    | PF_ATMPVC -> domain_PF_ATMPVC ()
    | PF_X25 -> domain_PF_X25 ()
    | PF_INET6 -> domain_PF_INET6 ()
    | PF_ROSE -> domain_PF_ROSE ()
    | PF_DECnet -> domain_PF_DECnet ()
    | PF_NETBEUI -> domain_PF_NETBEUI ()
    | PF_SECURITY -> domain_PF_SECURITY ()
    | PF_KEY -> domain_PF_KEY ()
    | PF_NETLINK -> domain_PF_NETLINK ()
    | PF_ROUTE -> domain_PF_ROUTE ()
    | PF_PACKET -> domain_PF_PACKET ()
    | PF_ASH -> domain_PF_ASH ()
    | PF_ECONET -> domain_PF_ECONET ()
    | PF_ATMSVC -> domain_PF_ATMSVC ()
    | PF_RDS -> domain_PF_RDS ()
    | PF_SNA -> domain_PF_SNA ()
    | PF_IRDA -> domain_PF_IRDA ()
    | PF_PPPOX -> domain_PF_PPPOX ()
    | PF_WANPIPE -> domain_PF_WANPIPE ()
    | PF_LLC -> domain_PF_LLC ()
    | PF_CAN -> domain_PF_CAN ()
    | PF_TIPC -> domain_PF_TIPC ()
    | PF_BLUETOOTH -> domain_PF_BLUETOOTH ()
    | PF_IUCV -> domain_PF_IUCV ()
    | PF_RXRPC -> domain_PF_RXRPC ()
    | PF_ISDN -> domain_PF_ISDN ()
    | PF_PHONET -> domain_PF_PHONET ()
    | PF_IEEE802154 -> domain_PF_IEEE802154 ()
    | PF_CAIF -> domain_PF_CAIF ()
    | PF_ALG -> domain_PF_ALG ()
    | PF_NFC -> domain_PF_NFC ()
    | PF_VSOCK -> domain_PF_VSOCK ()
