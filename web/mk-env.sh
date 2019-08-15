#!/bin/sh

set -eu

ranstr ()
{
    stdbuf -o0 tr -dc 'a-zA-Z0-9' < /dev/random | head -c "$1"
}

cat << EOF > ".env"
JWT_SECRET=$(ranstr 64)

POSTGRES_DB=brewis
POSTGRES_USER=brewis
POSTGRES_PASSWORD=$(ranstr 64)
POSTGRES_HOST=db
POSTGRES_PORT=5432
EOF
