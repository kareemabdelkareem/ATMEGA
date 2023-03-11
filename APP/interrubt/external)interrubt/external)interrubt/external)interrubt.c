/*
	ATmega16 external interrupt to toggle the PORTC
	(www.electronicwings.com)
*/


#define F_CPU 8000000UL


#include "EXTI_int.h"
#include "led.h"
#include "dio.h"



#include <util/delay.h>

/*Interrupt Service Routine for INT0*/

void toggle();
void toggle2();
int main(void)

{    led_init();
	
	 EXT0_voidCallBack(toggle);
     EXT2_voidCallBack(toggle2);
	 dio_vidEnablePullUp(DIO_PORTD,DIO_PIN3) ;
	 dio_vidEnablePullUp(DIO_PORTB,DIO_PIN2) ;
	 EXT0_voidInit ( );
	 EXT0_voidEnable( );
	  EXT2_voidInit();
	  EXT2_voidEnable( );
	 
	 
	
	 
	 
	 
	 
	
	
			/* Enable Global Interrupt */
	
	while(1);
}

void toggle()     // int0
{  	
	led_toggle(led1) ; 
	//SET_BIT(SREG,7);  // enable global interrubt for nesting interrubt 
	
		
}
void toggle2()     // int1
{    
	led_toggle(led2) ; 
	//SET_BIT(SREG,7);    // enable global interrubt for nesting interrubt
	_delay_ms(600);
	//while(1);
	
}