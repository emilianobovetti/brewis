FROM alpine:3.18.3 AS build

ENV HOME=/home/build

WORKDIR "${HOME}"

RUN apk add --no-cache \
    m4 \
    make \
    opam \
    musl-dev \
    bluez-dev \
    libffi-dev \
    libressl-dev \
    linux-headers \
    pkgconf \
    ocamlbuild \
    ocaml-camlp4 \
    ocaml-camlp4-dev \
    ocaml-compiler-libs

RUN adduser builder --home "${HOME}" --system
USER builder

RUN opam init -y --auto-setup --disable-sandboxing
RUN opam install --fake ocamlbuild
RUN opam install -y \
    dune \
    core \
    ocamlfind \
    async \
    async_ssl \
    cohttp \
    cohttp-async \
    yojson \
    config-file

ENV PATH="${PATH}:${HOME}/.opam/default/bin"

RUN mkdir "${HOME}/brewisd"
WORKDIR "${HOME}/brewisd"

COPY --chown=builder:nogroup dune-project brewisd.opam ./
COPY --chown=builder:nogroup src ./src
RUN dune build

FROM alpine:3.18.3 AS deploy

RUN apk add --no-cache \
    libffi\
    bluez-libs \
    libressl

COPY --from=build /home/build/brewisd/_build/install/default/bin/* /usr/local/bin
COPY brewisd.conf /etc

CMD brewisd
