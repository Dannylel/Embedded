################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio_prg.c \
../Keyboard_prg.c \
../Lcd_prg.c \
../Uart_prg.c \
../main.c 

OBJS += \
./Dio_prg.o \
./Keyboard_prg.o \
./Lcd_prg.o \
./Uart_prg.o \
./main.o 

C_DEPS += \
./Dio_prg.d \
./Keyboard_prg.d \
./Lcd_prg.d \
./Uart_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


