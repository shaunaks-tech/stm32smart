#include <stm32f411xe.h>

void internal_clock(void) {
    // 1. Enable power control interface and set voltage scaling to Scale 2
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    // 2. Set Flash latency to 2 wait states and enable caches + prefetch
    FLASH->ACR |= FLASH_ACR_LATENCY_2WS;
    FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN;

    // 3. Configure AHB, APB1, and APB2 prescalers
    RCC->CFGR &= ~RCC_CFGR_HPRE;              // AHB prescaler = /1
    RCC->CFGR &= ~RCC_CFGR_PPRE1;             // Clear APB1 bits
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;         // APB1 prescaler = /2 (max 42 MHz)
    RCC->CFGR &= ~RCC_CFGR_PPRE2;             // Clear APB2 bits
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;         // APB2 prescaler = /1

    // 4. Enable HSE (external 25 MHz crystal)
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));       // Wait for HSE to stabilize

    // 5. Configure PLL
    // PLLM = 25, PLLN = 336, PLLP = 4, PLLQ = 7 → SYSCLK = 84 MHz
    RCC->PLLCFGR = 0;  // Reset PLLCFGR before setting
    RCC->PLLCFGR |= (25 << RCC_PLLCFGR_PLLM_Pos);     // PLLM = 25
    RCC->PLLCFGR |= (336 << RCC_PLLCFGR_PLLN_Pos);    // PLLN = 336
    RCC->PLLCFGR |= (1 << RCC_PLLCFGR_PLLP_Pos);      // PLLP = 4 (01)
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;           // PLL source = HSE
    RCC->PLLCFGR |= (7 << RCC_PLLCFGR_PLLQ_Pos);      // PLLQ = 7

    // 6. Enable PLL and wait for it to lock
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // 7. Switch system clock to PLL
    RCC->CFGR &= ~RCC_CFGR_SW;               // Clear SYSCLK bits
    RCC->CFGR |= RCC_CFGR_SW_PLL;            // Set SYSCLK source to PLL
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait for switch

    // 8. Update CMSIS variable (optional, but good)
    SystemCoreClockUpdate();
}