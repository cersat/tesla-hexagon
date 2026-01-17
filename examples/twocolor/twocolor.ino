#include <settings.h>
#include <addition.h>
#include <twocolor.h>

TwoColorLed tcl;

void setup() {
  tcl.pinSet();
  tcl.invert(true);
  tcl.disable();
  randomSeed(analogRead(A7));
  tcl.setRed();
  delay(1000);
  tcl.setGreen();
  delay(2000);
}
void loop() {
  tcl.control(Red);
  delay(1000);
  tcl.control(Green);
  delay(1000);
  tcl.control(Off);
  delay(1000);
}