/*
 * SPI_Interrupt_Slave.c
 *
 * Created: 7/11/2022 9:51:24 PM
 *  Author: complete
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

/* LIBs*/
#include "STD_TYPES.h"
#include "std_macros.h"
#include "Masseage.h"

/* MCAL*/
#include "GPIO.h"
#include "HSPI.h"
#include "Timers.h"

/* HAL */
#include "HLED.h"

#define ROOM1		D,0
#define ROOM2		D,1
#define ROOM3		D,2
#define ROOM4		D,3
#define TV			D,4
#define AIR_CON		D,5


#define SREG	*(volatile unsigned char*)(0x5F)
#define I_BIT	7

u8 Global_u8DemandResponse;
volatile u8 SPI_u8Request;
volatile u8 Global_u8TempVal=0;
volatile u8 Global_u8TempReq=0;
volatile u8 Global_Air_Con_State=0;

volatile u16 Global_ADC_Value = 0;
volatile u8 Global_Temp_val = 0;
volatile u8 Global_Temp_Flag = 0;
volatile u8 Global_TimerCounter = 0;

int main(void)
{

	u8 Local_u8SPIData;
	u8 SPI_u8Response;
	
	/* DIO Initialization */
	LED_init(ROOM1);	/* ROOM1 */
	LED_init(ROOM2);	/* ROOM2 */
	LED_init(ROOM3);	/* ROOM3 */
	LED_init(ROOM4);	/* ROOM4 */
	LED_init(TV);		/* TV    */
	LED_init(AIR_CON);	/* Air-Con. */
	
	/* Turn OFF ALL Rooms & TV and Air-Con. */
	LED_OFF(ROOM1);  LED_OFF(ROOM2);  LED_OFF(ROOM3);  LED_OFF(ROOM4);
	LED_OFF(TV); 
	LED_OFF(AIR_CON);
	
	
	/* ADC Initialization */
	MADC_Init();

	/* SPI Initialization */
	SPI_SlaveInit();
	
	/* Timer Initialization*/
	Timer0_CTC_Interrupt_Init(196);   /* Interrupt Occurres every 25ms */
	
	
    while(1)
    {
		
       SPI_u8Request = SPI_SlaveReceive(DEMAND_RESPONSE);	/* Waiting for Request from Master */
	   switch(SPI_u8Request)
	   {
			/*------------------- Request for Room 1 Status ---------------------- */
			case ROOM1_STATUS:
				SPI_u8Response = LED_Read_Status(ROOM1);		/* Read Room1 State */
				Global_u8DemandResponse = SPI_SlaveReceive(SPI_u8Response);	  /* Waiting Master Again for Request to Response */ 
				break;
			/*------------------- Request for Room 2 Status ---------------------- */
			 case ROOM2_STATUS:
				SPI_u8Response = LED_Read_Status(ROOM2);				/* Read Room2 State */
				Global_u8DemandResponse = SPI_SlaveReceive(SPI_u8Response);/* Waiting Master Again for Request to Response */
				break;
			/*------------------- Request for Room 3 Status ---------------------- */
			case ROOM3_STATUS:
				SPI_u8Response = LED_Read_Status(ROOM3);					/* Read Room3 State */
				Global_u8DemandResponse = SPI_SlaveReceive(SPI_u8Response);/* Waiting Master Again for Request to Response */
				break;
			/*------------------- Request for Room 4 Status ---------------------- */
			case ROOM4_STATUS:
				SPI_u8Response = LED_Read_Status(ROOM4);					 /* Read Room4 State */
				Global_u8DemandResponse = SPI_SlaveReceive(SPI_u8Response);  /* Waiting Master Again for Request to Response */
				break;
			/*------------------- Request for Turn ON Room 1 ---------------------- */
			case ROOM1_TURN_ON:   
				LED_ON(ROOM1);   /* Turn ON Room1 */
				break;
			/*------------------- Request for Turn OFF Room 1 ---------------------- */			
			case ROOM1_TURN_OFF: 
				LED_OFF(ROOM1); /* Turn OFF Room1 */
				break;
			
			/*------------------- Request for Turn ON Room 2 ---------------------- */
			case ROOM2_TURN_ON: 
				LED_ON(ROOM2); /* Turn OFF Room2 */
				break;
			/*------------------- Request for Turn OFF Room 2 ----------------------*/
			case ROOM2_TURN_OFF:
				LED_OFF(ROOM2); /* Turn OFF Room2 */
				break;
				
			/*------------------- Request for Turn ON Room 3 ---------------------- */	
			case ROOM3_TURN_ON:
				LED_ON(ROOM3);  /* Turn OFF Room3 */
				break;
			/*------------------- Request for Turn OFF Room 3 ---------------------- */
			case ROOM3_TURN_OFF:
				LED_OFF(ROOM3); /* Turn OFF Room3 */
				break;
				
			/*------------------- Request for Turn ON Room 4  ---------------------- */
			case ROOM4_TURN_ON:
				LED_ON(ROOM4); /* Turn OFF Room4 */
				break;	
			/*------------------- Request for Turn OFF Room 4 ---------------------- */
			case ROOM4_TURN_OFF:
				LED_OFF(ROOM4); /* Turn OFF Room4 */
				break;
				
			/*------------------- Request for TV Status ---------------------------- */
			case TV_STATUS:
				SPI_u8Response = LED_Read_Status(TV);						 /* Read TV State */
				Global_u8DemandResponse = SPI_SlaveReceive(SPI_u8Response);  /* Waiting Master Again for Request to Response */
				break;
			/*-------------------Request for Turn ON TV      ---------------------- */
			case TV_TURN_ON:
				LED_ON(TV); /* Turn ON TV */
				break;
			/*------------------- Request for Turn OFF TV    ---------------------- */
			case TV_TURN_OFF:
				LED_OFF(TV);  /* Turn OFF TV */
				break;
				
			/*------------------- Request for AiR_Con. Status ---------------------- */
			case AIR_CON_STATUS:
				Global_u8DemandResponse = SPI_SlaveReceive(Global_Air_Con_State);    /* Waiting Master Again for Request to Response */
				break;
			/*-------------------Request for Turn ON AiR_Con.  ---------------------- */
			case AIR_CON_TURN_ON:
				Global_Air_Con_State = ON_STATUS;  /* Request to Turn ON AiR_Con. */
				break;
			/*------------------- Request for Turn OFF AiR_Con. ---------------------- */
			case AIR_CON_TURN_OFF:
				Global_Air_Con_State = OFF_STATUS; /* Request to Turn OFF AiR_Con. */
				break;
				
			/*------------------- Request for Temp. Setting ---------------------------------- */
			case SEND_TEMP:
				Global_u8TempReq = SPI_SlaveReceive(DEMAND_RESPONSE); /* Waiting Master Again for Request to Set Temp. */
				Global_Temp_Flag = 1;				

				break;	
			default:
				break;	
	   }			
     

    }
}


/* ISR for Timer0 on CTC Mode 
   ISR Occurres Every 25ms
 */
ISR (TIMER0_COMP_vect)
{
	Global_ADC_Value = MADC_Read(0);							 /* Read ADC Value From Channel_0				    */
	Global_Temp_val  = Global_ADC_Value*((5.0/1024)*1000)/10.0;  /* Convert ADC Value to temp. (LM35 Temp._Sensor)  */
	if (Global_Air_Con_State == ON_STATUS )						 /* Check if Air_Con. is on by Master or not */
	{
		 /* Check if Actual Temperature is Greater than Temp. Requested --- if True >> Turn On Air_Con. */
		if ( (Global_Temp_val > Global_u8TempReq) && (Global_Temp_Flag ==1) )
		{
			LED_ON(AIR_CON);
			Global_Temp_Flag =0;
		}
			/* Check if Actual Temperature is less than Temp. Requested --- if True >> Turn OFF Air_Con. */
		else if (Global_Temp_val < Global_u8TempReq)
		{
			LED_OFF(AIR_CON);
			Global_Temp_Flag =1;
			
		}
	}
	else
	{
		LED_OFF(AIR_CON);
	}
}