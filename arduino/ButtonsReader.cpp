#include "ButtonsReader.h"

/*
 * Button 1:
 * LCD ON/OFF.
 *
 * Returns true if b1 was pressed.
 */
bool checkButtonOne(unsigned int input)
{
    if (input > 648 && input < 750)
    {
        if (lcd.getState() == LCD_OFF)
        {
            lcd.on();
            refreshLCD();
        }
        else
        {
            lcd.off();
        }

        return true;
    }

    return false;
}

/*
 * Button 2:
 * Heating system enable/disable.
 *
 * Returns true if b2 was pressed.
 */
bool checkButtonTwo(unsigned int input)
{
    if (input > 882 && input < 978)
    {
        if (lcd.getState() == LCD_OFF) lcd.on();

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print(heatingSystem);
        lcd.setCursor(0, 1);

        if (getHeatingSystemState() == DISABLED_STATE)
        {
            enableHeatingSystem();
            lcd.print(enabled);
        }
        else
        {
            disableHeatingSystem();
            lcd.print(disabled);
        }

        lcd.busy();

        return true;
    }

    return false;
}

/*
 * Button 3:
 * Data sender system ON/OFF.
 *
 * Returns true if b3 was pressed.
 */
bool checkButtonThree(unsigned int input)
{
    if (input >= 978)
    {
        if (lcd.getState() == LCD_OFF) lcd.on();

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print(sendDataSystem);
        lcd.setCursor(0, 1);

        if (getDataSenderState() == OFF_STATE)
        {
            enableDataSender();
            lcd.print(enabled);
        }
        else
        {
            disableDataSender();
            lcd.print(disabled);
        }

        lcd.busy();

        return true;
    }

    return false;
}

void readButtons(void)
{
    // this variable is set to 0 if no button
    // has been pressed recently
    static time_t lastTimePressed = 0;

    // if a button was pressed recently
    if (lastTimePressed > 0)
    {
        // if a button was pressed less than 'SLEEP_BUTTONS_AFTER_PRESSED'
        // millis ago don't do nothing
        if (millis() - lastTimePressed < SLEEP_BUTTONS_AFTER_PRESSED)
        {
            return;
        }
        else
        {
            lastTimePressed = 0;
            lcd.idle();
            lcd.clear();
            refreshLCD();
            return;
        }
    }

    unsigned int input = analogRead(BUTTONS_ANALOG_PIN);

    if (checkButtonOne(input) || checkButtonTwo(input) || checkButtonThree(input))
    {
        lastTimePressed = millis();
    }
}
