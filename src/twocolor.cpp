#include "twocolor.h"

bool invertColorLed = false;
byte pin1 = 3;
byte pin2 = 6;

void TwoColorLed::control(TwoColorLedColor color) {
  digitalWrite (pin1, color == Red);
  digitalWrite (pin2, color == Green);
}

void TwoColorLed::setRed() {
  digitalWrite (pin1, 1);
  digitalWrite (pin2, 0);
}

void TwoColorLed::setGreen() {
  digitalWrite (pin1, 0);
  digitalWrite (pin2, 1);
}

void TwoColorLed::disable() {
  digitalWrite (pin1, 0);
  digitalWrite (pin2, 0);
}

void TwoColorLed::blink(TwoColorLedColor color, int time) {
  digitalWrite (pin1, color == Red);
  digitalWrite (pin2, color == Green);
  delay(time);

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
	if (invertColorLed != invertion) {
    int prep2 = pin1;
    int prep1 = pin2;
    pin1 = prep1;
    pin2 = prep2;
    invertColorLed = invertion;
  }
}
