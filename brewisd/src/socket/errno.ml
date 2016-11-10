
type t =
    | E2BIG | EACCES | EADDRINUSE | EADDRNOTAVAIL | EAFNOSUPPORT
    | EAGAIN | EALREADY | EBADE | EBADF | EBADFD
    | EBADMSG | EBADR | EBADRQC | EBADSLT | EBUSY
    | ECANCELED | ECHILD | ECHRNG | ECOMM | ECONNABORTED
    | ECONNREFUSED | ECONNRESET | EDEADLK | EDEADLOCK | EDESTADDRREQ
    | EDOM | EDQUOT | EEXIST | EFAULT | EFBIG
    | EHOSTDOWN | EHOSTUNREACH | EIDRM | EILSEQ | EINPROGRESS
    | EINTR | EINVAL | EIO | EISCONN | EISDIR
    | EISNAM | EKEYEXPIRED | EKEYREJECTED | EKEYREVOKED | EL2HLT
    | EL2NSYNC | EL3HLT | EL3RST | ELIBACC | ELIBBAD
    | ELIBMAX | ELIBSCN | ELIBEXEC | ELOOP | EMEDIUMTYPE
    | EMFILE | EMLINK | EMSGSIZE | EMULTIHOP | ENAMETOOLONG
    | ENETDOWN | ENETRESET | ENETUNREACH | ENFILE | ENOBUFS
    | ENODATA | ENODEV | ENOENT | ENOEXEC | ENOKEY
    | ENOLCK | ENOLINK | ENOMEDIUM | ENOMEM | ENOMSG
    | ENONET | ENOPKG | ENOPROTOOPT | ENOSPC | ENOSR
    | ENOSTR | ENOSYS | ENOTBLK | ENOTCONN | ENOTDIR
    | ENOTEMPTY | ENOTSOCK | ENOTSUP | ENOTTY | ENOTUNIQ
    | ENXIO | EOPNOTSUPP | EOVERFLOW | EPERM | EPFNOSUPPORT
    | EPIPE | EPROTO | EPROTONOSUPPORT | EPROTOTYPE | ERANGE
    | EREMCHG | EREMOTE | EREMOTEIO | ERESTART | EROFS
    | ESHUTDOWN | ESPIPE | ESOCKTNOSUPPORT | ESRCH | ESTALE
    | ESTRPIPE | ETIME | ETIMEDOUT | ETXTBSY | EUCLEAN
    | EUNATCH | EUSERS | EWOULDBLOCK | EXDEV | EXFULL

