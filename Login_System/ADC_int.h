/*
 * ADC_int.h
 *
 *  Created on: Feb 15, 2020
 *      Author: Dan
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

void Adc_vidInit(void);
u16 Adc_u16GetResult(u8 Chnl_Id);

#define Adc_u8CH_0  0
#define Adc_u8CH_1 	1
#define Adc_u8CH_2  2
#define Adc_u8CH_3  3
#define Adc_u8CH_4  4
#define Adc_u8CH_5  5
#define Adc_u8CH_6  6
#define Adc_u8CH_7  7
#endif /* ADC_INT_H_ */
