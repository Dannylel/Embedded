/*
 * SPI_int.h
 *
 *  Created on: Jun 20, 2020
 *      Author: Dan
 */

#ifndef SPI_INT_H_

#define SPI_u8DUMMY_DATA 0xFF

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit(void);

u8 Spi_u8MasterTransfer(u8 Data);
u8 Spi_u8SlaveTransfer(u8 Data);


#define SPI_INT_H_



#endif /* SPI_INT_H_ */
