
#ifndef lcd
#define lcd
#include "dio.h"
#include <util/delay.h>


#define		UPPER			1 
#define		LOWER			0 
#define		LCD_PORT		DIO_PORTB 
#define		LCD_CHANNELS	UPPER 
#define		RS_PORT			DIO_PORTA 
#define		RS_PIN			DIO_PIN0
#define		EN_PORT			DIO_PORTA 
#define		EN_PIN			DIO_PIN1
#define     LCD_PIN7        DIO_PIN7
#define     LCD_PIN6        DIO_PIN6
#define     LCD_PIN5        DIO_PIN5
#define     LCD_PIN4        DIO_PIN4

#define DELAY_POWER_UP 35
#define DELAY_PULSE 2




typedef enum {
		CMD_4bit_mode	=	0x28,
		CMD_retrun_home	 =	0x02,
		CMD_Display_on	=	0x0E,
		CMD_Clear_display =	0x01
	}lcd_Cmd_Type;


void lcd_init(void);
void lcd_sendData(u8 data);
void lcd_sendCmd(lcd_Cmd_Type cmd);
void lcd_gotoRowColumn(u8 row, u8 column);
void lcd_displyChar(u8 chr);
void lcd_displyStr(u8* str);
void lcd_customWrite(u8* custCfg);
void lcd_Enable_pulse(void) ;


#endif