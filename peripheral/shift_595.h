#ifndef __595_SHIFT_H__
#define __595_SHIFT_H__
#include <stm32f10x.h>
#include <stdint.h>
#include "../utils/gpio.h"

void shift_595_init(GPIO_TypeDef *_gpio,uint8_t _DS, uint8_t _SHCP, uint8_t _STCP);
void shift_595_out(uint8_t val);
void shift_595_out_no_latch(uint8_t val);
void shift_595_latch();

#endif
