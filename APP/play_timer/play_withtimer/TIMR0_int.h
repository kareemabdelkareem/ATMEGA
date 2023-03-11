
#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H

#include "TIMR00_priv.h"
#include "TIMR0_config.h"
#include "std_types.h"
#include "bit_math.h"
void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

void __vector_11(void) __attribute__((signal , used));
void __vector_10(void) __attribute__((signal , used));

#endif