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
#include "dio.h"
#include "lcd.h"
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

void lcd_init(void)
{
		dio_vidConfigChannel(LCD_PORT,LCD_PIN4,OUTPUT);
		dio_vidConfigChannel(LCD_PORT,LCD_PIN5,OUTPUT);
		dio_vidConfigChannel(LCD_PORT,LCD_PIN6,OUTPUT);
		dio_vidConfigChannel(LCD_PORT,LCD_PIN7,OUTPUT);

	dio_vidConfigChannel(RS_PORT,RS_PIN,OUTPUT);
	dio_vidConfigChannel(EN_PORT,EN_PIN,OUTPUT);
	_delay_ms(DELAY_POWER_UP);
	lcd_sendCmd(CMD_retrun_home) ;
	lcd_sendCmd(CMD_4bit_mode) ;
	lcd_sendCmd(CMD_Display_on) ;
	lcd_sendCmd(CMD_Clear_display) ;
}


void lcd_sendCmd(lcd_Cmd_Type cmd)
{
	dio_vidWriteChannel(RS_PORT,RS_PIN,STD_LOW);
	
	dio_vidWriteChannel(LCD_PORT,LCD_PIN7,CHECK_BIT(cmd,7));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN6,CHECK_BIT(cmd,6));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN5,CHECK_BIT(cmd,5));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN4,CHECK_BIT(cmd,4));
	
	lcd_Enable_pulse();
	
 
	
			dio_vidWriteChannel(LCD_PORT,LCD_PIN7,CHECK_BIT(cmd,3));
			dio_vidWriteChannel(LCD_PORT,LCD_PIN6,CHECK_BIT(cmd,2));
			dio_vidWriteChannel(LCD_PORT,LCD_PIN5,CHECK_BIT(cmd,1));
			dio_vidWriteChannel(LCD_PORT,LCD_PIN4,CHECK_BIT(cmd,0));
		
		lcd_Enable_pulse();
		

}
void lcd_sendData(u8 data)
{
	
	
	dio_vidWriteChannel(RS_PORT,RS_PIN,STD_HIGH);
	
	dio_vidWriteChannel(LCD_PORT,LCD_PIN7,CHECK_BIT(data,7));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN6,CHECK_BIT(data,6));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN5,CHECK_BIT(data,5));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN4,CHECK_BIT(data,4));
	
	lcd_Enable_pulse();
	
	dio_vidWriteChannel(LCD_PORT,LCD_PIN7,CHECK_BIT(data,3));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN6,CHECK_BIT(data,2));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN5,CHECK_BIT(data,1));
	dio_vidWriteChannel(LCD_PORT,LCD_PIN4,CHECK_BIT(data,0));
	lcd_Enable_pulse();
	

}

void lcd_Enable_pulse(void) 
{
	dio_vidWriteChannel(EN_PORT,EN_PIN,STD_HIGH);
	_delay_ms(2);
	dio_vidWriteChannel(EN_PORT,EN_PIN,STD_LOW);
	_delay_ms(2);
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
