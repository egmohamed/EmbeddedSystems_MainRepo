
/*
 * Slave.c
 *
 * Created: 1/9/2019 07:48:18 PM
 *  Authors: Mohamed Hosny and Diaa Alhak
 */ 

 #include "Slave_header.h"

/*  Take action function  */

 void v_ReadingCompare(void)
 {
	u8 read_spi_value;
	u16 read_ADC_value;
	
	read_spi_value = SPI_u8SlaveRead();
	read_ADC_value = ADC_u16startConversion();

	if(read_ADC_value/2 <= 24) read_ADC_value = read_ADC_value/2;			// after divide adc values by two to convert to temperature degrees,
																		    // noted that values are increasing in ascending manner by one after
																			// certain values so we handle them to get the right degrees

	else if((read_ADC_value/2) >24 && (read_ADC_value/2) <= 61) read_ADC_value = read_ADC_value/2 -1;
	else if((read_ADC_value/2) >61 && (read_ADC_value/2) <=99)  read_ADC_value = read_ADC_value/2 -2;
	else if((read_ADC_value/2) >99 && (read_ADC_value/2) <=137) read_ADC_value = read_ADC_value/2 -3;
	else if(read_ADC_value/2 >137) read_ADC_value = read_ADC_value/2 -4;
	
	if(read_spi_value<read_ADC_value)										// if remote degree is lesser than room temperature 
	{
		
		SET_BIT(PORTA,5);
	}
	if(read_spi_value>read_ADC_value)
	{
		CLEAR_BIT(PORTA,5);
	}
	else
	{
		//do nothing
	}
	
	if(read_spi_value==101)													// upcoming spi values sent to control leds,tv and air conditioner 
	{
		CLEAR_BIT(PORTA,4);
	}
	else if(read_spi_value==102)
	{
		SET_BIT(PORTA,4);
	}
	else if(read_spi_value==103)
	{
		CLEAR_BIT(PORTA,3);
	}
	else if(read_spi_value==104)
	{
		SET_BIT(PORTA,3);
	}
	else if(read_spi_value==105)
	{
		CLEAR_BIT(PORTA,2);
	}
	else if(read_spi_value==106)
	{
		SET_BIT(PORTA,2);
	}
	else if(read_spi_value==107)
	{
		CLEAR_BIT(PORTA,1);
	}
	else if(read_spi_value==108)
	{
		SET_BIT(PORTA,1);
	}
	else if(read_spi_value==109)
	{
		CLEAR_BIT(PORTA,0);
	}
 }

/***********************************/
