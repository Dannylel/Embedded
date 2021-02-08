/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Lcd_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

int main(void){
	Lcd_vidInit();
	Lcd_vidSendCommand(0x83);
	Lcd_vidPrintStr("hello-world");
	while(1){

	}
	return 0;
}

