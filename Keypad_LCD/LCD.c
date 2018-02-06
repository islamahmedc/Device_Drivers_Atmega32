/*
 * LCD.c
 *
 *  Created on: Jan 30, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#include "Types.h"
#include "utilss.h"
#include <avr/delay.h>
#include "DIO.h"
#include "LCD.h"

#define F_CPU 8000000

//*************************************************************
void LCD_voidLcdInit(void)
{
	DDRC=0xFF;
	DDRA=0xFF;
	_delay_ms(50);

	LCD_voidSendCommand(0b00111000); 	// 8-bit initialization 2 lines
	_delay_us(50);
	LCD_voidSendCommand(0x0E); 			// Display on - Cursor on - blinking off
	_delay_us(50);
	LCD_voidSendCommand(0x01);			// Display clear
	_delay_ms(5);
	LCD_voidSendCommand(0b00000110);   	// Entry Mode Set
	_delay_ms(1);
}


//*************************************************************
void LCD_voidSendCommand(u8 cpy_u8Command)
{
	clr_bit(PORTA,LCD_EN);   	// disable
	PORTC=cpy_u8Command;		//send commands
	clr_bit(PORTA,LCD_RS);		// RS = 0 --> instruction register
	clr_bit(PORTA,LCD_RW);		// RW = 0 --> write

				/* Enable pulse */
	set_bit(PORTA,LCD_EN);      // Enable
	_delay_us(1);
	clr_bit(PORTA,LCD_EN);   	// disable
	_delay_us(1);
}


//*************************************************************
void LCD_voidWriteData(u8 cpy_u8Data)
{
	clr_bit(PORTA,LCD_EN);   	// disable
	PORTC=cpy_u8Data;			//send data
	set_bit(PORTA,LCD_RS);		// RS = 1 --> data register
	clr_bit(PORTA,LCD_RW);		// RW = 0 --> write

				/* Enable pulse */
	set_bit(PORTA,LCD_EN);      // Enable
	_delay_us(1);
	clr_bit(PORTA,LCD_EN);   	// disable
	_delay_us(1);

}


//*************************************************************
void LCD_voidSendPattern(u8 *u8ptr_pattern)
{

	LCD_voidSetACG(0b01000000); 	// Set CGRAM Address
	u8 Number_of_iterations;
	for(Number_of_iterations=0;Number_of_iterations<9;Number_of_iterations++)
	{
		LCD_voidWriteData(u8ptr_pattern[Number_of_iterations]);
	}
}


//*************************************************************
void LCD_voidDisplayPattern(u8 cpy_u8ADD)
{
	LCD_voidSetADD(0b10000000);
	LCD_voidWriteData(cpy_u8ADD);
}


//*************************************************************
void LCD_voidSetACG(u8 cpy_u8ACG)
{
	LCD_voidSendCommand(cpy_u8ACG);
}


//*************************************************************
void LCD_voidSetADD(u8 cpy_u8ADD)
{
	LCD_voidSendCommand(cpy_u8ADD);
}
