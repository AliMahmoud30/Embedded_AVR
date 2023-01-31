/*
 * Fast_PWM.c
 *
 * Created: 6/30/2022 10:38:49 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "Timers.h"

int main(void)
{
	Timer0_PWM_init();
	Timer0_PWM_Change(127);
	u8 duty;
	
    while(1)
    {/*
		for (duty=0;duty<255;duty++)
		{		
			Timer0_PWM_Change(duty);
			_delay_ms(20);
		}
		for (duty=255;duty>0;duty--)
		{
			Timer0_PWM_Change(duty);
			_delay_ms(20);
		}
		
		*/

    }
}