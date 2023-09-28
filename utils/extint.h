#ifndef __EXTINT_H__
#define __EXTINT_H__
#include <stdint.h>
#include <stdlib.h>
#include <stm32f10x.h>

void init_extint(uint8_t num);
void extint_ext0_set_handler(void *handler);
void __extint_ext0_handler();
void extint_ext1_handler();
void extint_ext2_handler();
void extint_ext3_handler();
void extint_ext4_handler();

#endif
