/*
 * Led_prg.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"LED_cfg.h"
#include<avr/io.h>
#include "LED_int.h"

void Led_vidInit(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinDir(LED_u8ID_1,DIO_u8HIGH);	//Setting 1st 2 pins
		break;
	case 2:
		Dio_vidSetPinDir(LED_u8ID_2,DIO_u8HIGH);	//of PORTA to output
		break;
	case 3:
		Dio_vidSetPinDir(LED_u8ID_3,DIO_u8HIGH);	//Setting 2nd 2 pins
		break;
	case 4:
		Dio_vidSetPinDir(LED_u8ID_4,DIO_u8HIGH);	//of PORTB to output
		break;
	case 5:
		Dio_vidSetPinDir(LED_u8ID_5,DIO_u8HIGH);	//Setting 3rd 2 pins
		break;
	case 6:
		Dio_vidSetPinDir(LED_u8ID_6,DIO_u8HIGH);	//of PORTC to output
		break;
	case 7:
		Dio_vidSetPinDir(LED_u8ID_7,DIO_u8HIGH);	//Setting 4th 2 pins
		break;
	case 8:
		Dio_vidSetPinDir(LED_u8ID_8,DIO_u8HIGH);	//of PORTD to output
		break;
	}
}
void Led_u8TurnON(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8HIGH);
		break;
	case 2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8HIGH);
		break;
	case 3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8HIGH);
		break;
	case 4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8HIGH);
		break;
	case 5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8HIGH);
		break;
	case 6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8HIGH);
		break;
	case 7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8HIGH);
		break;
	case 8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8HIGH);
		break;
	}
}

void Led_u8TurnOFF(u8 LedID){
	switch(LedID){
	case 1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8LOW);
		break;
	case 2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8LOW);
		break;
	case 3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8LOW);
		break;
	case 4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8LOW);
		break;
	case 5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8LOW);
		break;
	case 6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8LOW);
		break;
	case 7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8LOW);
		break;
	case 8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8LOW);
		break;
	}
}
