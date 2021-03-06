/*
 * Keypad.c
 *
 *  Created on: Jan 30, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#include "Types.h"
#include "utilss.h"
#include "avr/delay.h"
#include "DIO.h"

#define F_CPU 8000000

void Keypad_voidInit(void)
{
/*	#define DDRD DDRB
	#define PORTD PORTB
	#define PIND PINB

	//to change Port

*/


	/* Port configuration */
	DDRD=0x0F;		// upper Input --- lower Output
	PORTD=0xF0;		// Output all 0
	PIND=0xF0; 		// pull up resistors

}


//**************************************************************
u8 Keypad_u8GetKey(void)
{
	Keypad_voidInit();
	/* Keypad ASCII */
	u8 Key[4][4]=
	{
			'7','8','9','/',
			'4','5','6','*',
			'1','2','3','-',
			'C','0','=','+'
	};


	u8 ColumnNumber=0,RowNumber=0,ColumnRead=0;
	/* bounce delay and key detection */
	while(get_nibbleHigh(PIND)==0xF);
	_delay_ms(20);
	while(get_nibbleHigh(PIND)==0xF);
	_delay_ms(20);

	/* determine column */
	switch(get_nibbleHigh(PIND))
	{
		case 0b1110 :
			ColumnNumber=0;
			ColumnRead=0b1110;
			break;

		case 0b1101 :
			ColumnNumber=1;
			ColumnRead=0b1101;
			break;

		case 0b1011 :
			ColumnNumber=2;
			ColumnRead=0b1011;
			break;

		case 0b0111 :
			ColumnNumber=3;
			ColumnRead=0b0111;
			break;
	}

	/* determine row */
	u8 Number_of_Iterations=0, Check=0b1110;
	for(;Number_of_Iterations<4;Number_of_Iterations++)
	{
		assign_nibbleLow(PORTD,Check);
		if(get_nibbleHigh(PIND)==ColumnRead)
		{
			RowNumber=Number_of_Iterations;
			return Key[RowNumber][ColumnNumber];
		}
		Check=(Check<<1)|1;
	}
}
