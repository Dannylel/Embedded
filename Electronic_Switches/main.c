/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"../LED_Driver/pin_map.h"
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

int main(void){

	Dio_vidSetPinDir(DIO_u8_PIN0, DIO_u8_OUTPUT);
	while(1){
		Dio_vidSetPinVal(DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(3000);
		Dio_vidSetPinVal(DIO_u8_PIN0,DIO_u8_LOW);
		_delay_ms(3000);
	}
	return 0;
}
