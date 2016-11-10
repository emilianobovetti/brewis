#include <sys/types.h>
#include <sys/socket.h>

#include <caml/mlvalues.h>

CAMLprim value domain_PF_UNSPEC(value unit) { return Val_int (PF_UNSPEC); }
CAMLprim value domain_PF_LOCAL(value unit) { return Val_int (PF_LOCAL); }
CAMLprim value domain_PF_UNIX(value unit) { return Val_int (PF_UNIX); }
CAMLprim value domain_PF_FILE(value unit) { return Val_int (PF_FILE); }
CAMLprim value domain_PF_INET(value unit) { return Val_int (PF_INET); }
CAMLprim value domain_PF_AX25(value unit) { return Val_int (PF_AX25); }
CAMLprim value domain_PF_IPX(value unit) { return Val_int (PF_IPX); }
CAMLprim value domain_PF_APPLETALK(value unit) { return Val_int (PF_APPLETALK); }
CAMLprim value domain_PF_NETROM(value unit) { return Val_int (PF_NETROM); }
CAMLprim value domain_PF_BRIDGE(value unit) { return Val_int (PF_BRIDGE); }
CAMLprim value domain_PF_ATMPVC(value unit) { return Val_int (PF_ATMPVC); }
CAMLprim value domain_PF_X25(value unit) { return Val_int (PF_X25); }
CAMLprim value domain_PF_INET6(value unit) { return Val_int (PF_INET6); }
CAMLprim value domain_PF_ROSE(value unit) { return Val_int (PF_ROSE); }
CAMLprim value domain_PF_DECnet(value unit) { return Val_int (PF_DECnet); }
CAMLprim value domain_PF_NETBEUI(value unit) { return Val_int (PF_NETBEUI); }
CAMLprim value domain_PF_SECURITY(value unit) { return Val_int (PF_SECURITY); }
CAMLprim value domain_PF_KEY(value unit) { return Val_int (PF_KEY); }
CAMLprim value domain_PF_NETLINK(value unit) { return Val_int (PF_NETLINK); }
CAMLprim value domain_PF_ROUTE(value unit) { return Val_int (PF_ROUTE); }
CAMLprim value domain_PF_PACKET(value unit) { return Val_int (PF_PACKET); }
CAMLprim value domain_PF_ASH(value unit) { return Val_int (PF_ASH); }
CAMLprim value domain_PF_ECONET(value unit) { return Val_int (PF_ECONET); }
CAMLprim value domain_PF_ATMSVC(value unit) { return Val_int (PF_ATMSVC); }
CAMLprim value domain_PF_RDS(value unit) { return Val_int (PF_RDS); }
CAMLprim value domain_PF_SNA(value unit) { return Val_int (PF_SNA); }
CAMLprim value domain_PF_IRDA(value unit) { return Val_int (PF_IRDA); }
CAMLprim value domain_PF_PPPOX(value unit) { return Val_int (PF_PPPOX); }
CAMLprim value domain_PF_WANPIPE(value unit) { return Val_int (PF_WANPIPE); }
CAMLprim value domain_PF_LLC(value unit) { return Val_int (PF_LLC); }
CAMLprim value domain_PF_CAN(value unit) { return Val_int (PF_CAN); }
CAMLprim value domain_PF_TIPC(value unit) { return Val_int (PF_TIPC); }
CAMLprim value domain_PF_BLUETOOTH(value unit) { return Val_int (PF_BLUETOOTH); }
CAMLprim value domain_PF_IUCV(value unit) { return Val_int (PF_IUCV); }
CAMLprim value domain_PF_RXRPC(value unit) { return Val_int (PF_RXRPC); }
CAMLprim value domain_PF_ISDN(value unit) { return Val_int (PF_ISDN); }
CAMLprim value domain_PF_PHONET(value unit) { return Val_int (PF_PHONET); }
CAMLprim value domain_PF_IEEE802154(value unit) { return Val_int (PF_IEEE802154); }
CAMLprim value domain_PF_CAIF(value unit) { return Val_int (PF_CAIF); }
CAMLprim value domain_PF_ALG(value unit) { return Val_int (PF_ALG); }
CAMLprim value domain_PF_NFC(value unit) { return Val_int (PF_NFC); }
CAMLprim value domain_PF_VSOCK(value unit) { return Val_int (PF_VSOCK); }
