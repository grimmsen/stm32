// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "stdio.h"

void (*_putchar)(char c);

char *_sputc_dst;
void _sputc(char c) {
  *_sputc_dst++=c;
  return;
}

/* very simple printf
 * just supports decimal, hex and strings
 */
int _vprintf(char *format, va_list list) {
  char l_nibbles[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
  char u_nibbles[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
  char buf[128];
  unsigned int written;
  unsigned int fill_count;
  unsigned int digit;
  char fill_char='0';
  char *f = format;
  int lead=1;
  unsigned int u32_tmp;
  char *s;
  while(*f!=0) {
    written=0;
    fill_count=0;
    lead=1;
    if(*f=='%') {
      f++;
      switch(*f) {
        case '0':
          if((*(f+1)>='0')&(*(f+1)<='9')) { // leading zeros
            fill_count=*(++f)-'0'; // max 99
            if((*(f+1)>='0')&(*(f+1)<='9')) { // > 10?
              fill_count*=10;
              fill_count+=*(++f)-'0';
            }
	          fill_char='0';
          }
          f++;
        break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          fill_count=*(f++)-'0'; // max 99
          if((*f>='0')&(*f<='9')) { // > 10?
            fill_count*=10;
            fill_count+=*(f++)-'0';
          }
          fill_char=' ';
        break;
        default:
        break;
      }
      switch(*f) {
        case '%':
          _putchar('%');
          break;
        // decimal
        case 'd':
        case 'i':
        case 'u':
          u32_tmp = va_arg(list, int);
          if((*f=='d')|(*f=='i')) { // signed
            if(u32_tmp&0x80000000) {
              _putchar('-');
              u32_tmp=~u32_tmp+1;
            }
          }
          written=0;
          unsigned int done=0;
          int cur=1000000000;
          while(cur>=1) {
            digit=(unsigned int)(u32_tmp-done)/cur;
            done+=digit*cur;
            cur/=10;
            if((digit!=0)|(lead==0)) {
              lead=0;
              buf[written++]=l_nibbles[digit];
            }
          }
          break;
        // octal
        case 'o':
          u32_tmp = va_arg(list, unsigned int);
          // start at 30
          for(int c=30;c>=0;c-=3) {
            // mask every 3 bits and shift back
            digit=(u32_tmp>>c)&7;
            if((digit!=0)|(lead==0)) {
              lead=0;
              buf[written++]=l_nibbles[digit];
            }
          }
          break;
        // hexadecimal
        case 'x':
        case 'X':
        case 'p':
          u32_tmp = va_arg(list, int);
          for(int c=28;c>=0;c-=4) {
            digit=(u32_tmp & (0xf<<c))>>c; // mask and shift back
            if(digit!=0) {
              lead=0;
              if((*f=='x')|(*f=='p'))
                buf[written++]=l_nibbles[digit];
              else
                buf[written++]=u_nibbles[digit];
            } else {
              if(!lead)
                buf[written++]='0';
            }
          }
          break;
        // binary
        case 'b': // full 32bit
        case 'W': // Word
        case 'B': // Byte
          u32_tmp = va_arg(list,int);
          int width=32;
          if(*f=='W') {
            width=16;
            u32_tmp&=0x0000ffff; // mask 16 bit
          }
          if(*f=='B') {
            width=8;
            u32_tmp&=0x000000ff; // mask 8 bit
          }
          for(int c=width; c>0; c--) {
            digit=(u32_tmp>>(c-1))&1;
            buf[written++]=l_nibbles[digit];
          }
          break;
        // a string
        case 's':
          s = va_arg(list,char*);
          while(*s!=0) {
            _putchar(*s++);
          }
          break;
        case 'c':
          u32_tmp=va_arg(list,int);
          if((u32_tmp>=32)&(u32_tmp<127))
            _putchar(u32_tmp);
          else
            _putchar('.');
          break;
        // not supported
        default:
          _putchar('%');
          _putchar(*f);
          break;
      }
      if(written>0) { // flush buffer if it contains something
        // fill leading character as requested
        if(written<fill_count) {
          for(unsigned int c=0;c<(fill_count-written);c++) {
            _putchar(fill_char);
          }
        }
        for(int c=0;c<written;c++) {
          _putchar(buf[c]);
        }
      } else {
        if(fill_count==0) _putchar(fill_char);
        for(unsigned int c=0;c<(fill_count);c++) {
          _putchar(fill_char);
        }
      }
    } else {
      // no format expression, regular data
      _putchar(*f);
    }
    f++;
  }
  return 0;
}

int _printf(char *format, ...) {
  va_list list;
  va_start(list,format);
  _vprintf(format, list);
  return 0;
}

int _sprintf(char *dst, char *format, ...) {
  va_list list;
  va_start(list,format);
  void (*_putchar_bak)(char c)=_putchar;
  _sputc_dst = dst;
  _putchar=_sputc;
  _vprintf(format, list);
  _putchar = _putchar_bak;
  return 0;
}
