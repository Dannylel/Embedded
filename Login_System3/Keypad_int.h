/*
 * Keypad_int.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Dan
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_


void Keypad_vidInit(void);
u8 Keypad_u8GetKey(void);

#define Keypad_PORT	DDRD
#define Keypad_PIN	PORTD
#define Keypad_BIT 	PIND


#define KEYPAD_u8NO_KEY 0xFF

#endif /* KEYPAD_INT_H_ */

