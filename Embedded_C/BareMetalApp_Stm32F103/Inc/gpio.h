#ifndef  GPIO_H_
#define  GPIO_H_

#include "Platform_Types.h"

#define PIN_13         13U

/* Base address of GPIOA */
#define GPIOA_Base     0x40010800

/* Base address of RCC module */
#define RCC_Base       0x40021000

/* Pins mode register definition for the most significant bits of PORTA */
#define GPIOA_CRH_R    *((vuint32*) (GPIOA_Base + 0x04))

/* Output data register definition for PORTA */
#define GPIOA_ODR_R    *((vuint32*) (GPIOA_Base + 0x0C))

/* RCC register definition for poart A */
#define RCC_APB2ENR_R *((vuint32*) (RCC_Base + 0x18))


typedef enum {INPUT, OUTPUT}E_PIN_DIR_t;

void Gpio_Init(uint8 DIR);
void Gpio_Toggle_Pin(vuint32 PORT, uint8 PIN_DIR);

#endif /* GPIO_H_*/