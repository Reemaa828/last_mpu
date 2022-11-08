
#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD_config.h"
#include "lcd_private.h"
#include <stdarg.h>
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN 3
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 3
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void lcd_set_cursor(u8 x, u8 y);
void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void lcd_printf(char *format, ...);

#endif /* LCD_H_ */
