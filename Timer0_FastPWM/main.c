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
#include"LED_int.h"
#include<avr/interrupt.h>
#include<util/delay.h>

int main(void){

	u8 x,y,z;
	Dio_vidSetPinDir(DIO_u8PIN_11,DIO_u8OUTPUT);//PB3
	SET_BIT(TCCR0,6);//TIMER FAST
	SET_BIT(TCCR0,3);//	PWM MODE

	SET_BIT(TCCR0,5);//SET ON TOP
	CLR_BIT(TCCR0,4);//CLEAR ON COMPARE

	CLR_BIT(TCCR0,2);//	NO
	CLR_BIT(TCCR0,1);//	PRESCALER
	SET_BIT(TCCR0,0);//	USED(PRESCALER/1)


		while(1){

			for(x=10; x<50; x++){
				OCR0=x;
				_delay_ms(5);
			}

			for(x=50; x>0; x--){
				OCR0=x;
				_delay_ms(5);
			}

		}
		return 0;
	}




