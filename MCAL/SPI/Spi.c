/*
 * Spi.c
 *
 * Created: 3/4/2023 1:15:13 PM
 *  Author: PC
 */ 


#include "Spi.h"




void Spi_master_init(void)
{   SPCR_REG = 0x00;
	SET_BIT(DIO_DDRB_REG,4);
	SET_BIT(DIO_DDRB_REG,5);
	SET_BIT(DIO_DDRB_REG,7);
	CLEAR_BIT(DIO_DDRB_REG,6);
	SET_BIT(DIO_PORTB_REG,4);
	
	SPCR_REG |= (1<<SPE)|(1<<MSTR)|DATA_ORDER | (SPI_CLK & 0b00000011);
	SPSR_REG  |=  (SPI_CLK>>2) ;
	
	#if INTERRUPT_STATE == ENABLE_INTERRUPT 
		SET_BIT(SPCR_REG , SPIE);
	#elif INTERRUPT_STATE==DISABLE_INTERRUPT
		CLEAR_BIT(SPCR_REG , SPIE);
	#endif


}	

void Spi_slave_init()
{   SPCR_REG = 0x00;
	CLEAR_BIT(DIO_DDRB_REG,4);
	CLEAR_BIT(DIO_DDRB_REG,5);
	CLEAR_BIT(DIO_DDRB_REG,7);
	SET_BIT(DIO_DDRB_REG,6);
	SPCR_REG = (1<<SPE);
	
	#if INTERRUPT_STATE == ENABLE_INTERRUPT
	SET_BIT(SPCR_REG , SPIE);
	#elif INTERRUPT_STATE==DISABLE_INTERRUPT
	CLEAR_BIT(SPCR_REG , SPIE);
	#endif
	
	
	
}	


u8 Spi_Master_Transieve_byte(u8 data) 
{
	CLEAR_BIT(DIO_PORTB_REG ,4);
	SPDR_REG = data;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<SPIF)));
	return  SPDR_REG ;
}	

u8 Spi_slave_recieve(void) 
{
	     //SPDR_REG = DUMMY_DATA ;
		/* Wait for reception complete */
		while(!(SPSR_REG & (1<<SPIF))) ;
		
		/* Return data register */
		return SPDR_REG;
}

u8 Spi_slave_transmit_byte(u8 Data ) 
{
	
	/* Start transmission */
	SPDR_REG = Data;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<SPIF))) ;
	return SPSR_REG ;
}


 u8* pointer = NULL;
  
void Spi_recieve_ISR(u8 *p)
{
	
	pointer = p;
}	
  
u8 recieve_var = 0 ;
void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
   if(pointer != NULL)
	 
	 { 
		 *pointer =  SPDR_REG ;
	 }		 

}




