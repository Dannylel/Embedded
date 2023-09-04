/*
 * main.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"LED_int.h"

int main(void){

	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_1,DIO_u8INPUT);

	while(1){
		if(Dio_u8GetPinVal(DIO_u8PIN_1)==1){
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		}
		else{
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		}



	}
	return 0;
}
