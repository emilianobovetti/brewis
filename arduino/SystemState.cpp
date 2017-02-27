#include "SystemState.h"

#define STARTING_EEPROM_ADDRESS 0

#define DATA_SENDER_STATE_EEPROM_ADDRESS \
    STARTING_EEPROM_ADDRESS
#define TARGET_TEMPERATURE_EEPROM_ADDRESS \
    DATA_SENDER_STATE_EEPROM_ADDRESS + sizeof (DATA_SENDER_STATE_TYPE)
#define DELTA_TEMPERATURE_EEPROM_ADDRESS \
    TARGET_TEMPERATURE_EEPROM_ADDRESS + sizeof (TARGET_TEMPERATURE_TYPE)

static struct
{
    DATA_SENDER_STATE_TYPE dataSenderState;

    HEATING_SYSTEM_STATE_TYPE heatingSystemState;

    TARGET_TEMPERATURE_TYPE targetTemperature;

    DELTA_TEMPERATURE_TYPE deltaTemperature;

    CURRENT_TEMPERATURE_TYPE currentTemperature;

} system;

void initializeSystemState(void)
{
    EEPROM.get(DATA_SENDER_STATE_EEPROM_ADDRESS, system.dataSenderState);
    EEPROM.get(TARGET_TEMPERATURE_EEPROM_ADDRESS, system.targetTemperature);
    EEPROM.get(DELTA_TEMPERATURE_EEPROM_ADDRESS, system.deltaTemperature);

    if (system.dataSenderState != OFF_STATE && system.dataSenderState != ON_STATE)
    {
        setDataSenderState(OFF_STATE);
    }

    // TODO
    // warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
    // use union conversion instead
    unsigned int ones = -1;
    unsigned int targetTemperature = *((unsigned int*) &system.targetTemperature);
    unsigned int deltaTemperature = *((unsigned int*) &system.deltaTemperature);

    if (targetTemperature == ones)
    {
        setTargetTemperature(DEFAULT_TARGET_TEMPERATURE);
    }

    if (deltaTemperature == ones)
    {
        setDeltaTemperature(DEFAULT_DELTA_TEMPERATURE);
    }

    system.heatingSystemState = DISABLED_STATE;
    system.currentTemperature = UNKNOWN_TEMPERATURE;
}

/*
 * -------------------
 * System state getter
 * -------------------
 */

DATA_SENDER_STATE_TYPE getDataSenderState(void)
{
    return system.dataSenderState;
}

HEATING_SYSTEM_STATE_TYPE getHeatingSystemState(void)
{
    return system.heatingSystemState;
}

TARGET_TEMPERATURE_TYPE getTargetTemperature(void)
{
    return system.targetTemperature;
}

DELTA_TEMPERATURE_TYPE getDeltaTemperature(void)
{
    return system.deltaTemperature;
}

CURRENT_TEMPERATURE_TYPE getCurrentTemperature(void)
{
    return system.currentTemperature;
}

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE state)
{
    system.dataSenderState = state;
    EEPROM.put(DATA_SENDER_STATE_EEPROM_ADDRESS, system.dataSenderState);
}

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE state)
{
    system.heatingSystemState = state;
}

void setTargetTemperature(TARGET_TEMPERATURE_TYPE temperature)
{
    system.targetTemperature = temperature;
    EEPROM.put(TARGET_TEMPERATURE_EEPROM_ADDRESS, system.targetTemperature);
}

void setDeltaTemperature(DELTA_TEMPERATURE_TYPE temperature)
{
    system.deltaTemperature = temperature;
    EEPROM.put(DELTA_TEMPERATURE_EEPROM_ADDRESS, system.deltaTemperature);
}

void setCurrentTemperature(CURRENT_TEMPERATURE_TYPE temperature)
{
    system.currentTemperature = temperature;
}
