/*
 * SPI_prg.c
 *
 *  Created on: Jun 20, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Spi_priv.h"
#include"Spi_int.h"
#include"Dio_int.h"
void Spi_vidMasterInit(void){

	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8OUTPUT);
	//Enable SPI module
	SET_BIT(SPCR,6);
	//Select MSB data order
	CLR_BIT(SPCR,5);
	//Select Master Role
	SET_BIT(SPCR,4);

	//Select Idle High (Rising/Leading Edge)
	SET_BIT(SPCR,3);

	//Select Setup first at Leading edge
	SET_BIT(SPCR,2);

	//Select F_osc/64 SCK
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	CLR_BIT(SPSR,0); //SPI2X (double speed control disabled)

}

void Spi_vidSlaveInit(void){

	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);
	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8INPUT);



	//Enable SPI module
	SET_BIT(SPCR,6);
	//Select MSB data order
	CLR_BIT(SPCR,5);
	//Select Slave Role
	SET_BIT(SPCR,4);

	//Select Idle High (Rising/Leading Edge)
	SET_BIT(SPCR,3);

	//Select Setup first at Leading edge
	SET_BIT(SPCR,2);


	//Select Idle High (Rising/Leading Edge)
	SET_BIT(SPCR,3);

	//Select Setup first at Leading edge
	SET_BIT(SPCR,2);


}



u8 Spi_u8MasterTransfer(u8 Data){
	//Activate Slave using SS pin
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8LOW);
	//Waiting for the data to be transfered
	SPDR = Data;
	//Waiting till the transfer is complete
	while(GET_BIT(SPSR,7)==0);

	//Release Slave
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);

	//Return receieved data
	return SPDR;
}


u8 Spi_u8SlaveTransfer(u8 Data){

	//Waiting for the data to be transfered
	SPDR = Data;
	//Waiting till the transfer is complete
	while(GET_BIT(SPSR,7)==0);

	//Return receieved data
	return SPDR;
}

/*						DIO CONFIG
						MASTER | SLAVE
 *						______________
PB4	12	SS				O/P		 I/P (PULL-UP)
PB5	13	MOSI 			O/P		 I/P
PB6	14	MISO			I/P		 O/P
PB7	15	SCK				O/P		 I/P
 *
 */
