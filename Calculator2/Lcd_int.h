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
void Lcd_vidWriteChar(u8 Char);
void Lcd_MoveCursor(u8 Pos);
#define LCD_u8_CMD_8_BIT_2x16_5x7 0x38
#define LCD_u8_CMD_DISP_ON_CURS_OFF 0x0C
#define LCD_u8_CMD_CLR_DISPLAY 0x01
