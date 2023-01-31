/*
 * BCD_to_seven_segment.c
 *
 * Created: 6/7/2022 2:09:30 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU	8000000ul
#include "util/delay.h"

#include "H7_Segment.h"

int main(void)
{
	Seven_Segment_Init();
	u8 i;
    while(1)
    {
		for (i=0;i<=9;i++)
		{
			Seven_Segment_write_BCD(i);
			_delay_ms(1000);
		}		
    }
}