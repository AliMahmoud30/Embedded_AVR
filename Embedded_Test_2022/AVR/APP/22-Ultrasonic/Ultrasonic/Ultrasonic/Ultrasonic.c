/*
 * Ultrasonic.c
 *
 * Created: 7/5/2022 3:54:17 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>

#include "std_macros.h"

#include "GPIO.h"
#include "LCD.h"


#define TRIGGER_PIN		0
#define ECHO_PIN		6

unsigned long Distance;
unsigned short a;
unsigned short b;
unsigned short T_HIGH;


void Send_Val_to_LCD(u32 u16_Value);

int main(void)
{	/* LCD Init  */
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Distance=");
	
	/*Set Trigger Pin as Output */
	DIO_Set_Pin_Direction(D,TRIGGER_PIN,OUTPUT);
	//DIO_Set_Pin_Direction(D,ECHO_PIN,INPUT);
	
    while(1)
    {
		TCCR1A=0;
		/*Clear ICIF */
		SET_BIT(TIFR,ICF1);
		
		/* Send Trigger */	
		DIO_Set_Pin_Value(D,TRIGGER_PIN,HIGH);
		_delay_us(30);
		DIO_Set_Pin_Value(D,TRIGGER_PIN,LOW);
	
		
		/* Start Timer with >> no prescaler, noise canceler, Input capture unite to Rising edge */
		TCCR1B=0xc1;
		/* wait flag to become one*/
		while (GET_BIT(TIFR,ICF1)==0);
		a=ICR1;
		/* clear TIFR1 flag*/
		SET_BIT(TIFR,ICF1);
		
		/* Change ICU to detect falling edge */
		TCCR1B=0X81;
		/* wait flag to become one*/
		while (GET_BIT(TIFR,ICF1)==0);
		b=ICR1;
		/* clear TIFR1 flag*/
		SET_BIT(TIFR,ICF1);
		
		/*clear timer/counter1 */
		TCNT1=0;
		/* Stop Timer1*/
		TCCR1B=0;
		
		/* Calculate Distance*/
		T_HIGH=b-a;
		Distance=(T_HIGH*34600)/(F_CPU*2.0);
		LCD_move_cursor(1,10);
		Send_Val_to_LCD(Distance);
		LCD_move_cursor(2,1);
		Send_Val_to_LCD(T_HIGH);
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