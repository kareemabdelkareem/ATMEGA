/*
 * Timer0.h
 *
 * Created: 3/1/2023 1:35:04 PM
 *  Author: PC
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


#define NULL   0
#include "TIMR0_priv.h"
#include "std_types.h"
#include "bit_math.h"
#include "Timer_conf.h"

	typedef enum {NORMAL = 0x00,
	PWM_PhaseCorrect = 0x40,
	CTC =0x08,
	PWM_FastMode = 0x48,
}T0_Modes;

typedef enum {
	CMP_Disable = 0x00 ,
	NonPWM_Toggle = 0x10,
	NonPwm_Clear = 0x20,
	NonPwm_Set = 0x30,
	PwmFast_Invert =0x30 ,
	PwmFast_NonInvert= 0x20,
	PwmPhaseCorrect_UpClear=0x20 ,
	PwmPhaseCorrect_Upset=0x30,
}T0_Cmp_OutputMode;

typedef enum{
	T0_Disable = 0x00,
	F_CPU_Prescaler1,
	F_CPU_Prescaler8,
	F_CPU_Prescaler64,
	F_CPU_Prescaler256,
	F_CPU_Prescaler1024,
	F_T0_PIN_SRISING,
}T0_ClkSelect;
typedef enum{
	T0_INTERRUPT_DISABLE,
	T0_TOV_INTERRUPT_ENABLE,
	T0_OCM_INTERRUPT_ENABLE,
	T0_TOV_OCM_INTERRUPT_ENABLE,
}T0_Interrupt_State;



void TIMER0_void_Init(void);
void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);
void TIMER0_void_SetCompareVal(u8 Copy_uint8Val) ;
void TIMER0_void_EnableOVInt(void) ;
void TIMER0_void_DisableOVInt(void) ;
void TIMER0_void_EnableCTCInt(void) ;
void TIMER0_void_DisableCTCInt(void) ;


void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

void __vector_11(void) __attribute__((signal , used));
void __vector_10(void) __attribute__((signal , used));


#endif /* TIMER0_H_ */