/*
 * std_Macros1.h
 *
 * Created: 05/10/2018 11:44:36 ص
 *  Author: ~MoHaMeD~
 */ 


#ifndef STD_MACROS1_H_
#define STD_MACROS1_H_
#define  F_CPU 8000000ul
#include <avr/delay.h>
#define LED2
#define SET_BIT(REG,BIT) ((REG) |=(1<<(BIT)))
#define DATA_BUS 8
#define CLR_BIT(REG,BIT) ((REG) &= ~(1<<(BIT)))
#define READ_BIT(REG,BIT)(((REG) &(1<<BIT))>>BIT)
#define TOG_BIT(REG,BIT) ((REG) ^= (1<<BIT))
#define ROT_bit(REG,BIT) (REG<<BIT) |REG >>(DATA_BUS - BIT)

#endif /* STD_MACROS1_H_ */