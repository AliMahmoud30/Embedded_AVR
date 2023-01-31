/*
 * Traffic_Light.c
 *
 * Created: 6/29/2022 2:53:43 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>


#include "STD_TYPES.h"
#include "LCD.h"
#include "Timers.h"
#include "HLED.h"


#define GREEN_LED	0
#define YELLOW_LED	1
#define RED_LED		2


/*global variables */
volatile u16 Counter;


int main(void)
{	
	s8 Red_Counter=10;
	s8 Yellow_Counter=5;
	s8 Green_Counter=10;
	
	/* Initialization */
	LED_init(D,GREEN_LED);
	LED_init(D,YELLOW_LED);
	LED_init(D,RED_LED);
	
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Traffic Light");
	_delay_ms(200);
	LCD_clear();
	//LCD_move_cursor(1,0);
	LCD_send_string("Remaining Time:");
	LCD_move_cursor(2,4);
	LCD_send_char('s');
	Timer0_CTC_Interrupt_Init(80);
	
    while(1)
    {
		Red_Counter=10;
		Yellow_Counter=5;
		Green_Counter=10;
		/*---------------------------Red Time-----------------------------*/
		while (Red_Counter>=0)
		{
			LED_ON(D,RED_LED);
			LED_OFF(D,YELLOW_LED);
			LED_OFF(D,GREEN_LED);
			if(Counter>=100)
			{
				LCD_move_cursor(2,1);
				LCD_send_char((Red_Counter/10)+48);
				LCD_send_char((Red_Counter%10)+48);
				Red_Counter--;
				Counter=0;
			}
			
		}
			LCD_move_cursor(2,1);
			LCD_send_char((Yellow_Counter/10)+48);
			LCD_send_char((Yellow_Counter%10)+48);
			Yellow_Counter--;
		
		/*---------------------------Yellow Time-----------------------------*/
		while (Yellow_Counter>=0)
		{	
			LED_OFF(D,RED_LED);
			LED_ON(D,YELLOW_LED);
			LED_OFF(D,GREEN_LED);
			if(Counter>=100)
			{
				LCD_move_cursor(2,1);
				LCD_send_char((Yellow_Counter/10)+48);
				LCD_send_char((Yellow_Counter%10)+48);
				Yellow_Counter--;
				Counter=0;
			}
		}
		LCD_move_cursor(2,1);
		LCD_send_char((Green_Counter/10)+48);
		LCD_send_char((Green_Counter%10)+48);
		Green_Counter--;
			/*---------------------------Green Time-----------------------------*/
			while (Green_Counter>=0)
			{
				LED_OFF(D,RED_LED);
				LED_OFF(D,YELLOW_LED);
				LED_ON(D,GREEN_LED);
				if(Counter>=100)
				{
					LCD_move_cursor(2,1);
					LCD_send_char((Green_Counter/10)+48);
					LCD_send_char((Green_Counter%10)+48);
					Green_Counter--;
					Counter=0;
				}
			}			
    
    }
}
ISR(TIMER0_COMP_vect)
{
	Counter++;
	
}
