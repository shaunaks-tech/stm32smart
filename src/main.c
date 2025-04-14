#include "stm32f4xx_hal.h"

void SystemClock_Config(void);

int main(void) {
    HAL_Init();                  // Initialize the HAL Library
    SystemClock_Config();        // Configure the system clock

    __HAL_RCC_GPIOA_CLK_ENABLE(); // Enable GPIOA clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Toggle PA5
        HAL_Delay(500);                        // Wait 500ms
    }
}
