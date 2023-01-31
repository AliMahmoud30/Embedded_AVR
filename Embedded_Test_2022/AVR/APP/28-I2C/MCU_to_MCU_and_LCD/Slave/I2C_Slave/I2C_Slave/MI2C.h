/***************************************************/
/* Author  : Ali Morsy                             */
/* Date    : 9-8-2022                              */
/* VERSION : VO1                                   */
/***************************************************/

#ifndef MI2C_H
#define MI2C_H

/* TWI Bit Rate Register傍WBR */
#define I2C_TWBR	*((volatile u8*)(0x20))

/*TWI Control Register傍WC */
#define I2C_TWCR	*((volatile u8*)(0x56))
#define	TWIE		0
#define	TWEN		2
#define	TWWC		3
#define	TWSTO		4
#define	TWSTA		5
#define	TWEA		6
#define	TWINT		7

/* TWI Status Register傍WSR */
#define I2C_TWSR	*((volatile u8*)(0x21))
#define	TWPS0		0
#define	TWPS1		1
#define	TWS3		3
#define	TWS4		4
#define	TWS5		5
#define	TWS6		6
#define	TWS7		7

/* TWI Data Register傍WDR */
#define I2C_TWAR	*((volatile u8*)(0x22))

/* TWI (Slave) Address Register傍WAR */
#define I2C_TWDR	*((volatile u8*)(0x23))






 /* I2C Initialization  */
void MI2C_u8voidInit(void);


 /* This Function Returns 1 if Start condition has been transmitted,
	returns 0 if not Transmitted */
 void MI2C_voidStart(void);
 
 /* This Function Returns 1 if SLA+W has been transmitted & ack Received,
	returns 0 if not Ack */
u8 MI2C_u8WriteAddress(u8 copy_u8WriteAddress);

 /* This Function Returns 1 if Data has been transmitted & ack Received,
	returns 0 if not Ack */
u8 MI2C_u8WriteData(u8 copy_u8Data);

  /* This Function Returns 1 if Repeated Start and SLA+R has been transmitted,
	 returns 0 if not ack received */
u8 MI2C_u8RepeatedStart(u8 copy_u8ReadAddress);

 /* This function read data available on the SDA line and returns its acknowledgment to the slave device 
	about data read successful and also tells slave to transmit another data. */
u8 MI2C_u8ReadAck(void);
 
 /*This function read last needed data byte available on the SDA line but does not returns an acknowledgment of it.
 It used to indicate slave that master don稚 want next data and want to stop communication.*/
u8 MI2C_u8ReadNAck(void);
 
 
 /* I2C stop function */
 void MI2C_voidStop(void);		
 
 /* I2C Slave initialization function */
void MI2C_voidSlaveInit(u8 copy_u8SlaveAddress);

 /* The slave device always needs to listen to the TWI bus to check whether it gets addressed by any Master.
	if return 0:	Own SLA+W received &ack returned
	if return 1:	Own SLA+R received &ack returned 
	if return 2:	General call received &ack returned */ 
u8 MI2C_u8SlaveListen(void);
 
/* I2C_Slave_Transmit function */ 
s8 I2C_Slave_Transmit(u8 copy_u8Data);

/* I2C_Slave_Recieve function */
s8 MI2C_u8Slave_Receive(void);

#endif
