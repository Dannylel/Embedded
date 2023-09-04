/*
 * Led_prg.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"LED_cfg.h"
#include"Dio_int.h"
#include<avr/io.h>
#include "LED_int.h"

void Led_vidInit(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinDir(LED_u8ID1,DIO_u8_HIGH);	//Setting 1st 2 pins
		break;
	case 2:
		Dio_vidSetPinDir(LED_u8ID2,DIO_u8_HIGH);	//of PORTA to output
		break;
	case 3:
		Dio_vidSetPinDir(LED_u8ID3,DIO_u8_HIGH);	//Setting 2nd 2 pins
		break;
	case 4:
		Dio_vidSetPinDir(LED_u8ID4,DIO_u8_HIGH);	//of PORTB to output
		break;
	case 5:
		Dio_vidSetPinDir(LED_u8ID5,DIO_u8_HIGH);	//Setting 3rd 2 pins
		break;
	case 6:
		Dio_vidSetPinDir(LED_u8ID6,DIO_u8_HIGH);	//of PORTC to output
		break;
	case 7:
		Dio_vidSetPinDir(LED_u8ID7,DIO_u8_HIGH);	//Setting 4th 2 pins
		break;
	case 8:
		Dio_vidSetPinDir(LED_u8ID8,DIO_u8_HIGH);	//of PORTD to output
		break;
	}
}
void Led_u8TurnON(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinVal(LED_u8ID1,DIO_u8_HIGH);
		break;
	case 2:
		Dio_vidSetPinVal(LED_u8ID2,DIO_u8_HIGH);
		break;
	case 3:
		Dio_vidSetPinVal(LED_u8ID3,DIO_u8_HIGH);
		break;
	case 4:
		Dio_vidSetPinVal(LED_u8ID4,DIO_u8_HIGH);
		break;
	case 5:
		Dio_vidSetPinVal(LED_u8ID5,DIO_u8_HIGH);
		break;
	case 6:
		Dio_vidSetPinVal(LED_u8ID6,DIO_u8_HIGH);
		break;
	case 7:
		Dio_vidSetPinVal(LED_u8ID7,DIO_u8_HIGH);
		break;
	case 8:
		Dio_vidSetPinVal(LED_u8ID8,DIO_u8_HIGH);
		break;
	}
}

void Led_u8TurnOFF(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinVal(LED_u8ID1,DIO_u8_LOW);
		break;
	case 2:
		Dio_vidSetPinVal(LED_u8ID2,DIO_u8_LOW);
		break;
	case 3:
		Dio_vidSetPinVal(LED_u8ID3,DIO_u8_LOW);
		break;
	case 4:
		Dio_vidSetPinVal(LED_u8ID4,DIO_u8_LOW);
		break;
	case 5:
		Dio_vidSetPinVal(LED_u8ID5,DIO_u8_LOW);
		break;
	case 6:
		Dio_vidSetPinVal(LED_u8ID6,DIO_u8_LOW);
		break;
	case 7:
		Dio_vidSetPinVal(LED_u8ID7,DIO_u8_LOW);
		break;
	case 8:
		Dio_vidSetPinVal(LED_u8ID8,DIO_u8_LOW);
		break;
	}
}