external errno_E2BIG : unit -> int = "errno_E2BIG"
external errno_EACCES : unit -> int = "errno_EACCES"
external errno_EADDRINUSE : unit -> int = "errno_EADDRINUSE"
external errno_EADDRNOTAVAIL : unit -> int = "errno_EADDRNOTAVAIL"
external errno_EAFNOSUPPORT : unit -> int = "errno_EAFNOSUPPORT"
external errno_EAGAIN : unit -> int = "errno_EAGAIN"
external errno_EALREADY : unit -> int = "errno_EALREADY"
external errno_EBADE : unit -> int = "errno_EBADE"
external errno_EBADF : unit -> int = "errno_EBADF"
external errno_EBADFD : unit -> int = "errno_EBADFD"
external errno_EBADMSG : unit -> int = "errno_EBADMSG"
external errno_EBADR : unit -> int = "errno_EBADR"
external errno_EBADRQC : unit -> int = "errno_EBADRQC"
external errno_EBADSLT : unit -> int = "errno_EBADSLT"
external errno_EBUSY : unit -> int = "errno_EBUSY"
external errno_ECANCELED : unit -> int = "errno_ECANCELED"
external errno_ECHILD : unit -> int = "errno_ECHILD"
external errno_ECHRNG : unit -> int = "errno_ECHRNG"
external errno_ECOMM : unit -> int = "errno_ECOMM"
external errno_ECONNABORTED : unit -> int = "errno_ECONNABORTED"
external errno_ECONNREFUSED : unit -> int = "errno_ECONNREFUSED"
external errno_ECONNRESET : unit -> int = "errno_ECONNRESET"
external errno_EDEADLK : unit -> int = "errno_EDEADLK"
external errno_EDEADLOCK : unit -> int = "errno_EDEADLOCK"
external errno_EDESTADDRREQ : unit -> int = "errno_EDESTADDRREQ"
external errno_EDOM : unit -> int = "errno_EDOM"
external errno_EDQUOT : unit -> int = "errno_EDQUOT"
external errno_EEXIST : unit -> int = "errno_EEXIST"
external errno_EFAULT : unit -> int = "errno_EFAULT"
external errno_EFBIG : unit -> int = "errno_EFBIG"
external errno_EHOSTDOWN : unit -> int = "errno_EHOSTDOWN"
external errno_EHOSTUNREACH : unit -> int = "errno_EHOSTUNREACH"
external errno_EIDRM : unit -> int = "errno_EIDRM"
external errno_EILSEQ : unit -> int = "errno_EILSEQ"
external errno_EINPROGRESS : unit -> int = "errno_EINPROGRESS"
external errno_EINTR : unit -> int = "errno_EINTR"
external errno_EINVAL : unit -> int = "errno_EINVAL"
external errno_EIO : unit -> int = "errno_EIO"
external errno_EISCONN : unit -> int = "errno_EISCONN"
external errno_EISDIR : unit -> int = "errno_EISDIR"
external errno_EISNAM : unit -> int = "errno_EISNAM"
external errno_EKEYEXPIRED : unit -> int = "errno_EKEYEXPIRED"
external errno_EKEYREJECTED : unit -> int = "errno_EKEYREJECTED"
external errno_EKEYREVOKED : unit -> int = "errno_EKEYREVOKED"
external errno_EL2HLT : unit -> int = "errno_EL2HLT"
external errno_EL2NSYNC : unit -> int = "errno_EL2NSYNC"
external errno_EL3HLT : unit -> int = "errno_EL3HLT"
external errno_EL3RST : unit -> int = "errno_EL3RST"
external errno_ELIBACC : unit -> int = "errno_ELIBACC"
external errno_ELIBBAD : unit -> int = "errno_ELIBBAD"
external errno_ELIBMAX : unit -> int = "errno_ELIBMAX"
external errno_ELIBSCN : unit -> int = "errno_ELIBSCN"
external errno_ELIBEXEC : unit -> int = "errno_ELIBEXEC"
external errno_ELOOP : unit -> int = "errno_ELOOP"
external errno_EMEDIUMTYPE : unit -> int = "errno_EMEDIUMTYPE"
external errno_EMFILE : unit -> int = "errno_EMFILE"
external errno_EMLINK : unit -> int = "errno_EMLINK"
external errno_EMSGSIZE : unit -> int = "errno_EMSGSIZE"
external errno_EMULTIHOP : unit -> int = "errno_EMULTIHOP"
external errno_ENAMETOOLONG : unit -> int = "errno_ENAMETOOLONG"
external errno_ENETDOWN : unit -> int = "errno_ENETDOWN"
external errno_ENETRESET : unit -> int = "errno_ENETRESET"
external errno_ENETUNREACH : unit -> int = "errno_ENETUNREACH"
external errno_ENFILE : unit -> int = "errno_ENFILE"
external errno_ENOBUFS : unit -> int = "errno_ENOBUFS"
external errno_ENODATA : unit -> int = "errno_ENODATA"
external errno_ENODEV : unit -> int = "errno_ENODEV"
external errno_ENOENT : unit -> int = "errno_ENOENT"
external errno_ENOEXEC : unit -> int = "errno_ENOEXEC"
external errno_ENOKEY : unit -> int = "errno_ENOKEY"
external errno_ENOLCK : unit -> int = "errno_ENOLCK"
external errno_ENOLINK : unit -> int = "errno_ENOLINK"
external errno_ENOMEDIUM : unit -> int = "errno_ENOMEDIUM"
external errno_ENOMEM : unit -> int = "errno_ENOMEM"
external errno_ENOMSG : unit -> int = "errno_ENOMSG"
external errno_ENONET : unit -> int = "errno_ENONET"
external errno_ENOPKG : unit -> int = "errno_ENOPKG"
external errno_ENOPROTOOPT : unit -> int = "errno_ENOPROTOOPT"
external errno_ENOSPC : unit -> int = "errno_ENOSPC"
external errno_ENOSR : unit -> int = "errno_ENOSR"
external errno_ENOSTR : unit -> int = "errno_ENOSTR"
external errno_ENOSYS : unit -> int = "errno_ENOSYS"
external errno_ENOTBLK : unit -> int = "errno_ENOTBLK"
external errno_ENOTCONN : unit -> int = "errno_ENOTCONN"
external errno_ENOTDIR : unit -> int = "errno_ENOTDIR"
external errno_ENOTEMPTY : unit -> int = "errno_ENOTEMPTY"
external errno_ENOTSOCK : unit -> int = "errno_ENOTSOCK"
external errno_ENOTSUP : unit -> int = "errno_ENOTSUP"
external errno_ENOTTY : unit -> int = "errno_ENOTTY"
external errno_ENOTUNIQ : unit -> int = "errno_ENOTUNIQ"
external errno_ENXIO : unit -> int = "errno_ENXIO"
external errno_EOPNOTSUPP : unit -> int = "errno_EOPNOTSUPP"
external errno_EOVERFLOW : unit -> int = "errno_EOVERFLOW"
external errno_EPERM : unit -> int = "errno_EPERM"
external errno_EPFNOSUPPORT : unit -> int = "errno_EPFNOSUPPORT"
external errno_EPIPE : unit -> int = "errno_EPIPE"
external errno_EPROTO : unit -> int = "errno_EPROTO"
external errno_EPROTONOSUPPORT : unit -> int = "errno_EPROTONOSUPPORT"
external errno_EPROTOTYPE : unit -> int = "errno_EPROTOTYPE"
external errno_ERANGE : unit -> int = "errno_ERANGE"
external errno_EREMCHG : unit -> int = "errno_EREMCHG"
external errno_EREMOTE : unit -> int = "errno_EREMOTE"
external errno_EREMOTEIO : unit -> int = "errno_EREMOTEIO"
external errno_ERESTART : unit -> int = "errno_ERESTART"
external errno_EROFS : unit -> int = "errno_EROFS"
external errno_ESHUTDOWN : unit -> int = "errno_ESHUTDOWN"
external errno_ESPIPE : unit -> int = "errno_ESPIPE"
external errno_ESOCKTNOSUPPORT : unit -> int = "errno_ESOCKTNOSUPPORT"
external errno_ESRCH : unit -> int = "errno_ESRCH"
external errno_ESTALE : unit -> int = "errno_ESTALE"
external errno_ESTRPIPE : unit -> int = "errno_ESTRPIPE"
external errno_ETIME : unit -> int = "errno_ETIME"
external errno_ETIMEDOUT : unit -> int = "errno_ETIMEDOUT"
external errno_ETXTBSY : unit -> int = "errno_ETXTBSY"
external errno_EUCLEAN : unit -> int = "errno_EUCLEAN"
external errno_EUNATCH : unit -> int = "errno_EUNATCH"
external errno_EUSERS : unit -> int = "errno_EUSERS"
external errno_EWOULDBLOCK : unit -> int = "errno_EWOULDBLOCK"
external errno_EXDEV : unit -> int = "errno_EXDEV"
external errno_EXFULL : unit -> int = "errno_EXFULL"

