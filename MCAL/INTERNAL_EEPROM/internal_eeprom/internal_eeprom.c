/*
 * internal_eeprom.c
 *
 * Created: 3/11/2023 11:20:21 AM
 *  Author: PC
 */ 


#include <avr/io.h>
#include "INTERNAL_EEPORM.h"

int main(void)
{  
	lcd_vidInit() ;
	// write in address  0x0A    data 5 
	 	EEPROM_write(1,'k') ;
	 	EEPROM_write(2,'a') ;
	 	EEPROM_write(3,'r') ;
	 	EEPROM_write(4,'i') ;
	 	EEPROM_write(5,'m') ;
    while(1)
    {   lcd_vidDisplyChar(EEPROM_read(1)) ;
	    lcd_vidDisplyChar(EEPROM_read(2)) ;
	    lcd_vidDisplyChar(EEPROM_read(3)) ;
	    lcd_vidDisplyChar(EEPROM_read(4)) ;
	    lcd_vidDisplyChar(EEPROM_read(5)) ;
		lcd_vidGotoRowColumn(0, 0);
        //TODO:: Please write your application code 
    }
}