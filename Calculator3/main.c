/*
 * main.c
 *
 *  Created on: Feb 1, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Keypad_cfg.h"
#include"Lcd_cfg.h"
#include<avr/io.h>
#include"Keypad_int.h"
#include"Lcd_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>

u8 key,key1,key2,operand1,operand2,operator,result;
int main(void){
	u8 key,key1;
	Lcd_vidInit();
	Keypad_vidInit();
	while(1){
		key=Keypad_u8GetKey();
		if(key!=0xFF){
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteChar(key);
			_delay_ms(500);
			key=0;
		}
		key1=Keypad_u8GetKey();
		if(key1!=0xFF){
			Lcd_vidSendCommand(0x81);
			Lcd_vidWriteChar(key1);
			_delay_ms(500);
			key1=0;
		}
	}
	return 0;

}
