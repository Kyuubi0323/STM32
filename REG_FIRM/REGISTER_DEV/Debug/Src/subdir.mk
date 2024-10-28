################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/clock_reg.c \
../Src/gpio_reg.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart_reg.c 

OBJS += \
./Src/clock_reg.o \
./Src/gpio_reg.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart_reg.o 

C_DEPS += \
./Src/clock_reg.d \
./Src/gpio_reg.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/clock_reg.cyclo ./Src/clock_reg.d ./Src/clock_reg.o ./Src/clock_reg.su ./Src/gpio_reg.cyclo ./Src/gpio_reg.d ./Src/gpio_reg.o ./Src/gpio_reg.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart_reg.cyclo ./Src/uart_reg.d ./Src/uart_reg.o ./Src/uart_reg.su

.PHONY: clean-Src

