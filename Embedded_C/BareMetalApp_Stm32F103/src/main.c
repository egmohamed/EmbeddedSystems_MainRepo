/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Hosny
 * @brief          : Main program body
 *
 ******************************************************************************
 */

#include "../Inc/Platform_Types.h"
#include "../Inc/gpio.h"

int main(void)
{
	/* Set pins direction for the left half (most significant bits)for GPIOA as output */	
	E_PIN_DIR_t DIR = OUTPUT;
	Gpio_Init((uint8)DIR);
	
	int i;
	for(;;)
	{
		Gpio_Toggle_Pin(GPIOA_ODR_R, (uint8)PIN_13);     
        for(i = 0; i < 5000; i++);

	}
}


