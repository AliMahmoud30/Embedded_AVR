/*
 * UART_Receiver.c
 *
 * Created: 7/7/2022 10:05:48 AM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU	8000000ul
#include <util/delay.h>

#include "LCD.h"
#include "UART.h"

int main(void)
{
	LCD_inti();
	UART_init(9600,1,NONE);
	unsigned char x;

	
    while(1)
    {
		x=UART_Receive_Data();
		LCD_send_char(x);
		UART_Send_Data('1');
    }
}