/*
 * SPI_Interrupt_Master.c
 *
 * Created: 7/11/2022 9:50:18 PM
 *  Author: Morsy
 */ 


//#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#include "HSPI.h"
#include "GPIO.h"
#include "MADC.h"

#define SREG	*(volatile unsigned char*)(0x5F)
#define I_BIT	7

volatile u16 ADC_value;
volatile u8 SPI_Value;
int main(void)
{

	SPI_MasterInit();
	MADC_Init();
	
	//DIO_Set_Pin_Direction(A,0,OUTPUT);
	DIO_Set_Pin_Direction(B,4,OUTPUT);  /* SS Pins*/
		
	DIO_Set_Pin_Value(B,4,LOW);
	//DIO_Set_Pin_Value(A,0,LOW);
	
	//Set I-Bit
	SET_BIT(SREG,I_BIT);
	//Enable ADC Interrupt
	SET_BIT(ADCSRA,ADIE);
	/* Set Channel to MUX*/
	ADMUX &= 0xE0;              // Clear BITs (MUX0 to MUX4) before Writing
	ADMUX |= (0x00);
	/*Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	_delay_ms(1000);
		
	
    while(1)
    {

    }
}

ISR(ADC_vect)
{
	ADC_value=ADCL;
	ADC_value|=ADCH<<8;
	SPI_Value=(ADC_value*(5.0/1023))*100;

	SPI_MasterTransmit(SPI_Value);
	_delay_ms(100);
	
	/*Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	
}

