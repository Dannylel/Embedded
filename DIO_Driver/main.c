/*
 * main.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Dan
 */
#include"Std_types.h"
#include"Bit_math.h"
#include"Dio_int.h"




int main(void){

	Dio_vidSetPinDir(7,1);
	while(1){

		Dio_vidSetPinVal(7,1);

	}
	return 0;
}
