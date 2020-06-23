/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dfsdm.h"
#include "i2c.h"
#include "quadspi.h"
#include "rng.h"
#include "spi.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TERMINAL_USE
#define DEBUG_LEVEL 1

/* Update SSID and PASSWORD with own Access point settings */
uint8_t RemoteIP[] = {192,168,1,129};
#define RemotePORT	4433
#define SERVER_PORT "4433"
#define SERVER_NAME "localhost"
#define WIFI_WRITE_TIMEOUT 10000
#define WIFI_READ_TIMEOUT  10000
#define WRITE_BUF_SIZE	100
#define READ_BUF_SIZE	100

#if defined (TERMINAL_USE)
#define TERMOUT(...)  printf(__VA_ARGS__)
#else
#define TERMOUT(...)
#endif

#define ca_cert									   					   	   \
	"-----BEGIN CERTIFICATE-----\r\n" 								 	   \
	"MIIDQjCCAiqgAwIBAgIBATANBgkqhkiG9w0BAQsFADA6MRIwEAYDVQQDDAlsb2Nh\r\n" \
	"bGhvc3QxFzAVBgNVBAoMDm15b3JnYW5pemF0aW9uMQswCQYDVQQGEwJOTDAeFw0y\r\n" \
	"MDAxMDEwMDAwMDBaFw0yMTEyMzEyMzU5NTlaMDoxEjAQBgNVBAMMCWxvY2FsaG9z\r\n" \
	"dDEXMBUGA1UECgwObXlvcmdhbml6YXRpb24xCzAJBgNVBAYTAk5MMIIBIjANBgkq\r\n" \
	"hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA5R/XfHLERFGsV/rlbLQ0qDZS9W8o7bQK\r\n" \
	"T63kVgR4/4+9sWgOqDM4OIv4Y6m3LQ2oxqKAVFSQJ5m+KqA5c7oO464KkGCK3i/i\r\n" \
	"fnl/5sraNsgxrSRSTOPboQ9KNW3BssBXyECAXTUuW43P0mxisXv7Oe+yVTIZaVEh\r\n" \
	"3r7rIOLyxewWYDauST98apqhK+MRc+H8zGKkqy64mgcRK9xkaLalzudguaTS8gcc\r\n" \
	"XP+l32n1THJEj6/Q1PoeK4tAgqDdngV/Z8nBniv9VCxG+pYukJ/6dB9u9LLPL0oI\r\n" \
	"Lp8p0LI9SDKJqns8MfaTeUJ/ub/rY7E0WOneYs9UlUN524ziUwTGQwIDAQABo1Mw\r\n" \
	"UTAPBgNVHRMECDAGAQH/AgEAMB0GA1UdDgQWBBTsiPRR8fzUM+X309HWu1+VOZkQ\r\n" \
	"RTAfBgNVHSMEGDAWgBTsiPRR8fzUM+X309HWu1+VOZkQRTANBgkqhkiG9w0BAQsF\r\n" \
	"AAOCAQEANUxAiSOR7Rpf5K0cG6n6eMmd37S3AiVmXYxEbz4ZOnTMzmxcVS8UbMLQ\r\n" \
	"ZqI8rVuj4+P+cePOgnp/FqaD24OdJ1TME/T20476WKFDem6MwRkrcXzvoFFbaLKQ\r\n" \
	"PhDi0TBWhS3Pep7+SpuhFowRDwzozCemzBkS30yMcXWVs1f92/IwRFWhScI8sT+M\r\n" \
	"UQpXXeqL7BWkLTGI9EgldDfuEg9/Bet6OXahF3LnoM3I+NzCavc2LlJtA5sdafJW\r\n" \
	"H7WhCfqQc8QClsOaJs1r9cn4QTYucoux4IaUeK1xLvLeELVMmtSAzfqeX0Yyu3MD\r\n" \
	"/LWsuxQHsRyN4FFLpsMhrxHc+5OMeQ==\r\n" 								   \
	"-----END CERTIFICATE-----\r\n"

