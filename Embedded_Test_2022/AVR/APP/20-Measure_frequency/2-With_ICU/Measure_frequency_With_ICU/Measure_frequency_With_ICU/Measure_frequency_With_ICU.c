/*
 * Measure_frequency_With_ICU.c
 *
 * Created: 7/4/2022 4:20:50 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"
#include "std_macros.h"

unsigned long T_Period;
unsigned short Frequency;
unsigned char Duty_Cycle;

unsigned short a;
unsigned short b;
unsigned short c;
unsigned short T_ON;
unsigned short T_OFF;

void Send_Val_to_LCD(u32 u16_Value);

int main(void)
{
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Time=");
	LCD_move_cursor(2,1);
	LCD_send_string("Frequency=");
	CLR_BIT(DDRD,6);
	SET_BIT(TCCR1B,CS11);	   /* Prescaler DIV_8 */
	//SET_BIT(TCCR1B,CS10);
	SET_BIT(TIFR,ICES1);			/* Reset ICF1 flag  */
	
	SET_BIT(TCCR1B,CS11);	   /* start Timer >> Prescaler DIV_8 */
	SET_BIT(TCCR1B,ICES1);     /* Set Input Capture Edge Select to detect rising edge*/
	while (GET_BIT(TIFR,ICF1)==0); /* wait until ICF1 to set 1 */
	SET_BIT(TIFR,ICES1);			/* Reset ICF1 flag  */
	a=ICR1;

	CLR_BIT(TCCR1B,ICES1);     /* Set Input Capture Edge Select to detect Falling edge*/
	while (GET_BIT(TIFR,ICF1)==0); /* wait until ICF1 to set 1 */
	SET_BIT(TIFR,ICES1);			/* Reset ICF1 flag  */
	b=ICR1;
			
	SET_BIT(TCCR1B,ICES1);     /* Set Input Capture Edge Select to detect rising edge*/
	//SET_BIT(TCCR1B,CS11);	   /* Prescaler DIV_8 */
	while (GET_BIT(TIFR,ICF1)==0); /* wait until ICF1 to set 1 */
	SET_BIT(TIFR,ICES1);			/* Reset ICF1 flag  */
	c=ICR1;
			
	CLR_BIT(TCCR1B,CS11); /* stop Timer */
	
	if (a<b && b<c)
	{
		//LCD_clear();
		T_ON=b-a;
		T_OFF=c-b;
				
		T_Period=T_ON+T_OFF;
		//T_Period=T_Period*(8.0/F_CPU);
		Duty_Cycle=((float)T_ON/T_Period)*100;
		//Frequency=1.0/((float)T_Period);
		Frequency=F_CPU/(T_Period*8.0);
				
				
		LCD_move_cursor(1,6);
		Send_Val_to_LCD(Duty_Cycle);
		LCD_send_char('%');
		LCD_move_cursor(2,11);
		Send_Val_to_LCD(Frequency);
		LCD_send_string("Hz");
	}
	else
	{
		LCD_clear();
		LCD_send_string("Out of Range");
	}
    while(1)
    {

		
		
    }
}
void Send_Val_to_LCD(u32 u16_Value)
{
	if (u16_Value<10)
	{
		LCD_send_char(48);
		LCD_send_char(48);
		LCD_send_char(48);
		LCD_send_char(u16_Value+48);
	}
	else if(u16_Value<100)
	{
		LCD_send_char(48);
		LCD_send_char(48);
		LCD_send_char((u16_Value/10)+48);
		LCD_send_char((u16_Value%10)+48);
	}
	else if(u16_Value<1000)
	{
		LCD_send_char(48);
		LCD_send_char((u16_Value/100)+48);
		LCD_send_char(((u16_Value/10)%10)+48);
		LCD_send_char((u16_Value%10)+48);
	}
	else if(u16_Value<10000)
	{
		LCD_send_char((u16_Value/1000)+48);
		LCD_send_char(((u16_Value/100)%10)+48);
		LCD_send_char(((u16_Value/10)%10)+48);
		LCD_send_char((u16_Value%10)+48);
	}

}