/*
 * main.c
 *
 *  Created on: Jan 31, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Lcd_int.h"
#include<avr/io.h>
#include<util/delay.h>
#define jj 0xC0
#define kk 0x80
int main(void){
	Lcd_vidInit();

	Lcd_vidWriteChar('D');
	Lcd_vidSendCommand(0xC1);
	Lcd_vidWriteChar('A');
	Lcd_vidSendCommand(0x82);
	//Lcd_MoveCursor(20);

	Lcd_vidWriteChar('N');



	while(1);
	return 0;
}

