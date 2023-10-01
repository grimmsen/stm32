#ifndef __GPIO_H__
#define __GPIO_H__
#include <stm32f10x.h>
#include <stdint.h>

#define GPIO_MODE_INPUT_ANALOG     0x0  // 00 00 analog input
#define GPIO_MODE_INPUT_FLOATING   0x4  // 01 00 floating input
#define GPIO_MODE_INPUT_PULLUP     0xf8 // 10 00 input with pullup / pulldown
#define GPIO_MODE_INPUT_PULLDOWN   0x8  // 10 00 input with pullup / pulldown
#define GPIO_MODE_OUTPUT_MS_GP_PP  0x1  // 00 01 medium speed general purpose output push pull
#define GPIO_MODE_OUTPUT_LS_GP_PP  0x2  // 00 10 low speed general purpose output push pull
#define GPIO_MODE_OUTPUT_HS_GP_PP  0x3  // 00 10 highspeed general purpose output push pull
#define GPIO_MODE_OUTPUT_MS_GP_OD  0x5  // 01 01 medium speed general purpose output open drain
#define GPIO_MODE_OUTPUT_LS_GP_OD  0x6  // 01 10 low speed general purpose output open drain
#define GPIO_MODE_OUTPUT_HS_GP_OD  0x7  // 01 11 high speed general purpose output open drain
#define GPIO_MODE_OUTPUT_MS_AF_PP  0x9  // 10 01 medium speed alternate function output push pull
#define GPIO_MODE_OUTPUT_LS_AF_PP  0xa  // 10 10 low speed alternate function output push pull
#define GPIO_MODE_OUTPUT_HS_AF_PP  0xb  // 10 11 high speed alternate function output push pull
#define GPIO_MODE_OUTPUT_MS_AF_OD  0xd  // 11 01 medium speed alternate function output open drain
#define GPIO_MODE_OUTPUT_LS_AF_OD  0xe  // 11 10 low speed alternate function output open drain
#define GPIO_MODE_OUTPUT_HS_AF_OD  0xf  // 11 11 high speed alternate function output open drain

#define GPIO_MODE_INPUT  0x4 // quick select general purpose
#define GPIO_MODE_OUTPUT 0x1 // quick select general purpose

#define LOW 0
#define HIGH 1

void systick_enable(uint8_t slow);
void gpio_init_all();
void gpio_pin_mode(GPIO_TypeDef *gpio, uint8_t pin, uint8_t mode);
void gpio_pin_write(GPIO_TypeDef *gpio, uint8_t pin, uint8_t val);
uint8_t gpio_pin_read(GPIO_TypeDef *gpio, uint8_t pin);

#endif
