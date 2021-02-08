/*
 * Dio_int.h
 *
 *  Created on: Jan 18, 2020
 *      Author: Dan
 */
#ifndef DIO_INT_H_
#define DIO_INT_H_

void Dio_vidSetPinDir(u8 Pin, u8 Dir);
void Dio_vidSetPinVal(u8 Pin, u8 Val);
u8 Dio_u8GetPinVal(u8 Pin);

#define DIO_u8PIN_0	  0   //PORTA0
#define DIO_u8PIN_1   1   //PORTA1
#define DIO_u8PIN_2	  2	  //PORTA2
#define DIO_u8PIN_3   3   //PORTA3
#define DIO_u8PIN_4   4   //PORTA4
#define DIO_u8PIN_5   5   //PORTA5
#define DIO_u8PIN_6   6   //PORTA6
#define DIO_u8PIN_7   7   //PORTA7
#define DIO_u8PIN_8   8   //PORTB0
#define DIO_u8PIN_9	  9   //PORTB1
#define DIO_u8PIN_10  10  //PORTB2
#define DIO_u8PIN_11  11  //PORTB3
#define DIO_u8PIN_12  12  //PORTB4
#define DIO_u8PIN_13  13  //PORTB5
#define DIO_u8PIN_14  14  //PORTB6
#define DIO_u8PIN_15  15  //PORTB7
#define DIO_u8PIN_16  16  //PORTC0
#define DIO_u8PIN_17  17  //PORTC1
#define DIO_u8PIN_18  18  //PORTC2
#define DIO_u8PIN_19  19  //PORTC3
#define DIO_u8PIN_20  20  //PORTC4
#define DIO_u8PIN_21  21  //PORTC5
#define DIO_u8PIN_22  22  //PORTC6
#define DIO_u8PIN_23  23  //PORTC7
#define DIO_u8PIN_24  24  //PORTD0
#define DIO_u8PIN_25  25  //PORTD1
#define DIO_u8PIN_26  26  //PORTD2
#define DIO_u8PIN_27  27  //PORTD3
#define DIO_u8PIN_28  28  //PORTD4
#define DIO_u8PIN_29  29  //PORTD5
#define DIO_u8PIN_30  30  //PORTD6
#define DIO_u8PIN_31  31  //PORTD7

#define DIO_u8INVALED_PIN_NUM 2

#define DIO_u8HIGH   1
#define DIO_u8LOW    0
#define DIO_u8OUTPUT 1
#define DIO_u8INPUT 0
#endif /* DIO_NT_H_ */
