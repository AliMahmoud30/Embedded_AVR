/*
 * UART.h
 *
 * Created: 7/7/2022 8:06:37 AM
 *  Author: Morsy
 */ 


#ifndef UART_H_
#define UART_H_


#include "STD_TYPES.h"

#define UBRRL		*(volatile u8*)(0x29)
/* USART Control and Status Register B –UCSRB */
#define UCSRB		*(volatile u8*)(0x2A)
#define TXB8		0
#define RXB8		1
#define UCSZ2		2
#define TXEN		3
#define RXEN		4
#define UDRIE		5
#define TXCIE		6
#define RXCIE		7


/* USART Control and Status Register A–UCSRA */
#define UCSRA		*(volatile u8*)(0x2B)
#define MPCM	0
#define U2X		1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE	5
#define TXC		6
#define RXC		7	



/* USART I/O Data Register–UDR */
#define  UDR		*(volatile u8*)(0x2C)

#define  UBRRH		*(volatile u8*)(0x40)

/* USART Control and Status Register C–UCSRC*/
#define UCSRC		UBRRH

#define UCPOL		0
#define UCSZ0		1
#define UCSZ1		2
#define USBS		3
#define UPM0		4
#define UPM1		5
#define UMSEL		6
#define URSEL		7		/* write 0 to access UBRRH, write 1 to Access UCSRC*/


/* PARITY >> none(default)=0, EVEN=2, Odd=3 */
#define NONE		0
#define EVEN		2
#define ODD			3

void UART_init(u32 Baud_Rate,u8 Stop_Bit,u8 Parity);
void UART_Send_Data(u8 Data);
void UART_Send_String(u8* string);
u8 UART_Receive_Data(void);
#endif /* UART_H_ */