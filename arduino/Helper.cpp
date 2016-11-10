#include "Helper.h"

void initializeSerial(void)
{
    static bool initialized = false;

    if ( ! initialized)
    {
        pinMode(BLUETOOTH_TX_PIN, INPUT);
        pinMode(BLUETOOTH_RX_PIN, OUTPUT);

        COMM_SERIAL.begin(COMM_SERIAL_BAUD_RATE);

        initialized = true;
    }
}

void emptyString(char *str, uint8_t dim)
{
    uint8_t i;

    for (i = 0; i < dim; i++)
    {
        str[i] = '\0';
    }
}

void emptyGlobalBuffer(void)
{
    emptyString(globalBuffer, GLOBAL_STRING_BUFFER_SIZE);
}