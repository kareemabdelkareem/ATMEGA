/*
 * INTERNAL_EEPORM.c
 *
 * Created: 3/11/2023 11:21:14 AM
 *  Author: PC
 */ 





#include <avr/io.h>
#include "INTERNAL_EEPORM.h"
#include "Bit_Math.h"
#include "Std_types.h"
void EEPROM_write(unsigned short address, unsigned char data )
{
	/*set up address register*/
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	/*set up data register*/
	EEDR=data ;
	/*write logical one to EEMWE*/
	SET_BIT(EECR,EEMWE);
	/*start EEPROM write by setting EEWE*/
	SET_BIT(EECR,EEWE);
	/* wait for completion of write operation*/
	while(GET_BIT(EECR,EEWE)==1);
}
unsigned char EEPROM_read( unsigned short address )
{
	/*set up address register*/
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	/*start EEPROM read by setting EERE*/
	SET_BIT(EECR,EERE);
	/*return data from data register*/
	return EEDR ;
}