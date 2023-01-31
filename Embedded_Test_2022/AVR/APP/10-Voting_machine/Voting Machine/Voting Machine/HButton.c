/*
 * HButton.c
 *
 * Created: 5/22/2022 10:03:18 AM
 *  Author: Morsy
 */ 
#include "HButton.h"

void Button_init(u8 PORT,u8 PIN)
{
	DIO_Set_Pin_Direction(PORT,PIN,INPUT);
}

void Button_init_Pull_UP(u8 PORT,u8 PIN)
{
	DIO_Set_Pin_Direction(PORT,PIN,INPUT);
	DIO_Set_Pin_Value(PORT,PIN,HIGH);
}

u8 Button_Read(u8 PORT,u8 PIN)
{
	u8 Button_state;
	Button_state=DIO_Get_Pin_value(PORT,PIN);
	return Button_state;
}
