FROM alpine:3.18.3

RUN apk add --no-cache \
    php \
    php-fpm \
    php-dom \
    php-xml \
    php-pdo \
    php-pdo_pgsql \
    php-json \
    php-phar \
    php-openssl \
    php-mbstring \
    php-fileinfo \
    php-tokenizer \
    php-xmlwriter \
    nginx \
    openssl

RUN openssl req \
    -x509 \
    -batch \
    -nodes \
    -days 365 \
    -newkey rsa:4096 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt

ENV composer_setup="/tmp/composer-setup.php"
ENV composer_setup_sha384="a5c698ffe4b8e849a443b120cd5ba38043260d5c4023dbf93e1558871f1f07f58274fc6f4c93bcfd858c6bd0775cd8d1"

RUN php -r "copy('https://getcomposer.org/installer', '${composer_setup}');" \
    && php -r "if (hash_file('sha384', '${composer_setup}') !== '${composer_setup_sha384}') unlink('${composer_setup}');" \
    && php "${composer_setup}" --install-dir=/usr/local/bin --filename=composer \
    && php -r "unlink('${composer_setup}');"

RUN mkdir /var/www/brewis
WORKDIR /var/www/brewis

COPY composer.json composer.lock ./
RUN composer install \
    --no-dev \
    --no-cache \
    --no-autoloader \
    --no-interaction

COPY . .

RUN composer dump-autoload --optimize

RUN addgroup --system php-fpm \
    && adduser --system php-fpm -G php-fpm \
    && chmod -R 700 storage \
    && chown -R php-fpm storage

COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY php-fpm.conf /etc/php7/php-fpm.d/www.conf

CMD ["sh", "startup.sh"]
