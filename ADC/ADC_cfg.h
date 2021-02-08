/*
 * ADC_cfg.h
 *
 *  Created on: Mar 21, 2020
 *      Author: Dan
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADC_u8AREF		1
#define ADC_u8AVCC		2
#define ADC_u8_2_56V	3

#define ADC_u8LEFT_ADJUST	0
#define ADC_u8RIGHT_ADJUST	1

#define ADC_u8TRIGGER_SOURCE_DISABLED 						0
#define ADC_u8TRIGGER_SOURCE_FREE_RUN 					    1
#define ADC_u8TRIGGER_SOURCE_ANALOG_COMPARATOR			    2
#define ADC_u8TRIGGER_SOURCE_EXTERNAL_INTERRUPT_REQUEST_0   3
#define ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_0_COMPARE_MATCH  4
#define ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_0_OVERFLOW	    5
#define ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_COMPARE_MATCH_B  6
#define ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_1_OVERFLOW	    7
#define ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_1_CAPTURE_EVENT  8

#define ADC_u8INTERRUPT_BASED	1
#define ADC_u8POOLING_BASED		2

#define ADC_u8FCPU_2	1
#define ADC_u8FCPU_4	2
#define ADC_u8FCPU_8	3
#define ADC_u8FCPU_16	4
#define ADC_u8FCPU_32	5
#define ADC_u8FCPU_64	6
#define ADC_u8FCPU_128	7



/***************
 * Reference Voltage Configuration:
 * Select one of the following:
 *
 * ADC_u8AREF
 * ADC_u8AVCC
 * ADC_u8_2_56V
 *
 * example: #define ADC_u8REF_VOLT 		ADC_u8AREFF
 **************/
#define ADC_u8REF_VOLT  ADC_u8AVCC

/***************
 * Result Adjustment Configuration:
 * Select one of the following:
 *
 * ADC_u8LEFT_ADJUST
 * ADC_u8RIGHT_ADJUST
 *
 * example: #define ADC_u8RESULT_ADJUST 	ADC_u8LEFT_ADJUST
 ***************/
#define ADC_u8RESULT_ADJUST ADC_u8RIGHT_ADJUST
/***************
 * Auto Trigger Configuration:
 * Select one of the following:
 *
 * ADC_u8TRIGGER_SOURCE_DISABLED
 * ADC_u8TRIGGER_SOURCE_FREE_RUN
 * ADC_u8TRIGGER_SOURCE_ANALOG_COMPARATOR
 * ADC_u8TRIGGER_SOURCE_EXTERNAL_INTERRUPT_REQUEST_0
 * ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_0_COMPARE_MATCH
 * ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_0_OVERFLOW
 * ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_COMPARE_MATCH_B
 * ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_1_OVERFLOW
 * ADC_u8TRIGGER_SOURCE_TIMER_COUNTER_1_CAPTURE_EVENT
 *
 * example: #define ADC_u8AUTO_TRIGGER	ADC_u8TRIGGER_SOURCE_DISABLED
 ***************/
#define ADC_u8AUTO_TRIGGER	ADC_u8TRIGGER_SOURCE_DISABLED

#define ADC_u8PRESCALER_VALUE
/***************
 * ADC Implementation Configuration:
 * Select one of the following:
 *
 * ADC_U8INTERRUPT_BASED
 * ADC_U8POOLING_BASED
 *
 * example: #define ADC_u8IMPLEMENTATION_BASED	ADC_u8INTERRUPT_BASED
 ***************/
#define ADC_u8IMPLEMENTATION_BASED	ADC_u8POOLING_BASED
/***************
 * ADC Prescaler Configuration:
 * Select one of the following:
 *
 * ADC_u8FCPU_2
 * ADC_u8FCPU_4
 * ADC_u8FCPU_8
 * ADC_u8FCPU_16
 * ADC_u8FCPU_32
 * ADC_u8FCPU_64
 * ADC_u8FCPU_128
 *
 * example: #define ADC_u8PRESCALER_VALUE	ADC_u8FCPU_2
 **************/
#define ADC_u8PRESCALER_VALUE	ADC_u8FCPU_8




#endif /* ADC_CFG_H_ */
