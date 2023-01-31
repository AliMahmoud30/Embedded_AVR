/*
 * Seven_Segement_Multiplexing.c
 *
 * Created: 6/30/2022 5:32:57 AM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"

#include "GPIO.h"
#include "Timers.h"
#include "H7_Segment.h"

#define _7_SEGMENT_1	D,0
#define _7_SEGMENT_2	D,1

volatile u8 Num_Counter;
volatile u8 ms_Counter;
volatile u8 Flag;


int main(void)
{
	/* initialization */
	DIO_Set_Pin_Direction(_7_SEGMENT_1,OUTPUT);
	DIO_Set_Pin_Direction(_7_SEGMENT_2,OUTPUT);
	Seven_Segment_Init();
	Timer0_CTC_Interrupt_Init(80);
	
    while(1)
    {
	
		if (Flag==0)
		{
			DIO_Set_Pin_Value(_7_SEGMENT_1,LOW);
			DIO_Set_Pin_Value(_7_SEGMENT_2,HIGH);
			Seven_Segment_write(Num_Counter/10);
		}
		else
		{
			DIO_Set_Pin_Value(_7_SEGMENT_1,HIGH);
			DIO_Set_Pin_Value(_7_SEGMENT_2,LOW);
			Seven_Segment_write(Num_Counter%10);
		}
		
			
		if (ms_Counter>=100)
		{
			Num_Counter++;
			ms_Counter=0;
		}
		
		if (Num_Counter>99)
		{
			Num_Counter=0;
		}
		
    }
}
ISR(TIMER0_COMP_vect)
{
	ms_Counter++;
	Flag^=1;
}