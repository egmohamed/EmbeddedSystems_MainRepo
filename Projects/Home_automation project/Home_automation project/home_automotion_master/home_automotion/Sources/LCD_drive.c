/*
 * LCD_drive.c
 *
 * Created: 24/10/2018 05:02:39 م
 *  Author: ~MoHaMeD~
 */ 
 #include "LCD_drive.h"

 void sndFallinEdge(){
	 PORTB |= (1<<EN);
	 _delay_ms(5);
	 PORTB &= ~(1<<EN);
	 _delay_ms(5);
 }

 void LCD_vInit(){
	// #ifdef Bit_8
	 DDRD = 0xFF;
	 DDRB |= 0x07;
	 PORTB &= ~(1<<Rw);
	 LCD_vSendCmd(0x38); // 8 bit mode
	 LCD_vSendCmd(0x01); // clear screen
	 LCD_vSendCmd(0x0E); // Turn cursor
	 LCD_vSendCmd(0x80); // cursor home
	// #else
	/*
	 DDRA |= 0xF0;
	 DDRB |= 0x0E;
	 PORTB &= ~(1<<Rw);
	 LCD_vSendCmd(0x33);
	 LCD_vSendCmd(0x32);
	 LCD_vSendCmd(0x28);
	 LCD_vSendCmd(0x28);
	 LCD_vSendCmd(0x01); // clear screen
	 LCD_vSendCmd(0x0F); // blink cursor
	 #endif
	 */
	 _delay_ms(15);
 }

 
 void LCD_vSendCmd(unsigned char cmd){
	// #ifdef Bit_8
	 PORTD = cmd;    // put data on data pins
	 PORTB &= ~(1<<Rs);
	 sndFallinEdge();
	// #else
	/*
	 PORTA &= 0x0F;
	 PORTA |= cmd & 0x0F;
	 PORTB &= ~(1<<Rs);
	 sndFallinEdge();
	 PORTA &= 0x0F;
	 PORTA |= (cmd<<4);
	 PORTB &= (~(1<<Rs));
	 sndFallinEdge();
	 #endif
	 */
 }

 void LCD_vSendChar(unsigned char chr)
 {
	 PORTD = chr;
	 PORTB |= (1<<Rs);
	 sndFallinEdge();
 }
 void LCD_vPrintString(char *ptr){
	 while(*ptr != '\0'){
		 LCD_vSendChar(*ptr);
		 ptr++;
	 }
 }

 void LCD_vClearScreen(){
	 LCD_vSendCmd(0x01);
 }
 void LCD_vMovCursor(unsigned char row,unsigned char col){
	 unsigned char temp =0;
	 if(row == 0)
	 {
		 temp = 0x80 + col;

	 }
	 else if(row == 1){
		 temp = 0xC0 + col;

	 }
	 LCD_vSendCmd(temp);
 }