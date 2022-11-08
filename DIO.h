#ifndef DIO_H_
#define DIO_H_
#include "STD_Types.h"

#define OK 0
#define NOK 1

#define SetHighNibble 240
#define SetLowerNibble 15
#define AllPort_High 255
#define AllPort_Low 0

#define PORTA_Num  0
#define PORTB_Num  1
#define PORTC_Num  2
#define PORTD_Num  3

#define PIN_Num0 0
#define PIN_Num1 1
#define PIN_Num2 2
#define PIN_Num3 3
#define PIN_Num4 4
#define PIN_Num5 5
#define PIN_Num6 6
#define PIN_Num7 7

#define Input 0
#define Output 1

#define Low 0
#define High 1

#define Activate_PU 1
#define Deactivate_PU 0



u8 PORT_Num;
u8 PIN_Num;
u8 PIN_Direction;
u8 PIN_Value;
u8 PORT_Value;
u8 Pin_Val;
u8 PORT_Direction;
u8 Port_Val;



u8 DIO_SetPinDirection(u8 PORT_Num, u8 PIN_Num, u8 PIN_Direction);
u8 DIO_SetPinValue(u8 PORT_Num, u8 PIN_Num, u8 PIN_Value);
u8 DIO_SetPortDirection(u8 PORT_Num, u8 PORT_Direction);
u8 DIO_SetPortValue(u8 PORT_Num, u8 PORT_Value);
u8 DIO_GetPinValue(u8 PORT_Num, u8 PIN_Num, u8*Pin_Val);
u8 DIO_GetPortValue(u8 PORT_Num, u8*Port_Val);
void write_low_nibble(unsigned char portname,unsigned char value);
void write_high_nibble(unsigned char portname,unsigned char value);


#endif
