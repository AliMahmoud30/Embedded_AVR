/*
 * RESET.c
 *
 * Created: 6/15/2022 1:49:08 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "HButton.h"
#include "HLED.h"


int main(void)
{
	LED_init(A,0);
	LED_init(A,1);
	LED_init(A,2);
	
    while(1)
    {
		LED_ON(A,0);
		_delay_ms(1000);
		LED_ON(A,1);
		_delay_ms(1000);
		LED_ON(A,2);
		_delay_ms(1000);
		
		
		
		LED_OFF(A,0);
		_delay_ms(1000);
		LED_OFF(A,1);
		_delay_ms(1000);
		LED_OFF(A,2);
		_delay_ms(1000);
		
	}
}