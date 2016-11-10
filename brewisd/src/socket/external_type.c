#include <sys/types.h>
#include <sys/socket.h>

#include <caml/mlvalues.h>

CAMLprim value type_SOCK_STREAM(value unit) { return Val_int (SOCK_STREAM); }
CAMLprim value type_SOCK_DGRAM(value unit) { return Val_int (SOCK_DGRAM); }
CAMLprim value type_SOCK_RAW(value unit) { return Val_int (SOCK_RAW); }
CAMLprim value type_SOCK_RDM(value unit) { return Val_int (SOCK_RDM); }
CAMLprim value type_SOCK_SEQPACKET(value unit) { return Val_int (SOCK_SEQPACKET); }
CAMLprim value type_SOCK_DCCP(value unit) { return Val_int (SOCK_DCCP); }
CAMLprim value type_SOCK_PACKET(value unit) { return Val_int (SOCK_PACKET); }
CAMLprim value type_SOCK_CLOEXEC(value unit) { return Val_int (SOCK_CLOEXEC); }
CAMLprim value type_SOCK_NONBLOCK(value unit) { return Val_int (SOCK_NONBLOCK); }
