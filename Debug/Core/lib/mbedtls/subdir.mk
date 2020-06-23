################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/mbedtls/aes.c \
../Core/lib/mbedtls/aesni.c \
../Core/lib/mbedtls/arc4.c \
../Core/lib/mbedtls/aria.c \
../Core/lib/mbedtls/asn1parse.c \
../Core/lib/mbedtls/asn1write.c \
../Core/lib/mbedtls/base64.c \
../Core/lib/mbedtls/bignum.c \
../Core/lib/mbedtls/blowfish.c \
../Core/lib/mbedtls/camellia.c \
../Core/lib/mbedtls/ccm.c \
../Core/lib/mbedtls/certs.c \
../Core/lib/mbedtls/chacha20.c \
../Core/lib/mbedtls/chachapoly.c \
../Core/lib/mbedtls/cipher.c \
../Core/lib/mbedtls/cipher_wrap.c \
../Core/lib/mbedtls/cmac.c \
../Core/lib/mbedtls/ctr_drbg.c \
../Core/lib/mbedtls/debug.c \
../Core/lib/mbedtls/des.c \
../Core/lib/mbedtls/dhm.c \
../Core/lib/mbedtls/ecdh.c \
../Core/lib/mbedtls/ecdsa.c \
../Core/lib/mbedtls/ecjpake.c \
../Core/lib/mbedtls/ecp.c \
../Core/lib/mbedtls/ecp_curves.c \
../Core/lib/mbedtls/entropy.c \
../Core/lib/mbedtls/entropy_poll.c \
../Core/lib/mbedtls/error.c \
../Core/lib/mbedtls/gcm.c \
../Core/lib/mbedtls/havege.c \
../Core/lib/mbedtls/hkdf.c \
../Core/lib/mbedtls/hmac_drbg.c \
../Core/lib/mbedtls/md.c \
../Core/lib/mbedtls/md2.c \
../Core/lib/mbedtls/md4.c \
../Core/lib/mbedtls/md5.c \
../Core/lib/mbedtls/md_wrap.c \
../Core/lib/mbedtls/memory_buffer_alloc.c \
../Core/lib/mbedtls/net_sockets.c \
../Core/lib/mbedtls/nist_kw.c \
../Core/lib/mbedtls/oid.c \
../Core/lib/mbedtls/padlock.c \
../Core/lib/mbedtls/pem.c \
../Core/lib/mbedtls/pk.c \
../Core/lib/mbedtls/pk_wrap.c \
../Core/lib/mbedtls/pkcs11.c \
../Core/lib/mbedtls/pkcs12.c \
../Core/lib/mbedtls/pkcs5.c \
../Core/lib/mbedtls/pkparse.c \
../Core/lib/mbedtls/pkwrite.c \
../Core/lib/mbedtls/platform.c \
../Core/lib/mbedtls/platform_util.c \
../Core/lib/mbedtls/poly1305.c \
../Core/lib/mbedtls/ripemd160.c \
../Core/lib/mbedtls/rsa.c \
../Core/lib/mbedtls/rsa_internal.c \
../Core/lib/mbedtls/sha1.c \
../Core/lib/mbedtls/sha256.c \
../Core/lib/mbedtls/sha512.c \
../Core/lib/mbedtls/ssl_cache.c \
../Core/lib/mbedtls/ssl_ciphersuites.c \
../Core/lib/mbedtls/ssl_cli.c \
../Core/lib/mbedtls/ssl_cookie.c \
../Core/lib/mbedtls/ssl_srv.c \
../Core/lib/mbedtls/ssl_ticket.c \
../Core/lib/mbedtls/ssl_tls.c \
../Core/lib/mbedtls/threading.c \
../Core/lib/mbedtls/timing.c \
../Core/lib/mbedtls/version.c \
../Core/lib/mbedtls/version_features.c \
../Core/lib/mbedtls/x509.c \
../Core/lib/mbedtls/x509_create.c \
../Core/lib/mbedtls/x509_crl.c \
../Core/lib/mbedtls/x509_crt.c \
../Core/lib/mbedtls/x509_csr.c \
../Core/lib/mbedtls/x509write_crt.c \
../Core/lib/mbedtls/x509write_csr.c \
../Core/lib/mbedtls/xtea.c 

