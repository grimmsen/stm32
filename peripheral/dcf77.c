#include "dcf77.h"

GPIO_TypeDef *dcf77_gpio;
uint8_t dcf77_pin;
uint8_t dcf77_interrupt;

uint16_t _d_start;
uint16_t _d_end;
uint16_t _d_dur;
uint16_t _d_sec;
uint16_t _d_next;
uint8_t _bit_count;
uint8_t _insync;
uint8_t _hour;
uint8_t _minutes;
uint32_t _bit0_31;
uint32_t _bit32_58;

void dcf77_init(GPIO_TypeDef *gpio, uint8_t pin, uint8_t interrupt) {
  _d_start=0;
  _d_end=0;
  dcf77_gpio = gpio;
  dcf77_pin = pin;
  dcf77_interrupt = interrupt;
  // init the timer for measuring
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
  // set desired pin to input mode
  gpio_pin_mode(gpio,pin,GPIO_MODE_INPUT);
  // init external interrupt
  if(gpio==GPIOA) {
    extint_init(EXTI_GPIOA,pin,interrupt,EXTI_RISING_EDGE);
  } else if(gpio==GPIOB) {
    extint_init(EXTI_GPIOB,pin,interrupt,EXTI_RISING_EDGE);
  } else if(gpio==GPIOC) {
    extint_init(EXTI_GPIOC,pin,interrupt,EXTI_RISING_EDGE);
  } else {
    return;
  }
  // trigger on both edges
  extint_add_edge(interrupt,EXTI_RISING_EDGE);
  extint_add_edge(interrupt,EXTI_FALLING_EDGE);
  // set handler
  switch(interrupt) {
    case 0:
      extint_ext0_set_handler(&dcf77_handler);
      break;
    case 1:
      extint_ext1_set_handler(&dcf77_handler);
      break;
    case 2:
      extint_ext2_set_handler(&dcf77_handler);
      break;
    case 3:
      extint_ext3_set_handler(&dcf77_handler);
      break;
    case 4:
      extint_ext4_set_handler(&dcf77_handler);
      break;
    default:
      break;
    }
}

/**
 * dcf77_handler - the interrupt handler for handling the signals
 *
 *  - this function actually decodes the bit stream provided by the receiver, which
 *    is the data transmitted by DCF77
 *  - it detects the start bit to sync, and distiguishes short and long pulses (0 and 1)
 *  - the 59 bits are shifted into two variables, which can then be decoded
 *  - it handles garbled data and resyncing after a failure
 */
void dcf77_handler() {
  if(gpio_pin_read(dcf77_gpio,dcf77_pin)==LOW) {
    _d_next=TIM2->CNT-_d_start;
    TIM2->CNT=0;
    _d_start=TIM2->CNT;
  } else {
    _d_end=TIM2->CNT;
    _d_sec=_d_next/4;
    _d_dur=(_d_end-_d_start)/4;
    // adding some guard time left end right
    // times are very graceful
    if((_d_sec>=930)&(_d_sec<=1070)&_insync) { // we are in sync, normal bit
      if((_d_dur>=89)&(_d_dur<=189)) { // short pulse -> 0
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
      _insync=1;
      _bit_count=1;
    } else if (_d_sec<800) {
      __NOP();
    } else {
      // we are not in sync
      _insync=0;
    }
    _printf("%u %u %04x %04x\r\n",_insync,_d_dur,_bit0_31,_bit32_58);
  }
  extint_clear_interrupt(0);
  return;
}

struct dcf77_time dcf77_get_time() {
  struct dcf77_time time = {
    (uint8_t)((_bit0_31&0xe0000000)>>29)+((_bit32_58&0x00000001)<<3)+((_bit32_58&0x00000006)>>1)*10,
    (uint8_t)((_bit0_31&0x01f00000)>>21)+((_bit0_31&0x0e000000)>>25)*10,
    (uint8_t)(_bit_count)
  };
  return time;
}
