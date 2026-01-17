#ifndef TWOCOLOR_H
#define TWOCOLOR_H

#include <Arduino.h>

enum TwoColorLedColor{Off, Red, Green};
extern bool invertColorLed;
extern byte pin1;
extern byte pin2;

class TwoColorLed {
public:
  //! @param color - Цвет двухцветного светодиода. Использует константы вида: Off, Green, Red
  // Управление двухцветным светодиодом.
  static void control(TwoColorLedColor color);

  // Задать двухцветному светодиоду красный цвет
  static void setRed();

  // Задать двухцветному светодиоду зелёный цвет
  static void setGreen();

  // Выключить двухцветный светодиод
  static void disable();

  //! @param color - Цвет мигающего двухцветного светодиода. Использует константы вида: Off, Green, Red
  //! @param time - Время до окончания мигания.
  //! @param endColor - Необязательный параметр, обозначающий цвет после завершения мигания. По умолчанию выключает светодиод
  // Мигать двухцветным светодиодом с указанным цветом
  static void blink(TwoColorLedColor color, int time, TwoColorLedColor endColor = Off);

  //! @param p1 - Первый пин двухцветного светодиода
  //! @param p2 -
  // Задать пины для двухцветного светодиода
  static void pinSet(byte p1 = 3, byte p2 = 6);

  // Инвертировать двухцветный светодиод
  static void invert(bool invertion);
};

#endif
