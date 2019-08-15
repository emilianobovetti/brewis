#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#include <caml/mlvalues.h>

CAMLprim value bluetooth_BTPROTO_L2CAP(value unit) { return Val_int (BTPROTO_L2CAP); }
CAMLprim value bluetooth_BTPROTO_HCI(value unit) { return Val_int (BTPROTO_HCI); }
CAMLprim value bluetooth_BTPROTO_SCO(value unit) { return Val_int (BTPROTO_SCO); }
CAMLprim value bluetooth_BTPROTO_RFCOMM(value unit) { return Val_int (BTPROTO_RFCOMM); }
CAMLprim value bluetooth_BTPROTO_BNEP(value unit) { return Val_int (BTPROTO_BNEP); }
CAMLprim value bluetooth_BTPROTO_CMTP(value unit) { return Val_int (BTPROTO_CMTP); }
CAMLprim value bluetooth_BTPROTO_HIDP(value unit) { return Val_int (BTPROTO_HIDP); }
CAMLprim value bluetooth_BTPROTO_AVDTP(value unit) { return Val_int (BTPROTO_AVDTP); }

/*
 * bluetooth_connect : int -> string -> int -> int
 *
 * return 0 on success, errno for errors
 */
CAMLprim value bluetooth_connect(value socket_desc, value dest_addr, value channel)
{
    struct sockaddr_rc addr = { 0 };
    char *dest = String_val (dest_addr);
    int desc = Int_val (socket_desc);
    int chan = Int_val (channel);
    int result = 0;

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) chan;

    if (chan < 0 || chan > 255)
    {
        result = EINVAL; // Invalid channel
    }
    else if (str2ba(dest, &addr.rc_bdaddr) == -1)
    {
        result = EINVAL; // Invalid destination address
    }
    else if (connect(desc, (struct sockaddr *) &addr, sizeof addr) == -1)
    {
        result = errno;
    }

    return Val_int (result);
}
