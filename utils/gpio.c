// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "gpio.h"

/**
 * systick_enable - enables the systick counter
 *
 */
void systick_enable(uint8_t slow) {
  SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
  if(slow) {
    SysTick->CTRL|=SysTick_CTRL_CLKSOURCE_Msk;
  }
}

/**
 * gpio_init_all - enables all ports on the microcontroller
 *
 */
void gpio_init_all(void) {
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
  return;
}

/**
 * gpio_pin_mode - sets pin mode (input, output) and general or alternative mode
 * @gpio: CMSIS gpio handle
 * @mode: the mode to set, see .h-file
 *
 */
void gpio_pin_mode(GPIO_TypeDef *gpio, uint8_t pin, uint8_t mode) {
  // set ODR if input pull up
  if(mode == GPIO_MODE_INPUT_PULLUP) {
    mode = mode & 0xf;
  }
  // choose high or low register
  if(pin<=7) {
    gpio->CRL&=~(0xf<<(4*pin));
    gpio->CRL|=mode<<(4*pin);
  } else {
    gpio->CRH&=~(0xf<<(4*(pin-8)));
    gpio->CRH|=mode<<(4*(pin-8));
  }
  if(mode == GPIO_MODE_INPUT_PULLUP) {
    gpio->ODR|=(1<<pin);
  }
  return;
}

/**
 * gpio_pin_write - writes high or low to the specified pin
 * @gpio: CMSIS gpio handle
 * @pin: the pin to set on given port
 * @val: the value to set (HIGH or LOW)
 *
 */
void gpio_pin_write(GPIO_TypeDef *gpio, uint8_t pin, uint8_t val) {
  gpio->ODR=(gpio->ODR&(~(1<<pin)))|((val&1)<<pin);
  return;
}

/**
 * gpio_pin_read - reads the digital status of the specified pin
 * @gpio: CMSIS gpio handle
 * @pin: the pin to read from
 *
 */
uint8_t gpio_pin_read(GPIO_TypeDef *gpio, uint8_t pin) {
  return ((gpio->IDR&(1<<pin))==0);
}
