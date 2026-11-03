#include <Arduino.h>
#include "button.h++"

void button_initD(int button) {
  DDRD &= ~(1 << button);
  PORTD |= (1 << button);  
}

int button_readD(int button) {
  return PIND & (1 << button);
}

void button_pullup_enableD(int button) {
  PORTD |= (1 << button);
}

void button_initC(int button) {
  DDRC &= ~(1 << button);
  PORTC |= (1 << button);  
}

int button_readC(int button) {
  return PINC & (1 << button);
}

void button_pullup_enableC(int button) {
  PORTC |= (1 << button);
}

void button_interrupt1_on_falling_edge_enableD() {
  EIMSK |= (1 << INT1);
  EICRA |= (1 << ISC11);
  EICRA &= ~(1 << ISC10);
}
