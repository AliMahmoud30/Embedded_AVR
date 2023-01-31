/*
 * LCD_config.h
 *
 * Created: 7/6/2020 4:04:06 PM
 *  Author: PC
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD_Mode   Four bit or Eight Bit  */
//#define LCD_eghit_bit
#define LCD_four_bit

/*
Note:
	 if your work on eight bit mode we will use all pins below,
	 but if you work on four bit mode we will use last four pins 
	 and the first four pins don't care.

*/


/*LCD Pins  PAIR   PORT,PIN */

#define LCD_D0		C,0		 /* first pin in eight bit mode   */
#define LCD_D1		C,1
#define LCD_D2		C,2
#define LCD_D3		C,3
#define LCD_D4		D,0      /* first pin in four bit mode   */
#define LCD_D5		D,1
#define LCD_D6		D,2
#define LCD_D7		D,3

#define LCD_RS		D,4
#define LCD_EN		D,5
#define LCD_RW		D,6   /* it's option */


#endif /* LCD_CONFIG_H_ */