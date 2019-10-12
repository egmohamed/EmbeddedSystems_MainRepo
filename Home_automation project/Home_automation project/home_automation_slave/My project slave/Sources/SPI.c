#include "SPI.h"
void SPI_vMasterInit()
{	
	SET_BIT(SPCR,SPR1);		//choose clock rate (8MHZ/64)
	SET_BIT(SPCR,MSTR);		//choose master mode
	SET_BIT(DDRB,SS);
	SET_BIT(DDRB,MOSI);
	SET_BIT(DDRB,SCK);
	SET_BIT(PORTB,SS);	
	SET_BIT(SPCR,SPE);		//enable SPI	
}
void SPI_vSlaveInit()
{
	SET_BIT(SPCR,SPE);		//enable SPI
	SET_BIT(DDRB,MISO);
}
void SPI_vMasterWrite(u8 data)
{
	CLEAR_BIT(PORTB,SS);
	SPDR=data;
	while(READ_BIT(SPSR,SPIF)==0)		//make sure that the data has been sent
	{
		
	}
	SET_BIT(PORTB,SS);
}
u8 SPI_u8SlaveRead()
{
	while(READ_BIT(SPSR,SPIF)==0)		//wait until data is received in SPI register
	{
		
	}
	return SPDR;
}
