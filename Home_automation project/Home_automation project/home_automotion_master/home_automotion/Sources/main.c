/*
 * home_automotion.c
 *
 * Created: 12/1/2018 08:43:49 AM
 * Author : ~MoHaMeD~
 */ 
 /*  Headers included  */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "home_automotion.h"

/***********************************/

/*  Volatile and extern variables definitions  */

volatile short Timer_counter = 1500;
volatile unsigned char timer_flag;
volatile unsigned char pressed_button;
extern char blocked_flag;

/***********************************/

int main(void)
{  
/*  Initializations  */

 LCD_vInit();
 KeyPad_vInit();
 Timer_vInit();
 SPI_vMasterInit();
 sei();

/***********************************/

  
  
   while (1) 
    {
		 while (v_ReadEEPROM(0xA) == 1)
		 {
			 LCD_vClearScreen();
			 LCD_vPrintString("It seems You");
			 LCD_vMovCursor(1,0);
			 LCD_vPrintString("are blocked");
			 _delay_ms(10000);
			 v_WriteEEPROM(0xA,0);
		 }
			
				Init_program();
				Mode_decision();
	

		}
	}

/*  ISR timer  */

ISR(TIMER0_COMP_vect){

	Timer_counter --;

	if(pressed_button != 0){

		Timer_counter = 1500;
	}
	
}

/***********************************/
