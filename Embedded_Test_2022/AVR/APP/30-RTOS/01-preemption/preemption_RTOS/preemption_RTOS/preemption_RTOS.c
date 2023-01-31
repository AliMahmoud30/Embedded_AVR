/*
 * preemption_RTOS.c
 *
 * Created: 9/7/2022 5:32:15 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU	8000000ul
#include <util/delay.h>

#include "FreeRTOS.h"
#include "task.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"


void Task1(void* pv);
void Task2(void* pv);

u8 D0 = 0;
u8 D1 = 1;
int main(void)
{
	
	xTaskCreate(Task1,"Ali",  100,&D0,1,NULL);
	xTaskCreate(Task2,"Morsy",100,&D1,2,NULL);
	
	vTaskStartScheduler();
    while(1)
    {
      
	}	   
}

void Task1(void* pv)
{
	
	/* Initialization*/
	DIO_Set_Pin_Direction(D,*((char*)pv),OUTPUT);
	u8 x=0;	
	while(1)
	{
		x++;
		DIO_Toggle_Pin(D,*((char*)pv));
		_delay_ms(1000);
		/*if (x == 8)
		{
			vTaskDelay(4000);
			x=0;
		}*/
	}
	
}

void Task2(void* pv)
{
	//vTaskDelay(4000);
	/* Initialization*/
	DIO_Set_Pin_Direction(D,*((char*)pv),OUTPUT);
	u8 x=0;
	while(1)
	{
		x++;
		DIO_Toggle_Pin(D,*((char*)pv));
		_delay_ms(1000);
		if (x == 5)
		{
			vTaskDelay(4000);
			x=0;
		}
	}
	
	
}