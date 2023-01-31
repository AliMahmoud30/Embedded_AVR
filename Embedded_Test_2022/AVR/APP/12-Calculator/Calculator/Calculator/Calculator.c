/*
 * Calculator.c
 *
 * Created: 6/20/2022 6:50:10 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "LCD.h"
#include "Hkeypad.h"

#define NOTPRESSED	0xFF
int main(void)
{
	
	LCD_inti();
	Keypad_4_4_Init();
	unsigned char arr_of_operand1[2];
	unsigned char arr_of_operand2[2];
	unsigned char arithmetic_mark;
	
	unsigned char Counter1=0;
	unsigned char Counter2=0;
	unsigned char Keypad_Value;
	unsigned char Flag=0;
	unsigned int  Result;
    while(1)
    {
		Keypad_Value=Keypad_4_4_Read();
		if (Keypad_Value!=NOTPRESSED)
		{
			LCD_send_char(Keypad_Value);
			if((Keypad_Value!='+')&&(Keypad_Value!='-')&&(Keypad_Value!='*')&&(Keypad_Value!='/')&&(Keypad_Value!='=')&&(Keypad_Value!='C'))
			{
				if(Flag==0)
				{
					arr_of_operand1[Counter1]=Keypad_Value-48;
					Counter1++;
					if(Counter1==2)
					{
						Counter1=0;
					}
				}
				else if(Flag==1)
				{
					arr_of_operand2[Counter2]=Keypad_Value-48;
					Counter2++;
					if(Counter2==2)
					{
						Counter2=0;
					}
				}
				
			}
			else if((Keypad_Value=='+') || (Keypad_Value=='-')||(Keypad_Value=='*')|| (Keypad_Value=='/'))
			{
				arithmetic_mark=Keypad_Value;
				Flag=1;
			}
			else if(Keypad_Value=='=')
			{
				switch(arithmetic_mark)
				{
					case '+':
						Result=arr_of_operand1[0]+arr_of_operand2[0];
						//LCD_send_char('A');
						break;
					case '-':
						Result=arr_of_operand1[0]-arr_of_operand2[0];
						break;
					case '*':
						Result=arr_of_operand1[0]*arr_of_operand2[0];
						break;
					case '/':
						Result=arr_of_operand1[0]/arr_of_operand2[0];
						break;
					default:
						break;
				}
				LCD_send_char(Result+48);
			}
			else if(Keypad_Value=='C')
			{
					Counter1=0;
					Counter2=0;
					Flag=0;
					Result=0;
					LCD_clear();
			}

			_delay_ms(250);
			
		}
	 
    }
}