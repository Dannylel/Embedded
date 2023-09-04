/*
 * A_Naming_prg.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"LcdNaming_int.h"

//CGRAM 0x40	Address of the first custom character in CGRAM
//LcdLoc 0x80	Address of the first desired location in LCD
//Custom 0x00	Address of the first byte containing the first custom character in CGRAM
void Naming_vidPassLetter(u8 *letter, u8 size, u8 CGRAM, u8 LcdLoc, u8 Custom){
	u8 i;
	Lcd_vidSendCommand(CGRAM);
	for(i=0; i<size; i++){
		Lcd_vidWriteChar(letter[i]);
	}
	Lcd_vidSendCommand(LcdLoc);
	Lcd_vidWriteChar(Custom);

}
