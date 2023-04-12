################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Line_Sensors/Line_Sensors.c 

OBJS += \
./Drivers/Line_Sensors/Line_Sensors.o 

C_DEPS += \
./Drivers/Line_Sensors/Line_Sensors.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Line_Sensors/%.o Drivers/Line_Sensors/%.su Drivers/Line_Sensors/%.cyclo: ../Drivers/Line_Sensors/%.c Drivers/Line_Sensors/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Com_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Line_Sensors

clean-Drivers-2f-Line_Sensors:
	-$(RM) ./Drivers/Line_Sensors/Line_Sensors.cyclo ./Drivers/Line_Sensors/Line_Sensors.d ./Drivers/Line_Sensors/Line_Sensors.o ./Drivers/Line_Sensors/Line_Sensors.su

.PHONY: clean-Drivers-2f-Line_Sensors

