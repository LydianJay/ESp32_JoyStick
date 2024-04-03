#include "JoyStick.h"


// LY IDLE = ~2600 +- 30
// LY UP = ~4095 DOWN = 0



void JoyStick::begin(uint8_t pinX, uint8_t pinY, uint8_t c) {
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    pinMode(c, INPUT_PULLDOWN);
    this->c = c;
    x = pinX;
    y = pinY;
}

uint8_t JoyStick::getState() {
    const uint16_t mx = 1900;
    const uint16_t my = 1850;
    
    uint8_t state = JOY_IDLE;

    auto aX = analogRead(x);
    auto aY = analogRead(y);


    // Y Dir
    if(aY > my + 150) {
        state |= JOY_UP;
    }
    else if(aY < my - 150) {
        state |= JOY_DOWN;
    }

    if(aX > mx + 150) {
        state |= JOY_LEFT;
    }
    else if(aX < mx - 150) {
        state |= JOY_RIGHT;
    }

    if(analogRead(c) == 0){
        state |= JOY_PRESSED;
    }
    //Serial.println(analogRead(c));
   // Serial.println("X:" + String(aX) + " Y:" + String(aY));

    return state;
}
