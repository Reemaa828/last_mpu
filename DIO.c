#include "STD_Types.h"
#include "MACROS.h"
#include "avr/io.h"
#include <avr/delay.h>
#include "DIO.h"
#define F_CPU 8000000UL






u8 DIO_SetPinDirection(u8 PORT_Num, u8 PIN_Num, u8 PIN_Direction)
{

	u8 Func_Stat0 = OK;

	if ((PORT_Num > PORTD_Num) || (PIN_Num > PIN_Num7) || (PIN_Direction > Output))
	{
		Func_Stat0 = NOK;
	}

	else
	{
		switch (PORT_Num)
		{
		  case PORTA_Num:
			if(PIN_Direction == Input)
			{
				CLR_BIT(DDRA,PIN_Num);
			}
			else if(PIN_Direction==Output)
			{
				SET_BIT(DDRA, PIN_Num);
			}

			break;
		  case PORTB_Num:
			if(PIN_Direction == Input)
			{
				CLR_BIT(DDRB,PIN_Num);
			}
			else if(PIN_Direction==Output)
			{
				SET_BIT(DDRB, PIN_Num);
			}
			break;
		  case PORTC_Num:
			if(PIN_Direction == Input)
			{
				CLR_BIT(DDRC,PIN_Num);
			}
			else if(PIN_Direction==Output)
			{
				SET_BIT(DDRC, PIN_Num);
			}
			break;
		  case PORTD_Num:
		 	if(PIN_Direction == Input)
			{
				CLR_BIT(DDRD,PIN_Num);
			}
			else if(PIN_Direction==Output)
			{
				SET_BIT(DDRD, PIN_Num);
			}
			break;
		}
	}
	return Func_Stat0;
}

u8 DIO_SetPinValue(u8 PORT_Num, u8 PIN_Num, u8 PIN_Value)
{
	u8 Func_Stat1 = OK;

	if ((PORT_Num > PORTD_Num) || (PIN_Num > PIN_Num7) || (PIN_Value > High))
	{
		Func_Stat1 = NOK;
	}
	else
	{
		switch(PORT_Num)
		{
		case PORTA_Num:
			if(PIN_Value == High)
			{
				SET_BIT(PORTA, PIN_Num);
			}
			else if(PIN_Value == Low)
			{
				CLR_BIT(PORTA, PIN_Num);
			}
			break;
		case PORTB_Num:
			if(PIN_Value == High)
			{
				SET_BIT(PORTB, PIN_Num);
			}
			else if(PIN_Value == Low)
			{
				CLR_BIT(PORTB, PIN_Num);
			}
			break;
		case PORTC_Num:
			if(PIN_Value == High)
			{
				SET_BIT(PORTC, PIN_Num);
			}
			else if(PIN_Value == Low)
			{
				CLR_BIT(PORTC, PIN_Num);
		    }
			break;
		case PORTD_Num:
			if(PIN_Value == High)
			{
				SET_BIT(PORTD, PIN_Num);
			}
			else if(PIN_Value == Low)
			{
				CLR_BIT(PORTD, PIN_Num);
		    }
			break;
		}
	}
	return Func_Stat1;
}
u8 DIO_SetPortDirection(u8 PORT_Num, u8 PORT_Direction)
{
	u8 Func_Stat2 = OK;
	if((PORT_Num > PORTD_Num) || (PORT_Direction > Output))
	{
		Func_Stat2 = NOK;
	}
	else
	{
		switch(PORT_Num)
		{
		case PORTA_Num:
			if(PORT_Direction == Output)
			{
				DDRA=255;
			}
			else if(PORT_Direction == Input)
			{
				DDRA=0;
			}
			break;
		case PORTB_Num:
			if(PORT_Direction == Output)
			{
				DDRB=255;
			}
			else if(PORT_Direction == Input)
			{
				DDRB=0;
			}
			break;
		case PORTC_Num:
			if(PORT_Direction == Output)
			{
				DDRC=255;
			}
			else if(PORT_Direction == Input)
			{
				DDRC=0;
			}
			break;
		case PORTD_Num:
			if(PORT_Direction == Output)
			{
				DDRD=255;
			}
			else if(PORT_Direction == Input)
			{
				DDRD=0;
			}
			break;
		}
	}
	return Func_Stat2;
}
u8 DIO_SetPortValue(u8 PORT_Num, u8 PORT_Value)
{
	u8 Func_Stat3 = OK;
		if((PORT_Num > PORTD_Num) || (PORT_Direction > High))
		{
			Func_Stat3 = NOK;
		}
		else
		{
			switch(PORT_Num)
			{
			case PORTA_Num:
				PORTA=PORT_Value;
				break;
			case PORTB_Num:
				PORTB=PORT_Value;
				break;
			case PORTC_Num:
				PORTC=PORT_Value;
				break;
			case PORTD_Num:
				PORTD=PORT_Value;
				break;
			}
		}
	return Func_Stat3;
}
u8 DIO_GetPinValue(u8 PORT_Num, u8 PIN_Num, u8*Pin_Val)
{
	u8 Func_Stat4 = OK;

		if((PORT_Num > PORTD_Num) || (PIN_Num > PIN_Num7))
		{
			Func_Stat4 = NOK;
		}
		else
		{
		switch(PORT_Num)
		{
		case PORTA_Num:
			*Pin_Val=GET_BIT(PINA, PIN_Num);
			break;
		case PORTB_Num:
			*Pin_Val=GET_BIT(PINB, PIN_Num);
			break;
		case PORTC_Num:
			*Pin_Val=GET_BIT(PINC, PIN_Num);
			break;
		case PORTD_Num:
			*Pin_Val=GET_BIT(PIND, PIN_Num);
			break;
		}
	}
	return Func_Stat4;
}
u8 DIO_GetPortValue(u8 PORT_Num, u8*Port_Val)
{
	u8 Func_Stat5 = OK;
	if((PORT_Num > PORTD_Num))
	{
		Func_Stat5=NOK;
	}
	else
	{
		switch(PORT_Num)
		{
		case PORTA_Num:
			*Port_Val=PINA;
			break;
		case PORTB_Num:
			*Port_Val=PINB;
			break;
		case PORTC_Num:
			*Port_Val=PINC;
			break;
		case PORTD_Num:
			*Port_Val=PIND;
			break;
		}
	}
	return Func_Stat5;
}
void write_low_nibble(unsigned char portname,unsigned char value)
{
	value&=0x0f;
	switch(portname)
	{
		case 0:
		PORTA&=0xf0;
		PORTA|=value;
		case 1:
		PORTB&=0xf0;
		PORTB|=value;
		case 2:
		PORTC&=0xf0;
		PORTC|=value;
		case 3:
		PORTD&=0xf0;
		PORTD|=value;
	}
}

void write_high_nibble(unsigned char portname,unsigned char value)
{
	value<<=4;
	switch(portname)
	{
		case 0:
		PORTA&=0x0f;
		PORTA|=value;
		case 1:
		PORTB&=0x0f;
		PORTB|=value;
		case 2:
		PORTC&=0x0f;
		PORTC|=value;
		case 3:
		PORTD&=0x0f;
		PORTD|=value;
	}
}










