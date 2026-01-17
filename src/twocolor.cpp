#include "twocolor.h"

bool invertColorLed = false;
byte pin1 = 3;
byte pin2 = 6;

void TwoColorLed::control(TwoColorLedColor color) {
  if(!invertColorLed) {
    digitalWrite (pin1, color == Red);
    digitalWrite (pin2, color == Green);
  } else {
    digitalWrite (pin2, color == Red);
    digitalWrite (pin1, color == Green);
  }
}

void TwoColorLed::setRed() {
  if(!invertColorLed) {
    digitalWrite (pin1, 1);
    digitalWrite (pin2, 0);
  } else {
    digitalWrite (pin2, 1);
    digitalWrite (pin1, 0);
  }
}

void TwoColorLed::setGreen() {
  if(!invertColorLed) {
    digitalWrite (pin1, 0);
    digitalWrite (pin2, 1);
  } else {
    digitalWrite (pin2, 0);
    digitalWrite (pin1, 1);
  }
}

void TwoColorLed::disable() {
  digitalWrite (pin1, 0);
  digitalWrite (pin2, 0);
}

void TwoColorLed::blink(TwoColorLedColor color, int time, TwoColorLedColor endColor) {
  if(!invertColorLed) {
    digitalWrite (pin1, color == Red);
    digitalWrite (pin2, color == Green);
  } else {
    digitalWrite (pin2, color == Red);
    digitalWrite (pin1, color == Green);
  }
  delay(1000);

  digitalWrite (pin2, 0);
  digitalWrite (pin1, 0);
}

void TwoColorLed::pinSet(byte p1, byte p2) {
	pin1 = p1;
	pin2 = p2;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void TwoColorLed::invert(bool invertion) {
	invertColorLed = invertion;
}