/*
 * LED.h
 *
 *  Created on: Jan 4, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#ifndef LED_H_
#define LED_H_

#include "Types.h"
#include "utilss.h"
#include "DIO.h"

#define LED_u8PortA		0
#define LED_u8PortB 	1
#define LED_u8PortC		2
#define LED_u8PortD 	3



void LED_BlinkRandom (u8 u8PortNumberCpy);




#endif /* LED_H_ */