/*	"-----BEGIN CERTIFICATE-----\r\n"                                      \
    "MIIDQTCCAimgAwIBAgIBAzANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJOTDER\r\n" \
    "MA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0EwHhcN\r\n" \
    "MTkwMjEwMTQ0NDAwWhcNMjkwMjEwMTQ0NDAwWjA7MQswCQYDVQQGEwJOTDERMA8G\r\n" \
    "A1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0EwggEiMA0G\r\n" \
    "CSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDA3zf8F7vglp0/ht6WMn1EpRagzSHx\r\n" \
    "mdTs6st8GFgIlKXsm8WL3xoemTiZhx57wI053zhdcHgH057Zk+i5clHFzqMwUqny\r\n" \
    "50BwFMtEonILwuVA+T7lpg6z+exKY8C4KQB0nFc7qKUEkHHxvYPZP9al4jwqj+8n\r\n" \
    "YMPGn8u67GB9t+aEMr5P+1gmIgNb1LTV+/Xjli5wwOQuvfwu7uJBVcA0Ln0kcmnL\r\n" \
    "R7EUQIN9Z/SG9jGr8XmksrUuEvmEF/Bibyc+E1ixVA0hmnM3oTDPb5Lc9un8rNsu\r\n" \
    "KNF+AksjoBXyOGVkCeoMbo4bF6BxyLObyavpw/LPh5aPgAIynplYb6LVAgMBAAGj\r\n" \
    "UDBOMAwGA1UdEwQFMAMBAf8wHQYDVR0OBBYEFLRa5KWz3tJS9rnVppUP6z68x/3/\r\n" \
    "MB8GA1UdIwQYMBaAFLRa5KWz3tJS9rnVppUP6z68x/3/MA0GCSqGSIb3DQEBCwUA\r\n" \
    "A4IBAQA4qFSCth2q22uJIdE4KGHJsJjVEfw2/xn+MkTvCMfxVrvmRvqCtjE4tKDl\r\n" \
    "oK4MxFOek07oDZwvtAT9ijn1hHftTNS7RH9zd/fxNpfcHnMZXVC4w4DNA1fSANtW\r\n" \
    "5sY1JB5Je9jScrsLSS+mAjyv0Ow3Hb2Bix8wu7xNNrV5fIf7Ubm+wt6SqEBxu3Kb\r\n" \
    "+EfObAT4huf3czznhH3C17ed6NSbXwoXfby7stWUDeRJv08RaFOykf/Aae7bY5PL\r\n" \
    "yTVrkAnikMntJ9YI+hNNYt3inqq11A5cN0+rVTst8UKCxzQ4GpvroSwPKTFkbMw4\r\n" \
    "/anT1dVxr/BtwJfiESoK3/4CeXR1\r\n"                                     \
    "-----END CERTIFICATE-----\r\n"*/

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
RNG_HandleTypeDef hrng;
uint32_t myRandomNum;

#if defined (TERMINAL_USE)
extern UART_HandleTypeDef hDiscoUart;
#endif /* TERMINAL_USE */

mbedtls_net_context server_fd;
mbedtls_entropy_context entropy;
mbedtls_ctr_drbg_context ctr_drbg;
mbedtls_ssl_context ssl;
mbedtls_ssl_config conf;
mbedtls_x509_crt cacert;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
extern  SPI_HandleTypeDef hspi;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

