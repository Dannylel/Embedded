/*
 * Lcd_int.h
 *
 *  Created on: Jan 31, 2020
 *      Author: Dan
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_



#endif /* LCD_INT_H_ */


void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteChar(char Char);
void Lcd_MoveCursor(u8 Pos);
