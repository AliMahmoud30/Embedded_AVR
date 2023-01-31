/*
 * HSPI.h
 *
 * Created: 7/11/2022 9:09:56 AM
 *  Author: Morsy
 */ 


#ifndef HSPI_H_
#define HSPI_H_

#include "STD_TYPES.h"
#include "GPIO.h"


/* SPI Data Register */
#define SPDR	*(volatile u8*)(0x2F)

/* SPI Status Register */
#define SPSR	*(volatile u8*)(0x2E)
#define SPI2X	0
#define	WCOL	6
#define	SPIF	7

/* SPI Control Register*/
#define SPCR	*(volatile u8*)(0x2D)
#define SPR0	0
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7

#define SS		B,4
#define MOSI	B,5
#define MISO	B,6
#define SCK		B,7

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
u8 SPI_MasterTransmit(u8 Data);
u8 SPI_SlaveReceive(u8 Data);
void SPI_MasterSendString(u8* string);

#endif /* HSPI_H_ */