/*
 * Bit_math.h
 *
 *  Created on: Jan 18, 2020
 *      Author: Dan
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,Bit) Reg|=(1<<Bit)
#define CLR_BIT(Reg,Bit) Reg&=~(1<<Bit)
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&1)

#endif /* BIT_MATH_H_ */
