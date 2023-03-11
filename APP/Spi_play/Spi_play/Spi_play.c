/*
 * Spi_play.c
 *
 * Created: 3/4/2023 1:14:58 PM
 *  Author: PC
 */ 

#define  F_CPU 16000000
#include "util/delay.h"
#include <avr/io.h>
#include "Spi.h"
#include "dio.h"
#include "led.h"
#include "button.h"
int main(void)
{   led_init();
	Spi_slave_init() ;
	
	u8 read ;
    while(1)
    {    
		   read = Spi_slave_recieve();
		   if(read == 'a')
		   {
			   led_on(led2); 
			   _delay_ms(200);
		   }	
		   else if(read == 'b')
		   {
			     led_off(led2);
			     _delay_ms(200);
		   }
		 			   		   
        //TODO:: Please write your application code 
    }
}






/*
#define  F_CPU 16000000
#include "util/delay.h"
#include <avr/io.h>
#include "Spi.h"
#include "dio.h"
int main(void)
{   led_init();
	 button_vidInit();
	 Spi_master_init() ;
	while(1)
	{  if(Button_GetStatus(BUTTON0)==PRESSED) 
		{
			Spi_Master_Transieve_byte('a');
			_delay_ms(500) ;
		}
		else
		{
			  Spi_Master_Transieve_byte('b');
			_delay_ms(500) ;
		}
		
		_delay_ms(100);
		//TODO:: Please write your application code
	}
}




*/
