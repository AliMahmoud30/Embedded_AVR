/*
 * SPI_Receiver.c
 *
 * Created: 7/11/2022 9:08:30 AM
 *  Author: Morsy
 */ 

//#include <avr/io.h>
#define	F_CPU	 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"

#include "HSPI.h"
#include "LCD.h"

int main(void)
{
	/* Initialization */
	LCD_inti();
	SPI_SlaveInit();
	
	u8 Data=0xFF;
	
	//_delay_ms(500);
	//LCD_clear();
	DIO_Set_Pin_Direction(A,0,INPUT);
	DIO_Set_Pin_Direction(A,1,OUTPUT);
	DIO_Set_Pin_Direction(A,2,OUTPUT);
	
	Data=SPI_SlaveReceive(Data);
	LCD_send_char(Data);
	
		Data=SPI_SlaveReceive(0xFF);
		LCD_send_char(Data);
	
    while(1)
    {
     
	 	DIO_Set_Pin_Value(A,2,HIGH);
		Data=SPI_SlaveReceive(Data);
		DIO_Set_Pin_Value(A,2,LOW);
	
	   if (Data==0x0F)
	   {
		   DIO_Set_Pin_Value(A,1,HIGH);
		   DIO_Set_Pin_Value(A,2,LOW);
		   Data=0x23;
	   }
	   else if(Data==0x50)
	   {
		    DIO_Set_Pin_Value(A,1,LOW);
		    DIO_Set_Pin_Value(A,2,HIGH);
			Data=0xFF;
	   }
		//Data=0xFF;
	   //LCD_send_char(Data);
	   //_delay_ms(100);
    }
}