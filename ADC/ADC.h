/*
 * ADC.h
 *
 *  Created on: Jun 16, 2018
 *      Author: Islam Ahmed 
 *		Email : islamahmed.c@gmail.com
 */

#ifndef ADC_H_
#define ADC_H_

#include "Types.h"
#include "utilss.h"


/* ADC Registers */
#define ADMUX  *((volatile u8*) 0x27) /* ADC Multiplexer Selection Register */
#define ADCSRA *((volatile u8*) 0x26) /* ADC Control and Status Register A */
#define SFIOR  *((volatile u8*) 0x50) /* Special FunctionIO Register */
#define ADCL   *((volatile u8*) 0x24) /* ADC Data Register Low Byte */
#define ADCH   *((volatile u8*) 0x25) /* ADC Data Register High Byte */

/* ADC Functions */
extern void ADC_voidInit (void);
extern u8 ADC_u8StartAndGet(void); 	  /* Polling mode */


#endif /* ADC_H_ */
