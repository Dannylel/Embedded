/*
 * main.c
 *
 *  Created on: Feb 28, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"LED_int.h"
#include<avr/io.h>
#include<avr/interrupt.h>

void MyDelay_ms(u32 Time);
u32 OVF_Counts;
u32 ms_counts;
u32 T_desired;
u8 End;
int main(void){


	while(1){
		Led_vidInit(Led_1);
		PORTA=0xFF;
	//	Led_u8TurnON(Led_1);
		MyDelay_ms(500);
	//	Led_u8TurnOFF(Led_1);
		PORTA=0x00;
		MyDelay_ms(500);

	}
	return 0;
}


void MyDelay_ms(u32 Time){
	ms_counts=0;
	OVF_Counts=0;
	T_desired=Time;
	End=0;
	CLR_BIT(TCCR0,6);//TIMER NORMAL
	CLR_BIT(TCCR0,3);//		 MODE

	CLR_BIT(TCCR0,2);//	NO
	CLR_BIT(TCCR0,1);//	PRESCALER
	SET_BIT(TCCR0,0);//	USED

	SET_BIT(SREG,7);// GIE
	SET_BIT(TIMSK,0);// PIE OVERFLOW INTERRUPT
	TCNT0=192;       // INITIAL VALUE (0.25%)

	while(End==0);
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);

}

ISR(TIMER0_OVF_vect){
	OVF_Counts++;
	if(OVF_Counts==32){
		TCNT0=192;
		OVF_Counts=0;
		ms_counts++;
		if(ms_counts==T_desired){
			End=1;
		}
	}
}
