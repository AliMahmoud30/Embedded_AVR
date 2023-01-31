/*
 * LM_35.c
 *
 * Created: 6/26/2022 5:48:20 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"
#include "MADC.h"
#include "STD_TYPES.h"


void Send_Val_to_LCD(u16 u16_Value);

int main(void)
{
	MADC_Init();
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Temp=");
	
	u16 ADC_Value;
	u16 Milli_volt;
	u8 temp_val;
	
    while(1)
    {
		ADC_Value=MADC_Read(0);
		LCD_move_cursor(1,6);
		Send_Val_to_LCD(ADC_Value);
		
		//temp_val=ADC_Value*((2.5/1024)*1000)/10;
		//temp_val=ADC_Value*((2.5/1024)*1000)/10.0;
		temp_val=ADC_Value*((5.0/1024)*1000)/10.0;
		LCD_move_cursor(2,0);
		Send_Val_to_LCD(temp_val);
		LCD_send_char(0xDF);    // celsius symbol
		LCD_send_char('C');
		
		Milli_volt=ADC_Value*((5.0/1024)*1000);
		LCD_move_cursor(2,7);
		Send_Val_to_LCD(Milli_volt);
		LCD_send_string("mv");
		
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