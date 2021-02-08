/*
 * Lcd_prg.c
 *
 *  Created on: Jan 31, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"

#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include"Dio_int.h"
#include"Lcd_cfg.h"
#include"Lcd_int.h"


void Lcd_vidSendCommand(u8 Cmd){

	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8LOW);  //RS Pin cleared
	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW);  //RW Pin cleared because we always wanna write
	Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Cmd,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH); //EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW); //EN
}

void Lcd_vidWriteChar(u8 Char){
	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8HIGH);  //RS Pin set
	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW);  //RW Pin cleared because we always wanna write
	Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Char,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Char,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Char,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Char,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Char,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Char,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Char,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Char,7));
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH);   //EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW);   //EN
}

void Lcd_vidInit(void){

	Dio_vidSetPinDir(LCD_u8RS_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN_PIN,DIO_u8OUTPUT);

	Dio_vidSetPinDir(LCD_u8D0_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7_PIN,DIO_u8OUTPUT);




	Lcd_vidSendCommand(LCD_u8_CMD_8_BIT_2x16_5x7); 	 //Function Set 8bit 2 line 5x7
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8_CMD_DISP_ON_CURS_OFF); 	//Display ON Cursor OFF
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8_CMD_CLR_DISPLAY);	//Clear Display
	_delay_ms(2);
}

void Lcd_MoveCursor(u8 Pos){
	for(int i=0; i<Pos; i++){
		Lcd_vidSendCommand(16);
	}
}


void Lcd_vidPrintStr(char *word){
	u8 ii;
	while(word[ii]!='\0'){
		Lcd_vidWriteChar(word[ii]);
		ii++;
	}



}

