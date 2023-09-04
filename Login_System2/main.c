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
//WORKING
u8 UserCheck(char *user1, char *user2);
u8 PassCheck(char *pass1, char *pass2);
void NumCheck(void);
void VerifiedUser(void);
u8 key,x,i,checker,count1,pos,flag,passflag,errorflag,jj;
u8 j=0;
char id[3];
char pass[3];

char id1[4]={'d','a','n'};
char id2[4]={'m','a','n'};
char id3[4]={'c','a','b'};
char pass1[4]={2,2,5};
char pass2[4]={3,2,7};
char pass3[4]={8,6,9};
u8 loc=0x80;
u8 loc2=0xC0;
int main(void){
	Dio_vidSetPinDir(DIO_u8PIN_6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_8,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_8,DIO_u8HIGH); //pullup resistor
	Lcd_vidInit();
	Keypad_vidInit();
	while(1){

		key=Keypad_u8GetKey();
		x=PINB;
		if(x==1){

			if((key!='=')&&(key!=0xFF)){
				Lcd_vidSendCommand(loc);
				switch(key){
				case 1:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('a');
					loc++;
					id[j]='a';
					j++;
					_delay_ms(200);
					break;
				case 2:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('b');
					loc++;
					id[j]='b';
					j++;
					_delay_ms(200);
					break;
				case 3:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('c');
					loc++;
					id[j]='c';
					j++;
					_delay_ms(200);
					break;
				case 4:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('d');
					loc++;
					id[j]='d';
					j++;
					_delay_ms(200);
					break;
				case 5:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('e');
					loc++;
					id[j]='e';
					j++;
					_delay_ms(200);
					break;
				case 6:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('f');
					loc++;
					id[j]='f';
					j++;
					_delay_ms(200);
					break;
				case 7:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('g');
					loc++;
					id[j]='g';
					j++;
					_delay_ms(200);
					break;
				case 8:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('h');
					loc++;
					id[j]='h';
					j++;
					_delay_ms(200);
					break;
				case 9:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('i');
					loc++;
					id[j]='i';
					j++;
					_delay_ms(200);
					break;
				case '+':
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('j');
					loc++;
					id[j]='j';
					j++;
					_delay_ms(200);
					break;
				case 0:
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('k');
					loc++;
					id[j]='k';
					j++;
					_delay_ms(200);
					break;
				case '#':
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('l');
					loc++;
					id[j]='l';
					j++;
					_delay_ms(200);
					break;
				case '-':
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('m');
					loc++;
					id[j]='m';
					j++;
					_delay_ms(200);
					break;
				case '*':
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('n');
					loc++;
					id[j]='n';
					j++;
					_delay_ms(200);
					break;
				case '/':
					Lcd_vidSendCommand(loc);
					Lcd_vidWriteChar('o');
					loc++;
					id[j]='o';
					j++;
					_delay_ms(200);
					break;
				}

			}
			else if(key=='='){
				Lcd_vidSendCommand(0x80);
				for(i=0; i<16; i++){
					Lcd_vidWriteChar(' ');
				}
				if(UserCheck(id,id1)==1){
					passflag=1;
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendCommand(0x80);
					Lcd_vidPrintStr("User 1");
					_delay_ms(3000);
					VerifiedUser();
				}
				else if(UserCheck(id,id2)==1){
					passflag=2;
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendCommand(0x80);
					Lcd_vidPrintStr("User 2");
					_delay_ms(3000);
					VerifiedUser();
				}
				else if(UserCheck(id,id3)==1){
					passflag=3;
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendCommand(0x80);
					Lcd_vidPrintStr("User 3");
					_delay_ms(3000);
					VerifiedUser();
				}
				else {
					if(errorflag<3){

						//display: wrong username
						Lcd_vidSendCommand(0x80);
						Lcd_vidPrintStr("Wrong Username");
						_delay_ms(1000);
						errorflag++;

					}
					else {
						errorflag=0;
						Lcd_vidSendCommand(0x01);
						//Lcd_vidSendCommand(0x85);

					}
				}

			}
		}
		else if(x==0){

			if((key!='=')&&(key!=0xFF)){
				Lcd_vidSendCommand(loc2);
				switch(key){
				case 1:
					NumCheck();
					break;

				case 2:
					NumCheck();
					break;
				case 3:
					NumCheck();
					break;
				case 4:
					NumCheck();
					break;
				case 5:
					NumCheck();
					break;
				case 6:
					NumCheck();
					break;
				case 7:
					NumCheck();
					break;
				case 8:
					NumCheck();
					break;
				case 9:
					NumCheck();
					break;
				case '+':
					Lcd_vidSendCommand(loc2);
					Lcd_vidWriteChar(key);
					loc2++;
					pass[j]=key;
					j++;
					_delay_ms(200);
					break;
				case 0:
					NumCheck();
					break;
				case '#':
					Lcd_vidSendCommand(loc2);
					Lcd_vidWriteChar(key);
					loc2++;
					pass[j]=key;
					j++;
					_delay_ms(200);
					break;
				case '-':
					Lcd_vidSendCommand(loc2);
					Lcd_vidWriteChar(key);
					loc2++;
					pass[j]=key;
					j++;
					_delay_ms(200);
					break;

				case '*':
					Lcd_vidSendCommand(loc2);
					Lcd_vidWriteChar(key);
					loc2++;
					pass[j]=key;
					j++;
					_delay_ms(200);
					break;
				case '/':
					Lcd_vidSendCommand(loc2);
					Lcd_vidWriteChar(key);
					loc2++;
					pass[j]=key;
					j++;
					_delay_ms(200);
					break;
				}
			}
			else if(key=='='){

				flag=0;
				Lcd_vidSendCommand(0xC0);
				for(i=0; i<16; i++){
					Lcd_vidWriteChar(' ');
				}
				switch(passflag){
				case 1:
					jj=PassCheck(pass,pass1);
					if(jj==1){
						//do something
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidPrintStr("Welcome User 1");
						_delay_ms(3000);
					}
					else if(jj==0){
						//do something
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidPrintStr("Wrong Password1");
					}
					else if(jj==2){
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidPrintStr("No pass");
					}
					break;
				case 2:
					if(PassCheck(pass,pass2)==1){
						//do something
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidPrintStr("Welcome User 2");
						_delay_ms(3000);
					}
					else {
						//do something
						Lcd_vidSendCommand(0xC0);
						Lcd_vidPrintStr("Wrong Password2");
					}
					break;
				case 3:

					if(PassCheck(pass,pass3)==1){
						//do something
						Lcd_vidSendCommand(0x01);
						//for(i=0; i<7; i++){
						//Lcd_vidWriteChar(welcome[i]);
						//}
						Lcd_vidSendCommand(0x80);
						Lcd_vidPrintStr("Welcome User 3!");
						//Lcd_vidWriteChar('3');
						_delay_ms(3000);
					}
					else {
						//do something
						Lcd_vidSendCommand(0xC0);
						Lcd_vidPrintStr("Wrong Password3");
					}
					break;

					//default:
					/*if(errorflag<3){

					}
					else {
						if(errorflag<3){

							//display: wrong username
								Lcd_vidPrintStr("Wrong Username");
								errorflag++;

						}
						else {
							errorflag=0;
							Lcd_vidSendCommand(0x01);
							//Lcd_vidSendCommand(0x85);

						}
					}
					break;*/
				}


				/*
				_delay_ms(4000);
				Dio_vidSetPinVal(DIO_u8PIN_6,DIO_u8HIGH);
				_delay_ms(2000);
				Dio_vidSetPinVal(DIO_u8PIN_6,DIO_u8LOW);
				for(i=0; i<16; i++){
					Lcd_vidWriteChar(' ');
				}
				Lcd_vidSendCommand(0xC0);
				Lcd_vidWriteChar('x');
				 */
			}
		}

	}

	return 0;
}

