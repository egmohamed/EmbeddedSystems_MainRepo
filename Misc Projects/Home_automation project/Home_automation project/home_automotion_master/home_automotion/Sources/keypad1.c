
/*
 * keypad1.c
 *
 * Created: 26/01/40 09:44:26 ص
 *  Author: Mahmoud Saleh
 */ 

#include "std_Macros1.h"
#include "keypad1.h"
#define NO_BTN_PRESSED 0
void KeyPad_vInit()
{
	DDRC |= 0x0F;
	PORTC |=0xFF;// Pull up res
}
unsigned char keypade_vscan()
{
	unsigned char calc[4][4]=
	{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'A','0','=','+'}
	};
	for (int row =0;row<4;row++)
	{
		PORTC |= 0xFF;
		CLR_BIT(PORTC,row);
	    //_delay_ms(1000);
		 
		for (int col=0;col<4;col++)
		{
			if(READ_BIT(PINC,(col+4))==0) // cause it will get zero value from line above and zero by pressing the button 
			{
				return calc[row][col];	
				
			}
						
		}
		
		
	}
	return 0;
}	
	