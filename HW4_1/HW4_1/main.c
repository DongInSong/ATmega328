/*
 * HW4_1.c
 *
 * Created: 2023-05-21 오후 11:39:00
 * Author : songd
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART.h"

volatile int count = 0;
int button = 0x08 | 0x20 | 0x80;
int state = 0;

ISR(PCINT2_vect)
{
	if(PIND & 0x08) count++; else count++;
	state = 0;
	_delay_ms(100);
}

void INIT_PORT(void)
{
	DDRB = 0x20;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD |= button;
}

void INIT_PCINT2(void)
{
	PCICR |= (1 << PCIE2);
	PCMSK2 |= (1 << PCINT19) | (1 << PCINT21) | (1 << PCINT23);
	sei();
}

int main(void)
{
		INIT_PORT();
		INIT_PCINT2();    
		UART_INIT();
		while (1) 
    {
		if(count > 0 && !(count % 3) && !state) {
			state = 1;
			UART_printString("Current Count: ");
			UART_printNumber(count);
			UART_transmit('\n');
		}
		_delay_ms(100);
    }
}

