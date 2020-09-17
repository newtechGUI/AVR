/*
 * pwm_ledRGB.c
 *
 * Created: 13-06-20 10:17:29
 * Author : newtechGUI
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// initialize PWM
void pwm_init(void)
{
		
	DDRB = (1<<PB5)|(1<<PB6)|(1<<PB7); // output PWM on 0C1A pin 11 PWM - OC1B pin 12 PWM - OC1C pin 13 PWM
	
	// initialize timer1 in PWM mode
	// Digital Pin 11 PWM - OC1A
	// Timer 1 - Fast PWM 8bits
	// COM1A1 : 1 & COM1A0 : 0 - clear OC1A on compare match - for red color
	// COM1B1 : 1 & COM1B0 : 0 - clear OC1B on compare match - for blue color
	// COM1C1 : 1 & COM1C0 : 0 - clear OC1C on compare match - for green color
	// WGM11 : 0 & WGM10 : 1 - fast PWM 8 bits
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)|(1<<COM1C1)|(0<<COM1C0)|(0<<WGM11)|(1<<WGM10); 
	
	// WGM13 : 0 & WGM12 : 1 - fast PWM
	// CS12 : 0 ; CS11 : 0 ; CS10 : 1 - no prescaling
	TCCR1B = (0<<ICNC1)|(0<<ICES1)|(0<<WGM13)|(1<<WGM12)|(0<<CS12)|(0<<CS11)|(1<<CS10);
}

void redColor(void)
{
	OCR1A = 255; // red R = 255
	OCR1B = 0; // blue B = 0
	OCR1C = 0; // green G = 0
}

void blueColor(void)
{
	OCR1A = 0; // red R = 0
	OCR1B = 255; // blue B = 255
	OCR1C = 0; // green G = 0
}

void greenColor(void)
{
	OCR1A = 0; // red R = 0
	OCR1B = 0; // blue B = 0
	OCR1C = 255; // green G = 255
}

// for a custom color
void RGBColor(int red, int blue, int green)
{
	OCR1A = red; // comparison value red color
	OCR1B = blue; // comparison value blue color
	OCR1C = green; // comparison value green color
}

int main(void)
{
	
	pwm_init();
	
	while (1)
	{
		redColor();
		_delay_ms(1000);
		
		greenColor();
		_delay_ms(1000);
		
		blueColor();
		_delay_ms(1000);
		
		// example R: 127; B: 127; G: 0
		RGBColor(127, 127, 0);
		_delay_ms(1000);
		
	}
}




