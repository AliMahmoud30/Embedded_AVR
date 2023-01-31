/*
 * EXT_Interrupt.h
 *
 * Created: 6/12/2022 3:21:34 PM
 *  Author: Morsy
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_


/* Status register */
#define SREG	*((volatile unsigned char*)(0x5F))
#define I_BIT	7

/* General Interrupt Control register */
#define GICR	*((volatile unsigned char*)(0x5B))
#define INT2	5
#define INT0	6	
#define INT1	7


/* General Interrupt Flag register */
#define GIFR	*((volatile unsigned char*)(0x5A))

#define INTF2	5
#define INTF0	6
#define INTF1	7


/*Control register */
#define MCUCR	*((volatile unsigned char*)(0x55))

#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/*Control and status register */
#define MCUCSR	*((volatile unsigned char*)(0x54))
ISC2	6



#endif /* EXT_INTERRUPT_H_ */