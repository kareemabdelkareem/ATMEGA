/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "uart.h"
#include "uart_reg.h"
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
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/





void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;
	UART_UBRRH_REG = (u8)(baudRate>>8);

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;    // (1 << URSEL_BIT_NO) to select between  UART_UCSRC_REG and  UART_UBRRH_REG

	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/
void UART_TransmitChr(u8 data)
{
	/* Put data into buffer*/
	while (CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)==0) ;
	UART_UDR_REG = data;
	
	
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{  // while (CHECK_BIT(UART_UCSRA_REG,7)==0 ) ;
	if(CHECK_BIT(UART_UCSRA_REG,7))
	{
		return UART_UDR_REG;
	}	
	else
	{
		return 0 ;
	}			
		
}

/******************************************************************************
* \Syntax          : u8 UART_TransmitStr(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : u8     transmite data
*******************************************************************************/

void UART_TransmitStr(u8 *str)
{    
	while (*str != NULL)
	{ 
		UART_TransmitChr(str[0]) ; 
		str++ ; 
	}
}



// buffer of transmitted data 
u8 Uart_tx_buff[Max_size];
u16 byte_index = 0 ;

u16 recieve_index = 0 ;
//buffer of the received data 
u8 Uart_rx_buff[Max_size];
u8 recieve_flag = 0 ;

void UART_TransmitStr_INTERRUPT(u8 *str)
{   u16 i  = 0 ;
    byte_index =0 ;
	while (str[i] != NULL)
	{
		Uart_tx_buff[i] =  str[i]  ;
				i++ ;
	}
	Uart_tx_buff[i] = NULL ;
	UART_UDR_REG = Uart_tx_buff[byte_index] ; 
	
}



void __vector_15(void) __attribute__(( signal , used ));

void __vector_15(void)
{
	byte_index++;
	if( Uart_tx_buff[byte_index]!= NULL || byte_index>=Max_size )
	{
		UART_UDR_REG = Uart_tx_buff[byte_index] ;
	}
	else
	{
		byte_index = 0 ;
	}
}

/******************************************************************************
* \Syntax          : u8 UART_Recieve_is_ready(void)
* \Description     : check if the there is data recieved 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : u8    
*******************************************************************************/
u8 UART_Recieve_is_ready(void) 
{
	
	if(recieve_flag)
	{   
		recieve_flag = 0 ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

/* make the pointer from main to point to buffer instead of copy the data */
void UART_RecieveStr_int( u8 ** str)
{
	*str = Uart_rx_buff ;
	
}


/*ISR fun of rx_recieve flag */
void __vector_13(void) __attribute__(( signal , used ));
void __vector_13(void)
{     
	Uart_rx_buff[recieve_index] = UART_UDR_REG ;
	
	 if(Uart_rx_buff[recieve_index] == LAST_KEY || recieve_index>=Max_size )    // 13 == enter in protus 
	{    
        //led_on(led1) ;
		Uart_rx_buff[recieve_index] =  NULL; // insert null at last of the string 
		recieve_flag = 1 ;                    // raise flag 
		recieve_index = 0 ;                   // reset the index to start of the buffer 
	}
	recieve_index++ ;
	
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/