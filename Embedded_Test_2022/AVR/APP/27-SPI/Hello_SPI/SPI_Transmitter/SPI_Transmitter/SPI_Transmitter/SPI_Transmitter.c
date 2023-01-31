/*
 * SPI_Transmitter.c
 *
 * Created: 7/11/2022 9:07:27 AM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define	F_CPU	8000000ul
#include <util/delay.h>


#include "HSPI.h"
#include "GPIO.h"


int main(void)
{
	u8 Data=0x0F,i;
	DIO_Set_Pin_Direction(A,0,OUTPUT);
	_delay_ms(2000);
	
	 /* Initialization */
	 SPI_MasterInit();

	/* for (i=0;i<10;i++)
	 {
		 Data=SPI_MasterTransmit(i+48);
		 _delay_ms(300);
		 if(Data==0x18)
		 {
			 DIO_Set_Pin_Value(A,0,HIGH);
		 }
	 }
	 */
			Data=SPI_MasterTransmit(0x30);
			if (Data==0xFF)
			{
				DIO_Set_Pin_Value(A,0,HIGH);
			
			}
			else
			{
				DIO_Set_Pin_Value(A,0,LOW);
			}
			_delay_ms(2000);
			Data=SPI_MasterTransmit(0x30);
    while(1)
    {/*
		Data=SPI_MasterTransmit(Data);
		if (Data==0xFF)
		{
			DIO_Set_Pin_Value(A,0,HIGH);
			Data=0x50;
		}
		else if(Data==0x23)
		{
			DIO_Set_Pin_Value(A,0,LOW);
			Data=0x0F;
		}
					
	    _delay_ms(1000);
	*/
    }
	
}