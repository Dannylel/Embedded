/*
 * Maze_prg.c
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

void Left2Right_1st_Row(void){
	//Left to right first row
	u8 j;
	for(j=0x81; j<=0x8F; j++){
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar('X');
		_delay_ms(250);
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar(' ');
	}
}
void Left2Right_2nd_Row(void){
	//Left to right 2nd row
	u8 j;
	for(j=0xC0; j<=0xCE; j++){
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar('X');
		_delay_ms(250);
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar(' ');
	}
}
void Right2Left_2nd_Row(void){
	//Right to left 2nd row
	u8 j;
	for(j=0xCE; j>=0xC0; j--){
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar('X');
		_delay_ms(250);
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar(' ');
	}
}
void Right2Left_1st_Row(void){
	//Right to left 1st row
	u8 j;
	for(j=0x8F; j>=0x81; j--){
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar('X');
		_delay_ms(250);
		Lcd_vidSendCommand(j);
		Lcd_vidWriteChar(' ');
	}
}
