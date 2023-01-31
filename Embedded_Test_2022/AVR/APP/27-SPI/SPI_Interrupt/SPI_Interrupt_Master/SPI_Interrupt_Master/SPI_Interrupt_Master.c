/*
 * SPI_Interrupt_Master.c
 *
 * Created: 7/11/2022 9:50:18 PM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "HSPI.h"
#include "GPIO.h"

int main(void)
{
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	DIO_Set_Pin_Direction(B,4,OUTPUT);  /* SS Pins*/
	
	SPI_Master_INT_Init();
	DIO_Set_Pin_Value(B,4,LOW);
	DIO_Set_Pin_Value(A,0,LOW);
	_delay_ms(1000);
    while(1)
    {
		
        SPI_INT_Transmite(0x64);
		_delay_ms(2000);
    }
}
ISR(SPI_STC_vect)
{
	DIO_Toggle_Pin(A,0);
	_delay_ms(1000);
}