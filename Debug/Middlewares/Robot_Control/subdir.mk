################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Robot_Control/EnemyPosition.c \
../Middlewares/Robot_Control/State_Control.c \
../Middlewares/Robot_Control/Strategies.c \
../Middlewares/Robot_Control/Tactics.c 

OBJS += \
./Middlewares/Robot_Control/EnemyPosition.o \
./Middlewares/Robot_Control/State_Control.o \
./Middlewares/Robot_Control/Strategies.o \
./Middlewares/Robot_Control/Tactics.o 

C_DEPS += \
./Middlewares/Robot_Control/EnemyPosition.d \
./Middlewares/Robot_Control/State_Control.d \
./Middlewares/Robot_Control/Strategies.d \
./Middlewares/Robot_Control/Tactics.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Robot_Control/%.o Middlewares/Robot_Control/%.su Middlewares/Robot_Control/%.cyclo: ../Middlewares/Robot_Control/%.c Middlewares/Robot_Control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Robot_Driver" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Middlewares/Robot_Control" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Robot_Control

clean-Middlewares-2f-Robot_Control:
	-$(RM) ./Middlewares/Robot_Control/EnemyPosition.cyclo ./Middlewares/Robot_Control/EnemyPosition.d ./Middlewares/Robot_Control/EnemyPosition.o ./Middlewares/Robot_Control/EnemyPosition.su ./Middlewares/Robot_Control/State_Control.cyclo ./Middlewares/Robot_Control/State_Control.d ./Middlewares/Robot_Control/State_Control.o ./Middlewares/Robot_Control/State_Control.su ./Middlewares/Robot_Control/Strategies.cyclo ./Middlewares/Robot_Control/Strategies.d ./Middlewares/Robot_Control/Strategies.o ./Middlewares/Robot_Control/Strategies.su ./Middlewares/Robot_Control/Tactics.cyclo ./Middlewares/Robot_Control/Tactics.d ./Middlewares/Robot_Control/Tactics.o ./Middlewares/Robot_Control/Tactics.su

.PHONY: clean-Middlewares-2f-Robot_Control

