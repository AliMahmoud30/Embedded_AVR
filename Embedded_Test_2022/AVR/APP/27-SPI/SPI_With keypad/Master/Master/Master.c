/*
 * Master.c
 *
 * Created: 7/11/2022 3:18:36 PM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"

#include "Hkeypad.h"
#include "HSPI.h"

#define NOTPRESSED	0xFF
int main(void)
{
	u8 Keypad_Value;
	u8 Flag=0;
	Keypad_4_4_Init();
	SPI_MasterInit();
	
    while(1)
    {
        Keypad_Value=Keypad_4_4_Read();
		if (Keypad_Value!=NOTPRESSED && Flag==0)
		{
			SPI_MasterTransmit(Keypad_Value);
			Flag=1;
		}
		else if(Keypad_Value==NOTPRESSED && Flag==1)
		{
			Flag=0;
		}			
    }
}