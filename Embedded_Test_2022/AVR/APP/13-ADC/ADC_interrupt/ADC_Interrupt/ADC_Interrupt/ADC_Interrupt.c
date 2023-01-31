/*
 * ADC_Interrupt.c
 *
 * Created: 6/28/2022 2:26:18 AM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#include "LCD.h"
#include "MADC.h"

#define SREG	*(volatile unsigned char*)(0x5F)
#define I_BIT	7

void Send_Val_to_LCD(u16 u16_Value);
volatile u16 ADC_value;

int main(void)
{
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	MADC_Init();
	LCD_send_string("A1=");
	
	//Set I-Bit
	SET_BIT(SREG,I_BIT);
	//Enable ADC Interrupt
	SET_BIT(ADCSRA,ADIE);
	/* Set Channel to MUX*/
	ADMUX &= 0xE0;              // Clear BITs (MUX0 to MUX4) before Writing
	ADMUX |= (0x00);
	/*Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	
	
    while(1)
    {
	    LCD_move_cursor(1,4);
	    Send_Val_to_LCD(ADC_value);
    }
}

ISR(ADC_vect)
{
	ADC_value=ADCL;
	ADC_value|=ADCH<<8;
	/*Start Conversion */
	SET_BIT(ADCSRA,ADSC);
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