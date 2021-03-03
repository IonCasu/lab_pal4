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
  *
  * Il codice qui scritto effettua le seguenti operazioni:
  *  - Connessione alla rete Wi-Fi
  *  - Creazione di una connessione criptata TLS
  *  - Creazione di una connessione MQTT
  *  - Sottoscrizione al topic di ricezione orario
  *  - Publish su due diversi topic
  *  - Scrittura a terminale di avvenuta ricezione di un messaggio inviato dal broker
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dfsdm.h"
#include "i2c.h"
#include "quadspi.h"
#include "rng.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "MQTT_fundamental.h"
#include "macro_def.h"
#include "eeprom_emul.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

#if defined (TERMINAL_USE)
extern UART_HandleTypeDef hDiscoUart;
#endif /* TERMINAL_USE */

/* Variabile che identifica l'SPI3 */
extern  SPI_HandleTypeDef hspi;


extern __IO uint32_t uwTick;
extern uint16_t dataCollectIterations;

/* Variabile Random Number Generator (RNG) */
RNG_HandleTypeDef hrng;

/* Variabili per connessione TLS */
mbedtls_net_context server_fd;
mbedtls_entropy_context entropy;
mbedtls_ssl_context ssl;
mbedtls_ctr_drbg_context ctr_drbg;
mbedtls_ssl_config conf;
mbedtls_x509_crt cacert;
Network network;

/* Variabile client MQTT */
MQTTClient c;

/*Variabili per la gestione dell'RTC*/
RTC_TimeTypeDef structureTimeGet;
RTC_DateTypeDef structureDateGet;

flags_t flags = {0};

//uint8_t timeReqFlag = 0;

/*
 * Variabili per la gestione del sensore HTS221 (temperatura e umidità)
 * */
	int i=0;
	int16_t T0_out, T1_out, T_out, T0_degC_x8_u16, T1_degC_x8_u16;
	int16_t T0_degC, T1_degC;
	uint8_t buffer[4], tmp;
	int32_t temperature32;
	char temperature32_string[5];

	int16_t H0_T0_out, H1_T0_out, H_T_out;
	int16_t H0_rh, H1_rh;
	int32_t humidity32;
	char humidity32_string[5];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

typedef enum{
	IDLE,
	timeRequest,
	dataRead,
	dataSend
}state;



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t ret = 0;

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
  MX_RTC_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */

  /*
   * Definizione parametri UART per scrittura a terminale
   */
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
#endif
  /* Inizializzazione TLS */
  Net_TLS_Init();
  /* Connessione alla rete Wi-Fi */

  /*
   * TODO: In caso di errore di mancata connessione al wifi (ret!=0) si deve pensare alla gestione
   */
  ret = board_wifi_init(SSID_RETE, PASSWORD);
  WIFI_Status_t conn_rc = WIFI_STATUS_ERROR;
  for(uint8_t connTrials=0; connTrials<CONNECTION_TRIAL_MAX;connTrials++)
  {
	  /* Connessione al server con TLS */
	  conn_rc = TLS_connect(SERVER_NAME, SERVER_PORT, SERVER_CN);
	  if(conn_rc==WIFI_STATUS_OK)
	  {
		  TERMOUT("> TLS connection to server SUCCESSFULL\n");
		  break;
	  }
	  else
	  {
		  TERMOUT("> TLS connection to server FAILED\n");
		  HAL_Delay(RECONNECT_DELAY);
		  if(connTrials==CONNECTION_TRIAL_MAX-1)
		  {
			  /*
			   * TODO: Gestire la mancata connessione al server
			   */
			  Error_Handler();
		  }
	  }
  }
  /* Setup connessione MQTT */
  MQTT_setup();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


#if defined (SERVER_MODENA)
  /*
   * Queste sono le variabili da riempire con i dati da inviare al server:
   *
   * diff_measures: Numero di diverse tipologie di misura
   * measures_name: Nome della misura
   * measure_unit: Unità di misura
   * data_type: Tipologia di dato (es. passo, salto, temp. interna, temp. esterna, ...)
   * values: Valori di misura. ATTENZIONE! tutti i valori delle misure devono essere inseriti
   * 		 in questo array in ordine come nelle variabili precedenti
   * 		 Esempio: prima i 10 valori di passo, poi i 5 di salto, poi i 7 di temp. interna,
   * 		 		  poi i 9 di temp. esterna
   * measures_intervals: Il numero di valori di ogni diversa misura
   * 					 (nel nostro esempio rispettivamente 10,5,7,9)
   *
   * TODO: Il massimo numero di caratteri della stringa sono 2000... valore da valutare
   *
   */
