#include<avr/io.h>
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#define DDRA    (*((volatile u8 *)0x3A))
#define DDRB	(*((volatile u8 *)0x37))
#define DDRC	(*((volatile u8 *)0x34))
#define DDRD	(*((volatile u8 *)0x31))

#define PORTA	(*((volatile u8 *)0x3B))
#define PORTB	(*((volatile u8 *)0x38))
#define PORTC	(*((volatile u8 *)0x35))
#define PORTD	(*((volatile u8 *)0x32))
#define DDRA (*(volatile Reg_type *)0x3A))
int main(void){
	typedef union{
		struct {
			u8 b0:1;
			u8 b1:1;
			u8 b2:1;
			u8 b3:1;
			u8 b4:1;
			u8 b5:1;
			u8 b6:1;
			u8 b7:1;
		}Bits;
		u8 Byte;
	}Reg_type;






	DDRA.Byte=192;
	DDRA.Bits.b0=1;
	DDRA=5; //0x3A
	u8 ptr=0x3A;
	*ptr=5;

	u8 y=*((u8 *)0x3A)=5;


	while(1){

	}
	return 0;
}

/*
typedef struct {
	u8 b0:1;
	u8 b1:1;
	u8 b2:1;
	u8 b3:1;
	u8 b4:1;
	u8 b5:1;
	u8 b6:1;
	u8 b7:1;

}Reg_type;


 */

/*
 *(ptr).b0=1;
 *(volatile Reg_type*)0x3A)
		Reg_type &ptr=0x3A;
 */

//keyword volatile 1st use to disable compiler optimization


#include<avr/interrupt.h>



void __vector_11(void) __attribute__((signal,used,externaly_visible));

void __vector__11(void){


}
//Doxygen
//function attributes (search)
//function name = first instruction of function like name of array= first element of array when using pointers
