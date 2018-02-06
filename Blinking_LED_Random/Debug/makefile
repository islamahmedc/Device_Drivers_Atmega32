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
Blinking_LED_Random.lss \

FLASH_IMAGE += \
Blinking_LED_Random.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Blinking_LED_Random.elf secondary-outputs

# Tool invocations
Blinking_LED_Random.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Blinking_LED_Random.map -mmcu=atmega32 -o "Blinking_LED_Random.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Blinking_LED_Random.lss: Blinking_LED_Random.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Blinking_LED_Random.elf  >"Blinking_LED_Random.lss"
	@echo 'Finished building: $@'
	@echo ' '

Blinking_LED_Random.hex: Blinking_LED_Random.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Blinking_LED_Random.elf  "Blinking_LED_Random.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Blinking_LED_Random.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Blinking_LED_Random.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Blinking_LED_Random.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Blinking_LED_Random.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Blinking_LED_Random.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
