/*************************************/
/* Author  : Ali Morsy  **************/
/* Version : 1          **************/
/* Date    : 22/9/022   **************/
/*         Smart Home				 */
/*************************************/

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

/* LIBs*/
#include "STD_TYPES.h"
#include "std_macros.h"

/* HAL */
#include "Hkeypad.h"
#include "LCD.h"

#include "Masseage.h"


extern u8 Global_u8DemandResponse;
extern u8 SPI_u8Response;

#define ROOM1		1
#define ROOM2		2
#define ROOM3		3
#define ROOM4		4
#define TV			5
#define AIR_CON		6


void Room_voidGetStatus(u8 copy_u8RoomNumber)
{
	Global_u8DemandResponse = SPI_MasterTransmit(copy_u8RoomNumber);  /* Send Request For Room Status */
	_delay_ms(100);
	SPI_u8Response = SPI_MasterTransmit(DEMAND_RESPONSE);             /* Receive Room Status */
	LCD_move_cursor(1,7);
	if (SPI_u8Response == ON_STATUS)
	{
		LCD_send_string(" ON");
	}
	else if(SPI_u8Response == OFF_STATUS)
	{
		LCD_send_string("OFF");
	}
}


void voidDisplayWindow(u8 copy_u8RoomNum)
{
	u8 Local_u8TurnON;
	u8 Local_u8TurnOFF;
	u8 Key_val = NOT_PRESSED;
	u8 Key_Flag = 0;
	LCD_clear();

	switch(copy_u8RoomNum)
	{
		case ROOM1:
			copy_u8RoomNum  = ROOM1_STATUS		;		/* Assign Status Message		*/
			Local_u8TurnON  = ROOM1_TURN_ON		;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = ROOM1_TURN_OFF	;		/* Assign Turn OFF Message		*/
			LCD_send_string("Room1: ")			;		/* Display Window On LCD		*/
			break;
		case ROOM2:
			copy_u8RoomNum  = ROOM2_STATUS		;		/* Assign Status Message		*/
			Local_u8TurnON  = ROOM2_TURN_ON		;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = ROOM2_TURN_OFF	;		/* Assign Turn OFF Message		*/
			LCD_send_string("Room2: ")			;		/* Display Window On LCD		*/
			break;
		case ROOM3:
			copy_u8RoomNum  = ROOM3_STATUS		;		/* Assign Status Message		*/
			Local_u8TurnON  = ROOM3_TURN_ON		;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = ROOM3_TURN_OFF	;		/* Assign Turn OFF Message		*/
			LCD_send_string("Room3: ")			;		/* Display Window On LCD		*/
			break;
		case ROOM4:
			copy_u8RoomNum  = ROOM4_STATUS		;		/* Assign Status Message		*/
			Local_u8TurnON  = ROOM4_TURN_ON		;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = ROOM4_TURN_OFF	;		/* Assign Turn OFF Message		*/
			LCD_send_string("Room4: ")			;		/* Display Window On LCD		*/
			break;
		case TV:
			copy_u8RoomNum  = TV_STATUS			;		/* Assign Status Message		*/
			Local_u8TurnON  = TV_TURN_ON		;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = TV_TURN_OFF		;		/* Assign Turn OFF Message		*/
			LCD_send_string(" TV  : ")			;		/* Display Window On LCD		*/
			break;
		case AIR_CON:
			copy_u8RoomNum  = AIR_CON_STATUS	;		/* Assign Status Message		*/
			Local_u8TurnON  = AIR_CON_TURN_ON	;		/* Assign Turn ON Message		*/
			Local_u8TurnOFF = AIR_CON_TURN_OFF	;		/* Assign Turn OFF Message		*/
			LCD_send_string("Con. : ")			;		/* Display Window On LCD		*/
			break;
		default:
			break;
	}
	
			/* Display Window On LCD */
	LCD_move_cursor(2,1);
	LCD_send_string("1:ON 2:OFF 0:Ret");
	
	/* Get Status */
	Room_voidGetStatus(copy_u8RoomNum);
	Key_Flag = 0;
	_delay_ms(50);
	do
	{
		Key_val = Keypad_4_4_Read();
		if ( Key_val != NOT_PRESSED && Key_Flag == 0)
		{
			if (Key_val == '1')
			{
				Global_u8DemandResponse = SPI_MasterTransmit(Local_u8TurnON);	 /* Turn ON Room1 */
				_delay_ms(10);
				Room_voidGetStatus(copy_u8RoomNum);	 /* Get Room1 State */
			}
			else if (Key_val == '2')
			{
				Global_u8DemandResponse = SPI_MasterTransmit(Local_u8TurnOFF); /* Turn OFF Room1 */
				_delay_ms(10);
				Room_voidGetStatus(copy_u8RoomNum);   /* Get Room1 State */
			}
			Key_Flag = 1;
		}
		else if( Key_val == NOT_PRESSED && Key_Flag ==1)
		{
			Key_Flag = 0;
		}
	} while(Key_val != '0');
	while( Keypad_4_4_Read() != NOT_PRESSED ) ;		/*  Waite until  Release '0' Key*/
	_delay_ms(30);
}

