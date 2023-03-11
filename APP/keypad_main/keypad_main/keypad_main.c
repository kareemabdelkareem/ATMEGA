/*
 * keypad_main.c
 *
 * Created: 2/18/2023 8:49:22 PM
 *  Author: PC
 */ 


#include <avr/io.h>
#include "dio.h"
#include "led.h"
int main(void)
{   keypad_init();
	led_init();
	u8 result ;
	dio_vidConfigChannel(DIO_PORTA , DIO_PIN1,OUTPUT);
	 
    while(1)
    {
       result = keypad_get_states();
	   if(result == 2)
	   {
		   led_on(LED_RED);
		   _delay_ms(200);
	   }
	   else
	   {
		  dio_vidWriteChannel(DIO_PORTA,DIO_PIN1,STD_LOW);
		   _delay_ms(200);
	   }
		   
    }
}