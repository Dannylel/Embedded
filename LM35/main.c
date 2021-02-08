/*
 * main.c
 *
 *  Created on: Feb 15, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"ADC_int.h"
#include"LED_int.h"


int main(void){
	Led_vidInit(Led_1);
	Led_vidInit(Led_2);
	Adc_vidInit();
	u16 digital;
	u8 analog;

	while(1){
		digital=Adc_u16GetResult(Adc_u8CH_0);
		analog=(digital*5)/1024;
		if(analog>2){
			Led_u8TurnON(Led_1);
			Led_u8TurnOFF(Led_2);
		}
		else {
			Led_u8TurnON(Led_2);
			Led_u8TurnOFF(Led_1);

		}
	}
	return 0;
}
