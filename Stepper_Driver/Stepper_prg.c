/*
 * Stepper_prg.c
 *
 *  Created on: Feb 13, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include"Dio_int.h"
#include"Stepper_cfg.h"
#include"Stepper_int.h"
#include<avr/io.h>

void Stepper_vidInit(void){
	Dio_vidSetPinDir(Stepper_Motor_u8PIN_A,DIO_u8OUTPUT);
	Dio_vidSetPinDir(Stepper_Motor_u8PIN_B,DIO_u8OUTPUT);
	Dio_vidSetPinDir(Stepper_Motor_u8PIN_C,DIO_u8OUTPUT);
	Dio_vidSetPinDir(Stepper_Motor_u8PIN_D,DIO_u8OUTPUT);
}

void Stepper_vidDirection(char direction, u8 angle){
	u8 x;
	if(direction=='L'){
		switch(angle){
		case 90:
			for(x=0; x<135; x++){
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8HIGH);
				_delay_us(1000);

				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);


				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);


				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);
			}
			break;

		case 180:
			for(x=0; x<250; x++){
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8HIGH);
				_delay_us(1000);

				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);


				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);


				Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8HIGH);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
				Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
				_delay_us(1000);
			}
			break;


		}
	}


		else if(direction=='R'){
			switch(angle){
			case 90:

				for(x=0; x<135; x++){
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);

					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);


					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);


					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8HIGH);
					_delay_us(850);
				}
				break;

			case 180:
				for(x=0; x<250; x++){
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);

					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);


					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8HIGH);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8LOW);
					_delay_us(850);


					Dio_vidSetPinVal(Stepper_Motor_u8PIN_A,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_B,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_C,DIO_u8LOW);
					Dio_vidSetPinVal(Stepper_Motor_u8PIN_D,DIO_u8HIGH);
					_delay_us(850);
				}
				break;
			}
		}
	}
