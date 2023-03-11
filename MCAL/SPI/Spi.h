/*
 * Spi.h
 *
 * Created: 3/4/2023 1:15:28 PM
 *  Author: PC
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "bit_math.h"
#include "Std_Types.h"
#include "dio_reg.h"
#include "dio.h"
#define  SPCR_REG     (*(volatile u8*)(0x2D))
#define  SPSR_REG     (*(volatile u8*)(0x2E))
#define  SPDR_REG       (*(volatile u8*)(0x2F))

#define SPE 6
#define  MSTR 4
#define  SPR0 0
#define  SPR1 1
#define  SPIF  7
#define  SPIE  7
#define  SPI2X 0


#define LSB_FIRST 0b00100000
#define  MSB_FIRST 0b00000000
#define  DUMMY_DATA 255


#define DATA_ORDER   MSB_FIRST

#define SPI_CLK_FCPU_4   0
#define SPI_CLK_FCPU_16   1
#define SPI_CLK_FCPU_64    2
#define SPI_CLK_FCPU_128   3
#define SPI_CLK_FCPU_2     4
#define SPI_CLK_FCPU_8     5
#define SPI_CLK_FCPU_32   6


#define SPI_CLK    SPI_CLK_FCPU_16

#define CLOCK_PHASE_RISING  0
#define CLOCK_PHASE_FALLING  1
#define CLOCK_TYPE_SAMPLE  2
#define CLOCK_TYPE_SETUP 2


#define CLOCK_PHASE   CLOCK_PHASE_RISING
#define CLOCK_TYPE CLOCK_TYPE_SAMPLE


#define  ENABLE_INTERRUPT  1 
#define  DISABLE_INTERRUPT  0
#define  INTERRUPT_STATE  ENABLE_INTERRUPT 


void Spi_master_init(void);
void Spi_slave_init(void);
u8 Spi_Master_Transieve_byte(u8 data) ;
u8 Spi_slave_recieve(void) ;
u8 Spi_slave_transmit_byte(u8 data ) ;

void Spi_recieve_ISR(u8 *p) ; 
#endif /* SPI_H_ */