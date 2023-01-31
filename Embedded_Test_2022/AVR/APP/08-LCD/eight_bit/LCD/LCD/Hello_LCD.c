/*
 * LCD.c
 *
 * Created: 6/15/2022 8:16:56 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"

int main(void)
{
	unsigned int x=0;
	LCD_inti();

	LCD_send_string("Ali Mahmoud");
    while(1)
    {
		LCD_move_cursor(2,1);
		if (x<10)
		{
			LCD_send_char((x/10)+48);
			LCD_send_char((x/10)+48);
			LCD_send_char((x/10)+48);
			LCD_send_char((x%10)+48);
				
		}
		else if (x<100)
		{
			LCD_send_char((x/100)+48);
			LCD_send_char((x/100)+48);
			LCD_send_char((x/10)+48);
			LCD_send_char((x%10)+48);
			
		}
		else if (x<1000)
		{
			LCD_send_char((x/1000)+48);
			LCD_send_char((x/100)+48);
			LCD_send_char(((x/10)%10)+48);
			LCD_send_char((x%10)+48);
			
		}
		else
		{
			LCD_send_char(1+48);
			LCD_send_char(48);
			LCD_send_char(48);
			LCD_send_char(48);
			x=0;
		}
		
		
		x++;
		_delay_ms(500);
         
    }
}