/*
 * main.c
 *
 *  Created on: Jul 29, 2020
 *      Author: Dan
 */
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
	void (*pfTaskCode)(void);	//pointer to function
}TaskType;

TaskType App1;
TaskType App2;

TaskType* TaskArray[2];
void App1_Code(void);
void App2_Code(void);
void Scheduler(void);
void Timer_vidInit(void);
int main(void){
	App1.u32Periodicity =15;
	App1.u32FirstDelay  =100;
	App1.pfTaskCode 	=App1_Code;	//referencing function NOT calling it


	App2.u32Periodicity =50;
	App2.u32FirstDelay  =200;
	App2.pfTaskCode  	=App2_Code;	//referencing function NOT calling it


	//assigning pointers in array to structs
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
void Scheduler(void){
	u8 ArrayCounter;

	for(ArrayCounter=0; ArrayCounter<2; ArrayCounter++){
		if(TaskArray[ArrayCounter]->u32FirstDelay ==0){

			//Array of pointer to structures containing pointer to function
			TaskArray[ArrayCounter]->pfTaskCode();	//this time we are CALLING the function in the struct
			TaskArray[ArrayCounter]->u32FirstDelay=TaskArray[ArrayCounter]->u32Periodicity-1;
		}
		else {
			TaskArray[ArrayCounter]->u32FirstDelay--;
		}
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
		TCNT0=192;	//filling 3/4th of the register to count 1/4th of a register as a dummy pack so that we can count a register and a quarter 1.25 to
		//this will run 32 times
		Scheduler();
	}
}