let ht = Hashtbl.create 121

let () = begin
    Hashtbl.add ht (errno_E2BIG ()) E2BIG;
    Hashtbl.add ht (errno_EACCES ()) EACCES;
    Hashtbl.add ht (errno_EADDRINUSE ()) EADDRINUSE;
    Hashtbl.add ht (errno_EADDRNOTAVAIL ()) EADDRNOTAVAIL;
    Hashtbl.add ht (errno_EAFNOSUPPORT ()) EAFNOSUPPORT;
    Hashtbl.add ht (errno_EAGAIN ()) EAGAIN;
    Hashtbl.add ht (errno_EALREADY ()) EALREADY;
    Hashtbl.add ht (errno_EBADE ()) EBADE;
    Hashtbl.add ht (errno_EBADF ()) EBADF;
    Hashtbl.add ht (errno_EBADFD ()) EBADFD;
    Hashtbl.add ht (errno_EBADMSG ()) EBADMSG;
    Hashtbl.add ht (errno_EBADR ()) EBADR;
    Hashtbl.add ht (errno_EBADRQC ()) EBADRQC;
    Hashtbl.add ht (errno_EBADSLT ()) EBADSLT;
    Hashtbl.add ht (errno_EBUSY ()) EBUSY;
    Hashtbl.add ht (errno_ECANCELED ()) ECANCELED;
    Hashtbl.add ht (errno_ECHILD ()) ECHILD;
    Hashtbl.add ht (errno_ECHRNG ()) ECHRNG;
    Hashtbl.add ht (errno_ECOMM ()) ECOMM;
    Hashtbl.add ht (errno_ECONNABORTED ()) ECONNABORTED;
    Hashtbl.add ht (errno_ECONNREFUSED ()) ECONNREFUSED;
    Hashtbl.add ht (errno_ECONNRESET ()) ECONNRESET;
    Hashtbl.add ht (errno_EDEADLK ()) EDEADLK;
    Hashtbl.add ht (errno_EDEADLOCK ()) EDEADLOCK;
    Hashtbl.add ht (errno_EDESTADDRREQ ()) EDESTADDRREQ;
    Hashtbl.add ht (errno_EDOM ()) EDOM;
    Hashtbl.add ht (errno_EDQUOT ()) EDQUOT;
    Hashtbl.add ht (errno_EEXIST ()) EEXIST;
    Hashtbl.add ht (errno_EFAULT ()) EFAULT;
    Hashtbl.add ht (errno_EFBIG ()) EFBIG;
    Hashtbl.add ht (errno_EHOSTDOWN ()) EHOSTDOWN;
    Hashtbl.add ht (errno_EHOSTUNREACH ()) EHOSTUNREACH;
    Hashtbl.add ht (errno_EIDRM ()) EIDRM;
    Hashtbl.add ht (errno_EILSEQ ()) EILSEQ;
    Hashtbl.add ht (errno_EINPROGRESS ()) EINPROGRESS;
    Hashtbl.add ht (errno_EINTR ()) EINTR;
    Hashtbl.add ht (errno_EINVAL ()) EINVAL;
    Hashtbl.add ht (errno_EIO ()) EIO;
    Hashtbl.add ht (errno_EISCONN ()) EISCONN;
    Hashtbl.add ht (errno_EISDIR ()) EISDIR;
    Hashtbl.add ht (errno_EISNAM ()) EISNAM;
    Hashtbl.add ht (errno_EKEYEXPIRED ()) EKEYEXPIRED;
    Hashtbl.add ht (errno_EKEYREJECTED ()) EKEYREJECTED;
    Hashtbl.add ht (errno_EKEYREVOKED ()) EKEYREVOKED;
    Hashtbl.add ht (errno_EL2HLT ()) EL2HLT;
    Hashtbl.add ht (errno_EL2NSYNC ()) EL2NSYNC;
    Hashtbl.add ht (errno_EL3HLT ()) EL3HLT;
    Hashtbl.add ht (errno_EL3RST ()) EL3RST;
    Hashtbl.add ht (errno_ELIBACC ()) ELIBACC;
    Hashtbl.add ht (errno_ELIBBAD ()) ELIBBAD;
    Hashtbl.add ht (errno_ELIBMAX ()) ELIBMAX;
    Hashtbl.add ht (errno_ELIBSCN ()) ELIBSCN;
    Hashtbl.add ht (errno_ELIBEXEC ()) ELIBEXEC;
    Hashtbl.add ht (errno_ELOOP ()) ELOOP;
    Hashtbl.add ht (errno_EMEDIUMTYPE ()) EMEDIUMTYPE;
    Hashtbl.add ht (errno_EMFILE ()) EMFILE;
    Hashtbl.add ht (errno_EMLINK ()) EMLINK;
    Hashtbl.add ht (errno_EMSGSIZE ()) EMSGSIZE;
    Hashtbl.add ht (errno_EMULTIHOP ()) EMULTIHOP;
    Hashtbl.add ht (errno_ENAMETOOLONG ()) ENAMETOOLONG;
    Hashtbl.add ht (errno_ENETDOWN ()) ENETDOWN;
    Hashtbl.add ht (errno_ENETRESET ()) ENETRESET;
    Hashtbl.add ht (errno_ENETUNREACH ()) ENETUNREACH;
    Hashtbl.add ht (errno_ENFILE ()) ENFILE;
    Hashtbl.add ht (errno_ENOBUFS ()) ENOBUFS;
    Hashtbl.add ht (errno_ENODATA ()) ENODATA;
    Hashtbl.add ht (errno_ENODEV ()) ENODEV;
    Hashtbl.add ht (errno_ENOENT ()) ENOENT;
    Hashtbl.add ht (errno_ENOEXEC ()) ENOEXEC;
    Hashtbl.add ht (errno_ENOKEY ()) ENOKEY;
    Hashtbl.add ht (errno_ENOLCK ()) ENOLCK;
    Hashtbl.add ht (errno_ENOLINK ()) ENOLINK;
    Hashtbl.add ht (errno_ENOMEDIUM ()) ENOMEDIUM;
    Hashtbl.add ht (errno_ENOMEM ()) ENOMEM;
    Hashtbl.add ht (errno_ENOMSG ()) ENOMSG;
    Hashtbl.add ht (errno_ENONET ()) ENONET;
    Hashtbl.add ht (errno_ENOPKG ()) ENOPKG;
    Hashtbl.add ht (errno_ENOPROTOOPT ()) ENOPROTOOPT;
    Hashtbl.add ht (errno_ENOSPC ()) ENOSPC;
    Hashtbl.add ht (errno_ENOSR ()) ENOSR;
    Hashtbl.add ht (errno_ENOSTR ()) ENOSTR;
    Hashtbl.add ht (errno_ENOSYS ()) ENOSYS;
    Hashtbl.add ht (errno_ENOTBLK ()) ENOTBLK;
    Hashtbl.add ht (errno_ENOTCONN ()) ENOTCONN;
    Hashtbl.add ht (errno_ENOTDIR ()) ENOTDIR;
    Hashtbl.add ht (errno_ENOTEMPTY ()) ENOTEMPTY;
    Hashtbl.add ht (errno_ENOTSOCK ()) ENOTSOCK;
    Hashtbl.add ht (errno_ENOTSUP ()) ENOTSUP;
    Hashtbl.add ht (errno_ENOTTY ()) ENOTTY;
    Hashtbl.add ht (errno_ENOTUNIQ ()) ENOTUNIQ;
    Hashtbl.add ht (errno_ENXIO ()) ENXIO;
    Hashtbl.add ht (errno_EOPNOTSUPP ()) EOPNOTSUPP;
    Hashtbl.add ht (errno_EOVERFLOW ()) EOVERFLOW;
    Hashtbl.add ht (errno_EPERM ()) EPERM;
    Hashtbl.add ht (errno_EPFNOSUPPORT ()) EPFNOSUPPORT;
    Hashtbl.add ht (errno_EPIPE ()) EPIPE;
    Hashtbl.add ht (errno_EPROTO ()) EPROTO;
    Hashtbl.add ht (errno_EPROTONOSUPPORT ()) EPROTONOSUPPORT;
    Hashtbl.add ht (errno_EPROTOTYPE ()) EPROTOTYPE;
    Hashtbl.add ht (errno_ERANGE ()) ERANGE;
    Hashtbl.add ht (errno_EREMCHG ()) EREMCHG;
    Hashtbl.add ht (errno_EREMOTE ()) EREMOTE;
    Hashtbl.add ht (errno_EREMOTEIO ()) EREMOTEIO;
    Hashtbl.add ht (errno_ERESTART ()) ERESTART;
    Hashtbl.add ht (errno_EROFS ()) EROFS;
    Hashtbl.add ht (errno_ESHUTDOWN ()) ESHUTDOWN;
    Hashtbl.add ht (errno_ESPIPE ()) ESPIPE;
    Hashtbl.add ht (errno_ESOCKTNOSUPPORT ()) ESOCKTNOSUPPORT;
    Hashtbl.add ht (errno_ESRCH ()) ESRCH;
    Hashtbl.add ht (errno_ESTALE ()) ESTALE;
    Hashtbl.add ht (errno_ESTRPIPE ()) ESTRPIPE;
    Hashtbl.add ht (errno_ETIME ()) ETIME;
    Hashtbl.add ht (errno_ETIMEDOUT ()) ETIMEDOUT;
    Hashtbl.add ht (errno_ETXTBSY ()) ETXTBSY;
    Hashtbl.add ht (errno_EUCLEAN ()) EUCLEAN;
    Hashtbl.add ht (errno_EUNATCH ()) EUNATCH;
    Hashtbl.add ht (errno_EUSERS ()) EUSERS;
    Hashtbl.add ht (errno_EWOULDBLOCK ()) EWOULDBLOCK;
    Hashtbl.add ht (errno_EXDEV ()) EXDEV;
    Hashtbl.add ht (errno_EXFULL ()) EXFULL;
