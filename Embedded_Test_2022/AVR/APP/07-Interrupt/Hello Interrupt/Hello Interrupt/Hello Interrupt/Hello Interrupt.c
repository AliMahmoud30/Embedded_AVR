/*
 * Hello_Interrupt.c
 *
 * Created: 6/12/2022 3:13:26 PM
 *  Author: Morsy
 */ 


#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include <util/delay.h>



//#include "EXT_Interrupt.h"
#include "HButton.h"
#include "HLED.h"


int main(void)
{
	SREG|=(1<<7);					 /*Set I-bit (Global Interrupt) */
	
	/*Set Sense control for Rising Edge */
	MCUCR|=(1<<ISC00)|(1<<ISC01);    
	 
	 /*Set Sense control for Falling Edge */
	//MCUCR|=(1<<ISC01);   
	//MCUCR&=~(1<<ISC00);
	
	 /*Set Sense control for any Change*/
	//MCUCR|=(1<<ISC00); 
	//MCUCR&=~(1<<ISC01); 
	
	 /*Set Sense control for Low Level */
	//MCUCR&=~(1<<ISC00); 
	//MCUCR&=~(1<<ISC01);
	   
	GICR|=(1<<INT0);			     /*Set Enable Bit For INT0 */
	
	
	LED_init(A,0);
	Button_init(D,2);
	
    while(1)
    {
    LED_OFF(A,0);
	
    }
}


ISR(INT0_vect)
{
	
	LED_ON(A,0);
	_delay_ms(1000);
	sei();
}



/*
void __vector_1(void) __attribute((signal,used)) __attribute((naked));

void __vector_1(void)
{
	
	LED_ON(A,0);
	_delay_ms(1000);
	sei();
}

*/
