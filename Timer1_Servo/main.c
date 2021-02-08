/*
 * main.c
 *
 *  Created on: Feb 28, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include<avr/io.h>
#include<util/delay.h>

/*SERVO CONNECTIONS
BROWN=GND
RED=VCC
ORANGE=PWM
 */

int main(void){
	u16 y=300;//MY 0 ANGLE
	u16 x=1130;//MY 90 ANGLE
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);	//PD5
	SET_BIT(TCCR1A,7);//SET ON TOP
	CLR_BIT(TCCR1A,6);//CLEAR ON COMPARE

	SET_BIT(TCCR1A,1);//	FAST
	CLR_BIT(TCCR1A,0);//	PWM
	SET_BIT(TCCR1B,4);//	ICR1->TOP
	SET_BIT(TCCR1B,3);//
	CLR_BIT(TCCR1B,2);//	PRESCALER
	SET_BIT(TCCR1B,1);//		/
	CLR_BIT(TCCR1B,0);//		8
	ICR1=20000;
	for(x=300;x<2500; x++){
		OCR1A=x;
		_delay_us(100);
	}
	for(x=2500;x>300; x--){
		OCR1A=x;
		_delay_us(100);
	}
	while(1){

	}
	return 0;
}




