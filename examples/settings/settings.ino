#include <settings.h>
#include <addition.h>

Settings settings;
byte load_state = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(A0));
  settings.loadVar(0, load_state);

  if (load_state == 0) {
    byte v = random(256);
    Serial.print("generated:");
    Serial.println(v);
    settings.save(1, v);
    settings.save(0, 1);
  } else {
    Serial.print("loaded:");
    Serial.println(settings.load(1));
    settings.save(0, 0);
  }
}

void loop() {}
