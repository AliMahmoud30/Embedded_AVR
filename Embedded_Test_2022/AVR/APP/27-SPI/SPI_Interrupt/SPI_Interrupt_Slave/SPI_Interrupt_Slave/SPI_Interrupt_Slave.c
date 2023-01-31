/*
 * SPI_Interrupt_Slave.c
 *
 * Created: 7/11/2022 9:51:24 PM
 *  Author: Morsy
 */ 


//s#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "HSPI.h"
#include "GPIO.h"
#include "LCD.h"

int main(void)
{
	LCD_inti();
	SPI_Slave_INT_Init();
	
    while(1)
    {
       
    }
}
ISR(SPI_STC_vect)
{
	LCD_send_char(SPDR);
	SPDR=0x33;
}