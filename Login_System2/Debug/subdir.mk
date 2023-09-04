################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prg.c \
../Dio_prg.c \
../Keypad_prg.c \
../Lcd_prg.c \
../Login_prg.c \
../Stepper_prg.c \
../main.c 

OBJS += \
./ADC_prg.o \
./Dio_prg.o \
./Keypad_prg.o \
./Lcd_prg.o \
./Login_prg.o \
./Stepper_prg.o \
./main.o 

C_DEPS += \
./ADC_prg.d \
./Dio_prg.d \
./Keypad_prg.d \
./Lcd_prg.d \
./Login_prg.d \
./Stepper_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