void Guest_u8Display(void)
{
	u8 Local_KeyVal = NOT_PRESSED;
	while( Local_KeyVal != '0')				/* Break while Loop if Get '0' Key */
	{
	
		/* Display Guest Window  */
		LCD_clear();
		_delay_ms(50);
		LCD_send_string("1:Room1 2:Room2");
		LCD_move_cursor(2,1);
		LCD_send_string("3:Room3 4:Room4");
		
		/* wait till key Pressed */
		do
		{
			Local_KeyVal = Keypad_4_4_Read();
		} while(Local_KeyVal == NOT_PRESSED );
		while( Keypad_4_4_Read() != NOT_PRESSED ) ;		/*  Waite until  Release '0' Key*/
		
		/*---------------  Check Key --------------- */
		if (Local_KeyVal == '1')
		{
			/* ----------------------------------------------ROOM 1---------------------------------------- */
			voidDisplayWindow(ROOM1);
		}
		else if (Local_KeyVal == '2')
		{
			/* ----------------------------------------------ROOM 2---------------------------------------- */
			voidDisplayWindow(ROOM2);
		}
		else if (Local_KeyVal == '3')
		{
			/* ----------------------------------------------ROOM 3---------------------------------------- */
			voidDisplayWindow(ROOM3);
		}
		else if (Local_KeyVal == '4')
		{
			/* ----------------------------------------------ROOM 4---------------------------------------- */
			voidDisplayWindow(ROOM4);
		}
	}	
	

}



void Admin_u8Display(void)
{
	u8 Local_KeyVal = NOT_PRESSED;
	while( Local_KeyVal != '0')
	{
		/* Display Admin Window  */
		LCD_clear();
		_delay_ms(50);
		LCD_send_string("1:Room1 2:Room2");
		LCD_move_cursor(2,1);
		LCD_send_string("3:Room3 4:more");
		
		/* wait till key Pressed */
		do
		{
			Local_KeyVal = Keypad_4_4_Read();
		} while(Local_KeyVal == NOT_PRESSED );
		
		while(Keypad_4_4_Read() != NOT_PRESSED );			/* wait till Release key*/
		
		/*---------------  Check Key --------------- */
		if (Local_KeyVal == '1')
		{
			/* ----------------------------------------------ROOM 1---------------------------------------- */
		
			voidDisplayWindow(ROOM1);		
		}
		else if (Local_KeyVal == '2')
		{
			/* ----------------------------------------------ROOM 2---------------------------------------- */
			voidDisplayWindow(ROOM2);		
		}
		else if (Local_KeyVal == '3')
		{
			/* ----------------------------------------------ROOM 3---------------------------------------- */
			voidDisplayWindow(ROOM3);		
		
		}
		else if (Local_KeyVal == '4')
		{
			/* ---------------------------------------------- More Option---------------------------------------- */		
			Admin_voidDisplayMore();
		}

	}	
	
while( Keypad_4_4_Read() != NOT_PRESSED ) ;		/*  Waite until  Release '0' Key*/
}

