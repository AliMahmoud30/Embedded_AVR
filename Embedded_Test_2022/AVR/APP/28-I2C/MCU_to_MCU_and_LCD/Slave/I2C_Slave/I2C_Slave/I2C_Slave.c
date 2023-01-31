/*
 * I2C_Slave.c
 *
 * Created: 8/11/2022 4:07:10 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_TYPES.h"
#include "std_macros.h"

#include "LCD.h"
#include "MI2C.h"

#define Slave_ADDRESS		0X30
int main(void)
{
	DIO_Set_Pin_Direction(B,0,OUTPUT);
	/****************Local Variables*******************************/
	u8 Data=0;
	volatile u8 Counter=0;
	volatile u8 i=0;
	volatile s8 Ack_Status;
	
	/*************** Initialization**********************************/
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	MI2C_voidSlaveInit(Slave_ADDRESS);
	/****************************************************************/
	LCD_clear();
	LCD_send_string("Slave Device:");
	LCD_move_cursor(2,1);
	LCD_send_string("Receiving: ");
	while(1)
	{
		switch (MI2C_u8SlaveListen())
		{
		case 0:      
			/**************** Slave Receiver *************************/
			LCD_move_cursor(2,1);
			LCD_send_string("Receiving:     ");
			Counter=0;
			do 
			{
				Data=MI2C_u8Slave_Receive();
				LCD_move_cursor(2,12);
				LCD_send_char(Data+48);
				Counter++;
			} while(Counter<10);
			break;
			
		case 1:   
		/*********** Slave  Transmitter *****************************/
			LCD_move_cursor(2,1);
			LCD_send_string("Sending:       ");
			Counter=0;
			do 
			{	
				Ack_Status=I2C_Slave_Transmit(Counter);
				LCD_move_cursor(2,12);
				LCD_send_char(Counter+48);
				Counter++;
			} while(Ack_Status==0);
				
			break;
		default:
			break;
		}
	     
    }
}