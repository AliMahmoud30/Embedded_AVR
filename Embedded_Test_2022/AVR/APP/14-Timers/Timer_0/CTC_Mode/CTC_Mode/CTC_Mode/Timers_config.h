/*
 * Timers_config.h
 *
 * Created: 6/28/2022 4:52:17 PM
 *  Author: Ali Morsy
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

 /* MCU Clock Division*/
 #define DIV_1				1
 #define DIV_8				2
 #define DIV_64				3
 #define DIV_256			4
 #define DIV_1024			5
 #define EXT_FALLING_EDGE	6
 #define EXT_RISING_EDGE	7


/*--------------------------------- Timer0 Configuration------------------------------------------*/

/* 
	Select prescaler for Timer0 (MCU Clock Division):
	DIV_1
	DIV_8
	DIV_64  
	DIV_256
	DIV_1024  (Default Prescaler)
	EXT_FALLING_EDGE
	EXT_RISING_EDGE
 */

#define TIMER0_CLOCK_SELECT		EXT_RISING_EDGE

/* --------------------------------------------*/



/* Timer1 Configuration*/

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

#define TIMER1_CLOCK_SELECT		DIV_1024

/* --------------------------------------------*/


/* Timer2 Configuration*/

/* 
	Select prescaler for Timer2 (MCU Clock Division):
	DIV_1
	DIV_8
	DIV_64 
	DIV_256
	DIV_1024	(Default Prescaler)
	EXT_FALLING_EDGE
	EXT_RISING_EDGE
 */

#define TIMER2_CLOCK_SELECT		DIV_1024



#endif /* TIMERS_CONFIG_H_ */