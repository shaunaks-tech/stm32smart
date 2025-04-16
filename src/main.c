#include <stm32f411xe.h>

// write internal clock function to 84MHz for stm32f4 blackpill
int main(void) {
    
    internal_clock();  // CMSIS-based clock config to 84 MHz

    // Configure PC13 for output (LED control)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    GPIOC->MODER &= ~(3 << (13 * 2));
    GPIOC->MODER |= (1 << (13 * 2));
    GPIOC->OTYPER &= ~(1 << 13);
    GPIOC->PUPDR &= ~(3 << (13 * 2));

    while (1) {
        GPIOC->ODR |= (1 << 13); // Set PC13 high
        for (volatile int i = 0; i < 1000000; i++); // Delay
        GPIOC->ODR &= ~(1 << 13); // Set PC13 low
        for (volatile int i = 0; i < 1000000; i++); // Delay

    }
}



