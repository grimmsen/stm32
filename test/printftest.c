#include "../std/stdio.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

extern void (* _putchar)(char c);

void __putchar(char c) {
  putchar(c);
}

void main() {
  char *test = malloc(1024);
  _sprintf(test,"Hallo HAllo %d %b\n",1024,1023);
  _putchar = __putchar;
  //_printf("%s",test);
  _printf("0x%08X\n",0xff00012);
  _printf("0x%x %o %d\n",254,0b111000101101,-1234123);
  _printf("%09u %c 0x%010x %B 20%% %s\n",-65103,'c',0xf38,0xe0ff83,test);
  //_printf("%d %d %d\n",65535,132,0x10000);
  //_printf("Hallo %s: cpu = %d\n","asdasd",1231);
  return;
}
