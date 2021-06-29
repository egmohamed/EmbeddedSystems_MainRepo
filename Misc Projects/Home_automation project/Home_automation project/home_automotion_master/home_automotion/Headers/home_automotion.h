
/*
 * home_automotion.h
 *
 * Created: 12/1/2018 08:50:46 AM
 *  Authors: Mohamed Hosny and Diaa Alhak
 */ 
 /*  Headers included  */

	 #include "keypad1.h"
	 #include "LCD_drive.h"
	 #include "std_Macros1.h"
	 #include "Timers.h"
	 #include "SPI.h"
	 #include "EEPROM.h"

/***********************************/

	#define _AVR_DELAY_H_
 
/*  Functions definitions  */

	 auto unsigned char check_pass();
	 extern inline void Init_program();
	 extern inline void check_timer();
	 extern inline void Mode_execution (char choosen_mode);
	 unsigned char check_pass();
	 void Mode_decision(void);
	 void EEPROM_reset(void);

/***********************************/

/*  extern variables declaration  */

	 extern volatile short Timer_counter;
	 extern volatile unsigned char pressed_button;

/***********************************/
