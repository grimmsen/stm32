#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdint.h>
#include <stdarg.h>

void _sputc(char c);
int _printf(char *format, ...);
int _sprintf(char *dst, char *format, ...);
int _vprintf(char *format, va_list list);

#endif