OBJS += \
./Core/lib/mbedtls/aes.o \
./Core/lib/mbedtls/aesni.o \
./Core/lib/mbedtls/arc4.o \
./Core/lib/mbedtls/aria.o \
./Core/lib/mbedtls/asn1parse.o \
./Core/lib/mbedtls/asn1write.o \
./Core/lib/mbedtls/base64.o \
./Core/lib/mbedtls/bignum.o \
./Core/lib/mbedtls/blowfish.o \
./Core/lib/mbedtls/camellia.o \
./Core/lib/mbedtls/ccm.o \
./Core/lib/mbedtls/certs.o \
./Core/lib/mbedtls/chacha20.o \
./Core/lib/mbedtls/chachapoly.o \
./Core/lib/mbedtls/cipher.o \
./Core/lib/mbedtls/cipher_wrap.o \
./Core/lib/mbedtls/cmac.o \
./Core/lib/mbedtls/ctr_drbg.o \
./Core/lib/mbedtls/debug.o \
./Core/lib/mbedtls/des.o \
./Core/lib/mbedtls/dhm.o \
./Core/lib/mbedtls/ecdh.o \
./Core/lib/mbedtls/ecdsa.o \
./Core/lib/mbedtls/ecjpake.o \
./Core/lib/mbedtls/ecp.o \
./Core/lib/mbedtls/ecp_curves.o \
./Core/lib/mbedtls/entropy.o \
./Core/lib/mbedtls/entropy_poll.o \
./Core/lib/mbedtls/error.o \
./Core/lib/mbedtls/gcm.o \
./Core/lib/mbedtls/havege.o \
./Core/lib/mbedtls/hkdf.o \
./Core/lib/mbedtls/hmac_drbg.o \
./Core/lib/mbedtls/md.o \
./Core/lib/mbedtls/md2.o \
./Core/lib/mbedtls/md4.o \
./Core/lib/mbedtls/md5.o \
./Core/lib/mbedtls/md_wrap.o \
./Core/lib/mbedtls/memory_buffer_alloc.o \
./Core/lib/mbedtls/net_sockets.o \
./Core/lib/mbedtls/nist_kw.o \
./Core/lib/mbedtls/oid.o \
./Core/lib/mbedtls/padlock.o \
./Core/lib/mbedtls/pem.o \
./Core/lib/mbedtls/pk.o \
./Core/lib/mbedtls/pk_wrap.o \
./Core/lib/mbedtls/pkcs11.o \
./Core/lib/mbedtls/pkcs12.o \
./Core/lib/mbedtls/pkcs5.o \
./Core/lib/mbedtls/pkparse.o \
./Core/lib/mbedtls/pkwrite.o \
./Core/lib/mbedtls/platform.o \
./Core/lib/mbedtls/platform_util.o \
./Core/lib/mbedtls/poly1305.o \
./Core/lib/mbedtls/ripemd160.o \
./Core/lib/mbedtls/rsa.o \
./Core/lib/mbedtls/rsa_internal.o \
./Core/lib/mbedtls/sha1.o \
./Core/lib/mbedtls/sha256.o \
./Core/lib/mbedtls/sha512.o \
./Core/lib/mbedtls/ssl_cache.o \
./Core/lib/mbedtls/ssl_ciphersuites.o \
./Core/lib/mbedtls/ssl_cli.o \
./Core/lib/mbedtls/ssl_cookie.o \
./Core/lib/mbedtls/ssl_srv.o \
./Core/lib/mbedtls/ssl_ticket.o \
./Core/lib/mbedtls/ssl_tls.o \
./Core/lib/mbedtls/threading.o \
./Core/lib/mbedtls/timing.o \
./Core/lib/mbedtls/version.o \
./Core/lib/mbedtls/version_features.o \
./Core/lib/mbedtls/x509.o \
./Core/lib/mbedtls/x509_create.o \
./Core/lib/mbedtls/x509_crl.o \
./Core/lib/mbedtls/x509_crt.o \
./Core/lib/mbedtls/x509_csr.o \
./Core/lib/mbedtls/x509write_crt.o \
./Core/lib/mbedtls/x509write_csr.o \
./Core/lib/mbedtls/xtea.o 

