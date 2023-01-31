/*
 * H7_Segment.c
 *
 * Created: 5/22/2022 10:31:05 AM
 *  Author: Morsy
 */ 
 

 
 #include "H7_Segment.h"
 #include "std_macros.h"
 
 #include "GPIO.h"
 u8 Seg_num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 void Seven_Segment_Init(void)
 {
	 DIO_Set_Pin_Direction(A_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(B_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(C_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(D_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(E_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(F_Seg,OUTPUT);
	 DIO_Set_Pin_Direction(G_Seg,OUTPUT);
	 
 }
 
 void Seven_Segment_write(u8 number)
 {
	 
	DIO_Set_Pin_Value(A_Seg,GET_BIT(Seg_num[number],0));
	DIO_Set_Pin_Value(B_Seg,GET_BIT(Seg_num[number],1));
	DIO_Set_Pin_Value(C_Seg,GET_BIT(Seg_num[number],2));
	DIO_Set_Pin_Value(D_Seg,GET_BIT(Seg_num[number],3));
	DIO_Set_Pin_Value(E_Seg,GET_BIT(Seg_num[number],4));
	DIO_Set_Pin_Value(F_Seg,GET_BIT(Seg_num[number],5));
	DIO_Set_Pin_Value(G_Seg,GET_BIT(Seg_num[number],6));
	 /*
	DIO_Set_Pin_Value(A_Seg,1);
	DIO_Set_Pin_Value(B_Seg,1);
	DIO_Set_Pin_Value(C_Seg,0);
	DIO_Set_Pin_Value(D_Seg,1);
	DIO_Set_Pin_Value(E_Seg,1);
	DIO_Set_Pin_Value(F_Seg,0);
	DIO_Set_Pin_Value(G_Seg,1);
	*/
 }
 
 