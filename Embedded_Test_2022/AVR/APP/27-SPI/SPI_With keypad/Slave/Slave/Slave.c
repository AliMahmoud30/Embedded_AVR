/*
 * Slave.c
 *
 * Created: 7/11/2022 3:19:46 PM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"

#include "LCD.h"
#include "HSPI.h"

int main(void)
{
	u8 Data=0xFF;
	LCD_inti();
	SPI_SlaveInit();
	
    while(1)
    {
		Data=SPI_SlaveReceive(Data);
		LCD_send_char(Data);
    }
}