#include "addition.h"
#include "twocolor.h"
#include "HexagonPins.h"

long timer = 0;

bool buttonPress (int btn) {
  if (btn == 1) return (!digitalRead(sensors_b1));
  if (btn == 2) return (!digitalRead(sensors_b2));
  if (btn == 3) return (!digitalRead(sensors_b3));
  return 0;
}

long secFromStart () {
  return millis() / 1000;
}

int minFromStart () {
  return millis() / 1000 / 60;
}

byte hourFromStart () {
  return millis() / 1000 / 60 / 60;
}

byte startTimeByte(char ret, unsigned long add) {
  unsigned long seconds = millis() / 1000 + add;

  switch (ret) {
    case 's':
      return seconds % 60;

    case 'm':
      return (seconds / 60) % 60;

    case 'h':
      return (seconds / 3600) % 24;

    default:
      return 0;
  }
}

time startTime(unsigned long add) {
  unsigned long seconds = millis() / 1000 + add;
  return {seconds % 60, (seconds / 60) % 60, (seconds / 3600) % 24};
}

int init(unsigned long baud, uint8_t unused_pin, bool invertTCC, bool checkEEPROM, bool blinkLED) {

    uint8_t err = 0;
    // 1. Serial
    Serial.begin(baud);
#if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAM_DUE)
    unsigned long start = millis();
    while(!Serial){
      if(millis() - start > 2000) {
        err = 1;
        break; // Serial не стартанул за 2 сек
      }
    }
#endif

    // 2. Random seed
    unsigned long seed = analogRead(unused_pin) ^ millis();
    randomSeed(seed);

    // 3. EEPROM (опционально)
    if(checkEEPROM){
      if(EEPROM.read(0) != 151){
        err = 2; // EEPROM «битая» или не инициализирована
      }
    }

    // 4. Инвертация двухцветного светодиода
    TwoColorLed::pinSet(3, 6);
    TwoColorLed::invert(invertTCC);
    TwoColorLed::disable();
    
    // Моргание светодиодом для показа ошибок
    pinMode(LED_BUILTIN, OUTPUT);
    if(blinkLED){
      for (int i = 0; i > err; i++) {
        digitalWrite(LED_BUILTIN,HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN,LOW);
        delay(100);
      }
    }
    // 0 = всё ок
    return err;
}

void startTimer() {
  timer = millis();
}

long getTimer() {
  return millis() - timer;
}

void endTimer() {
  timer = 0;
}
