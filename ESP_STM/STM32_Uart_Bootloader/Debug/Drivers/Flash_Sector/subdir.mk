################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Flash_Sector/Flash_Sector.c 

OBJS += \
./Drivers/Flash_Sector/Flash_Sector.o 

C_DEPS += \
./Drivers/Flash_Sector/Flash_Sector.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Flash_Sector/%.o Drivers/Flash_Sector/%.su Drivers/Flash_Sector/%.cyclo: ../Drivers/Flash_Sector/%.c Drivers/Flash_Sector/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I../Drivers/Flash_Sector -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Flash_Sector

clean-Drivers-2f-Flash_Sector:
	-$(RM) ./Drivers/Flash_Sector/Flash_Sector.cyclo ./Drivers/Flash_Sector/Flash_Sector.d ./Drivers/Flash_Sector/Flash_Sector.o ./Drivers/Flash_Sector/Flash_Sector.su

.PHONY: clean-Drivers-2f-Flash_Sector

