/*
 * main.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include<string.h>
#include"Lcd_int_bouncing.h"
#include"Bouncing_Names_int.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

int main(void){
	//u8 first[16]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
	//u8 second[16]={0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF};
	char a[3]="dan";

	u8 i,j;
	Lcd_vidInit();
	//Bouncing_Names_vidWriteName(a,3);


	/*Lcd_vidSendCommand(00);
	Lcd_vidWriteChar('s');
	Lcd_vidSendCommand(193);
	Lcd_vidWriteChar('a');
	 */
	//Lcd_vidSendCommand(0x80);
	//Lcd_vidWriteChar('a');
	while(1){
		//for(row1=0x80; row1<0x8F; row1+=2){
		//	Lcd_vidSendCommand(first[row1]);
	//	}

		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar(a[2]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xC1);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar(a[1]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xC1);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xC3);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xC1);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xC3);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xC5);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xC3);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xC5);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xC7);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xC5);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x88);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xC7);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xC9);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x88);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xC7);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x8A);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xC9);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x88);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xCB);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x8A);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xC9);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x8C);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xCB);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x8A);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xCD);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x8C);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xCB);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0x8E);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0xCD);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x8C);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xCF);
		Lcd_vidWriteChar(a[2]);
		Lcd_vidSendCommand(0x8E);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0xCD);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xCF);
		Lcd_vidWriteChar(a[1]);
		Lcd_vidSendCommand(0x8E);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);

		Lcd_vidSendCommand(0xCF);
		Lcd_vidWriteChar(a[0]);
		_delay_ms(600);
		Lcd_vidSendCommand(0x01);


	}
	return 0;
}

