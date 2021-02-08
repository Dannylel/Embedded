/*
 * Voltmeter_prg.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Dan
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"Lcd_int.h"
#include"ADC_int.h"
#include"Voltmeter_int.h"

#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/io.h>




