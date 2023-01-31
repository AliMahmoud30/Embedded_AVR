/*
 * Hello_I2C_Slave.c
 *
 * Created: 8/10/2022 12:04:21 PM
 *  Author: Morsy
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "LCD.h"
#include "MI2C.h"


int main(void)
{
	s8 listen_status;
	u8 Data; 
	
	LCD_inti();
	LCD_send_string("Hello I2C:");
	LCD_move_cursor(2,1);
	DIO_Set_Pin_Direction(B,0,OUTPUT);
	//I2C_Set_Slave_Address(0x50);
	MI2C_voidSlaveInit(0x50);
	u8 i=0;
	
    while(1)
    {
		switch (MI2C_u8SlaveListen())
		{
			case 0:
				LCD_send_char(MI2C_u8Slave_Receive());	
				break;
			default:
				break;
		}

	}
		
 }
