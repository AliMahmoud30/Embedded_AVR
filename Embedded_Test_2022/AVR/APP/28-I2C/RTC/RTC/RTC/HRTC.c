/*
 * HRTC.c
 *
 * Created: 8/12/2022 8:11:05 PM
 *  Author: Morsy
 */ 


#include "HRTC.h"

void HRTC_voidReadClock(u8* copy_u8Seconds, u8* copy_u8Minutes, u8* copy_u8Hours)
{
	
	MI2C_voidStart();
	MI2C_u8WriteAddress(RTC_ADDRESS_WRITE);
	MI2C_u8WriteData(RTC_ADDRESS_OF_SECONDS);  //Addresses Are Incremental
	MI2C_u8RepeatedStart(RTC_ADDRESS_READ);
	*copy_u8Seconds  = MI2C_u8ReadAck();
	*copy_u8Minutes  = MI2C_u8ReadAck();
	*copy_u8Hours    = MI2C_u8ReadNAck();
	MI2C_voidStop();
}

void HRTC_voidReadCalender(u8* copy_u8Day, u8* copy_u8Date, u8* copy_u8Month, u8* copy_u8Year)
{
	
	MI2C_voidStart();
	MI2C_u8WriteAddress(RTC_ADDRESS_WRITE);
	MI2C_u8WriteData(RTC_ADDRESS_OF_DAY);
	MI2C_u8RepeatedStart(RTC_ADDRESS_READ);
	*copy_u8Day	     = MI2C_u8ReadAck();
	*copy_u8Date     = MI2C_u8ReadAck();
	*copy_u8Month    = MI2C_u8ReadAck();
	*copy_u8Year	 = MI2C_u8ReadNAck();
	MI2C_voidStop();
}
