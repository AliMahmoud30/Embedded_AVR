/*
 * HButton.h
 *
 * Created: 5/22/2022 10:03:30 AM
 *  Author: Morsy
 */ 

#include "GPIO.h"
#include "STD_TYPES.h"

#ifndef HBUTTON_H_
#define HBUTTON_H_

void Button_init(u8 PORT,u8 PIN);

u8 Button_Read(u8 PORT,u8 PIN);

void Button_init_Pull_UP(u8 PORT,u8 PIN);


#endif /* HBUTTON_H_ */