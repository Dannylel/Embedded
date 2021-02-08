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
u8 operand1,operand2,result;
//u8 arr[10]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1011000,0b0000000,0b0010000};
u8 key,key1,key2,key3,op,op1,op2,re;
int main(void){

	Keypad_vidInit();
	Lcd_vidInit();
	while(1){
		key=Keypad_u8GetKey();
		if(key!=0xFF){
			if((key!='#')&&(key!='=')){
				if((key!='+')&&(key!='-')&&(key!='*')&&(key!='/')){
					op1=key;
					Lcd_vidSendCommand(0x80);
					Lcd_vidWriteChar(op1+'0');

				}
				else if(key=='+'){
					result=op1+op2;
					Lcd_vidSendCommand(0x81);
					Lcd_vidWriteChar('+');
				}
				else if(key=='-'){
					result=op1-op2;
					Lcd_vidSendCommand(0x81);
					Lcd_vidWriteChar('-');
				}
				else if(key=='*'){
					result=op1*op2;
					Lcd_vidSendCommand(0x81);
					Lcd_vidWriteChar('*');
				}
				else if(key=='/'){
					result=op1/op2;
					Lcd_vidSendCommand(0x81);
					Lcd_vidWriteChar('/');
				}
			}
			key1=Keypad_u8GetKey();
			if((key1!='#')&&(key1!='=')){
				if((key1!='+')&&(key!='-')&&(key1!='*')&&(key1!='/')){
					op2=key1;
					Lcd_vidSendCommand(0x82);
					Lcd_vidWriteChar(op2+'0');
				}
			}
			key2=Keypad_u8GetKey();
			if(key2=='='){
				Lcd_vidSendCommand(0x83);
				Lcd_vidWriteChar(key2);

				Lcd_vidSendCommand(0x84);
				Lcd_vidWriteChar(result+'0');
			}
			else if(key2=='#'){
				Lcd_vidSendCommand(0x01);
			}
		}
	}
	return 0;
}






