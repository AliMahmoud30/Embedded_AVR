/*
 * SPI_Interrupt_Slave.c
 *
 * Created: 7/11/2022 9:51:24 PM
 *  Author: complete
 */ 


//s#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "HSPI.h"
#include "GPIO.h"
#include "LCD.h"
#define SREG	*(volatile unsigned char*)(0x5F)
#define I_BIT	7

void Send_Val_to_LCD(u16 u16_Value);

int main(void)
{
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	SPI_Slave_INT_Init();
	
    while(1)
    {
       
    }
}
ISR(SPI_STC_vect)
{
	LCD_move_cursor(1,1);
	Send_Val_to_LCD(SPDR);
	//SPDR=0x33;
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