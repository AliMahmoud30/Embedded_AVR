/*
 * std_macros.h
 *
 * Created: 11/25/2020 3:19:35 PM
 *  Author: PC
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(REG,BIT)	REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)	REG&=(~(1<<BIT))
#define TOG_BIT(REG,BIT)	REG^= (1<<BIT)
#define GET_BIT(REG,BIT)    ((REG>>BIT)&1)
//#define GET_BIT(REG,BIT)  (REG&(1<<BIT))>>BIT)


#endif /* STD_MACROS_H_ */