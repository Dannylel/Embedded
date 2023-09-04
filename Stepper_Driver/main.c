/*
 * main.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include"Dio_int.h"
#include"Stepper_int.h"


int main(void){

	Stepper_vidInit();
	_delay_ms(500);
	Stepper_vidDirection('R',90);
	while(1){

	Stepper_vidDirection('L',90);
		//133=90 degrees
		//200=130-135 degrees
		//250=180 degrees
	}
	return 0;
}

