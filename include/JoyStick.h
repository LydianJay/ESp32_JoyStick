#ifndef _BUTTON_H
#define _BUTTON_H
#include <Arduino.h>


#define JOY_IDLE    0b00000000
#define JOY_UP      0b00000001
#define JOY_DOWN    0b00000010
#define JOY_LEFT    0b00000100
#define JOY_RIGHT   0b00001000
#define JOY_PRESSED 0b00010000

// INVERTED
#define JOY_INV_UP      JOY_DOWN
#define JOY_INV_DOWN    JOY_UP
#define JOY_INV_LEFT    JOY_RIGHT
#define JOY_INV_RIGHT   JOY_LEFT


class JoyStick {

public:
    void begin(uint8_t pinX, uint8_t pinY, uint8_t c);
    
    uint8_t getState();
private:
    uint8_t x, y, c;
};




#endif