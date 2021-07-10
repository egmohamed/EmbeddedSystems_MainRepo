/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Platform_Types.h"
/* First method for accessing registers */

#define ON             1U
#define OFF            0

#define SET_VALUE      1U
#define CLEAR_VALUE    0

#define METHOD1        OFF
#define METHOD2	       ON

#define PIN_13         13U

#define GPIOA_Base     0x40010800
#define RCC_Base       0x40021000

#if METHOD1 == ON

#define GPIO_CRH_R    *((vuint32*) (GPIOA_Base + 0x04))
#define GPIO_ODR_R    *((vuint32*) (GPIOA_Base + 0x0C))

#define RCC_APB2ENR_R *((vuint32*) (RCC_Base + 0x18))

#endif /* METHOD1 */

#if METHOD2 == ON

enum E_MODES
{
	OUTPUT_MODE = 2
};

typedef union
{
   vuint32 allFields;
   struct
   {
   	  vuint8        :2;
   	  vuint8 IOPAEN :1;

   }RCC_APB2ENR_Bits;

}RCC_APB2ENR_t;

typedef union
{
   vuint32 allFields;
   struct
   {
   	  vuint32 Reserved :13;
   	  vuint32 PIN13    :1;

   }GPIOA_Pins;

}GPIOA_ODR_t;

typedef union
{
   vuint32 allFields;
   struct
   {
   	  vuint32           :20;
   	  vuint32 MODE_Bits :5;
   }Bits;

}GPIOA_CRH_t;

volatile RCC_APB2ENR_t* RCC_APB2ENR_Ptr = (volatile RCC_APB2ENR_t*)(RCC_Base   + 0x18);
volatile GPIOA_CRH_t*   GPIOA_CRH_Ptr   = (volatile GPIOA_CRH_t*)  (GPIOA_Base + 0x04);
volatile GPIOA_ODR_t*   GPIOA_ODR_Ptr   = (volatile GPIOA_ODR_t*)  (GPIOA_Base + 0x0C);

#endif  /* METHOD2 */

int main(void)
{

#if METHOD1 == ON

	RCC_APB2ENR_R |= (1<<2);
	GPIO_CRH_R    &= 0xFF0FFFFF;
	GPIO_CRH_R    |= 0x00200000;

#endif  /* METHOD1 */

#if METHOD2 == ON

	RCC_APB2ENR_Ptr->RCC_APB2ENR_Bits.IOPAEN  = SET_VALUE;
	GPIOA_CRH_Ptr->Bits.MODE_Bits = OUTPUT_MODE;

#endif /* METHOD2 */

	int i;

	for(;;)
	{
        #if METHOD1 == ON
        GPIO_ODR_R ^= (1<<13);
        #endif  /* METHOD1 */

        #if METHOD2 == ON
        GPIOA_ODR_Ptr->allFields ^= (1<<PIN_13);
        #endif /* METHOD2 */

        for(i = 0; i < 5000; i++);

	}
}