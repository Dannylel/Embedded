/*
 * blinking1.c
 *
 *  Created on: Jan 17, 2020
 *      Author: Dan
 */


#include<avr/io.h>
#undef F_CPU
#define F_CPU 8000000

#include<util/delay.h>


int main(void){
	DDRA|=(1<<0);

	while(1){

		PORTA|=(1<<0);

		_delay_ms(10);

		PORTA=0;

		_delay_ms(10);


	}
	return 0;
}
