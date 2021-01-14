################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/MQTT_Src/MQTTClient.c \
../Core/lib/MQTT_Src/MQTTConnectClient.c \
../Core/lib/MQTT_Src/MQTTConnectServer.c \
../Core/lib/MQTT_Src/MQTTDeserializePublish.c \
../Core/lib/MQTT_Src/MQTTFormat.c \
../Core/lib/MQTT_Src/MQTTPacket.c \
../Core/lib/MQTT_Src/MQTTSerializePublish.c \
../Core/lib/MQTT_Src/MQTTSubscribeClient.c \
../Core/lib/MQTT_Src/MQTTSubscribeServer.c \
../Core/lib/MQTT_Src/MQTTUnsubscribeClient.c \
../Core/lib/MQTT_Src/MQTTUnsubscribeServer.c \
../Core/lib/MQTT_Src/Network.c \
../Core/lib/MQTT_Src/timer_interface.c \
../Core/lib/MQTT_Src/transport.c 

C_DEPS += \
./Core/lib/MQTT_Src/MQTTClient.d \
./Core/lib/MQTT_Src/MQTTConnectClient.d \
./Core/lib/MQTT_Src/MQTTConnectServer.d \
./Core/lib/MQTT_Src/MQTTDeserializePublish.d \
./Core/lib/MQTT_Src/MQTTFormat.d \
./Core/lib/MQTT_Src/MQTTPacket.d \
./Core/lib/MQTT_Src/MQTTSerializePublish.d \
./Core/lib/MQTT_Src/MQTTSubscribeClient.d \
./Core/lib/MQTT_Src/MQTTSubscribeServer.d \
./Core/lib/MQTT_Src/MQTTUnsubscribeClient.d \
./Core/lib/MQTT_Src/MQTTUnsubscribeServer.d \
./Core/lib/MQTT_Src/Network.d \
./Core/lib/MQTT_Src/timer_interface.d \
./Core/lib/MQTT_Src/transport.d 

OBJS += \
./Core/lib/MQTT_Src/MQTTClient.o \
./Core/lib/MQTT_Src/MQTTConnectClient.o \
./Core/lib/MQTT_Src/MQTTConnectServer.o \
./Core/lib/MQTT_Src/MQTTDeserializePublish.o \
./Core/lib/MQTT_Src/MQTTFormat.o \
./Core/lib/MQTT_Src/MQTTPacket.o \
./Core/lib/MQTT_Src/MQTTSerializePublish.o \
./Core/lib/MQTT_Src/MQTTSubscribeClient.o \
./Core/lib/MQTT_Src/MQTTSubscribeServer.o \
./Core/lib/MQTT_Src/MQTTUnsubscribeClient.o \
./Core/lib/MQTT_Src/MQTTUnsubscribeServer.o \
./Core/lib/MQTT_Src/Network.o \
./Core/lib/MQTT_Src/timer_interface.o \
./Core/lib/MQTT_Src/transport.o 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/MQTT_Src/MQTTClient.o: ../Core/lib/MQTT_Src/MQTTClient.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTClient.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTConnectClient.o: ../Core/lib/MQTT_Src/MQTTConnectClient.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTConnectClient.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTConnectServer.o: ../Core/lib/MQTT_Src/MQTTConnectServer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTConnectServer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTDeserializePublish.o: ../Core/lib/MQTT_Src/MQTTDeserializePublish.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTDeserializePublish.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTFormat.o: ../Core/lib/MQTT_Src/MQTTFormat.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTFormat.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTPacket.o: ../Core/lib/MQTT_Src/MQTTPacket.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTPacket.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTSerializePublish.o: ../Core/lib/MQTT_Src/MQTTSerializePublish.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTSerializePublish.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTSubscribeClient.o: ../Core/lib/MQTT_Src/MQTTSubscribeClient.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTSubscribeClient.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTSubscribeServer.o: ../Core/lib/MQTT_Src/MQTTSubscribeServer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTSubscribeServer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTUnsubscribeClient.o: ../Core/lib/MQTT_Src/MQTTUnsubscribeClient.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTUnsubscribeClient.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/MQTTUnsubscribeServer.o: ../Core/lib/MQTT_Src/MQTTUnsubscribeServer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/MQTTUnsubscribeServer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/Network.o: ../Core/lib/MQTT_Src/Network.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/Network.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/timer_interface.o: ../Core/lib/MQTT_Src/timer_interface.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/timer_interface.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/MQTT_Src/transport.o: ../Core/lib/MQTT_Src/transport.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Src" -I../Core/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/wifi_Src" -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/mbedtls" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"C:/Users/cocco/OneDrive/Documents/Dottorato/Ricerca/Pleinair/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MQTT_Src/transport.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

