/*
 * main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Dan
 */
#include<avr/io.h>
#include<util/delay.h>

int main(void){

	DDRB=0xFF;
	while(1){

		PORTB=0b00000001;
		_delay_ms(4000);
		PORTB=0b00000000;
		_delay_ms(5000);
		PORTB=0b00000010;
		_delay_ms(3000);
		PORTB=0b00000000;
		_delay_ms(3000);
	}
	return 0;
}

