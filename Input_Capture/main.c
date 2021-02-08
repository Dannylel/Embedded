/*
 * main.c
 *
 *  Created on: Mar 6, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include<avr/io.h>
#include"Lcd_int.h"
#include<util/delay.h>
#include<avr/interrupt.h>
u32 OVF_count;
u8 state,first_Reading;
f32 Ton,Toff,Ttot;
f32 freq,Duty;
void init(void);
ISR(TIMER1_OVF_vect);
ISR(TIMER1_CAPT_vect);
int main(void){
	u8 word[10]={'F','r','e','q','='};
	u8 word1[10]={'D','u','t','y'};
	u8 i;
	Lcd_vidInit();
	init();
	while(1){

		Ttot=Ton+Toff;
		freq=(f32)1/Ttot;
		Duty=(Ton*(f32)100)/Ttot;
		Lcd_vidSendCommand(0x80);
		for(i=0; i<5; i++){
			Lcd_vidWriteChar(word[i]);
		}
		//FREQUENCY
		Lcd_vidWriteChar(((u8)freq/100)+'0');
		Lcd_vidWriteChar((((u8)freq%100)/10)+'0');
		Lcd_vidWriteChar((((u8)freq%100)%10)+'0');
		Lcd_vidWriteChar('H');
		Lcd_vidWriteChar('Z');

		//DUTY CYCLE
		Lcd_vidSendCommand(0xC0);
		for(i=0; i<4; i++){
			Lcd_vidWriteChar(word1[i]);
		}
		Lcd_vidWriteChar(((u8)Duty/100)+'0');
		Lcd_vidWriteChar((((u8)Duty%100)/10)+'0');
		Lcd_vidWriteChar((((u8)Duty%100)%10)+'0');
		Lcd_vidWriteChar('%');
	}
	return 0;
}


ISR(TIMER1_OVF_vect){
	OVF_count++;
}
ISR(TIMER1_CAPT_vect){
	if(first_Reading==0){
		TCNT1=0;
		CLR_BIT(TCCR1B,6);
		state=1;
		OVF_count=0;
		first_Reading = 1;
	}
	else {
		if(state==1){
			TCNT1=0;
			SET_BIT(TCCR1B,6);
			Ton=(f32)(ICR1+(65536*OVF_count))/(f32)8000000;
			state=0;
			OVF_count=0;
		}
		else {
			TCNT1=0;
			CLR_BIT(TCCR1B,6);
			Toff=(f32)(ICR1+(65536*OVF_count))/(f32)8000000;
			state=1;
			OVF_count=0;
		}
	}
}

void init(void){
	CLR_BIT(TCCR1A,1);//	NORMAL
	CLR_BIT(TCCR1A,0);//	MODE
	CLR_BIT(TCCR1B,3);//	NORMAL
	CLR_BIT(TCCR1B,4);//	MODE

	SET_BIT(TCCR1B,6);//INPUT CAPTURE EDGE SELECT(RISING EDGE IF SET, FALLING EDGE IF CLEARED)
	CLR_BIT(TCCR1B,2);//	NO
	CLR_BIT(TCCR1B,1);//	PRESCALER
	SET_BIT(TCCR1B,0);//	USED

	SET_BIT(TIMSK,5);//ENABLE INPUT CATPURE INTERRUPT
	SET_BIT(TIMSK,2);//ENABLE OVERFLOW INTERRUPT


	SET_BIT(SREG,7);//ENABLING GLOBAL INTERRUPTS

	Dio_vidSetPinDir(DIO_u8PIN_30,DIO_u8INPUT);
}
