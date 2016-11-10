#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>

/*
 * nbsocket_create : int -> int -> int -> int * Unix.file_descr
 */
CAMLprim value nbsocket_create(value dom, value typ, value proto)
{
    CAMLparam3 (dom, typ, proto);
    CAMLlocal1 (pair);

    pair = caml_alloc_tuple(2);

    Store_field (pair, 0, Val_int (0));

    int desc = socket(Int_val (dom), Int_val (typ), Int_val (proto));

    if (desc == -1)
    {
        Store_field (pair, 0, Val_int (errno));
    }

    int fcntl_status = fcntl(desc, F_SETFL, fcntl(desc, F_GETFL, 0) | O_NONBLOCK);

    if (desc != -1 && fcntl_status == -1)
    {
        Store_field (pair, 0, Val_int (errno));
    }

    Store_field (pair, 1, Val_int (desc));

    CAMLreturn (pair);
}

/*
 * nbsocket_get_errno : Unix.file_descr -> int
 *
 * Raises Failure on error
 */
CAMLprim value nbsocket_get_errno(value socket_desc)
{
    int desc = Int_val (socket_desc);
    int optlen, optval = 0;

    if (getsockopt(desc, SOL_SOCKET, SO_ERROR, &optval, &optlen) == -1)
    {
        caml_failwith("getsockopt()"); // TODO errno
    }

    return Val_int(optval);
}

int nbsocket_select(int desc, fd_set * readfds, fd_set * writefds, fd_set * exceptfds)
{
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    // TODO
    // if (desc < 0)
    // if (desc >= FD_SETSIZE)

    if (readfds != NULL)
    {
        FD_ZERO(readfds);
        FD_SET(desc, readfds);
    }

    if (writefds != NULL)
    {
        FD_ZERO(writefds);
        FD_SET(desc, writefds);
    }

    if (exceptfds != NULL)
    {
        FD_ZERO(exceptfds);
        FD_SET(desc, exceptfds);
    }

    return select(desc + 1, readfds, writefds, exceptfds, &timeout);
}

/*
 * nbsocket_readable : Unix.file_descr -> int
 */
CAMLprim value nbsocket_readable(value socket_desc)
{
    int desc = Int_val (socket_desc);
    fd_set readfds;

    return Val_int (nbsocket_select(desc, &readfds, NULL, NULL));
}

/*
 * nbsocket_writable : Unix.file_descr -> int
 */
CAMLprim value nbsocket_writable(value socket_desc)
{
    int desc = Int_val (socket_desc);
    fd_set writefds;

    return Val_int (nbsocket_select(desc, NULL, &writefds, NULL));
}

/*
 * nbsocket_read : Unix.file_descr -> int -> int * int * string
 *
 * Reads up to buffer_len bytes from buffer,
 * returns (errno, status, message)
 *
 * status can be, num of bytes read, -1 for errors or 0 for EOF
 */
CAMLprim value nbsocket_read(value socket_desc, value buffer_len)
{
    CAMLparam2 (socket_desc, buffer_len);
    CAMLlocal2 (message, triple);

    triple = caml_alloc_tuple(3);

    int desc = Int_val (socket_desc);
    size_t b_len = Unsigned_int_val (buffer_len); // <= SSIZE_MAX

    char * buffer = malloc(b_len + 1);
    memset(buffer, 0, b_len + 1);

    int res = read(desc, buffer, b_len);

    if (res == -1)
    {
        Store_field (triple, 0, Val_int (errno));
    }
    else
    {
        Store_field (triple, 0, Val_int (0));
    }

    message = caml_copy_string(buffer);

    free(buffer);

    Store_field (triple, 1, Val_int (res));
    Store_field (triple, 2, message);

    CAMLreturn (triple);
}

/*
 * nbsocket_write : Unix.file_descr -> string -> int -> int * int
 *
 * returns (errno, written) where written is the number of bytes written,
 * -1 for errors
 */
CAMLprim value nbsocket_write(value socket_desc, value str, value length)
{
    CAMLparam3 (socket_desc, str, length);
    CAMLlocal1 (pair);

    pair = caml_alloc_tuple(2);

    int desc = Int_val (socket_desc);
    char *buf = String_val (str);
    size_t len = Unsigned_int_val (length);

    int res = write(desc, buf, len);

    if (res == -1)
    {
        Store_field (pair, 0, Val_int (errno));
    }
    else
    {
        Store_field (pair, 0, Val_int (0));
    }

    Store_field (pair, 1, Val_int (res));

    CAMLreturn (pair);
}

/*
 * nbsocket_close : Unix.file_descr -> unit
 */
CAMLprim value nbsocket_close(value socket_desc)
{
    int desc = Int_val (socket_desc);

    close(desc);

    return Val_unit;
}
