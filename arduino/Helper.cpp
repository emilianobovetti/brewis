#include "Helper.h"

bool isValidTemperature(float temp)
{
    // Valid temperature range for DS18B20 sensor
    return temp > -55 && temp < 125;
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

void padGlobalBufferWithSpaces(uint8_t target)
{
    uint8_t length = strlen(globalBuffer);

    while (length < target)
    {
        globalBuffer[length] = space[0];
        length++;
    }

    globalBuffer[length] = '\0';
}

void writeStringInGlobalBuffer(const char *str)
{
    strcat(globalBuffer, str);
}

char floatBuffer[8];

/*
 * `width + prec` must be at most 6
 */
void writeFloatInGlobalBuffer(float val, signed char width, unsigned char prec)
{
    emptyString(floatBuffer, 8);
    dtostrf(val, width, prec, floatBuffer);
    writeStringInGlobalBuffer(floatBuffer);
}

void writeTemperatureInGlobalBuffer(float temp)
{
    /*
     * We aren't using isValidTemperature() here
     * because we need to make sure the temperature
     * is at most 4 characters long.
     */
    if (temp < -9 || temp > 99)
    {
        writeStringInGlobalBuffer(error);
    }
    else
    {
        writeFloatInGlobalBuffer(temp, 2, 1);
    }
}
