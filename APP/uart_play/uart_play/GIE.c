/*
 * GIE.c
 *
 * Created: 2/25/2023 11:29:47 PM
 *  Author: PC
 */ 


#include "GIE.h"




void GIE_Enable()
{
	SET_BIT(SREG,7);
}
void GIE_Disable()
{
	CLEAR_BIT(SREG,7);
}