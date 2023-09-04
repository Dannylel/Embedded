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
Volume_Bar.lss \

FLASH_IMAGE += \
Volume_Bar.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Volume_Bar.elf secondary-outputs

# Tool invocations
Volume_Bar.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Volume_Bar.map -mmcu=atmega32 -o "Volume_Bar.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Volume_Bar.lss: Volume_Bar.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Volume_Bar.elf  >"Volume_Bar.lss"
	@echo 'Finished building: $@'
	@echo ' '

Volume_Bar.hex: Volume_Bar.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Volume_Bar.elf  "Volume_Bar.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Volume_Bar.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Volume_Bar.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Volume_Bar.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
