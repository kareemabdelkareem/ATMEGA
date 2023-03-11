/*
 * Stepper.c
 *
 * Created: 3/2/2023 3:06:54 PM
 *  Author: kareem
 */ 


/****************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "Stepper.h"



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : StepperMotor_init This function used to initialize stepper motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/


void StepperMotor_voidinit(void) 
{
	u8 u8motor_num = 0 ;
	for (u8motor_num=0 ;u8motor_num<NUM__OF_STEPPERS ;u8motor_num++)
	{
		dio_vidConfigChannel(ArrayOfMotor[u8motor_num].port_of_pin1, ArrayOfMotor[u8motor_num].pin1 , OUTPUT);
		dio_vidConfigChannel(ArrayOfMotor[u8motor_num].port_of_pin2, ArrayOfMotor[u8motor_num].pin2 , OUTPUT);
		dio_vidConfigChannel(ArrayOfMotor[u8motor_num].port_of_pin3, ArrayOfMotor[u8motor_num].pin3 , OUTPUT);
		dio_vidConfigChannel(ArrayOfMotor[u8motor_num].port_of_pin4, ArrayOfMotor[u8motor_num].pin4 , OUTPUT);
	}
}


/****************************************************************/
/* Description    :  This function used to start step clockwise of the stepper  */
/*					 Inputs : motor number we used, 
                         note start from 0		 					*/
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after stepper  */
/*     				 initialized								*/
/****************************************************************/
void StepperMotor_viodrotateCW(u8 motor_num)
{
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);               // step1 
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);                   //step2
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);                
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);                //step 3 
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);              //step4
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);                //step5
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);               //step6
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);               //step7
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);                 //step8
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
}


/* Description    :  This function used to start step Anticlockwise of the stepper  */
/*					 Inputs : motor number we used, 
                         note start from 0		 					*/
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after stepper  */
/*     				 initialized								*/
/****************************************************************/
void StepperMotor_viodrotateACW(u8 motor_num)
{
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);                 //step1
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);               //step2
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);               //step3
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);                //step4
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);              //step5
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_LOW);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_HIGH);                //step 6
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(100);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);                   //step7
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(50);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin1 ,ArrayOfMotor[motor_num].pin1,STD_HIGH);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin2 ,ArrayOfMotor[motor_num].pin2,STD_LOW);
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin3 ,ArrayOfMotor[motor_num].pin3,STD_LOW);               // step8
	dio_vidWriteChannel(ArrayOfMotor[motor_num].port_of_pin4 ,ArrayOfMotor[motor_num].pin4,STD_HIGH);
	_delay_ms(50);
}



/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/