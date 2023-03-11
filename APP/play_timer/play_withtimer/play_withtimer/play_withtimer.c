/*
 * play_withtimer.c
 *
 * Created: 2/26/2023 11:04:55 AM
 *  Author: PC
 */ 


#define F_CPU 8000000
#include "led.h"
#include "std_types.h"
#include "Timer0.h"
#include "Timer1.h"
#include "GIE.h"
#include "dio.h"
/* timer0 overflow interrupt */
u16 counter = 0 ;
u16 counter2 = 0 ;
u16 compare = 100 ;
void led_tog();
void led2_tog();


void set_sec_toggle(u16 x );
int main( void )
{   led_init();
	//SET_BIT(DIO_DDRB_REG,3);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT) ; 
	//TIMER0_void_SetOVCallBack(led_tog) ;
	TIMER1_void_SetOVCallBack(led_tog);
	//TIMER0_void_SetCTCCallBack(led2_tog) ; 
	TIMER1_void_Init();
	//TIMER0_void_Init();
	TIMER1_void_EnableOVInt();
	//TIMER0_void_EnableOVInt() ;
	//TIMER0_void_EnableCTCInt();
	//TIMER0_void_SetCompareVal(128) ; 
	GIE_Enable();
    //set_sec_toggle(2) ;


	while(1);
	
}
void led_tog()
{
	counter++ ;
	//led_on(LED_RED) ;
	if(counter > 10)
	{
		led_toggle(LED_RED) ;
		//led_on(LED_RED);
		counter = 0 ;
	}
}

void led2_tog()
{
	counter2++ ;
	if(counter2 > 100)
	{
		led_toggle(LED_GREEN) ;
		counter2 = 0 ;
	}
}
void set_sec_toggle(u16 x )
{
	compare = (float )x/ ((1024 * 256.0) /8000000) ;
}