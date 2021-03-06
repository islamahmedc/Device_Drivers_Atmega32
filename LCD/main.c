/*
 * main.c
 *
 *  Created on: Jan 4, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#include "Types.h"
#include "utilss.h"
#include <avr/delay.h>
#include "DIO.h"
#include "LCD.h"

#define F_CPU 8000000

void main()
{

    //Smiley Face From The Tutorial

    u8 Pattern[8] =
    {

		0b00000000, // _____

		0b00001010, // _*_*_

		0b00001010, // _*_*_

		0b00001010, // _*_*_

		0b00000000, // _____

		0b00010001, // *___*

		0b00001110, // _***_

		0b00000000  // _____

    };
	LCD_voidLcdInit();
	while (1)
	{
		LCD_voidSendPattern(Pattern);
		LCD_voidDisplayPattern(0x00);
		_delay_ms(10);
	}
}

