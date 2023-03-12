/*
 * i2c_play.c
 *
 * Created: 3/5/2023 2:58:00 PM
 *  Author: PC
 */ 



#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

#include "DIO_private.h"

// master code 
/*
int main(void)
{
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	
	I2C_Master_voidInit();
	I2C_Error_State Error=I2C_OK;
	while (1)
	{
		Error =I2C_Master_enuSendStartCond();
		Error=I2C_Master_enuSendSlaveAddressWithWrite(0x10);
		if(Error==I2C_OK)
		{
			Error=I2C_Master_enuSendu8Data('A');
			
		}
		if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			Error=I2C_Master_enuSendu8Data('H');
		}
		else if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			Error=I2C_Master_enuSendu8Data('L');
		}
		
	
	}
}
*/



// slave code 
int main(void)
{
    DIO_voidSetPinDirection(PORTA,0,OUTPUT) ;
	u8 read  = 0 ;
	//I2C_Master_voidInit();
	I2C_Slave_voidInit(0x10) ;
	I2C_Error_State Error=I2C_OK;
	while (1)
	{
		//Error =I2C_Master_enuSendStartCond();
		I2C_Slave_voidListen();
		Error=I2C_Slave_enuReadu8Data(&read) ;
		//Error=I2C_Master_enuSendSlaveAddressWithWrite(0x10);
		
		if(read == 'b')   DIO_voidSetPinValue(PORTA,0,HIGH) ;
		if(Error==I2C_OK)
		{
			Error=I2C_Master_enuSendu8Data('A');
			
		}
		if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			Error=I2C_Master_enuSendu8Data('H');
		}
		else if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			Error=I2C_Master_enuSendu8Data('L');
		}
	}
}

