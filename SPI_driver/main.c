/*
 * main.c
 *
 *  Created on: Jun 20, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"

#undef F_CPU
#define F_CPU 8000000
#include""
#include"Spi_int.h"


int main(void){



	while(1){

		ReceivedData = Spi_u8SlaveTransfer(SPI_u8DUMMY_DATA);
		if(ReceievedData == 'a'){
			Led_vidTurnOn(Led_1);
		}
		else if(ReceivedData = 's'){
			Led_vidTurnOff(Led_1);
		}
	}

	return 0;
}
