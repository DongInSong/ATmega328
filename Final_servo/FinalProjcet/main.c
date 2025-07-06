/*
 * FinalProjcet.c
 *
 * Created: 2023-06-16 오후 11:58:39
 * Author : songd
 */ 
#include "TEXT_LCD.h"
#include "UART.h"
#include "modules.h"

volatile int isPressing = 0;
int isOpen = 0;
uint8_t distance;
char *num = "12345";

// 3 PORTB green lights
unsigned char led_B[] = {0x08, 0x10, 0x20};
// 2 PORTC green lights
unsigned char led_C[] = {0x08, 0x10};
	
ISR(PCINT1_vect) {
	if(PINC & 0x20) {
		isPressing = 0;
	}
	else {
		isPressing = 1;
	}
}

void ShowOpenText() {
	LCD_clear();
	LCD_write_string("Welcome!! - ");
}

void active_led() {
	if(isOpen) {
		// red light off
		PORTD &= ~0x08;
	}
	else {
		// green lights off, red light on
		PORTD |= 0x08;
		PORTB &= ~0x38;
		PORTC &= ~0x18;
	}
}

void active_Door(uint8_t sec) {
	uint8_t i;
	// open door
	isOpen = 1;
	OCR1A = PULSE_MAX;
	for(i = 0; i < sec; i++) {
		// for check distance in for loop;
		distance = measure_distance();
		
		// button press, distance check, reset door time
		if(isPressing || (distance >= 5 && distance <= 15)) {
			i = 0;
			PORTB &= ~0x38;
			PORTC &= ~0x18;
		}
		
		// green lights on
		if(i < 3) {
			PORTB |= led_B[i];
		}
		else {
			PORTC |= led_C[i - 2];
		}
		
		// show texts
		ShowOpenText();
		LCD_write_data(num[i]);
		
		// delay 1000ms
		_delay_ms(ROTATION_DELAY);
	}
	// close door
	isOpen = 0;
	OCR1A = PULSE_MIN;
	LCD_clear();
}

uint8_t MODE = 4;

int main(void)
{
	
	LCD_init();
	LCD_write_string("Initializing...");

	INIT_PORT();
	INIT_PCINT1();
	
	UART_INIT();
	INIT_TIMER1();
	INIT_TIMER0();
	
	
	while (1)
	{
		distance = measure_distance();
		
		active_led();
		
		if(isPressing || (distance >= 5 && distance <= 15)) {
			active_Door(5);
			_delay_ms(10);
		}
	_delay_ms(100);
}

}