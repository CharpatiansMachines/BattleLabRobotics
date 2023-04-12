################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Com_Driver/UART_Driver.c 

OBJS += \
./Drivers/Com_Driver/UART_Driver.o 

C_DEPS += \
./Drivers/Com_Driver/UART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Com_Driver/%.o Drivers/Com_Driver/%.su Drivers/Com_Driver/%.cyclo: ../Drivers/Com_Driver/%.c Drivers/Com_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Com_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Com_Driver

clean-Drivers-2f-Com_Driver:
	-$(RM) ./Drivers/Com_Driver/UART_Driver.cyclo ./Drivers/Com_Driver/UART_Driver.d ./Drivers/Com_Driver/UART_Driver.o ./Drivers/Com_Driver/UART_Driver.su

.PHONY: clean-Drivers-2f-Com_Driver

