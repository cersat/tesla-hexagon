#ifndef SETTINGS_H
#define SETTINGS_H

extern unsigned int eepromSize;

#include <Arduino.h>
#include <EEPROM.h>

class Settings {
public:
    // Инициализатор, можно добавить размер EEPROM для использования в других платах
    Settings(unsigned int size = 1024);

    // Затереть все значения в памяти нулями. Можно выбрать другое значение
    static void resetAll(byte val = 0);
    
    // Сохранить значение по адресу addr
    static void save(int addr, byte val);

    // Сохранить байт по адресу addr
    static void saveBool(int addr, bool val);

    // Прочитать байт с EEPROM
    static byte load(int addr);

    // Загрузить байт по адресу в переменную
    static void loadVar(int addr, byte &var);

    // Прочитать байт с EEPROM, но только в области, задаваемой параметрами
    static byte loadClamped(int addr, byte minVal = 0, byte maxVal = 255);
};

#endif
