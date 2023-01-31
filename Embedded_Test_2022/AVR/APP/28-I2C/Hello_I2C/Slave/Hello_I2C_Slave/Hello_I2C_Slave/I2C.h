/*************************************/
/* Author  : Ali Morsy  **************/
/* Version : 1          **************/
/* Date    : 22/10/021   **************/
/*************************************/


#ifndef I2C_H_
#define I2C_H_

void I2C_Master_Init(unsigned long SCL_Clock);

void I2C_start(void);

void I2c_Write_Address(unsigned char Address);

void I2c_Write_Data(unsigned char Data);

void i2C_stop(void);

void I2C_Set_Slave_Address(unsigned char Address);

unsigned char I2C_Slave_Read(void);






#endif /* I2C_H_ */