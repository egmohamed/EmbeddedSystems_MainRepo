/*
 * Timers.h
 *
 * Created: 19/10/2018 10:38:49 ص
 *  Author: ~MoHaMeD~
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#define  F_CPU 8000000ul
#define  prscaler 1024.0
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_Macros1.h"
void Timer_vInit();




#endif /* TIMERS_H_ */