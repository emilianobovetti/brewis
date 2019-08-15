.PHONY: all build run

mounts := \
	--mount src=brewisd-logs,dst=/var/log \
	--mount src=/etc/localtime,dst=/etc/localtime,type=bind,readonly \
	--mount src=/usr/share/zoneinfo,dst=/usr/share/zoneinfo,type=bind,readonly

all: build

build:
	docker build --tag brewisd .

brewisd.conf:
	bash mk-conf

run: brewisd.conf build
	docker run -it --net host $(mounts) brewisd

run-shell: brewisd.conf build
	docker run -it --net host $(mounts) brewisd /bin/sh
