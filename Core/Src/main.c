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
#define DEBUG_LEVEL 2

/* Update SSID and PASSWORD with own Access point settings */
#define SERVER_PORT 8883
//#define SERVER_NAME "192.168.1.129"
#define SERVER_NAME "test.mosquitto.org"
#define WIFI_WRITE_TIMEOUT 10000
#define WIFI_READ_TIMEOUT  10000

#if defined (TERMINAL_USE)
#define TERMOUT(...)  printf(__VA_ARGS__)
#else
#define TERMOUT(...)
#endif

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

//key-size: 2048
/*const unsigned char certificate[] =
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
		"-----END CERTIFICATE-----\r\n";*/

//key-size: 4096
/*const unsigned char certificate[] =
		"-----BEGIN CERTIFICATE-----\r\n" 									   \
		"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\r\n" \
		"rqfkhnKu\r\n" 														   \
		"-----END CERTIFICATE-----\r\n";*/

//key-size: 8192
/*const unsigned char certificate[] =
		"-----BEGIN CERTIFICATE-----\r\n" 									   \
		"MIIJQjCCBSqgAwIBAgIBATANBgkqhkiG9w0BAQsFADA6MRIwEAYDVQQDDAlsb2Nh\r\n" \
		"bGhvc3QxFzAVBgNVBAoMDm15b3JnYW5pemF0aW9uMQswCQYDVQQGEwJOTDAeFw0y\r\n" \
		"MDAxMDEwMDAwMDBaFw0yMTEyMzEyMzU5NTlaMDoxEjAQBgNVBAMMCWxvY2FsaG9z\r\n" \
		"dDEXMBUGA1UECgwObXlvcmdhbml6YXRpb24xCzAJBgNVBAYTAk5MMIIEIjANBgkq\r\n" \
		"hkiG9w0BAQEFAAOCBA8AMIIECgKCBAEAo+l/wy/G67m4fEM8suBQlMYM9PB6F0zC\r\n" \
		"FRAZw6kEdaYeu1ET3cIV5uhnFbCmf8znVGXMeiCDioaScg8XyDlOFvpaOPks70BU\r\n" \
		"7rPS5GiNDfgjPKxtEbhN2tqeRzVLvWoJDECaplz9NHy+4GVrg7VAzeHU1tISs4qU\r\n" \
		"DP5Ao+DcLoakh/JedTKKFexDqXf9Jslep6WvOmdd8/a3u4bLbc/1nhc4dtzoeKaJ\r\n" \
		"B463j4p78/12cOj3u6Ig5QEfKYa5rdoKpRX8cPWeLr7JSYLYyA8yL7JTKUjbg90s\r\n" \
		"Aonvj22yu1VBQ+sh1k8n5txNG2mLlY+aU8/utehoX1fBktwyKp7vgsOHcsBrloi4\r\n" \
		"MqJaWptfvO8KZ1Xb6Vsu78AVQtkmd+VBs0YVF11/SAFbm+EENu8JAhg9KtPFajv1\r\n" \
		"TBgukgfvE0hP8AEIAqHJZ5RvBy058srM91poVDrI7//aIwpwrtcuzAmY9LIFIFRF\r\n" \
		"X/oEilzbfDQ/rGFO2YTKso4PnTBa0Pavm6kyx57cLlRLq7PC9Zy+I58y8z5gXbDa\r\n" \
		"UAjJcpGjYKrfWR3E4GFfnE5IredaM7db8ZtAD8f5+jc/xVQNDSL9uW3Q3eRQlpaC\r\n" \
		"Nhm4EEVl0o34IXeVMpefPsPLFXO4sGYbrN+xMDIS9pjR2En4LbfIqPtcDR4TdWN/\r\n" \
		"DNYHJ7TvGLttVPldaMbc+kbdLF+5xr9zxrZ6vr00pwY0JeMyCAI8QE6oQl5asFtn\r\n" \
		"QWJjFtbsI/+2B7vNW76qBoeWIHTvrFogN4mg64Ny8mbUGZG4bct2mcYNaDaHTWDm\r\n" \
		"JW4G6OgI4eFfHerjHe+6108eR/ekHkzUZO8Kq6Lbg1oWa2LNniC2iy29o9wKkEl8\r\n" \
		"idTsKJkWhsdcSsVaGaUiFbPe0G91SUrFDZ0rmkVaCL81CEdowDlKl79XEf5r/WWZ\r\n" \
		"MCwrNlhxOv+tqgW/BV13vuiAtRVnnIMjTwI3OFj1U65SlHlpxYQ56MtECkKbHo+1\r\n" \
		"erBfGIc5D6AFIjrYzrDs9TJR2c14mPgbuPclBRCQfz1qi7ytKkodnIH73YZj0gzc\r\n" \
		"0ZcFG5JoGKeUwoiuHtWr+1gY7Azffvv52sHQJ5Cm3A3B1ObFzIjSVKUvY/ObGKGc\r\n" \
		"VXYK4NLOFaCqbWX4Qbe2n+8KTfSFzOZpun0LooGO8DcVs7E3Oblao/UvV4RNGYh2\r\n" \
		"UvNA2PIZD9tM+vQ9EeNq9TGFfixo7HBmd0Hx0zgjrwIH++gqhPxA+bdcGpnKKPb0\r\n" \
		"VSjFFjPRCY/AJfD6NGXPeNTrdnd8WGHrZ7GvH3kx/hzs01Gnuju8iKPtftJ2/F9U\r\n" \
		"wbnwUU5JZN+uRaZzviisbkuX6Krck0QvfcpXkDr6fWnlIu1dy2aQuQIDAQABo1Mw\r\n" \
		"UTAPBgNVHRMECDAGAQH/AgEAMB0GA1UdDgQWBBTQtF2yZx2W49GmzJW9g526dayU\r\n" \
		"/TAfBgNVHSMEGDAWgBTQtF2yZx2W49GmzJW9g526dayU/TANBgkqhkiG9w0BAQsF\r\n" \
		"AAOCBAEAYclif5EEKJaLlFx+5azQa6+dcz6FYoTfDk5YMTPi0SkV2iCzRIRY9PIn\r\n" \
		"noIvbDGUbdqzWvAU8t8UqOINgJPQgS6HRxc1DKvw65vSoj1ZwPAgA2gG+IshLOYf\r\n" \
		"bvjU7/cb3/QWTq0IClEZoqOBry+8LlP9qz/bvrBqcx0kxioGnPob95EQdCqsgaXG\r\n" \
		"/rRTDpAjnJXMcoQEZ26ZOvYm/0at9GBt3vBs9m3Efe5yOXDorfLl7fgFJvewQgfH\r\n" \
		"/l7lp/fwyDeQIQCIQ20ZLFyKvpA2NWwB0I73nHh7ISzWlwvgymO6y4saXomM6Vnp\r\n" \
		"UEzWAr1ddt9CFyq3XTrchzmQUjKIWA5lzRBmCOnx3J4Wm0BixrAU8sQq4w6lODny\r\n" \
		"FYNTBs7dM9LFENEURYUaELI67P324MhMUkrxnzZEfviOgETvzmhed4xHGMYmiz0T\r\n" \
		"3wGjvscFwA4QCScg1JbSt33D4wWQAHXf+OKU7IsgwbRT2NgHZRq220I5SxI3V0aL\r\n" \
		"3BCWFaFKJcCa4/IpZUeV96A6NAF2HQXlpdWEoz9d0ItXNusdMzPZZo9OQ36xKW16\r\n" \
		"ckM171X//CuHaYSi/yKRY8PpfnhvQetb7AoHwC0hQt/uO+saTj0I1vYkPvMP3kaN\r\n" \
		"aSy13y8vHYHDBs4jxw4dJXjDHFyXteQcTpTl8L+rxayHwVpItvT/ZEitG2MmOVw3\r\n" \
		"Z+3va0++SgadTXODtX6S/7U+U3P4PszUAncxQqA4nhPm36cct2HJDK+1yMcM6p4n\r\n" \
		"mr+AHQi6nCzCMQz19FpDMYT93EYmntqMzuYjWcOcafd3mASU07m///j0UtqVF0Qx\r\n" \
		"2mblb4w5ZZdzqS/YoYuv3ECNvG5FY6KOaQhI9F+wTUZsaW+DMTD4ytB6Vp2LwYRq\r\n" \
		"7vsPLgwHdA8DEh9UAexi99ejmg/4Rnt7vVeEUPym3GjuCnk0gfUzCvL96vvCNFtC\r\n" \
		"qORrenGkv9LSRen1T/m3DoWv6GzeeRhrrbTN04MOoYuiGDYegu7IGyJN4rBRo/V/\r\n" \
		"sYwxnK/YuwcdCAwR1CZ3ICuRFQU9ztUJ+oTeSfqJF2qyYfRrkZGau+GL1JZSE2mF\r\n" \
		"7tPmlLUtNssvh9Q/Qq76EDjUT9O9+xpQ5n/3SmuiWwYBz+0FkQ3P9XgwN6GwE8Hn\r\n" \
		"RfFQgk9U41uYjaBz22DZUDETLvILj62Ae1WzhbaCkagHlUFnvAWXjFQXzowvZQXg\r\n" \
		"rab6xV/GVAYc+RF4WeCTQ4pNvpFHYdTreJ/sk+N3pPo3ltzOkDhh2DfninHo0/od\r\n" \
		"rdj2Bb9mp/GsqhOUPe8ziaIy23eKTCe1WwQS+2NrPIJx93CpqWHUlikYhN2VbY24\r\n" \
		"6NKRISnwVctYoyWVzGPf/xmj6bfOOw==\r\n" 								   \
		"-----END CERTIFICATE-----\r\n";*/


