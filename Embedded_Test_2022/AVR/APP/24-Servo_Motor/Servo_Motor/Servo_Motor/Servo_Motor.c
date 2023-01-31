/*
 * Servo_Motor.c
 *
 * Created: 7/5/2022 11:36:04 PM
 *  Author: Ali Morsy
 */ 


#include <avr/io.h>
#define F_CPU	1000000ul
#include <util/delay.h>

#include "STD_TYPES.h"
#include "std_macros.h"

#define T1_TCCR1A		*((volatile u8* )(0x4F))
#define T1_TCCR1B		*((volatile u8* )(0x4E))
#define T1_TCNT			*((volatile u16*)(0x4C))
#define T1_OCR1A		*((volatile u16*)(0x4A))
#define T1_OCR1B		*((volatile u16*)(0x48))
#define T1_ICR1			*((volatile u16*)(0x46))

void Servo_Write(double Value);
int main(void)
{
	/*Set PD5(OC1A) as OUTPUT */
	SET_BIT(DDRD,5);
	/*set Fast PWM mode in timer_1 */
	SET_BIT(T1_TCCR1A,1); //WGM11
	SET_BIT(T1_TCCR1B,3); //WGM12
	SET_BIT(T1_TCCR1B,4); //WGM13
	/*Load  T_HIGH Value */
	T1_OCR1A=2000;
	/*Load T_Period Value */
	T1_ICR1=19999;
	/* Clear OC1A on Compare Match,set OC1A at BOTTOM
	   COM1A0=0,COM1A1=1*/
	SET_BIT(T1_TCCR1A,COM1A1); //COM1A1
	/*Start Timer with no Prescaler */
	SET_BIT(T1_TCCR1B,CS10);
	Servo_Write(12.5);
	
    while(1)
    {
		/*
      Servo_Write(20);
      _delay_ms(1000);
	  Servo_Write(50);
	  _delay_ms(1000);
	  Servo_Write(180);
	  _delay_ms(1000);
	  */
		 
    }
}

void Servo_Write(double Value)
{
	/*Set PD5(OC1A) as OUTPUT */
	SET_BIT(DDRD,5);
	/*set Fast PWM mode in timer_1 */
	SET_BIT(T1_TCCR1A,1); //WGM11
	SET_BIT(T1_TCCR1B,3); //WGM12
	SET_BIT(T1_TCCR1B,4); //WGM13
	/*Load  T_HIGH Value */
	/* convert 0:180 >> 1:2 ms*/
	//T1_OCR1A=1000*1.069444444;
	T1_OCR1A=1000*((1/180.0*Value)+1);
	//T1_OCR1A=((1.0/F_CPU)*1000000)*((1/180.0*Value)+1); //F_CPU= 1Mhz, tick time = 1us
	/*Load T_Period Value */
	T1_ICR1=19999;
	/* Clear OC1A on Compare Match,set OC1A at BOTTOM
	   COM1A0=0,COM1A1=1*/
	SET_BIT(T1_TCCR1A,COM1A1); //COM1A1
	/*Start Timer with no Prescaler */
	SET_BIT(T1_TCCR1B,CS10);
	
}