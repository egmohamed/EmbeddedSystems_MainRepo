/************************************************************************/
/*  
*	Home automation is project which provide potential
	for user to control home leds in rooms, tv and air 
	conditioner. There are two micro-controller included, one 
	for sending controlling signal and the second for
	receiving.
*	communication protocol: SPI
*	project was written in c language
*	This is Master file
*	current Admin password: 1111  
*	blocking time = 10 seconds for testing, preferred time = 15 minutes
*	session time = 15 seconds for testing,  preferred time = 15 minutes
*   Created: 12/1/2018 09:40:10 PM
*   Authors: Mohamed Hosny and Diaa Elhak

/************************************************************************/

/*  Nested function declaration   */

	unsigned char check_pass();

/***********************************/

/*  Headers included  */

	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include "home_automotion.h"

/***********************************/

/*  Global variables definitions  */

	volatile unsigned char pressed_button;	// pressed button value sent by keypad
	char entered_timeOut_flag = 0;			// flag for session timeout
	static char EEPROM_recorded = 0;		// flag for EEPROM write
	char is_guest_mode_flag = 0;			// detector flag for home page
	char is_admin_mode = 0;					// detector flag if admin mode has been chosen
	extern volatile short Timer_counter;	// variable for timer counter 
	char blocked_flag = 0;					// detector flag for blocking by entering wrong password for 3 times

/***********************************/

/*  EEPROM reset function  /*

	// Caution: This part of code for testing on
	// simulation programs only. DON'T use it on
	// your micro-controller or it's EEPROM will
	// be damaged!
	// Usage: if needed, run this code by removing
	// double slash of the function in the start
	// of program to be able to add new password.
	// run program, wait for 3 seconds and reset 
	// program manually then after entering new password,
	// manually reset the program again
	// to add new admin password
	// current password: 1111

	void EEPROM_reset(void)
	{
	unsigned char counter;
	for(counter =0; counter <1000;counter++)
		{
			v_WriteEEPROM(0x00+counter,0xFF);
		}
	}

/***********************************/

/*  Initialization function  */

	extern inline void Init_program()
	{
		//EEPROM_reset();
		LCD_vClearScreen();	
		LCD_vPrintString("    Welcome   ");
		_delay_ms(1000);
		LCD_vClearScreen();
		LCD_vSendCmd(0x80);
		LCD_vMovCursor(0,0);
		LCD_vPrintString("Please choose:");
		_delay_ms(1000);
		LCD_vClearScreen();
		LCD_vPrintString("Guest Mode (1)");
		LCD_vMovCursor(1,0);
		LCD_vPrintString("Admin Mode (2)");
	
	 }

/***********************************/

/*  Handling wrong password function  */

	void Mode_decision_repetition()
	{	
	unsigned char check;
	static char entering_function_counter_flag = 0;// indicator flag for number of entering function 
	LCD_vPrintString("Enter Password");
	LCD_vMovCursor(1,0);
	check = check_pass();							// check entering password if returned value equals one, passed otherwise not passed
	if(check == 1){
		LCD_vClearScreen();
		LCD_vPrintString("    Passed");
		_delay_ms(500);								// hold "passed" word for 0.5 second
		if (is_admin_mode == 1)
		{
			Mode_execution(1);						// if password correct then go to mode execution function with passed value equals one
													// as indicator for admin mode or zero as indicator for guest mode
		}
		else if (is_guest_mode_flag == 1)
		{
			Mode_execution(0);
		}
	}
	else if(check == 0){							// password is not correct

		LCD_vPrintString(" Not Passed");
		_delay_ms(1000);
		LCD_vClearScreen();
		entering_function_counter_flag++;
		if(entering_function_counter_flag < 2){		// number of allowed trials to enter password
			Mode_decision_repetition();
		}
		else{
			LCD_vPrintString("It seems You");
			LCD_vMovCursor(1,0);
			LCD_vPrintString("are Blocked");
			_delay_ms(800);
			LCD_vClearScreen();
			LCD_vPrintString("For 15 minutes");
			v_WriteEEPROM(0xA,1);
			_delay_ms(10000);
			v_WriteEEPROM(0xA,0);
			LCD_vMovCursor(1,0);
			is_guest_mode_flag = 0;
			is_admin_mode = 0;
			entering_function_counter_flag = 0;
			Timer_counter = 1500;
			Init_program();
			Mode_decision();
		}
	}
}

