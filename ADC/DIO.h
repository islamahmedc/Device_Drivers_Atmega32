/*
 * DIO.h
 *
 *  Created on: Nov 27, 2017
 *      Author: Islam Ahmed
 *
 */

 
#ifndef DIO_H_
#define DIO_H_



/*
 * Define DIO Registers
 * from datasheet from Section Register Summary
 */

#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)
#define PORTA *((volatile u8*)0x3B)

#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)
#define PORTB *((volatile u8*)0x38)

#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)
#define PORTC *((volatile u8*)0x35)

#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)
#define PORTD *((volatile u8*)0x32)




/* define high & low */
#define DIO_u8LOW 0
#define DIO_u8HIGH 1

/* define pin output and pin input */
#define DIO_u8PinIp 0
#define DIO_u8PinOp 1



/*
 * define all Atmega16 pins
 */
#define DIO_u8PinA0 0
#define DIO_u8PinA1 1
#define DIO_u8PinA2 2
#define DIO_u8PinA3 3
#define DIO_u8PinA4 4
#define DIO_u8PinA5 5
#define DIO_u8PinA6 6
#define DIO_u8PinA7 7

#define DIO_u8PinB0 8
#define DIO_u8PinB1 9
#define DIO_u8PinB2 10
#define DIO_u8PinB3 11
#define DIO_u8PinB4 12
#define DIO_u8PinB5 13
#define DIO_u8PinB6 14
#define DIO_u8PinB7 15

#define DIO_u8PinC0 16
#define DIO_u8PinC1 17
#define DIO_u8PinC2 18
#define DIO_u8PinC3 19
#define DIO_u8PinC4 20
#define DIO_u8PinC5 21
#define DIO_u8PinC6 22
#define DIO_u8PinC7 23

#define DIO_u8PinD0 24
#define DIO_u8PinD1 25
#define DIO_u8PinD2 26
#define DIO_u8PinD3 27
#define DIO_u8PinD4 28
#define DIO_u8PinD5 29
#define DIO_u8PinD6 30
#define DIO_u8PinD7 31


/* DIO Functions */
extern void DIO_voidSetDirection(u8 Copy_u8PinNum, u8 Copy_u8PinValue );
extern void DIO_voidWritePIN(u8 Copy_u8PinNum, u8 Copy_u8PinValue);
extern u8 DIO_u8ReadPIN(u8 Copy_u8PinNum);



#endif /* DIO_H_ */
