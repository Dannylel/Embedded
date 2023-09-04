/*
 * Uart_int.h
 *
 *  Created on: Jun 19, 2020
 *      Author: Dan
 */

#ifndef UART_INT_H_



#define UART_INT_H_


void Uart_vidInit(void);

void Uart_vidSendByte(u8 Byte);

u8 Uart_u8ReceiveByte(void);



#endif /* UART_INT_H_ */
