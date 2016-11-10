RESULT = brewis

SOURCES = \
    src/util.mli src/util.ml \
    src/socket/external_errno.c src/socket/errno.mli src/socket/errno.ml \
    src/socket/external_bluetooth.c src/socket/bluetooth.mli src/socket/bluetooth.ml \
    src/socket/external_domain.c src/socket/domain.mli src/socket/domain.ml \
    src/socket/external_type.c src/socket/type.mli src/socket/type.ml \
    src/socket/protocol.mli src/socket/protocol.ml \
    src/socket/address.mli src/socket/address.ml \
    src/socket/external_nbsocket.c src/socket/nbsocket.mli src/socket/nbsocket.ml \
    src/jwt_session.mli src/jwt_session.ml \
    src/config.mli src/config.ml \
    src/main.mli src/main.ml

PACKS = unix async cohttp cohttp.async config-file yojson

CLIBS = bluetooth

THREADS = yes

OCAMLMAKEFILE = ./OCamlMakefile

all:    nc

%:      all

include $(OCAMLMAKEFILE)
