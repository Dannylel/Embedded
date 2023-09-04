/*
 * main.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"../DIO_Driver/Dio_int.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

int main(void){
	Led_vidInit(2);
	while(1){

		Led_u8TurnON(2);
		_delay_ms(400);
		Led_u8TurnOFF(2);
		_delay_ms(400);

	}
	return 0;
}
