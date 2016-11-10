#include "LCDRefresher.h"

void initializeLCDRefresher(void)
{
    lcd.begin(LCD_COLUMNS_NUM, LCD_ROWS_NUM, LCD_BACKLIGHT_SUPPLY);
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

    lcd.setCursor(0, 0);
    lcd.print(getCurrentTemperature());
    lcd.print(spaces);
    lcd.setCursor(0, 1);
    lcd.print(getCurrentDensity());
    lcd.print(spaces);
}
