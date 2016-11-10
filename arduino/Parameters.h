#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

/*
 * -----------
 * Analog pins
 * -----------
 */
#define A0_PIN 14
#define A1_PIN 15
#define A2_PIN 16
#define A3_PIN 17
#define A4_PIN 18
#define A5_PIN 19

/*
 * --------------------
 * Serial communication
 * --------------------
 */
// can be "Serial" or "bluetooth"
#define COMM_SERIAL bluetooth
#define COMM_SERIAL_BAUD_RATE 9600

#define DATA_RECEIVER_TIMEOUT 2000

/*
 * ---------
 * Bluetooth
 * ---------
 */
#define BLUETOOTH_TX_PIN 8
#define BLUETOOTH_RX_PIN 9

/*
 * --------------------------------------
 * Temperature control and heating system
 * --------------------------------------
 */
#define DS18B20_BUS_PIN 6
#define HEATING_SYSTEM_RELAY_PIN 7

#define DEFAULT_HS_STARTING_TEMPERATURE 20
#define DEFAULT_HS_STOPPING_TEMPERATURE 21

#define UNKNOWN_TEMPERATURE -127.0

/*
 * ---------------
 * Density control
 * ---------------
 */
#define HX711_DOUT_PIN A2_PIN
#define HX711_SCK_PIN A3_PIN

                                    // grams
#define MEASUREMENT_STANDARD_WEIGHT 185
                                    // liters
#define MEASUREMENT_STANDARD_VOLUME 0.158082357
                                    // Kg / m^3
#define MEASUREMENT_STANDARD_DENSITY \
    (MEASUREMENT_STANDARD_WEIGHT / MEASUREMENT_STANDARD_VOLUME)

#define UNKNOWN_DENSITY 0

/*
 * -------
 * Buttons
 * -------
 */
#define BUTTONS_ANALOG_PIN A0_PIN
#define SLEEP_BUTTONS_AFTER_PRESSED 2000

/*
 * ---
 * LCD
 * ---
 */
#define LCD_BACKLIGHT_SUPPLY A1_PIN

#define LCD_D7_PIN 2
#define LCD_D6_PIN 3
#define LCD_D5_PIN 4
#define LCD_D4_PIN 5
#define LCD_ENABLE_PIN 11
#define LCD_RS_PIN 12

#define LCD_COLUMNS_NUM 16
#define LCD_ROWS_NUM 2

/*
 * --------------------
 * Global string buffer
 * --------------------
 */
#define GLOBAL_STRING_BUFFER_LENGTH 25
#define GLOBAL_STRING_BUFFER_SIZE GLOBAL_STRING_BUFFER_LENGTH + 1

#endif // __PARAMETERS_H__
