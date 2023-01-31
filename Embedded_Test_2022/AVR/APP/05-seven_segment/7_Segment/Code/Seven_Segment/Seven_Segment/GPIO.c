/*************************************/
/* Author  : Ali Morsy  **************/
/* Version : 1          **************/
/* Date    : 22/5/021   **************/
/*************************************/


#include "STD_TYPES.h"
#include "std_macros.h"

#include "GPIO.h" 



/*        SET Direction         */ 
void DIO_Set_Port_Direction(u8 Base, u8 Direction)
{
	if((Direction == OUTPUT)||(Direction==1))
	{
		(*(volatile u8*)(Base+1)) = 0xFF;
	}
	else if((Direction == INPUT)||(Direction==0))
	{
		(*(volatile u8*)(Base+1)) = 0x00;
	}
	
	
}




void DIO_Set_Pin_Direction(u8 Base, u8 PIN, u8 Direction)
{

	if((Direction == OUTPUT) || (Direction == 1))
	{
		//SET_BIT((*(volatile u8*)(Base+1)),PIN);  // OUTPUT = 1
		(*(volatile u8*)(Base+1))|=(1<<PIN);
	}
	else if((Direction == INPUT) || (Direction == 0))
	{
		//CLR_BIT((*(volatile u8*)(Base+1)),PIN); // INPUT = 0;
		(*(volatile u8*)(Base+1))&=(~(1<<PIN)); 
	}
	else
	{
		
	}
}


/*        SET Value         */ 
void DIO_Set_Port_Value(u8 Base, u8 Value)
{
	(*(volatile u8*)(Base+2)) = Value;
}

void DIO_Set_Pin_Value(u8 Base,u8 PIN, u8 Value)
{
	if((Value == HIGH) || (Value == 1))
	{	//SET_BIT((*(volatile u8*)(Base+2)),PIN);
		(*(volatile u8*)(Base+2))|=(1<<PIN);
	}
	else if((Value == LOW) || (Value == 0))
	{
		(*(volatile u8*)(Base+2))&=(~(1<<PIN));
	}
	else
	{
		
	}
}

/*        Get Value         */ 
u8 DIO_Get_Port_value(u8 Base)
{
	 volatile u8 Value;
	Value = (*(volatile u8*)(Base));
	return Value;
}


u8 DIO_Get_Pin_value (u8 Base, u8 PIN)
{
	volatile u8 Value;
	Value = ((*(volatile u8*)(Base))>>PIN)&1;	
	return Value;
}


/* Set HIGH NIPPLE */

void DIO_SET_HIGH_Nipple_Value(u8 Base, u8 Data)
{
	Data<<=4;
	(*(volatile u8*)(Base+2)) &=0x0f;  //to CLR HIGH NIPPLE Pins before write 
	(*(volatile u8*)(Base+2)) ^=Data;
	
} 

/* Set LOW NIPPLE */

void DIO_SET_LOW_Nipple_Value(u8 Base, u8 Data)
{
	(*(volatile u8*)(Base+2)) &=0xf0;  //to CLR LOW NIPPLE before write
	(*(volatile u8*)(Base+2)) ^=(Data & 0x0F) ;
	
}
/*
void DIO(u8 Base, u8 Data)
{
	(*(volatile u8*)(Base+2)) &=0xf0;  //to CLR LOW NIPPLE before write
	(*(volatile u8*)(Base+2)) ^=Data;
	
}

*/