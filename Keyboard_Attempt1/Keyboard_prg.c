/*
 * Keyboard_prg.c
 *
 *  Created on: Jun 24, 2020
 *      Author: Dan
 */


#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Keyboard_priv.h"
#include"Keyboard_int.h"
#include"Keyboard_cfg.h"
#include"Uart_int.h"
#include"Uart_priv.h"
#include"Lcd_int.h"
#include"Lcd_cfg.h"

void Keyboard_vidInit(void){
	Lcd_vidInit();

	//Lcd_vidSendCommand(0x80);
	Uart_vidInit();
}

void Keyboard_vidReceivedKey(void){

	extern u8 EscFlag,ExtendedFlag, Cursor;
	u8 CursorPosition[2][16],i,j,Keyboard_u8ReceivedKey;
	/*******Filling our Cursor Tracker Array*********
	CursorPosition[0][0]=0x7F,CursorPosition[1][0]=0xBF;
	for(i=0; i<2; i++){
		for(j=0; j<16; j++){
			CursorPosition[i][j]++;
		}
	}
	************************************************/
	//Getting data from UART
	Keyboard_u8ReceivedKey = Uart_u8ReceiveByte();


	//Checking if Data sent is Normal Characters
	if((Keyboard_u8ReceivedKey!=Keyboard_u8Esc)&&(EscFlag==Keyboard_u8FlagCleared)&&(Keyboard_u8ReceivedKey!=Keyboard_u8Enter)&&(Keyboard_u8ReceivedKey!=Keyboard_u8Space)&&(Keyboard_u8ReceivedKey!=Keyboard_u8Backspace)){
		if(Cursor<=0x8F){
			if(Cursor==0x8F){
				Lcd_vidSendCommand(Cursor);
				Lcd_vidWriteChar(Keyboard_u8ReceivedKey);
				Cursor=0xC0;
			}
			else{
				Lcd_vidSendCommand(Cursor);
				Lcd_vidWriteChar(Keyboard_u8ReceivedKey);
				Cursor++;
			}
		}
		else if((Cursor>0x8F)&&(Cursor<0xC0)){
			Cursor=0x8F;
		}
		else if(Cursor<=0xCF){
			if(Cursor==0xCF){
				Lcd_vidSendCommand(Cursor);
				Lcd_vidWriteChar(Keyboard_u8ReceivedKey);
				Cursor=0xCF;
			}
			else {
				Lcd_vidSendCommand(Cursor);
				Lcd_vidWriteChar(Keyboard_u8ReceivedKey);
				Cursor++;
			}
		}
		//Returning Name of Pressed Key via UART as a method of testing
		Uart_vidSendByte(Keyboard_u8ReceivedKey);
		Uart_vidSendByte(Keyboard_u8Carriage_Return);
		Uart_vidSendByte(Keyboard_u8Newline);



	}

	else if(Keyboard_u8ReceivedKey==Keyboard_u8Esc){
		//Setting Esc Flag indicating the possibility of Esc key, arrow key or delete key being pressed
		EscFlag=Keyboard_u8FlagSet;
	}
	else {
		switch(Keyboard_u8ReceivedKey){
		case Keyboard_u8Enter: //Enter
			//if cursor is on second line, jump to first space in second line. if on second line do nothing
			if(Cursor<=0x8F){
				Cursor=0xC0;
				Lcd_vidSendCommand(Cursor);
			}
			else if(Cursor<=0xCF){
				Cursor=0x80;
				Lcd_vidSendCommand(Cursor);
			}
			Uart_vidSendByte('E');
			Uart_vidSendByte('N');
			Uart_vidSendByte('T');
			Uart_vidSendByte('E');
			Uart_vidSendByte('R');
			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			break;

		case Keyboard_u8Backspace: //Backspace
			//put " " on cursor location and shift cursor location to left by one per backspace
			if(Cursor>=0x80){
				if(Cursor==0x80){
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor=0x80;
				}
				else if((Cursor>0x80)&&(Cursor<=0x8F)){
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor--;
				}
			}
			else if(Cursor>=0xC0){
					if(Cursor==0xC0){
						Lcd_vidSendCommand(Cursor);
						Lcd_vidWriteChar(' ');
						Cursor=0x8F;
					}
					else if((Cursor>0x8F)&&(Cursor<0xC0)){
						Cursor=0x8F;
						Lcd_vidSendCommand(Cursor);
					}
					else {
						Lcd_vidSendCommand(Cursor);
						Lcd_vidWriteChar(' ');
						Cursor--;
					}
			}
			//Returning Name of Pressed Key via UART as a method of testing
			Uart_vidSendByte('B');
			Uart_vidSendByte('A');
			Uart_vidSendByte('C');
			Uart_vidSendByte('K');
			Uart_vidSendByte('S');
			Uart_vidSendByte('P');
			Uart_vidSendByte('A');
			Uart_vidSendByte('C');
			Uart_vidSendByte('E');
			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			break;

		case Keyboard_u8Space:	//Space
			if(Cursor<=0x8F){
				if(Cursor==0x8F){
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor=0xC0;
				}
				else{
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor++;
				}
			}
			else if(Cursor<=0xCF){
				if(Cursor==0xCF){
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor=0xCF;
				}
				else {
					Lcd_vidSendCommand(Cursor);
					Lcd_vidWriteChar(' ');
					Cursor++;
				}
			}
			//Returning Name of Pressed Key via UART as a method of testing
			Uart_vidSendByte('S');
			Uart_vidSendByte('P');
			Uart_vidSendByte('A');
			Uart_vidSendByte('C');
			Uart_vidSendByte('E');
			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			break;
		}
	}
	//Checking for Esc flag
	if(EscFlag==Keyboard_u8FlagSet){
		if(Keyboard_u8ReceivedKey==Keyboard_u8Extended){
			ExtendedFlag=Keyboard_u8FlagSet;
		}
		else {
			//Esc key is pressed
			Cursor=0x80;
			Lcd_vidSendCommand(ClearDisplay);
			Lcd_vidSendCommand(InitialPosition);
			EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
		}
	}//Checking for arrow Keys
	if((EscFlag==Keyboard_u8FlagSet)&&(ExtendedFlag==Keyboard_u8FlagSet)){
		switch(Keyboard_u8ReceivedKey){
		case Keyboard_u8Up:

			if((Cursor<=0xCF)&&(Cursor>=0xC0)){
				Cursor-=0x40;
				Lcd_vidSendCommand(Cursor);
			}
			else if((Cursor<=0x8F)&&(Cursor>=0x80)){
				Lcd_vidSendCommand(Cursor);
			}
			Uart_vidSendByte('U');
			Uart_vidSendByte('P');
			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			//Clearing Flags
			EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
			break;
		case Keyboard_u8Down:
			if((Cursor<=0x8F)&&(Cursor>=0x80)){
				Cursor+=0x40;
				Lcd_vidSendCommand(Cursor);
			}
			else if((Cursor<=0xCF)&&(Cursor>=0xC0)){
				Lcd_vidSendCommand(Cursor);
			}
			Uart_vidSendByte('D');
			Uart_vidSendByte('O');
			Uart_vidSendByte('W');
			Uart_vidSendByte('N');

			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
			break;
		case Keyboard_u8Right:
			//put cursor control and fix arrow key flag in all arrows
			Lcd_vidPrintStr("Right");
			Uart_vidSendByte('R');
			Uart_vidSendByte('I');
			Uart_vidSendByte('G');
			Uart_vidSendByte('H');
			Uart_vidSendByte('T');

			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
			break;
		case Keyboard_u8Left:
			//put cursor control
			Lcd_vidPrintStr("Left");
			Uart_vidSendByte('L');
			Uart_vidSendByte('E');
			Uart_vidSendByte('F');
			Uart_vidSendByte('T');

			Uart_vidSendByte(Keyboard_u8Carriage_Return);
			Uart_vidSendByte(Keyboard_u8Newline);
			EscFlag=Keyboard_u8FlagCleared,ExtendedFlag=Keyboard_u8FlagCleared;
			break;
		}
	}





}