/***********************************/

/*  Mode choose function  */
 
	void Mode_decision(void){

	unsigned char take_decesion_flag = 0;
	unsigned char check;
	
		while(take_decesion_flag == 0){
			
			pressed_button = keypade_vscan();		// read keypad value
			
			check_timer();							// check if 15 minutes elapsed, session timed out 
			
			if(pressed_button == '1'){				// guest mode
				
				is_guest_mode_flag = 1;
				LCD_vClearScreen();
				_delay_ms(100);
				LCD_vPrintString("Enter Password:");
				LCD_vMovCursor(1,0);
				check = check_pass();				// check password for guest mode 
				if(check == 1){
					LCD_vClearScreen();
					LCD_vPrintString("Entering guest");
					LCD_vMovCursor(1,0);
					LCD_vPrintString("mode ...");
					_delay_ms(500);
					Mode_execution(0);
					
				}
				else if(check == 0){

					LCD_vPrintString(" Not Passed");
					_delay_ms(1000);
					LCD_vClearScreen();
					Mode_decision_repetition();

				}
			}
				
			else if(pressed_button == '2'){				// admin mode 
				is_admin_mode = 1;
				if(v_ReadEEPROM(0x05) != v_ReadEEPROM(0xFF)){
					
					LCD_vClearScreen();
					_delay_ms(100);
					LCD_vPrintString("Enter Password");
					LCD_vMovCursor(1,0);
					check = check_pass();

					if(check == 1){

						LCD_vClearScreen();
						LCD_vPrintString("Entering admin");
						LCD_vMovCursor(1,0);
						LCD_vPrintString("mode ...");
						
						_delay_ms(500);
						Mode_execution(1);
					}

					else{
						LCD_vPrintString(" Not Passed");
						_delay_ms(1000);
						LCD_vClearScreen();
						Mode_decision_repetition();
						
					}
					
				}
				
				else if(v_ReadEEPROM(0x05) == v_ReadEEPROM(0xFF)){			// by default EEPROM values are 0xFF, by comparing location of memory
																			// which new password will be saved in with addressed location 0xFF if 
																			// they are equaling to each other equaling to 0xFF,
																			// that means no password set
				LCD_vClearScreen();
				LCD_vPrintString("Enter password");
				LCD_vMovCursor(1,0);
				LCD_vPrintString("for first time");
				_delay_ms(1000);
				LCD_vClearScreen();
				_delay_ms(300);
				EEPROM_recorded++;											// indicator password saved 
				check = check_pass();
								
			}	
		}
	
	}
 }

/***********************************/

