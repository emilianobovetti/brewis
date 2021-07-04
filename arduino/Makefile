# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG = uno

ARCHITECTURE = avr

MONITOR_BAUDRATE = 9600

MONITOR_PORT = /dev/ttyACM0

ARDUINO_LIBS = \
	Hx711 \
	EEPROM \
	OneWire \
	LiquidCrystal \
	SoftwareSerial \
	DallasTemperature \
	TaskScheduler

USER_LIB_PATH = ./libraries

include ./Arduino-Makefile/Arduino.mk
