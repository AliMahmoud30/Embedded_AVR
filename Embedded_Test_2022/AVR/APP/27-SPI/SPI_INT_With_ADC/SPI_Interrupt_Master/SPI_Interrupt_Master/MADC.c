/*
 * MADC.c
 *
 * Created: 32/6/2022 
 *  Author: Ali Morsy
 */ 

#include "MADC.h"

void MADC_Init(void)
{
	/* Set ADC Reference Voltage >>(AREF)*/
		// Configuration V-ref
	/*
	REFS0 =0 , REFS0 =0 ------- AREF, Internal Vref turned off
	REFS0 =0 , REFS0 =1	-------AVCC with external capacitor at AREF pin
	REFS0 =1 , REFS0 =1 ------Internal 2.56V Voltage Reference with external capacitor at AREF pin
	*/
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	/* Set ADC Right Adjusted */
	CLR_BIT(ADMUX,ADLAR);
	/* Enable ADC  */
	SET_BIT(ADCSRA,ADEN);
	/* Set Prescaler 64 */
	CLR_BIT(ADMUX,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}
u16  MADC_Read(u8 Channel_Num)
{
	u16 ADC_Value;
	/* Set Channel to MUX*/
	ADMUX &= 0xE0;              // Clear BITs (MUX0 to MUX4) before Writing
	ADMUX |= (Channel_Num);    // Set Channel Number  appear (0x01)
	/*
	ADMUX|=GET_BIT(Channel_Num,0)<<0;
	ADMUX|=GET_BIT(Channel_Num,1)<<1;
	ADMUX|=GET_BIT(Channel_Num,2)<<2;
	*/
	/*Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* wait until Conversion is completed */
	while(GET_BIT(ADCSRA,ADIF)==0);
	/* Reset ADIF Flag*/
	SET_BIT(ADCSRA,ADIF);
	/*Read ADCL and ADC High Data Register */
	ADC_Value=ADCL;
	ADC_Value|=(ADCH<<8);	//Read Value from ADCH Register without Effect on First Value(From ADCL)
	/* Return ADC Value*/
	return ADC_Value;	
}