/*
 * Timers.c
 *
 * Created: 6/28/2022 3:15:11 PM
 *  Author: Morsy
 */ 


#include "Timers.h"


void Timer0_CTC_Interrupt_Init(u8 OCR0_Value)
{
	/* Set Output Compare Mode (CTC Mode) */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/* Set prescaler For Timer0 */
	
	TCCR0&=0xF8;					/* clear CS00, CS01 and CS02 before write */
	TCCR0|=TIMER0_CLOCK_SELECT;		/* write Prescaler value without change others bits*/

	/* Load Value to OCR0*/
	OCR0=OCR0_Value;

	/* Set Timer0 Interrupt Enable*/
	SET_BIT(TIMSK,OCIE0);

	/* Set Global Interrupt (I-BIT) */
	SET_BIT(SREG,I_BIT);
}
	