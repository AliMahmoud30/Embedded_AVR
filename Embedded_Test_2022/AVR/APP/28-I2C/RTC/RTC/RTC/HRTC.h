/*
 * HRTC.h
 *
 * Created: 8/12/2022 8:11:22 PM
 *  Author: Morsy
 */ 


#ifndef HRTC_H_
#define HRTC_H_

#include "STD_TYPES.h"
#include "std_macros.h"


#include "MI2C.h"
#include "HRTC_config.h"


void HRTC_voidReadClock(u8* copy_u8Seconds, u8* copy_u8Minutes, u8* copy_u8Hours);


#endif /* HRTC_H_ */