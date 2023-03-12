/*
 * I2C.c
 *
 * Created: 3/5/2023 3:03:03 PM
 *  Author: PC
 */ 


#include "I2C.h"






void I2C_MasterInit(u8 addr)
{
	
}
void I2C_SlaveInit(u8 addr);
boolean I2C_StartCondition(void);
boolean I2C_RepeatedStartCondition(void);
void I2C_StopCondition(void);
void I2C_WriteByte(u8 data);
boolean I2C_Send_SlaveAddressWriteOperation(u8 addr);
boolean I2C_Send_SlaveAddressReadOperation(u8 addr);
u8 I2C_ReadByte(void);
u8 I2C_ReadStatus(void)
{
	return ;
}