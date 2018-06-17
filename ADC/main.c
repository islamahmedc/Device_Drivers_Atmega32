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
#include "ADC.h"

#define F_CPU 8000000

void main()
{
	LCD_voidLcdInit();
	ADC_voidInit();
	LCD_Send_A_String("temp ");
	_delay_ms(3000);
	while (1)
	{
		LCD_Send_An_Integer( ((ADC_u8StartAndGet())/4) );
		_delay_ms(3000);
		LCD_Send_A_String(" ");
	}
}

