/*
 * Dio_prg.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_Priv.h"
#include"Dio_int.h"

void Dio_vidSetPinDir(u8 Pin, u8 Dir){
	u8 PortId;
	u8 PinLoc;
	PortId=Pin/8;
	PinLoc=Pin%8;
	switch(PortId){
	case 0:	//DDRA
		if(Dir==1){
			SET_BIT(DDRA.Byte,PinLoc);
		}
		else {
			CLR_BIT(DDRA.Byte,PinLoc);
		}
		break;
	case 1:	//DDRB
		if(Dir==1){
			SET_BIT(DDRB.Byte,PinLoc);
		}
		else {
			CLR_BIT(DDRB.Byte,PinLoc);
		}
		break;
	case 2:	//DDRC
		if(Dir==1){
			SET_BIT(DDRC.Byte,PinLoc);
		}
		else {
			CLR_BIT(DDRC.Byte,PinLoc);
		}
		break;
	case 3:	//DDRD
		if(Dir==1){
			SET_BIT(DDRD.Byte,PinLoc);
		}
		else {
			CLR_BIT(DDRD.Byte,PinLoc);
		}
		break;
	}
}

void Dio_vidSetPinVal(u8 Pin, u8 Val){
	u8 PortId;
	u8 PinLoc;
	PortId=Pin/8;
	PinLoc=Pin%8;
	switch(PortId){
	case 0:
		if(Val==1){
			SET_BIT(PORTA,PinLoc);
		}
		else {
			CLR_BIT(PORTA,PinLoc);
		}
		break;
	case 1:
		if(Val==1){
			SET_BIT(PORTB,PinLoc);
		}
		else {
			CLR_BIT(PORTB,PinLoc);
		}
		break;
	case 2:
		if(Val==1){
			SET_BIT(PORTC,PinLoc);
		}
		else {
			CLR_BIT(PORTC,PinLoc);
		}
		break;
	case 3:
		if(Val==1){
			SET_BIT(PORTD,PinLoc);
		}
		else {
			CLR_BIT(PORTD,PinLoc);
		}
		break;
	}
}

u8 Dio_u8GetPinVal(u8 Pin){
	u8 PortId;
	u8 PinLoc;

	u8 ReturnResult= 0;

	PortId=Pin/8;
	PinLoc=Pin%8;
	switch(PortId){
	case 0:	//PINA
		ReturnResult = Get_BIT(PINA,PinLoc);
		break;
	case 1:	//PINB
		ReturnResult = Get_BIT(PINB,PinLoc);
		break;
	case 2:	//PINC
		ReturnResult = Get_BIT(PINC,PinLoc);
		break;
	case 3:	//PIND
		ReturnResult = Get_BIT(PIND,PinLoc);
		break;
	}
}


