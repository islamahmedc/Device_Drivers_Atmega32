/*
 * main.c
 *
 *  Created on: Jan 4, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#include "Types.h"
#include "utilss.h"
#include "stdlib.h"
#include <avr/delay.h>
#include "DIO.h"
#include "LED.h"

void main()
{
	while (1)
	{

		LED_BlinkRandom(LED_u8PortC);
		_delay_ms(500);
	}
}

