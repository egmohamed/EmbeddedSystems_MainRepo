/*
 * Timers.c
 *
 * Created: 19/10/2018 10:31:09 ص
 *  Author: ~MoHaMeD~
 */ 
 
 #include "Timers.h"
 //unsigned char Tick = 10/(prscaler/F_CPU);
 void Timer_vInit(){
 
 SET_BIT(TCCR0,WGM01);
 CLR_BIT(TCCR0,WGM00);

 OCR0 = 78;
 SET_BIT(TIMSK,OCIE0);
 SET_BIT(TCCR0,CS02);
 SET_BIT(TCCR0,CS00);
 CLR_BIT(TCCR0,CS01);
 

 }