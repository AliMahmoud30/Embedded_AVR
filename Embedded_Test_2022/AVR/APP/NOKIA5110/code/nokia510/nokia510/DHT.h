#ifndef __DHT_H__
#define __DHT_H__

/*
 * DHT Sensor for AVR-GCC Family
 *
 * Author      : David Feng
 * Updated     : June 26th, 2018
 * Description : DHT Sensor Library for AVR-GCC compiler
 * Usage       : Use library with AVR-GCC for Atmega family of microcontrollers (tested with Atmega 1284)
 */

#include <stdio.h>
#include <avr/io.h>

//Port where DHT sensor is connected
#define DHT_DDR DDRB
#define DHT_PORT PORTB
#define DHT_PIN PINB
#define DHT_INPUTPIN 0

//Define sensor type
#define DHT_DHT11 0
#define DHT_DHT22 1
#define DHT_TYPE DHT_DHT22

//timeout retries
#define DHT_TIMEOUT 200

//functions
#if DHT_TYPE == 1
extern s8 dht_GetTempUtil(u16 *temperature, u16 *humidity);
#elif DHT_TYPE == 0
extern s8 dht_GetTempUtil(s8 *temperature, s8 *humidity);
#endif

#endif