/*
 * Mutual_Exclusion_1.c
 *
 * Created: 9/8/2022 9:13:47 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "std_macros.h"
#include "GPIO.h"

#include "FreeRTOS.h"
#include "task.h"

void Task1(void* pv);
void Task2(void* pv);

u8 x=0,y=0;

int main(void)
{
	xTaskCreate(Task1,"Ali",100,NULL,2,NULL);   /* High priority */
	xTaskCreate(Task2,"Morsy",100,NULL,1,NULL); /* Low Priority  */
	
	
	vTaskStartScheduler();
	
    while(1)
    {
       
    }
}
void Task1(void* pv)
{
	DIO_Set_Pin_Direction(D,0,OUTPUT);
	while(1)
	{
		if (x == y)
		{
			DIO_Toggle_Pin(D,0);	
		}
		vTaskDelay(100);  /* go to waiting state  >> 100 tick  (100ms) */
	}	
}
void Task2(void* pv)
{
	while(1)
	{
		//cli();   /* Disable global interrupt */
		taskENTER_CRITICAL();
		x++;
		_delay_ms(200);
		y++;
		taskEXIT_CRITICAL();
		//sei();
		_delay_ms(200);
		  /* enable global interrupt */
	}		
}