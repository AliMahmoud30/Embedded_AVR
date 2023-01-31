/*
 * HSPI.c
 *
 * Created: 7/11/2022 9:09:45 AM
 *  Author: Morsy
 */ 

#include "HSPI.h"
#define	F_CPU	1000000ul
#include <util/delay.h>
void SPI_MasterInit(void)
{
	/*Set MOSI, SCK,SS as OUTPUT Pins */
	DIO_Set_Pin_Direction(MOSI,OUTPUT);
	DIO_Set_Pin_Direction(SCK,OUTPUT);
	DIO_Set_Pin_Direction(SS,OUTPUT);
	
	/*Enable SPI Peripheral, Enable Master Mode, Set Clock fosc/16 >> in SPCR Register*/
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	/*Write High on SS pin */
	DIO_Set_Pin_Value(SS,HIGH);
}

void SPI_SlaveInit(void)
{
	/*set MISO As Output Pin */
	DIO_Set_Pin_Direction(MISO,OUTPUT);
	
	/*Enable SPI Peripheral */
	SPCR|=(1<<SPE);
	
}

u8 SPI_MasterTransmit(u8 Data)
{
	volatile u8 Slave_Data;
	
	/*Clear SS to send Data to Slave */
	DIO_Set_Pin_Value(SS,LOW);
	
	/* Start Transmission */
	SPDR=Data;
	/* Wait for Transmission complete */
	while (!(SPSR&(1<<SPIF)));
	
	Slave_Data=SPDR;
	/*Set SS */
	//DIO_Set_Pin_Value(SS,HIGH);
	/* Return Data Received Data*/
	
	return Slave_Data;
}

u8 SPI_SlaveReceive(u8 Data)
{
	volatile u8 SPI_DataReceived;
	
	SPDR=Data;
	/*Wait for Reception  Received */
	while(!(SPSR&(1<<SPIF)));
	//_delay_ms(1000);
	/*return data */
	SPI_DataReceived=SPDR;
	return SPI_DataReceived;
}
void SPI_MasterSendString(u8* string)
{
	while (*string!='\0')
	{
		SPI_MasterTransmit(*string);
		string++;
		_delay_ms(100);
	}
}


