
#include "LCD.h"
#ifndef F_CPU
#define  F_CPU 8000000UL
#endif
#include <util/delay.h>
#include <stdio.h>
#include "STD_Types.h"
#ifdef LCD_TRACK_POS
u8 xpos = 0;
u8 ypos = 0;
#endif
void LCD_vInit(void)
{
#ifdef LCD_TRACK_POS
    xpos = 0;
    ypos = 0;
#endif
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_SetPinDirection(0,0,1);
	DIO_SetPinDirection(0,1,1);
	DIO_SetPinDirection(0,2,1);
	DIO_SetPinDirection(0,3,1);
	DIO_SetPinDirection(0,4,1);
	DIO_SetPinDirection(0,5,1);
	DIO_SetPinDirection(0,6,1);
	DIO_SetPinDirection(0,7,1);
	DIO_SetPinDirection(1,EN,1);
	DIO_SetPinDirection(1,RW,1);
	DIO_SetPinDirection(1,RS,1);
	DIO_SetPinValue(1,RW,0);
	LCD_vSend_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1); 
	
	#elif defined four_bits_mode
	DIO_SetPinDirection(0,4,1);
	DIO_SetPinDirection(0,5,1);
	DIO_SetPinDirection(0,6,1);
	DIO_SetPinDirection(0,7,1);
	DIO_SetPinDirection(1,EN,1);
	DIO_SetPinDirection(1,RW,1);
	DIO_SetPinDirection(1,RS,1);
   	DIO_SetPinValue(1,RW,0);
	LCD_vSend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}


static void send_falling_edge(void)
{
	DIO_SetPinValue(1,EN,1);
	_delay_ms(2);
	DIO_SetPinValue(1,EN,0);
	_delay_ms(2);
}
void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_SetPortValue(0,cmd);
	DIO_SetPinValue(1,RS,0);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(0,cmd>>4);
	DIO_SetPinValue(1,RS,0);
	send_falling_edge();
	write_high_nibble(0,cmd);
	DIO_SetPinValue(1,RS,0);
	send_falling_edge();
	#endif
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_SetPortValue(0,data);
	DIO_SetPinValue(1,RS,1);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(0,data>>4);
	DIO_SetPinValue(1,RS,1);
	send_falling_edge();
	write_high_nibble(0,data);
	DIO_SetPinValue(1,RS,1);
	send_falling_edge();
	#endif
	_delay_ms(1);
}


void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void lcd_set_cursor(u8 x, u8 y) {
#ifdef LCD_TRACK_POS
    xpos = x;
    ypos = y;
#endif

#define LINE_SHIFT 6  // LCD controller constant
    uint8_t address = x | (y << LINE_SHIFT);
    LCD_vSend_cmd(SET_CURSOR_LOCATION | address);
}
void lcd_printf(char *format, ...) {
    va_list args;
    va_start(args, format);
#ifdef LCD_DYNALLOC
#include <stdlib.h>
    uint8_t len = snprintf(NULL, 0, format, args);
    char *str_buffer = malloc(len + 1);
    vsnprintf(str_buffer, len + 1, format, args);
#else
    char str_buffer[16 * 2];
    vsnprintf(str_buffer, 16 * 2, format, args);
#endif
    va_end(args);
    LCD_vSend_string(str_buffer);
}
