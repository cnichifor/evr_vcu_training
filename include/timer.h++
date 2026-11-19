#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

extern volatile uint8_t elapsed;
extern volatile uint8_t elapsed_pwm;

void timer1_init();
void timer0_init();

#endif