static void my_debug(void *ctx, int level, const char *file, int line,
                     const char *str)
{
    const char *p, *basename;
    (void) ctx;

    /* Extract basename from file */
    for(p = basename = file; *p != '\0'; p++) {
        if(*p == '/' || *p == '\\') {
            basename = p + 1;
        }
    }

    TERMOUT("%s:%04d: |%d| %s", basename, line, level, str);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DFSDM1_Init();
  MX_I2C2_Init();
  MX_QUADSPI_Init();
  MX_SPI3_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */
#if defined (TERMINAL_USE)
  /* Initialize all configured peripherals */
  hDiscoUart.Instance = DISCOVERY_COM1;
  hDiscoUart.Init.BaudRate = 115200;
  hDiscoUart.Init.WordLength = UART_WORDLENGTH_8B;
  hDiscoUart.Init.StopBits = UART_STOPBITS_1;
  hDiscoUart.Init.Parity = UART_PARITY_NONE;
  hDiscoUart.Init.Mode = UART_MODE_TX_RX;
  hDiscoUart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  hDiscoUart.Init.OverSampling = UART_OVERSAMPLING_16;
  hDiscoUart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  hDiscoUart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

  BSP_COM_Init(COM1, &hDiscoUart);
#endif /* TERMINAL_USE */

  int ret;
   int len;
  uint32_t flags;
  unsigned char buf[1024];
  const char *pers = "ssl_client1";
  uint32_t read_timeout=10000;

  mbedtls_net_init( &server_fd );
  mbedtls_ssl_init( &ssl );
  mbedtls_ssl_config_init( &conf );
  mbedtls_x509_crt_init( &cacert );
  mbedtls_ctr_drbg_init( &ctr_drbg );
  mbedtls_entropy_init( &entropy );

	#if DEBUG_LEVEL > 0
			mbedtls_ssl_conf_dbg(&conf, my_debug, NULL);
			mbedtls_debug_set_threshold(DEBUG_LEVEL);
	#endif

  TERMOUT( "> Adding a new entropy source..." );
  ret = mbedtls_entropy_add_source(&entropy,mbedtls_rng_poll_cb,&hrng,32,MBEDTLS_ENTROPY_SOURCE_STRONG);
  if (ret != 0)
    {
  	  TERMOUT( " failed\n  ! mbedtls_entropy_add_source returned %d\n", ret );
    }

  TERMOUT( " ok\n" );

  /*
   * 0. Initialize the RNG and the session data
   */
  TERMOUT( "> Seeding the random number generator..." );

  if( ( ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
							 (const unsigned char *) pers,
							 strlen( pers ) ) ) != 0 )
  {
	  TERMOUT( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret );
  }

  TERMOUT( " ok\n" );

  /*
   * 0. Initialize certificates
   */
  TERMOUT( "> Loading the CA root certificate ..." );

  /*ret = mbedtls_x509_crt_parse( &cacert, (const unsigned char *) mbedtls_test_cas_pem,
						mbedtls_test_cas_pem_len );*/
  ret = mbedtls_x509_crt_parse( &cacert, (const unsigned char *) ca_cert, sizeof( ca_cert ) );

  if( ret < 0 )
  {
	  TERMOUT( " failed\n  !  mbedtls_x509_crt_parse returned -0x%x\n", -ret );
  }

  TERMOUT( " ok (%d skipped)\n", ret );

  /*
   * 1. Start the connection
   */
  TERMOUT( "> Connecting to tcp/%s/%s...\n\n", SERVER_NAME, SERVER_PORT );

  if( ( ret = mbedtls_net_connect( &server_fd, RemoteIP,
                                       RemotePORT, MBEDTLS_NET_PROTO_TCP ) ) != 0 )
  {
	  TERMOUT( " failed\n  ! mbedtls_net_connect returned %d\n", ret );
  }

  /*
   * 2. Setup stuff
   */
  TERMOUT( "> Setting up the SSL/TLS structure..." );

  if( ( ret = mbedtls_ssl_config_defaults( &conf,
                  MBEDTLS_SSL_IS_CLIENT,
                  MBEDTLS_SSL_TRANSPORT_STREAM,
                  MBEDTLS_SSL_PRESET_DEFAULT ) ) != 0 )
  {
	  TERMOUT( " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret );
  }

  TERMOUT( " ok\n" );

  /* OPTIONAL is not optimal for security,
   * but makes interop easier in this simplified example */
  mbedtls_ssl_conf_authmode( &conf, MBEDTLS_SSL_VERIFY_REQUIRED);
  mbedtls_ssl_conf_ca_chain( &conf, &cacert, NULL );

  mbedtls_ssl_conf_read_timeout( &conf, read_timeout );

  mbedtls_ssl_conf_rng( &conf, mbedtls_ctr_drbg_random, &ctr_drbg );

  if( ( ret = mbedtls_ssl_setup( &ssl, &conf ) ) != 0 )
  {
      TERMOUT( " failed\n  ! mbedtls_ssl_setup returned %d\n", ret );
  }

  if( ( ret = mbedtls_ssl_set_hostname( &ssl, SERVER_NAME ) ) != 0 )
  //if( ( ret = mbedtls_ssl_set_hostname( &ssl, "PolarSSL Test CA" ) ) != 0 )
  {
      TERMOUT( " failed\n  ! mbedtls_ssl_set_hostname returned %d\n", ret );
  }

  mbedtls_ssl_set_bio(&ssl, &server_fd, mbedtls_net_send, NULL, mbedtls_net_recv);

  /*
   * 4. Handshake
   */
  TERMOUT( "> Performing the SSL/TLS handshake..." );

  while( ( ret = mbedtls_ssl_handshake( &ssl ) ) != 0 )
  {
     // if( ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE )
      if( ret != MBEDTLS_ERR_SSL_WANT_READ &&
          ret != MBEDTLS_ERR_SSL_WANT_WRITE &&
          ret != MBEDTLS_ERR_SSL_CRYPTO_IN_PROGRESS )
      {
    	  TERMOUT( " failed\n  ! mbedtls_ssl_handshake returned -0x%x\n\n", -ret );
      }
  }

  TERMOUT( " ok\n" );

  /*
   * 5. Verify the server certificate
   */
  TERMOUT( "> Verifying peer X.509 certificate..." );

  /* In real life, we probably want to bail out when ret != 0 */
  if( ( flags = mbedtls_ssl_get_verify_result( &ssl ) ) != 0 )
  {
      char vrfy_buf[512];

      TERMOUT( " failed\n" );

      mbedtls_x509_crt_verify_info( vrfy_buf, sizeof( vrfy_buf ), "  ! ", flags );

      TERMOUT( "%s\n", vrfy_buf );
  }
  else
	  TERMOUT( " ok\n" );

  /*
   * 3. Write the GET request
   */
  TERMOUT( "> Write to server:" );
  fflush( stdout );

  len = sprintf( (char *) buf, "prova" );

  while( ( ret = mbedtls_ssl_write( &ssl, buf, len ) ) <= 0 )
  {
      if( ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE )
      {
    	  TERMOUT( " failed\n  ! mbedtls_ssl_write returned %d\n\n", ret );
      }
  }

  len = ret;
  mbedtls_printf( " %d bytes written\n\n%s", len, (char *) buf );

  mbedtls_x509_crt_free( &cacert );
  mbedtls_ssl_free( &ssl );
  mbedtls_ssl_config_free( &conf );
  mbedtls_ctr_drbg_free( &ctr_drbg );
  mbedtls_entropy_free( &entropy );

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART3
                              |RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_DFSDM1
                              |RCC_PERIPHCLK_USB|RCC_PERIPHCLK_RNG;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
  PeriphClkInit.Dfsdm1ClockSelection = RCC_DFSDM1CLKSOURCE_PCLK;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
  PeriphClkInit.RngClockSelection = RCC_RNGCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration 
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
    case (GPIO_PIN_1):
    {
      SPI_WIFI_ISR();
      break;
    }
    default:
    {
      break;
    }
  }
}

void SPI3_IRQHandler(void)
{
  HAL_SPI_IRQHandler(&hspi);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

void mbedtls_net_init( mbedtls_net_context *ctx )
{
  ctx->fd = -1;
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
