################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWM.c \
../adc.c \
../dc-motor.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../miniproject3.c 

OBJS += \
./PWM.o \
./adc.o \
./dc-motor.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./miniproject3.o 

C_DEPS += \
./PWM.d \
./adc.d \
./dc-motor.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./miniproject3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


