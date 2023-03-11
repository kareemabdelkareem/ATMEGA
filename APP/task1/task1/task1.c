/*
 * task1.c
 *
 * Created: 2/19/2023 9:29:02 AM
 *  Author: PC
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "BUTTON.h"
#include "dio.h"
#include "LED.h"

int main(void)
{  volatile u8 count[3]={0,0,0} ;
	volatile u8 buttons[] ={BUTTON1,BUTTON2,BUTTON3} ;
	volatile u8 i =0 ;
	volatile	u8 read_state = 0 ;
	volatile	u8 sum_count = 0;
	 BUTTON_init();
	LED_INIT(); 
	LED_OFF(RED); 
	LED_OFF(GREEN);
	
    while(1)
    { 
		
		
		for(i=0;i<3;i++)
		{ read_state=BUTTON_get_status(buttons[i]);
			if(read_state==PRESSED)
			
			{
				count[i]++ ;
				sum_count++ ; 
			
			}
			while( BUTTON_get_status(buttons[i])==PRESSED) ;
			
		}	
		
		/*if(count[2]>2)
		{
			LED_ON(RED);
			_delay_ms(500);
			
			
		}*/
		if(sum_count==6)	
		{	
				if((count[0]== 3) && (count[1]==2) && (count[2]==1))
				{
		
					LED_ON(RED);
					_delay_ms(500);
					sum_count=0 ;
		
				}
				else 
				{
					LED_ON(GREEN);
					_delay_ms(500);
					sum_count=0 ;
				}
			
			
		}
		        
    }
}