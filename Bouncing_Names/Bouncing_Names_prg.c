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
	u8 i,j,k;
}
/*
	for(i=0; i<size; i++){
		if((i%2)==0){

		Lcd_vidSendComand(pos1[j]);
		Lcd_vidWriteChar(letter[i]);
		}
		else {

			Lcd_vidSendCommand(pos2[k]);
			Lcd_vidWriteChar(letter[i]);
		}
	}


}
	/*for(j=0; j<16; j++){
	for(i=size-1; i>=0; i--){
		if(i==size-1){
			Lcd_vidSendCommand(first);
			Lcd_vidWriteChar(letter[i]);
			_delay_ms(1000);
			first+=2;
		}
		else {
			Lcd_vidSendCommand(second);
			Lcd_vidWriteChar(letter[i-1]);
			Lcd_vidSendCommand(first-2);
			Lcd_vidWriteChar(letter[i]);
			second+=2;
			_delay_ms(1000);
		}
		Lcd_vidSendCommand(0x01);

}*/



