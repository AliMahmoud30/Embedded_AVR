/*
 * nested_interrupt.c
 *
 * Created: 6/13/2022 10:16:22 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"
#include <avr/interrupt.h>


#include "HButton.h"
#include "HLED.h"

#include "std_macros.h"

#define SREG	*((volatile unsigned char*)(0x5F))

int main(void)
{
	LED_init(A,0);
	LED_init(A,1);
	LED_init(A,2);
	
	Button_init(D,2);    /* PIN INT0   */
	Button_init(D,3);    /* PIN INT1   */
	Button_init(B,2);   /*  PIN INT2   */
	
	SET_BIT(SREG,7);    /* SET I-BIT for Global Interrupt */
	
	/* SET INT0 */
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	SET_BIT(GICR,INT0);
	
	/* SET INT1 */
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(GICR,INT1);
	
	/* SET INT2 */
	SET_BIT(GICR,INT2);
	SET_BIT(MCUCSR,ISC2);
	
	
    while(1)
    {
       LED_OFF(A,0);
	   LED_OFF(A,1);
	   LED_OFF(A,2);
	   
    }
}

ISR(INT0_vect)
{
	sei();
	LED_ON(A,0);
	_delay_ms(2000);
}


ISR(INT1_vect)
{
	sei();
	LED_ON(A,1);
	_delay_ms(2000);
	
}

ISR(INT2_vect)
{
	sei();
	LED_ON(A,2);
	_delay_ms(2000);
	
}