end

let of_int = function
    | 0 -> `Ok
    | e -> `Error (Hashtbl.find ht e)

let to_int = function
    | `Ok -> 0
    | `Error E2BIG -> errno_E2BIG ()
    | `Error EACCES -> errno_EACCES ()
    | `Error EADDRINUSE -> errno_EADDRINUSE ()
    | `Error EADDRNOTAVAIL -> errno_EADDRNOTAVAIL ()
    | `Error EAFNOSUPPORT -> errno_EAFNOSUPPORT ()
    | `Error EAGAIN -> errno_EAGAIN ()
    | `Error EALREADY -> errno_EALREADY ()
    | `Error EBADE -> errno_EBADE ()
    | `Error EBADF -> errno_EBADF ()
    | `Error EBADFD -> errno_EBADFD ()
    | `Error EBADMSG -> errno_EBADMSG ()
    | `Error EBADR -> errno_EBADR ()
    | `Error EBADRQC -> errno_EBADRQC ()
    | `Error EBADSLT -> errno_EBADSLT ()
    | `Error EBUSY -> errno_EBUSY ()
    | `Error ECANCELED -> errno_ECANCELED ()
    | `Error ECHILD -> errno_ECHILD ()
    | `Error ECHRNG -> errno_ECHRNG ()
    | `Error ECOMM -> errno_ECOMM ()
    | `Error ECONNABORTED -> errno_ECONNABORTED ()
    | `Error ECONNREFUSED -> errno_ECONNREFUSED ()
    | `Error ECONNRESET -> errno_ECONNRESET ()
    | `Error EDEADLK -> errno_EDEADLK ()
    | `Error EDEADLOCK -> errno_EDEADLOCK ()
    | `Error EDESTADDRREQ -> errno_EDESTADDRREQ ()
    | `Error EDOM -> errno_EDOM ()
    | `Error EDQUOT -> errno_EDQUOT ()
    | `Error EEXIST -> errno_EEXIST ()
    | `Error EFAULT -> errno_EFAULT ()
    | `Error EFBIG -> errno_EFBIG ()
    | `Error EHOSTDOWN -> errno_EHOSTDOWN ()
    | `Error EHOSTUNREACH -> errno_EHOSTUNREACH ()
    | `Error EIDRM -> errno_EIDRM ()
    | `Error EILSEQ -> errno_EILSEQ ()
    | `Error EINPROGRESS -> errno_EINPROGRESS ()
    | `Error EINTR -> errno_EINTR ()
    | `Error EINVAL -> errno_EINVAL ()
    | `Error EIO -> errno_EIO ()
    | `Error EISCONN -> errno_EISCONN ()
    | `Error EISDIR -> errno_EISDIR ()
    | `Error EISNAM -> errno_EISNAM ()
    | `Error EKEYEXPIRED -> errno_EKEYEXPIRED ()
    | `Error EKEYREJECTED -> errno_EKEYREJECTED ()
    | `Error EKEYREVOKED -> errno_EKEYREVOKED ()
    | `Error EL2HLT -> errno_EL2HLT ()
    | `Error EL2NSYNC -> errno_EL2NSYNC ()
    | `Error EL3HLT -> errno_EL3HLT ()
    | `Error EL3RST -> errno_EL3RST ()
    | `Error ELIBACC -> errno_ELIBACC ()
    | `Error ELIBBAD -> errno_ELIBBAD ()
    | `Error ELIBMAX -> errno_ELIBMAX ()
    | `Error ELIBSCN -> errno_ELIBSCN ()
    | `Error ELIBEXEC -> errno_ELIBEXEC ()
    | `Error ELOOP -> errno_ELOOP ()
    | `Error EMEDIUMTYPE -> errno_EMEDIUMTYPE ()
    | `Error EMFILE -> errno_EMFILE ()
    | `Error EMLINK -> errno_EMLINK ()
    | `Error EMSGSIZE -> errno_EMSGSIZE ()
    | `Error EMULTIHOP -> errno_EMULTIHOP ()
    | `Error ENAMETOOLONG -> errno_ENAMETOOLONG ()
    | `Error ENETDOWN -> errno_ENETDOWN ()
    | `Error ENETRESET -> errno_ENETRESET ()
    | `Error ENETUNREACH -> errno_ENETUNREACH ()
    | `Error ENFILE -> errno_ENFILE ()
    | `Error ENOBUFS -> errno_ENOBUFS ()
    | `Error ENODATA -> errno_ENODATA ()
    | `Error ENODEV -> errno_ENODEV ()
    | `Error ENOENT -> errno_ENOENT ()
    | `Error ENOEXEC -> errno_ENOEXEC ()
    | `Error ENOKEY -> errno_ENOKEY ()
    | `Error ENOLCK -> errno_ENOLCK ()
    | `Error ENOLINK -> errno_ENOLINK ()
    | `Error ENOMEDIUM -> errno_ENOMEDIUM ()
    | `Error ENOMEM -> errno_ENOMEM ()
    | `Error ENOMSG -> errno_ENOMSG ()
    | `Error ENONET -> errno_ENONET ()
    | `Error ENOPKG -> errno_ENOPKG ()
    | `Error ENOPROTOOPT -> errno_ENOPROTOOPT ()
    | `Error ENOSPC -> errno_ENOSPC ()
    | `Error ENOSR -> errno_ENOSR ()
    | `Error ENOSTR -> errno_ENOSTR ()
    | `Error ENOSYS -> errno_ENOSYS ()
    | `Error ENOTBLK -> errno_ENOTBLK ()
    | `Error ENOTCONN -> errno_ENOTCONN ()
    | `Error ENOTDIR -> errno_ENOTDIR ()
    | `Error ENOTEMPTY -> errno_ENOTEMPTY ()
    | `Error ENOTSOCK -> errno_ENOTSOCK ()
    | `Error ENOTSUP -> errno_ENOTSUP ()
    | `Error ENOTTY -> errno_ENOTTY ()
    | `Error ENOTUNIQ -> errno_ENOTUNIQ ()
    | `Error ENXIO -> errno_ENXIO ()
    | `Error EOPNOTSUPP -> errno_EOPNOTSUPP ()
    | `Error EOVERFLOW -> errno_EOVERFLOW ()
    | `Error EPERM -> errno_EPERM ()
    | `Error EPFNOSUPPORT -> errno_EPFNOSUPPORT ()
    | `Error EPIPE -> errno_EPIPE ()
    | `Error EPROTO -> errno_EPROTO ()
    | `Error EPROTONOSUPPORT -> errno_EPROTONOSUPPORT ()
    | `Error EPROTOTYPE -> errno_EPROTOTYPE ()
    | `Error ERANGE -> errno_ERANGE ()
    | `Error EREMCHG -> errno_EREMCHG ()
    | `Error EREMOTE -> errno_EREMOTE ()
    | `Error EREMOTEIO -> errno_EREMOTEIO ()
    | `Error ERESTART -> errno_ERESTART ()
    | `Error EROFS -> errno_EROFS ()
    | `Error ESHUTDOWN -> errno_ESHUTDOWN ()
    | `Error ESPIPE -> errno_ESPIPE ()
    | `Error ESOCKTNOSUPPORT -> errno_ESOCKTNOSUPPORT ()
    | `Error ESRCH -> errno_ESRCH ()
    | `Error ESTALE -> errno_ESTALE ()
    | `Error ESTRPIPE -> errno_ESTRPIPE ()
    | `Error ETIME -> errno_ETIME ()
    | `Error ETIMEDOUT -> errno_ETIMEDOUT ()
    | `Error ETXTBSY -> errno_ETXTBSY ()
    | `Error EUCLEAN -> errno_EUCLEAN ()
    | `Error EUNATCH -> errno_EUNATCH ()
    | `Error EUSERS -> errno_EUSERS ()
    | `Error EWOULDBLOCK -> errno_EWOULDBLOCK ()
    | `Error EXDEV -> errno_EXDEV ()
    | `Error EXFULL -> errno_EXFULL ()

external errno_to_string : int -> string = "errno_to_string"

let to_string errno = errno |> to_int |> errno_to_string
