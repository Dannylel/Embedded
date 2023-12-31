/*
 * main.c
 *
 *  Created on: Jun 28, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include<avr/io.h>
#include"Dio_int.h"
#include<util/delay.h>
#include"Uart_int.h"
#include"Led_int.h"


int main(void){

	u8 ReceivedData;
	Uart_vidInit();

	Dio_vidSetPinDir(DIO_u8PIN_23,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_22,DIO_u8OUTPUT);
	while(1){
		ReceivedData=Uart_u8ReceiveByte();
		if(ReceivedData=='r'){

			Dio_vidSetPinVal(DIO_u8PIN_23,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_22,DIO_u8LOW);

		}
		else if(ReceivedData=='g'){
			Dio_vidSetPinVal(DIO_u8PIN_22,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_23,DIO_u8LOW);

		}

	}

	return 0;
}
