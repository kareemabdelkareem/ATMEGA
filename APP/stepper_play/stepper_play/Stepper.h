/*
 * Stepper.h
 *
 * Created: 3/2/2023 3:06:38 PM
 *  Author: PC
 */ 


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef STEPPER_H_
#define STEPPER_H_


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/
#define F_CPU 8000000
#include "util/delay.h"
#include "Stepper_conf.h"
/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "dio.h"



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : StepperMotor_init This function used to initialize stepper motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
void StepperMotor_voidinit(void) ;

/****************************************************************/
/* Description    :  This function used to start step clockwise of the stepper  */
/*					 Inputs : motor number we used, 
                         note start from 0		 					*/
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after stepper  */
/*     				 initialized								*/

void StepperMotor_viodrotateCW(u8 motor_num);
/* Description    :  This function used to start step Anticlockwise of the stepper  */
/*					 Inputs : motor number we used, 
                         note start from 0		 					*/
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after stepper  */
/*     				 initialized								*/
/****************************************************************/
void StepperMotor_viodrotateACW(u8 motor_num);

extern StepperMotor ArrayOfMotor [ NUM__OF_STEPPERS ] ;

#endif /* STEPPER_H_ */