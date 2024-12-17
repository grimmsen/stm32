#include "timer.h"

void timer_init(uint8_t num, uint32_t speed) {
  return;
} 

void timer_tim1_set_handler(void *handler) {
  __tim1_call = handler;
  return;
}

void __timer_tim1_handler() {
  if(__tim1_call!=NULL) __tim1_call();
  return;
}

void timer_tim2_set_handler(void *handler) {
  __tim2_call = handler;
  return;
}

void __timer_tim2_handler() {
  if(__tim2_call!=NULL) __tim2_call();
  return;
}

void timer_tim3_set_handler(void *handler) {
  __tim3_call = handler;
  return;
}

void __timer_tim3_handler() {
  if(__tim3_call!=NULL) __tim3_call();
  return;
}

void timer_tim4_set_handler(void *handler) {
  __tim4_call = handler;
  return;
}

void __timer_tim4_handler() {
  if(__tim4_call!=NULL) __tim4_call();
  return;
}

void timer_tim5_set_handler(void *handler) {
  __tim5_call = handler;
  return;
}

void __timer_tim5_handler() {
  if(__tim5_call!=NULL) __tim5_call();
  return;
}

void timer_tim6_set_handler(void *handler) {
  __tim6_call = handler;
  return;
}

void __timer_tim6_handler() {
  if(__tim6_call!=NULL) __tim6_call();
  return;
}

void timer_tim7_set_handler(void *handler) {
  __tim7_call = handler;
  return;
}

void __timer_tim7_handler() {
  if(__tim7_call!=NULL) __tim7_call();
  return;
}

void timer_tim8_set_handler(void *handler) {
  __tim8_call = handler;
  return;
}

void __timer_tim8_handler() {
  if(__tim8_call!=NULL) __tim8_call();
  return;
}

