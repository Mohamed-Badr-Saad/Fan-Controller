################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/source/adc.c \
../MCAL/source/gpio.c \
../MCAL/source/timer0.c 

OBJS += \
./MCAL/source/adc.o \
./MCAL/source/gpio.o \
./MCAL/source/timer0.o 

C_DEPS += \
./MCAL/source/adc.d \
./MCAL/source/gpio.d \
./MCAL/source/timer0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/source/%.o: ../MCAL/source/%.c MCAL/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\APP" -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\HAL\include" -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\MCAL\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


