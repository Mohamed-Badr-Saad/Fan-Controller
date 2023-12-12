################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/source/dc-motor.c \
../HAL/source/lcd.c \
../HAL/source/lm35.c 

OBJS += \
./HAL/source/dc-motor.o \
./HAL/source/lcd.o \
./HAL/source/lm35.o 

C_DEPS += \
./HAL/source/dc-motor.d \
./HAL/source/lcd.d \
./HAL/source/lm35.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/source/%.o: ../HAL/source/%.c HAL/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\APP" -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\HAL\include" -I"G:\university\GitHub\Fan-Controller\Mini_Project3_WS\Fan_Controller_System\MCAL\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


