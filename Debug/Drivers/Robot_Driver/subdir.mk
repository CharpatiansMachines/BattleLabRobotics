################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Robot_Driver/Communication_Driver.c \
../Drivers/Robot_Driver/Enemy_Sensors.c \
../Drivers/Robot_Driver/IMU_Driver.c \
../Drivers/Robot_Driver/Line_Sensors.c \
../Drivers/Robot_Driver/motor_driver.c 

OBJS += \
./Drivers/Robot_Driver/Communication_Driver.o \
./Drivers/Robot_Driver/Enemy_Sensors.o \
./Drivers/Robot_Driver/IMU_Driver.o \
./Drivers/Robot_Driver/Line_Sensors.o \
./Drivers/Robot_Driver/motor_driver.o 

C_DEPS += \
./Drivers/Robot_Driver/Communication_Driver.d \
./Drivers/Robot_Driver/Enemy_Sensors.d \
./Drivers/Robot_Driver/IMU_Driver.d \
./Drivers/Robot_Driver/Line_Sensors.d \
./Drivers/Robot_Driver/motor_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Robot_Driver/%.o Drivers/Robot_Driver/%.su Drivers/Robot_Driver/%.cyclo: ../Drivers/Robot_Driver/%.c Drivers/Robot_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Proiecte/STMCUBE/BattleLabRobotics/Drivers/Robot_Driver" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Robot_Driver

clean-Drivers-2f-Robot_Driver:
	-$(RM) ./Drivers/Robot_Driver/Communication_Driver.cyclo ./Drivers/Robot_Driver/Communication_Driver.d ./Drivers/Robot_Driver/Communication_Driver.o ./Drivers/Robot_Driver/Communication_Driver.su ./Drivers/Robot_Driver/Enemy_Sensors.cyclo ./Drivers/Robot_Driver/Enemy_Sensors.d ./Drivers/Robot_Driver/Enemy_Sensors.o ./Drivers/Robot_Driver/Enemy_Sensors.su ./Drivers/Robot_Driver/IMU_Driver.cyclo ./Drivers/Robot_Driver/IMU_Driver.d ./Drivers/Robot_Driver/IMU_Driver.o ./Drivers/Robot_Driver/IMU_Driver.su ./Drivers/Robot_Driver/Line_Sensors.cyclo ./Drivers/Robot_Driver/Line_Sensors.d ./Drivers/Robot_Driver/Line_Sensors.o ./Drivers/Robot_Driver/Line_Sensors.su ./Drivers/Robot_Driver/motor_driver.cyclo ./Drivers/Robot_Driver/motor_driver.d ./Drivers/Robot_Driver/motor_driver.o ./Drivers/Robot_Driver/motor_driver.su

.PHONY: clean-Drivers-2f-Robot_Driver

