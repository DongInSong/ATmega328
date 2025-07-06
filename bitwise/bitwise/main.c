/*
 * bitwise.c
 *
 * Created: 2023-04-11 오후 3:05:12
 * Author : songd
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	//0x01 0x02 0x04 0x08 0x10 0x20 0x40 0x80
	//0x80 0x40 0x20 0x10 0x08 0x04 0x02 0x01
	while (1)
	{
		for(int i = 0; i < 4; i++) {
			char p1 = 0x01 << i;
			char p2 = 0x80 >> i;
				PORTD = p1 | p2;
				_delay_ms(500);
			
		}
	}
}
