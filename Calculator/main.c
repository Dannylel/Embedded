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
#include"Keypad_int.h"
#include"Lcd_int.h"
#include<avr/io.h>
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
//u8 arr[10]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1011000,0b0000000,0b0010000};
void number(void);
u8 kk,key,key1,key2,operand1,operand2,operator,result,pos;
int main(void){
	pos=0;
	operator=' ';
	Keypad_vidInit();
	Lcd_vidInit();
	while(1){
		key=Keypad_u8GetKey();
		if(key!=0xFF){
			Lcd_vidSendCommand(0x80+pos);
			if((operator=='+')||(operator=='-')||(operator=='*')||(operator=='/')){

				if((key>=0)&&(key<=9)){
					key2=key;
					Lcd_vidWriteChar(key2+'0');
					pos++;
				}
					_delay_ms(200);
					key=Keypad_u8GetKey();

					if(key=='='){
						if(operator=='+'){
							result=key1+key2;

						}
						else if(operator=='-'){
							result=key1-key2;

						}
						else if(operator=='*'){
							result=key1*key2;

						}
						else if(operator=='/'){
							result=key1/key2;

						}
						Lcd_vidSendCommand(0x83);
						Lcd_vidWriteChar('=');
						Lcd_vidSendCommand(0x84);
						Lcd_vidWriteChar(result+'0');

					}
					else if(key=='#'){
						Lcd_vidSendCommand(0x01);
						key1=0;
						key2=0;
						key=0;
						pos=0;
						operator=0;
						Lcd_vidSendCommand(0x80);
					}




			}
			else if((key>=0)&&(key<=9)){
				key1=key;
				Lcd_vidWriteChar(key1+'0');
				pos++;

			}
			else if(key=='+'){
				operator='+';
				Lcd_vidSendCommand(0x80+pos);
				Lcd_vidWriteChar(operator);
				pos++;

			}
			else if(key=='-'){
				operator='-';
				Lcd_vidSendCommand(0x80+pos);
				Lcd_vidWriteChar(operator);
				pos++;
			}

			else if(key=='*'){
				operator='*';
				Lcd_vidSendCommand(0x80+pos);
				Lcd_vidWriteChar(operator);
				pos++;
			}
			else if(key=='/'){
				operator='/';
				Lcd_vidSendCommand(0x80+pos);
				Lcd_vidWriteChar(operator);
				pos++;
			}
			/*else if(key=='='){
				if(operator=='+'){
					result=key1+key2;

				}
				else if(operator=='-'){
					result=key1-key2;

				}
				else if(operator=='*'){
					result=key1*key2;

				}
				else if(operator=='/'){
					result=key1/key2;

				}
				Lcd_vidSendCommand(0x83);
				Lcd_vidWriteChar('=');
				Lcd_vidSendCommand(0x84);
				Lcd_vidWriteChar(result);

			}
			else if(key=='#'){
				Lcd_vidSendCommand(0x01);
				key1=0;
				key2=0;
				key=0;
				operator=0;
				Lcd_vidSendCommand(0x80);
			}
			 */
		}
		else {
			PORTD=0xFF;
		}
		_delay_ms(200);

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
