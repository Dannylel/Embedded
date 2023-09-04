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
//u8 arr[10]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1011000,0b0000000,0b0010000};

u8 key,key1,key2,operand1,operand2,operator,result;
int main(void){
	operator=0x81;
	Lcd_vidInit();
	Keypad_vidInit();
	while(1){
	key=Keypad_u8GetKey();
	if(key!=0xFF){
	switch(key){
	case 0:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('0');
		_delay_ms(500);
		operand1=0;
		key=0;
		break;
	case 1:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('1');
		_delay_ms(500);
		operand1=1;
		key=0;
		break;
	case 2:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('2');
		_delay_ms(500);
		operand1=2;
		key=0;
		break;
	case 3:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('3');
		_delay_ms(500);
		operand1=3;
		key=0;
		break;
	case 4:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('4');
		_delay_ms(500);
		operand1=4;
		key=0;
		break;
	case 5:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('5');
		_delay_ms(500);
		operand1=5;
		key=0;
		break;
	case 6:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('6');
		_delay_ms(500);
		operand1=6;
		key=0;
		break;
	case 7:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('7');
		_delay_ms(500);
		operand1=7;
		key=0;
		break;
	case 8:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('8');
		_delay_ms(500);
		operand1=8;
		key=0;
		break;
	case 9:
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('9');
		_delay_ms(500);
		operand1=9;
		key=0;
		break;
	}
	_delay_ms(2000);
	}
	else if(key==0xFF){
		PORTD=0xFF;
	}
	operator=Keypad_u8GetKey();
	if(operator!=0xFF){
	if(operator=='+'){
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(operator);
		result=operand1+operand2;
		_delay_ms(500);
	}
	else if(operator=='-'){
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(operator);
		result=operand1-operand2;
		_delay_ms(500);
	}
	else if(operator=='*'){
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(operator);
		result=operand1*operand2;
		_delay_ms(500);
	}
	else if(operator=='/'){
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(operator);
		result=operand1/operand2;
		_delay_ms(500);
	}
	}
	else if(operator==0xFF){
		PORTD=0xFF;
	}
	key1=Keypad_u8GetKey();
	if(key1!=0xFF){
	switch(key1){
	case 0:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('0');
		_delay_ms(500);
		operand2=0;
		key1=0;
		break;
	case 1:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('1');
		_delay_ms(500);
		operand2=1;
		key1=0;
		break;
	case 2:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('2');
		_delay_ms(500);
		operand2=2;
		key1=0;
		break;
	case 3:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('3');
		_delay_ms(500);
		operand2=3;
		key1=0;
		break;
	case 4:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('4');
		_delay_ms(500);
		operand2=4;
		key1=0;
		break;
	case 5:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('5');
		_delay_ms(500);
		operand2=5;
		key1=0;
		break;
	case 6:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('6');
		_delay_ms(500);
		operand2=6;
		key1=0;
		break;
	case 7:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('7');
		_delay_ms(500);
		operand2=7;
		key1=0;
		break;
	case 8:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('8');
		_delay_ms(500);
		operand2=8;
		key1=0;
		break;
	case 9:
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar('9');
		_delay_ms(500);
		operand2=9;
		key1=0;
		break;
	}
	}
	else if(key1==0xFF){
		PORTD=0xFF;
	}
	_delay_ms(500);
	key2=Keypad_u8GetKey();
	if(key2!=0xFF){
	if(key2=='='){
	/*	if(operator=='+'){
			result=key+key1;
		}
		else if(operator=='-'){
			result=key-key1;
		}
		else if(operator=='*'){
			result=key*key1;
		}
		else if(operator=='/'){
			result=key/key1;
		}*/
		Lcd_vidSendCommand(0x83);
		Lcd_vidWriteChar('=');
		_delay_ms(200);
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(result+'0');
		_delay_ms(500);
	}
	}
	else if(key2==0xFF){
		PORTD=0xFF;
	}



	}
	return 0;

}
