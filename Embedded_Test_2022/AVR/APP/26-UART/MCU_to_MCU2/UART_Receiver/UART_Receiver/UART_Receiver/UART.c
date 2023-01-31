/*
 * UART.c
 *
 * Created: 7/7/2022 
 *  Author: Ali Morsy
 */ 



#include "UART.h"

#define	F_CPU	8000000ul
#include <util/delay.h>

void UART_init(u32 Baud_Rate,u8 Stop_Bit,u8 Parity)
{
	u16 UBRR;
	/*calculate UBRR Value >> UBRR=(Fco/16Baud_Rate)-1 */
	UBRR=(F_CPU/(16*Baud_Rate))-1;
	UBRRH=(u8)(UBRR>>8);
	UBRRL=(u8)UBRR;
	/*Set Parity */
	if (Parity==2)
	{
		/* EVEN PARITY  */
		UCSRC|=(1<<UPM1)|(1<<URSEL);
	}
	else if (Parity==3)
	{
		/* Odd PARITY  */
		UCSRC|=(1<<UPM1)|(1<<UPM0)|(1<<URSEL);		
	}
	/*Set Stop bit and Data size */
	if(Stop_Bit==1)
	{
		/* Set Bit size 8 bit data and 1 stop */
		UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
	}
	else if (Stop_Bit==2)
	{
		/* Set Bit size 8 bit data and 2 stop */
		UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<USBS)|(1<<URSEL);
	}

	/* Enable Transmitter & receiver in UCSRB Register */
	UCSRB|=(1<<TXEN)|(1<<RXEN);
	
	
}

void UART_Send_Data(u8 Data)
{
	/* wait for UDR Transmitter buffer to be Empty*/
	while(((UCSRA>>UDRE)&1)==0);
	/*Load data in UDRR */
	UDR=Data;
}


void UART_Send_String(u8* string)
{
	while(*string!='\0')
	{
		UART_Send_Data(*string);
		string++;
		_delay_ms(50);
	}
}

u8 UART_Receive_Data(void)
{
	/* wait for UDR Transmitter buffer to be Empty*/
	while(((UCSRA>>RXC)&1)==0);
	/*receive data from UDRR Receive Buffer */
	return UDR;
}
