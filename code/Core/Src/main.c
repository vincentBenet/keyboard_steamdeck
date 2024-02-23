/* USER CODE BEGIN Header */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define KEY_MOD_RCTRL 	0x10
#define KEY_MOD_RSHIFT 	0x20
#define KEY_MOD_RALT   	0x40
#define KEY_NONE 		0x00
#define KEY_ERR_OVF 	0x01

#define INDEX_FN1		31
#define INDEX_FN2		32
#define INDEX_FN3		42
#define INDEX_FN4		43


#define NUM_FN4_CTRL	16384
#define NUM_FN3_CTRL	8192
#define NUM_FN2_CTRL	4096
#define NUM_FN1_CTRL	2048
#define NUM_KEY_CTRL	1024
#define NUM_KEY_ALTGR	512
#define NUM_KEY_SHIFT	256
#define NUM_FN4_ALTGR	128
#define NUM_FN4_SHIFT	64
#define NUM_FN3_ALTGR	32
#define NUM_FN3_SHIFT	16
#define NUM_FN2_ALTGR	8
#define NUM_FN2_SHIFT	4
#define NUM_FN1_ALTGR	2
#define NUM_FN1_SHIFT	1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern USBD_HandleTypeDef hUsbDeviceFS;
typedef struct{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}subKeyBoard;
subKeyBoard keyBoardHIDsub = {0, 0, 0, 0, 0, 0, 0, 0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

uint8_t INPUTKEYS[44] = {
		0x29,	0x14,	0x1A,	0x08,	0x15,	0x17,	0x1C,	0x18,	0x0C,	0x12,	0x13,
		0x2B,	0x04,	0x16,	0x07,	0x09,	0x0A,	0x0B,	0x0D,	0x0E,	0x0F,	0x33,
		0x02,	0x1D,	0x1B,	0x06,	0x19,	0x05,	0x11,	0x52,	0x28,	0xFC,	0xFD,
		0x01,	0x08,	0x04,	0x2C,	0x2A,	0x4C,	0x50,	0x51,	0x4F,	0xFE,	0xFF
};
uint8_t FN1KEYS[44] = {
		0xF8,	0x1E,	0x1F,	0x20,	0x21,	0x22,	0x23,	0x24,	0x25,	0x26,	0x27,
		0x39,	0x22,	0x00,	0x2D,	0x00,	0x00,	0x00,	0x00,	0x00,	0x2D,	0x2E,
		0x02,	0x10,	0x36,	0x10,	0x36,	0x37,	0x38,	0x4B,	0x06,	0xFC,	0xFD,
		0x01,	0x08,	0x04,	0x23,	0x1A,	0x1C,	0x4A,	0x4E,	0x4D,	0xFE,	0xFF
};
uint8_t FN2KEYS[44] = {
		0x66,	0x1E,	0x1F,	0x20,	0x21,	0x22,	0x23,	0x24,	0x25,	0x26,	0x27,
		0x53,	0x22,	0x00,	0x2D,	0x00,	0x00,	0x00,	0x00,	0x00,	0x2D,	0x2E,
		0x02,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x09,	0x1B,	0xFC,	0xFD,
		0x01,	0x08,	0x04,	0x00,	0x00,	0x00,	0xEA,	0x15,	0xEB,	0xFE,	0xFF
};
uint8_t FN3KEYS[44] = {
		0x00,	0x3A,	0x3B,	0x3C,	0x3D,	0x3E,	0x3F,	0x40,	0x41,	0x42,	0x43,
		0x49,	0x21,	0x00,	0x2E,	0x00,	0x00,	0x34,	0x2F,	0x30,	0x44,	0x45,
		0x02,	0x08,	0x38,	0x30,	0x30,	0x34,	0x31,	0xE8,	0x19,	0xFC,	0xFD,
		0x01,	0x08,	0x04,	0xFA,	0x00,	0x00,	0xF1,	0x48,	0xF2,	0xFE,	0xFF
};
uint8_t FN4KEYS[44] = {
		0x00,	0x35,	0x1F,	0x20,	0x21,	0x22,	0x23,	0x24,	0x25,	0x2F,	0x27,
		0x00,	0x00,	0x2F,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x2D,	0x2E,
		0x02,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x80,	0x46,	0xFC,	0xFD,
		0x01,	0x08,	0x04,	0x00,	0x00,	0x00,	0x7F,	0x81,	0x65,	0xFE,	0xFF
};
bool MODIFIER_MASK[44] = {  // Mask of hardware fixed modifier keys (SHIFT, ALT, SUPER, CTRL)
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		true, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		true, 	true, 	true, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false
};
uint16_t TRIGGERS_MODIFIER[44] = {  // Mask for FN1-shift(1)FN1-altgr(2)FN2-shift(4)FN2-altgr(8)FN3-shift(16)FN3-altgr(32)FN4-shift(64)FN4-altgr(128)KEY-shift(256)Key-altgr(512)
		0,	4,	132,	132,	132,	132,	132,	132,	132,	4,	132,
		0,	40,	0,	40,	0,	0,	16,	16,	32,	132,	132,
		0,	33,	17,	16,	0,	0,	16,	4096,	14336,	0,	0,
		0,	0,	0,	0,	2048,	2048,	0,	0,	0,	0,	0
};
GPIO_TypeDef *GPIOPORTS_C[11] = {	GPIOA, 			GPIOA, 			GPIOA, 			GPIOB, 			GPIOA, 			GPIOA, 			GPIOA, 			GPIOA, 			GPIOA, 			GPIOA, 			GPIOB		};
int PINS_C[11] = {					GPIO_PIN_10, 	GPIO_PIN_9, 	GPIO_PIN_8, 	GPIO_PIN_0, 	GPIO_PIN_7, 	GPIO_PIN_6, 	GPIO_PIN_5, 	GPIO_PIN_4, 	GPIO_PIN_3, 	GPIO_PIN_2, 	GPIO_PIN_5	};
GPIO_TypeDef *GPIOPORTS_L[4] = {	GPIOB, 			GPIOB, 			GPIOB, 			GPIOB};
int PINS_L[4] = {					GPIO_PIN_2, 	GPIO_PIN_1, 	GPIO_PIN_7, 	GPIO_PIN_6};
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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  bool last_pressed = false;
  while (1){
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  bool PRESSED[44] = {  // Initialize physical mask pressed keys to all false
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false,
		false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false, 	false
	  };
	  bool press = false;  // Initialize pressed any physical key on keyboard
	  bool press_fn_bar = false;  // Initialize pressed any physical key that are not FN key
	  for (int c=0; c<11; c++) HAL_GPIO_WritePin(GPIOPORTS_C[c], PINS_C[c], GPIO_PIN_SET);  // All columns GPIO are turned ON
	  for (int line=0; line<4; line++) {
		  if(HAL_GPIO_ReadPin (GPIOPORTS_L[line], PINS_L[line])){  // Lines GPIO are checked
			  press = true;  // If one or more line GPIO are true: a key has been pressed
			  line = 4;
		   }
	  }

	  if (press){
		  for (int c=0; c<11; c++) HAL_GPIO_WritePin(GPIOPORTS_C[c], PINS_C[c], GPIO_PIN_RESET);  // All columns GPIO are turned OFF
		  for (int line=0; line<4; line++) {
			  for (int c=0; c<11; c++){  // Scan columns one by one to get all keys
				  HAL_GPIO_WritePin(GPIOPORTS_C[c], PINS_C[c], GPIO_PIN_SET);  // Turn ON GPIO of scanned column
				  if(HAL_GPIO_ReadPin (GPIOPORTS_L[line], PINS_L[line])){  // Check again line GPIO to test (column x line)
					  PRESSED[line * 11 + c] = true;  // Index of physical pressed key is turned to true
				  }
				  HAL_GPIO_WritePin(GPIOPORTS_C[c], PINS_C[c], GPIO_PIN_RESET);  // Turn OFF GPIO of scanned column
			  }
		  }

		  bool fn1 = PRESSED[INDEX_FN1];  // Check if FN1 is pressed
		  bool fn2 = PRESSED[INDEX_FN2];  // Check if FN2 is pressed
		  bool fn3 = PRESSED[INDEX_FN3];  // Check if FN3 is pressed
		  bool fn4 = PRESSED[INDEX_FN4];  // Check if FN4 is pressed
		  keyBoardHIDsub.MODIFIER = KEY_NONE;
		  for (int index=0; index<44; index++) {
			  if (MODIFIER_MASK[index] && PRESSED[index]) {
				  keyBoardHIDsub.MODIFIER |= (uint8_t)INPUTKEYS[index];
			  }
		  }
		  for (int index=0; index<44; index++) {  // Loop on every physical keys
			  if (
				  !PRESSED[index] ||  // Physical key is not pressed
				  MODIFIER_MASK[index] ||  // Si touches de modifier pressed
				  index == INDEX_FN1 ||  // FN1 is not analyzed
				  index == INDEX_FN2 ||  // FN2 is not analyzed
				  index == INDEX_FN3 ||  // FN3 is not analyzed
				  index == INDEX_FN4     // FN4 is not analyzed
			  ) continue;

			  press_fn_bar = true;  // A key that is not FN has been pressed

			  uint8_t 		  key = (uint8_t)INPUTKEYS[index];  // Affect standard key
			  if 		(fn1) key = (uint8_t)FN1KEYS[index];  // Affect FN1 key if is pressed
			  else if 	(fn2) key = (uint8_t)FN2KEYS[index];  // Affect FN2 key if is pressed€
			  else if 	(fn3) key = (uint8_t)FN3KEYS[index];  // Affect FN3 key if is pressed
			  else if 	(fn4) key = (uint8_t)FN4KEYS[index];  // Affect FN4 key if is pressed

			  uint16_t trigger_modifier = (uint16_t)TRIGGERS_MODIFIER[index];  // Get Modifier value index
			  // Affect modifier if specified in table TRIGGERS_MODIFIER
			  bool fn4_ctrl = trigger_modifier >= NUM_FN4_CTRL;
			  trigger_modifier -= NUM_FN4_CTRL * fn4_ctrl;
			  bool fn3_ctrl = trigger_modifier >= NUM_FN3_CTRL;
			  trigger_modifier -= NUM_FN3_CTRL * fn3_ctrl;
			  bool fn2_ctrl = trigger_modifier >= NUM_FN2_CTRL;
			  trigger_modifier -= NUM_FN2_CTRL * fn2_ctrl;
			  bool fn1_ctrl = trigger_modifier >= NUM_FN1_CTRL;
			  trigger_modifier -= NUM_FN1_CTRL * fn1_ctrl;
			  bool key_ctrl = trigger_modifier >= NUM_KEY_CTRL;
			  trigger_modifier -= NUM_KEY_CTRL * key_ctrl;
			  bool key_altgr = trigger_modifier >= NUM_KEY_ALTGR;  // If value in TRIGGERS_MODIFIER is higher than NUM_KEY_ALTGR
			  trigger_modifier -= NUM_KEY_ALTGR * key_altgr;  // Remove value NUM_KEY€_ALTGR from TRIGGERS_MODIFIER value index of key
			  bool key_shift = trigger_modifier >= NUM_KEY_SHIFT;  // Repeat for NUM_KEY_SHIFT
			  trigger_modifier -= NUM_KEY_SHIFT * key_shift;  // Repeat for NUM_KEY_SHIFT
			  bool fn4_altgr = trigger_modifier >= NUM_FN4_ALTGR;
			  trigger_modifier -= NUM_FN4_ALTGR * fn4_altgr;
			  bool fn4_shift = trigger_modifier >= NUM_FN4_SHIFT;
			  trigger_modifier -= NUM_FN4_SHIFT * fn4_shift;
			  bool fn3_altgr = trigger_modifier >= NUM_FN3_ALTGR;
			  trigger_modifier -= NUM_FN3_ALTGR * fn3_altgr;
			  bool fn3_shift = trigger_modifier >= NUM_FN3_SHIFT;
			  trigger_modifier -= NUM_FN3_SHIFT * fn3_shift;
			  bool fn2_altgr = trigger_modifier >= NUM_FN2_ALTGR;
			  trigger_modifier -= NUM_FN2_ALTGR * fn2_altgr;
			  bool fn2_shift = trigger_modifier >= NUM_FN2_SHIFT;
			  trigger_modifier -= NUM_FN2_SHIFT * fn2_shift;
			  bool fn1_altgr = trigger_modifier >= NUM_FN1_ALTGR;
			  trigger_modifier -= NUM_FN1_ALTGR * fn1_altgr;
			  bool fn1_shift = trigger_modifier >= NUM_FN1_SHIFT;
			  trigger_modifier -= NUM_FN1_SHIFT * fn1_shift;

			  if (
				  (key_altgr && !(fn1 || fn2 || fn3 || fn4)) ||
				  (fn4_altgr && fn4) ||
				  (fn3_altgr && fn3) ||
				  (fn2_altgr && fn2) ||
				  (fn1_altgr && fn1)
			  ) keyBoardHIDsub.MODIFIER |= KEY_MOD_RALT;

			  else if (
				  (key_shift && !(fn1 || fn2 || fn3 || fn4)) ||
				  (fn4_shift && fn4)  ||
				  (fn3_shift && fn3)  ||
				  (fn2_shift && fn2)  ||
				  (fn1_shift && fn1)
			  ) keyBoardHIDsub.MODIFIER |= KEY_MOD_RSHIFT;

			  else if (
				  (key_ctrl && !(fn1 || fn2 || fn3 || fn4)) ||
				  (fn4_ctrl && fn4)  ||
				  (fn3_ctrl && fn3)  ||
				  (fn2_ctrl && fn2)  ||
				  (fn1_ctrl && fn1)
			  ) keyBoardHIDsub.MODIFIER |= KEY_MOD_RCTRL;


			  if 		(keyBoardHIDsub.KEYCODE1 == 0x00) 	keyBoardHIDsub.KEYCODE1 = 	key;
			  else if 	(keyBoardHIDsub.KEYCODE2 == 0x00) 	keyBoardHIDsub.KEYCODE2 = 	key;
			  else if 	(keyBoardHIDsub.KEYCODE3 == 0x00) 	keyBoardHIDsub.KEYCODE3 = 	key;
			  else if 	(keyBoardHIDsub.KEYCODE4 == 0x00) 	keyBoardHIDsub.KEYCODE4 = 	key;
			  else if 	(keyBoardHIDsub.KEYCODE5 == 0x00) 	keyBoardHIDsub.KEYCODE5 = 	key;
			  else if 	(keyBoardHIDsub.KEYCODE6 == 0x00) 	keyBoardHIDsub.KEYCODE6 = 	key;

			  else {  // Too much key pressed
				  keyBoardHIDsub.MODIFIER = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE1 = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE2 = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE3 = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE4 = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE5 = KEY_ERR_OVF;
				  keyBoardHIDsub.KEYCODE6 = KEY_ERR_OVF;
			  }
		  };
		  if (press_fn_bar){
			  USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));  // Send keys report thought USB
		  }
		  HAL_Delay(50);  // Wait of loop iteration in ms
	  } else {
		  HAL_Delay(100);  // Wait of loop iteration in ms
	  }

	  if (!press_fn_bar && last_pressed) {
		  keyBoardHIDsub.MODIFIER = KEY_NONE;
		  keyBoardHIDsub.KEYCODE1 = KEY_NONE;
		  keyBoardHIDsub.KEYCODE2 = KEY_NONE;
		  keyBoardHIDsub.KEYCODE3 = KEY_NONE;
		  keyBoardHIDsub.KEYCODE4 = KEY_NONE;
		  keyBoardHIDsub.KEYCODE5 = KEY_NONE;
		  keyBoardHIDsub.KEYCODE6 = KEY_NONE;
		  USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));
	  }
	  last_pressed = press_fn_bar;
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
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_3;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
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
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA3 PA4 PA5
                           PA6 PA7 PA8 PA9
                           PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB2 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_6|GPIO_PIN_7;
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
