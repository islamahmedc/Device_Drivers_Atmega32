/*
 * LCD.h
 *
 *  Created on: Jan 30, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#ifndef LCD_H_
#define LCD_H_

#include "Types.h"
#include "utilss.h"

#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2

void LCD_voidLcdInit(void);
void LCD_voidSendCommand(u8 cpy_u8Command);
void LCD_voidWriteData(u8 cpy_u8Data);
void LCD_Send_A_String(char *StringOfCharacters);
void LCD_Send_An_Integer(u8 cpy_u8Integer);
void LCD_voidSendPattern(u8 *u8ptr_pattern);
void LCD_voidSetACG(u8 cpy_u8ACG);
void LCD_voidSetADD(u8 cpy_u8ADD);
void LCD_voidDisplayPattern(u8 cpy_u8ADD);


#endif /* LCD_H_ */
