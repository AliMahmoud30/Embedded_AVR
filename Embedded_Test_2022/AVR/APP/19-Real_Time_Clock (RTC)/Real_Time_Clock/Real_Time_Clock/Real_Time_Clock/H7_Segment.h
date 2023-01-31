/*
 * H7_Segment.h
 *
 * Created: 5/22/2022 10:31:19 AM
 *  Author: Morsy
 */ 

#include "STD_TYPES.h"

#ifndef H7_SEGMENT_H_
#define H7_SEGMENT_H_


#define  A_Seg  D,0
#define  B_Seg  D,1
#define  C_Seg  D,2
#define  D_Seg  D,3
#define  E_Seg  D,4
#define  F_Seg  D,5
#define  G_Seg  D,6



void Seven_Segment_Init(void);

void Seven_Segment_write(u8 number);

void Seven_Segment_write_BCD(u8 number);

 
#endif /* H7_SEGMENT_H_ */