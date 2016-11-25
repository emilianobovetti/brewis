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

void emptyLCD(void)
{
    int row, column;

    for (row = 0; row < LCD_NUM_ROWS; row++)
    {
        lcd.setCursor(0, row);

        for (column = 0; column < LCD_NUM_COLUMNS; column++)
        {
            lcd.print(space);
        }
    }
}

void refreshLCD(void)
{
    if (lcd.getState() != LCD_IDLE)
    {
        return;
    }

    emptyLCD();

    lcd.setCursor(0, 0);
    lcd.print(getCurrentTemperature());
    lcd.setCursor(0, 1);
    lcd.print(getCurrentDensity());
}
