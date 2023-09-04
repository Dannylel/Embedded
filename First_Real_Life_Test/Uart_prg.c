/*
 * Uart_prg.c
 *
 *  Created on: Jun 19, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"

#include"Uart_int.h"
#include"Uart_priv.h"
#include"Uart_cfg.h"

void Uart_vidInit(void){
	u8 Temp_u8UcsrcData;	//Temp variable to set UCSRC config


	SET_BIT(UCSRB,4); //RX enabled
	SET_BIT(UCSRB,3); //TX enabled
	Temp_u8UcsrcData=0;
	CLR_BIT(UCSRB,2); //Character size: 8

	SET_BIT(Temp_u8UcsrcData,2);//Character size: 8 in UCSRC
	SET_BIT(Temp_u8UcsrcData,1);//Character size: 8 in UCSRC

	CLR_BIT(Temp_u8UcsrcData,6); //Asynchronous     in UCSRC
	CLR_BIT(Temp_u8UcsrcData,5); //Parity Disabled  in UCSRC
	CLR_BIT(Temp_u8UcsrcData,4); //Parity Disabled  in UCSRC
	CLR_BIT(Temp_u8UcsrcData,3); //1 stop bit       in UCSRC
	SET_BIT(Temp_u8UcsrcData,7); //7th bit set to 1 indicating we chose to use UCSRC using URSEL register select

	UCSRC=Temp_u8UcsrcData; //Writing UCSRC configuration

	UBRRH=0;	//Set BaudRate to 9600
	UBRRL=51;	//Set BaudRate to 9600
}

void Uart_vidSendByte(u8 Byte){

	while(GET_BIT(UCSRA,5)==0);	//Waiting for the UDRE flag
	UDR = Byte;		//Update UDR register with new data to send

}

u8 Uart_u8ReceiveByte(void){

	while(GET_BIT(UCSRA,7)==0); //Waiting for RX flag
	return UDR;		//Read UDR Received Byte
}
