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


/* MCAL*/
#include "GPIO.h"
#include "HSPI.h"
#include "MEEPROM.h"
#include "Timers.h"

/* HAL */
#include "LCD.h"
#include "Hkeypad.h"
#include "HLED.h"

/* App_Header_File */
#include "Masseage.h"
#include "SmartHome_Functions.h"


/* EEPROM Locations */
#define EEPROM_ADMIN_PASS_LOCATION			(u16)0x10     /* Admin Password Location */
#define EEPROM_ADMIN_PASS_STATE_LOCATION	(u16)0x11	  /* Admin Password State Location */
#define EEPROM_GUEST_PASS_LOCATION			(u16)0x12     /* GUEST Password Location*/
#define EEPROM_GUEST_PASS_STATE_LOCATION	(u16)0x13     /* GUEST Password State Location*/

#define ADMIN_PASSWORD_STATE					0xF3	  /* ADMIN Password State*/
#define GUEST_PASSWORD_STATE					0xAF	  /* GUEST Password State*/

#define PASSWORD_SIZE							4		  /* Password Size */
#define	PASSWORD_TRIES							3		  /* PASSWORD TRIES */

#define TIME_OF_SYSTEM_CLOSED				(u16)20000

#define BLOCK_LED								D,0
#define GUEST_LED								D,1
#define ADMIN_LED								D,2

void FirstTime_voidDisplay(void);		
void Guest_voidSetPassword(void);
void Admin_voidSetPassword(void);
u8 AdminLogin_u8CheckPassword(void);
u8 GuestLogin_u8CheckPassword(void);


u8 SPI_u8Response;
u8 Global_u8DemandResponse;


int main(void)
{
	u8 Key_val, Local_u8Key_Flag=0;
	u8 i=0;
	
	/* LED  Initialization */
	LED_init(BLOCK_LED);
	LED_init(GUEST_LED);
	LED_init(ADMIN_LED);
	
	/*TURN OFF ALL LEDs */
	LED_OFF(BLOCK_LED);
	LED_OFF(GUEST_LED);
	LED_OFF(ADMIN_LED);
	
	/*Keypad Initialization */
	Keypad_4_4_Init();
   
	/*LCD Initialization */
	LCD_inti();
	
	/* SPI Initialization */
	SPI_MasterInit();
	DIO_Set_Pin_Direction(MISO,INPUT);
	//LCD_move_cursor(2,1);
	
	//_delay_ms(500);
	//Admin_u8Display();


	FirstTime_voidDisplay();
	_delay_ms(500);
	
	/* Password Initialization (Reset & Check)*/
	/* Check if Admin Password & Guest Password is set ? 
		if True  : go to Check Selection Mode Window
		if False : go to Set Password Window
	*/
	Admin_voidSetPassword();      
	Guest_voidSetPassword();
	
	
	while(1)
	{
	  
		/* Home Screen */
		LCD_clear();
		LCD_send_string("Select Mode :");
		LCD_move_cursor(2,1);
		LCD_send_string("0:Admin 1:Guest");
		
		LED_OFF(GUEST_LED);
		LED_OFF(ADMIN_LED);
		
		/* Get Key Value */
		do 
		{
			Key_val = Keypad_4_4_Read();
		} while(Key_val == NOT_PRESSED);
		while( Keypad_4_4_Read() != NOT_PRESSED ) ;		/*  Waite until  Release '0' Key*/
		
		//_delay_ms(200);
		if ( (Key_val-48) == 0x00 )
		{
			/*--------------------------------------- Admin Mode ----------------------------------------*/
			if (AdminLogin_u8CheckPassword() == 0xFF)
			{
				/* Correct Password */
				
				LED_ON(ADMIN_LED);  /* Turn ON Admin LED */
		
				Admin_u8Display();  /* go to Admin Mode */
				
			}
			else
			{
				/* Incorrect password 3 Times */
				LED_ON(BLOCK_LED);		/* Turn ON Block LED */
				
				LCD_clear();
				LCD_send_string("System Closed");
				LCD_move_cursor(2,1);
				LCD_send_string("Waite 20 Sec");
				_delay_ms(TIME_OF_SYSTEM_CLOSED);
				
				LED_OFF(BLOCK_LED);		/* Turn OFF Block LED */
			}
		}
	  else if ( (Key_val-48) == 0x01 )
	  {
		  /*------------------------------------------ Guest Mode --------------------------------------*/
		  if (GuestLogin_u8CheckPassword() == 0xFF)
		  {
			 /* Correct Password */
			 
			  LED_ON(GUEST_LED);  /* Turn ON Guest LED */
			
			  Guest_u8Display();    /* go to Guest Mode */
			
		  }
		  else
		  {
			  /* Incorrect password 3 Times */
			  LED_ON(BLOCK_LED);		/* Turn ON Block LED */
			  
			  LCD_clear();
			  LCD_send_string("System Closed");
			  LCD_move_cursor(2,1);
			  LCD_send_string("Waite 20 Sec");
			  _delay_ms(TIME_OF_SYSTEM_CLOSED);
			  
			  LED_OFF(BLOCK_LED);		/* Turn OFF Block LED */
		  }
	  }
	  else
	  {
		  /* Wrong Choice */
		   LCD_clear();
		   LCD_send_string("Wrong Choice");
		   _delay_ms(1500);
	  }
	
	}
}