//  uint8_t diff_measures = 4;//numero di misure
//  char* measures_name[] = {"tmp","pos","vel","wgh"};
//  char* measure_unit[] = {"celsius","centimeters","meters/seconds","kg"};
//  char* data_type[] = {"ambient temperature", "foot position", "run speed", "subject weight"};
//  int values[] = {1,2,3,4,5,6,7,8,9,0};
//  int measures_intervals[] = {3,4,2,1};

    uint8_t diff_measures = 2;//numero di misure
    char* measures_name[] = {"Temperatura","Umidita"};	//nomi delle misure
    char* measure_unit[] = {"celsius","%"};	//unita' di misura
    char* data_type[] = {"temperatura ambiente", "umidita relativa"};
    uint8_t values[] = {0,0,0,0,0,0,0,0,0,0};
    int measures_intervals[] = {DATA_SEND_INTERVAL, DATA_SEND_INTERVAL};	//numero di campioni per ciascuna misura
    char* timestamps[DATA_SEND_INTERVAL];

    for(i=0;i<DATA_SEND_INTERVAL;i++){
    	timestamps[i] = (char*)malloc(17*sizeof(char));
    }

    //Per default tutti i flag sono 0, tranne quelli elencati sotto che devono essere a 1.
    flags.serverTimeRequest = 1;	//alla prima esecuzione chiedo il tempo

    /*Configurazione e abilitazione delle varie periferiche*/
    rtc_alarm_setup(23,55,00);	//impostazione dell'allarme; parametri: 1.ora, 2.minuti, 3.secondi;
    hts221_setup();	//configurazione del sensore di temperatura e umidità
    tim16_setup(TIM16_IRQ_INTERVAL);	//configurazione e abilitazione del timer TIM16

//    ee_init();


