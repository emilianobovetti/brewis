#ifndef __LIQUID_CRYSTAL_IMPROVED_H__
#define __LIQUID_CRYSTAL_IMPROVED_H__

#include <Arduino.h>
#include <LiquidCrystal.h>

enum LiquidCrystalState { LCD_OFF, LCD_BUSY, LCD_IDLE };

class LiquidCrystalImproved : public LiquidCrystal {
public:
    LiquidCrystalImproved(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    LiquidCrystalImproved(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    LiquidCrystalImproved(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    LiquidCrystalImproved(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

    void begin(uint8_t cols, uint8_t rows, uint8_t backlight, uint8_t charsize = LCD_5x8DOTS);

    void on(void);
    void off(void);

    void idle(void);
    void busy(void);

    enum LiquidCrystalState getState(void);

    virtual size_t write(uint8_t);

private:
    enum LiquidCrystalState _lcd_state; // default IDLE
    uint8_t _backlight_supply_pin;
};

#endif // __LIQUID_CRYSTAL_IMPROVED_H__
