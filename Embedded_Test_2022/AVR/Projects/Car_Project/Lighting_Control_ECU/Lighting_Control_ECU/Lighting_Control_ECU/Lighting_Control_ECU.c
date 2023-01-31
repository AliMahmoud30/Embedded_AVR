/*
 * Lighting_Control_ECU.c
 *
 * Created: 9/10/2022 9:14:56 PM
 *  Author: Morsy
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "MI2C.h"

#define LED1	A,0
#define LED2	A,1
#define LED3	A,2
#define LED4	A,3

#define Slave_ADDRESS		0X30


int main(void)
{
	/* DIO Initialization  */
	DIO_Set_Pin_Direction(LED1,OUTPUT);
	DIO_Set_Pin_Direction(LED2,OUTPUT);
	DIO_Set_Pin_Direction(LED3,OUTPUT);
	DIO_Set_Pin_Direction(LED4,OUTPUT);
	DIO_Set_Pin_Value(LED1, LOW);
	DIO_Set_Pin_Value(LED2, LOW);
	DIO_Set_Pin_Value(LED3, LOW);
	DIO_Set_Pin_Value(LED4, LOW);
	/* I2C Initialization */
	MI2C_voidSlaveInit(Slave_ADDRESS);		
	
	/* Variables  */
	
	u8 I2C_Data_Received;
    while(1)
    {
		switch (MI2C_u8SlaveListen())
		{
			case 0:
				/**************** Slave Receiver *************************/
				I2C_Data_Received = MI2C_u8Slave_Receive();
				DIO_Set_Pin_Value(LED1, GET_BIT(I2C_Data_Received,0));
				DIO_Set_Pin_Value(LED2, GET_BIT(I2C_Data_Received,1));
				DIO_Set_Pin_Value(LED3, GET_BIT(I2C_Data_Received,2));
				DIO_Set_Pin_Value(LED4, GET_BIT(I2C_Data_Received,3));
			
				break;
				
			default:
				break;
		}
		
		
		
	}
}