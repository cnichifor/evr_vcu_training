#include <Arduino.h>
#include "adc.h++"

void adc_init(int adc_pin) {
    // 5v ref
    ADMUX = (1 << REFS0) | (1 << ADLAR) | (adc_pin & 0x07);
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}