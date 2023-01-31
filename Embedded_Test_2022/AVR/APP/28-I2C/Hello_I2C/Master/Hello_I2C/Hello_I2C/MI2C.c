/***************************************************/
/* Author  : Ali Morsy                             */
/* Date    : 9-8-2022                              */
/* VERSION : VO1                                   */
/***************************************************/

#include "STD_TYPES.h"
#include "std_macros.h"

#include "MI2C.h"
#include "MI2C_config.h"
#include "GPIO.h"

#define F_CPU 8000000ul

void MI2C_u8voidInit(void)
{
	I2C_TWBR=(u8)(((F_CPU/I2C_CLOCK)-16)/(2*I2C_Prescaler));
	//I2C_TWBR=72;
	switch (I2C_Prescaler)
	{
		case DIV_1 : CLR_BIT(I2C_TWSR,0);CLR_BIT(I2C_TWSR,1); break;
		case DIV_4 : SET_BIT(I2C_TWSR,0);CLR_BIT(I2C_TWSR,1); break;
		case DIV_16: CLR_BIT(I2C_TWSR,0);SET_BIT(I2C_TWSR,1); break;
		case DIV_64: CLR_BIT(I2C_TWSR,0);CLR_BIT(I2C_TWSR,1); break;
		default:
		break;
	}
}

void MI2C_voidStart(void)
{
	u8 status;
	u8 ReturnVal=1;
	I2C_TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);  /* Enable TWI, Generate Start Condition, Clear TWI Flag  */
	while(GET_BIT(I2C_TWCR,TWINT)==0);		   /* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;
	if(status==0x08)					       /* Check weather START transmitted or not? */
	{
		ReturnVal=1;
	}
	else
	{
		ReturnVal=0;
	}
	return ReturnVal;
}


u8 MI2C_u8WriteAddress(u8 copy_u8WriteAddress)
{	
	u8 status;
	u8 ReturnVal;
	I2C_TWDR=copy_u8WriteAddress;
	I2C_TWCR=(1<<TWINT)|(1<<TWEN);		/* Enable TWI and clear interrupt flag */
	while(GET_BIT(I2C_TWCR,TWINT)==0);  /* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;				/* Read TWI status register */
	if(status==0x18)					/* Check for SLA+W transmitted & ack received */
	{
		ReturnVal=1;
	}
	else if(status==0x20)	            /* Check for SLA+W transmitted &nack received */
	{
		ReturnVal=0;
	}
	return ReturnVal;
}

u8 MI2C_u8WriteData(u8 copy_u8Data)
{
	u8 status;
	u8 ReturnVal;
	
	I2C_TWDR=copy_u8Data;					/* Copy data in TWI data register */
	I2C_TWCR=(1<<TWINT)|(1<<TWEN);			/* Enable TWI and clear interrupt flag */
	while (GET_BIT(I2C_TWCR,TWINT)==0);		/* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;					/* Read TWI status register */
	if(status==0x28)						/* Check for Data transmitted & ack received */
	{
		ReturnVal=1;
	}
	else if (status==0x30)					/* Check for Data transmitted &nack received */
	{
		ReturnVal=0;
	}
}

/* I2C repeated start function */
u8 MI2C_u8RepeatedStart(u8 copy_u8WriteAddress) 
{
	u8 status;									/* Declare variable */
	I2C_TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);	/* Enable TWI, generate start */
	while (GET_BIT(I2C_TWCR,TWINT)==0);			/* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;							/* Read TWI status register */
	if(status!=0x10)							/* Check for repeated start transmitted */
	{
		return 0;								/* Return 0 for repeated start condition fail */
	}		
	I2C_TWDR=copy_u8WriteAddress;					/* Write SLA+R in TWI data register */
	I2C_TWCR=(1<<TWEN)|(1<<TWINT);				/* Enable TWI and clear interrupt flag */
	while (GET_BIT(I2C_TWCR,TWINT)==0);			/* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;							/* Read TWI status register */
	if(status==0x40)							/* Check for SLA+R transmitted &ack received */
	{
	return 1;									/* Return 1 to indicate ack received */
	}	
	if(status==0x48)							/* Check for SLA+R transmitted &nack received */
	{
	return 2;									/* Return 2 to indicate nack received */
	}	
	else
	{
	return 3;									/* Else return 3 to indicate SLA+W failed */
	}	
}


