/*
 * main.c
 *
 *  Created on: Feb 21, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"DIO_int.h"
#include"Keypad_int.h"
#include"Lcd_int.h"
#include"Login_int.h"
#include<string.h>
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>

int main(void){
	u8 key,x,i,count,count1,pos;
	char id[4];
	char pass[4];
	u8 msg[5]={'e','n','t','e','r'};
	u8 error[5]={'E','R','R','O','R'};
	char id1[4]={'d','a','n'};
	char id2[4]={'m','a','n'};
	char id3[4]={'c','a','b'};
	char pass1[4]={2,2,5};
	char pass2[4]={3,2,7};
	char pass3[4]={8,6,9};
	u8 loc=0x80;
	u8 loc2=0xC0;
	u8 error_loc1=0x85;
	u8 error_loc2=0xC5;
	count=0;
	Dio_vidSetPinDir(DIO_u8PIN_8,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_8,DIO_u8HIGH); //pullup resistor
	Lcd_vidInit();
	while(1){
		key=PINB;
		if(key==1){
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteChar('a');
		}
		else if(key==0){
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteChar('b');

		}

	}

	return 0;
}


