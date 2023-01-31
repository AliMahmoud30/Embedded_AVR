/*
 * Hello_Keypad.c
 *
 * Created: 6/15/2022 8:16:56 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"
#include "Hkeypad.h"
				
int main(void)
{
	/* Keypad init */
	Keypad_4_4_Init();
										
	/*LCD init*/
	LCD_inti();
	
	unsigned char Value;
	unsigned char Flag=0;
	
    while(1)
    {
		//LCD_move_cursor(1,1);
		Value=Keypad_4_4_Read();
		
		//LCD_send_char(Value);
		//_delay_ms(1000);
		if((Value!=0xFF)&&(Flag==0))
		{
			//_delay_ms(30);
			LCD_send_char(Value);
			Flag=1;
		}
		else if((Value==0xFF)&&(Flag==1))
		{
			Flag=0;	
		}
	}
}
