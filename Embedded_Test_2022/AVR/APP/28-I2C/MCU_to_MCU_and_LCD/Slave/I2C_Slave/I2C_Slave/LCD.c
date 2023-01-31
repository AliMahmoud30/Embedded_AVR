/*
 * LCD.c
 *
 * Created: 7/6/2020 2:44:45 PM
 *  Author: PC
 */ 

#include "GPIO.h"
#include "std_macros.h"
#include "LCD.h"
#define F_CPU 8000000ul
#include <util/delay.h>

static void LCD_Enable(void);

void LCD_inti(void)
{
	_delay_ms(200);
	#if defined LCD_eghit_bit
		// Data Pins 
	DIO_Set_Pin_Direction(LCD_D0,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D1,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D2,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D3,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D4,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D5,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D6,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D7,OUTPUT);
	// RS & RW & EN
	DIO_Set_Pin_Direction(LCD_EN,OUTPUT);
	DIO_Set_Pin_Direction(LCD_RS,OUTPUT);
	DIO_Set_Pin_Direction(LCD_RW,OUTPUT);
	DIO_Set_Pin_Value(LCD_RW,LOW);
	// Commands
	LCD_send_cmd(EGHIT_BITS);
	_delay_ms(1);
	LCD_send_cmd(display_on_cursor_on);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
    #elif defined LCD_four_bit
	// Data Pins 
	DIO_Set_Pin_Direction(LCD_D4,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D5,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D6,OUTPUT);
	DIO_Set_Pin_Direction(LCD_D7,OUTPUT);
	// RS & RW & EN
	DIO_Set_Pin_Direction(LCD_EN,OUTPUT);
	DIO_Set_Pin_Direction(LCD_RS,OUTPUT);
	DIO_Set_Pin_Direction(LCD_RW,OUTPUT); 
	DIO_Set_Pin_Value(LCD_RW,LOW);
	// Commands
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);	
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_send_cmd(display_on_cursor_on);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}	

 // sent character to LCD
 void LCD_send_char(char data)
{
	#if defined LCD_eghit_bit

 		DIO_Set_Pin_Value(LCD_D0,GET_BIT(data,0));
		DIO_Set_Pin_Value(LCD_D1,GET_BIT(data,1));
		DIO_Set_Pin_Value(LCD_D2,GET_BIT(data,2));
		DIO_Set_Pin_Value(LCD_D3,GET_BIT(data,3));
		DIO_Set_Pin_Value(LCD_D4,GET_BIT(data,4));
		DIO_Set_Pin_Value(LCD_D5,GET_BIT(data,5));
		DIO_Set_Pin_Value(LCD_D6,GET_BIT(data,6));
		DIO_Set_Pin_Value(LCD_D7,GET_BIT(data,7));
		
		DIO_Set_Pin_Value(LCD_RS,HIGH);
		LCD_Enable();
	 
	#elif defined LCD_four_bit
	/* old 
		DIO_SET_HIGH_Nipple_Value(D,data>>4);
		DIO_Set_Pin_Value(D,RS,HIGH);
		LCD_Enable();
		DIO_SET_HIGH_Nipple_Value(D,data);
		DIO_Set_Pin_Value(D,RS,HIGH);
		LCD_Enable();
	*/
		/*Write High Nipple */
		DIO_Set_Pin_Value(LCD_D4,GET_BIT(data,4));
		DIO_Set_Pin_Value(LCD_D5,GET_BIT(data,5));
		DIO_Set_Pin_Value(LCD_D6,GET_BIT(data,6));
		DIO_Set_Pin_Value(LCD_D7,GET_BIT(data,7));
		
		DIO_Set_Pin_Value(LCD_RS,HIGH);
		LCD_Enable();
		
		/*Write LOW Nipple */
		DIO_Set_Pin_Value(LCD_D4,GET_BIT(data,0));
		DIO_Set_Pin_Value(LCD_D5,GET_BIT(data,1));
		DIO_Set_Pin_Value(LCD_D6,GET_BIT(data,2));
		DIO_Set_Pin_Value(LCD_D7,GET_BIT(data,3));

		DIO_Set_Pin_Value(LCD_RS,HIGH);
		LCD_Enable();
		
	 #endif
}

void LCD_send_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
		
	}
}

static void LCD_Enable(void)
{
	DIO_Set_Pin_Value(LCD_EN,HIGH);
	_delay_ms(2);
	DIO_Set_Pin_Value(LCD_EN,LOW);
}

void LCD_send_cmd(char cmd)
{
	#if defined LCD_eghit_bit
	
	DIO_Set_Pin_Value(LCD_D0,GET_BIT(cmd,0));
	DIO_Set_Pin_Value(LCD_D1,GET_BIT(cmd,1));
	DIO_Set_Pin_Value(LCD_D2,GET_BIT(cmd,2));
	DIO_Set_Pin_Value(LCD_D3,GET_BIT(cmd,3));
	DIO_Set_Pin_Value(LCD_D4,GET_BIT(cmd,4));
	DIO_Set_Pin_Value(LCD_D5,GET_BIT(cmd,5));
	DIO_Set_Pin_Value(LCD_D6,GET_BIT(cmd,6));
	DIO_Set_Pin_Value(LCD_D7,GET_BIT(cmd,7));
	
	DIO_Set_Pin_Value(LCD_RS,LOW);
	LCD_Enable(); 
    #elif defined LCD_four_bit 
	/* old
	
	DIO_SET_HIGH_Nipple_Value(D,cmd>>4);
	DIO_Set_Pin_Value(D,RS,LOW);
	LCD_Enable();
	DIO_SET_HIGH_Nipple_Value(D,cmd);
	DIO_Set_Pin_Value(D,RS,LOW);
	LCD_Enable();	
	*/
	/*Write High Nipple */
	DIO_Set_Pin_Value(LCD_D4,GET_BIT(cmd,4));
	DIO_Set_Pin_Value(LCD_D5,GET_BIT(cmd,5));
	DIO_Set_Pin_Value(LCD_D6,GET_BIT(cmd,6));
	DIO_Set_Pin_Value(LCD_D7,GET_BIT(cmd,7));
			
	DIO_Set_Pin_Value(LCD_RS,LOW);
	LCD_Enable();
	
	/*Write LOW Nipple */
	DIO_Set_Pin_Value(LCD_D4,GET_BIT(cmd,0));
	DIO_Set_Pin_Value(LCD_D5,GET_BIT(cmd,1));
	DIO_Set_Pin_Value(LCD_D6,GET_BIT(cmd,2));
	DIO_Set_Pin_Value(LCD_D7,GET_BIT(cmd,3));

	DIO_Set_Pin_Value(LCD_RS,LOW);
	LCD_Enable();
	
	#endif

}

void LCD_clear(void)
{
	LCD_send_cmd(CLR_SCREEN);
	
}

void LCD_move_cursor(char row, char coloumn)
{
	volatile char data;
	if(row==1)
	{
		data=0x80+(coloumn-1);
	}
	else if (row==2)
	{
		data=0xc0+(coloumn-1);
	}
	else if (row>2 || row<1 ||coloumn>16 || coloumn<1)
	{
		data=0x80;
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}

void lcd_print(char *str)
{
	unsigned char i=0;
	while (str[i] |= 0)
	{
		LCD_send_char(str[i]);
		i++;
	}
}
