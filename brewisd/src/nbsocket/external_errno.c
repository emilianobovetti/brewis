#include <errno.h>

#include <string.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value errno_E2BIG(value unit) { return Val_int (E2BIG); }
CAMLprim value errno_EACCES(value unit) { return Val_int (EACCES); }
CAMLprim value errno_EADDRINUSE(value unit) { return Val_int (EADDRINUSE); }
CAMLprim value errno_EADDRNOTAVAIL(value unit) { return Val_int (EADDRNOTAVAIL); }
CAMLprim value errno_EAFNOSUPPORT(value unit) { return Val_int (EAFNOSUPPORT); }
CAMLprim value errno_EAGAIN(value unit) { return Val_int (EAGAIN); }
CAMLprim value errno_EALREADY(value unit) { return Val_int (EALREADY); }
CAMLprim value errno_EBADE(value unit) { return Val_int (EBADE); }
CAMLprim value errno_EBADF(value unit) { return Val_int (EBADF); }
CAMLprim value errno_EBADFD(value unit) { return Val_int (EBADFD); }
CAMLprim value errno_EBADMSG(value unit) { return Val_int (EBADMSG); }
CAMLprim value errno_EBADR(value unit) { return Val_int (EBADR); }
CAMLprim value errno_EBADRQC(value unit) { return Val_int (EBADRQC); }
CAMLprim value errno_EBADSLT(value unit) { return Val_int (EBADSLT); }
CAMLprim value errno_EBUSY(value unit) { return Val_int (EBUSY); }
CAMLprim value errno_ECANCELED(value unit) { return Val_int (ECANCELED); }
CAMLprim value errno_ECHILD(value unit) { return Val_int (ECHILD); }
CAMLprim value errno_ECHRNG(value unit) { return Val_int (ECHRNG); }
CAMLprim value errno_ECOMM(value unit) { return Val_int (ECOMM); }
CAMLprim value errno_ECONNABORTED(value unit) { return Val_int (ECONNABORTED); }
CAMLprim value errno_ECONNREFUSED(value unit) { return Val_int (ECONNREFUSED); }
CAMLprim value errno_ECONNRESET(value unit) { return Val_int (ECONNRESET); }
CAMLprim value errno_EDEADLK(value unit) { return Val_int (EDEADLK); }
CAMLprim value errno_EDEADLOCK(value unit) { return Val_int (EDEADLOCK); }
CAMLprim value errno_EDESTADDRREQ(value unit) { return Val_int (EDESTADDRREQ); }
CAMLprim value errno_EDOM(value unit) { return Val_int (EDOM); }
CAMLprim value errno_EDQUOT(value unit) { return Val_int (EDQUOT); }
CAMLprim value errno_EEXIST(value unit) { return Val_int (EEXIST); }
CAMLprim value errno_EFAULT(value unit) { return Val_int (EFAULT); }
CAMLprim value errno_EFBIG(value unit) { return Val_int (EFBIG); }
CAMLprim value errno_EHOSTDOWN(value unit) { return Val_int (EHOSTDOWN); }
CAMLprim value errno_EHOSTUNREACH(value unit) { return Val_int (EHOSTUNREACH); }
CAMLprim value errno_EIDRM(value unit) { return Val_int (EIDRM); }
CAMLprim value errno_EILSEQ(value unit) { return Val_int (EILSEQ); }
CAMLprim value errno_EINPROGRESS(value unit) { return Val_int (EINPROGRESS); }
CAMLprim value errno_EINTR(value unit) { return Val_int (EINTR); }
CAMLprim value errno_EINVAL(value unit) { return Val_int (EINVAL); }
CAMLprim value errno_EIO(value unit) { return Val_int (EIO); }
CAMLprim value errno_EISCONN(value unit) { return Val_int (EISCONN); }
CAMLprim value errno_EISDIR(value unit) { return Val_int (EISDIR); }
CAMLprim value errno_EISNAM(value unit) { return Val_int (EISNAM); }
CAMLprim value errno_EKEYEXPIRED(value unit) { return Val_int (EKEYEXPIRED); }
CAMLprim value errno_EKEYREJECTED(value unit) { return Val_int (EKEYREJECTED); }
CAMLprim value errno_EKEYREVOKED(value unit) { return Val_int (EKEYREVOKED); }
CAMLprim value errno_EL2HLT(value unit) { return Val_int (EL2HLT); }
CAMLprim value errno_EL2NSYNC(value unit) { return Val_int (EL2NSYNC); }
CAMLprim value errno_EL3HLT(value unit) { return Val_int (EL3HLT); }
CAMLprim value errno_EL3RST(value unit) { return Val_int (EL3RST); }
CAMLprim value errno_ELIBACC(value unit) { return Val_int (ELIBACC); }
CAMLprim value errno_ELIBBAD(value unit) { return Val_int (ELIBBAD); }
CAMLprim value errno_ELIBMAX(value unit) { return Val_int (ELIBMAX); }
CAMLprim value errno_ELIBSCN(value unit) { return Val_int (ELIBSCN); }
CAMLprim value errno_ELIBEXEC(value unit) { return Val_int (ELIBEXEC); }
CAMLprim value errno_ELOOP(value unit) { return Val_int (ELOOP); }
CAMLprim value errno_EMEDIUMTYPE(value unit) { return Val_int (EMEDIUMTYPE); }
CAMLprim value errno_EMFILE(value unit) { return Val_int (EMFILE); }
CAMLprim value errno_EMLINK(value unit) { return Val_int (EMLINK); }
CAMLprim value errno_EMSGSIZE(value unit) { return Val_int (EMSGSIZE); }
CAMLprim value errno_EMULTIHOP(value unit) { return Val_int (EMULTIHOP); }
CAMLprim value errno_ENAMETOOLONG(value unit) { return Val_int (ENAMETOOLONG); }
CAMLprim value errno_ENETDOWN(value unit) { return Val_int (ENETDOWN); }
CAMLprim value errno_ENETRESET(value unit) { return Val_int (ENETRESET); }
CAMLprim value errno_ENETUNREACH(value unit) { return Val_int (ENETUNREACH); }
CAMLprim value errno_ENFILE(value unit) { return Val_int (ENFILE); }
CAMLprim value errno_ENOBUFS(value unit) { return Val_int (ENOBUFS); }
CAMLprim value errno_ENODATA(value unit) { return Val_int (ENODATA); }
CAMLprim value errno_ENODEV(value unit) { return Val_int (ENODEV); }
CAMLprim value errno_ENOENT(value unit) { return Val_int (ENOENT); }
CAMLprim value errno_ENOEXEC(value unit) { return Val_int (ENOEXEC); }
CAMLprim value errno_ENOKEY(value unit) { return Val_int (ENOKEY); }
CAMLprim value errno_ENOLCK(value unit) { return Val_int (ENOLCK); }
CAMLprim value errno_ENOLINK(value unit) { return Val_int (ENOLINK); }
CAMLprim value errno_ENOMEDIUM(value unit) { return Val_int (ENOMEDIUM); }
CAMLprim value errno_ENOMEM(value unit) { return Val_int (ENOMEM); }
CAMLprim value errno_ENOMSG(value unit) { return Val_int (ENOMSG); }
CAMLprim value errno_ENONET(value unit) { return Val_int (ENONET); }
CAMLprim value errno_ENOPKG(value unit) { return Val_int (ENOPKG); }
CAMLprim value errno_ENOPROTOOPT(value unit) { return Val_int (ENOPROTOOPT); }
CAMLprim value errno_ENOSPC(value unit) { return Val_int (ENOSPC); }
CAMLprim value errno_ENOSR(value unit) { return Val_int (ENOSR); }
CAMLprim value errno_ENOSTR(value unit) { return Val_int (ENOSTR); }
CAMLprim value errno_ENOSYS(value unit) { return Val_int (ENOSYS); }
CAMLprim value errno_ENOTBLK(value unit) { return Val_int (ENOTBLK); }
CAMLprim value errno_ENOTCONN(value unit) { return Val_int (ENOTCONN); }
CAMLprim value errno_ENOTDIR(value unit) { return Val_int (ENOTDIR); }
CAMLprim value errno_ENOTEMPTY(value unit) { return Val_int (ENOTEMPTY); }
CAMLprim value errno_ENOTSOCK(value unit) { return Val_int (ENOTSOCK); }
CAMLprim value errno_ENOTSUP(value unit) { return Val_int (ENOTSUP); }
CAMLprim value errno_ENOTTY(value unit) { return Val_int (ENOTTY); }
CAMLprim value errno_ENOTUNIQ(value unit) { return Val_int (ENOTUNIQ); }
CAMLprim value errno_ENXIO(value unit) { return Val_int (ENXIO); }
CAMLprim value errno_EOPNOTSUPP(value unit) { return Val_int (EOPNOTSUPP); }
CAMLprim value errno_EOVERFLOW(value unit) { return Val_int (EOVERFLOW); }
CAMLprim value errno_EPERM(value unit) { return Val_int (EPERM); }
CAMLprim value errno_EPFNOSUPPORT(value unit) { return Val_int (EPFNOSUPPORT); }
CAMLprim value errno_EPIPE(value unit) { return Val_int (EPIPE); }
CAMLprim value errno_EPROTO(value unit) { return Val_int (EPROTO); }
CAMLprim value errno_EPROTONOSUPPORT(value unit) { return Val_int (EPROTONOSUPPORT); }
CAMLprim value errno_EPROTOTYPE(value unit) { return Val_int (EPROTOTYPE); }
CAMLprim value errno_ERANGE(value unit) { return Val_int (ERANGE); }
CAMLprim value errno_EREMCHG(value unit) { return Val_int (EREMCHG); }
CAMLprim value errno_EREMOTE(value unit) { return Val_int (EREMOTE); }
CAMLprim value errno_EREMOTEIO(value unit) { return Val_int (EREMOTEIO); }
CAMLprim value errno_ERESTART(value unit) { return Val_int (ERESTART); }
CAMLprim value errno_EROFS(value unit) { return Val_int (EROFS); }
CAMLprim value errno_ESHUTDOWN(value unit) { return Val_int (ESHUTDOWN); }
CAMLprim value errno_ESPIPE(value unit) { return Val_int (ESPIPE); }
CAMLprim value errno_ESOCKTNOSUPPORT(value unit) { return Val_int (ESOCKTNOSUPPORT); }
CAMLprim value errno_ESRCH(value unit) { return Val_int (ESRCH); }
CAMLprim value errno_ESTALE(value unit) { return Val_int (ESTALE); }
CAMLprim value errno_ESTRPIPE(value unit) { return Val_int (ESTRPIPE); }
CAMLprim value errno_ETIME(value unit) { return Val_int (ETIME); }
CAMLprim value errno_ETIMEDOUT(value unit) { return Val_int (ETIMEDOUT); }
CAMLprim value errno_ETXTBSY(value unit) { return Val_int (ETXTBSY); }
CAMLprim value errno_EUCLEAN(value unit) { return Val_int (EUCLEAN); }
CAMLprim value errno_EUNATCH(value unit) { return Val_int (EUNATCH); }
CAMLprim value errno_EUSERS(value unit) { return Val_int (EUSERS); }
CAMLprim value errno_EWOULDBLOCK(value unit) { return Val_int (EWOULDBLOCK); }
CAMLprim value errno_EXDEV(value unit) { return Val_int (EXDEV); }
CAMLprim value errno_EXFULL(value unit) { return Val_int (EXFULL); }

CAMLprim value errno_to_string(value err)
{
    CAMLparam1 (err);

    CAMLreturn (caml_copy_string(strerror(Int_val (err))));
}