u8 MI2C_u8ReadAck(void)
{
	I2C_TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); /* Enable TWI, generation of ack */
	while (GET_BIT(I2C_TWCR,TWINT)==0);		 /* Wait until TWI finish its current job */
	return I2C_TWDR;						 /* Return Received Data */
}

u8 MI2C_u8ReadNAck(void)
{
	I2C_TWCR=(1<<TWEN)|(1<<TWINT);			 /* Enable TWI and clear interrupt flag */
	while (GET_BIT(I2C_TWCR,TWINT)==0);		 /* Wait until TWI finish its current job */
	return I2C_TWDR;						 /* Return Received Data */
}


void MI2C_voidStop(void)
{
	SET_BIT(I2C_TWCR,TWSTO);				 /* Enable TWI, generate stop */
	while(GET_BIT(I2C_TWCR,TWSTO)==1);		 /* Wait until stop condition execution */
}


void MI2C_voidSlaveInit(u8 copy_u8SlaveAddress)
{
	I2C_TWAR=copy_u8SlaveAddress;
	SET_BIT(I2C_TWCR,TWEN);					/* Enable TWI     */
	SET_BIT(I2C_TWCR,TWEA);					/* Enable Generation for Ack */
	SET_BIT(I2C_TWCR,TWINT);				/* Clear TWI Flag */
}


u8 MI2C_u8SlaveListen(void)
{
	u8 status;
	while(1)
	{
		SET_BIT(I2C_TWCR,TWINT);					/* Clear TWI Flag */
		while((GET_BIT(I2C_TWCR,TWINT))==0);		/* Wait to be addressed */
		status=I2C_TWSR & 0xF8;						/* Read TWI status register */
		if((status==0x60)||(status==0x68))			/* Own SLA+W received &ack returned */
			return 0;								/* Return 0 to indicate ack returned */
		if((status==0xA8)||(status==0xB0))			/* Own SLA+R received &ack returned */
			return 1;								/* Return 1 to indicate ack returned */
		if((status==0x70)||(status==0x78))			/* General call received &ack returned */
			return 2;								/* Return 2 to indicate ack returned */
		else
			continue;								/* Else continue */
	}
}

s8 I2C_Slave_Transmit(u8 copy_u8Data)
{
	s8 status;
	I2C_TWDR=copy_u8Data;						/* Write data to TWDR to be transmitted */
	SET_BIT(I2C_TWCR,TWINT);					/* Clear TWI Flag */
	while (GET_BIT(I2C_TWCR,TWINT)==0);			/* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;						/* Read TWI status register */
	if(status==0xA0)							/* Check for STOP/REPEATED START received */
	{
		SET_BIT(I2C_TWCR,TWINT);				/* Clear interrupt flag & return -1 */
		return -1;
	}
	if(status==0xB8)							/* Check for data transmitted & ack received */
	{
		return 0;								/* If yes then return 0 */
	}
	if(status==0xC0)							/* Check for data transmitted & nack received */
	{
		SET_BIT(I2C_TWCR,TWINT);				/* Clear interrupt flag & return -2 */
		return -2;
	}
	if(status==0xC8)							/* Last byte transmitted with ack received */
	{
		return -3;								/* If yes then return -3 */
	}
	else										/* else return -4 */
	{
		return -4;
	}
	
}

s8 MI2C_u8Slave_Receive(void)
{
	u8 status;									/* Declare variable */
	SET_BIT(I2C_TWCR,TWINT);					/* Clear TWI Flag */
	while (GET_BIT(I2C_TWCR,TWINT)==0);			/* Wait until TWI finish its current job */
	status=I2C_TWSR & 0xF8;						/* Read TWI status register */
	if(status==0x80||status==0x90)				/* Check for data received &ack returned */
	{
		return I2C_TWDR;						/* If yes then return received data */
	}
	
	/* Check for data received, nack returned & switched to not addressed slave mode */
	if(status==0x88||status==0x98)
	{
		return I2C_TWDR;						/* If yes then return received data */
	}
	if(status==0xA0)							/* Check wether STOP/REPEATED START */
	{
		SET_BIT(I2C_TWCR,TWINT);				/* Clear interrupt flag & return -1 */
		return -1;
	}
	else
	{
		return -2;			/* Else return -2 */
	}
}