#include <stm32f4xx.h>
#include <stdio.h>

extern void uart2_init(void);
extern void uart2_write_string(const char *s);
extern internal_clock(void);
extern void i2c1_init(void);
// write internal clock function to 84MHz for stm32f4 blackpill
int i2c1_check_device(uint8_t addr) {
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB)); // Wait for start bit
    (void)I2C1->SR1; // Clear start bit flag
    I2C1->DR = addr << 1; // Send address with write bit

    while (!(I2C1->SR1 & (I2C_SR1_ADDR | I2C_SR1_AF))); // Wait for address sent or NACK

    if (I2C1->SR1 & I2C_SR1_ADDR) {
        (void)I2C1->SR2; // Clear address flag
        I2C1->CR1 |= I2C_CR1_STOP; // Send stop condition
        return 1; // Device found
    }
    else {
        I2C1->CR1 |= I2C_CR1_STOP; // Send stop condition
        return 0; // Device not found
    }
}


int main(void) {
    
    internal_clock();  // CMSIS-based clock config to 84 MHz
    uart2_init();

    //Configure PC13 for output (LED control)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    GPIOC->MODER &= ~(3 << (13 * 2));
    GPIOC->MODER |= (1 << (13 * 2));
    GPIOC->OTYPER &= ~(1 << 13);
    GPIOC->PUPDR &= ~(3 << (13 * 2));

    // while (1) {
    //     GPIOC->ODR |= (1 << 13); // Set PC13 high
    //     for (volatile int i = 0; i < 1000000; i++); // Delay
    //     GPIOC->ODR &= ~(1 << 13); // Set PC13 low
    //     for (volatile int i = 0; i < 1000000; i++); // Delay

    // }
    // while (1) {
    //     uart2_write_string("Hello, World!\n");
    //     for (volatile int i = 0; i < 1000000; i++); // Delay
    // }

    uart2_write_string("Checking I2C devices...\n");
    i2c1_init(); // Initialize I2C1
   
    // AD0 Wired to GND, so address is 0x68, code to check if devicec is present
    int found = i2c1_check_device(0x68); 
    if (found) {
        uart2_write_string("Device at address 0x68 found!\n");
    } else {
        uart2_write_string("Device at address 0x68 not found.\n");
    }
    

    uart2_write_string("I2C scan complete.\n");
    while (1); 
}



