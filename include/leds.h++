#ifndef _LEDS_H_
#define _LEDS_H_

#define TASK1_LED1_D 2
#define TASK1_LED2_D 4
#define TASK1_LED3_D 7

#define TASK2_LED1_C 4
#define TASK2_LED2_C 5

#define TASK3_LED_C 3

void leds_initD();
void led_initD(int led);

void leds_initC();
void led_initC(int led);

void led_setD(int led);
void led_resetD(int led);
void led_toggleD(int led);

void led_setC(int led);
void led_resetC(int led);
void led_toggleC(int led);

#endif
