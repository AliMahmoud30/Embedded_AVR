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

volatile unsigned char counter1;
volatile unsigned char counter2;
volatile unsigned short counter3;

int main(void)
{
	/*Initialization */
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	DIO_Set_Pin_Direction(A,1,OUTPUT);
	DIO_Set_Pin_Direction(A,2,OUTPUT);
	
	
	Timer0_CTC_Interrupt_Init(80);
		
		
    while(1)
    {
		if (counter1>=100)
		{
			DIO_Toggle_Pin(A,0);
			counter1=0;
		}
		if (counter2>=200)
		{
			DIO_Toggle_Pin(A,1);
			counter2=0;
		}
		if (counter3>=300)
		{
			DIO_Toggle_Pin(A,2);
			counter3=0;
		}
		
       
    }
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}