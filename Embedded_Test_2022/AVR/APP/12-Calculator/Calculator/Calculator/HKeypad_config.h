/*
 * HKeypad_config.h
 *
 * Created: 6/17/2022 3:48:00 PM
 *  Author: Ali Morsy
 */ 


#ifndef HKEYPAD_CONFIG_H_
#define HKEYPAD_CONFIG_H_

/* Keypad 4*4 Pins PAIR   PORT,PIN  */
#define ROW_0	C,0
#define ROW_1	C,1
#define ROW_2	C,2
#define ROW_3	C,3
#define Col_0	C,4
#define Col_1	C,5
#define Col_2	C,6
#define Col_3	C,7

/* Keypad 2D Array  */
unsigned char keypad_chr[4][4]={{'7','8','9','/'},
								{'4','5','6','*'},					
							    {'1','2','3','-'},
								{'C','0','=','+'}};
			


#endif /* HKEYPAD_CONFIG_H_ */