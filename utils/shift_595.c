// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "shift_595.h"

GPIO_TypeDef *gpio;
uint8_t DS,STCP,SHCP;

void mydelay(uint16_t t) {
  for(int c=0; c<=t; c++) { __NOP(); }
}

void shift_595_init(GPIO_TypeDef *_gpio, uint8_t _DS, uint8_t _SHCP, uint8_t _STCP) {
  gpio = _gpio;
  DS = _DS;
  STCP = _STCP;
  SHCP = _SHCP;
  gpio_pin_mode(gpio,DS,GPIO_MODE_OUTPUT);
  gpio_pin_mode(gpio,STCP,GPIO_MODE_OUTPUT);
  gpio_pin_mode(gpio,SHCP,GPIO_MODE_OUTPUT);
  gpio_pin_write(gpio,DS,LOW);
  gpio_pin_write(gpio,STCP,HIGH);
  gpio_pin_write(gpio,SHCP,LOW);
}

void shift_595_out(uint8_t val) {
  for(int c=8; c>=0; c--) {
    gpio_pin_write(gpio,DS,(val>>c)&1);
    gpio_pin_write(gpio,SHCP,HIGH);
    mydelay(65000); //__NOP();
    gpio_pin_write(gpio,SHCP,LOW);
    __NOP();
  }
  gpio_pin_write(gpio,STCP,LOW);
  __NOP();
  gpio_pin_write(gpio,STCP,HIGH);
}

void shift_595_out_no_latch(uint8_t val) {
  for(int c=8; c>=0; c--) {
    gpio_pin_write(gpio,DS,(val>>c)&1);
    gpio_pin_write(gpio,SHCP,HIGH);
    __NOP(); //mydelay(65000); //__NOP();
    gpio_pin_write(gpio,SHCP,LOW);
    __NOP();
  }
}

void shift_595_latch() {
  gpio_pin_write(gpio,STCP,LOW);
  __NOP();
  gpio_pin_write(gpio,STCP,HIGH);
}
