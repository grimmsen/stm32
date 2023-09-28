#ifndef __UART_H__
#define __UART_H__
#include <stm32f10x.h>
#include <stdint.h>
#include "gpio.h"

void uart2_init();
void uart2_send_char(char c);
char uart2_get_char();
void uart2_send_string(char *s);

#endif
