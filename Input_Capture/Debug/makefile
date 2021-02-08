################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Input_Capture.lss \

FLASH_IMAGE += \
Input_Capture.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Input_Capture.elf secondary-outputs

# Tool invocations
Input_Capture.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Input_Capture.map -mmcu=atmega32 -o "Input_Capture.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Input_Capture.lss: Input_Capture.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Input_Capture.elf  >"Input_Capture.lss"
	@echo 'Finished building: $@'
	@echo ' '

Input_Capture.hex: Input_Capture.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Input_Capture.elf  "Input_Capture.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Input_Capture.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Input_Capture.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Input_Capture.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
