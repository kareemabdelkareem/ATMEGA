/*
 * nti_day1.c
 *
 * Created: 2/17/2023 11:44:23 AM
 *  Author: PC
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>



#include "dio.h"
#include "led.h"
int main(void)
{ led_init();
	dio_vidConfigChannel(DIO_PORTB,7,OUTPUT);
	
	dio_vidConfigChannel(DIO_PORTD,7,INPUT);
	dio_vidEnablePullUp(DIO_PORTD,7);
    while(1)
    {     if( ! dio_dioLevelReadChannel(DIO_PORTD,7))
		 {led_on(led1);
		 _delay_ms(500); }
		 else
		{ led_off(led1);
		  _delay_ms(500); }
		  
        //TODO:: Please write your application code 
    }
}