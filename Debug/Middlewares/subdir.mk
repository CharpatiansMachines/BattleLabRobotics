################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/State_Control.c \
../Middlewares/Strategies.c \
../Middlewares/Tactics.c 

OBJS += \
./Middlewares/State_Control.o \
./Middlewares/Strategies.o \
./Middlewares/Tactics.o 

C_DEPS += \
./Middlewares/State_Control.d \
./Middlewares/Strategies.d \
./Middlewares/Tactics.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/%.o Middlewares/%.su Middlewares/%.cyclo: ../Middlewares/%.c Middlewares/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Robot_Driver" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares

clean-Middlewares:
	-$(RM) ./Middlewares/State_Control.cyclo ./Middlewares/State_Control.d ./Middlewares/State_Control.o ./Middlewares/State_Control.su ./Middlewares/Strategies.cyclo ./Middlewares/Strategies.d ./Middlewares/Strategies.o ./Middlewares/Strategies.su ./Middlewares/Tactics.cyclo ./Middlewares/Tactics.d ./Middlewares/Tactics.o ./Middlewares/Tactics.su

.PHONY: clean-Middlewares

