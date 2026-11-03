#include <Arduino.h>
#include "isr.h++"
#include "leds.h++"

void button_isr() {
  led_toggleC(TASK3_LED_C);
}


ISR(INT1_vect) {
    button_isr();
} 