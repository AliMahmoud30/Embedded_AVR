/*
 * HLED.c
 *
 * Created: 5/21/2022 12:31:02 AM
 *  Author: Morsy
 */ 


#include "HLED.h"

void LED_init(u8 PORT, u8 PIN)
{
	DIO_Set_Pin_Direction(PORT,PIN,OUTPUT);
}

void LED_ON(u8 PORT, u8 PIN)
{
	DIO_Set_Pin_Value(PORT,PIN,HIGH);
}

void LED_OFF(u8 PORT, u8 PIN)
{
	
	DIO_Set_Pin_Value(PORT,PIN,LOW);
}

void LED_Toggle(u8 PORT, u8 PIN)
{
	TOG_BIT(PORT,PIN);
}

u8 LED_Read_Status(u8 PORT, u8 PIN)
{
	u8 Pin_Value;
	Pin_Value=DIO_Get_Pin_value(PORT,PIN);
	return Pin_Value;
}

