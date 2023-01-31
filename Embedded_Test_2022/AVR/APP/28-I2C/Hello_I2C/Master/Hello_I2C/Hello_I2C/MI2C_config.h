/***************************************************/
/* Author  : Ali Morsy                             */
/* Date    : 9-8-2022                              */
/* VERSION : VO1                                   */
/***************************************************/

#ifndef MI2C_CONFIG_H
#define MI2C_CONFIG_H


#define DIV_1	0
#define DIV_4	1
#define DIV_16	2
#define DIV_64	3

/*  SCL Clock */
#define I2C_CLOCK		50000	// 50KHz

/*prescaler Options:
					DIV_1,
					DIV_4,
					DIV_16,
					DIV_64   */
#define	I2C_Prescaler	DIV_1

#endif
