#include "clock.h"

uint8_t clock_speed;

uint32_t clock_set_speed(uint32_t mhz) {
  clock_speed=mhz;
  uint32_t multiplier;
  switch (mhz) {
    case 16:
      multiplier = RCC_CFGR_PLLMULL2;
      break;
    case 24:
      multiplier = RCC_CFGR_PLLMULL3;
      break;
    case 32:
      multiplier = RCC_CFGR_PLLMULL4;
      break;
    case 40:
      multiplier = RCC_CFGR_PLLMULL5;
      break;
    case 48:
      multiplier = RCC_CFGR_PLLMULL6;
      break;
    case 56:
      multiplier = RCC_CFGR_PLLMULL7;
      break;
    case 64:
      multiplier = RCC_CFGR_PLLMULL8;
      break;
    case 72:
      multiplier = RCC_CFGR_PLLMULL9;
      break;
    default:
      return 8000000;
  }
  // set flash latency
  FLASH->ACR |= FLASH_ACR_LATENCY_2;
  // set APB clock
  RCC->CFGR |= RCC_CFGR_PPRE1_2;
  RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE;
  // turn on HSE
  RCC->CR |= RCC_CR_HSEON;
  while(!(RCC->CR & RCC_CR_HSERDY)) ;
  WRITE_REG(GPIOC->CRH, READ_REG(GPIOC->CRH)&0xf0ffffff|0x08000000);
  // setup PLL
  RCC->CFGR |= RCC_CFGR_PLLSRC;
  RCC->CFGR |= multiplier;
  RCC->CR |= RCC_CR_PLLON;
  while(!(RCC->CR & RCC_CR_PLLRDY)) ;
  // set clock source
  RCC->CFGR |= RCC_CFGR_SW_PLL;
  while(!(RCC->CFGR & RCC_CFGR_SWS_PLL)) ;
  // and done
}

