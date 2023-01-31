/*
 * UART_Transmitter.c
 *
 * Created: 7/7/2022 9:59:00 AM
 *  Author: Ali Morsy
 */ 


//#include <avr/io.h>
#define F_CPU	8000000ul
#include <util/delay.h>

#include "UART.h"

int main(void)
{
	
	UART_init(9600,1,NONE);    /*UART init*/ 
	_delay_ms(500);
	
	UART_Send_Data('A');
	UART_Send_String(" Ali Morsy");
    while(1)
    {

		    
    }
}