//    i=0;

  while (1)
  {



	/*Richiesta del tempo e aggiornamento dell'RTC*/
	if(flags.serverTimeRequest==1){

		TERMOUT("Chiedo il tempo al server\n");
		ret = request_time();
		ret = request_time();

		HAL_Delay(1000);

		if (ret == 0)
		{
		  TERMOUT("> Correct Publish to the topic: %s\n", TOPIC_REQ_TIME);
		}
		else
		{
		  /*
		   * TODO: Riavviare la connessione al broker in caso di errore nella publish
		   */
		  TERMOUT("> Unable to Publish to the topic: %s\n", TOPIC_REQ_TIME);
		}

//		//aspetto per un po' di tempo la risposta del server


		//azzero il flag
		flags.serverTimeRequest = 0;

	}
	if(flags.connectionCheck==1){

		TERMOUT("Sono nella Yield\n");	//per debug
		if ((ret=MQTTYield(&c, 1000))!=0)
		{
		  TERMOUT("Yield ERROR \n");
		  /*
		   * TODO: Riavviare la connessione al broker in caso di errore nella Yield
		   */
		}else{
			TERMOUT("Yield SUCCESS \n");	//per debug

			//azzero flag
			flags.connectionCheck = 0;
			TERMOUT("Esco dalla Yield\n");
		}

	}

	if(flags.sensorDataRead==1 && flags.connectionCheck == 0){

		TERMOUT("COLLECTING DATA\n");	//per debug

//		uint8_t to_flash[8];

//		//1. Leggo sensori
		hts221_temp_humidity_read((int32_t*)&values[i], (int32_t*)&values[i+DATA_SEND_INTERVAL]);
//		hts221_temp_humidity_read((int32_t*)&to_flash[0], (int32_t*)&to_flash[1]);

		HAL_RTC_GetTime(&hrtc, &structureTimeGet, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &structureDateGet, RTC_FORMAT_BIN);

		sprintf(timestamps[i], "%d:%d:%d-%d:%d:%d",
								structureDateGet.Year, structureDateGet.Month, structureDateGet.Date,
								structureTimeGet.Hours, structureTimeGet.Minutes, structureTimeGet.Seconds);
//		to_flash[2] = structureDateGet.Year;
//		to_flash[3] = structureDateGet.Month;
//		to_flash[4] = structureDateGet.Date;
//		to_flash[5] = structureTimeGet.Hours;
//		to_flash[6] = structureTimeGet.Minutes;
//		to_flash[7] = structureTimeGet.Seconds;
//
//		//2. Inserisco i dati nella flash
//		ee_writeToRam(8*i, 8, to_flash);
//		ee_commit();


		//Variabile che memorizza il numero di valori inseriti nella flash
		i++; if(i==DATA_SEND_INTERVAL){i=0;}

		//3. azzero flag
		flags.sensorDataRead=0;
	}

	if(flags.sensorDataSend==1 && flags.connectionCheck == 0){

		TERMOUT("SENDING DATA \n");

//		uint8_t from_flash[DATA_SEND_INTERVAL][8];

//		//1. Leggo i dati dalla flash
//		for(int i = 0; i < DATA_SEND_INTERVAL; i++){
//
//			ee_read(8*i, 8, from_flash[i]);
//
//		}


//		for(int i = 0; i < DATA_SEND_INTERVAL; i++){
//
//			values[i] = from_flash[i][0];
//			values[i+DATA_SEND_INTERVAL] = from_flash[i][1];
//			sprintf(timestamps[i], "%d:%d:%d-%d:%d:%d",
//									from_flash[i][2], from_flash[i][3], from_flash[i][4],
//									from_flash[i][5], from_flash[i][6], from_flash[i][7]);
//		}







		//2. Pubblico il messaggio
		send_data(diff_measures, measures_name, measure_unit, data_type, values, measures_intervals, timestamps);

//		//3. Cancello il vecchio set di campioni dalla flash
//		ee_format(true);

		//3. azzero flag
		flags.sensorDataSend=0;
	}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
#else

  MQTTMessage data_msg;
  uint8_t qos = QOS_PUB;
  char* data_send_topic = TOPIC_OSO;
  char buffer[2000];
  sprintf(buffer,"This is a test for yield verify");
  data_msg.payload = buffer;
  data_msg.payloadlen = strlen(data_msg.payload);
  data_msg.qos = qos;
  data_msg.retained = 0;
  data_msg.dup = 0;

  while (1)
  {
	  TERMOUT("> Message 1 at QoS %d\n", QOS_PUB);
	  ret = MQTTPublish(&c, data_send_topic, &data_msg);

	  if (ret == 0)
	  {
		  TERMOUT("> Correct Publish to the topic: %s\n", TOPIC_OSO);
	  }
	  else
	  {
		  /*
		   * TODO: Riavviare la connessione al broker in caso di errore nella publish
		   */
		  TERMOUT("> Unable to Publish to the topic: %s\n", TOPIC_OSO);
	  }
	  HAL_Delay(1000);

	  TERMOUT("> Message 2 at QoS %d\n", QOS_PUB);
	  ret = MQTTPublish(&c, data_send_topic, &data_msg);
	  if (ret == 0)
	  {
		  TERMOUT("> Correct Publish to the topic: %s\n", TOPIC_OSO);
	  }
	  else
	  {
		  /*
		   * TODO: Riavviare la connessione al broker in caso di errore nella publish
		   */
		  TERMOUT("> Unable to Publish to the topic: %s\n", TOPIC_OSO);
	  }
	  HAL_Delay(1000);

	  TERMOUT("> Time request \n");
	  ret = MQTTPublish(&c, data_send_topic, &data_msg);
	  if (ret == 0)
	  {
		  TERMOUT("> Correct Publish to the topic: %s\n", TOPIC_REQ_TIME);
	  }
	  else
	  {
		  /*
		   * TODO: Riavviare la connessione al broker in caso di errore nella publish
		   */
		  TERMOUT("> Unable to Publish to the topic: %s\n", TOPIC_REQ_TIME);
	  }
	  HAL_Delay(1000);

	  while(1)
	  {
		  if ((ret=MQTTYield(&c, 2000))!=0)
		  {
			  TERMOUT("Yield ERROR \n");
			  /*
			   * TODO: Riavviare la connessione al broker in caso di errore nella Yield
			   */
		  }
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
#endif
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_LSE
                              |RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_I2C2
                              |RCC_PERIPHCLK_DFSDM1|RCC_PERIPHCLK_USB
                              |RCC_PERIPHCLK_RNG;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
  PeriphClkInit.Dfsdm1ClockSelection = RCC_DFSDM1CLKSOURCE_PCLK;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
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

/*
 * 	@brief	Funzione di lettura del sensore HTS221
 * 	@param	temperature indirizzo della variabile in cui verrà salvata la temperatura calcolata
 * 	@param	humidity puntatore alla variabile per il salvataggio dell'umidità calcolata
 *
 * */
void hts221_temp_humidity_read(int32_t *temperature, int32_t *humidity){

	int32_t temp32, hum32;
	uint8_t buffer[2];

	/*Lettura dei registri 0x2A & 0x2B del sensore HTS221 contenenti la temperatura*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x2A, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x2B, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);
	T_out = ((uint16_t)buffer[1])<<8 | (uint16_t)buffer[0];

	/*Calcolo della temperatura per interpolazione lineare*/
	temp32 = ((((int32_t)(T_out - T0_out)) * ((int32_t)(T1_degC - T0_degC)))) / (T1_out - T0_out) + T0_degC;

	/*Lettura dell'umidità*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x28, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x29, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);
	H_T_out = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];

	/*Calcolo dell'umidità per interpolazione lineare*/
	hum32 = (((int32_t)(H_T_out - H0_T0_out)) * ((int32_t)(H1_rh - H0_rh))) / (uint16_t)(H1_T0_out - H0_T0_out) + H0_rh;

	/*Saturazione dell'umidità*/
	if(hum32>1000){hum32=1000;};

	*temperature = temp32;
	*humidity = hum32;

}

/*
 * @brief Configurazione del sensore HTS221 e lettura dei parametri di calibrazione.
 *
 * */
void hts221_setup(void){

	uint8_t msg;

	//CTRL_REG_1 config
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)HTS221_CTRL_REG_1, I2C_MEMADD_SIZE_8BIT, &msg, 1, 1000);
	msg |=  0b10000001 & 0b11111001;	//1Hz output data rate
	HAL_I2C_Mem_Write(&hi2c2, HTS221_DEVICE_ID_WRITE, (uint16_t)HTS221_CTRL_REG_1, I2C_MEMADD_SIZE_8BIT, &msg, 1, 1000);

	/*Lettura dai registri 0x32 & 0x33 dei coefficienti T0_degC_x8 e T1_degC_x8 */
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x32, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x33, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);

	/*Lettura dal registro 0x35 del valore dei MSB di T1_degC e T0_degC*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x35, I2C_MEMADD_SIZE_8BIT, &tmp, 1, 1000);

	/*Calcolo di T0_degC e T1_degC*/
	T0_degC_x8_u16 = ((uint16_t)(tmp & 0x03))<<8 | ((uint16_t)buffer[0]);
	T1_degC_x8_u16 = ((uint16_t)(tmp & 0x0C))<<6 | ((uint16_t)buffer[1]);
	T0_degC = T0_degC_x8_u16>>3; //divisione per 8
	T1_degC = T1_degC_x8_u16>>3; //divisione per 8

	/*Lettura di T0_out e T1_out out dai registri 0x3C & 0x3D e 0x3E & 0x3F rispettivamente*/

	for(i=0; i<4; i++){
	  HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x3C+i, I2C_MEMADD_SIZE_8BIT, &buffer[i], 1, 1000);
	}
	T0_out = ((uint16_t)buffer[1])<<8 | (uint16_t)buffer[0];
	T1_out = ((uint16_t)buffer[3])<<8 | (uint16_t)buffer[2];


	/*Gestione del sensore di umidità*/
	/*Lettura dei coefficienti H0_rH e H1_rH*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x30, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x31, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);
	H0_rh = buffer[0]>>1;
	H1_rh = buffer[1]>>1;

	/*Calcolo di H0_T0_OUT*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x36, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x37, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);
	H0_T0_out = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];

	/*Calcolo di H1_T0_OUT*/
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x3A, I2C_MEMADD_SIZE_8BIT, &buffer[0], 1, 1000);
	HAL_I2C_Mem_Read(&hi2c2, HTS221_DEVICE_ID_READ, (uint16_t)0x3B, I2C_MEMADD_SIZE_8BIT, &buffer[1], 1, 1000);
	H1_T0_out = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];

}

