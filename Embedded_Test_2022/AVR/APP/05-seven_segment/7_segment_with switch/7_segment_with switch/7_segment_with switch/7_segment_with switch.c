/*
 * _7_segment_with_switch.c
 *
 * Created: 6/7/2022 12:54:28 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>


#include "H7_Segment.h"
#include "HButton.h"
int main(void)
{
	Seven_Segment_Init();
	Seven_Segment_write(0);
	Button_init(A,0);
	u8 sw_state=0;
	u8 counter=0;
	u8 flag=0;
    while(1)	
    {
		sw_state=Button_Read(A,0);
		if ((sw_state==1)&& (flag==0))
		{
			//_delay_ms(150);
			//if(Button_Read(A,0)==1)
			//{
				flag=1;
				counter++;
				Seven_Segment_write(counter);
				if (counter==9)
				{
					counter=0;
				}
						
			//}
			
		}
		else if((Button_Read(A,0)==0) && (flag==1))
		{
			flag=0;
		}								
       
    }
}