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

#include "GPIO.h"
#include "Timers.h"
#include "H7_Segment.h"

#define _7_SEGMENT_1	D,0
#define _7_SEGMENT_2	D,1
int main(void)
{
	/* initialization */
	DIO_Set_Pin_Direction(_7_SEGMENT_1,OUTPUT);
	DIO_Set_Pin_Direction(_7_SEGMENT_2,OUTPUT);
	
	Seven_Segment_Init();
	//Seven_Segment_write(5);
	
    while(1)
    {
		DIO_Set_Pin_Value(_7_SEGMENT_1,LOW);
		DIO_Set_Pin_Value(_7_SEGMENT_2,HIGH);
		Seven_Segment_write(5);
		_delay_ms(10);
		DIO_Set_Pin_Value(_7_SEGMENT_1,HIGH);
		DIO_Set_Pin_Value(_7_SEGMENT_2,LOW);
		Seven_Segment_write(0);
		_delay_ms(10);
		
      
    }
}