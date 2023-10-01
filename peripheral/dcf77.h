#ifndef __DCF77_H__
#define __DCF77_H__
#include <stdint.h>
#include <stm32f10x.h>
#include "../utils/extint.h"
#include "../utils/gpio.h"
#include "../std/stdio.h"

struct dcf77_time {
  uint8_t hour;
  uint8_t minute;
  uint8_t seconds;
};

//todo: timing with other frequencies
// occupies timer TIM2 ant EXTI0
void dcf77_init(GPIO_TypeDef *gpio, uint8_t pin, uint8_t interrupt);
void dcf77_handler();
struct dcf77_time dcf77_get_time();

#endif
