/*
 * Keypad_prg.c
 *
 *  Created on: Feb 1, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Keypad_cfg.h"
#include"Keypad_int.h"
#include"Keypad_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

void Keypad_vidInit(void){
	Keypad_PORT=0b00001111;	//Setting upper 4 bits to output and lower 4 to input
	Keypad_PIN=0b11111111;	//Pulling up resistors for lower 4 bits and passing 5v through upper 4 bits
	//>Indicating that we are not scanning for any button clicks right now
}

u8 Keypad_u8GetKey(void){
	u8 temp;
	CLR_BIT(Keypad_PIN,0);
	SET_BIT(Keypad_PIN,1);
	SET_BIT(Keypad_PIN,2);
	SET_BIT(Keypad_PIN,3);
	temp= Keypad_BIT& (0b11110000); //Masking to get values of input pins solely

	switch(temp){
	case 0b11100000:
		return 1;
	case 0b11010000:
		return 2;
	case 0b10110000:
		return 3;
	case 0b01110000:
		return '+';
	}
	SET_BIT(Keypad_PIN,0);
	CLR_BIT(Keypad_PIN,1);
	SET_BIT(Keypad_PIN,2);
	SET_BIT(Keypad_PIN,3);
	temp= Keypad_BIT& (0b11110000);

	switch(temp){
	case 0b11100000:
		return 4;
	case 0b11010000:
		return 5;
	case 0b10110000:
		return 6;
	case 0b01110000:
		return '-';
	}
	SET_BIT(Keypad_PIN,0);
	SET_BIT(Keypad_PIN,1);
	CLR_BIT(Keypad_PIN,2);
	SET_BIT(Keypad_PIN,3);
	temp= Keypad_BIT& (0b11110000);

	switch(temp){
	case 0b11100000:
		return 7;
	case 0b11010000:
		return 8;
	case 0b10110000:
		return 9;
	case 0b01110000:
		return '*';
	}
	SET_BIT(Keypad_PIN,0);
	SET_BIT(Keypad_PIN,1);
	SET_BIT(Keypad_PIN,2);
	CLR_BIT(Keypad_PIN,3);
	temp= Keypad_BIT& (0b11110000);

	switch(temp){
	case 0b11100000:
		return '#';
	case 0b11010000:
		return 0;
	case 0b10110000:
		return '=';
	case 0b01110000:
		return '/';
	}
	return KEYPAD_u8NO_KEY;
}
