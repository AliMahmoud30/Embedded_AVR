/*
 * Inter_Task_Communication.c
 *
 * Created: 11/28/2022 4:52:08 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

/* LIBs  */
#include "STD_TYPES.h"
#include "StackMacros.h"

/* MCAL */
#include "GPIO.h"

/* HAL */
#include "Hkeypad.h"
#include "LCD.h"

/* Free RTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* void pointer variable */
QueueHandle_t	My_Queue;


void KeyPad_voidTask(void* pv);
void LCD_voidTask(void* pv);

int main(void)
{
	/* Initialization */
	LCD_inti();
	Keypad_4_4_Init();	
	xTaskCreate(KeyPad_voidTask,"Keypad",100,NULL,2,NULL);  /* Create Keypad Task */
	xTaskCreate(LCD_voidTask,"LCD"   ,100,NULL,1,NULL);	/* Create LCD Task    */
	
	My_Queue = xQueueCreate(5,sizeof(u8));  /*  Create Queue */
	
	
	/* Start Scheduler */
	vTaskStartScheduler();
	//u8 Local_u8KeyVal;
	
    while(1)
    {
    /*  Local_u8KeyVal = Keypad_4_4_Read();
      if ( Local_u8KeyVal != NOT_PRESSED )
      {		
		  LCD_send_char(Local_u8KeyVal);
		  _delay_ms(300);
      }*/
    }
}


void KeyPad_voidTask(void* pv)
{
	/* Initialization */
	
	u8 Local_u8KeyVal;
	u8 count=0;	
	while(1)
	{
		Local_u8KeyVal = Keypad_4_4_Read();
		if ( Local_u8KeyVal != NOT_PRESSED )
		{
			xQueueSend(My_Queue,&Local_u8KeyVal,1000);  /* timeout 1 second */
			_delay_ms(300);
			count++;
			if (count == 5)
			{
				vTaskDelay(1000);
				count=0;
			}
		} 
		else
		{
			
		}
	}	
	
}
void LCD_voidTask(void* pv)
{
	/* Initialization */
	u8 Local_u8QueueReceive;
	
	while(1)
	{
		xQueueReceive(My_Queue,&Local_u8QueueReceive,1000);  /* timeout 1 second */
		LCD_send_char(Local_u8QueueReceive);				/* Send Value Received from Queue to LCD */
	}
	
	
}