/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"LcdMaze_int.h"
#include"Maze_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

int main(void){
	Lcd_vidInit();
	Lcd_vidSendCommand(0x80);
	Lcd_vidWriteChar('|');
	Lcd_vidSendCommand(0xCF);
	Lcd_vidWriteChar('|');

	while(1){
		Left2Right_1st_Row();
		Left2Right_2nd_Row();
		Right2Left_2nd_Row();
		Right2Left_1st_Row();
	}
	return 0;
}