u8 UserCheck(char *user1, char *user2){//function to check user and another function to check pass
	flag=0;
	//Lcd_vidSendCommand(0x80);
	//for(i=0; i<16; i++){
	//Lcd_vidWriteChar(' ');
	//}
	for(i=0; i<3; i++){
		if(user1[i]==user2[i]){
			flag++;
		}
		else {
			break;
		}

	}
	if(flag==3){
		return 1;//for matching user
	}
	else {
		return 0;//for non-matching user
	}
}





u8 PassCheck(char *pass1, char *pass2){
	flag=0;
	for(i=0; i<3; i++){
		if(pass1[i]==pass2[i]){
			flag++;
		}
		else {
			break;
		}
	}
	if(flag==3){

		return 1;//for matching password
	}
	else if(flag<3){

		return 0;//for non-matching password
	}
	else {
		return 2;//indicating password is not entered
	}
}

void NumCheck(void){
	if(j==2){
		j=0;
	}
	else {

	}
	Lcd_vidSendCommand(loc2);
	Lcd_vidWriteChar(key+'0');
	loc2++;
	pass[j]=key;
	j++;
	_delay_ms(200);
}
void VerifiedUser(void){
	_delay_ms(4000);
	Lcd_vidSendCommand(0xC0);
	Lcd_vidPrintStr("Enter password");
	_delay_ms(2000);
	Lcd_vidSendCommand(0xC0);
	for(i=0; i<16; i++){
		Lcd_vidWriteChar(' ');
	}
	Lcd_vidSendCommand(loc2);
}

