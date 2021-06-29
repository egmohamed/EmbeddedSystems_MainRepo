/*
 * LCD_drive.h
 *
 * Created: 24/10/2018 05:02:55 م
 *  Author: ~MoHaMeD~
 */ 


#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_
#include <avr/io.h>
//#include"std_Macros1.h"
#define F_CPU 8000000ul
#define Bit_8 8
#include <avr/delay.h>
#define EN 2
#define Rw 1
#define Rs 0
void sndFallinEdge();
void LCD_vInit();
void LCD_vSendCmd(unsigned char cmd);
void LCD_vSendChar(unsigned char chr);
void LCD_vPrintString(char *ptr);
void LCD_vClearScreen();
void LCD_vMovCursor(unsigned char row,unsigned char col);


#endif /* LCD_DRIVE_H_ */