C_DEPS += \
./Core/lib/mbedtls/aes.d \
./Core/lib/mbedtls/aesni.d \
./Core/lib/mbedtls/arc4.d \
./Core/lib/mbedtls/aria.d \
./Core/lib/mbedtls/asn1parse.d \
./Core/lib/mbedtls/asn1write.d \
./Core/lib/mbedtls/base64.d \
./Core/lib/mbedtls/bignum.d \
./Core/lib/mbedtls/blowfish.d \
./Core/lib/mbedtls/camellia.d \
./Core/lib/mbedtls/ccm.d \
./Core/lib/mbedtls/certs.d \
./Core/lib/mbedtls/chacha20.d \
./Core/lib/mbedtls/chachapoly.d \
./Core/lib/mbedtls/cipher.d \
./Core/lib/mbedtls/cipher_wrap.d \
./Core/lib/mbedtls/cmac.d \
./Core/lib/mbedtls/ctr_drbg.d \
./Core/lib/mbedtls/debug.d \
./Core/lib/mbedtls/des.d \
./Core/lib/mbedtls/dhm.d \
./Core/lib/mbedtls/ecdh.d \
./Core/lib/mbedtls/ecdsa.d \
./Core/lib/mbedtls/ecjpake.d \
./Core/lib/mbedtls/ecp.d \
./Core/lib/mbedtls/ecp_curves.d \
./Core/lib/mbedtls/entropy.d \
./Core/lib/mbedtls/entropy_poll.d \
./Core/lib/mbedtls/error.d \
./Core/lib/mbedtls/gcm.d \
./Core/lib/mbedtls/havege.d \
./Core/lib/mbedtls/hkdf.d \
./Core/lib/mbedtls/hmac_drbg.d \
./Core/lib/mbedtls/md.d \
./Core/lib/mbedtls/md2.d \
./Core/lib/mbedtls/md4.d \
./Core/lib/mbedtls/md5.d \
./Core/lib/mbedtls/md_wrap.d \
./Core/lib/mbedtls/memory_buffer_alloc.d \
./Core/lib/mbedtls/net_sockets.d \
./Core/lib/mbedtls/nist_kw.d \
./Core/lib/mbedtls/oid.d \
./Core/lib/mbedtls/padlock.d \
./Core/lib/mbedtls/pem.d \
./Core/lib/mbedtls/pk.d \
./Core/lib/mbedtls/pk_wrap.d \
./Core/lib/mbedtls/pkcs11.d \
./Core/lib/mbedtls/pkcs12.d \
./Core/lib/mbedtls/pkcs5.d \
./Core/lib/mbedtls/pkparse.d \
./Core/lib/mbedtls/pkwrite.d \
./Core/lib/mbedtls/platform.d \
./Core/lib/mbedtls/platform_util.d \
./Core/lib/mbedtls/poly1305.d \
./Core/lib/mbedtls/ripemd160.d \
./Core/lib/mbedtls/rsa.d \
./Core/lib/mbedtls/rsa_internal.d \
./Core/lib/mbedtls/sha1.d \
./Core/lib/mbedtls/sha256.d \
./Core/lib/mbedtls/sha512.d \
./Core/lib/mbedtls/ssl_cache.d \
./Core/lib/mbedtls/ssl_ciphersuites.d \
./Core/lib/mbedtls/ssl_cli.d \
./Core/lib/mbedtls/ssl_cookie.d \
./Core/lib/mbedtls/ssl_srv.d \
./Core/lib/mbedtls/ssl_ticket.d \
./Core/lib/mbedtls/ssl_tls.d \
./Core/lib/mbedtls/threading.d \
./Core/lib/mbedtls/timing.d \
./Core/lib/mbedtls/version.d \
./Core/lib/mbedtls/version_features.d \
./Core/lib/mbedtls/x509.d \
./Core/lib/mbedtls/x509_create.d \
./Core/lib/mbedtls/x509_crl.d \
./Core/lib/mbedtls/x509_crt.d \
./Core/lib/mbedtls/x509_csr.d \
./Core/lib/mbedtls/x509write_crt.d \
./Core/lib/mbedtls/x509write_csr.d \
./Core/lib/mbedtls/xtea.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/mbedtls/aes.o: ../Core/lib/mbedtls/aes.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/aes.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/aesni.o: ../Core/lib/mbedtls/aesni.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/aesni.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/arc4.o: ../Core/lib/mbedtls/arc4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/arc4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/aria.o: ../Core/lib/mbedtls/aria.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/aria.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/asn1parse.o: ../Core/lib/mbedtls/asn1parse.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/asn1parse.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/asn1write.o: ../Core/lib/mbedtls/asn1write.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/asn1write.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/base64.o: ../Core/lib/mbedtls/base64.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/base64.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/bignum.o: ../Core/lib/mbedtls/bignum.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/bignum.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/blowfish.o: ../Core/lib/mbedtls/blowfish.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/blowfish.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/camellia.o: ../Core/lib/mbedtls/camellia.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/camellia.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ccm.o: ../Core/lib/mbedtls/ccm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ccm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/certs.o: ../Core/lib/mbedtls/certs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/certs.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/chacha20.o: ../Core/lib/mbedtls/chacha20.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/chacha20.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/chachapoly.o: ../Core/lib/mbedtls/chachapoly.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/chachapoly.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/cipher.o: ../Core/lib/mbedtls/cipher.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/cipher.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/cipher_wrap.o: ../Core/lib/mbedtls/cipher_wrap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/cipher_wrap.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/cmac.o: ../Core/lib/mbedtls/cmac.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/cmac.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ctr_drbg.o: ../Core/lib/mbedtls/ctr_drbg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ctr_drbg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/debug.o: ../Core/lib/mbedtls/debug.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/debug.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/des.o: ../Core/lib/mbedtls/des.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/des.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/dhm.o: ../Core/lib/mbedtls/dhm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/dhm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ecdh.o: ../Core/lib/mbedtls/ecdh.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ecdh.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ecdsa.o: ../Core/lib/mbedtls/ecdsa.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ecdsa.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ecjpake.o: ../Core/lib/mbedtls/ecjpake.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ecjpake.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ecp.o: ../Core/lib/mbedtls/ecp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ecp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ecp_curves.o: ../Core/lib/mbedtls/ecp_curves.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ecp_curves.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/entropy.o: ../Core/lib/mbedtls/entropy.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/entropy.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/entropy_poll.o: ../Core/lib/mbedtls/entropy_poll.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/entropy_poll.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/error.o: ../Core/lib/mbedtls/error.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/error.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/gcm.o: ../Core/lib/mbedtls/gcm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/gcm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/havege.o: ../Core/lib/mbedtls/havege.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/havege.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/hkdf.o: ../Core/lib/mbedtls/hkdf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/hkdf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/hmac_drbg.o: ../Core/lib/mbedtls/hmac_drbg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/hmac_drbg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/md.o: ../Core/lib/mbedtls/md.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/md.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/md2.o: ../Core/lib/mbedtls/md2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/md2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/md4.o: ../Core/lib/mbedtls/md4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/md4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/md5.o: ../Core/lib/mbedtls/md5.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/md5.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/md_wrap.o: ../Core/lib/mbedtls/md_wrap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/md_wrap.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/memory_buffer_alloc.o: ../Core/lib/mbedtls/memory_buffer_alloc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/memory_buffer_alloc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/net_sockets.o: ../Core/lib/mbedtls/net_sockets.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/net_sockets.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/nist_kw.o: ../Core/lib/mbedtls/nist_kw.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/nist_kw.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/oid.o: ../Core/lib/mbedtls/oid.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/oid.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/padlock.o: ../Core/lib/mbedtls/padlock.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/padlock.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pem.o: ../Core/lib/mbedtls/pem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pk.o: ../Core/lib/mbedtls/pk.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pk.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pk_wrap.o: ../Core/lib/mbedtls/pk_wrap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pk_wrap.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pkcs11.o: ../Core/lib/mbedtls/pkcs11.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pkcs11.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pkcs12.o: ../Core/lib/mbedtls/pkcs12.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pkcs12.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pkcs5.o: ../Core/lib/mbedtls/pkcs5.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pkcs5.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pkparse.o: ../Core/lib/mbedtls/pkparse.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pkparse.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/pkwrite.o: ../Core/lib/mbedtls/pkwrite.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/pkwrite.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/platform.o: ../Core/lib/mbedtls/platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/platform_util.o: ../Core/lib/mbedtls/platform_util.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/platform_util.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/poly1305.o: ../Core/lib/mbedtls/poly1305.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/poly1305.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ripemd160.o: ../Core/lib/mbedtls/ripemd160.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ripemd160.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/rsa.o: ../Core/lib/mbedtls/rsa.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/rsa.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/rsa_internal.o: ../Core/lib/mbedtls/rsa_internal.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/rsa_internal.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/sha1.o: ../Core/lib/mbedtls/sha1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/sha1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/sha256.o: ../Core/lib/mbedtls/sha256.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/sha256.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/sha512.o: ../Core/lib/mbedtls/sha512.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/sha512.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_cache.o: ../Core/lib/mbedtls/ssl_cache.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_cache.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_ciphersuites.o: ../Core/lib/mbedtls/ssl_ciphersuites.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_ciphersuites.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_cli.o: ../Core/lib/mbedtls/ssl_cli.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_cli.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_cookie.o: ../Core/lib/mbedtls/ssl_cookie.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_cookie.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_srv.o: ../Core/lib/mbedtls/ssl_srv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_srv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_ticket.o: ../Core/lib/mbedtls/ssl_ticket.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_ticket.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/ssl_tls.o: ../Core/lib/mbedtls/ssl_tls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/ssl_tls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/threading.o: ../Core/lib/mbedtls/threading.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/threading.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/timing.o: ../Core/lib/mbedtls/timing.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/timing.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/version.o: ../Core/lib/mbedtls/version.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/version.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/version_features.o: ../Core/lib/mbedtls/version_features.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/version_features.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509.o: ../Core/lib/mbedtls/x509.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509_create.o: ../Core/lib/mbedtls/x509_create.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509_create.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509_crl.o: ../Core/lib/mbedtls/x509_crl.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509_crl.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509_crt.o: ../Core/lib/mbedtls/x509_crt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509_crt.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509_csr.o: ../Core/lib/mbedtls/x509_csr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509_csr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509write_crt.o: ../Core/lib/mbedtls/x509write_crt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509write_crt.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/x509write_csr.o: ../Core/lib/mbedtls/x509write_csr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/x509write_csr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/lib/mbedtls/xtea.o: ../Core/lib/mbedtls/xtea.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L475xx -c -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Inc" -I../Drivers/CMSIS/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Src" -I../Core/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/wifi_Src" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I"/home/cocco/STM32CubeIDE/workspace_1.2.0/prova2/Core/lib/MQTT_Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/mbedtls/xtea.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

