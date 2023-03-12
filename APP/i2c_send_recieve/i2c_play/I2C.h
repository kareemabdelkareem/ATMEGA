



#ifndef I2C_H
#define I2C_H


#include "bit_math.h"
#include "Std_Types.h"
#include "DIO_interface.h"



#define TWSR (*(volatile u8*)(0x21))
#define TWBR (*(volatile u8*)(0x20))
#define TWCR (*(volatile u8*)(0x56))
#define TWDR (*(volatile u8*)(0x23))
#define TWAR (*(volatile u8*)(0x22))


#define  START_ACK  0x08       // start has been sent 
#define  REP_START_ACK 0x10        // reapeted start 
#define  SLAVE_ADD_AND_WR_ACK 0x18
#define  MASTER_BYTE_WR_ACK 0x28

#define  MASTER_R_BYTE_ACK 0x50


void I2C_MasterInit(u8 addr);
void I2C_SlaveInit(u8 addr);
boolean I2C_StartCondition(void);
boolean I2C_RepeatedStartCondition(void);
void I2C_StopCondition(void);
void I2C_WriteByte(u8 data);
boolean I2C_Send_SlaveAddressWriteOperation(u8 addr);
boolean I2C_Send_SlaveAddressReadOperation(u8 addr);
u8 I2C_ReadByte(void);
u8 I2C_ReadStatus(void);




#endif
