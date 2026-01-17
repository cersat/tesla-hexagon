#include "settings.h"

unsigned int eepromSize = 1024;

Settings::Settings(unsigned int size) {
    eepromSize = size;
}

void Settings::loadVar(int addr, byte &var) {
    if (addr >= 0 && addr < 1024) {
        var = EEPROM.read(addr);
    }
}

void Settings::resetAll(byte val) {
    for (int i = 0; i < 1024; i++) {
        EEPROM.update(i, val);
    }
}

void Settings::save(int addr, byte val) {
    if (addr >= 0 && addr < 1024) {
        EEPROM.update(addr, val);
    }
}

void Settings::saveBool(int addr, bool val) {
    if (addr >= 0 && addr < 1024) {
        EEPROM.update(addr, val);
    }
}

byte Settings::load(int addr) {
    if (addr >= 0 && addr < 1024) {
        return EEPROM.read(addr);
    }
    return 0;
}

byte Settings::loadClamped(int addr, byte minVal, byte maxVal) {
  byte v = EEPROM.read(addr);
  if (v < minVal) {
    return minVal;
  }
  if (v > maxVal) {
    return maxVal;
  }
  return v;
}

