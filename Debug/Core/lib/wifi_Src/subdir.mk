################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/wifi_Src/es_wifi.c \
../Core/lib/wifi_Src/es_wifi_io.c \
../Core/lib/wifi_Src/stm32l475e_iot01.c \
../Core/lib/wifi_Src/wifi.c 

C_DEPS += \
./Core/lib/wifi_Src/es_wifi.d \
./Core/lib/wifi_Src/es_wifi_io.d \
./Core/lib/wifi_Src/stm32l475e_iot01.d \
./Core/lib/wifi_Src/wifi.d 

OBJS += \
./Core/lib/wifi_Src/es_wifi.o \
./Core/lib/wifi_Src/es_wifi_io.o \
./Core/lib/wifi_Src/stm32l475e_iot01.o \
./Core/lib/wifi_Src/wifi.o 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/wifi_Src/es_wifi.o: ../Core/lib/wifi_Src/es_wifi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/mbedtls" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/wifi_Src/es_wifi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/wifi_Src/es_wifi_io.o: ../Core/lib/wifi_Src/es_wifi_io.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/mbedtls" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/wifi_Src/es_wifi_io.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/wifi_Src/stm32l475e_iot01.o: ../Core/lib/wifi_Src/stm32l475e_iot01.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/mbedtls" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/wifi_Src/stm32l475e_iot01.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/wifi_Src/wifi.o: ../Core/lib/wifi_Src/wifi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/wifi_Src" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/mbedtls" -I"C:/Users/39389/Desktop/PLEINAIR/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/wifi_Src/wifi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

