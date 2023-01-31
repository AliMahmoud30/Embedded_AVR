/*
 * MEEPROM.c
 *
 * Created: 6/9/2022 10:08:44 AM
 *  Author: Ali Morsy
 */ 

#include "MEEPROM.h"
#include "STD_TYPES.h"

void EEPROM_Write(u16 Address, u8 value)
{
	//EEPAR=Address;   // with pointer to unsigend short 
	/*setup location address */
	EEPARL=(u8)Address;
	EEPARH=(u8)(Address>>8);

	/*load Value to EEDR */
	EEPDR=value;
	/*Set EEMWE bit in EECR register to one */
	EEPCR|=(1<<EEPMWE);
	/*Set EEWE bit in EECR register to one */
	EEPCR|=(1<<EEPWE);
	/*Wait for completion write */
	while(((EEPCR>>EEPWE)&1) ==1);
}

u8 EEPROM_Read(u16 Address)
{
	u8 data;
	/*setup location address */
	EEPARH=(Address>>8);
	EEPARL=Address;
	/*Set EERE bit in EECR register to one to read  */
	EEPCR|=(1<<EEPRE);
	
	/* Read EEDR content */
	data=EEPDR;
	
	return data;
}
