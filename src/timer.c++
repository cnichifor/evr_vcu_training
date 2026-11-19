#include "timer.h++"

volatile uint8_t elapsed = 0;

void timer1_init() {
  const uint8_t interrupt_state = SREG;
  sei();

  TCCR1B = 0;
  TCCR1A = 0;
  TCNT1 = 0;
  elapsed = 0;

  const uint32_t f_tmr1 = F_CPU / 256UL;
  OCR1A = f_tmr1 * 0.25 - 1; // Perioada de 550 ms

  TIFR1 = (1 << OCF1A);
  TIMSK1 = (1 << OCIE1A);
  TCCR1B = (1 << CS12) | (1 << WGM12); // CTC, prescaler 256
}

void timer0_init() {
    TCCR0A = (1 << WGM01) | (1 << WGM00)
           | (1 << COM0B1) | (1 << COM0A1);

    TCCR0B = (1 << CS01) | (1 << CS00);

    OCR0B = 0;
}

ISR(TIMER1_COMPA_vect) {
  elapsed = 1; 
}
