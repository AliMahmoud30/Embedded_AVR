/*
 * LCD.h
 *
 * Created: 7/6/2020 4:02:47 PM
 *  Author: PC
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "GPIO.h"
#include "LCD_config.h"


#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define display_on_cursor_on 0x0e
#define display_off_cursor_off 0x08
#define display_on_cursor_off 0x0C
#define ENTRY_MODE  0x0
#define shift_cursor_to_left 0x04
#define shift_cursor_to_right 0x06
#define shift_display_to_left 0x18
#define shift_display_to_right 0x1c


#if defined LCD_eghit_bit

#define EGHIT_BITS 0x38   // Function_set

#elif defined LCD_four_bit

#define FOUR_BITS 0x28    // Function_set

/*  old 
#define EN 0
#define RS 1
#define RW 2  */



#endif

// FUNCTIONS 
void LCD_inti(void);
void LCD_send_char(char data);
void LCD_send_string(char *data);
static void LCD_Enable (void);
void LCD_send_cmd(char cmd);
void LCD_clear(void);
void LCD_move_cursor(char row, char coloumn);
void lcd_print(char *str);
#endif /* LCD_H_ */