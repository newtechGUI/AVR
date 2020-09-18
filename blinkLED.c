/*
 * clignotement_LED.c
 *
 * Created: 25-11-19 20:17:05
 * Author : newtechGUI
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	
    while (1) 
    {
		
		PORTC = DDRC;
		_delay_ms(30);
		PORTC = ~PORTC;
		_delay_ms(1000);
		
    }
}

