/*
 * Lcd_prg.c
 *
 *  Created on: Jan 31, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include"Lcd_int_bouncing.h"


void Lcd_vidSendCommand(u8 Cmd){
	CLR_BIT(PORTB,0);  //RS Pin cleared
	CLR_BIT(PORTB,1);  //RW Pin cleared because we always wanna write
	PORTA=Cmd;
	SET_BIT(PORTB,2); //EN
	_delay_ms(2);
	CLR_BIT(PORTB,2); //EN
}

void Lcd_vidWriteChar(char Char){
	SET_BIT(PORTB,0);  //RS Pin set
	CLR_BIT(PORTB,1);  //RW Pin cleared because we always wanna write
	PORTA=Char;
	SET_BIT(PORTB,2); //EN
	_delay_ms(2);
	CLR_BIT(PORTB,2); //EN
}

void Lcd_vidInit(void){
	DDRA=0xFF;
	DDRB=0xFF;
	Lcd_vidSendCommand(0x38); 	 //Function Set 8bit 2 line 5x7
	_delay_ms(2);
	Lcd_vidSendCommand(0x0C); 	//Display ON Cursor OFF
	_delay_ms(2);
	Lcd_vidSendCommand(0x01);	//Clear Display
	_delay_ms(2);
}

void Lcd_MoveCursor(u8 Pos){
	for(int i=0; i<Pos; i++){
		Lcd_vidSendCommand(20);
	}
}
