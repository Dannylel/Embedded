/*
 * ledwar.c
 *
 *  Created on: Jan 24, 2020
 *      Author: Dan
 */
#include<stdio.h>
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include<util/delay.h>
void led_troops(u8 n);
void reverse_led_troops(u8 n);
void light_it_up(u8 n);
u8 i,j,k,n;
int main(void){
	n=0;
	//Setting PORTA to output using for loop iterating on each bit in the register
	for(i=0; i<8; i++){
		Dio_vidSetPinDir(i,1);
	}
	while(1){
		led_troops(1);
		light_it_up(2);
		reverse_led_troops(1);
		for(i=0; i<8; i++){
			Dio_vidSetPinVal(i,0);
		}
		_delay_ms(500);
	}
	return 0;
}


void light_it_up(u8 n){
	while(n!=0){
		for(i=0; i<8; i++){
			Dio_vidSetPinVal(i,1);
		}
		_delay_ms(500);
		for(i=0; i<8; i++){
			Dio_vidSetPinVal(i,0);
		}
		_delay_ms(250);
		n--;
	}
}
void led_troops(u8 n){
	while(n!=0){
		i=0,j=7,k=0;

		for(i=0; i<4; i++){
			Dio_vidSetPinVal(j,1);
			Dio_vidSetPinVal(k,1);
			_delay_ms(500);
			Dio_vidSetPinVal(j,0);
			Dio_vidSetPinVal(k,0);
			_delay_ms(50);
			j--;
			k++;
		}
		n--;
	}
}
void reverse_led_troops(u8 n){
	while(n!=0){
		i=0,j=3,k=4;

		for(i=0; i<4; i++){
			Dio_vidSetPinVal(j,1);
			Dio_vidSetPinVal(k,1);
			_delay_ms(500);
			Dio_vidSetPinVal(j,0);
			Dio_vidSetPinVal(k,0);
			_delay_ms(50);
			j--;
			k++;
		}
		n--;
	}
}
