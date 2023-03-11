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
#include "button.h"
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
void button_init(void)
{
	dio_vidConfigChannel(DIO_PORTD,7,INPUT);
	if(button1_conn== button_pullup)
		{dio_vidEnablePullUp(DIO_PORTD,7);}
		
	dio_vidConfigChannel(DIO_PORTD,6,INPUT);
	if(button2_conn== button_pullup)
		{dio_vidEnablePullUp(DIO_PORTD,6);}
		
	dio_vidConfigChannel(DIO_PORTD,5,INPUT);
	if(button3_conn== button_pullup)
		{dio_vidEnablePullUp(DIO_PORTD,5);}
		
	dio_vidConfigChannel(DIO_PORTD,3,INPUT);
	if(button4_conn== button_pullup)
		{dio_vidEnablePullUp(DIO_PORTD,3);}
}

button_state button_get_states(button_ID button_id)
{  
	switch(button_id)
	{
		case button1 :
			if(button1_conn==button_pulldown)
				{return dio_dioLevelReadChannel(DIO_PORTD,7);}
			else 
				return !(dio_dioLevelReadChannel(DIO_PORTD,7));
		
		break ;
		
	    case button2 :
			if(button2_conn==button_pulldown)
				return dio_dioLevelReadChannel(DIO_PORTD,6);
			else 
				return !(dio_dioLevelReadChannel(DIO_PORTD,6));
		
	    break ;
		
	    case button3 :
		if(button3_conn==button_pulldown)
			return dio_dioLevelReadChannel(DIO_PORTD,5);
		else 
			return !(dio_dioLevelReadChannel(DIO_PORTD,5));
				break ;
				
		case button4 :
		if(button4_conn==button_pulldown)
				return dio_dioLevelReadChannel(DIO_PORTD,3);
		else 
			return !dio_dioLevelReadChannel(DIO_PORTD,3);
					break ;
		
	}

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
