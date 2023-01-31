/*
 * HLED.h
 *
 * Created: 5/21/2022 12:26:21 AM
 *  Author: Morsy
 */ 


#include "STD_TYPES.h"
#include "GPIO.h"
#include "std_macros.h"

#ifndef HLED_H_
#define HLED_H_

void LED_init(u8 PORT, u8 PIN);

void LED_ON(u8 PORT, u8 PIN);

void LED_OFF(u8 PORT, u8 PIN);

void LED_Toggle(u8 PORT, u8 PIN);

u8 LED_Read_Status(u8 PORT, u8 PIN);

#endif //HLED_H_