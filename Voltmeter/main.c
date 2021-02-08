/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Lcd_int.h"
#include"ADC_int.h"
#include"Voltmeter_int.h"

#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>
int main(void){
	Dio_vidSetPinDir(DIO_u8PIN_24,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8HIGH);
	Lcd_vidInit();
	Adc_vidInit();
	f32 analog;
	u16 digital;
	u8 x;
	while(1){
		//x=GET_BIT(DDRD,0);
		digital=Adc_u16GetResult(Adc_u8CH_0);
		analog=((f32)digital*5.0f)/1024.0f;
		x=PIND;
		if(x==1){

			Lcd_vidSendCommand(0x81);
			Lcd_vidWriteChar((int)analog+'0');
			Lcd_vidSendCommand(0x82);
			Lcd_vidWriteChar(46);
			Lcd_vidSendCommand(0x83);
			Lcd_vidWriteChar((int)(analog*10)%10+'0');
			Lcd_vidSendCommand(0x84);
			Lcd_vidWriteChar('V');

		}
		else if(x==0){
			Lcd_vidSendCommand(0x81);
			Lcd_vidWriteChar((int)analog+'0');
			Lcd_vidSendCommand(0x82);
			Lcd_vidWriteChar(46);
			Lcd_vidSendCommand(0x83);
			Lcd_vidWriteChar((int)(analog*10)%10+'0');
			Lcd_vidSendCommand(0x84);
			Lcd_vidWriteChar(((int)(analog*100)%100)%10+'0');
			Lcd_vidSendCommand(0x85);
			Lcd_vidWriteChar(((int)(analog*1000)%1000)%10+'0');
			Lcd_vidSendCommand(0x86);
			Lcd_vidWriteChar('m');
			Lcd_vidSendCommand(0x87);
			Lcd_vidWriteChar('V');



		}


		_delay_ms(350);
		Lcd_vidSendCommand(0x01);
	}
	return 0;
}
