/*
 * uart_play.c
 *
 * Created: 3/3/2023 10:47:33 AM
 *  Author: PC
 */ 
#define F_CPU 16000000
#include "util/delay.h"
//#include <avr/io.h>
#include "uart.h"
#include "GIE.h"

int main(void)
{  UART_Init(UART_BAUDRATE_9600);
	led_init();
	GIE_Enable();
	u8 *read ;
	
	//UART_TransmitStr_int("hello");
    while(1)
    {    if(UART_Recieve_is_ready())
		{    
			UART_RecieveStr_int(&read);    //  read is a pointer to buffer instead of dublicate the daata 
		} 
		
		
		if(read[1]== 'a')
		{
			UART_TransmitStr_INTERRUPT("hi\r");
		}
		
		_delay_ms(1000);
		/*read  = UART_ReceiveChr();
        UART_TransmitChr(read) ;*/
		//UART_TransmitStr("hello man") ;
		//_delay_ms(500);//TODO:: Please write your application code 
    }
}