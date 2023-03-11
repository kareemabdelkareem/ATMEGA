
#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV




#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR0 	 (*(volatile u8 * )0x5C)
#define TCCR0	 (*(volatile u8 * )0x53)
#define TCNT0	 (*(volatile u8 * )0x52)
#define TIFR	 (*(volatile u8 * )0x58)

#define DIO_DDRB_REG   	(*(volatile u8*)(0x37))





#endif
