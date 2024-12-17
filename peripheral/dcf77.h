#ifndef __DCF77_H__
#define __DCF77_H__
#include <stdint.h>
#include <stm32f10x.h>
#include "../utils/iae_handlers.h"
#include "../utils/extint.h"
#include "../utils/gpio.h"
#include "../std/stdio.h"
#include "../std/time.h"

//todo: timing with other frequencies
// occupies timer TIM2
void dcf77_init(GPIO_TypeDef *gpio, uint8_t pin, uint8_t interrupt);
void dcf77_handler();
uint32_t dcf77_get_time();

#endif
