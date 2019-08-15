#!/bin/sh

set -eu

. .env

echo "Waiting for postgres..."

until nc -z "${POSTGRES_HOST}" "${POSTGRES_PORT}"; do
    sleep 1
done

php artisan migrate --force --seed

php-fpm7

test -d /run/nginx || mkdir /run/nginx
nginx -t
nginx

tail -f /var/log/nginx/*
