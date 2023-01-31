/*
 * Timers.h
 *
 * Created: 6/28/2022 5:21:53 AM
 *  Author: Morsy
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "STD_TYPES.h"
#include "std_macros.h"
#include "GPIO.h"

#include "Timers_config.h"

/* Status Register */
#define SREG	*((volatile unsigned char*)(0x5F))
#define I_BIT	7

/*Output Compare Register-OCR0 */
#define OCR0	*((volatile unsigned char*)(0x5C))

/*Output Compare Register-OCR2 */
#define OCR2	*((volatile unsigned char*)(0x43))

/*Timer/Counter Register-TCNT0 */
#define TCNT0	*((volatile unsigned char*)(0x52))

/*Timer/Counter Register-TCNT2 */
#define TCNT2	*((volatile unsigned char*)(0x44))

/*Timer/Counter Control Register-TCCR0*/
#define TCCR0	*((volatile unsigned char*)(0x53))
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

/*Timer/Counter Control Register-TCCR2*/
#define TCCR2	*((volatile unsigned char*)(0x45))
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7

/*Timer/Counter Interrupt Mask Register-TIMSK*/
#define TIMSK	*((volatile unsigned char*)(0x59))
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

/*Timer/Counter Interrupt Flag Register–TIFR*/
#define TIFR	*((volatile unsigned char*)(0x58))
#define TOV0	0
#define OCF0	1
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7


/* Asynchronous Status Register–ASSR */
#define ASSR	*((volatile unsigned char*)(0X42))
#define	TCR2UB	0
#define OCR2UB	1
#define TCN2UB	2
#define	AS2		3

#define TOGGLE	1
#define CLEAR	2
#define SET		3

/*Timer0 Prototypes */
void Timer0_Overflow_Interrupt_Init(void);
void Timer0_CTC_Interrupt_Init(u8 OCR0_Value);
void Timer0_Wave_Non_PWM(u8 OCR0_Value,u8 OC0_Pin_Mode);
void Timer0_PWM_init(void);
void Timer0_PWM_Change(u8 PWM_Value);
void Timer0_Phase_Correct_PWM(u8 OCR0_Value);


/* Timer2 Prototypes */
void Timer2_Overflow_Interrupt_Init(void);



#endif /* TIMERS_H_ */