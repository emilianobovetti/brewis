#include "LCD.h"

LiquidCrystal lcd(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void initializeLCDRefresher(void)
{
    lcd.begin(LCD_NUM_COLUMNS, LCD_NUM_ROWS);
}

void enableLCDRefresher(void)
{
    setTaskState(&lcdRefresherTask, RUNNING);
}

void disableLCDRefresher(void)
{
    setTaskState(&lcdRefresherTask, NOT_RUNNING);
}

void enableLCD(void)
{
    analogWrite(LCD_BACKLIGHT_SUPPLY, 255);
    setLCDState(ON_STATE);
}

void disableLCD(void)
{
    digitalWrite(LCD_BACKLIGHT_SUPPLY, LOW);
    setLCDState(OFF_STATE);
}

void refreshLCD(void)
{
    lcd.clear();

    lcd.setCursor(0, 0);
    emptyGlobalBuffer();
    writeStringInGlobalBuffer("IN:");
    writeTemperatureInGlobalBuffer(getBrewingTemperature());

    writeStringInGlobalBuffer(space);
    writeStringInGlobalBuffer("OUT:");
    writeTemperatureInGlobalBuffer(getRoomTemperature());

    lcd.print(globalBuffer);

    lcd.setCursor(0, 1);
    emptyGlobalBuffer();
    writeStringInGlobalBuffer("HS:");
    writeStringInGlobalBuffer(space);

    switch (getHeatingSystemState())
    {
        case STARTED_STATE:
            writeStringInGlobalBuffer(on);
            writeStringInGlobalBuffer(space);
            writeStringInGlobalBuffer(space);
            break;
        case DISABLED_STATE:
            writeStringInGlobalBuffer(off);
            writeStringInGlobalBuffer(space);
            break;
        case STOPPED_STATE:
            writeStringInGlobalBuffer("idle");
            break;
        default:
            writeStringInGlobalBuffer(error);
            writeStringInGlobalBuffer(space);
    }

    writeStringInGlobalBuffer(space);
    writeStringInGlobalBuffer("DS:");
    writeStringInGlobalBuffer(space);

    switch (getDataSenderState())
    {
        case ON_STATE:
            writeStringInGlobalBuffer(on);
            break;
        case OFF_STATE:
            writeStringInGlobalBuffer(off);
            break;
        default:
            writeStringInGlobalBuffer(error);
    }

    lcd.print(globalBuffer);
}
