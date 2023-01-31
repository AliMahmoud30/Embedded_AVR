/*
 * Timers_config.h
 *
 * Created: 6/28/2022 4:52:17 PM
 *  Author: Ali Morsy
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

/* MCU Clock Division for Timer0*/
#define TIMER0_DIV_1				1
#define TIMER0_DIV_8				2
#define TIMER0_DIV_64				3
#define TIMER0_DIV_256				4
#define TIMER0_DIV_1024				5
#define TIMER0_EXT_FALLING_EDGE		6
#define TIMER0_EXT_RISING_EDGE		7


/* MCU Clock Division for Timer2*/
#define TIMER2_DIV_1				1
#define TIMER2_DIV_8				2
#define TIMER2_DIV_32				3
#define TIMER2_DIV_64				4
#define TIMER2_DIV_128				5
#define TIMER2_DIV_256				6
#define TIMER2_DIV_1024				7

/*--------------------------------- Timer0 Configuration------------------------------------------*/

/* 
	Select prescaler for Timer0 (MCU Clock Division):
	TIMER0_DIV_1
	TIMER0_DIV_8
	TIMER0_DIV_64  
	TIMER0_DIV_256
	TIMER0_DIV_1024  (Default Prescaler)
	TIMER0_EXT_FALLING_EDGE
	TIMER0_EXT_RISING_EDGE
	
	
	----------------------------------------------
	OC0_Pin Mode 
	
		
 */

#define TIMER0_CLOCK_SELECT		TIMER0_DIV_1024

/* --------------------------------------------*/



/*--------------------------------- Time1 Configuration------------------------------------------*/


/* 
	Select prescaler for Timer1 (MCU Clock Division):
	DIV_1
	DIV_8
	DIV_64  
	DIV_256
	DIV_1024	(Default Prescaler)
	EXT_FALLING_EDGE
	EXT_RISING_EDGE
 */

#define TIMER1_CLOCK_SELECT		0

/* --------------------------------------------*/




/*--------------------------------- Timer2 Configuration------------------------------------------*/


/* 
	Select prescaler for Timer2 (MCU Clock Division):
	TIMER2_DIV_1
	TIMER2_DIV_8
	TIMER2_DIV_32
	TIMER2_DIV_64
	TIMER2_DIV_128
	TIMER2_DIV_256				
	TIMER2_DIV_1024				
 */

#define TIMER2_CLOCK_SELECT		TIMER2_DIV_128



#endif /* TIMERS_CONFIG_H_ */