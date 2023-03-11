/*
 * keypad_conf.h
 *
 * Created: 3/2/2023 5:46:39 PM
 *  Author: PC
 */ 


#ifndef KEYPAD_CONF_H_
#define KEYPAD_CONF_H_


#include "std_types.h"
#define ROW_PORT DIO_PORTC
#define COLUMN_PORT DIO_PORTD

#define R1 DIO_PIN5
#define R2 DIO_PIN4
#define R3 DIO_PIN3
#define R4 DIO_PIN2

#define C1 DIO_PIN7
#define C2 DIO_PIN6
#define C3 DIO_PIN5
#define C4 DIO_PIN3

#define ROW_NUM 4
#define COL_NUM 4



u8 keypad_buttons[COL_NUM][ROW_NUM] = { {1,2,3,'A'},
	                               {4,5,6,'B'},
								   {7,8,9,'C'},
								   {'*',0,'#','D'} } ;
u8 keypad_row_pin[4]={R1,R2,R3,R4};
u8 keypad_col_pin[4]={C1,C2,C3,C4};	


#endif /* KEYPAD_CONF_H_ */