/*************************************/
/* Author  : Ali Morsy  **************/
/* Version : 1          **************/
/* Date    : 22/10/021   **************/
/*************************************/

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#define prescaler 1

#include "std_macros.h"
#include "I2C.h"

void I2C_Master_Init(unsigned long SCL_Clock)
{
	TWBR= (unsigned char) (((F_CPU/SCL_Clock)-16) / (2*prescaler));
	if (prescaler==1)
	{
		TWSR=0;
	}
	else if (prescaler==4)
	{
		TWSR=1;
	}
	else if (prescaler==16)
	{
		TWSR=2;
	}
	else if (prescaler==64)
	{
		TWSR=3;
	}
	
}

void I2C_start(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}

void I2c_Write_Address(unsigned char Address)
{
	TWDR=Address;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received
}

void I2c_Write_Data(unsigned char Data)
{
	TWDR=Data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}

void i2C_stop(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(GET_BIT(TWCR,TWSTO)==1);

}





void I2C_Set_Slave_Address(unsigned char Address)
{
	TWAR=Address;
}

unsigned char I2C_Slave_Read(void)
	{
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while(GET_BIT(TWCR,TWINT)==0);
		while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while(GET_BIT(TWCR,TWINT)==0);
		while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
		return TWDR ;
	}