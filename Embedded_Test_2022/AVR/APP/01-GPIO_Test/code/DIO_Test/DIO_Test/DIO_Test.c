/*
 * DIO_Test.c
 *
 * Created: 3/18/2022 11:42:48 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>


#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"

#define MY_PORTA    *(( unsigned char*)(0x3B))
#define MY_DDRA    *(( unsigned char*)(0x3A))

#define MY_PORTB    *((volatile unsigned char*)(0x38))
#define MY_DDRB     *((volatile unsigned char*)(0x37))


int main(void)
{
	
	DIO_Set_Port_Direction(A,OUTPUT);
	DIO_Set_Port_Value(A,0x55);
	
	   /*
	 MY_DDRA|=(1<<0);
	 MY_PORTA|=(1<<0);
	 
	MY_DDRB=0xFF;
	MY_PORTB=0xFF;
	_delay_ms(1000);
*/
    while(1)
    {
		DIO_Set_Port_Value(A,0XFF);
		_delay_ms(1000);
		DIO_Set_Port_Value(A,0X00);
		_delay_ms(1000);
		
	/*MYDIO_Set_Port_Value(A,0XFF);
		_delay_ms(1000);
		_PORTB=0x0F;
	_delay_ms(500);
		
    PORTB=0xF0;
    _delay_ms(500);
    */
    }
}