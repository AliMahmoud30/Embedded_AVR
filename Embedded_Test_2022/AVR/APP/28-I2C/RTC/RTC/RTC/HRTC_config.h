/*
 * HRTC_config.h
 *
 * Created: 8/12/2022 8:15:15 PM
 *  Author: Morsy
 */ 


#ifndef HRTC_CONFIG_H_
#define HRTC_CONFIG_H_

#define RTC_ADDRESS_WRITE	0XD0
#define RTC_ADDRESS_READ	0XD1

/*Clock Addresses */
#define RTC_ADDRESS_OF_SECONDS	0x00
#define RTC_ADDRESS_OF_MINUTES	0x01
#define RTC_ADDRESS_OF_HOURS	0x02

/*Calender Addresses */
#define RTC_ADDRESS_OF_DAY		0x03
#define RTC_ADDRESS_OF_DATE		0x04
#define RTC_ADDRESS_OF_MONTH	0x05
#define RTC_ADDRESS_OF_YEAR		0x06


#endif /* HRTC_CONFIG_H_ */