/*
 * Relay.c
 *
 * Created: 6/9/2022 7:52:38 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "std_macros.h"
#include "STD_TYPES.h"

#include "GPIO.h"

int main(void)
{
	DIO_Set_Pin_Direction(D,0,OUTPUT);
    while(1)
    {
		 DIO_Set_Pin_Value(D,0,HIGH);
		 _delay_ms(1000);
		 DIO_Set_Pin_Value(D,0,LOW);
		 _delay_ms(1000);
		 
    }
}