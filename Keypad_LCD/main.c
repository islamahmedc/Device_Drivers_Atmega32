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
#include "Keypad.h"
#include "LCD.h"

#define F_CPU 8000000

void main()
{
	Keypad_voidInit();
	LCD_voidLcdInit();
	while (1)
	{
		LCD_voidWriteData(Keypad_u8GetKey());
		_delay_ms(400);
	}
}

