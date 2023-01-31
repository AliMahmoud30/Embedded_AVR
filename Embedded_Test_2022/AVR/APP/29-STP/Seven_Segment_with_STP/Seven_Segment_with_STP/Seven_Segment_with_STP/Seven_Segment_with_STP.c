/*
 * GccApplication1.c
 *
 * Created: 8/21/2022 4:39:56 PM
 *  Author: Morsy
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h"
#include "STP_interface.h"

u8 Seg_num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

u32 Counter=989980;
u8	 DIGIT_NUM_1=0;
u8	 DIGIT_NUM_2=0;
u8	 DIGIT_NUM_3=0;
u8	 DIGIT_NUM_4=0;
u8	 DIGIT_NUM_5=0;
u8	 DIGIT_NUM_6=0;

int main(void)
{
	/*DIO Initialization */
	DIO_Set_Pin_Direction(C,0,OUTPUT);
	DIO_Set_Pin_Direction(C,1,OUTPUT);
	DIO_Set_Pin_Direction(C,2,OUTPUT);
	

    while(1)
    {
		if (Counter<100)
		{
			DIGIT_NUM_1=Counter/10;
			DIGIT_NUM_2=Counter%10;
			DIGIT_NUM_3=0;
			DIGIT_NUM_4=0;
			DIGIT_NUM_5=0;
			DIGIT_NUM_6=0;
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_2]);		 /*Seven_Seg_6 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_1]);		 /*Seven_Seg_5 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_6]);
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_5]);
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_4]);
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_3]);

		}
		else if (Counter<1000)
		{
			DIGIT_NUM_1=Counter/100;
			DIGIT_NUM_2=(Counter/10)%10;
			DIGIT_NUM_3=Counter%10;
			DIGIT_NUM_4=0;
			DIGIT_NUM_5=0;
			DIGIT_NUM_6=0;
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_3]);		 /*Seven_Seg_6 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_2]);		 /*Seven_Seg_5 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_1]);		 /*Seven_Seg_4 */
			
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_4]);		 /*Seven_Seg_3 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_5]);		 /*Seven_Seg_2 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_6]);		 /*Seven_Seg_1 */
			
		}
		else if (Counter<10000)
		{
			DIGIT_NUM_1=Counter/1000;
			DIGIT_NUM_2=(Counter/100)%10;
			DIGIT_NUM_3=((Counter/10)%10);
			DIGIT_NUM_4=Counter%10;
			DIGIT_NUM_5=0;
			DIGIT_NUM_6=0;
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_4]);		 /*Seven_Seg_6 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_3]);		 /*Seven_Seg_5 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_2]);		 /*Seven_Seg_4 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_1]);		 /*Seven_Seg_3 */
			
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_5]);		 /*Seven_Seg_2 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_6]);		 /*Seven_Seg_1 */
		}
		else if (Counter<100000)
		{
			DIGIT_NUM_1=Counter/10000;
			DIGIT_NUM_2=((Counter/1000)%10);
			DIGIT_NUM_3=((Counter/100)%10 );
			DIGIT_NUM_4=((Counter/10)%10  );
			DIGIT_NUM_5=Counter%10;
			DIGIT_NUM_6=0;
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_5]);		 /*Seven_Seg_6 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_4]);		 /*Seven_Seg_5 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_3]);		 /*Seven_Seg_4 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_2]);		 /*Seven_Seg_3 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_1]);		 /*Seven_Seg_2 */
			
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_6]);		 /*Seven_Seg_1 */
		}
		else if (Counter<1000000)
		{
			DIGIT_NUM_1=(Counter/100000);
			DIGIT_NUM_2=((Counter/10000)%10);
			DIGIT_NUM_3=((Counter/1000)%10);
			DIGIT_NUM_4=((Counter/100)%10);
			DIGIT_NUM_5=((Counter/10)%10);
			DIGIT_NUM_6=Counter%10;
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_6]);		 /*Seven_Seg_6 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_5]);		 /*Seven_Seg_5 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_4]);		 /*Seven_Seg_4 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_3]);		 /*Seven_Seg_3 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_2]);		 /*Seven_Seg_2 */
			HSTP_voidSendSynchronuse(Seg_num[DIGIT_NUM_1]);		 /*Seven_Seg_1 */
		}
		
		
		
		Counter++;
		_delay_ms(500);
		/*
		for(u8 i =0; i<8;i++)
		{
			HSTP_voidSendSynchronuse(Seg_num[i]);
			_delay_ms(500);
		}
		*/
	}	
}


