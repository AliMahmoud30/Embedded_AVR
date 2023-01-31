/*
 * Measure_frequencyWith_INT.c
 *
 * Created: 7/4/2022 2:09:33 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"

#define INT_GICR	*((volatile unsigned char*)(0X5B))
#define INT_GIFR	*((volatile unsigned char*)(0X5A))
#define INT_MCUCR	*((volatile unsigned char*)(0X55))



volatile unsigned char Counter;
volatile unsigned char T_ON;
volatile unsigned char T_OFF;
volatile unsigned short Frequency;
volatile unsigned long T_Period;
volatile unsigned char duty_Cycle;


void Send_Val_to_LCD(u32 u16_Value);

int main(void)
{
	
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Duty Cycle=");
	LCD_move_cursor(2,1);
	LCD_send_string("Frequency =");
	TCNT0=0;
	INT_GIFR&=~(1<<6);
	DDRB|=1<<0;
	DDRD&=~(1<<2);
	INT_MCUCR|=(1<<0)|(1<<1);    /* Set ISC00,ISC01 to rising edge */
	/* Interrupt Init */
	INT_GICR|=(1<<6);				 /* Enable INT0*/
	sei();						/*  Enable global interrupt */
	
	
	
    while(1)
    {
		//T_ON=T_ON*(8.0/F_CPU);
		//T_OFF=T_OFF*(8.0/F_CPU);
		
		//T_Period=(T_ON+T_OFF);

		T_Period=(T_ON+T_OFF);
        duty_Cycle=((float)T_ON/T_Period)*100.0;
		Frequency=F_CPU/(T_Period*8.0);
		LCD_move_cursor(1,12);
		Send_Val_to_LCD(T_OFF);
		LCD_move_cursor(2,12);
		Send_Val_to_LCD(Frequency);
    }
}
ISR(INT0_vect)	
{
	//cli();
	//PORTB^=1<<0;
	Counter++;
	
	if (Counter==1)
	{	/* start Timer in normal mode*/
		TCCR0|=1<<CS01;
		 /* Set ISC00,ISC01 to flaing edge */
		 INT_MCUCR|=(1<<1);    /* Set ISC00,ISC01 to flaing edge */
		 INT_MCUCR&=~(1<<0);
		 Counter++;
	}
	if (Counter==2)
	{
		
		T_ON=TCNT0;
		TCNT0=0;
		 /* Set ISC00,ISC01 to Rising edge */
		INT_MCUCR|=(1<<1);    /* Set ISC00,ISC01 to Rising edge */
		INT_MCUCR|=(1<<0);  
		Counter++;
	}
	else if (Counter==3)
	{
		PORTB|=1<<0;
		T_OFF=TCNT0;
		TCNT0=0;
		//Counter++;
		 /* Set ISC00,ISC01 to Rising edge */
		// INT_MCUCR|=(1<<1);    /* Set ISC00,ISC01 to flaing edge */
		// INT_MCUCR|=(1<<0);
		// Counter=0;
		cli();
	}
	//sei();
	
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