/*
 * Stepper_conf.c
 *
 * Created: 3/2/2023 3:07:17 PM
 *  Author: kareem
 contain stepper Motors Pins configuration*/
 /*             							[config.c] 				*/
 /*								Link time configuration	in 		*/
 /*										build process
  
 */ 




#include "Stepper_conf.h"


/*****************************************************************/
/* !comment : Array of struct ( Stepper Motors )      	 	 */
/*****************************************************************/


StepperMotor ArrayOfMotor [NUM__OF_STEPPERS]=
{  {DIO_PORTD,DIO_PIN0 ,DIO_PORTD,DIO_PIN1,DIO_PORTD,DIO_PIN2,DIO_PORTD,DIO_PIN3 }
	
	};
	
	/***********************************************************************************************/
	/************************************* END OF PROGRAM ******************************************/
	/***********************************************************************************************/