/*
 * LEDs.c
 *
 * Created: 5/21/2022 12:21:43 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "HLED.h"

int main(void)
{
	LED_init(A,0);
	
    while(1)
    {
		LED_ON(A,0);
		_delay_ms(1000);
		LED_OFF(A,0);
		_delay_ms(1000);
		
         
    }
}