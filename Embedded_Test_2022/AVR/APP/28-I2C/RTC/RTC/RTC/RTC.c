/*
 * RTC.c
 *
 * Created: 8/12/2022 6:23:30 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_TYPES.h"
#include "std_macros.h"


#include "LCD.h"
#include "MI2C.h"



int main(void)
{
	/**********   Variables   *********************/
	u8 Second=0, Minutes=0, Hours=0, AM_PM;
	u8 Day   =0, Date=0,    Month=0, Year=0;
	
	/********** Initialization ********************/
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	MI2C_u8voidInit();
    while(1)
    {
		 HRTC_voidReadClock(&Second, &Minutes ,&Hours);
		 HRTC_voidReadCalender(&Day, &Date, &Month, &Year);
		 
		 /**********************Display Clock **********************/
		 LCD_move_cursor(1,1);
		 LCD_send_char(((Hours & 0x30)>>4)+48);   //Upper BCD digit of Hours
		 LCD_send_char((Hours & 0x0F)+48);		 //lower BCD digit of Hours
		 LCD_send_char(':');
		 
		 LCD_send_char(((Minutes & 0x70)>>4)+48);   //Upper BCD digit of Minutes
		 LCD_send_char((Minutes & 0x0F)+48);		//lower BCD digit of Minutes
		 LCD_send_char(':');
	
 		 LCD_send_char(((Second & 0x70)>>4)+48);	//Upper BCD digit of Seconds
 		 LCD_send_char((Second & 0x0F)+48);			//lower BCD digit of Seconds
		 AM_PM=GET_BIT(Hours,5);
		 if (AM_PM==1)
		 {
			 LCD_send_string(" PM");
		 }
		 else
		 {
			 LCD_send_string(" AM");
		 }

		/**********************Display Calender **********************/
		 LCD_move_cursor(2,1);
		 LCD_send_char((Date   >> 4  )+48);		/* Upper BCD digit of Date */ 
		 LCD_send_char((Date & 0x0F)+48);		/* lower BCD digit of Date */
		 LCD_send_char('-');
		 
		 LCD_send_char((Month >>  4) +48);      /* Upper BCD digit of Month  */
		 LCD_send_char((Month & 0x0F)+48);		/* lower BCD digit of Month  */
		 LCD_send_char('-');
		 
		 LCD_send_char((Year   >> 4)+48);		/* Upper BCD digit of Year */
		 LCD_send_char((Year & 0x0F)+48);		/* lower BCD digit of Year */

		 _delay_ms(200);
		 
    }
}