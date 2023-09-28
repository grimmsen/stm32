// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "uart.h"

extern uint8_t clock_speed;

void uart2_init() {
  RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
  gpio_pin_mode(GPIOA,2,GPIO_MODE_OUTPUT_HS_AF_PP);
  gpio_pin_mode(GPIOA,3,GPIO_MODE_INPUT);
  switch (clock_speed) {
    case 72:
      USART2->BRR = 0xea0;
      break;
    default:
      USART2->BRR = 0xea0;
      break;
  }
  USART2->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;
}

void uart2_send_char(char c) {
  USART2->DR=c;
  while(!(USART2->SR & USART_SR_TXE)) {};
  return;
}

char uart2_get_char() {
  char tmp;
  while(!(USART2->SR & (1<<5)));
  tmp = USART2->DR;
  return tmp;
}

void uart2_send_string(char *s) {
  while(*s != 0) {
    while(!(USART2->SR&USART_SR_TXE)) {};
    USART2->DR=*s++;
  }
  return;
}
