/*
 * GIE.h
 *
 * Created: 2/25/2023 11:29:19 PM
 *  Author: PC
 */ 


#ifndef GIE_H_
#define GIE_H_

#include "bit_math.h"
#include "Std_Types.h"
#define SREG   *((volatile u8 * ) (0X5F))





void GIE_Enable();
void GIE_Disable();


#endif /* GIE_H_ */