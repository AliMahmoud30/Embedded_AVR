/*
 * Hello_ADC.c
 *
 * Created: 6/23/2022 10:09:09 PM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"

#include "MADC.h"
#include "LCD.h"

void Send_Val_to_LCD(u16 u16_Value);

int main(void)
{
	/* LCD Initialization	*/
	LCD_inti(); 
	LCD_send_cmd(display_on_cursor_off);
	
	LCD_send_string("A1=");
	LCD_move_cursor(1,10);
	LCD_send_string("A2=");
	LCD_move_cursor(2,1);
	LCD_send_string("A3=");
	LCD_move_cursor(2,10);
	LCD_send_string("A4=");
	
	/* ADC Initialization */
	MADC_Init();  
	
	u16 Analog_val;
	
    while(1)
    {
        Analog_val=MADC_Read(0);
	    LCD_move_cursor(1,4);
		Send_Val_to_LCD(Analog_val);
		Analog_val=MADC_Read(1);
		LCD_move_cursor(1,13);
		Send_Val_to_LCD(Analog_val);
		Analog_val=MADC_Read(2);
		LCD_move_cursor(2,4);
		Send_Val_to_LCD(Analog_val);
		Analog_val=MADC_Read(3);
		LCD_move_cursor(2,13);
		Send_Val_to_LCD(Analog_val);		
	  	//_delay_ms(100);
    }
}

void Send_Val_to_LCD(u16 u16_Value)
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
	 else 
	 {
		 LCD_send_char((u16_Value/1000)+48);
		 LCD_send_char(((u16_Value/100)%10)+48);
		 LCD_send_char(((u16_Value/10)%10)+48);
		 LCD_send_char((u16_Value%10)+48);
	 }

}