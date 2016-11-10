#include "LiquidCrystalImproved.h"

LiquidCrystalImproved::LiquidCrystalImproved(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
    : LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}

LiquidCrystalImproved::LiquidCrystalImproved(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
    : LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}

LiquidCrystalImproved::LiquidCrystalImproved(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
    : LiquidCrystal(rs, rw, enable, d0, d1, d2, d3) {}

LiquidCrystalImproved::LiquidCrystalImproved(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
    : LiquidCrystal(rs, enable, d0, d1, d2, d3) {}

void LiquidCrystalImproved::begin(uint8_t cols, uint8_t rows, uint8_t backlight, uint8_t charsize)
{
    LiquidCrystal::begin(cols, rows, charsize);
    _backlight_supply_pin = backlight;
    on();
}

void LiquidCrystalImproved::on(void)
{
    analogWrite(_backlight_supply_pin, 255);
    display();
    _lcd_state = LCD_IDLE;
}

void LiquidCrystalImproved::off(void)
{
    analogWrite(_backlight_supply_pin, 0);
    noDisplay();
    _lcd_state = LCD_OFF;
}

void LiquidCrystalImproved::idle(void)
{
    if (_lcd_state != LCD_OFF)
    {
        _lcd_state = LCD_IDLE;
    }
}

void LiquidCrystalImproved::busy(void)
{
    if (_lcd_state != LCD_OFF)
    {
        _lcd_state = LCD_BUSY;
    }
}

enum LiquidCrystalState LiquidCrystalImproved::getState(void)
{
    return _lcd_state;
}

size_t LiquidCrystalImproved::write(uint8_t character)
{
    if (_lcd_state == LCD_IDLE)
    {
        return LiquidCrystal::write(character);
    }
    else
    {
        return 0;
    }
}
