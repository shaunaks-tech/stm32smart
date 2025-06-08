#include "stm32f4xx.h"

void i2c1_init(void) {
    // Enable GPIOB and I2C1 clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // Set PB8 and pb9 to alternate function mode 
    GPIOB->MODER &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9);
    GPIOB->MODER |= (GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1);

    // Set both pins to AF4 (I2C1)
    // GPIOB->AFR[1] &= ~(GPIO_AFRH_AFSEL8 | GPIO_AFRH_AFSEL9);
    // GPIOB->AFR[1] |= (4 << GPIO_AFRH_AFSEL8_Pos) | (4 << GPIO_AFRH_AFSEL9_Pos);
    GPIOB->AFR[1] &= ~((0xF << (4 * 0)) | (0xF << (4 * 1)));   // Clear PB8 (AFR[1] bit 0-3), PB9 (bit 4-7)
    GPIOB->AFR[1] |=  (4 << (4 * 0)) | (4 << (4 * 1));         // AF4 for I2C1

    // Enable pull ups for both pins
    GPIOB->OTYPER |= (1 << 8) | (1 << 9); // Set PB8 and PB9 to open-drain
    // GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR8 | GPIO_PUPDR_PUPDR9);
    // GPIOB->PUPDR |= (GPIO_PUPDR_PUPDR8_0 | GPIO_PUPDR_PUPDR9_0);
    
    // Enable I2C1 clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    // Reset I2C1
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST;

    // Configure i2c1 timing & enable
    I2C1->CR1 &= ~I2C_CR1_PE; // Disable I2C1
    I2C1->CR2 = 42; // 42MHz
    I2C1->CCR = 210; // 100kHz
    I2C1->TRISE = 43; // Rise time
    
    // Enable I2C1
    I2C1->CR1 |= I2C_CR1_PE; // Enable I2C1
}