/*
 * Real_Time_Clock.c
 *
 * Created: 7/1/2022 9:34:19 PM
 *  Author: Ali Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "GPIO.h"
#include "H7_Segment.h"
#include "Timers.h"
#include "Hkeypad.h"
#include "LCD.h"
#include "STD_TYPES.h"


/*Enable Pins for all 7-Segments*/
#define EN_1	C,0
#define EN_2	C,1
#define EN_3	C,2
#define EN_4	C,3
#define EN_5	C,4
#define EN_6	C,5

#define NOT_PRESSED	0XFF

volatile u8 Second;
u8 Minutes,Hours;
u8 Keypad_Value;
u8 Fisrt_Number;
u8 Second_Number;

int main(void)
{
	/* ----------------------------------Initialization --------------------------- */
	DIO_Set_Pin_Direction(EN_1,OUTPUT);
	DIO_Set_Pin_Direction(EN_2,OUTPUT);
	DIO_Set_Pin_Direction(EN_3,OUTPUT);
	DIO_Set_Pin_Direction(EN_4,OUTPUT);
	DIO_Set_Pin_Direction(EN_5,OUTPUT);
	DIO_Set_Pin_Direction(EN_6,OUTPUT);
	
	LCD_inti();
	Keypad_4_4_Init();
	Seven_Segment_Init();
	Timer2_Overflow_Interrupt_Init();
	LCD_send_cmd(display_on_cursor_off);
	//LCD_send_string("Real Time Clock");
	//LCD_move_cursor(2,1);
	LCD_send_string("Press 1 to Edit..");
	/*------------------------------------------------------------------------------ */


    while(1)
    {
		Keypad_Value=Keypad_4_4_Read();
		if (Keypad_Value!=NOT_PRESSED)
		{
			while (Keypad_4_4_Read()!=NOT_PRESSED);
			if (Keypad_Value=='1')
			{
				/*-------------------------------------Hours Setting----------------------------------------*/
				LCD_clear();
				LCD_send_string("hours=--");
				LCD_move_cursor(1,7);
				do 
				{
				
					do 
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Fisrt_Number=Keypad_Value;
				
					do
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Second_Number=Keypad_Value;
				
					Hours=(Fisrt_Number-48)*10+(Second_Number-48);
				
					/* Check hour number less than 24 */
					if (Hours>=24)
					{
						LCD_clear();
						LCD_send_string("Error");
						LCD_move_cursor(2,1);
						LCD_send_string("max num is 23");
						_delay_ms(2000);
						LCD_clear();
						LCD_send_string("Try again");
						_delay_ms(500);
						LCD_clear();
						LCD_send_string("hours=--");
						LCD_move_cursor(1,7);
					}
				} while (Hours>=24);
				/*-------------------------------------Minutes Setting----------------------------------------*/
				LCD_clear();
				LCD_send_string("Minutes=--");
				LCD_move_cursor(1,9);
				do 
				{
				
					do
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Fisrt_Number=Keypad_Value;
				
					do
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Second_Number=Keypad_Value;
					Minutes=(Fisrt_Number-48)*10+(Second_Number-48);
				
					/* Check Minutes number less than 59 */
					if (Minutes>=60)
					{
						LCD_clear();
						LCD_send_string("Error");
						LCD_move_cursor(2,1);
						LCD_send_string("max num is 59");
						_delay_ms(2000);
						LCD_clear();
						LCD_send_string("Try again");
						_delay_ms(500);
						LCD_clear();
						LCD_send_string("Minutes=--");
						LCD_move_cursor(1,9);	
					}						
				} while (Minutes>60);
				/*-------------------------------------Seconds Setting----------------------------------------*/
				LCD_clear();
				LCD_send_string("Seconds=--");
				LCD_move_cursor(1,9);
				do 
				{
					do
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Fisrt_Number=Keypad_Value;
				
					do
					{
						Keypad_Value=Keypad_4_4_Read();
					} while (Keypad_Value==NOT_PRESSED);
					LCD_send_char(Keypad_Value);
					while (Keypad_4_4_Read()!=NOT_PRESSED);
					Second_Number=Keypad_Value;
				
					Second=(Fisrt_Number-48)*10+(Second_Number-48);
					/* Check Seconds less than 59 */
					if (Second>=60)
					{
						LCD_clear();
						LCD_send_string("Error");
						LCD_move_cursor(2,1);
						LCD_send_string("max num is 59");
						_delay_ms(2000);
						LCD_clear();
						LCD_send_string("Try again");
						_delay_ms(500);
						LCD_clear();
						LCD_send_string("Seconds=--");
						LCD_move_cursor(1,9);
					}
				} while (Second>=60);	
				
				LCD_clear();
				LCD_send_string("clock configured");
				_delay_ms(500);
				LCD_clear();
				LCD_send_string("Press 1 to Edit..");
			}
			else
			{
				LCD_clear();
				LCD_send_string("Wrong choice");
				_delay_ms(2000);
				LCD_clear();
				//LCD_send_string("Real Time Clock");
				//LCD_move_cursor(2,1);
				LCD_send_string("Press 1 to Edit..");
				//LCD_move_cursor(2,1);
			}
		}
		if(Second>59)
		{
			Second=0;
			Minutes++;
		}
		if(Minutes>59)
		{
			Minutes=0;
			Hours++;
		}
		if(Hours>23)
		{
			Hours=0;
		}			
			
		DIO_Set_Pin_Value(EN_1,LOW);		/*  Number of Second */
		DIO_Set_Pin_Value(EN_2,HIGH);
		DIO_Set_Pin_Value(EN_3,HIGH);
		DIO_Set_Pin_Value(EN_4,HIGH);
		DIO_Set_Pin_Value(EN_5,HIGH);
		DIO_Set_Pin_Value(EN_6,HIGH);
		Seven_Segment_write(Second%10);
		_delay_ms(2);
		
		DIO_Set_Pin_Value(EN_1,HIGH);  
		DIO_Set_Pin_Value(EN_2,LOW);
		DIO_Set_Pin_Value(EN_3,HIGH);
		DIO_Set_Pin_Value(EN_4,HIGH);
		DIO_Set_Pin_Value(EN_5,HIGH);
		DIO_Set_Pin_Value(EN_6,HIGH);
		Seven_Segment_write(Second/10);
		_delay_ms(2);
		DIO_Set_Pin_Value(EN_1,HIGH);  /*  Number of Minutes */
		DIO_Set_Pin_Value(EN_2,HIGH);
		DIO_Set_Pin_Value(EN_3,LOW);
		DIO_Set_Pin_Value(EN_4,HIGH);
		DIO_Set_Pin_Value(EN_5,HIGH);
		DIO_Set_Pin_Value(EN_6,HIGH);
		Seven_Segment_write(Minutes%10);
		_delay_ms(2);
				
		DIO_Set_Pin_Value(EN_1,HIGH); 
		DIO_Set_Pin_Value(EN_2,HIGH);
		DIO_Set_Pin_Value(EN_3,HIGH);
		DIO_Set_Pin_Value(EN_4,LOW);
		DIO_Set_Pin_Value(EN_5,HIGH);
		Seven_Segment_write(Minutes/10);
		_delay_ms(2);
		DIO_Set_Pin_Value(EN_1,HIGH);  /*  Number of Hours */
		DIO_Set_Pin_Value(EN_2,HIGH);
		DIO_Set_Pin_Value(EN_3,HIGH);
		DIO_Set_Pin_Value(EN_4,HIGH);
		DIO_Set_Pin_Value(EN_5,LOW);
		DIO_Set_Pin_Value(EN_6,HIGH);
		Seven_Segment_write(Hours%10);
		_delay_ms(2);
						
		DIO_Set_Pin_Value(EN_1,HIGH);
		DIO_Set_Pin_Value(EN_2,HIGH);
		DIO_Set_Pin_Value(EN_3,HIGH);
		DIO_Set_Pin_Value(EN_4,HIGH);
		DIO_Set_Pin_Value(EN_5,HIGH);
		DIO_Set_Pin_Value(EN_6,LOW);
		Seven_Segment_write(Hours/10);
		_delay_ms(2);
	}
	
}	


ISR(TIMER2_OVF_vect)	
{
	Second++;
}