void Admin_voidDisplayMore(void)
{
	u8 Local_KeyVal = NOT_PRESSED;
	while( Local_KeyVal != '0')
	{
		/* Display More option Window  */
		LCD_clear();
		_delay_ms(50);
		LCD_send_string("1:Room4    2:TV");
		LCD_move_cursor(2,1);
		LCD_send_string("3:Air Con. 0:RET");
		
		/* wait till key Pressed */
		do
		{
			Local_KeyVal = Keypad_4_4_Read();
		} while(Local_KeyVal == NOT_PRESSED );
		
		while(Keypad_4_4_Read() != NOT_PRESSED );			/* wait till Release key*/
		
		/*---------------  Check Key --------------- */
		if (Local_KeyVal == '1')
		{
			/* ---------------------------------------------- ROOM 4---------------------------------------- */
			voidDisplayWindow(ROOM4);
		}
		else if (Local_KeyVal == '2')
		{
			/* ---------------------------------------------- TV ---------------------------------------- */
			voidDisplayWindow(TV);
		}
		else if (Local_KeyVal == '3')
		{
			/* ----------------------------------------------Air Con.---------------------------------------- */
			AirCon_voidDisplay();
		}
	}	
}

void AirCon_voidDisplay(void)
{
	
	u8 Local_KeyVal = NOT_PRESSED;
	while( Local_KeyVal != '0')
	{
		/* Display Air_Con. Window  */
		LCD_clear();
		_delay_ms(50);
		LCD_send_string("1:Set Temp.");
		LCD_move_cursor(2,1);
		LCD_send_string("2:Control  0:RET");
		
		/* wait till key Pressed */
		do
		{
			Local_KeyVal = Keypad_4_4_Read();
		} while(Local_KeyVal == NOT_PRESSED );
		
		  while(Keypad_4_4_Read() != NOT_PRESSED );			/* wait till Release key*/
		  
		  /*---------------  Check Key --------------- */
		if (Local_KeyVal == '1')
		{
			/* ---------------------------------------Set Temperature --------------------------------------- */
			Set_Temperature();
		}
		else if (Local_KeyVal == '2')
		{
			/* ------------------------------------ Air Conditioning Control---------------------------------- */
			voidDisplayWindow(AIR_CON);
		}
	
	}
	//while( Keypad_4_4_Read() != NOT_PRESSED ) ;		/*  Waite until  Release '0' Key*/
}

/* use this Function to Send Temperature Requested to Slave */
void Set_Temperature(void)
{
	u8 Local_u8Key=NOT_PRESSED;
	u8 Local_u8TempVal=0;
	
	/* Display Temperature Window */
	LCD_clear();
	_delay_ms(50);
	LCD_send_string("Temperature=   C");
	LCD_move_cursor(1,13);
	
	/* Get Temperature Value from Admin user  (2-Digit) */
	for(u8 i=0; i<2; i++)
	{
		do
		{
			Local_u8Key = Keypad_4_4_Read();				 /*    wait till Key Pressed			*/
															      
		} while(Local_u8Key == NOT_PRESSED );
						      
		while(Keypad_4_4_Read() != 0xFF);					 /* wait till Release key*/	
														      
		LCD_send_char(Local_u8Key);							 /*    Send Temp Value to LCD			*/
		
		/* Merge Digits in variables */
		if(i == 0)											      
		{													      
			Local_u8TempVal = (Local_u8Key - 48)*10 ;        /*    Get First Digit					*/
															      
		}													      
		else												      
		{													      
			Local_u8TempVal += (Local_u8Key - 48)   ;        /*    Get Second Digit					*/
		}															
	}														      
															      
	SPI_MasterTransmit(SEND_TEMP);							/*   Send Temperature Command			*/
	_delay_ms(200);											      
	SPI_MasterTransmit(Local_u8TempVal);					/*   Send Temperature Value				*/
	
	/* Now, Temp. Value Sent to Slave */
	LCD_clear();
	LCD_send_string("Temperature Sent");					/*   Send Message To LCD				*/
	_delay_ms(500);
	
}															      