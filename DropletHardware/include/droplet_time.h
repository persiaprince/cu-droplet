#ifndef DROPLET_TIME_H
#define DROPLET_TIME_H
#define F_CPU 32000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "scheduler.h"

void Config32MHzClock(void);
void set_current_time(uint16_t count);
void delay_ms(uint16_t ms);

inline uint16_t get_16bit_time(){ return RTC.CNT; }
static inline void delay_us(double __us){ _delay_us(__us); }
	
#endif