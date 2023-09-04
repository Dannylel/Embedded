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
	u8 key,x,i,count,count1;
	char id[4];
	char pass[4];
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
	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH); //pullup resistor
	Lcd_vidInit();
	while(1){
		x=PINB;

		if(x==1){
			do{
				for(i=0; i<3; i++){
					key=Keypad_u8GetKey();
					Lcd_vidSendCommand(loc);
					if(key!=0xFF){
					if((key!='=')&&(key!='#')){
						if(key==1){
							id[i]='a';
							Lcd_vidWriteChar('a');
							_delay_ms(2000);
						}
						else if(key==2){
							id[i]='b';
							Lcd_vidWriteChar('b');
							_delay_ms(2000);
						}
						else if(key==3){
							id[i]='c';
							Lcd_vidWriteChar('c');
							_delay_ms(2000);
						}
						else if(key=='+'){
							id[i]='d';
							Lcd_vidWriteChar('d');
							_delay_ms(2000);
						}
						else if(key==4){
							id[i]='e';
							Lcd_vidWriteChar('e');
							_delay_ms(2000);
						}
						else if(key==5){
							id[i]='f';
							Lcd_vidWriteChar('f');
							_delay_ms(2000);
						}
						else if(key==6){
							id[i]='g';
							Lcd_vidWriteChar('g');
							_delay_ms(2000);
						}
						else if(key=='-'){
							id[i]='h';
							Lcd_vidWriteChar('h');
							_delay_ms(2000);
						}
						else if(key==7){
							id[i]='i';
							Lcd_vidWriteChar('i');
							_delay_ms(2000);
						}
						else if(key==8){
							id[i]='j';
							Lcd_vidWriteChar('j');
							_delay_ms(2000);
						}
						else if(key==9){
							id[i]='k';
							Lcd_vidWriteChar('k');
							_delay_ms(2000);
						}
						else if(key=='*'){
							id[i]='l';
							Lcd_vidWriteChar('l');
							_delay_ms(2000);
						}
						else if(key==0){
							id[i]='m';
							Lcd_vidWriteChar('m');
							_delay_ms(2000);
						}
						else if(key=='/'){
							id[i]='n';
							Lcd_vidWriteChar('n');
							_delay_ms(2000);
						}
					}
				}
					loc+=0x01;
				}
				do{
					key=Keypad_u8GetKey();
				}
				while(key!='=');
				count++;
			}
			while((strcmp(id,id1)!=0)&&(strcmp(id,id2)!=0)&&(strcmp(id,id3)!=0)&&(count<3));
			if((strcmp(id,id1)!=0)&&(strcmp(id,id2)!=0)&&(strcmp(id,id3)!=0)){
				Lcd_vidSendCommand(0x01);
				for(i=0; i<5; i++){
					Lcd_vidSendCommand(error_loc1);
					Lcd_vidWriteChar(error[i]);
					error_loc1+=0x01;
				}
				_delay_ms(5000);
			}
		}

		else if(x==0){
			do{
				for(i=0; i<3; i++){
					key=Keypad_u8GetKey();
					Lcd_vidSendCommand(loc2);
					if(key!=0xFF){
					if((key!='=')&&(key!='#')&&(key!='+')&&(key!='*')&&(key!='/')&&(key!='-')){
						if(key==0){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==1){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==2){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==3){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==4){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==5){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==6){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==7){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==8){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}
						else if(key==9){
							pass[i]=key;
							Lcd_vidWriteChar(key+'0');
							_delay_ms(2000);
						}


					}
				}
					loc2+=0x01;
				}
				do{
					key=Keypad_u8GetKey();
				}
				while(key!='=');
				count1++;
			}
			while((strcmp(pass,pass1)!=0)&&(strcmp(pass,pass2)!=0)&&(strcmp(pass,pass3)!=0)&&(count1<3));
			if((strcmp(pass,pass1)!=0)&&(strcmp(pass,pass2)!=0)&&(strcmp(pass,pass3)!=0)){
				Lcd_vidSendCommand(0x01);
				for(i=0; i<5; i++){
					Lcd_vidSendCommand(error_loc2);
					Lcd_vidWriteChar(error[i]);
					error_loc2+=0x01;
				}
				_delay_ms(5000);
			}
		}
	}

	return 0;
}


