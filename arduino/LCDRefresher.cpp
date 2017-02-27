#include "LCDRefresher.h"

void initializeLCDRefresher(void)
{
    lcd.begin(LCD_NUM_COLUMNS, LCD_NUM_ROWS, LCD_BACKLIGHT_SUPPLY);
}

void enableLCDRefresher(void)
{
    setTaskState(&lcdRefresherTask, RUNNING);
}

void disableLCDRefresher(void)
{
    setTaskState(&lcdRefresherTask, NOT_RUNNING);
}

void refreshLCD(void)
{
    if (lcd.getState() != LCD_IDLE)
    {
        return;
    }

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(getCurrentTemperature());
    lcd.setCursor(0, 1);

    lcd.print("HS: ");

    switch (getHeatingSystemState())
    {
        case STARTED_STATE:
            lcd.print(on);
            lcd.print(space);
            lcd.print(space);
            break;
        case DISABLED_STATE:
            lcd.print(off);
            lcd.print(space);
            break;
        case STOPPED_STATE:
            lcd.print("idle");
            break;
        default:
            lcd.print(error);
            lcd.print(space);
    }

    lcd.print(" DS: ");
    switch (getDataSenderState())
    {
        case ON_STATE:
            lcd.print(on);
            break;
        case OFF_STATE:
            lcd.print(off);
            break;
        default:
            lcd.print(error);
    }
}
