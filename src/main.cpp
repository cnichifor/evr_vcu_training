#include <Arduino.h>

#include "task.h++"
#include "leds.h++"

void setup() {
  task1_init();
  task2_init();
  task3_init();
  task4_init();
  task5_init();
  task6_init();
}

void loop() {
  task1();
  task2();
  task4();
  // task5();
  task6();
}



