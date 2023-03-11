/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for EXT0		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/


//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI_int.h"



/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT0_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXTI0_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#elif EXTI0_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXTI0_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXTI0_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;
	
	SET_BIT(SREG,7);
	
	
}

void EXT1_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXTI1_SENSE_MODE == IOC
	SET_BIT(MCUCR , 1);
	CLEAR_BIT(MCUCR , 2);
	
	#elif EXTI1_SENSE_MODE == RISING
	SET_BIT(MCUCR , 1);
	SET_BIT(MCUCR , 2);
	
	#elif EXTI1_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 1);
	SET_BIT(MCUCR , 2);
	
	#elif EXTI1_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 1);
	CLEAR_BIT(MCUCR , 2);
	
	
	
	#endif
	/* End ( if ) condition for Macros */

	
	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 7 );
	SET_BIT(GIFR , 7 ) ;
	
	SET_BIT(SREG,7);
	
	
}
void EXT2_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	
	
	#if EXTI2_SENSE_MODE ==  FALLING
	CLEAR_BIT(MCUCSR , 6);
	#elif EXTI2_SENSE_MODE == RISING
	SET_BIT(MCUCSR , 6);
	#endif
	/* End ( if ) condition for Macros */
	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 5 );
	SET_BIT(GIFR , 5 ) ;
	
	SET_BIT(SREG,7);
	
	
}
/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/






/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidEnable()
{
	
	SET_BIT( GICR , 6 );
	
}

void EXT1_voidEnable()
{
	
	SET_BIT( GICR , 7 );
	
}

void EXT2_voidEnable()
{
	
	SET_BIT( GICR , 5);
	
}

/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidDisable()
{
	
	CLEAR_BIT( GICR , 6 );
	
}

void EXT1_voidDisable()
{
	
	CLEAR_BIT( GICR , 7);
	
}
void EXT2_voidDisable()
{
	
	CLEAR_BIT( GICR , 5);
	
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidCallBack(pf addresscpy_in0)
{
	if(addresscpy_in0 != NULL)
	{
		x = addresscpy_in0;
	}
}


void EXT1_voidCallBack(pf addresscpy_int1)
{
	if(addresscpy_int1 != NULL)
	{
		y = addresscpy_int1;
	}
}

void EXT2_voidCallBack(pf addresscpy_int2)
{
	if(addresscpy_int2 != NULL)
	{
		z = addresscpy_int2;
	}
}

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT0_voidSetSignalch(u8 SenseCpy)
{
	
if (SenseCpy == IOC)
{
	SET_BIT(MCUCR , 0);
CLEAR_BIT(MCUCR , 1);
}
else if (SenseCpy == RISING)
{
SET_BIT(MCUCR , 0);
SET_BIT(MCUCR , 1);
}
else if (SenseCpy == FALLING)
{
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
}

else if (SenseCpy == LOW_LEVEL)
{
	
CLEAR_BIT(MCUCR , 0);
CLEAR_BIT(MCUCR , 1);
}

void EXT1_voidSetSignalch(u8 SenseCpy)
{
	

	if (SenseCpy == IOC)
	{
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 2);
	}
	else if (SenseCpy == RISING)
	{
		SET_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 2);
	}
	else if (SenseCpy == FALLING)
	{
		CLEAR_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 2);
	}

	else if (SenseCpy == LOW_LEVEL)
	{
		
		CLEAR_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 2);
	}

	
}

void EXT2_voidSetSignalch(u8 SenseCpy)
{
	
	if(EXTI2_SENSE_MODE == RISING)
	{
		CLEAR_BIT(MCUCSR , 6);
	}
	
	else if( EXTI2_SENSE_MODE == FALLING)
	{
		SET_BIT(MCUCSR , 6);
	}		
	


	
}
/* End ( if ) condition for Macros */


/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */

	
}

/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void )
{
	flagStatus ErrorStatus ;
	
	if( (GET_BIT(GIFR, 6)) == 1 )
	{
		
		ErrorStatus = LBTY_NOK ;
	}
	else if ( (GET_BIT(GIFR, 6)) == 0 )
	{
		
		ErrorStatus = LBTY_OK ;
	}
	
	return ErrorStatus ;
}
*/
/** Linker Problem solved */



void __vector_1(void)
{
	x();
	
}

void __vector_2(void)
{
	y();
	
}
void __vector_3(void)
{
	z();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/