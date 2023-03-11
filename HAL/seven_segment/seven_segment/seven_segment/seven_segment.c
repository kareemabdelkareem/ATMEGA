/*
 * seven_segment.c
 *
 * Created: 2/22/2023 9:50:40 AM
 *  Author: PC
 */ 


#include <avr/io.h>
#include "SSD.h"
#include "button.h"




u8 get_pressed() 
{   static u8 flag = 1 ;
	 if(Button_GetStatus(BUTTON0))
	 {
		 flag = 1 ;
		 _delay_ms(100) ;
	 }
	 else if(Button_GetStatus(BUTTON1))
	 {
		 flag = 0 ;
		 _delay_ms(100) ;
	 }
	 
	return flag ;
}

void show_num(u8 num)
{  u8 i ;
	for ( i = 0 ;i<5 ; i++)
	{
		SSD_DisplayNum(num)  ;
		_delay_ms(40) ;
	}
	
}
int main(void)
{
	button_vidInit();
	SSD_vidInit() ;
	u8 counter = 0 ;
	u8 flag = 1 ; 
	
    while(1)
    {  
		
		get_pressed();
		
		if(flag==1 ) 
		{
			counter++ ;
			if(counter == 99 ) counter = 0 ;
		}
		else
		{
			counter-- ; 
			if(counter ==0) counter = 99 ;
			
		}
		
		flag =  get_pressed();
		show_num(counter) ;
		flag =  get_pressed();
		show_num(counter) ;
		flag = get_pressed();
		show_num(counter) ;
		flag = get_pressed();
		show_num(counter) ;
        //TODO:: Please write your application code 
    }
}