#include "SystemState.h"

#define STARTING_EEPROM_ADDRESS 0

#define DATA_SENDER_STATE_EEPROM_ADDRESS \
    STARTING_EEPROM_ADDRESS
#define TARGET_TEMPERATURE_EEPROM_ADDRESS \
    DATA_SENDER_STATE_EEPROM_ADDRESS + sizeof (DATA_SENDER_STATE_TYPE)
#define DELTA_TEMPERATURE_EEPROM_ADDRESS \
    TARGET_TEMPERATURE_EEPROM_ADDRESS + sizeof (TARGET_TEMPERATURE_TYPE)

/*
 * The global system state stores runtime data,
 * this is our world and source of truth
 */
static struct
{
    DATA_SENDER_STATE_TYPE dataSenderState;

    HEATING_SYSTEM_STATE_TYPE heatingSystemState;

    TARGET_TEMPERATURE_TYPE targetTemperature;

    DELTA_TEMPERATURE_TYPE deltaTemperature;

    CURRENT_TEMPERATURE_TYPE currentTemperature;

} world;

void initializeSystemState(void)
{
    EEPROM.get(DATA_SENDER_STATE_EEPROM_ADDRESS, world.dataSenderState);
    EEPROM.get(TARGET_TEMPERATURE_EEPROM_ADDRESS, world.targetTemperature);
    EEPROM.get(DELTA_TEMPERATURE_EEPROM_ADDRESS, world.deltaTemperature);

    if (world.dataSenderState != OFF_STATE && world.dataSenderState != ON_STATE)
    {
        setDataSenderState(OFF_STATE);
    }

    // TODO
    // warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
    // use union conversion instead
    unsigned int ones = -1;
    unsigned int targetTemperature = *((unsigned int*) &world.targetTemperature);
    unsigned int deltaTemperature = *((unsigned int*) &world.deltaTemperature);

    if (targetTemperature == ones)
    {
        setTargetTemperature(DEFAULT_TARGET_TEMPERATURE);
    }

    if (deltaTemperature == ones)
    {
        setDeltaTemperature(DEFAULT_DELTA_TEMPERATURE);
    }

    world.heatingSystemState = DISABLED_STATE;
    world.currentTemperature = UNKNOWN_TEMPERATURE;
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

TARGET_TEMPERATURE_TYPE getTargetTemperature(void)
{
    return world.targetTemperature;
}

DELTA_TEMPERATURE_TYPE getDeltaTemperature(void)
{
    return world.deltaTemperature;
}

CURRENT_TEMPERATURE_TYPE getCurrentTemperature(void)
{
    return world.currentTemperature;
}

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE state)
{
    world.dataSenderState = state;
    EEPROM.put(DATA_SENDER_STATE_EEPROM_ADDRESS, world.dataSenderState);
}

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE state)
{
    world.heatingSystemState = state;
}

void setTargetTemperature(TARGET_TEMPERATURE_TYPE temperature)
{
    world.targetTemperature = temperature;
    EEPROM.put(TARGET_TEMPERATURE_EEPROM_ADDRESS, world.targetTemperature);
}

void setDeltaTemperature(DELTA_TEMPERATURE_TYPE temperature)
{
    world.deltaTemperature = temperature;
    EEPROM.put(DELTA_TEMPERATURE_EEPROM_ADDRESS, world.deltaTemperature);
}

void setCurrentTemperature(CURRENT_TEMPERATURE_TYPE temperature)
{
    world.currentTemperature = temperature;
}
