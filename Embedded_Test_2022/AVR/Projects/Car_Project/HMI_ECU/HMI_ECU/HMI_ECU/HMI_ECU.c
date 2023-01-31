/*
 * HMI_ECU.c
 *
 * Created: 9/10/2022 11:32:04 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU	8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>


#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "UART.h"
#include "MI2C.h"
#include "Timers.h"


#include "LCD.h"
#include "Hkeypad.h"


#define Slave_ADDRESS_WRITE		0X30
#define Slave_ADDRESS_READ		0X31

/* Prototypes */
void Receiving_voidTemptoLCD();


/* Global Variables */
volatile u8 Global_u8Temp;
volatile u16 Timer_Counter = 0;
volatile u8 Second = 0;

int main(void)
{
	/* DIO  Initialization */
	DIO_Set_Pin_Direction(D,7,OUTPUT);
	
	/* LCD  Initialization */
	LCD_inti();
	LCD_send_cmd(display_on_cursor_off);
	
	/* Keypad_4*4  Initialization */
	Keypad_4_4_Init();
	
	/* UART  Initialization */
	UART_init(9600,1,NONE);  
	
	/* I2C  Initialization */
	MI2C_u8voidInit();	
	
	/* Variables  */
	u8 Keypad_Val , KeyPad_Flag = 0;
	u8 Receive_Flag=0;
	u8 LCD_Second;
	u8 I2C_Data=0, I2C_Data_Bit=0;
	
	/* Main Window On LCD */
	LCD_send_string("1-MOTOR CONTROL");
	LCD_move_cursor(2,1);
	LCD_send_string("2-LIGHT CONTROL");
	
	  
    while(1)
    {
		/* ------------------------Get Keypad Val --------------------------*/
		Keypad_Val = Keypad_4_4_Read();
		 if( (Keypad_Val !=0xFF) && (KeyPad_Flag == 0) )
		 {
			//LCD_send_char(Keypad_Val);
			//_delay_ms(20);
			  KeyPad_Flag = 1;			 
		 }
		 else if( (Keypad_Val == 0xFF) && (KeyPad_Flag == 1) )
		 {
			 KeyPad_Flag =0;
		 }
		 
		/* ------------------------Mode Checking ---------------------------*/	 		 
		 if (Keypad_Val == '1' )
		 {
			/* -------------- Motor Control--------------------------------- */
			 /* Motor Cooling Control */
/*
// 			 LCD_clear();
// 			 LCD_send_string("MOTOR COOLING");
// 			 LCD_move_cursor(2,1);
// 			 LCD_send_string("CONTROL ");
// 			 _delay_ms(1000);
*/
			  
			 LCD_clear();
			 LCD_send_string("Temp= ");
			/*  Send Message to Motor Control ECU to Give me The Temp. Value  */
			do
			{
				Keypad_Val = Keypad_4_4_Read();
				/* Motor Cooling Control */
				Receiving_voidTemptoLCD();
				if (Global_u8Temp > 70)
				{			
					UART_Send_String("[FN]");   /* Send to Turn ON FAN*/
					LCD_move_cursor(2,1);
					LCD_send_string("Wait ");
					Second=0;
					Timer_Counter = 0;
					do
					{
						/* wait 20s*/
						Timer0_CTC_Interrupt_Init(80);   /* Interrupt Occurres every 10ms */
						/* Motor Cooling Control */
						Receiving_voidTemptoLCD();
						//LCD_Second = 10 - Second;
						LCD_move_cursor(2,7);
						LCD_send_char( ( (20-Second) /10)+48 );
						LCD_send_char( ( (20-Second) %10)+48 );
						LCD_send_char('s');
						/* check Time if greater than 20s (20000 ms)*/
						if (Second >= 20)
						{
							LCD_clear();
							LCD_send_string(" System Failure ");
							LCD_move_cursor(2,1);
							LCD_send_string("Wait ");							
							
							/* Reset All*/
							UART_Send_String("[MF]");   /* Send to Turn OFF Motor */
							UART_Send_String("[FF]");   /* Send to Turn OFF Fan   */
							
							/* send Turn OFF The Light  */
							MI2C_voidStart();
							MI2C_u8WriteAddress(Slave_ADDRESS_WRITE);
							MI2C_u8WriteData(0x00);
							MI2C_voidStop();
							
							/* Reset Seconds & Timer_Counter*/
							Second = 0;
							Timer_Counter = 0;
							LCD_move_cursor(2,1);
							//LCD_send_string("wait ");
							do
							{
								/* wait 30s*/
								LCD_move_cursor(2,7);
								LCD_send_char( ( (30-Second) /10)+48 );
								LCD_send_char( ( (30-Second) %10)+48 );
								LCD_send_char('s');
							}while (Second <= 30);
							
							Keypad_Val = '0';
							break;  /* break from do..while(Global_u8Temp>=70)  */
							
						}
												
					}while(Global_u8Temp>=70);
					LCD_move_cursor(2,1);
					LCD_send_string("          ");
					UART_Send_String("[FF]");   /* FAN OFF*/
					DIO_Set_Pin_Value(D,7,LOW);
					//break;
					
					/* Stop Timer */
					CLR_BIT(TCCR0,CS00);
					CLR_BIT(TCCR0,CS01);
					CLR_BIT(TCCR0,CS02);
					/*  Timer0 CTC Interrupt Disable*/
					CLR_BIT(TIMSK,OCIE0);
					cli();
				}
				else
				{
					
				}
									
				
			} while (Keypad_Val != '0');
			
				/*Display main window */
				LCD_clear();
				LCD_send_string("1-MOTOR CONTROL");
				LCD_move_cursor(2,1);
				LCD_send_string("2-LIGHT CONTROL");
				UART_Send_String("[MN]");   /* Motor ON*/
		}
		else if(Keypad_Val == '2')
		{
			/* ----------------------- Lighting Control ---------------------------*/
			/* Lighting Control */
/*
// 			LCD_clear();
// 			LCD_send_string("LIGHT CONTROL");
// 			UART_Send_Data('L');
// 			_delay_ms(1000);
*/			

			LCD_clear();
			LCD_send_string("L1:OFF    L2:OFF");
			LCD_move_cursor(2,1);
			LCD_send_string("L3:OFF    L4:OFF");
			_delay_ms(100);
			do 
			{
				Keypad_Val = Keypad_4_4_Read();
				if (Keypad_Val != 0xFF)
				{
					_delay_ms(200);
					I2C_Data_Bit = Keypad_Val - 48;
					if( (I2C_Data_Bit >0) && (I2C_Data_Bit <5) )
					{
						TOG_BIT(I2C_Data,I2C_Data_Bit-1);
						if (GET_BIT(I2C_Data,0) == 1)
						{
							LCD_move_cursor(1,4);
							LCD_send_string("ON ");
						}
						else
						{
							LCD_move_cursor(1,4);
							LCD_send_string("OFF");
						}
						if (GET_BIT(I2C_Data,1) == 1)
						{
							LCD_move_cursor(1,14);
							LCD_send_string("ON ");
						}
						else
						{
							LCD_move_cursor(1,14);
							LCD_send_string("OFF");
						}
						if (GET_BIT(I2C_Data,2) == 1)
						{
							LCD_move_cursor(2,4);
							LCD_send_string("ON ");
						}
						else
						{
							LCD_move_cursor(2,4);
							LCD_send_string("OFF");
						}
						if (GET_BIT(I2C_Data,3) == 1)
						{
							LCD_move_cursor(2,14);
							LCD_send_string("ON ");
						}
						else
						{
							LCD_move_cursor(2,14);
							LCD_send_string("OFF");
						}
						/* send Data to Lighting  */
						MI2C_voidStart();
						MI2C_u8WriteAddress(Slave_ADDRESS_WRITE);
						MI2C_u8WriteData(I2C_Data);
						MI2C_voidStop();
						I2C_Data_Bit = 0;
					}
				}	
				//LCD_send_char(I2C_Data+48);
			} while (Keypad_Val != '0');
			LCD_clear();
			LCD_send_string("1-MOTOR CONTROL");
			LCD_move_cursor(2,1);
			LCD_send_string("2-LIGHT CONTROL");
			
		}
						
	}
		

}
			

void Receiving_voidTemptoLCD()
{
	u8 Local_u8Temp[3];
	LCD_move_cursor(1,8);
	UART_Send_String("[T_]");
	
	for (u8 i=0; i<3; i++)
	{
		Local_u8Temp[i] = UART_Receive_Data();
		LCD_send_char(Local_u8Temp[i]);
	}
	LCD_send_char(0xDF);    // Celsius symbol
	LCD_send_char('C');
	//DIO_Toggle_Pin(D,7);
	Global_u8Temp = (Local_u8Temp[0]-48)*100;
	Global_u8Temp+= (Local_u8Temp[1]-48)*10;
	Global_u8Temp+= (Local_u8Temp[2]-48);
	
}

ISR (TIMER0_COMP_vect)
{
	
	Timer_Counter++;
	if (Timer_Counter >= 100)
	{
		DIO_Toggle_Pin(D,7);
		Timer_Counter=0;
		Second++;
	}

}