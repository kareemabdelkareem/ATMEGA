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
#include "SSD.h"
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
void SSD_vidInit()
{
	dio_vidConfigChannel(SSD_port,SSD_pin0,OUTPUT);
	dio_vidConfigChannel(SSD_port,SSD_pin1,OUTPUT);
	dio_vidConfigChannel(SSD_port,SSD_pin2,OUTPUT);
	dio_vidConfigChannel(SSD_port,SSD_pin3,OUTPUT);
	
	dio_vidConfigChannel(SSD_Enable1_port,SSD_Enable1_pin,OUTPUT);
	dio_vidConfigChannel(SSD_Enable2_port,SSD_Enable2_pin,OUTPUT);
	dio_vidConfigChannel(SSD_Enable3_port,SSD_Enable3_pin,OUTPUT);
	dio_vidConfigChannel(SSD_Enable4_port,SSD_Enable4_pin,OUTPUT);
	
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
void SSD_DisplayNum(u16 num) 
{
	u8 num1 = num % 10  ;
	num = num /10 ;
	u8 num2 = num %10 ;
	num = num/10 ;
	u8 num3 = num %10 ; 
	num = num/10 ;
	u8 last_num = num %10 ;
	//enable fisrst digit 
	dio_vidWriteChannel(SSD_Enable1_port,SSD_Enable1_pin,STD_HIGH) ;
	
	dio_vidWriteChannel(SSD_port,SSD_pin0,CHECK_BIT(num1,0)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin1,CHECK_BIT(num1,1)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin2,CHECK_BIT(num1,2)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin3,CHECK_BIT(num1,3)) ;
	
	_delay_ms(1);
	dio_vidWriteChannel(SSD_Enable1_port,SSD_Enable1_pin,STD_LOW) ;
	
	// enable seconde digit 
	dio_vidWriteChannel(SSD_Enable2_port,SSD_Enable2_pin,STD_HIGH) ;
	
	dio_vidWriteChannel(SSD_port,SSD_pin0,CHECK_BIT(num2,0)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin1,CHECK_BIT(num2,1)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin2,CHECK_BIT(num2,2)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin3,CHECK_BIT(num2,3)) ;
	
	_delay_ms(1);
	dio_vidWriteChannel(SSD_Enable2_port,SSD_Enable2_pin,STD_LOW) ;
		
	// enable seconde digit
	dio_vidWriteChannel(SSD_Enable3_port,SSD_Enable3_pin,STD_HIGH) ;
		
	dio_vidWriteChannel(SSD_port,SSD_pin0,CHECK_BIT(num3,0)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin1,CHECK_BIT(num3,1)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin2,CHECK_BIT(num3,2)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin3,CHECK_BIT(num3,3)) ;
	
	
	_delay_ms(1);
	dio_vidWriteChannel(SSD_Enable3_port,SSD_Enable3_pin,STD_LOW) ;
		
	// enable seconde digit
	dio_vidWriteChannel(SSD_Enable4_port,SSD_Enable4_pin,STD_HIGH) ;
		
	dio_vidWriteChannel(SSD_port,SSD_pin0,CHECK_BIT(last_num,0)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin1,CHECK_BIT(last_num,1)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin2,CHECK_BIT(last_num,2)) ;
	dio_vidWriteChannel(SSD_port,SSD_pin3,CHECK_BIT(last_num,3)) ;
	
	_delay_ms(1);
	dio_vidWriteChannel(SSD_Enable4_port,SSD_Enable4_pin,STD_LOW) ;
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
