/*
 * DC_Motor.c
 *
 * Created: 7/5/2022 4:33:18 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "GPIO.h"
#include "Timers.h"

#define IN1	0
#define IN2	1
#define EN1	2

#define EN2	3
#define IN3	4
#define IN4	5

int main(void)
{

	DIO_Set_Port_Direction(D,OUTPUT);
	DIO_Set_Pin_Value(D,EN1,HIGH);
	DIO_Set_Pin_Value(D,EN2,HIGH);
	
	Timer0_PWM_init();
	unsigned char i;
    while(1)
    {
		DIO_Set_Pin_Value(D,IN1,HIGH);
		DIO_Set_Pin_Value(D,IN2,LOW);
		DIO_Set_Pin_Value(D,IN3,LOW);
		DIO_Set_Pin_Value(D,IN4,LOW);
		for (i=0;i<255;i++)
		{
			Timer0_PWM_Change(i);
			_delay_ms(20);
		}
		for (i=255;i>0;i--)
		{
			Timer0_PWM_Change(i);
			_delay_ms(20);
		}
		
		
		/*
		_delay_ms(1000);
		DIO_Set_Pin_Value(D,IN1,LOW);
		DIO_Set_Pin_Value(D,IN2,LOW);
		DIO_Set_Pin_Value(D,IN3,LOW);
		DIO_Set_Pin_Value(D,IN4,HIGH);
		
		_delay_ms(1000);
		*/
 
    }
}