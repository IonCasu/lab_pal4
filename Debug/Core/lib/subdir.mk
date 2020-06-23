################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/mbedtls_entropy.c \
../Core/lib/net_address.c \
../Core/lib/net_class_extension.c \
../Core/lib/net_conf.c \
../Core/lib/net_core.c \
../Core/lib/net_mbedtls.c 

OBJS += \
./Core/lib/mbedtls_entropy.o \
./Core/lib/net_address.o \
./Core/lib/net_class_extension.o \
./Core/lib/net_conf.o \
./Core/lib/net_core.o \
./Core/lib/net_mbedtls.o 

C_DEPS += \
./Core/lib/mbedtls_entropy.d \
./Core/lib/net_address.d \
./Core/lib/net_class_extension.d \
./Core/lib/net_conf.d \
./Core/lib/net_core.d \
./Core/lib/net_mbedtls.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/mbedtls_entropy.o: ../Core/lib/mbedtls_entropy.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls_entropy.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/net_address.o: ../Core/lib/net_address.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/net_address.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/net_class_extension.o: ../Core/lib/net_class_extension.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/net_class_extension.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/net_conf.o: ../Core/lib/net_conf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/net_conf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/net_core.o: ../Core/lib/net_core.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/net_core.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/net_mbedtls.o: ../Core/lib/net_mbedtls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/net_mbedtls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

