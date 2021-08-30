#include "Platform_Types.h"
#include "gpio.h"

void Gpio_Init (uint8 PIN_DIR)
{
	/* Enable clock for port A */
	RCC_APB2ENR_R |= (1<<2);
	
	/* Set port pins for the left half (the most significant bits)
	   configuration to general purpose output push/pull mode 
	*/
	if (DIR == (uint8)OUTPUT)
	{
		GPIO_CRH_R    &= 0xFF0FFFFF;
		GPIO_CRH_R    |= 0x00200000;
	}
	
}

void Gpio_Toggle_Pin (vuint32 PORT, uint8 PIN)
{
	PORT ^= (1<<PIN);
}
