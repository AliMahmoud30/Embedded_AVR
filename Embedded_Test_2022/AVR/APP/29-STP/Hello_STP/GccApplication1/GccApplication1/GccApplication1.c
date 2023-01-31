/*
 * GccApplication1.c
 *
 * Created: 8/21/2022 4:39:56 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "STP_interface.h"

int main(void)
{
	/*DIO Initialization */
	DIO_Set_Pin_Direction(C,0,OUTPUT);
	DIO_Set_Pin_Direction(C,1,OUTPUT);
	DIO_Set_Pin_Direction(C,2,OUTPUT);
	
	//DIO_Set_Pin_Value(C,0,HIGH);
	//_delay_ms(1000);
/**
	HSTP_voidSendSynchronuse(0xFF);
	HSTP_voidSendSynchronuse(0x05);
	HSTP_voidSendSynchronuse(0xFF);
	HSTP_voidSendSynchronuse(0x05);
	*/
    while(1)
    {
		
		for(u8 i =0; i<8;i++)
		{
			HSTP_voidSendSynchronuse(1<<i);
			_delay_ms(200);
		}
		
	}	
}