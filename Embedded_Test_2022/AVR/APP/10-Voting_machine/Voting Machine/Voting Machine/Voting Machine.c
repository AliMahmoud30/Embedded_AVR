/*
 * Voting_Machine.c
 *
 * Created: 6/19/2022 4:55:15 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "LCD.h"
#include "HButton.h"


#define candidate_A		0
#define candidate_B		1
#define candidate_C		2
#define candidate_D		3
#define RESET			4



int main(void)
{
	Button_init_Pull_UP(B,candidate_A);
	Button_init_Pull_UP(B,candidate_B);
	Button_init_Pull_UP(B,candidate_C);
	Button_init_Pull_UP(B,candidate_D);
	Button_init_Pull_UP(B,RESET);
	
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	LCD_send_string("A=");
	LCD_move_cursor(1,13);
	LCD_send_string("B=");
	LCD_move_cursor(2,1);
	LCD_send_string("C=");
	LCD_move_cursor(2,13);
	LCD_send_string("D=");
	
	unsigned char Counter_1=0;
	unsigned char Counter_2=0;
	unsigned char Counter_3=0;
	unsigned char Counter_4=0;
	
    while(1)
    {
		if(Button_Read(B,candidate_A)==0)
		{
			while (Button_Read(B,candidate_A)==0);
			Counter_1++;
		}
		else if (Button_Read(B,candidate_B)==0)
		{
			while (Button_Read(B,candidate_B)==0);
			Counter_2++;
		}
		else if (Button_Read(B,candidate_C)==0)
		{
			while (Button_Read(B,candidate_C)==0);
			Counter_3++;
		}
		else if (Button_Read(B,candidate_D)==0)
		{
			while (Button_Read(B,candidate_D)==0);
			Counter_4++;
		}	
		else if (Button_Read(B,RESET)==0)
		{
			while (Button_Read(B,RESET)==0);
			Counter_1=0;
			Counter_2=0;
			Counter_3=0;
			Counter_4=0;
		}						
     	LCD_move_cursor(1,3);
     	LCD_send_char(Counter_1+48);
     	LCD_move_cursor(1,15);
     	LCD_send_char(Counter_2+48);
     	LCD_move_cursor(2,3);
    	LCD_send_char(Counter_3+48);
     	LCD_move_cursor(2,15);
     	LCD_send_char(Counter_4+48);
	
    }
}