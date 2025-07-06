/*
 * H3_2.c
 *
 * Created: 2023-04-30 오후 9:27:30
 * Author : songd
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void ADC_INIT(unsigned char c) {
	ADMUX |= 0x40;
	
	ADCSRA |= 0x07;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADATE);
	
	ADMUX |= ((ADMUX & 0xE0) | c);
	ADCSRA |= (1 << ADSC);
}

int read_ADC(void) {
	while(!(ADCSRA & (1 << ADIF)));
	return ADC;
}

void PORT_INIT() {
	DDRD = 0xFF;
	PORTD = 0x00;
}

int main(void)
{
	int value;

	ADC_INIT(0);
	PORT_INIT();
	
    while (1) 
    {
		value = read_ADC() >> 7;
		PORTD = 0x01 << value;
		_delay_ms(10);
    }
}

