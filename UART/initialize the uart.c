#include "stm32f4xx_hal.h"
#include "usart.h"

UART_HandleTypeDef huart2;

/* Initialize UART */
HAL_UART_MspInit(&huart2);  // Initialize the UART pins and clock
huart2.Instance = USART2;   // Use USART2
huart2.Init.BaudRate = 115200;
huart2.Init.WordLength = UART_WORDLENGTH_8B;
huart2.Init.StopBits = UART_STOPBITS_1;
huart2.Init.Parity = UART_PARITY_NONE;
huart2.Init.Mode = UART_MODE_TX_RX;
huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
HAL_UART_Init(&huart2);
