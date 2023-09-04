/*
 * Keyboard_int.h
 *
 *  Created on: Jun 24, 2020
 *      Author: Dan
 */

#ifndef KEYBOARD_INT_H_
#define KEYBOARD_INT_H_

void Keyboard_vidInit(void);
void Keyboard_vidReceivedKey(void);

u8 EscFlag,ExtendedFlag,Cursor;

#define Keyboard_u8Carriage_Return 	'\r'
#define Keyboard_u8Newline 		   	'\n'


#define Keyboard_u8Extended 		'['
#define Keyboard_u8Up 				'A'
#define Keyboard_u8Down 			'B'
#define Keyboard_u8Right 			'C'
#define Keyboard_u8Left 			'D'
#define Keyboard_u8Esc 				0x1B
#define Keyboard_u8Enter			0x0D
#define Keyboard_u8Backspace 		0x7F
#define Keyboard_u8Space			0x20

#define Keyboard_u8FlagSet 		1
#define Keyboard_u8FlagCleared	0


#define ClearDisplay 				0x01
#define InitialPosition				0x80
#endif /* KEYBOARD_INT_H_ */
