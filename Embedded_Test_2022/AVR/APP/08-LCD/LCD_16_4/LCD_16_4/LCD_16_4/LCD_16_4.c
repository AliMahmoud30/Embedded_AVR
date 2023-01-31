/*
 * LCD_16_4.c
 *
 * Created: 7/12/2022 8:31:42 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"


int main(void)
{
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("   Hello LCD");
	LCD_move_cursor(2,5);
	LCD_send_string("Line 2");
	LCD_move_cursor(3,5);
	LCD_send_string("Line 3");
	LCD_move_cursor(4,5);
	LCD_send_string("Line 4");
	
	
    while(1)
    {
        //LCD_send_cmd(shift_display_to_right);
		_delay_ms(50);
    }
}