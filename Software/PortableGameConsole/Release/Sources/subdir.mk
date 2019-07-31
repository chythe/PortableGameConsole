################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Main.c 

OBJS += \
./Sources/Main.o 

C_DEPS += \
./Sources/Main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Main.o: ../Sources/Main.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Communication" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Config" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Drivers" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Games" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\GUI" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Menu" -I"C:\AVR\SMIW_M.Chudy_PrzenosnaKonsolaGier\Software\PortableGameConsole\Sources\Tool" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"Sources/Main.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


