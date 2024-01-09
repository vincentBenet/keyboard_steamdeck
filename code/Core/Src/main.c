/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usb_device.h"
#include "stdio.h"
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
extern USBD_HandleTypeDef hUsbDeviceFS;
typedef struct {
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}subKeyBoard;
subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  printf("Initialisation begin");

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
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  printf("Initialisation finish");
  printf("Infinite loop begin");

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  printf("Cycle begin");
	  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_SET);

	  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC1");
		  };
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC2");
		  };
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC3");
		  };
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC4");
		  };
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC5");
		  };
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC6");
		  };
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC7");
		  };
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC8");
		  };
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC9");
		  };
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC10");
		  };
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L1_GPIO_Port, L1_Pin)){
			  printf("L1xC11");
		  };
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);
	  }

	  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC1");
		  };
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC2");
		  };
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC3");
		  };
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC4");
		  };
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC5");
		  };
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC6");
		  };
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC7");
		  };
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC8");
		  };
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC9");
		  };
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC10");
		  };
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L2_GPIO_Port, L2_Pin)){
			  printf("L2xC11");
		  };
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);
	  }

	  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC1");
		  };
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC2");
		  };
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC3");
		  };
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC4");
		  };
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC5");
		  };
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC6");
		  };
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC7");
		  };
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC8");
		  };
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC9");
		  };
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC10");
		  };
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L3_GPIO_Port, L3_Pin)){
			  printf("L3xC11");
		  };
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);
	  }

	  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC1");
		  };
		  HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC2");
		  };
		  HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC3");
		  };
		  HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC4");
		  };
		  HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC5");
		  };
		  HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC6");
		  };
		  HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC7");
		  };
		  HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC8");
		  };
		  HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC9");
		  };
		  HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC10");
		  };
		  HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin (L4_GPIO_Port, L4_Pin)){
			  printf("L4xC11");
		  };
		  HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, GPIO_PIN_RESET);
	  }

	  /*
	  HAL_Delay(1000);
	  keyBoardHIDsub.MODIFIER=0x02;  // To press shift key
	  keyBoardHIDsub.KEYCODE1=0x04;  // Press A key
	  keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
	  keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
	  HAL_Delay(50); 		       // Press all key for 50 milliseconds
	  keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
	  keyBoardHIDsub.KEYCODE1=0x00;  // Release A key
	  keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
	  keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
	  */

	  printf("Cycle finish");
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_6;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, C10_Pin|C9_Pin|C8_Pin|C7_Pin
                          |C6_Pin|C5_Pin|C3_Pin|C2_Pin
                          |C1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, C4_Pin|C11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : C10_Pin C9_Pin C8_Pin C7_Pin
                           C6_Pin C5_Pin C3_Pin C2_Pin
                           C1_Pin */
  GPIO_InitStruct.Pin = C10_Pin|C9_Pin|C8_Pin|C7_Pin
                          |C6_Pin|C5_Pin|C3_Pin|C2_Pin
                          |C1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : C4_Pin C11_Pin */
  GPIO_InitStruct.Pin = C4_Pin|C11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : L2_Pin L1_Pin L4_Pin L3_Pin */
  GPIO_InitStruct.Pin = L2_Pin|L1_Pin|L4_Pin|L3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
