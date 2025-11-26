#include "stm32f10x.h"

uint32_t SystemCoreClock = 72000000; // Operating frequency

void SystemInit(void) {
    RCC->CR |= RCC_CR_HSEON;                     // Turning on HSE (external quartz)
    while (!(RCC->CR & RCC_CR_HSERDY));          // Waiting for the HSE to stabilize

    RCC->CFGR |= RCC_CFGR_PLLSRC;                // PLL from HSE
    RCC->CFGR |= RCC_CFGR_PLLMULL9;              // Multiplier 9 -> 8 MHz * 9 = 72 MHz

    RCC->CR |= RCC_CR_PLLON;                     // Enabling PLL
    while (!(RCC->CR & RCC_CR_PLLRDY));          // Waiting for the PLL to stabilize

    RCC->CFGR |= RCC_CFGR_SW_PLL;                // Switching the system clock to PLL
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); //Waiting for the switch to be completed
}


