/*
 * sevenseg.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Dan
 */
#undef F_CPU
#define F_CPU 8000000
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Seven_Segment_cfg.h"
#include"Seven_Segment_int.h"
#include<avr/io.h>
#include<util/delay.h>

//              0         1         2        3          4        5         6         7          8         9
u8 arr[10]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1011000,0b0000000,0b0010000};
void Seven_Seg_u8Write(u8 number){
	u16 mod1,mod2;
	if((number<=99)&&(number>=0)){
		mod1=number/10;
		mod2=number%10;
		Seven_Seg1_num=arr[mod1];
		Seven_Seg2_num=arr[mod2];
	}
}
void Seven_Seg_vidInit(u8 disp){
	switch(disp){
	case 0:
		//Set pins to output for 1st seven segment only
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_a,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_b,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_c,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_d,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_e,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_f,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_g,DIO_u8_OUTPUT);
		//Displaying 0 on 1st seven segment only
		Seven_Seg1_num=arr[0];
		break;
	case 1:
		//Set pins to output for 2nd seven segment only
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_a,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_b,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_c,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_d,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_e,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_f,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_g,DIO_u8_OUTPUT);
		//Displaying 0 on 2nd seven segment only
		Seven_Seg2_num=arr[0];
		break;
	case 2:
		//Set pins to output for both seven segments
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_a,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_b,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_c,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_d,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_e,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_f,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg1_u8_PIN_g,DIO_u8_OUTPUT);

		Dio_vidSetPinDir(SevenSeg2_u8_PIN_a,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_b,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_c,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_d,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_e,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_f,DIO_u8_OUTPUT);
		Dio_vidSetPinDir(SevenSeg2_u8_PIN_g,DIO_u8_OUTPUT);
		//Displaying 0 on both seven segments
		Seven_Seg1_num=arr[0];
		Seven_Seg2_num=arr[0];
		break;
	default:
		break;
	}
}
