/*
 * Timer2_CTC_Mode.c
 *
 * Created: 7/2/2022 4:32:36 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

#include "std_macros.h"

volatile unsigned char Counter1;
volatile unsigned char Counter2;
volatile unsigned short Counter3;

int main(void)
{
	
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	
	SET_BIT(DDRD,7);
	/* Initialization  Timer2*/
	
	/* Set CTC Mode */
	SET_BIT(TCCR2,WGM21);
	/* Set Prescaler DIV/1024*/
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	/* Load Value in OCR2 Register */
	OCR2=80;
	
	SET_BIT(TCCR2,COM20);
	
	/* Set CTC Interrupt Enable bit*/
	SET_BIT(TIMSK,OCIE2);
	/* Set Global Interrupt bit (I-BIT) */
	sei();
	/*-----------------------------------------------------*/
	
	
	
    while(1)
    {
		if (Counter1>100)
		{
			TOG_BIT(PORTA,0);
			Counter1=0;
		}
		if (Counter2>200)
		{
			TOG_BIT(PORTA,1);
			Counter2=0;
		}
		if (Counter3>300)
		{
			TOG_BIT(PORTA,2);
			Counter3=0;
		}
        
    }
}


ISR(TIMER2_COMP_vect)
{
	Counter1++;
	Counter2++;
	Counter3++;
}