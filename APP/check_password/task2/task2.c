/*
 * NTI_R02_AVR_Int.c
 *
 * Created: 2/17/2023 11:45:04 AM
 *  Author: Eng_Fawzi
 */   

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

#include "button.h"

void check_password(u8 a[])
{   static  	u8 counter = 0 ;
	static u8 right= 1 ;
	
	
	if(Button_GetStatus(BUTTON0))
	{  
		counter++ ;
		if((a[counter-1] !=1))
		{
			 led_toggle(LED_BLUE);
			 right = 0 ;
			 
		}
		//while(Button_GetStatus(BUTTON0)) ;
		_delay_ms(300);
		
	}
	else if(Button_GetStatus(BUTTON1))
	{
		counter++ ;
		if((a[counter-1] !=2))
		{
			led_toggle(LED_BLUE);
			right = 0 ;
			
		}
		_delay_ms(300);
		//while(Button_GetStatus(BUTTON1)) ;
	}
	else if(Button_GetStatus(BUTTON2))
	{
		counter++ ;
		if((a[counter-1] !=3))
		{
			led_toggle(LED_BLUE);
			right = 0 ;
			
		}
		_delay_ms(300);
	}
	
	if( (counter==6) && (right == 1))
	{
		counter = 0 ;
		led_on(LED_RED);
		_delay_ms(1000);
	}
	else if(counter==6)
	{     led_on(LED_GREEN);
		_delay_ms(1000);
		counter = 0 ;
	}
	
	
	
}

int main(void)
{   
	
	
	led_init();
	button_vidInit();
	u8 a[]={1,1,2,3,3,3} ;
	
	while(1)
    {    
			check_password(a);

	    //TODO:: Please write your application code 
    }
}