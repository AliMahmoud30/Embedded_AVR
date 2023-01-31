/*
 * Stepper_Motor.c
 *
 * Created: 7/6/2022 5:30:42 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "std_macros.h"
int main(void)
{
	DDRD=0x0F;
    while(1)
    {
		SET_BIT(PORTD,0);
		_delay_ms(1000);
		
		SET_BIT(PORTD,1);
		_delay_ms(1000);
		
		CLR_BIT(PORTD,0);
		_delay_ms(1000);
		
		SET_BIT(PORTD,2);
        _delay_ms(1000);
		
		CLR_BIT(PORTD,1);
		_delay_ms(1000);
	
		SET_BIT(PORTD,3);
		_delay_ms(1000);
		
		CLR_BIT(PORTD,2);
		_delay_ms(1000);
		
		SET_BIT(PORTD,0);
		_delay_ms(1000);
		
		CLR_BIT(PORTD,3);
		
    }
}