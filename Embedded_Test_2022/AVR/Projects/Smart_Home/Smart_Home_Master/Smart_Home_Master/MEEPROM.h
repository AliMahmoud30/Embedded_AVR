/*
 * MEEPROM.h
 *
 * Created: 6/9/2022 10:08:57 AM
 *  Author: Ali Morsy
 */ 


#ifndef MEEPROM_H_
#define MEEPROM_H_

#include "STD_TYPES.h"

/* EEEPROM Registers Address*/
#define EEPARL		*((volatile unsigned char*)(0x3E))
#define EEPARH		*((volatile unsigned char*)(0x3F))
#define EEPAR		*((volatile unsigned short*)(0x3E))
#define EEPDR		*((volatile unsigned char*)(0x3D))
#define EEPCR		*((volatile unsigned char*)(0x3C))


/* EECR*/
#define EEPRE	0
#define EEPWE	1
#define EEPMWE	2
#define EEPIE	3

void EEPROM_Write(u16 Address, u8 value);
u8 EEPROM_Read(u16 address);

#endif /* MEEPROM_H_ */