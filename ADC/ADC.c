/*
 * ADC.c
 *
 *  Created on: Jun 16, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#include "Types.h"
#include "utilss.h"
#include "ADC.h"
#include "DIO.h"

void ADC_voidInit (void)
{
	ADMUX=0b11100000;	/* ADC Multiplexer Selection Register */
	/*		||||||||
	 * 		|||||||-- MUX0 {Select ADC0 Channel}
	 * 		||||||--- MUX1
	 * 		|||||---- MUX2
	 * 		||||----- MUX3
	 * 		|||------ MUX4
	 * 		||------- ADLAR {Left adjust}
	 * 		|-------- REFS0 {Internal 2.56V Voltage Reference}
	 * 		--------- REFS1
	 * */

	ADCSRA=0b10010111;
	/*		 ||||||||
	 * 		 |||||||-- ADPS0 {Division Factor (XTL/128)}
	 * 		 ||||||--- ADPS1
	 * 		 |||||---- ADPS2
	 * 		 ||||----- ADIE  {ADC Interrupt Disable}
	 * 		 |||------ ADIF  {ADC Interrupt Flag Cleared}
	 * 		 ||------- ADATE {ADC Auto Trigger Disable}
	 * 		 |-------- ADSC  {Stop Conversion}
	 * 		 --------- ADEN  {ADC Enable}
	 * */
}

//===================================================================

u8 ADC_u8StartAndGet(void)
{
	set_bit(ADCSRA,6);		/* Start Conversion */
	while( (get_bit(ADCSRA,4))==0 )
			; 				/* Polling mode */
	return ADCH;//+(ADCL>>6);	/* Return Result */

}