//mosquitto broker
const unsigned char certificate[] =
		"-----BEGIN CERTIFICATE-----\r\n" 									   \
		"MIIEAzCCAuugAwIBAgIUBY1hlCGvdj4NhBXkZ/uLUZNILAwwDQYJKoZIhvcNAQEL\r\n" \
		"BQAwgZAxCzAJBgNVBAYTAkdCMRcwFQYDVQQIDA5Vbml0ZWQgS2luZ2RvbTEOMAwG\r\n" \
		"A1UEBwwFRGVyYnkxEjAQBgNVBAoMCU1vc3F1aXR0bzELMAkGA1UECwwCQ0ExFjAU\r\n" \
		"BgNVBAMMDW1vc3F1aXR0by5vcmcxHzAdBgkqhkiG9w0BCQEWEHJvZ2VyQGF0Y2hv\r\n" \
		"by5vcmcwHhcNMjAwNjA5MTEwNjM5WhcNMzAwNjA3MTEwNjM5WjCBkDELMAkGA1UE\r\n" \
		"BhMCR0IxFzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTES\r\n" \
		"MBAGA1UECgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVp\r\n" \
		"dHRvLm9yZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzCCASIwDQYJ\r\n" \
		"KoZIhvcNAQEBBQADggEPADCCAQoCggEBAME0HKmIzfTOwkKLT3THHe+ObdizamPg\r\n" \
		"UZmD64Tf3zJdNeYGYn4CEXbyP6fy3tWc8S2boW6dzrH8SdFf9uo320GJA9B7U1FW\r\n" \
		"Te3xda/Lm3JFfaHjkWw7jBwcauQZjpGINHapHRlpiCZsquAthOgxW9SgDgYlGzEA\r\n" \
		"s06pkEFiMw+qDfLo/sxFKB6vQlFekMeCymjLCbNwPJyqyhFmPWwio/PDMruBTzPH\r\n" \
		"3cioBnrJWKXc3OjXdLGFJOfj7pP0j/dr2LH72eSvv3PQQFl90CZPFhrCUcRHSSxo\r\n" \
		"E6yjGOdnz7f6PveLIB574kQORwt8ePn0yidrTC1ictikED3nHYhMUOUCAwEAAaNT\r\n" \
		"MFEwHQYDVR0OBBYEFPVV6xBUFPiGKDyo5V3+Hbh4N9YSMB8GA1UdIwQYMBaAFPVV\r\n" \
		"6xBUFPiGKDyo5V3+Hbh4N9YSMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL\r\n" \
		"BQADggEBAGa9kS21N70ThM6/Hj9D7mbVxKLBjVWe2TPsGfbl3rEDfZ+OKRZ2j6AC\r\n" \
		"6r7jb4TZO3dzF2p6dgbrlU71Y/4K0TdzIjRj3cQ3KSm41JvUQ0hZ/c04iGDg/xWf\r\n" \
		"+pp58nfPAYwuerruPNWmlStWAXf0UTqRtg4hQDWBuUFDJTuWuuBvEXudz74eh/wK\r\n" \
		"sMwfu1HFvjy5Z0iMDU8PUDepjVolOCue9ashlS4EB5IECdSR2TItnAIiIwimx839\r\n" \
		"LdUdRudafMu5T5Xma182OC0/u/xRlEm+tvKGGmfFcN0piqVl8OrSPBgIlb+1IKJE\r\n" \
		"m/XriWr/Cq4h/JfB7NTsezVslgkBaoU=\r\n" 								   \
		"-----END CERTIFICATE-----\r\n";

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


  /*int len;
  unsigned char buf[1024];*/

  int ret;
  uint32_t flags;
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
  ret = mbedtls_x509_crt_parse( &cacert, certificate, sizeof( certificate ) );

  if( ret < 0 )
  {
	  TERMOUT( " failed\n  !  mbedtls_x509_crt_parse returned -0x%x\n", -ret );
  }

  TERMOUT( " ok (%d skipped)\n", ret );

  /*
   * 1. Start the connection
   */
  TERMOUT( "> Connecting to tcp/%s/%d...\n\n", SERVER_NAME, SERVER_PORT );

  if( ( ret = mbedtls_net_connect( &server_fd, (uint8_t *)SERVER_NAME,
		  	  	  	  	  	  SERVER_PORT, WIFI_TCP_PROTOCOL) ) != 0 )
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
  //if( ( ret = mbedtls_ssl_set_hostname( &ssl, "localhost" ) ) != 0 )
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
   * 3. Write to server
   */
  /*TERMOUT( "> Write to server:" );

  len = sprintf( (char *) buf, "prova" );

  while( ( ret = mbedtls_ssl_write( &ssl, buf, len ) ) <= 0 )
  {
      if( ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE )
      {
    	  TERMOUT( " failed\n  ! mbedtls_ssl_write returned %d\n\n", ret );
      }
  }

  len = ret;
  TERMOUT( " %d bytes written\n\n%s", len, (char *) buf );*/

  /*
   * 3. Read from server
   */
  /*TERMOUT( "  < Read from server:" );

  len = sizeof( buf ) - 1;
  memset( buf, 0, sizeof( buf ) );
  ret = mbedtls_ssl_read( &ssl, buf,(size_t)len );

  if( ret < 0 )
  {
	  TERMOUT( "failed\n  ! mbedtls_ssl_read returned %d\n\n", ret );
  }

  if( ret == 0 )
  {
	  TERMOUT( "\n\nEOF\n\n" );
  }

  len = ret;
  TERMOUT( " %d bytes read\n\n%s", len, (char *) buf );*/

  Network new_net;
  MQTTClient c;
  MQTTPacket_connectData options = MQTTPacket_connectData_initializer;
  uint8_t writebuf[1000];
  uint8_t readbuf[1000];

  NewNetwork(&new_net);
  MQTTClientInit(&c, &new_net, WIFI_WRITE_TIMEOUT, writebuf, 1000, readbuf, 1000);

  /*options.willFlag = 0;
  options.MQTTVersion = 3;
  options.clientID.cstring = "pc";
  options.username.cstring = "";
  options.password.cstring = "";
  options.keepAliveInterval = 10;
  options.cleansession = 1;
  options.will.message.cstring = "message";
  options.will.qos = 1;
  options.will.retained = 0;
  options.will.topicName.cstring = "topic";*/

  TERMOUT("> Connecting to MQTT Broker at %s:%d\n",SERVER_NAME,SERVER_PORT);
  ret = MQTTConnect(&c, &options);
  if (ret == 0)
  {
	  TERMOUT("> Connection established with the MQTT broker\n");
  }
  else
  {
	  TERMOUT("> Unable to connect with the MQTT broker\n");
  }

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
