/*
 * pwm_brightnessLED.c
 *
 * Created: 12-06-20 19:46:44
 * Author : newtechGUI
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// initialize PWM
void pwm_init(void)
{
	
		
	DDRB = (1<<PB5); // output mode PWM on 0C1A pin 11 PWM
	
	// initialize timer1 in PWM mode
	// Digital Pin 11 PWM - OC1A
	// Timer 1 - Fast PWM 8bits
	// COM1A1 : 1 et COM1A0 : 0 - clear l'OC1A on compare match
	// WGM11 : 0 et WGM10 : 1 - fast PWM 8 bits
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B1)|(0<<COM1B0)|(0<<COM1C1)|(0<<COM1C0)|(0<<WGM11)|(1<<WGM10); 
	
	// WGM13 : 0 & WGM12 : 1 - fast PWM
	// CS12 : 0 ; CS11 : 0 ; CS10 : 1 - no prescaling
	TCCR1B = (0<<ICNC1)|(0<<ICES1)|(0<<WGM13)|(1<<WGM12)|(0<<CS12)|(0<<CS11)|(1<<CS10);

}

int main(void)
{
	
	unsigned char duty;
	
	pwm_init();
	
	while (1)
	{

		for(duty = 0; duty < 255; duty++)
		{

			OCR1A = duty;
			
			_delay_ms(2);
		}
		

		for(duty = 255; duty > 0; duty--)
		{

			OCR1A = duty;
			
			_delay_ms(2);
		}
		
	}
}


