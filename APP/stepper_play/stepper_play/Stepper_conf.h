/*
 * Stepper_conf.h
 *
 * Created: 3/2/2023 3:07:28 PM
 *  Author: kareem
 /*	 Description 		:   contain Stepper Motors Numbers config	*/
 /*             							[config.h] 		        */
 /****************************************************************/
 


#ifndef STEPPER_CONF_H_
#define STEPPER_CONF_H_

#include "dio.h"
#include "std_types.h"
#include "bit_math.h"



#define NUM__OF_STEPPERS   1 

typedef struct stepper
{
	
	/**  port and pin for each motor wires 
		*/
	u8 port_of_pin1 ;
	u8 pin1;
	u8 port_of_pin2 ;
	u8 pin2;
	u8 port_of_pin3 ;
	u8 pin3;
	u8 port_of_pin4 ;
	u8 pin4;

}StepperMotor;







#endif /* STEPPER_CONF_H_ */