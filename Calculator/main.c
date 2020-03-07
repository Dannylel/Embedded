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
void number(void);
u8 kk,key,key1,key2,operand1,operand2,operator,result;
int main(void){
	operand1=0x80,operand2=0x82;

	Keypad_vidInit();
	Lcd_vidInit();
	while(1){
		key=Keypad_u8GetKey();
		if(key!=0xFF){
			Lcd_vidSendCommand(0x80);
			if((key!='=')&&(key!='+')&&(key!='-')&&(key!='*')&&(key!='/')&&(key!='#')){
				key1=key;
				Lcd_vidWriteChar(key1+'0');
			}
			if((key>=0)&&(key<=9));
		}
		else {
			PORTD=0xFF;
		}
		_delay_ms(200);
		key2=Keypad_u8GetKey();
		if(key2!=0xFF){
			Lcd_vidSendCommand(0x81);
			if(key2=='+'){
				operator=key2;
				Lcd_vidWriteChar(operator);

			}
			else if(key2=='-'){
				operator=key2;
				Lcd_vidWriteChar(operator);

			}
			else if(key2=='*'){
				operator=key2;
				Lcd_vidWriteChar(operator);
							}
			else if(key2=='/'){
				operator=key2;
				Lcd_vidWriteChar(operator);

			}
		}
		_delay_ms(200);
		kk=Keypad_u8GetKey();
		if(kk!=0xFF){
			Lcd_vidSendCommand(0x82);

			if((kk!='=')&&(kk!='+')&&(kk!='-')&&(kk!='*')&&(kk!='/')&&(kk!='#')){

				Lcd_vidWriteChar(kk+'0');
			}
			if((kk>=0)&&(kk<=9));
		}
		else {
			PORTD=0xFF;

		}
	}
	return 0;

}

void number(void){
	key=Keypad_u8GetKey();
	if((key!='=')&&(key!='+')&&(key!='-')&&(key!='*')&&(key!='/')&&(key!='#')){
		key1=key;
		Lcd_vidWriteChar(key1+'0');
		_delay_ms(150);
	}
	else if(key=='+'){
		operator=key;
		Lcd_vidWriteChar(operator);
		_delay_ms(150);
	}
	else if(key=='-'){
		operator=key;
		Lcd_vidWriteChar(operator);
		_delay_ms(150);
	}
	else if(key=='*'){
		operator=key;
		Lcd_vidWriteChar(operator);
		_delay_ms(150);
	}
	else if(key=='/'){
		operator=key;
		Lcd_vidWriteChar(operator);
		_delay_ms(150);
	}


}