void FirstTime_voidDisplay()
{
	LCD_clear();
	LCD_send_string("Welcome to Smart");
	LCD_move_cursor(2,1);
	LCD_send_string("Home system");
	_delay_ms(2000);
	LCD_clear();
}

void Admin_voidSetPassword(void)
{
	u8 i=0;
	u8 Local_Key_val;
	u8 Local_u8PassValue = 0;
	
	/* Check EEPROM Password Location State for Admin */
	if (EEPROM_Read(EEPROM_ADMIN_PASS_STATE_LOCATION) != ADMIN_PASSWORD_STATE)
	{
		LCD_send_string("Admin Login");
		LCD_move_cursor(2,1);
		LCD_send_string("First Time");
		_delay_ms(2000);
		LCD_clear();
		LCD_send_string("Set Admin Pass");
		LCD_move_cursor(2,1);
		LCD_send_string("Admin Pass:");
		
		while (i < PASSWORD_SIZE)
		{
			do
			{
				Local_Key_val = Keypad_4_4_Read();
				
			} while (Local_Key_val == 0xFF);
			_delay_ms(200);
			LCD_send_char(Local_Key_val);			/* First Digit in col 12 on LCD*/
			_delay_ms(100);
			LCD_move_cursor(2,12+i);		/* Replace Number with * on LCD*/
			LCD_send_char('*');
			Local_u8PassValue |= Local_Key_val-48;
			i++;
		}

		/* Store Password in EEPROM */
		EEPROM_Write(EEPROM_ADMIN_PASS_LOCATION,Local_u8PassValue);
		/* Set Admin Password State*/
		EEPROM_Write(EEPROM_ADMIN_PASS_STATE_LOCATION,ADMIN_PASSWORD_STATE);
		
		LCD_clear();
		LCD_send_string("Password Saved");
		_delay_ms(1000);
		LCD_clear();
	}
	else
	{
		/* No Thing*/
	}
	
}
void Guest_voidSetPassword(void)
{
	u8 i=0;
	u8 Local_Key_val;
	u8 Local_u8PassValue = 0;
	
	/* Check EEPROM Password Location State for Admin */
	if (EEPROM_Read(EEPROM_GUEST_PASS_STATE_LOCATION) != GUEST_PASSWORD_STATE)
	{
		LCD_send_string("Guest Login");
		LCD_move_cursor(2,1);
		LCD_send_string("First Time");
		_delay_ms(2000);
		LCD_clear();
		LCD_send_string("Set Guest Pass");
		LCD_move_cursor(2,1);
		LCD_send_string("Guest Pass:");
		
		while (i < PASSWORD_SIZE)
		{
			do
			{
				Local_Key_val = Keypad_4_4_Read();
				
			} while (Local_Key_val == 0xFF);
			_delay_ms(200);
			LCD_send_char(Local_Key_val);			/* First Digit in col 12 on LCD*/
			_delay_ms(100);
			LCD_move_cursor(2,12+i);		/* Replace Number with * on LCD*/
			LCD_send_char('*');
			Local_u8PassValue |= Local_Key_val-48;
			i++;
		}
		
		/* Store Password in EEPROM */
		EEPROM_Write(EEPROM_GUEST_PASS_LOCATION,Local_u8PassValue);
		/* Set Admin Password State*/
		EEPROM_Write(EEPROM_GUEST_PASS_STATE_LOCATION,GUEST_PASSWORD_STATE);
		
		LCD_clear();
		LCD_send_string("Password Saved");
		_delay_ms(1000);
		LCD_clear();
	}
	else
	{
		/* No Thing*/
	}
	
}

