################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.settings/Button.c 

OBJS += \
./.settings/Button.o 

C_DEPS += \
./.settings/Button.d 


# Each subdirectory must supply rules for building sources it contributes
.settings/%.o: ../.settings/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Applications" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Applications\Paint" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Games\PingPong" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Games\Snake" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Tool" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Config" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Games" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\GUI" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Menu" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Tool" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Communication" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Drivers" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


