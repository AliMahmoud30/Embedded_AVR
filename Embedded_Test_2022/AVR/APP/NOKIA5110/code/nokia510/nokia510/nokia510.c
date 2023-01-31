/*
 * nokia510.c
 *
 * Created: 11/22/2022 10:53:38 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define  F_CPU 8000000ul
#include <util/delay.h>

#include <stdlib.h>
#include <stdio.h>


/* LIBs */
#include "STD_TYPES.h"
#include "std_macros.h"

/* MCAL */
#include "GPIO.h"
#include "HSPI.h"
#include "MADC.h"

/* HAL */
#include "HNOKIA5110.h"


#define DHT11_PIN 7
u8 c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;

void Request()						/* Microcontroller send start pulse or request */
{
	DDRD |= (1<<DHT11_PIN);
	PORTD &= ~(1<<DHT11_PIN);		/* set to low pin */
	_delay_ms(20);					/* wait for 20ms */
	PORTD |= (1<<DHT11_PIN);		/* set to high pin */
}

void Response()						/* receive response from DHT11 */
{
	DDRD &= ~(1<<DHT11_PIN);
	while(PIND & (1<<DHT11_PIN));
	while((PIND & (1<<DHT11_PIN))==0);
	while(PIND & (1<<DHT11_PIN));
}

u8 Receive_data()							/* receive data */
{
	for (int q=0; q<8; q++)
	{
		while((PIND & (1<<DHT11_PIN)) == 0);	/* check received bit 0 or 1 */
		_delay_us(30);
		if(PIND & (1<<DHT11_PIN))				/* if high pulse is greater than 30ms */
		c = (c<<1)|(0x01);						/* then its logic HIGH */
		else									/* otherwise its logic LOW */
		c = (c<<1);
		while(PIND & (1<<DHT11_PIN));
	}
	return c;
}




int main(void)
{
	
	char data[5]={8,9,5};
	u8 TempVAl;
	
	/* NOKIA5110 initialization */
	NOKIA5110_voidInit();
	
	/* ADC initialization */
	MADC_Init();
	NOKIA5110_SendString("LM35",30,0);
	NOKIA5110_SendString("Temp= ",3,2);
	
	/*
	for (u8 i=0; i<10; i++)
	{
		NOKIA5110_SendChar(i+48,41,3);
		_delay_ms(500);
	}*/

	
    while(1)
    {
		
		TempVAl =( ( ( MADC_Read(0) *(5.0/1024) ) *1000 )/10.0  );
        NOKIA5110_SendChar((TempVAl/100)+48,40,2);	
        NOKIA5110_SendChar(((TempVAl/10)%10)+48,47,2);
		NOKIA5110_SendChar((TempVAl%10)+48,54,2);
		NOKIA5110_SendString("C",62,2);

		/**************************** DHT_11 (Humidity & Temperature) Sensor *****************************/
/*
// 		Request();				/ * send start pulse * /
// 		
// 		//Response();				/ * receive response * /
// 		NOKIA5110_SendString("H=",0,2);
// 	//	I_RH=Receive_data();	/ * store first eight bit in I_RH * /
// 		//D_RH=Receive_data();	/ * store next eight bit in D_RH * /
// 		//I_Temp=Receive_data();	/ * store next eight bit in I_Temp * /
// 		//D_Temp=Receive_data();	/ * store next eight bit in D_Temp * /
// 		//CheckSum=Receive_data();/ * store next eight bit in CheckSum * /
// 		
// 		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
// 		{
// 			//	lcd_gotoxy(0,0);
// 			//	lcd_print("Error");
// 			
// 		}
// 		
// 		else
// 		{
// 			NOKIA5110_SendString("H=",0,2);
// 			itoa(I_RH,data,10);
// 			//lcd_print(data);
// 			unsigned char i=0;
// 			u8 x;
// 			while (data[i] |= 0)
// 			{
// 				x=12;
// 			NOKIA5110_SendChar((data[i]/10)+48,x,2);
// 				x+=6;
// 				i++;
// 			}
// 
// 			//NOKIA5110_SendChar('.',7);
// 			/ *
// 			itoa(D_RH,data,10);
// 			lcd_print(data);
// 			NOKIA5110_SendChar('.',);
// 		
// 			LCD_move_cursor(2,10);
// 			LCD_send_string("T=");
// 			itoa(I_Temp,data,10);
// 			lcd_print(data);
// 			lcd_print(".");
// 			
// 			itoa(D_Temp,data,10);
// 			lcd_print(data);
// 			LCD_send_char(0xDF);
// 			LCD_send_char(0x43);* /
//}
*/

	}
}