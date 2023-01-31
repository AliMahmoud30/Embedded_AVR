/*************************************************************/
/* Author  : Ali Morsy                                       */
/* Date    : 20-8-2022                                       */
/* VERSION : VO1                                             */
/*************************************************************/
/*				Function Implementation						 */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronuse(u8 copy_u8DataToSend)
{
	s8 Local_u8Counter;
	u8 Local_u8Bit;
	/* Send bit by bit MSB first*/
	for(Local_u8Counter=7; Local_u8Counter>=0; Local_u8Counter--)
	{
		Local_u8Bit=GET_BIT(copy_u8DataToSend,Local_u8Counter);
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		/* send pulse on Shift clock  100ns  or more   */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWaite(1);				/* 1us*/ 
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWaite(1);				/* 1us*/
	}
	/* send pulse on Stor clock  100ns  or more   */
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_voidSetBusyWaite(1);				/* 1us*/ 
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_voidSetBusyWaite(1);				/* 1us*/
	
}
