/*
 * Masseage.h
 *
 * Created: 9/24/2022 4:49:06 PM
 *  Author: Morsy
 */ 


#ifndef MASSEAGE_H_
#define MASSEAGE_H_



#define DEMAND_RESPONSE		0xFF

#define ON_STATUS			0x01
#define OFF_STATUS			0x00

#define ROOM1_STATUS		0x11
#define ROOM2_STATUS		0x12
#define ROOM3_STATUS		0x13
#define ROOM4_STATUS		0x14
#define TV_STATUS			0x15
#define AIR_CON_STATUS		0x16



#define ROOM1_TURN_ON		0x21
#define ROOM2_TURN_ON		0x22
#define ROOM3_TURN_ON		0x23
#define ROOM4_TURN_ON		0x24
#define TV_TURN_ON			0x25
#define AIR_CON_TURN_ON		0x26


 
#define ROOM1_TURN_OFF		0x31
#define ROOM2_TURN_OFF		0x32
#define ROOM3_TURN_OFF		0x33
#define ROOM4_TURN_OFF		0x34
#define TV_TURN_OFF			0x35
#define AIR_CON_TURN_OFF	0x36

#define SEND_TEMP			0x37

#define NOT_PRESSED			0xFF



#endif /* MASSEAGE_H_ */

