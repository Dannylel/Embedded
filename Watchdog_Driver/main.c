/*
 * main.c
 *
 *  Created on: Jul 3, 2020
 *      Author: Dan
 */

#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"avr/io.h"
#include"avr/interrupt.h"
#include"Dio_int.h"
#include"Led_int.h"
u32 Ovf_counts=0;

typedef struct task{
	u32 u32Periodicity;
	u32 u32FirstDelay;
	void (*pfTaskCode)(void);
}Task_Type;
Task_Type App1;
Task_Type App2;

Task_Type* TaskArray[2];
void Led_Task_Fun(void);
void Switch_Task_Fun(void);
void Wdg_Task_Fun(void);
void Timer_vidInit(void);
int main(void){

	Task_Type Led_Task;
	Task_Type Switch_Task;
	Task_Type Wdg_Task;

	Led_Task.u32Periodicity =500;
	Led_Task.u32FirstDelay  =0;
	Led_Task.pfTaskCode 	=Led_Task_Fun;


	Switch_Task.u32Periodicity =1000;
	Switch_Task.u32FirstDelay  =0;
	Switch_Task.pfTaskCode  	=Switch_Task_Fun;

	Wdg_Task.u32Periodicity =1000;
	Wdg_Task.u32FirstDelay  =0;
	Wdg_Task.pfTaskCode  	=Wdg_Task_Fun;


	TaskArray[0] = &App1;
	TaskArray[1] = &App2;
	Led_vidInit(Led_1);
	Led_vidInit(Led_2);

	Timer_vidInit();

	while(1);
	return 0;
}
void App1_Code(void){

	static u8 flag = 0;

	if(flag==0){
		Led_vidTurnON(Led_1);
		flag=1;
	}
	else {
		Led_vidTurnOFF(Led_1);
		flag=0;
	}

}

void App2_Code(void){

	static u8 flag = 0;

	if(flag==0){
		Led_vidTurnON(Led_2);
		flag=1;
	}
	else {
		Led_vidTurnOFF(Led_2);
		flag=0;
	}
}
void Led_Task_Fun(void){
	static flag=0;

	switch(flag){

	case 0:
		Led_vidTurnON(Led_1);
		break;
	case 1:
		Led_vidTurnON(Led_2);
		break;
	case 2:
		Led_vidTurnON(Led_3);
		break;
	case 3:
		Led_vidTurnON(Led_4);
		break;
	case 4:
		Led_vidTurnON(Led_5);
		break;
	case 5:
		Led_vidTurnON(Led_6);
		break;
	case 6:
		Led_vidTurnON(Led_7);
		break;
	case 7:
		Led_vidTurnON(Led_8);
		break;
	default:
		Led_vidTurnOFF(Led_1);
		Led_vidTurnOFF(Led_2);
		Led_vidTurnOFF(Led_3);
		Led_vidTurnOFF(Led_4);
		Led_vidTurnOFF(Led_5);
		Led_vidTurnOFF(Led_6);
		Led_vidTurnOFF(Led_7);
		break;
	}
	flag++;
	if(flag==9){
		flag==0;
	}

}
void Timer_vidInit(void){
	Ovf_counts=0;
	TCCR0=0;
	SET_BIT(TCCR0,0);//No prescaler

	TCNT0=192;
	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);//Global Interrupt
}

ISR(TIMER0_OVF_vect){
	Ovf_counts++;
	if(Ovf_counts==32){//meaning that 1millisecond has passed
		Ovf_counts=0;
		TCNT0=192;
		//this will run 32 times
		Scheduler();
	}
}
