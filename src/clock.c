#include "stm32f4xx.h"

void internal_clock(void) {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    FLASH->ACR |= FLASH_ACR_LATENCY_2WS;
    FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN;

    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // APB1 prescaler
    RCC->CFGR &= ~RCC_CFGR_PPRE2;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; // APB2 prescaler

    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN |
                      RCC_PLLCFGR_PLLP | RCC_PLLCFGR_PLLSRC |
                      RCC_PLLCFGR_PLLQ);

    RCC->PLLCFGR |= (16 << RCC_PLLCFGR_PLLM_Pos);
    RCC->PLLCFGR |= (336 << RCC_PLLCFGR_PLLN_Pos);
    RCC->PLLCFGR |= (1 << RCC_PLLCFGR_PLLP_Pos);
    RCC->PLLCFGR |= (0 << RCC_PLLCFGR_PLLSRC_Pos);  // HSI selected
    RCC->PLLCFGR |= (7 << RCC_PLLCFGR_PLLQ_Pos);

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    SystemCoreClock = 84000000;
    //SystemCoreClockUpdate();
}


