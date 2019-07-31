################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/Tool/subdir.mk
-include Sources/Menu/subdir.mk
-include Sources/Games/Snake/subdir.mk
-include Sources/Games/PingPong/subdir.mk
-include Sources/GUI/subdir.mk
-include Sources/Drivers/subdir.mk
-include Sources/Communication/subdir.mk
-include Sources/Applications/Paint/subdir.mk
-include Sources/subdir.mk
-include .settings/subdir.mk
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
PortableGameConsole.lss \

FLASH_IMAGE += \
PortableGameConsole.hex \

EEPROM_IMAGE += \
PortableGameConsole.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: PortableGameConsole.elf secondary-outputs

# Tool invocations
PortableGameConsole.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PortableGameConsole.map -mmcu=atmega16 -o "PortableGameConsole.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PortableGameConsole.lss: PortableGameConsole.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PortableGameConsole.elf  >"PortableGameConsole.lss"
	@echo 'Finished building: $@'
	@echo ' '

PortableGameConsole.hex: PortableGameConsole.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PortableGameConsole.elf  "PortableGameConsole.hex"
	@echo 'Finished building: $@'
	@echo ' '

PortableGameConsole.eep: PortableGameConsole.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex PortableGameConsole.elf  "PortableGameConsole.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PortableGameConsole.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 PortableGameConsole.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PortableGameConsole.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
