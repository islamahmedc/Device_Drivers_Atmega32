/*
 * LED.c
 *
 *  Created on: Jan 4, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */


#include "Types.h"
#include "utilss.h"
#include "stdlib.h"
#include "DIO.h"


void LED_BlinkRandom (u8 u8PortNumberCpy)
{
	switch(u8PortNumberCpy)
	{

	case 0 :
		DDRA=255;
		PORTA=rand()%256;
		break;

	case 1 :
		DDRB=255;
		PORTB=rand()%256;
		break;

	case 2 :
		DDRC=255;
		PORTC=rand()%256;
		break;

	case 3 :
		DDRD=255;
		PORTD=rand()%128;
		break;

	default :
		break;
	}
}
