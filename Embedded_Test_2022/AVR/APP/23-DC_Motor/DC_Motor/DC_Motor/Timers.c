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


void Timer0_Wave_Non_PWM(u8 OCR0_Value,u8 OC0_Pin_Mode)
{
	
	/* Set OC0 PIN as OUTPUT Pin */
	DIO_Set_Pin_Direction(B,3,OUTPUT);
	/* Set CTC Mode in TCCR0 Register (WGM00=0, WGM01=1) */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* Set prescaler For Timer0 */
	TCCR0&=0xF8;					/* clear CS00, CS01 and CS02 before write */
	TCCR0|=TIMER0_CLOCK_SELECT;		/* write Prescaler value without change others bits*/
	/* Load OCR0 Value	*/
	OCR0=OCR0_Value;
	/* Set OC0 PIN Mode (Toggle or Clear or Set ) on compare Match */
	TCCR0|=GET_BIT(OC0_Pin_Mode,0)<<COM00;
	TCCR0|=GET_BIT(OC0_Pin_Mode,1)<<COM01;
}
void Timer0_PWM_init(void)
{
	/* Set OC0 PIN(PB3) as OUTPUT PIN */
	DIO_Set_Pin_Direction(B,3,OUTPUT);
	/* Set Fast PWM Mode in TCCR0 Register (WGM00=1, WGM01=1) */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* Set prescaler For Timer0 */
	TCCR0&=0xF8;					/* clear CS00, CS01 and CS02 before write */
	TCCR0|=TIMER0_CLOCK_SELECT;		/* write Prescaler value without change others bits*/
	
	/* Set OC0 PIN Mode (clear on Compare Match, set on Bottom >> COM00=0,COM01=1	 >> Non-Inverting Mode
						 Set on Compare Match, Clear on Bottom >> COM00=1,COM01=1    >> inverting Mode */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void Timer0_PWM_Change(u8 PWM_Value)
{
	/* Load OCR0 Value	*/
	OCR0=PWM_Value;
}
