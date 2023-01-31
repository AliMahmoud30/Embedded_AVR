/*
* EEPROM_Exapmle.c
*
* Created: 6/9/2022 8:21:14 AM
*  Author: Ali Morsy
*/


//#include <avr/io.h>

#define F_CPU 8000000ul
#include "util/delay.h"


#include "std_macros.h"
#include "STD_TYPES.h"

#include "MEEPROM.h"


#define MY_DDRD		*((volatile unsigned char*)(0x31))
#define My_PORTD	*((volatile unsigned char*)(0x32))


int main(void)
{
	u8 data;
	u8 counter=0;
	MY_DDRD|=1<<2;
	MY_DDRD|=1<<1;
	
	
	while(1)
	{
		data=EEPROM_Read(0x3FF);
		
		if (data==0x03)
		{
			My_PORTD|=(1<<2);
			My_PORTD&=(~(1<<1));
		}
		else if(data==0x05)
		{
			My_PORTD|=(1<<1);
			My_PORTD&=(~(1<<2));
		}

		
		
		if (counter==0)
		{
			EEPROM_Write(0x3FF,0x03);
			counter++;
		}
		else if(counter== 1)
		{
			EEPROM_Write(0x3FF,0x05);
			counter=0;
		}
			_delay_ms(1000);
	}
}