/*  Mode choose function  */

	unsigned char check_pass()
	{
		unsigned char count = 0;
		unsigned char entered_pass[4] = {-1,-1,-1,-1};								// array that will saves characters of password
		static unsigned char zero_pressed_flag = 0;

		while(count < 4){
		
			check_timer();
				
			pressed_button = keypade_vscan();
			
			if(pressed_button == '0'){
			
			LCD_vSendChar(pressed_button);
			_delay_ms(300);											// time between showing the number and hiding it
			LCD_vMovCursor(1,count);
			LCD_vSendChar('*');
	
			entered_pass[count] = pressed_button;					// save the current character in array
		
			zero_pressed_flag++;
			count++;
			}

			else if(pressed_button != 0 && pressed_button != '0' ){ // if button pressed and it's not equal to zero
				if(zero_pressed_flag == 0){
					
					continue;
				}
				zero_pressed_flag++;
				_delay_ms(300);
				LCD_vSendChar(pressed_button);
				if(EEPROM_recorded == 0){							// normal case 
				LCD_vMovCursor(1,count);
				}
				else if(EEPROM_recorded == 1){						// recording password in EEPROM for first time
					LCD_vMovCursor(0,count);
				}
				_delay_ms(300);
				LCD_vSendChar('*');
				entered_pass[count] = pressed_button;
				count++;
				if(EEPROM_recorded == 1){
					v_WriteEEPROM(0x04+count,pressed_button);		// write password in EEPROM
					if(count == 4){									// save password up to four digit
					LCD_vClearScreen();
					LCD_vPrintString(" Password saved");
					}
				}
			}
				zero_pressed_flag++;
		}
		
		if(entered_pass[0] == '0' && entered_pass[1] == '0' && entered_pass[2] == '0' && entered_pass[3] == '0'){
			if (is_guest_mode_flag == 1 && is_admin_mode == 0)
			{
				return 1;											// function return value indicates if password is correct or not
			}
			else if (is_admin_mode == 1)
			{
				return 0;
			}
			}
			else{
				if(v_ReadEEPROM(0x05) != v_ReadEEPROM(0xFF)){		// there's predefined admin saved password also check
																	// if password in array identical to saved password in EEPROM
					if(entered_pass[0] == v_ReadEEPROM(0x05) && entered_pass[1] == v_ReadEEPROM(0x06) && entered_pass[2] == v_ReadEEPROM(0x07) && entered_pass[3] == v_ReadEEPROM(0x08)){
						if (is_admin_mode == 1 && is_guest_mode_flag == 0)
						{
							return 1;
						}
						
					}
					else{
						return 0;
					}
				}
				return 0;
			}	

 }

/***********************************/

/*  Check timer interrupt  */

	extern inline void check_timer(){
		if(Timer_counter == 0){								// session time up
		 if(pressed_button == 0){							// currently there's no one pressing on keypad's keys
			 LCD_vClearScreen();
			 LCD_vPrintString("Session time out");
			 _delay_ms(500);
			 is_guest_mode_flag = 0;
			 is_admin_mode = 0;
			 Timer_counter = 1500;							// reset timer counter
			 Init_program();										 
			 Mode_decision();
		 }
	 }
 }

/***********************************/

