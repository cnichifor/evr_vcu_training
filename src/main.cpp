#include <Arduino.h>

#include "leds.h++"
#include "button.h++"
#include "task.h++"

void setup() {
  task1_init();
  task2_init();
  task3_init();
}

void loop() {
  task1();
  task2();
}



