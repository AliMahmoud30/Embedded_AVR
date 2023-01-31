/*
 * I2C_Master.c
 *
 * Created: 8/11/2022 4:05:01 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "LCD.h"
#include "MI2C.h"

#define Slave_ADDRESS_WRITE		0X30
#define Slave_ADDRESS_READ		0X31

int main(void)
{
	/******************** Local Variables****************************/
	u8 Counter=0;
	u8 Data=0;
	/******************** Initialization ****************************/
	LCD_inti();
	MI2C_u8voidInit();	
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("Master Device:");

	_delay_ms(500);
	
    while(1)
    {	
		
		/************************ Master Transmitter ******************/
		LCD_move_cursor(2,1);
		LCD_send_string("Sending:       ");
		MI2C_voidStart();
		MI2C_u8WriteAddress(Slave_ADDRESS_WRITE);
		_delay_ms(100);
		
		for(Counter=0;Counter<10;Counter++)
		{
			MI2C_u8WriteData(Counter);
			LCD_move_cursor(2,12);
			LCD_send_char(Counter+48);
			_delay_ms(500);
		}
		
		/************************ Master Receiver ******************/
		LCD_move_cursor(2,1);
		LCD_send_string("Receiving:     ");
		MI2C_u8RepeatedStart(Slave_ADDRESS_READ);
		_delay_ms(100);
		
		for(Counter=0;Counter<10;Counter++)
		{
			if (Counter<9)
			{
				Data=MI2C_u8ReadAck();
				LCD_move_cursor(2,12);
				LCD_send_char(Data+48);
			} 
			else
			{
				Data=MI2C_u8ReadNAck();
				LCD_move_cursor(2,12);
				LCD_send_char(Data+48);
			}
			_delay_ms(500);
		}
		
		MI2C_voidStop();
		
		//_delay_ms(500);
    }
}