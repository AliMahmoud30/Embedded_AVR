/*
 * Motor_Control_ECU.c
 *
 * Created: 9/10/2022 11:54:21 AM
 *  Author: Morsy
 */ 



#include <avr/io.h>
#define F_CPU	8000000ul
#include <util/delay.h>
#include "avr/interrupt.h"


#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "MADC.h"
#include "UART.h"

#define  FAN_PIN	B,0
#define  MOTOR_PIN	B,1

volatile u8 MODE = '\0';
volatile u8 Fram_Array[5];
volatile u8 Global_u8Counter;
volatile u8 Global_u8ISRData;
volatile u8 Global_u8FanData;
volatile u8 Global_u8MotorData;
volatile u8 Global_u8TurnOffAll;


int main(void)
{	
	/* Initialization */
	UART_init(9600,1,NONE);  /*  UART Init    */
	MADC_Init();			 /*  ADC  Init    */
	
	/* Enable UART INT */
	//SET_BIT(UCSRB,RXCIE);
	//sei();
	
	/* Variables  */
	u16 ADC_Value;
	u8 temp_val;
	u8 Temp_Arr[3];
	u8 Temp_String[4];
    u8 Global_u8ReceiveBuffer[5];
	DIO_Set_Pin_Direction(FAN_PIN,  OUTPUT);
	DIO_Set_Pin_Direction(MOTOR_PIN,OUTPUT);
	DIO_Set_Pin_Value(MOTOR_PIN,HIGH);
	DIO_Set_Pin_Value(FAN_PIN,LOW);
	//_delay_ms(200);

    while(1)
    {	
			for (u8 i=0; i<4; i++)
			{
				Global_u8ReceiveBuffer[i] = UART_Receive_Data();
			}
						
			if (Global_u8ReceiveBuffer[0] == '[')
			{
				if ( (Global_u8ReceiveBuffer[0] == '[') && (Global_u8ReceiveBuffer[1] == 'T') && (Global_u8ReceiveBuffer[2] == '_') && (Global_u8ReceiveBuffer[3] == ']') )
				{
					//_delay_ms(1000);
					ADC_Value = MADC_Read(0);
					temp_val=ADC_Value*((5.0/1024)*1000)/10.0;
					Temp_Arr[0] = (temp_val/100);
					Temp_Arr[1] = ((temp_val/10)%10);
					Temp_Arr[2] = (temp_val%10);
					for (u8 i=0; i<3; i++)
					{	
						/* Convert int to string */
						sprintf(Temp_String, "%d", Temp_Arr[i]);
						UART_Send_String(Temp_String);
						//UART_Send_Data(Temp_Arr[i]);
						//_delay_ms(200);
					}
					
				}
				else if( (Global_u8ReceiveBuffer[0] == '[') && (Global_u8ReceiveBuffer[1] == 'F') && (Global_u8ReceiveBuffer[2] == 'N') && (Global_u8ReceiveBuffer[3] == ']') )
				{
					/* Fan ON */
					DIO_Set_Pin_Value(FAN_PIN,HIGH);
				}
				else if ((Global_u8ReceiveBuffer[0] == '[') && (Global_u8ReceiveBuffer[1] == 'F') && (Global_u8ReceiveBuffer[2] == 'F') && (Global_u8ReceiveBuffer[3] == ']'))
				{
					/* Fan OFF */
					DIO_Set_Pin_Value(FAN_PIN,LOW);
				}
				else if( (Global_u8ReceiveBuffer[0] == '[') && (Global_u8ReceiveBuffer[1] == 'M') && (Global_u8ReceiveBuffer[2] == 'N') && (Global_u8ReceiveBuffer[3] == ']') )
				{
					/* Motor ON */
					DIO_Set_Pin_Value(MOTOR_PIN,HIGH);
				}
				else if ((Global_u8ReceiveBuffer[0] == '[') && (Global_u8ReceiveBuffer[1] == 'M') && (Global_u8ReceiveBuffer[2] == 'F') && (Global_u8ReceiveBuffer[3] == ']'))
				{
					/* Motor OFF */
					DIO_Set_Pin_Value(MOTOR_PIN,LOW);
				}
			}
			
			}
		
		}
		
	


/*
ISR (USART_RXC_vect)
{
	
	
	
	while(1)
	{
		
		for (u8 i=0; i<3; i++)
		{
			Global_u8ReceiveBuffer[i] = UART_Receive_Data();
		}
		if ( (Global_u8ReceiveBuffer[0] == 'T') (Global_u8ReceiveBuffer[1] == 'E') && (Global_u8ReceiveBuffer[2] == 'M') && (Global_u8ReceiveBuffer[3] == 'P') )
		{
			break;
		}
	}
	
	
	Global_u8ISRData = UART_Receive_Data();
	if ( (Global_u8ISRData == 'T') || (Global_u8ISRData == 'L') )
	{
		MODE = Global_u8ISRData;
	}
	else if ( (Global_u8ISRData == 0x20) || (Global_u8ISRData == 0x21) )
	{
		Global_u8FanData = Global_u8ISRData;
	}
	else if ( (Global_u8ISRData == 0x30) || (Global_u8ISRData == 0x31) )
	{
		Global_u8MotorData = Global_u8ISRData;
	}
	else if(Global_u8ISRData == 0x60)
	{
		Global_u8TurnOffAll = Global_u8ISRData;
		
	}
	/*
	Fram_Array[Global_u8Counter] = UART_Receive_Data();
	Global_u8Counter++;
	if (Global_u8Counter >4)
	{
		Global_u8Counter=0;
	}
	*/
//}
//*/