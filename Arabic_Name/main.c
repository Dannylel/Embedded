/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"A_Naming.h"
#include"LcdNaming_int.h"
//CGRAM 0x40	Address of the first custom character in CGRAM
//LcdLoc 0x80	Address of the first desired location in LCD
//Custom 0x00	Address of the first byte containing the first custom character in CGRAM
#include<avr/io.h>
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>

u8 letter1[8]={0x00,0x00,0x02,0x01,0x01,0x01,0x0F,0x00}; //D in arabic
u8 letter2[8]={0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00}; //A in arabic
u8 letter3[8]={0x00,0x04,0x00,0x11,0x11,0x11,0x0E,0x00}; //N in arabic

int main(void){
	u8 i;
	Lcd_vidInit();
	while(1){
		Naming_vidPassLetter(letter3,8,0x40,0x80,0x00); //Passing first character array
		Naming_vidPassLetter(letter2,8,0x48,0x82,0x01); //Passing 2nd character array
		Naming_vidPassLetter(letter1,8,0x50,0x84,0x02); //Passing 3rd character array
		_delay_ms(250);
		Lcd_vidSendCommand(0x1C);
	}
	return 0;
}
