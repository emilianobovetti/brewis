#include "SwitchesReader.h"

void initializeSwitchesReader(void)
{
    pinMode(SWITCH_0_PIN, INPUT_PULLUP);
    pinMode(SWITCH_1_PIN, INPUT_PULLUP);
    pinMode(SWITCH_2_PIN, INPUT_PULLUP);
}

/*
 * Switch 0: LCD ON/OFF.
 */
void checkSwitch0(void)
{
    bool isSwitchOn = digitalRead(SWITCH_1_PIN) == LOW;
    bool isLCDOn = getLCDState() == ON_STATE;

    if (!isLCDOn && isSwitchOn)
    {
        enableLCD();
    }
    else if (isLCDOn && !isSwitchOn)
    {
        disableLCD();
    }
}

/*
 * Switch 1: enable/disable heating system.
 */
void checkSwitch1(void)
{
    bool isSwitchOn = digitalRead(SWITCH_1_PIN) == LOW;
    bool isHeatingSystemEnabled = getHeatingSystemState() != DISABLED_STATE;

    if (!isHeatingSystemEnabled && isSwitchOn)
    {
        enableHeatingSystem();
    }
    else if (isHeatingSystemEnabled && !isSwitchOn)
    {
        disableHeatingSystem();
    }
}

/*
 * Switch 2: enable/disable data sender.
 */
void checkSwitch2(void)
{
    bool isSwitchOn = digitalRead(SWITCH_2_PIN) == LOW;
    bool isDataSenderEnabled = getDataSenderState() == ON_STATE;

    if (!isDataSenderEnabled && isSwitchOn)
    {
        enableDataSender();
    }
    else if (isDataSenderEnabled && !isSwitchOn)
    {
        disableDataSender();
    }
}

void readSwitches(void)
{
    checkSwitch0();
    checkSwitch1();
    checkSwitch2();
}
