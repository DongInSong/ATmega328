/*
 * HW4_2.c
 *
 * Created: 2023-05-22 오전 12:06:02
 * Author : songd
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART.h"

volatile int count = 0;
int state = 0;
int i = 0;

ISR(TIMER0_COMPA_vect)
{
	count++;
	TCNT0 = 0;
}

int main(void)
{
	DDRD = 0xFF;
	TCCR0B |= (1 << CS02) | (1 << CS00);
	OCR0A = 128;
	TIMSK0 |= (1 << OCIE0A);
	sei();
	
    while (1) 
    {
		if(count == 64) {
			count = 0;
			if(i < 4 && !state) {
				PORTD = (0x01 << i) | (0x10 << i);
				++i;
			}
			
			else {
				state = 1;
				if(i > 0) {
					--i;
					PORTD = (0x01 << i) | (0x10 << i);
				}
				else state = 0;
			}
		}
    }
}

