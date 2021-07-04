# Debian

```sh
apt install arduino-core screen
make
```

```sh
pip3 install pyserial
make upload
```

# Arch

```sh
pacman -S arduino-avr-core
make
```

```sh
pacman -S python-pyserial
gpasswd -a $(whoami) uucp
make upload
```

```sh
pacman -S screen
make monitor
```