/*
 * @brief RTC setup
 *
 * */
void rtc_alarm_setup(uint8_t ora, uint8_t minuti, uint8_t secondi){

	RTC_AlarmTypeDef alarm_t = {0};

	alarm_t.AlarmTime.Hours = ora;
	alarm_t.AlarmTime.Minutes = minuti;
	alarm_t.AlarmTime.Seconds = secondi;
	alarm_t.AlarmTime.SubSeconds = 0;
	alarm_t.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	alarm_t.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	alarm_t.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY;
	alarm_t.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	alarm_t.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	alarm_t.AlarmDateWeekDay = 1;
	alarm_t.Alarm = RTC_ALARM_A;

	//alarm setup
	HAL_RTC_SetAlarm_IT(&hrtc, &alarm_t, RTC_FORMAT_BIN);

}

/*
 * 	@brief tim16 irq setup
 * 	@param irq_interval intervallo di tempo, espresso in secondi, che intercorra fra due interrupt consecutivi
 *
 *	@nota valore massimo ammissibile per irq_interval = 4166, che equivale a circa 69 minuti.
 * */

void tim16_setup(uint32_t irq_interval){

    TIM_HandleTypeDef htim16;

    htim16.Instance = TIM16;
    htim16.Init.Prescaler = 20000-1;
    htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim16.Init.Period = 16*irq_interval-1;
    htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim16.Init.RepetitionCounter = 250-1;
    htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

    //timer setup
    HAL_TIM_Base_Init(&htim16);

    //timer start
	HAL_TIM_Base_Start_IT(&htim16);
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
  /*
   * TODO: Questo è il posto giusto dove gestire i diversi errori
   */
  /* USER CODE END Error_Handler_Debug */
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
