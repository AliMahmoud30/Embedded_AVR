/*
 * Hello_I2C.c
 *
 * Created: 8/10/2022 8:17:38 AM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "LCD.h"
#include "MI2C.h"

int main(void)
{
		
	u8 i=0;
	_delay_ms(500);
	//LCD_inti();
	DIO_Set_Pin_Direction(B,0,OUTPUT);
	DIO_Set_Pin_Direction(B,1,OUTPUT);
	
	MI2C_u8voidInit();
	for (i=0;i<10;i++)
	{
		MI2C_voidStart();
		MI2C_u8WriteAddress(0x50);
		MI2C_u8WriteData(i+48);
		MI2C_voidStop();
		_delay_ms(500);
	}
	
    while(1)
    {
        
    }
}
