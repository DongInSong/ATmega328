#include "modules.h"

uint8_t measure_distance(void) {
	PORTC |= (1 << PC0);
	_delay_ms(10);
	PORTC &= ~(1 << PC0);
	
	TCNT0 = 0;
	while(!(PINC & 0x02))
	if(TCNT0 > 250) return 255;
	
	TCNT0 = 0;
	while(PINC & 0x02) {
		if(TCNT0 > 250) {
			TCNT0 = 0;
			break;
		}
	}
	double pulse_width = TCNT0 * PERSCALER * 1000000.0 / F_CPU;
	
	return pulse_width / 58;
}

void INIT_PORT(void) {
	// Button (pull up)
	DDRC = 0x00;
	PORTC = 0x20;
	
	// leds
	DDRD |= 0x08;
	PORTD &= ~0x08;
	DDRB |= 0x38;
	PORTB &= ~0x38;
	DDRC |= 0x18;
	PORTC &= ~0x18;
	
	// Sensor Output
	DDRC |= 0x01;
}

void INIT_PCINT1(void) {
	PCICR |= (1 << PCIE1);
	PCMSK1 |= (1 << PCINT13);
	sei();
}

void INIT_TIMER0(void) {
	TCCR0B |= (1 << CS02) | (1 << CS00);
}


void INIT_TIMER1(void) {
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
	
	TCCR1B |= (1 << CS11);
	
	ICR1 = 40000;
	TCCR1A |= (1 << COM1A1);
	DDRB |= 0x02;
}