/*
 * HNOKIA5110.c
 *
 * Created: 11/23/2022 9:15:38 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define  F_CPU 8000000ul
#include <util/delay.h>


#include "STD_TYPES.h"
#include "std_macros.h"


#include "GPIO.h"
#include "HSPI.h"

#include "Font.h"
#include "HNOKIA5110.h"
#include "HNOKIA5110_config.h"


void NOKIA5110_voidInit(void)
{
	
	/* initialization  >> Master Mode, F_CPU/16 */
	SPI_MasterInit();
		
	/* Nokia5110 Initialization */
	DIO_Set_Pin_Direction(NOKIA_REST,OUTPUT);			/* Reset pin	>> OUTPUT */
	DIO_Set_Pin_Direction(NOKIA_DATA_CMD,OUTPUT);		/* Data/cmd pin >> OUTPUT */
	
	/* Send Reset Pulse */
	DIO_Set_Pin_Value(NOKIA_REST,LOW);
	_delay_ms(100);
	DIO_Set_Pin_Value(NOKIA_REST,HIGH);
	

}

void NOKIA5110_SendCmd(u8 copy_u8Command)
{
	DIO_Set_Pin_Value(NOKIA_DATA_CMD,LOW);  /* clear Data/cmd pin to command operation 	*/
	SPI_MasterTransmit(copy_u8Command);		/* Send command with SPI */
	DIO_Set_Pin_Value(NOKIA_DATA_CMD,HIGH); /* Set Data/cmd pin 	*/
}


void NOKIA5110_SendChar(u8 copy_u8Character, u8 copy_u8XIdx, u8 copy_u8YIdx)
{
	DIO_Set_Pin_Value(NOKIA_DATA_CMD,HIGH);  /* Set Data/cmd pin to Data operation 	*/
	NOKIA5110_SendCmd(copy_u8XIdx | 0x80);	// x
	NOKIA5110_SendCmd(copy_u8YIdx | 0x40);	// y
	for (u8 index=0; index<5; index++)
	{
		SPI_MasterTransmit(ASCII[copy_u8Character-32][index]);	/* send the data on data register */
	}
	SPI_MasterTransmit(0x00);
}

void NOKIA5110_SendString(u8 *string, u8 copy_u8XIdx, u8 copy_u8YIdx)
{
	if(copy_u8XIdx>83)
	{
		copy_u8XIdx=78;   /* at last 5 pixels */
	}
	else
	{
		/* no thing */
	}
	
	if(copy_u8YIdx>5)
	{
		copy_u8XIdx=4;   /* at last row */
	}
	else
	{
		/* no thing */
	}
	
	DIO_Set_Pin_Value(NOKIA_DATA_CMD,HIGH);  /* Set Data/cmd pin to Data operation 	*/
	while (*string != '\0')
	{
		NOKIA5110_SendChar(*string, copy_u8XIdx, copy_u8YIdx);
		string++;
		copy_u8XIdx+=7;
		if (copy_u8XIdx>84)
		{
			copy_u8XIdx = 0;
			copy_u8YIdx++;
		}
	}
}



void N5110_Data(char *DATA)
{
	DIO_Set_Pin_Value(NOKIA_DATA_CMD,HIGH);  /* Set Data/cmd pin to Data operation 	*/
	
	int lenan = strlen(DATA);							/* measure the length of data */
	for (int g=0; g<lenan; g++)
	{
		for (int index=0; index<5; index++)
		{
			SPI_MasterTransmit(ASCII[DATA[g] - 0x20][index]);	/* send the data on data register */
		}
		SPI_MasterTransmit(0x00);
	}
	
}

