/*
 * main.c
 *
 *  Created on: Feb 20, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Lcd_int.h"
#include"ADC_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include"Volume_int.h"

int main(void){

	Lcd_vidInit();
	Adc_vidInit();
	while(1){
		Volume_vidInit();
	}
	return 0;
}
