/*
 * Seven_Segment.c
 *
 * Created: 5/22/2022 10:28:54 AM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "GPIO.h"
#include "H7_Segment.h"


int main(void)
{
	u8 i=0;
	Seven_Segment_Init();
	
    while(1)
    {
       
	   for (i=0;i<=9;i++)
	   {
		   Seven_Segment_write(i);
		   _delay_ms(500);
	   }
    }
}