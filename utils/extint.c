// Copyright (C) 2023 by grimmsen
// Licence: GPL
#include "extint.h"

void (*__ext0_call)();

void init_extint(uint8_t num) {
  __ext0_call = NULL;
  return;
}

void extint_ext0_set_handler(void *handler) {
  __ext0_call = handler;
  return;
}

void __extint_ext0_handler() {
  if(__ext0_call!=NULL) __ext0_call();
  return;
}
