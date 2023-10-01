// https://controllerstech.com/how-to-setup-uart-using-registers-in-stm32/
#include <stdint.h>
#include <stm32f10x.h>
#include "std/stdio.h"
#include "utils/clock.h"
#include "utils/gpio.h"
#include "utils/uart.h"
#include "utils/extint.h"
#include "peripheral/shift_595.h"
#include "peripheral/dcf77.h"

// delay loop for 8 MHz CPU clock with optimizer enabled
void delay(uint32_t msec)
{
for (uint32_t j=0; j < 1000UL * msec; j++)
{
    __NOP();
}
}

/*void init_TIM1() {
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
  //NVIC_SetPriority(TIM2_IRQn,0x03);
  //NVIC_EnableIRQ(TIM2_IRQn);
  RCC->APB1RSTR|=RCC_APB1RSTR_TIM2RST;
  RCC->APB1RSTR&=~RCC_APB1RSTR_TIM2RST;
  TIM2->PSC=36000000/2000; // max speed 1000 ms
  TIM2->ARR=65535;
  TIM2->EGR|=TIM_EGR_UG;
  TIM2->DIER|=TIM_DIER_UIE;
  TIM2->CR1=TIM_CR1_CEN;
}

uint16_t _d_start;
uint16_t _d_end;
uint16_t _d_dur;
uint16_t _d_sec;
uint16_t _d_next;
uint8_t _bit_count;
uint8_t _insync;
uint8_t _needssync;

uint8_t _hour;
uint8_t _minutes;

uint32_t _bit0_31;
uint32_t _bit32_58;

void handleEXT0() {
  if(gpio_pin_read(GPIOA,0)==LOW) {
    _d_next=TIM2->CNT-_d_start;
    TIM2->CNT=0;
    _d_start=TIM2->CNT;
  } else {
    _d_end=TIM2->CNT;
    _d_sec=_d_next/4;
    _d_dur=(_d_end-_d_start)/4;
    // adding some guard time left end right
    if((_d_sec>=930)&(_d_sec<=1070)&_insync) { // we are in sync, normal bit
      if((_d_dur>=100)&(_d_dur<=189)) { // short pulse -> 0
        if(_bit_count<32) {
          _bit0_31&=~(1<<_bit_count);
        } else {
          _bit32_58&=~(1<<(_bit_count-32));
        }
         _bit_count++;
      } else if((_d_dur>=200)&(_d_dur<=270)) { // long pulse -> 1
        if(_bit_count<32) {
          _bit0_31|=1<<_bit_count;
        } else {
          _bit32_58|=1<<(_bit_count-32);
        }
        _bit_count++;
      } else {
        // lost sync
        _bit_count=1;
        _insync=0;
      }
    } else if (((_d_sec>=1950)&(_d_sec<=2050))) {
      _minutes=0;
      _hour=0;
      _insync=1;
      _bit_count=1;
    } else if (_d_sec<800) {
      __NOP();
    } else {
      // we are not in sync
      _insync=0;
    }
    _printf("%u %u %04x %04x\r\n",_insync,(_d_end-_d_start),_bit0_31,_bit32_58);
  }
  extint_clear_interrupt(0);
  return;
}
*/
int onoff, onoff2;
uint8_t count=0;
extern void (*_putchar)(char c);



void test() {
  if(onoff2==0) {
    gpio_pin_write(GPIOA,0,LOW);
    onoff2 = 1;
  } else {
    gpio_pin_write(GPIOA,0,HIGH);
    onoff2 = 0;
  }
  return;
}

int main(void)
{
  //_insync=0;
  //_needssync=1;
  onoff=0;
  onoff2=0;
    clock_set_speed(72);
    gpio_init_all();
    systick_enable(1);
    //init_TIM1();
    for(int i=13; i<=15; i++) {
      gpio_pin_mode(GPIOC,i,GPIO_MODE_INPUT_PULLUP);
    }
    uart2_init();
    _putchar=uart2_send_char;
    dcf77_init(GPIOA,0,0);
 //   gpio_pin_mode(GPIOA,0,GPIO_MODE_INPUT_PULLUP);
 //   extint_init(EXTI_GPIOA,0,0,EXTI_RISING_EDGE);
 //   extint_add_edge(0,EXTI_RISING_EDGE);
 //   extint_add_edge(0,EXTI_FALLING_EDGE);
 //   extint_ext0_set_handler(&handleEXT0);
    while(1) {
      //test();
      struct dcf77_time mytime = dcf77_get_time();
      _printf("\r\nlast decoded time = %u:%u:%u\r\n\r\n",mytime.hour,mytime.minute);
      // decode time
      //uint8_t mins = ((_bit0_31&0x01f00000)>>21)+((_bit0_31&0x0e000000)>>25)*10;
      //uint8_t hours = ((_bit0_31&0xe0000000)>>29)+((_bit32_58&0x00000001)<<3)+((_bit32_58&0x00000006)>>1)*10;
      //_printf("\n\n\rdecoded Time: %01u:%01u:%01u\n\n\r",hours,mins,_bit_count);

        //_printf("GPIOA: %b 0x%08x\r\n",GPIOA->IDR,GPIOA->IDR);
        //_printf("test: %d %o\r\n",-3123411,0b111000110100);
        delay(0x3fff);
    }
}

void T1Irr() {
  __disable_irq();
  count++;
  if(onoff==0) {
    gpio_pin_write(GPIOC,13,HIGH);
    onoff=1;
  } else {
    gpio_pin_write(GPIOC,13,LOW);
    onoff=0;
  }
  TIM2->SR&=~TIM_SR_UIF;
  __enable_irq();
  return;
}