u8 AdminLogin_u8CheckPassword(void)
{
	u8 i=0,Counter=0;;
	u8 Local_Key_val;
	u8 Local_Check_state=0;
	u8 Local_u8PassValue=0;
	
	/* get password from user and compare it with password stored in EEPROM*/
	for(Counter=PASSWORD_TRIES; Counter>0; Counter--)
	{
		/* Check Password*/
		LCD_clear();
		LCD_send_string("Check Admin Pass");
		LCD_move_cursor(2,1);
		LCD_send_string("Admin Pass:");
		
		while (i < PASSWORD_SIZE)
		{
			do
			{
				Local_Key_val = Keypad_4_4_Read();
				
			} while (Local_Key_val == 0xFF);
			_delay_ms(200);
			LCD_send_char(Local_Key_val);			/* First Digit in col 12 on LCD*/
			_delay_ms(100);
			LCD_move_cursor(2,12+i);		/* Replace Number with * on LCD*/
			LCD_send_char('*');
			Local_u8PassValue |= Local_Key_val-48;
			i++;
		}
		
		if (EEPROM_Read(EEPROM_ADMIN_PASS_LOCATION) == Local_u8PassValue)
		{
			/*Correct Password */
			LCD_clear();
			LCD_send_string("Correct Pass");
			_delay_ms(500);
			LCD_clear();
			Local_Check_state = 0xFF;
			break;
		}
		else
		{
			LCD_clear();
			LCD_send_string("Incorrect Pass");
			_delay_ms(500);
			LCD_move_cursor(2,1);
			LCD_send_string("Tries Left:");
			LCD_send_char(Counter-1+48);
			_delay_ms(1000);
			LCD_clear();
			Local_u8PassValue = 0;
			i = 0;						
		}
		
	}
	
	return Local_Check_state;
}
u8 GuestLogin_u8CheckPassword(void)
{
	u8 i=0,Counter=0;;
	u8 Local_Key_val;
	u8 Local_Check_state=0;
	u8 Local_u8Pass_Array[4];
	u8 Local_u8PassValue=0;
	
	/* get password from user and compare it with password stored in EEPROM*/
	for(Counter=PASSWORD_TRIES;Counter>0;Counter--)
	{
		/* Check Password*/
		LCD_clear();
		LCD_send_string("Check Guest Pass");
		LCD_move_cursor(2,1);
		LCD_send_string("Guest Pass:");
		
		while (i < PASSWORD_SIZE)
		{
			do
			{
				Local_Key_val = Keypad_4_4_Read();
				
			} while (Local_Key_val == 0xFF);
			_delay_ms(200);
			LCD_send_char(Local_Key_val);			/* First Digit in col 12 on LCD*/
			_delay_ms(100);
			LCD_move_cursor(2,12+i);		/* Replace Number with * on LCD*/
			LCD_send_char('*');
			Local_u8PassValue |= Local_Key_val-48;
			i++;
		}
		
		/* Store Password In Variable */
		if (EEPROM_Read(EEPROM_GUEST_PASS_LOCATION) == Local_u8PassValue)
		{
			/*Correct Password */
			LCD_clear();
			LCD_send_string("Correct Pass");
			_delay_ms(500);
			LCD_clear();
			Local_Check_state = 0xFF;
			break;
		}
		else
		{
			LCD_clear();
			LCD_send_string("Incorrect Pass");
			_delay_ms(500);
			LCD_move_cursor(2,1);
			LCD_send_string("Tries Left:");
			LCD_send_char(Counter-1+48);
			_delay_ms(1000);
			LCD_clear();
			Local_u8PassValue = 0;
			i = 0;
		}
		
	}
	
	return Local_Check_state;
}