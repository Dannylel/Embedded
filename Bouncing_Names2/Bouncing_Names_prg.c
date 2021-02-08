/*
 * Bouncing_Names_prg.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include<string.h>
#define F_CPU 8000000
#include<util/delay.h>
#include"Lcd_int_bouncing.h"

#include<avr/io.h>

void Bouncing_Names_vidWriteName(char *letter, u8 size){
	u8 i;
	u8 first,second;

	//	if(size%2==0){
	//	first=0xC1,second=0x80;
	//	}
	//else {
	first=0x80,second=0xC1;
	//	}
	while(second<=0xCF){
		for(i=0; i<size; i++){
			if((i%2)==0){
				Lcd_vidSendCommand(first);
				if(size%2==0){
					first++;
				}
				else{
					first+=2;
				}
			}
			else if((i%2)==1){
				Lcd_vidSendCommand(second);
				//if(size%2==0){
					second+=2;
			//	else {
				//	second++;
		//		}
			}
		}
		Lcd_vidWriteChar(letter[i]);
		_delay_ms(500);
		Lcd_vidSendCommand(0x01);
	}
}
}
