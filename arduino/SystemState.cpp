#include "SystemState.h"
#include <EEPROM.h>

/*
 * An EEPROM address is equal to previous address
 * plus byte size of previous stored data:
 *
 * +------------+--------------------+
 * | Address    | Content            |
 * +------------+--------------------+
 * | 0          | TARGET_TEMPERATURE |
 * | 4          | DELTA_TEMPERATURE  |
 * +------------+--------------------+
 */
#define STARTING_EEPROM_ADDRESS 0

#define TARGET_TEMPERATURE_EEPROM_ADDRESS \
    STARTING_EEPROM_ADDRESS

#define DELTA_TEMPERATURE_EEPROM_ADDRESS \
    TARGET_TEMPERATURE_EEPROM_ADDRESS + sizeof (TEMPERATURE_TYPE)

/*
 * The global system state stores runtime data,
 * this is our world and source of truth
 */
static struct
{
    DATA_SENDER_STATE_TYPE dataSenderState;

    HEATING_SYSTEM_STATE_TYPE heatingSystemState;

    LCD_STATE_TYPE  lcdState;

    TEMPERATURE_TYPE targetTemperature;

    TEMPERATURE_TYPE deltaTemperature;

    TEMPERATURE_TYPE brewingTemperature;

    TEMPERATURE_TYPE roomTemperature;
} world;

void initializeSystemState(void)
{
    /*
     * Set defaults to values that are not read from EEPROM
     */
    world.dataSenderState = OFF_STATE;
    world.heatingSystemState = DISABLED_STATE;
    world.lcdState = OFF_STATE;
    world.brewingTemperature = UNKNOWN_TEMPERATURE;
    world.roomTemperature = UNKNOWN_TEMPERATURE;

    /*
     * Read data from EEPROM and store in `world`
     */
    EEPROM.get(TARGET_TEMPERATURE_EEPROM_ADDRESS, world.targetTemperature);
    EEPROM.get(DELTA_TEMPERATURE_EEPROM_ADDRESS, world.deltaTemperature);

    /*
     * When EEPROM is empty the read will give all bytes to 1
     *
     * A float `f` with a memory representation of `0xffffffff`
     * is NaN, so we have `f != f`
     *
     * In this case we set a default value in both memory and EEPROM
     *
     * TODO: check if the given temperature is in a valid range
     */
    if (world.targetTemperature != world.targetTemperature)
    {
        setTargetTemperature(DEFAULT_TARGET_TEMPERATURE);
    }

    if (world.deltaTemperature != world.deltaTemperature)
    {
        setDeltaTemperature(DEFAULT_DELTA_TEMPERATURE);
    }
}

/*
 * -------------------
 * System state getter
 * -------------------
 */

DATA_SENDER_STATE_TYPE getDataSenderState(void)
{
    return world.dataSenderState;
}

HEATING_SYSTEM_STATE_TYPE getHeatingSystemState(void)
{
    return world.heatingSystemState;
}

LCD_STATE_TYPE getLCDState(void)
{
    return world.lcdState;
}

TEMPERATURE_TYPE getTargetTemperature(void)
{
    return world.targetTemperature;
}

TEMPERATURE_TYPE getDeltaTemperature(void)
{
    return world.deltaTemperature;
}

TEMPERATURE_TYPE getBrewingTemperature(void)
{
    return world.brewingTemperature;
}

TEMPERATURE_TYPE getRoomTemperature(void)
{
    return world.roomTemperature;
}

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE state)
{
    world.dataSenderState = state;
}

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE state)
{
    world.heatingSystemState = state;
}

void setLCDState(LCD_STATE_TYPE state)
{
    world.lcdState = state;
}

void setTargetTemperature(TEMPERATURE_TYPE temperature)
{
    world.targetTemperature = temperature;
    EEPROM.put(TARGET_TEMPERATURE_EEPROM_ADDRESS, world.targetTemperature);
}

void setDeltaTemperature(TEMPERATURE_TYPE temperature)
{
    world.deltaTemperature = temperature;
    EEPROM.put(DELTA_TEMPERATURE_EEPROM_ADDRESS, world.deltaTemperature);
}

void setBrewingTemperature(TEMPERATURE_TYPE temperature)
{
    world.brewingTemperature = temperature;
}

void setRoomTemperature(TEMPERATURE_TYPE temperature)
{
    world.roomTemperature = temperature;
}
