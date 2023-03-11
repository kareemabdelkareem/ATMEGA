/*
 * Timer0.c
 *
 * Created: 3/1/2023 1:34:48 PM
 *  Author: PC
 */ 


#include "Timer0.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;


void TIMER0_void_Init(void)
{
	TCCR0 = 0 ;
	TCCR0 |= TIMER0_MODE | TIMER0_PRESCALER | TIMER0_COM_EVENT ;
	
	// in ctc or pwm modes
	if(TIMER0_MODE != NORMAL)
	{  // set pin as output 
		SET_BIT(DIO_DDRB_REG,3) ;
	}
	// clear interrupt enable
	TIMSK &= 0xFC;
	// set the interrupt state 
	TIMSK |= Int_State;
	
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 0);
	SET_BIT(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
	

}


void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}


void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}

