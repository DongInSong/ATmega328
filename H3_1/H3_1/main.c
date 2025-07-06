/*
 * H3_1.c
 *
 * Created: 2023-04-30 오후 5:00:25
 * Author : songd
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "UART.h"

int main(void)
{
	DDRB = 0x00; // PB1 ~ PB4
	UART_INIT();
	unsigned char key;
	char ox[5] = "XXXX";
	
	while (1)
	{
		key = PINB & 0xDF; // 0010 0000 & 1101 1111 = 0000 0000
		
		// 0000 0010
		// 0000 0100
		// 0000 1000
		// 0001 0000
		
		for(int i = 0; i < 4; i++) {
			if(key & (0x1 << (i + 1))) { // 비트 검사
				ox[i] = 'O';
			}
			else ox[i] = 'X';
		}
		
		for(int i = 0; i < 4; i++) {
			UART_transmit(ox[i]);
			UART_transmit(' ');
		}
		UART_printString("\n");
		_delay_ms(2000);
	}
}

