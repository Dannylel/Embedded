/*
 * Volume_prg.c
 *
 *  Created on: Feb 20, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Lcd_int.h"
#include"ADC_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>

u8 a[8]={0X0E,0X0E,0X0E,0X0E,0X0E,0X0E,0X0E,0x0E};  //8
u8 b[8]={0x00,0X0E,0X0E,0X0E,0X0E,0X0E,0X0E,0X0E};  //7
u8 c[8]={0x00,0x00,0X0E,0X0E,0X0E,0X0E,0X0E,0X0E};  //6
u8 d[8]={0X00,0X00,0x00,0X0E,0X0E,0X0E,0X0E,0X0E};  //5
u8 e[8]={0X00,0X00,0x00,0x00,0X0E,0X0E,0X0E,0X0E};  //4
u8 f[8]={0x00,0x00,0x00,0x00,0x00,0X0E,0X0E,0X0E};  //3
u8 g[8]={0x00,0x00,0x00,0x00,0x00,0x00,0X0E,0X0E};  //2
u8 h[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X0E};  //1



void Volume_vidInit(void){
	u8 i;
	u16 digital_volume;
	f32 analog_volume;
	digital_volume=Adc_u16GetResult(Adc_u8CH_0);
	analog_volume=((f32)digital_volume*5.0f)/1024.0f;

	if((analog_volume>0)&&(analog_volume<=0.5)){
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x83);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x40);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(h[i]);
		}
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar(0x00);
	}
	else if((analog_volume>0.5)&&(analog_volume<=1.0)){
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x83);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');

		Lcd_vidSendCommand(0x48);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(g[i]);
		}
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(0x01);
	}

	else if((analog_volume>1.0)&&(analog_volume<=1.5)){
		Lcd_vidSendCommand(0x83);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x50);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(f[i]);
		}
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(0x02);
	}

	else if((analog_volume>1.5)&&(analog_volume<=2.0)){
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x58);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(e[i]);
		}
		Lcd_vidSendCommand(0x83);
		Lcd_vidWriteChar(0x03);
	}

	else if((analog_volume>2.0)&&(analog_volume<=2.5)){
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x60);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(d[i]);
		}
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar(0x04);
	}

	else if((analog_volume>2.5)&&(analog_volume<=3.0)){
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x68);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(c[i]);
		}
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar(0x05);
	}

	else if((analog_volume>3.0)&&(analog_volume<=3.5)){
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(' ');
		Lcd_vidSendCommand(0x70);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(b[i]);
		}
		Lcd_vidSendCommand(0x86);
		Lcd_vidWriteChar(0x06);
	}

	else if((analog_volume>3.5)&&(analog_volume<=4.0)){
		Lcd_vidSendCommand(0x78);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(a[i]);
		}
		Lcd_vidSendCommand(0x87);
		Lcd_vidWriteChar(0x07);
	}

	Lcd_vidSendCommand(0x80);
}
