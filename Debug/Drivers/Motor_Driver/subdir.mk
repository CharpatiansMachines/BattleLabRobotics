################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Motor_Driver/motor_driver.c 

OBJS += \
./Drivers/Motor_Driver/motor_driver.o 

C_DEPS += \
./Drivers/Motor_Driver/motor_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Motor_Driver/%.o Drivers/Motor_Driver/%.su Drivers/Motor_Driver/%.cyclo: ../Drivers/Motor_Driver/%.c Drivers/Motor_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Com_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Motor_Driver

clean-Drivers-2f-Motor_Driver:
	-$(RM) ./Drivers/Motor_Driver/motor_driver.cyclo ./Drivers/Motor_Driver/motor_driver.d ./Drivers/Motor_Driver/motor_driver.o ./Drivers/Motor_Driver/motor_driver.su

.PHONY: clean-Drivers-2f-Motor_Driver

