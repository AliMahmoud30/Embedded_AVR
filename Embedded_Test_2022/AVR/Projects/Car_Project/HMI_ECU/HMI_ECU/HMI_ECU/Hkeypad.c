/*
 * Hkeypad.c
 *
 * Created: 6/17/2022 3:36:49 PM
 *  Author: Ali Morsy
 */ 


#include "GPIO.h"
#include "Hkeypad.h"
#include "HKeypad_config.h"

void Keypad_4_4_Init(void)
{
	/*set Rows as Output Pins */
	DIO_Set_Pin_Direction(ROW_0,OUTPUT);
	DIO_Set_Pin_Direction(ROW_1,OUTPUT);
	DIO_Set_Pin_Direction(ROW_2,OUTPUT);
	DIO_Set_Pin_Direction(ROW_3,OUTPUT);
	
	/*set columns as Input_PULL_UP Pins */
	DIO_Set_Pin_Direction(Col_0,INPUT);
	DIO_Set_Pin_Direction(Col_1,INPUT);
	DIO_Set_Pin_Direction(Col_2,INPUT);
	DIO_Set_Pin_Direction(Col_3,INPUT);
	
	DIO_Set_Pin_Value(Col_0,HIGH);
	DIO_Set_Pin_Value(Col_1,HIGH);
	DIO_Set_Pin_Value(Col_2,HIGH);
	DIO_Set_Pin_Value(Col_3,HIGH);
}


unsigned char Keypad_4_4_Read(void)
{
	unsigned char ROW=0;
	unsigned char COL=0;
	unsigned char keypad_value=0xFF;
	
	for(ROW=0;ROW<4;ROW++)
	{
		DIO_Set_Pin_Value(ROW_0,HIGH);
		DIO_Set_Pin_Value(ROW_1,HIGH);
		DIO_Set_Pin_Value(ROW_2,HIGH);
		DIO_Set_Pin_Value(ROW_3,HIGH);
		
		DIO_Set_Pin_Value(ROW_0+ROW,LOW);
		for(COL=0;COL<4;COL++)
		{	
			if(DIO_Get_Pin_value(Col_0+COL)==0)
			{
				keypad_value=keypad_chr[ROW][COL];
				break;
			}
		}
		if((keypad_value)!=0xFF)
		{
			break;
		}
		
	}
	return keypad_value;
}