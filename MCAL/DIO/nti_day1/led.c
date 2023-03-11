/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "led.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                                                                         
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void led_init(void) 
{   dio_vidConfigChannel(DIO_PORTB,7,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,4,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,5,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,6,OUTPUT);
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void led_on(led_ID id)
{
	switch(id)
	{
		case led1:
		// if(led_source)
		 dio_vidWriteChannel(DIO_PORTB,7,led1_state);
		// else 
		// dio_vidWriteChannel(DIO_PORTB,7,STD_LOW);
		break ;
		case led2:
		//if(led_source)
		dio_vidWriteChannel(DIO_PORTA,4,led2_state);
		//else
		//dio_vidWriteChannel(DIO_PORTA,4,STD_LOW);
		break ;
		case led3:
		//if(led_source)
		dio_vidWriteChannel(DIO_PORTA,5,led3_state);
		//else
		//dio_vidWriteChannel(DIO_PORTA,5,STD_LOW);
		break ;
		case led4:
		//if(led_source)
		dio_vidWriteChannel(DIO_PORTA,6,led4_state);
		//else
		//dio_vidWriteChannel(DIO_PORTA,6,STD_LOW);
		break ;
		
	}
}



void led_off(led_ID id)
{
	switch(id)
	{
		case led1:
		if(led_source)
		dio_vidWriteChannel(DIO_PORTB,7,STD_LOW);
		else
		dio_vidWriteChannel(DIO_PORTB,7,STD_HIGH);
		break ;
		case led2:
		if(led_source)
		dio_vidWriteChannel(DIO_PORTA,4,STD_LOW);
		else
		dio_vidWriteChannel(DIO_PORTA,4,STD_HIGH);
		break ;
		case led3:
		if(led_source)
		dio_vidWriteChannel(DIO_PORTA,5,STD_LOW);
		else
		dio_vidWriteChannel(DIO_PORTA,5,STD_HIGH);
		break ;
		case led4:
		if(led_source)
		dio_vidWriteChannel(DIO_PORTA,6,STD_LOW);
		else
		dio_vidWriteChannel(DIO_PORTA,6,STD_HIGH);
		break ;
		
	}
	
}


void led_toggle(led_ID id)
{
	switch(id)
	{
		case led1:
		dio_vidFlipChannel(DIO_PORTB,7);
		break ;
		case led2:
		dio_vidFlipChannel(DIO_PORTA,4);
		break ;
		case led3:
		dio_vidFlipChannel(DIO_PORTA,5);
		break ;
		case led4:
		dio_vidFlipChannel(DIO_PORTA,6);
		break ;
		
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
