/*
 * ADC_driver.c
 *
 * Created: 13/10/2018 11:38:49 ص
 *  Author: ~MoHaMeD~
 */ 
#include "std_macros.h"
#include <avr/io.h>
#include "ADC.h"
void ADC_vInit(){
	SET_BIT(ADMUX,REFS0); // choose Vref (AVCC)
	SET_BIT(ADCSRA,ADPS1); // choose clock (8MHz/64)
	SET_BIT(ADCSRA,ADEN); // Enable ADC
	
}
unsigned short ADC_u16startConversion(){
	SET_BIT(ADCSRA,ADSC); // start conversion 
	unsigned short op_Result;
	while(READ_BIT(ADCSRA,ADIF) == 0){
		
	}
	op_Result |= ADCL;

	op_Result |= (unsigned short)(ADCH<<8);
	
	return op_Result;
	
}