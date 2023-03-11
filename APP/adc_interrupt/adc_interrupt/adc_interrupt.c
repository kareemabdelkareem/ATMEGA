/*
 * adc_interrupt.c
 *
 * Created: 3/1/2023 10:05:47 AM
 *  Author: PC
 */ 
#define  F_CPU 8000000
#include "util/delay.h"
#include "ADC_int.h"
#include "button.h"
#include "EXTI_int.h"
#include "led.h"
#include "dio.h"

u16 result = 0 ;

void interupt_callback();
void adc_calback();

int main(void)
{    ADC_voidCallBack(adc_calback);
	EXT0_voidCallBack(interupt_callback);
	EXT0_voidInit();
	ADC_voidInit();
	led_init();
	dio_vidEnablePullUp(DIO_PORTD,DIO_PIN2) ; 
    while(1)
    {
        if(result >2500)
		{
			led_on(led1);
			
		}	
		else
		{  
			led_off(led1);
		}					
    }
}

void interupt_callback()
{
	led_toggle(led2);
	_delay_ms(200);
}
void adc_calback()
{
	result = ADC_u16ReadADCIninterrupt(0) ; 
}