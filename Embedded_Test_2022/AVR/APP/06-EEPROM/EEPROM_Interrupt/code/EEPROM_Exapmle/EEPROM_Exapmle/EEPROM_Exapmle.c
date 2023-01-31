/*
* EEPROM_Exapmle.c
*
* Created: 6/9/2022 8:21:14 AM
*  Author: Ali Morsy
*/


//#include <avr/io.h>

#define F_CPU 8000000ul
#include "util/delay.h"
#include <avr/interrupt.h>

#include "std_macros.h"
#include "STD_TYPES.h"

#include "MEEPROM.h"


#define MY_DDRD		*((volatile unsigned char*)(0x31))
#define My_PORTD	*((volatile unsigned char*)(0x32))


int main(void)
{
	u8 data;
	MY_DDRD|=1<<1;
	sei();
	SET_BIT(EEPCR,EEPIE);
	//EEPROM_Write(0x00,0x03);
	
	while(1)
	{
			CLR_BIT(My_PORTD,1);
		
	}
}
ISR(EE_RDY_vect)
{
	
	SET_BIT(My_PORTD,1);
	_delay_ms(1000);
	//CLR_BIT(EEPCR,EEPIE);
}