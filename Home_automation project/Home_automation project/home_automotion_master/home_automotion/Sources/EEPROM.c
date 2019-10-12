/*
 * EEPROM.c
 *
 * Created: 10/26/2018 12:41:09 PM
 * Author : ~MoHaMeD~
 */ 

#include <avr/io.h>
#include "EEPROM.h"
void v_WriteEEPROM(unsigned short adress,unsigned char data){
	
	EEAR = adress;
	EEDR = data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)){}

}
unsigned char v_ReadEEPROM(unsigned char adress){
while(READ_BIT(EECR,EEWE)){}
EEAR = adress;
SET_BIT(EECR,EERE);
return EEDR;
}
