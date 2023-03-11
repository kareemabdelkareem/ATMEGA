/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_Types.h"
#include "Bit_Math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h" 
#include "dio_reg.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	  
	   //clear registers 
	   ADCSRA = 0;
	   ADMUX = 0;
	   // set  avcc as refrence and percision 
	   ADMUX |= AVCC |ADC_Percision;
	   // set prescaler 
	   ADCSRA |=ADC_PRESCALLER ;
	  
	   ADC_voidEnable();
	   
	   #if ADC_MODE ==ADC_AUTO_TRIGGER_SOURCE 
	   ADC_voidAutoTrigger() ;
	   	ADC_voidInterrputEnable();
	   #elif  ADC_MODE == ADC_INTERRUPT
	   	ADC_voidInterrputEnable();
	   #endif
	   
	    
	
	/* End ( if ) condition for Macros */	
	
	
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	 // enable adcinterrupt 
	SET_BIT( ADCSRA , ADIE );
	// enable global interrupt 
	SET_BIT(SREG,7) ;
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
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

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 5);
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7);
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 5);
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 5);
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR ,  7);

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 5);
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 channel)
{  
     // clear audmux then input channel 
	ADMUX &= 0b11100000;
	ADMUX |=  (channel & 0x0f);
			
	ADC_voidStartConversion();
		
	// check for the ADC flag pooling 
	while(CHECK_BIT(ADCSRA,ADIF)==0);
	// clear the adc flag by set one to it 
	SET_BIT(ADCSRA,ADIF);
		
			
	#if ADC_Percision == TEN_BITPERCISION
	   return (ADC * 5000UL / 1023);  // value in MV 
	
	#elif ADC_Percision ==EIGHT_BITPERCISION
	return  (ADCH * 5000UL / 1023) ;
	 
	 #endif
	
}




/****************************************************************/
/* Description    : This function used to Read ADC after  intterupt	*/
/*																*/
/*					Inputs : u8 channel	 of the ADC				  	*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized and enable global interrupt
                      and enable adc interrupt              	  */
/****************************************************************/

u16  ADC_u16ReadADCIninterrupt(  u8 channel )
{    
	// select channel 
	 ADMUX &= 0b11100000;
	 ADMUX |=  (channel & 0x0f);

	  
	  #if ADC_Percision == TEN_BITPERCISION
	  return (ADC * 5000UL / 1023);  // value in MV
	  
	  #elif ADC_Percision ==EIGHT_BITPERCISION
	  return  (ADCH * 5000UL / 1023) ;
	  
	  #endif
	
	}
	
	
	
	void ADC_voidCallBack(pf addresscpy)
	{
		if(addresscpy != NULL)
		{
			p_ADC= addresscpy;
		}
	}
	
	void __vector_16(void)
	{  	
			p_ADC();	
	}
	
	
	/****************************************************************/
	/* Description    : This function used to Read all ADC channels	*/
	/*																*/
	/*					Inputs : u8 result of array	 of the ADC				  	*/
	/*					Return : u16 Digital Converting melli Volt	*/
	/****************************************************************/
	/* Pre_condition  :  this function must be used after ADC 		*/
	/*     				 initialized and enable global interrupt			  */
	/****************************************************************/
	
	void  ADC_u16ReadADCChannels(  u16 result[])
	{   result[0]= ADC_u16ReadADCInMV(0) ;
		result[1]= ADC_u16ReadADCInMV(1) ;
		result[2]= ADC_u16ReadADCInMV(2) ;
		result[3]= ADC_u16ReadADCInMV(3) ;
		result[4]= ADC_u16ReadADCInMV(4) ;
		result[5]= ADC_u16ReadADCInMV(5) ;
		result[6]= ADC_u16ReadADCInMV(6) ;
		result[7]= ADC_u16ReadADCInMV(7) ;
	}
	

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/