#include <Arduino.h>

#include "leds.h++"

void led_initD(int led) {
  DDRD |= (1 << led);
  PORTD &= ~(1 << led);
}

void led_initC(int led) {
  DDRC |= (1 << led);
  PORTC &= ~(1 << led);
}

void led_setD(int led) {
  PORTD |= (1 << led);
}

void led_resetD(int led) {
  PORTD &= ~(1 << led);
}

void led_toggleD(int led) {
  PORTD ^= (1 << led);
}

void led_setC(int led) {
  PORTC |= (1 << led);
}

void led_resetC(int led) {
  PORTC &= ~(1 << led);
}

void led_toggleC(int led) {
  PORTC ^= (1 << led);
}

