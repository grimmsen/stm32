// https://controllerstech.com/how-to-setup-uart-using-registers-in-stm32/
#include <stdint.h>
#include <stm32f10x.h>
#include "std/stdio.h"
#include "utils/clock.h"
#include "utils/gpio.h"
#include "utils/uart.h"
#include "utils/extint.h"
#include "utils/shift_595.h"

// delay loop for 8 MHz CPU clock with optimizer enabled
void delay(uint32_t msec)
{
    for (uint32_t j=0; j < 1000UL * msec; j++)
    {
        __NOP();
    }
}

void init_TIM1() {
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
  NVIC_SetPriority(TIM2_IRQn,0x03);
  NVIC_EnableIRQ(TIM2_IRQn);
  RCC->APB1RSTR|=RCC_APB1RSTR_TIM2RST;
  RCC->APB1RSTR&=~RCC_APB1RSTR_TIM2RST;
  TIM2->PSC=0xfff;
  TIM2->ARR=500;
  TIM2->EGR|=TIM_EGR_UG;
  TIM2->DIER|=TIM_DIER_UIE;
  TIM2->CR1=TIM_CR1_CEN;
}

int onoff, onoff2;
uint8_t count=0;
extern void (*_putchar)(char c);

void test() {
  if(onoff2==0) {
    gpio_pin_write(GPIOA,0,LOW);
    onoff2 = 1;
  } else {
    gpio_pin_write(GPIOA,0,HIGH);
    onoff2 = 0;
  }
  return;
}

int main(void)
{
  onoff=0;
  onoff2=0;
    clock_set_speed(72);
    gpio_init_all();
    init_TIM1();
    for(int i=13; i<=15; i++) {
      gpio_pin_mode(GPIOC,i,GPIO_MODE_INPUT_PULLUP);
    }
    gpio_pin_mode(GPIOA,0,GPIO_MODE_OUTPUT);
    extint_ext0_set_handler(&test);
    uart2_init();
    _putchar=uart2_send_char;
    while(1) {
        _printf("GPIOC: %b 0x%08x\r\n",GPIOC->IDR,GPIOC->IDR);
        _printf("test: %d %o\r\n",-3123411,0b111000110100);
        delay(4000);
    }
}

void T1Irr() {
  __disable_irq();
  count++;
  if(onoff==0) {
    gpio_pin_write(GPIOC,13,HIGH);
    onoff=1;
  } else {
    gpio_pin_write(GPIOC,13,LOW);
    onoff=0;
  }
  TIM2->SR&=~TIM_SR_UIF;
  __enable_irq();
  return;
}
