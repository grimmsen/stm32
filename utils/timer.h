#ifndef __TIMER_H__
#define __TIMER_H__
#include <stdint.h>
#include <stdlib.h>

void (*__tim1_call)();
void (*__tim2_call)();
void (*__tim3_call)();
void (*__tim4_call)();
void (*__tim5_call)();
void (*__tim6_call)();
void (*__tim7_call)();
void (*__tim8_call)();

void timer_enable(uint8_t num);
void timer_init(uint8_t num, uint32_t freq);

void timer_tim1_set_handler(void *handler);
void __timer_tim1_handler();
void timer_tim2_set_handler(void *handler);
void __timer_tim2_handler();
void timer_tim3_set_handler(void *handler);
void __timer_tim3_handler();
void timer_tim4_set_handler(void *handler);
void __timer_tim4_handler();
void timer_tim5_set_handler(void *handler);
void __timer_tim5_handler();
void timer_tim6_set_handler(void *handler);
void __timer_tim6_handler();
void timer_tim7_set_handler(void *handler);
void __timer_tim7_handler();
void timer_tim8_set_handler(void *handler);
void __timer_tim8_handler();

#endif
