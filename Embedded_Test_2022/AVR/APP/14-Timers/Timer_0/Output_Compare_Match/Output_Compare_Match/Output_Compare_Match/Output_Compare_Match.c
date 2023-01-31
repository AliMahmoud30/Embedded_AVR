/*
 * Output_Compare_Match.c
 *
 * Created: 6/30/2022 3:45:28 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include "Timers.h"

int main(void)
{
	Timer0_Wave_Non_PWM(64,TOGGLE);	
    while(1)
    {
      
		
	}
}