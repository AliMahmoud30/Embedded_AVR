/*
 * MADC.h
 *
 * Created: 32/6/2022 
 *  Author: Ali Morsy
 */ 

#ifndef MADC_H_
#define MADC_H_

#include "STD_TYPES.h"
#include "std_macros.h"

/* Address of ADC Registers */

/* ADC Multiplexer Selection Register ADMUX */
#define ADMUX		*((volatile u8*)(0x27))
#define MUX0	0		
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

/* ADC Control and Status Register ADCSRA */
#define ADCSRA		*((volatile u8*)(0x26))	
#define ADPS0	0		
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7


/*The ADC Data Register – ADCL and ADCH*/
#define ADCH		*((volatile u8*)(0x25))
#define ADCL		*((volatile u8*)(0x24))


/*Special Function I/O Register */
#define SFIOR		*((volatile u8*)(0x50))
#define ADTS0	5
#define ADTS1	6
#define ADTS2	7



/* This Function Initial ADC Module */
void MADC_Init(void);
/* This Function Get ADC Value From 0-1023 */
u16  MADC_Read(u8 Channel_Num);


#endif /* MADC_H_ */