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

/**
 * dcf77_init - initializes the pins and interrupts
 * @gpio: on which data pin is on
 * @pin: the actual pin number, the receiver is connected to
 * @interrupt: which EXTI interrupt to use
 * */
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
    extint_init(EXTI_GPIOA,pin,interrupt);
  } else if(gpio==GPIOB) {
    extint_init(EXTI_GPIOB,pin,interrupt);
  } else if(gpio==GPIOC) {
    extint_init(EXTI_GPIOC,pin,interrupt);
  } else {
    return;
  }
  // trigger on both edges
  extint_add_edge(interrupt,EXTI_RISING_EDGE);
  extint_add_edge(interrupt,EXTI_FALLING_EDGE);
  // set handler
  switch(interrupt) {
    case 0:
      __EXTI0_set_handler(&dcf77_handler);
      break;
    case 1:
      __EXTI1_set_handler(&dcf77_handler);
      break;
    case 2:
      __EXTI2_set_handler(&dcf77_handler);
      break;
    case 3:
      __EXTI3_set_handler(&dcf77_handler);
      break;
    case 4:
      __EXTI4_set_handler(&dcf77_handler);
      break;
    default:
      break;
    }
}

/**
 * dcf77_handler - the interrupt handler for handling the signals
 *
 *  - this function decodes the bit stream provided by the receiver, which
 *    is the data transmitted by DCF77
 *  - it detects the start bit to sync, and distinguishes short and long pulses (0 and 1)
 *  - the 59 bits are shifted into two variables, which can are then ready be decoded
 *  - it handles garbled data and resyncing to the sender after a failure
 */
void dcf77_handler() {
  if(gpio_pin_read(dcf77_gpio,dcf77_pin)==LOW) {
    // falling edge
    _d_next=TIM2->CNT-_d_start;
    TIM2->CNT=0;
    _d_start=TIM2->CNT;
  } else {
    // rising edge
    _d_end=TIM2->CNT;
    _d_sec=_d_next/4;
    _d_dur=(_d_end-_d_start)/4;
    // add some guard time left end right
    // times are very graceful, found experimental
    if((_d_sec>=930)&(_d_sec<=1070)&_insync) { // we are in sync, normal bit
      if((_d_dur>=89)&(_d_dur<=189)) { // short pulse -> 0
        if(_bit_count<32) {
          _bit0_31&=~(1<<_bit_count);
        } else {
          _bit32_58&=~(1<<(_bit_count-32));
          _printf("0 pos = %u\r\n",_bit_count-32);
        }
         _bit_count++;
      } else if((_d_dur>=200)&(_d_dur<=270)) { // long pulse -> 1
        if(_bit_count<32) {
          _bit0_31|=1<<_bit_count;
        } else {
          _printf("1 pos = %u\r\n",_bit_count-32);
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
      // this is garbled data, omit
      __NOP();
    } else {
      // we are not in sync
      _insync=0;
    }
  }
  extint_clear_interrupt(dcf77_interrupt);
  return;
}

struct dcf77_time dcf77_get_time() {
  struct dcf77_time time = {
    /**
     * data is encoded in BCD at very inconvenient places
     * mask bits and shift them to the right place
     *
     * the masks are formed this according to the data format
     *
     * _bit32_58:
     *                 5           4         3
     *       876 5432 1098 7654 3210 9876 5432 - DCF77 bit num
     * 1098 7654 3210 9876 5432 1098 7654 3210 - _bit32_58 bitnum -> shift value
     * 1111 1100 1000 1110 0000 0100 1001 0100
     * -----------------------------------------------------------------------------
     * 0000 0000 0000 0000 0000 0000 0000 000x - mask hour bcd 1 bit 4    0x00000001
     * 0000 0000 0000 0000 0000 0000 0000 Pxx0 - mask hour bcd 10         0x00000006
     * 0000 0000 0000 0000 0000 0000 xxxx 0000 - mask day of month bcd 1  0x000000f0
     * 0000 0000 0000 0000 0000 00xx 0000 0000 - mask day of month bcd 10 0x00000300
     * 0000 0000 0000 0000 000x xx00 0000 0000 - mask day of week bcd 1   0x00001c00
     * 0000 0000 0000 000x xxx0 0000 0000 0000 - mask month bcd 1         0x0001e000
     * 0000 0000 0000 00x0 0000 0000 0000 0000 - mask month bcd 10        0x00020000
     * 0000 0000 00xx xx00 0000 0000 0000 0000 - mask year bcd 1          0x003c0000
     * 0000 00xx xx00 0000 0000 0000 0000 0000 - mask year bcd 10         0x03c00000
     *        || |||| |||| |||| |||| |||| |||L hour BCD 1 bit 4
     *        || |||| |||| |||| |||| |||| |LL_ hour BCD 10
     *        || |||| |||| |||| |||| LLLL_____ day BCD 1
     *        || |||| |||| |||| ||LL__________ day BCD 10
     *        || |||| |||| |||L_LL____________ day of week BCD 1
     *        || |||| |||L_LLL________________ month BCD 1
     *        || |||| ||L_____________________ month BCD 10
     *        || ||LL_LL______________________ year BCD 1
     *        LL_LL___________________________ year BCD 10
     */
    (uint8_t)((_bit0_31&0xe0000000)>>29)+((_bit32_58&0x00000001)<<3)+((_bit32_58&0x00000006)>>1)*10, // hour
    (uint8_t)((_bit0_31&0x01f00000)>>21)+((_bit0_31&0x0e000000)>>25)*10,                             // minute
    0,                                                                           // second
    (uint8_t)((_bit32_58&0x000000f0)>>4)+(((_bit32_58&0x00000300)>>8)*10),                           // day of month
    (uint8_t)((_bit32_58&0x00001c00)>>11),                                                           // day of week
    (uint8_t)((_bit32_58&0x0001e000)>>13)+(((_bit32_58&0x0002000)>>17)*10),                          // month
    (uint8_t)((_bit32_58&0x003c0000)>>18)+(((_bit32_58&0x03c00000)>>22)*10)                          // year
  };
  return time;
}
