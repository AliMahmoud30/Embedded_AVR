/*
 * Phase_Correct_PWM.c
 *
 * Created: 7/1/2022 1:44:08 AM
 *  Author: Ali Morsy
 */ 


//#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "GPIO.h"
#include "Timers.h"

volatile unsigned char Counter;
int main(void)
{
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	Timer0_Phase_Correct_PWM(64);
	
	TIMSK|=1<<OCIE0;
	sei();
	
    while(1)
    {/*
        if (Counter>=100)
        {
			DIO_Toggle_Pin(A,0);
			Counter=0;
        }*/

    }
	
	
}
ISR(TIMER0_COMP_vect)
{
	Counter++;
}