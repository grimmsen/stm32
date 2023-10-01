#ifndef __EXTINT_H__
#define __EXTINT_H__
#include <stdint.h>
#include <stdlib.h>
#include <stm32f10x.h>

#define EXTI_RISING_EDGE 0
#define EXTI_FALLING_EDGE 1
#define EXTI_GPIOA 0
#define EXTI_GPIOB 1
#define EXTI_GPIOC 2

void extint_init(uint8_t gpio, uint8_t num, uint8_t pin, uint8_t edge);
void extint_add_edge(uint8_t num, uint8_t edge);
void extint_clear_interrupt(uint8_t num);
void extint_ext0_set_handler(void *handler);
void extint_ext1_set_handler(void *handler);
void extint_ext2_set_handler(void *handler);
void extint_ext3_set_handler(void *handler);
void extint_ext4_set_handler(void *handler);
void __extint_ext0_handler();
void __extint_ext1_handler();
void __extint_ext2_handler();
void __extint_ext3_handler();
void __extint_ext4_handler();

#endif
