/*
 * GccApplication1.c
 *
 * Created: 11/28/2022 2:10:44 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"


#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void Task1(void* pv);
void Task2(void* pv);

SemaphoreHandle_t my_mutex;

int main(void)
{
	/* Create Tasks */
	xTaskCreate(Task1,"Ali",100,NULL,2,NULL);		/* HIGH Priority */
	xTaskCreate(Task2,"Morsy",100,NULL,1,NULL);		/* LOW  Priority */
	
	/* Create semaphore Mutex */
	my_mutex = xSemaphoreCreateMutex();
	
	/* Start Scheduler*/
	vTaskStartScheduler();
	
    while(1)
    {
         
    }
	
}


void Task1(void* pv)
{
	/* Initialization */
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	u8 semaphore_state;
	while(1)
	{
		semaphore_state = xSemaphoreTake(my_mutex,1000); /* timeout 1 second */
		
		if (semaphore_state == pdTRUE )
		{
			DIO_Set_Pin_Value(A,0,HIGH);
			vTaskDelay(2000);
			xSemaphoreGive(my_mutex);
			vTaskDelay(1000);
		}
		else
		{
			//DIO_Toggle_Pin(A,1);
			//xSemaphoreGive(my_mutex);
		}

	}
}
void Task2(void* pv)
{
	/* Initialization */
	DIO_Set_Pin_Direction(A,1,OUTPUT);
	u8 semaphore_state;
	
	while(1)
	{
		semaphore_state = xSemaphoreTake(my_mutex,1000); /* timeout 1 second */
		
		if (semaphore_state == pdTRUE )
		{
			DIO_Set_Pin_Value(A,0,LOW);
			xSemaphoreGive(my_mutex);
			vTaskDelay(2000);
		}
	}	
}