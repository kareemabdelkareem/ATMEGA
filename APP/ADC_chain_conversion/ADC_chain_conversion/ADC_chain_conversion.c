/*
 * ADC_chain_conversion.c
 *
 * Created: 3/2/2023 10:41:41 PM
 *  Author: PC
 */ 


#define F_CPU 8000000UL
#include "lcd.h"
#include "ADC_int.h"
#include "dio.h"
int main(void)
{   lcd_vidInit();
	ADC_voidInit() ;
	u16  result_arr[8] ;
	char String[5];
	
	//lcd_vidGotoRowColumn(1, 2);
    while(1)
    {   // read all channels 
        ADC_u16ReadADCChannels(result_arr) ; 
		
		
		// display only 3 channels results 
		itoa(result_arr[0],String,10);	/* Integer to string conversion */
		lcd_vidDisplyStr(String);
		lcd_vidDisplyStr("  ");
		itoa(result_arr[1],String,10);	/* Integer to string conversion */
		lcd_vidDisplyStr(String);
		lcd_vidDisplyStr("  ");
		itoa(result_arr[4],String,10);	/* Integer to string conversion */
		lcd_vidDisplyStr(String);
		lcd_vidDisplyStr("  ");
		
		_delay_ms(500);
    }
}