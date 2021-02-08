/*
 * main.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Dan
 */
#undef F_CPU
#define F_CPU 8000000
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Seven_Segment_cfg.h"
#include"Seven_Segment_int.h"
#include<avr/io.h>
#include<util/delay.h>
int main(void){
	u8 x;
	//Initializing both seven segment displays
	Seven_Seg_vidInit(2);
	//Writing numbers
	//Seven_Seg_u8Write(2);
	while(1){
		for(x=0; x<=99; x++){
			Seven_Seg_u8Write(x);
			_delay_ms(500);
		}
	}
	return 0;
}
