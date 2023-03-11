/*
 * adc_pooling.c
 *
 * Created: 3/1/2023 9:52:25 AM
 *  Author: kareem
 in this prohect we control led connected at portb pin 7 with reading of adc0
 */ 


//#include <avr/io.h>
#include "ADC_int.h"
#include "dio.h"
#include "led.h"
int main(void)
{   ADC_voidInit();
	led_init();
	u16 result = 0 ;
	
    while(1)
    {     result = ADC_u16ReadADCInMV(0);
		   if (result>2500)
		   {
			   led_on(led1) ; 
			   
		   }
		   else 
		   {
			   led_off(led1);
		   }			   			
        //TODO:: Please write your application code 
    }
}