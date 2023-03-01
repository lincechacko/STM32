#include "main.h"
#include "stdio.h"
 
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart1;
 
uint8_t Buffer[25] = {0};
uint8_t Space[] = " - ";
uint8_t StartMSG[] = "Starting I2C Scanning: \r\n";
uint8_t EndMSG[] = "Done! \r\n\r\n";
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
 
int main(void)
{
    uint8_t i = 0, ret;
 
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_I2C1_Init();
    MX_USART1_UART_Init();
 
    HAL_Delay(1000);
 
    /*-[ I2C Bus Scanning ]-*/
    HAL_UART_Transmit(&huart1, StartMSG, sizeof(StartMSG), 10000);
    for(i=1; i<128; i++)
    {
        ret = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 3, 5);
        if (ret != HAL_OK) /* No ACK Received At That Address */
        {
            HAL_UART_Transmit(&huart1, Space, sizeof(Space), 10000);
        }
        else if(ret == HAL_OK)
        {
            sprintf(Buffer, "0x%X", i);
            HAL_UART_Transmit(&huart1, Buffer, sizeof(Buffer), 10000);
        }
    }
    HAL_UART_Transmit(&huart1, EndMSG, sizeof(EndMSG), 10000);
    /*--[ Scanning Done ]--*/
 
    while (1)
    {
    }
}