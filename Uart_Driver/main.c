/*
 * main.c
 *
 *  Created on: Jun 19, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Uart_priv.h"
#include"Uart_int.h"
#include"Uart_cfg.h"
#include"Led_int.h"
int main(void){

	u8 App_u8ReceivedData; //Variable to receive data using UART

	Uart_vidInit();		//Initialize Uart
	Led_vidInit(Led_1);	//Initialize Led_1
	while(1){

		App_u8ReceivedData= Uart_u8ReceiveByte();	//Receive data from UART
		if(App_u8ReceivedData=='a'){	//Check if received data is'a'
			//Turn on Led_1 and send On using UART
			Led_vidTurnOn(Led_1);
			Uart_vidSendByte('O');
			Uart_vidSendByte('n');
			Uart_vidSendByte('\r');
			Uart_vidSendByte('\n');
		}
		else if(App_u8ReceivedData=='s'){	//Check if received data is's'
			//Turn off Led_1 and send Off using UART
			Led_vidTurnOff(Led_1);
			Uart_vidSendByte('O');
			Uart_vidSendByte('f');
			Uart_vidSendByte('f');
			Uart_vidSendByte('\r');
			Uart_vidSendByte('\n');
		}

	}
	return 0;
}

