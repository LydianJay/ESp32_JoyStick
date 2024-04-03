#include <Arduino.h>
#include <WiFi.h>
#include "JoyStick.h"





#define PIN_LX 14
#define PIN_LY 27
#define PIN_LC 26
#define PIN_L1 32
#define PIN_L2 33
#define PIN_L3 25

#define PIN_RX 0
#define PIN_RY 2
#define PIN_RC 15
#define PIN_R1 23
#define PIN_R2 19
#define PIN_R3 18


#define _BUTTON_1_PRESSED 0b00100000
#define _BUTTON_2_PRESSED 0b01000000
#define _BUTTON_3_PRESSED 0b10000000

// LY IDLE = ~2600 +- 30
// LY UP = ~4095 DOWN = 0


JoyStick left;
JoyStick right;

void setup() {
  Serial.begin(115200);

  left.begin(PIN_LX, PIN_LY, PIN_LC);
  right.begin(PIN_RX, PIN_RY, PIN_RC);
  

  pinMode(PIN_L1, INPUT_PULLUP);
  pinMode(PIN_L2, INPUT_PULLUP);
  pinMode(PIN_L3, INPUT_PULLUP);

  pinMode(PIN_R1, INPUT_PULLUP);
  pinMode(PIN_R2, INPUT_PULLUP);
  pinMode(PIN_R3, INPUT_PULLUP);


  
}



void loop() {


  uint8_t jState = left.getState();
  uint8_t rState = right.getState();

  if (jState != JOY_IDLE || rState != JOY_IDLE) {

    if(digitalRead(PIN_L1) == LOW) jState |= _BUTTON_1_PRESSED;
    if(digitalRead(PIN_L2) == LOW) jState |= _BUTTON_2_PRESSED;
    if(digitalRead(PIN_L3) == LOW) jState |= _BUTTON_3_PRESSED;

    if(digitalRead(PIN_R1) == LOW) rState |= _BUTTON_1_PRESSED;
    if(digitalRead(PIN_R2) == LOW) rState |= _BUTTON_2_PRESSED;
    if(digitalRead(PIN_R3) == LOW) rState |= _BUTTON_3_PRESSED;


    uint16_t state = jState;
    state <<= 8;
    state |= rState;


    Serial.write((uint8_t*)&state, 2);
  }
  
  // if(jState & JOY_LEFT) Serial.println("Left");
  // else if(jState & JOY_RIGHT) Serial.println("Right");
  
  // if(jState & JOY_UP) Serial.println("Up");
  // else if(jState & JOY_DOWN) Serial.println("Down");

  // if(jState & JOY_PRESSED) Serial.println("Pressed!");


  // if(digitalRead(PIN_L1) == LOW) Serial.println("L1");
  // if(digitalRead(PIN_L2) == LOW) Serial.println("L2");
  // if(digitalRead(PIN_L3) == LOW) Serial.println("L3");


  // if(rState & JOY_LEFT) Serial.println("R Left");
  // else if(rState & JOY_RIGHT) Serial.println("R Right");
  
  // if(rState & JOY_UP) Serial.println("R Up");
  // else if(rState & JOY_DOWN) Serial.println("D Down");

  // if(rState & JOY_PRESSED) Serial.println("R Pressed!");


  // if(digitalRead(PIN_R1) == LOW) Serial.println("R L1");
  // if(digitalRead(PIN_R2) == LOW) Serial.println("R L2");
  // if(digitalRead(PIN_R3) == LOW) Serial.println("R L3");
  // if(l1 == HIGH) { Serial.println("L1 Pressed!"); }
  // if(l2 == HIGH) { Serial.println("L2 Pressed!"); }
  // if(l3 == HIGH) { Serial.println("L3 Pressed!"); }


  delay(10);
}

