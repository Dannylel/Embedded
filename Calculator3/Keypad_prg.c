/*
 * Keypad_prg.c
 *
 *  Created on: Feb 1, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Keypad_cfg.h"
#include"Keypad_int.h"
#include"Keypad_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

void Keypad_vidInit(void){
	//Setting upper 4 bits to output and lower 4 to input
	Dio_vidSetPinDir(KEYPAD_u8R1_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R2_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R3_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R4_PIN,DIO_u8OUTPUT);

	Dio_vidSetPinDir(KEYPAD_u8C1_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C2_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C3_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C4_PIN,DIO_u8INPUT);

	//Pulling up resistors for lower 4 bits and passing 5v through upper 4 bits
	//>Indicating that we are not scanning for any button clicks right now
	Dio_vidSetPinVal(KEYPAD_u8R1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C4_PIN,DIO_u8HIGH);
}

u8 Keypad_u8GetKey(void){
	u8 temp,pin_c1,pin_c2,pin_c3,pin_c4;

	Dio_vidSetPinVal(KEYPAD_u8R1_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4_PIN,DIO_u8HIGH);

	//Masking to get values of input pins solely
	pin_c1= Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2= Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3= Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4= Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp=0;
	temp|=(pin_c1<<4);
	temp|=(pin_c2<<5);
	temp|=(pin_c3<<6);
	temp|=(pin_c4<<7);


	switch(temp){
	case 0b11100000:
		return KEYPAD_u8R1C1_KEY;
	case 0b11010000:
		return KEYPAD_u8R1C2_KEY;
	case 0b10110000:
		return KEYPAD_u8R1C3_KEY;
	case 0b01110000:
		return KEYPAD_u8R1C4_KEY;
	}

	Dio_vidSetPinVal(KEYPAD_u8R1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4_PIN,DIO_u8HIGH);

	//Masking to get values of input pins solely
	pin_c1= Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2= Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3= Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4= Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp=0;
	temp|=(pin_c1<<4);
	temp|=(pin_c2<<5);
	temp|=(pin_c3<<6);
	temp|=(pin_c4<<7);


	switch(temp){
	case 0b11100000:
		return KEYPAD_u8R2C1_KEY;
	case 0b11010000:
		return KEYPAD_u8R2C2_KEY;
	case 0b10110000:
		return KEYPAD_u8R2C3_KEY;
	case 0b01110000:
		return KEYPAD_u8R2C4_KEY;
	}

	Dio_vidSetPinVal(KEYPAD_u8R1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R4_PIN,DIO_u8HIGH);

	//Masking to get values of input pins solely
	pin_c1= Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2= Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3= Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4= Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp=0;
	temp|=(pin_c1<<4);
	temp|=(pin_c2<<5);
	temp|=(pin_c3<<6);
	temp|=(pin_c4<<7);

	switch(temp){
	case 0b11100000:
		return KEYPAD_u8R3C1_KEY;
	case 0b11010000:
		return KEYPAD_u8R3C2_KEY;
	case 0b10110000:
		return KEYPAD_u8R3C3_KEY;
	case 0b01110000:
		return KEYPAD_u8R3C4_KEY;
	}

	Dio_vidSetPinVal(KEYPAD_u8R1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4_PIN,DIO_u8LOW);

	//Masking to get values of input pins solely
	pin_c1= Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2= Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3= Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4= Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp=0;
	temp|=(pin_c1<<4);
	temp|=(pin_c2<<5);
	temp|=(pin_c3<<6);
	temp|=(pin_c4<<7);

	switch(temp){
	case 0b11100000:
		return KEYPAD_u8R4C1_KEY;
	case 0b11010000:
		return KEYPAD_u8R4C2_KEY;
	case 0b10110000:
		return KEYPAD_u8R4C3_KEY;
	case 0b01110000:
		return KEYPAD_u8R4C4_KEY;
	}
	return KEYPAD_u8NO_KEY;
}
