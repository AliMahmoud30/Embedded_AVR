/*
 * Switch.c
 *
 * Created: 5/22/2022 7:30:24 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include<util/delay.h>



#include "STD_TYPES.h"
#include "GPIO.h"

#include "HLED.h"
#include "HButton.h"



int main(void)
{
	u8 SW_State=0;
	Button_init_Pull_UP(C,0);
	
	LED_init(A,0);
	
	while(1)
	{
	 SW_State=Button_Read(C,0);
	 if(SW_State==0)
	 {
		 while(Button_Read(C,0)==1);
		 LED_Toggle(A,0);
		// _delay_ms(500);
		// LED_Toggle(A,0);
		 
	 }		 
    }
}