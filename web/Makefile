.PHONY: all build run run-shell clean

all: build

.env:
	sh mk-env.sh

public/node_modules:
	yarn

build: .env public/node_modules
	docker-compose build

run: build
	docker-compose up

run-shell: .env public/node_modules
	docker build -t brewis-web .
	docker run -it brewis-web /bin/sh

clean:
	rm -rf public/node_modules
