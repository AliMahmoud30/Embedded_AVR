/*
 * Overflow_mode.c
 *
 * Created: 6/28/2022 5:06:08 AM
 *  Author: Morsy
 */ 




//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "GPIO.h"
#include "Timers.h"
#include "std_macros.h"

volatile unsigned short counter;
int main(void)
{
	/*Initialization */
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	/*
	/* Set Normal Mode */
	//CLR_BIT(TCCR0,WGM00);
	//CLR_BIT(TCCR0,WGM01);
	
	/* Set prescaler For Timer0  DIV/1024 */
	//SET_BIT(TCCR0,CS00);
	//CLR_BIT(TCCR0,CS01);
	//SET_BIT(TCCR0,CS02);
	
	/* Set Timer0 Interrupt Enable*/
	//SET_BIT(TIMSK,TOIE0);
	
	/* Set Global Interrupt (I-BIT) */
	//sei();
	
	Timer0_Overflow_Interrupt_Init();
    while(1)
    {
		if (counter>30)
		{
			DIO_Toggle_Pin(A,0);
			counter=0;
		}
       
    }
}
ISR(TIMER0_OVF_vect)
{
	counter++;
}