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

/*
 * LCD - rows: 2, cols: 16
 */
void refreshLCD(void)
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("IN: ");
    lcd.print(getBrewingTemperature());
    lcd.print(" OUT: ");
    lcd.print(getRoomTemperature());
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
