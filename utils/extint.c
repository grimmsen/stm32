// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "extint.h"
#include "gpio.h"
#include "../std/stdio.h"

void extint_init(uint8_t gpio, uint8_t num, uint8_t pin) {
  // enable pin for input
  switch(gpio) {
    case EXTI_GPIOA:
      gpio_pin_mode(GPIOA,pin,GPIO_MODE_INPUT);
      break;
    case EXTI_GPIOB:
      gpio_pin_mode(GPIOB,pin,GPIO_MODE_INPUT);
      break;
    case EXTI_GPIOC:
      gpio_pin_mode(GPIOC,pin,GPIO_MODE_INPUT);
      break;
    default:
      break;
  }
  // choose port in AFIO
  if(num<=3) {
    AFIO->EXTICR[0]|=(AFIO->EXTICR[0]&(~(0xf<<num)))&(gpio<<num);
  } else if (num==4) {
    AFIO->EXTICR[1]|=(AFIO->EXTICR[1]&(~0xf))&(gpio);
  }
  // enable interrupt
  EXTI->IMR|=(1<<pin);
  switch(num) {
    case 0:
      NVIC_SetPriority(EXTI0_IRQn,0);
      NVIC_EnableIRQ(EXTI0_IRQn);
      break;
    case 1:
      NVIC_SetPriority(EXTI1_IRQn,0);
      NVIC_EnableIRQ(EXTI1_IRQn);
      break;
    case 2:
      NVIC_SetPriority(EXTI2_IRQn,0);
      NVIC_EnableIRQ(EXTI2_IRQn);
      break;
    case 3:
      NVIC_SetPriority(EXTI3_IRQn,0);
      NVIC_EnableIRQ(EXTI3_IRQn);
      break;
    case 4:
      NVIC_SetPriority(EXTI4_IRQn,0);
      NVIC_EnableIRQ(EXTI4_IRQn);
      break;
    default:
      break;
  }
  return;
}

void extint_add_edge(uint8_t num, uint8_t edge) {
   // select edge
  if(edge==EXTI_FALLING_EDGE) {
    EXTI->FTSR|=(1<<num);
  } else {
    EXTI->RTSR|=(1<<num);
  }
}

void extint_clear_interrupt(uint8_t num) {
  switch(num) {
    case 0:
      EXTI->PR|=EXTI_PR_PR0;
      break;
    case 1:
      EXTI->PR|=EXTI_PR_PR1;
      break;
    case 2:
      EXTI->PR|=EXTI_PR_PR2;
      break;
    case 3:
      EXTI->PR|=EXTI_PR_PR3;
      break;
    case 4:
      EXTI->PR|=EXTI_PR_PR4;
      break;
    default:
      break;
  }
  return;
}

