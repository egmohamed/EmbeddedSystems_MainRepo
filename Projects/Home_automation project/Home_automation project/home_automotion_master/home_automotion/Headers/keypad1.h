/*
 * keypad1.h
 *
 * Created: 26/01/40 09:44:50 ص
 *  Author: Mahmoud Saleh
 */ 


#ifndef KEYPAD1_H_
#define KEYPAD1_H_
#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
void KeyPad_vInit();
unsigned char keypade_vscan();





#endif /* KEYPAD1_H_ */