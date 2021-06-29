/************************************************************************/
/*	
*	Home automation is project which provide potential
	for user to control home leds in rooms, tv and air 
	conditioner. There are two micro-controller included, one 
	for sending controlling signal and the second for
	receiving.
*	communication protocol: SPI
*	project was written in c language
*	This is slave file  
*   Created: 12/1/2018 09:40:10 PM
*   Authors: Mohamed Hosny and Diaa Elhak

/************************************************************************/

/*  Headers included  */

	#include "Slave_header.h"

/***********************************/

int main(void)
{
/*  Initializations  */
			
	DDRA |= 0x3F;
	SPI_vSlaveInit();
	ADC_vInit();
	
/***********************************/
	
    while (1) 
    {
		v_ReadingCompare();
		
    }
}
