#include <stm32f4xx.h>
void uart2_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    GPIOA->MODER &= ~(3 << (2 * 2));
    GPIOA->MODER |=  (2 << (2 * 2));  // Alternate function
    GPIOA->AFR[0] &= ~(0xF << (4 * 2));
    GPIOA->AFR[0] |=  (7 << (4 * 2));  // AF7 = USART2

    // USART2->BRR = 0x2D9;  // 115200 baud @ 84 MHz
    // USART2->BRR= 0x1A0;
   //  USART2->BRR = 16000000 / 115200;
    // Assuming APB1 clock is 42 MHz (default for STM32F4 when SYSCLK is 84 MHz)
    USART2->BRR = 42000000 / 115200;
    USART2->CR1 |= USART_CR1_TE | USART_CR1_UE;
}

void uart2_write_string(const char *s) {
    while (*s) {
        while (!(USART2->SR & USART_SR_TXE));
        USART2->DR = *s++;
    }
}