/*
 * Simple_Game.c
 *
 * Created: 6/29/2022 1:42:06 PM
 *  Author: Ali Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>


#include "STD_TYPES.h"
#include "LCD.h"
#include "Hkeypad.h"
#include "Timers.h"


#define NOT_PRESSED		0XFF

/*global variables */
volatile u16 Counter;

/*Prototypes */
void Fisrt_Screen();
void Second_Screen();

int main(void)
{
	/* Initialization */
	LCD_inti();
	Keypad_4_4_Init();
	Fisrt_Screen();
	Second_Screen();
	Timer0_CTC_Interrupt_Init(80);
	
	/* local variables */
	u8 keypad_value;
	u8 Flag=0;
	
    while(1)
    {
		Flag=0;
		Counter=0;
		while ((Counter<1000) && (Flag==0))
		{
			keypad_value=Keypad_4_4_Read();
			if (keypad_value!=NOT_PRESSED)
			{
				LCD_send_char(keypad_value);
				_delay_ms(500);
				LCD_move_cursor(2,3);
				if (keypad_value=='3')
				{
					LCD_send_string("Well Done");
				}
				else
				{
					LCD_send_string("Wrong answer");
				}				
				Flag=1;
				_delay_ms(2000);
			}
		}
		if(Flag==0)
		{
			LCD_clear();
			LCD_move_cursor(1,3);
			LCD_send_string("Game Over");
			_delay_ms(2000);
		}
		
		Second_Screen();
    }

}

ISR(TIMER0_COMP_vect)
{
	Counter++;
	
}

void Fisrt_Screen()
{
	LCD_send_cmd(display_on_cursor_off);
	LCD_move_cursor(1,6);
	LCD_send_string("Hello");
	LCD_move_cursor(2,3);
	LCD_send_string("simple Game");
	_delay_ms(2000);
}

void Second_Screen()
{
	LCD_clear();
	LCD_send_cmd(display_on_cursor_on);
	LCD_send_char('8');
	LCD_send_char('+');
	LCD_send_char('?');
	LCD_send_char('=');
	LCD_send_char('1');
	LCD_send_char('1');
	LCD_move_cursor(1,3);
}
