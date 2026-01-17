#include <settings.h>
#include <addition.h>
#include <twocolor.h>


void setup() {
  init(115200, A6, false, false)
}

void loop() {
  delay(secFromStart() * 100);
  Serial.print("sec:");
  Serial.println(startTimeByte('s'));
  Serial.print("min:");
  Serial.println(startTimeByte('m'));
  Serial.print("hour:");
  Serial.println(startTimeByte('h'));
  Serial.println(startTime());
}