/*  Control assets function  */

	extern inline void Mode_execution (char choosen_mode)
	{
	char lag_flag = 0;										// just for stuck in loop
	unsigned char temp_pressed;
	
	if (choosen_mode == 1)									// 1 for admin mode, 0 for guest mode
	{	
		
		LCD_vMovCursor(0,0);
		LCD_vPrintString("1:L1 2:L2 3:L3  ");
		LCD_vMovCursor(1,0);
		LCD_vPrintString("4:TV 5:Air_Con  ");
	}
	else if (choosen_mode == 0)
	{
		
		LCD_vClearScreen();
		LCD_vMovCursor(0,0);
		LCD_vPrintString("1:L1 2:L2 3:L3  ");
	}
	
	
	while (lag_flag == 0)
	{
	 check_timer();														// uncommon behavior, if you passed to leds control panel
	 pressed_button = keypade_vscan();									// then backed to home control panel quickly for long time, session 
	 if (pressed_button == '1')											// time may end up regardless the interval after last pressed button, However
	 {																	// this effect clearly shows with short session times like the one we currently 
		Timer_counter = 1500;											// use for testing 
		LCD_vMovCursor(0,0);
		LCD_vPrintString("1:ON       2:OFF");
		LCD_vMovCursor(1,0);
		LCD_vPrintString("0:Back          ");
		lag_flag = 1;
		
	}
		
	 if (pressed_button == '2')
	 {
		Timer_counter = 1500;
		 LCD_vMovCursor(0,0);
		 LCD_vPrintString("1:ON       2:OFF");
		 LCD_vMovCursor(1,0);
		 LCD_vPrintString("0:Back          ");
		 lag_flag = 1;
	 }

	 if (pressed_button == '3')
	 {
		Timer_counter = 1500;
		 LCD_vMovCursor(0,0);
		 LCD_vPrintString("1:ON       2:OFF");
		 LCD_vMovCursor(1,0);
		 LCD_vPrintString("0:Back          ");
		 lag_flag = 1;
	 }

	 if (pressed_button == '4')
	 {	
		Timer_counter = 1500;
		if (choosen_mode == 1)
		{
			LCD_vMovCursor(0,0);
			LCD_vPrintString("1:ON       2:OFF");
			LCD_vMovCursor(1,0);
			LCD_vPrintString("0:Back          ");
			lag_flag = 1;
		}
		 
	 }

	 if (pressed_button == '5')
	 {
		Timer_counter = 1500;
		if (choosen_mode == 1)
		{
			LCD_vMovCursor(0,0);
			LCD_vPrintString("1:ON       2:OFF");
			LCD_vMovCursor(1,0);
			LCD_vPrintString("0:Back          ");
			lag_flag = 1;
		}
		 
	 }
		
		temp_pressed = pressed_button;							// temporary variable hold pressed button 
	}
		
		while (lag_flag == 1)
		{
					
				pressed_button = 0;								// to satisfy the condition of ISR function to keep timer counting 
					check_timer();
		
		if ( keypade_vscan() == '1') 
		{
			Timer_counter = 1500;								// reset timer to start counting from where last button pressed
			if (temp_pressed == '1')
			{
				SPI_vMasterWrite(102);
			}
			
			if (temp_pressed == '2')
			{
				SPI_vMasterWrite(104);
			}

			if (temp_pressed == '3')
			{
				SPI_vMasterWrite(106);
			}

			if (temp_pressed == '4')
			{
				SPI_vMasterWrite(108);
			}

			if (temp_pressed == '5')
			{
				char write_temp_counter = 0;							// to stuck in loop 
				char write_temp_counter2 = 0;							// index of entered temperature digit	
				unsigned char temp_save[3] = {0,0};						// array of two elements to hold the entire value which
				unsigned char sent_value = 0;							// controls air conditioner degree
				LCD_vMovCursor(0,0);
				LCD_vPrintString("Enter temp Deg: ");
				LCD_vMovCursor(1,0);
				LCD_vPrintString("__    X for back");
			
				while (write_temp_counter == 0) 
				{
						
						pressed_button = keypade_vscan();
						
							check_timer();
						
						if (write_temp_counter2 == 0 || write_temp_counter2 == 1)
						{
							LCD_vMovCursor(1,write_temp_counter2);
						}
						
						
						if (pressed_button != 0)						// button pressed
						{
							if (pressed_button == '*')					// for exit 
							{
								Mode_execution(1);						// return to the start of function 
							}
							LCD_vSendChar(pressed_button);
							_delay_ms(300);
							temp_save[write_temp_counter2] = pressed_button;

							if (write_temp_counter2 == 1)				// cursor on the second digit 
							{
																		// multiply double digit level by ten and add single digit
																		// to calculate the entire number

								sent_value  = temp_save[0] * 10 + temp_save[1];
								SPI_vMasterWrite(sent_value - 16);
								write_temp_counter2 = -1;
							}

							write_temp_counter2++;
						}
							
				}
							
			}
			
		}
		if ( keypade_vscan() == '2')
		{
			
			Timer_counter = 1500;

			if (temp_pressed == '1')
			{
				SPI_vMasterWrite(101);
			}

			if (temp_pressed == '2')
			{
				SPI_vMasterWrite(103);
			}

			if (temp_pressed == '3')
			{
				SPI_vMasterWrite(105);
			}

			if (temp_pressed == '4')
			{
				SPI_vMasterWrite(107);
			}

			if (temp_pressed == '5')
			{
				SPI_vMasterWrite(109);
			}

			
		}
		if ( keypade_vscan() == '0')								// back to home control panel
		{	
			Timer_counter = 1500;
			if (choosen_mode == 0)									// back to control panel '0' if you are 
			{														// running on admin mode or '1' if you are running on guest mode 
				Mode_execution(0);
			}
			else if (choosen_mode == 1)
			{
				Mode_execution(1);
			}
		}
	}
 }
 
 /***********************************/