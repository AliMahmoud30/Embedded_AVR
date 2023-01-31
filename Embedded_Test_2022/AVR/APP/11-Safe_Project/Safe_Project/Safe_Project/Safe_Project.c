/*
 * Safe_Project.c
 *
 * Created: 6/20/2022 2:10:24 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "LCD.h"
#include "Hkeypad.h"
#include "MEEPROM.h"
#include "HLED.h"

/* EEPROM Location */
#define EEPROM_PASS_LOACTION_1				0x00
#define EEPROM_PASS_LOACTION_2				0x01
#define EEPROM_PASS_LOACTION_3				0x02
#define EEPROM_PASS_LOACTION_4				0x03
#define EEPROM_PASS_LOCATION_State			0x04
#define PASSWORD_STATE						0xF3

#define PASSWORD_SIZE	4
#define PASSWORD_TRIES	3

#define LED_GREEN		0
#define LED_RED			1



/* Functions prototype*/
unsigned char Reset_pass(void);
unsigned char Check_Pass(void);


int main(void)
{
	unsigned char Reset_state=0x00;
	unsigned char Check_state=0x00;
	signed char Counter;
	LCD_inti();			 /* Keypad Initialization*/
	Keypad_4_4_Init();	 /* Keypad Initialization*/
	LED_init(B,LED_GREEN);		 	
	LED_init(B,LED_RED);
	LED_OFF(B,LED_GREEN);
	LED_OFF(B,LED_RED);
	
	/* Check EEPROM password Location State to Reset password or no */
	if(EEPROM_Read(EEPROM_PASS_LOCATION_State)!=PASSWORD_STATE)
	{
		while(Reset_state==0)
		{
			Reset_state=Reset_pass();
			if (Reset_state!=0)
			{
				LED_ON(B,LED_GREEN);
				_delay_ms(500);
				LED_OFF(B,LED_GREEN);
			}
			else if(Reset_state==0)
			{
				LED_ON(B,LED_RED);
				_delay_ms(500);
				LED_OFF(B,LED_RED);
			}
		}	
	}
	
	/* get password from user and compare it with password stored in EEPROM*/
	for(Counter=PASSWORD_TRIES;Counter>0;Counter--)
	{
		Check_state=Check_Pass();
		if (Check_state==0XFF)
		{
			LED_ON(B,LED_GREEN);
			_delay_ms(500);
			LED_OFF(B,LED_GREEN);
			break;
		}
		else
		{
			LED_ON(B,LED_RED);
			LCD_send_string("Tries Left:");
			LCD_send_char(Counter-1+48);
			_delay_ms(1000);
			LED_OFF(B,LED_RED);
			LCD_clear();
		}
		
	}
	if(Check_state==0)
	{
		LCD_clear();
		LCD_send_string("System Closed");
		LED_ON(B,LED_RED);
		while(1);
	}

	
    while(1)
    {
		LED_ON(B,LED_RED);
		_delay_ms(500);
		LED_OFF(B,LED_RED);
		_delay_ms(500);
		
    }
}

unsigned char Reset_pass(void)
{
	unsigned char counter;
	unsigned char keypad_value=0XFF;
	unsigned char Pass_array[PASSWORD_SIZE];
	unsigned char pass_State;
	
	LCD_send_string("Reset Password:");
	LCD_move_cursor(2,1);
	for(counter=0;counter<PASSWORD_SIZE;counter++)
	{
		while(keypad_value==0xFF)
		{
			keypad_value=Keypad_4_4_Read();
		}
		LCD_send_char(keypad_value);
		_delay_ms(500);
		LCD_move_cursor(2,counter+1);
		LCD_send_char('*');
		Pass_array[counter]=keypad_value;
		keypad_value=0XFF;
	}
		EEPROM_Write(EEPROM_PASS_LOACTION_1,Pass_array[0]);
		EEPROM_Write(EEPROM_PASS_LOACTION_2,Pass_array[1]);
		EEPROM_Write(EEPROM_PASS_LOACTION_3,Pass_array[2]);
		EEPROM_Write(EEPROM_PASS_LOACTION_4,Pass_array[3]);
		EEPROM_Write(EEPROM_PASS_LOCATION_State,PASSWORD_STATE);
	
	 	LCD_clear();
	 	LCD_send_string("Confirm Password");
		_delay_ms(1000);
		/* Read EEPROM Locations to confirm Password */
		if(EEPROM_Read(EEPROM_PASS_LOACTION_1)==Pass_array[0]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_2)==Pass_array[1]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_3)==Pass_array[2]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_4)==Pass_array[3]&&
		   EEPROM_Read(EEPROM_PASS_LOCATION_State)==PASSWORD_STATE)
			{
				LCD_clear();
				LCD_send_string("Password Stored");
				_delay_ms(2000);
				LCD_clear();
				pass_State=0XFF;
			}
			else
			{
				LCD_clear();
				LCD_send_string("Error to Store");
				LCD_move_cursor(2,1);
				LCD_send_string("Password");
				_delay_ms(2000);
				LCD_clear();
				pass_State=0x00;
			}
			return pass_State;
}

unsigned char Check_Pass(void)
{
	char counter;
	unsigned char keypad_value=0XFF;
	unsigned char Pass_array[PASSWORD_SIZE];
	unsigned char pass_State;
	
	LCD_send_string("Check Password:");
	LCD_move_cursor(2,1);
	for(counter=0;counter<PASSWORD_SIZE;counter++)
	{
		while(keypad_value==0xFF)
		{
			keypad_value=Keypad_4_4_Read();
		}
		LCD_send_char(keypad_value);
		_delay_ms(500);
		LCD_move_cursor(2,counter+1);
		LCD_send_char('*');
		Pass_array[counter]=keypad_value;
		keypad_value=0XFF;
	}
		if(EEPROM_Read(EEPROM_PASS_LOACTION_1)==Pass_array[0]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_2)==Pass_array[1]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_3)==Pass_array[2]&&
		   EEPROM_Read(EEPROM_PASS_LOACTION_4)==Pass_array[3])
		 {
			LCD_clear();
			LCD_send_string("Right Password");
			_delay_ms(2000);
			LCD_clear();
			pass_State=0xFF;
		 }
		 else
		 {
			LCD_clear();
			LCD_send_string("wrong Password");
			_delay_ms(2000);
			LCD_clear();
			pass_State=0x00;
		 }
		 return pass_State;
}