/*
 * modules.h
 *
 * Created: 2023-06-17 오전 1:50:31
 *  Author: songd
 */ 
#ifndef MODULES_H_
#define MODULES_H_

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define PERSCALER 1024

#define ROTATION_DELAY 1000
#define PULSE_MIN 1300
#define PULSE_MAX 4700

uint8_t measure_distance(void);

void INIT_PORT(void);
void INIT_PCINT1(void);

// Survo, Sensor timer 
void INIT_TIMER1(void);
void INIT_TIMER0(void);

#endif /* MODULES_H_ */