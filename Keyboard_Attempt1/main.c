/*
 * main.c
 *
 *  Created on: Jun 24, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Keyboard_int.h"


int main(void){

	Keyboard_vidInit();
	extern u8 EscFlag,ExtendedFlag,Cursor;
	Cursor=0x80;;
	EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
	while(1){
		Keyboard_vidReceivedKey();

	}
	return 0;
}

