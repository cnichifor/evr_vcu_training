#include <Arduino.h>

#include "button.h++"
#include "leds.h++"
#include "task.h++"
#include "isr.h++"

void setLedsState(uint8_t state) {
  led_resetD(TASK1_LED1_D);
  led_resetD(TASK1_LED2_D);
  led_resetD(TASK1_LED3_D);

  if (state >= 1) {
    led_setD(TASK1_LED1_D);
  }
  if (state >= 2) {
    led_setD(TASK1_LED2_D);
  }
  if (state >= 3) {
    led_setD(TASK1_LED3_D);
  }
}


void task1() {
  static uint8_t state = 0;

  for (volatile uint32_t i = 0; i < 100000; ++i) {
  }

  setLedsState(state);
  state = (state + 1) % 4;
}

void task2() {
  static bool ledState = false;
  static bool buttonWasPressed = false;

  if (!button_readC(TASK2_BUTTON_C)) {
    buttonWasPressed = true;
  } else if (buttonWasPressed) {
    ledState = !ledState;
    buttonWasPressed = false;
  }

  if (ledState) {
    led_setC(TASK2_LED1_C);
    led_resetC(TASK2_LED2_C);
  } else {
    led_resetC(TASK2_LED1_C);
    led_setC(TASK2_LED2_C);
  }

  for (volatile uint32_t i = 0; i < 10000; ++i) {}
}



// Init tasks
void task1_init() {
  led_initD(TASK1_LED1_D);
  led_initD(TASK1_LED2_D);
  led_initD(TASK1_LED3_D);
}

void task2_init() {
  led_initC(TASK2_LED1_C);
  led_initC(TASK2_LED2_C);

  button_initC(TASK2_BUTTON_C);
  button_pullup_enableC(TASK2_BUTTON_C);
}

void task3_init() {
  led_initC(TASK3_LED_C);
  button_initD(TASK3_BUTTON_D);
  button_pullup_enableD(TASK3_BUTTON_D);
  button_interrupt1_on_falling_edge_enableD();

  sei();
}
