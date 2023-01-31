/*
 * Switch.c
 *
 * Created: 5/22/2022 7:30:24 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include<util/delay.h>

#include "HLED.h"
#include "STD_TYPES.h"
#include "GPIO.h"


int main(void)
{
	u8 SW_State=0;
	u8 flag=0;
	LED_init(A,0);
	DIO_Set_Pin_Direction(C,0,INPUT);
	
	while(1)
    
	{/*
		SW_State=DIO_Get_Pin_value(C,0);
		if((SW_State==1) && (flag==0))
		{
			//_delay_ms(30);
			LED_Toggle(A,0);
			flag=1;
		} 
		else if((SW_State==0) &&(flag==1))
		{
			flag=0;
		}
       */
	
	 SW_State=DIO_Get_Pin_value(C,0);
	 if(SW_State==1)
	 {
		 while(DIO_Get_Pin_value(C,0)==1);
		 LED_Toggle(A,0);
	 }		 
    }
}