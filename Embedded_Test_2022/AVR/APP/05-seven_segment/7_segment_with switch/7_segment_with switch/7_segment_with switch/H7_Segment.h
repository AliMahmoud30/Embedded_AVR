/*
 * H7_Segment.h
 *
 * Created: 5/22/2022 10:31:19 AM
 *  Author: Morsy
 */ 

#include "STD_TYPES.h"

#ifndef H7_SEGMENT_H_
#define H7_SEGMENT_H_


#define  A_Seg  C,0
#define  B_Seg  C,1
#define  C_Seg  C,2
#define  D_Seg  C,3
#define  E_Seg  C,4
#define  F_Seg  C,5
#define  G_Seg  C,6



void Seven_Segment_Init(void);

void Seven_Segment_write(u8 number);
 
#endif /* H7_SEGMENT_H_ */