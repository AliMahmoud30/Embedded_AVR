/*
 * Semaphore_1.c
 *
 * Created: 9/10/2022 9:16:00 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "avr/interrupt.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void Task1(void* pv);
void Task2(void* pv);

//void* my_sem;
SemaphoreHandle_t my_sem;  

int main(void)
{
	/*  Enable INT0 for Rising Edge */
	MCUCR |= (1 << ISC00)|(1 << ISC01);
	GICR  |= (1 << INT0);
	sei();
	
	/* Create Task With Priority 1 */
	xTaskCreate(Task1,"Ali",100,NULL,2,NULL);
	/* Create Task With Priority 2 */
	xTaskCreate(Task2,"Mahmoud",100,NULL,1,NULL);
	
	my_sem = xSemaphoreCreateBinary();
	
	/*  Start Scheduler */
	vTaskStartScheduler();
	
    while(1)
    {
		
    }
}



void Task1(void* pv)
{
	/* Initialization */
	DIO_Set_Pin_Direction(A,0,OUTPUT);  /* PIN A0 >> OUTPUT */
	DIO_Set_Pin_Direction(A,2,OUTPUT);  /* PIN A0 >> OUTPUT */
	u8 sem_state;
	while (1)
	{
		/* Take Semaphore */
		sem_state = xSemaphoreTake(my_sem,10000);  /* time out 2000 tick(2 second) */
		if (sem_state == pdTRUE)
		{
			DIO_Toggle_Pin(A,0);
			_delay_ms(3000);
		}
		else
		{
			DIO_Toggle_Pin(A,2);
			//xSemaphoreGive(my_sem);
		}
		
	}
}


void Task2(void* pv)
{
	/* Initialization */
	DIO_Set_Pin_Direction(A,1,OUTPUT);  /* PIN A0 >> OUTPUT */
	while(1)
	{
		DIO_Toggle_Pin(A,1);
		//xSemaphoreGive(my_sem);
		_delay_ms(1000);
		//vTaskDelay(1000);
	}
}




/*
// void Task1(void* pv)
// {
// 	u8 x;
// 	DIO_Set_Pin_Direction(A,0,OUTPUT);
// 	DIO_Set_Pin_Direction(A,1,OUTPUT);
// 	while(1)
// 	{
// 		x=xSemaphoreTake(my_sem,5000);  / *  timeout 10s* /
// 		if (x == pdTRUE)
// 		{
// 			/ * Semaphore Available * /
// 			DIO_Toggle_Pin(A,0);
// 			_delay_ms(1000);
// 			/ * Give Semaphore From The which created it * /
// 			//xSemaphoreGive(my_sem);
// 		}
// 		else
// 		{
// 			/ * Semaphore non Available * /
// 			DIO_Set_Pin_Value(A,1,HIGH);
// 			_delay_ms(500);
// 			DIO_Set_Pin_Value(A,1,LOW);
// 			//xSemaphoreGive(my_sem);
// 		}
// 
// 	}
// 		
// }
*/


ISR(INT0_vect)
{
	xSemaphoreGiveFromISR(my_sem,NULL);
}