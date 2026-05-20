################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/board_octopus.c \
../Core/Src/board_raven.c \
../Core/Src/board_turtle.c \
../Core/Src/main.c \
../Core/Src/master_test.c \
../Core/Src/stm32g0xx_hal_msp.c \
../Core/Src/stm32g0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g0xx.c \
../Core/Src/test_analog.c \
../Core/Src/test_can.c \
../Core/Src/test_dio.c \
../Core/Src/test_uart.c 

OBJS += \
./Core/Src/board_octopus.o \
./Core/Src/board_raven.o \
./Core/Src/board_turtle.o \
./Core/Src/main.o \
./Core/Src/master_test.o \
./Core/Src/stm32g0xx_hal_msp.o \
./Core/Src/stm32g0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g0xx.o \
./Core/Src/test_analog.o \
./Core/Src/test_can.o \
./Core/Src/test_dio.o \
./Core/Src/test_uart.o 

C_DEPS += \
./Core/Src/board_octopus.d \
./Core/Src/board_raven.d \
./Core/Src/board_turtle.d \
./Core/Src/main.d \
./Core/Src/master_test.d \
./Core/Src/stm32g0xx_hal_msp.d \
./Core/Src/stm32g0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g0xx.d \
./Core/Src/test_analog.d \
./Core/Src/test_can.d \
./Core/Src/test_dio.d \
./Core/Src/test_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/board_octopus.cyclo ./Core/Src/board_octopus.d ./Core/Src/board_octopus.o ./Core/Src/board_octopus.su ./Core/Src/board_raven.cyclo ./Core/Src/board_raven.d ./Core/Src/board_raven.o ./Core/Src/board_raven.su ./Core/Src/board_turtle.cyclo ./Core/Src/board_turtle.d ./Core/Src/board_turtle.o ./Core/Src/board_turtle.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/master_test.cyclo ./Core/Src/master_test.d ./Core/Src/master_test.o ./Core/Src/master_test.su ./Core/Src/stm32g0xx_hal_msp.cyclo ./Core/Src/stm32g0xx_hal_msp.d ./Core/Src/stm32g0xx_hal_msp.o ./Core/Src/stm32g0xx_hal_msp.su ./Core/Src/stm32g0xx_it.cyclo ./Core/Src/stm32g0xx_it.d ./Core/Src/stm32g0xx_it.o ./Core/Src/stm32g0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32g0xx.cyclo ./Core/Src/system_stm32g0xx.d ./Core/Src/system_stm32g0xx.o ./Core/Src/system_stm32g0xx.su ./Core/Src/test_analog.cyclo ./Core/Src/test_analog.d ./Core/Src/test_analog.o ./Core/Src/test_analog.su ./Core/Src/test_can.cyclo ./Core/Src/test_can.d ./Core/Src/test_can.o ./Core/Src/test_can.su ./Core/Src/test_dio.cyclo ./Core/Src/test_dio.d ./Core/Src/test_dio.o ./Core/Src/test_dio.su ./Core/Src/test_uart.cyclo ./Core/Src/test_uart.d ./Core/Src/test_uart.o ./Core/Src/test_uart.su

.PHONY: clean-Core-2f-Src

