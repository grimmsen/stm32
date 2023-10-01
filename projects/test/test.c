#include <stdint.h>
#include <stm32f10x.h>
#include "utils/clock.h"
#include "utils/gpio.h"

int main(void) {
  clock_set_speed(72);
  gpio_init_all();
  // delete everything after this line and start
  int onoff=0;
  gpio_pin_mode(GPIOC,13,GPIO_MODE_OUTPUT);
  while(1) {
    for (uint32_t j=0; j < 1000000UL; j++) { __NOP(); }
    if(onoff==0) {
      gpio_pin_write(GPIOC,13,LOW);
      onoff=1;
    } else {
      gpio_pin_write(GPIOC,13,HIGH);
      onoff=0;
    }
  }
}

