/*************************************/
/* Author  : Ali Morsy  **************/
/* Version : 1          **************/
/* Date    : 22/5/021   **************/
/*************************************/

#ifndef GPIO_H
#define GPIO_H

#include "STD_TYPES.h"

// BASE ADDRESS FOR ALL PORTS  Base Address = Address of PIN Register
#define A	0x39  // PINA
#define B	0x36  // PINB
#define C	0x33  // PINC	
#define D	0x30  // PIND
	
#define OUTPUT 1	
#define INPUT  0

#define HIGH   1
#define LOW    0


/*        SET Direction         */ 
void DIO_Set_Port_Direction(u8 Base, u8 Direction);
void DIO_Set_Pin_Direction(u8 Base, u8 PIN, u8 Direction);

/*        SET Value         */ 
void DIO_Set_Port_Value(u8 Base, u8 Value);
void DIO_Set_Pin_Value(u8 Base,u8 PIN, u8 Value);

/*        Get Value         */ 
u8 DIO_Get_Port_value (u8 Base);
u8 DIO_Get_Pin_value  (u8 Base, u8 PIN);

/*        Toggle PIN         */ 
void DIO_Toggle_Pin(u8 Base, u8 PIN);

/* Set HIGH NIPPLE */

void DIO_SET_HIGH_Nipple_Value(u8 Base, u8 Data);

/* Set LOW NIPPLE */

void DIO_SET_LOW_Nipple_Value(u8 Base, u8 Data);

#endif  // GPIO_H