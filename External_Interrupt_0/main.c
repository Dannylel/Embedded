/*
 * main.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"LED_int.h"
#include"Dio_int.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/interrupt.h>
int main(void){
	//GIE Global Interrupts Enabled
	SET_BIT(SREG,7);
	//Peripheral Interrupt Enable (external interrupt 0 enabled)
	SET_BIT(GICR,6);
	Led_vidInit(Led_2);
	//Clear bits to set interrupt capture to low level detection
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

	Dio_vidSetPinDir(DIO_u8_PIN26,DIO_u8_INPUT);
	Dio_vidSetPinVal(DIO_u8_PIN26,DIO_u8_HIGH);
	while(1){
		Led_vidTurnOFF(Led_2);
	}
	return 0;
}
ISR(INT0_vect){
	Led_vidTurnON(Led_2);
}
