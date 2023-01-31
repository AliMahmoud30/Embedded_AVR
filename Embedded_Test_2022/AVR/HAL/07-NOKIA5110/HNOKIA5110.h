/*
 * HNOKIA5110.h
 *
 * Created: 11/23/2022 9:15:48 PM
 *  Author: Morsy
 */ 


#ifndef HNOKIA5110_H_
#define HNOKIA5110_H_

void NOKIA5110_voidInit(void);
void NOKIA5110_SendCmd(u8 copy_u8Command);
void NOKIA5110_SendChar(u8 copy_u8Character, u8 copy_u8XIdx, u8 copy_u8YIdx);
void NOKIA5110_SendString(u8 *string, u8 copy_u8XIdx, u8 copy_u8YIdx);
void N5110_Data(char *DATA);


#endif /* HNOKIA5110_H_ */