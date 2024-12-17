#include "iae_handlers.h"
#include "stdlib.h"

void iae_init() {
  __NMI_call = NULL;
  __HardFault_call = NULL;
  __MemManage_call = NULL;
  __BusFault_call = NULL;
  __UsageFault_call = NULL;
  __SVCall_call = NULL;
  __DebugMonitor_call = NULL;
  __PendSV_call = NULL;
  __SysTick_call = NULL;
  __WWDG_call = NULL;
  __PVD_call = NULL;
  __TAMPER_call = NULL;
  __RTC_call = NULL;
  __FLASH_call = NULL;
  __RCC_call = NULL;
  __EXTI0_call = NULL;
  __EXTI1_call = NULL;
  __EXTI2_call = NULL;
  __EXTI3_call = NULL;
  __EXTI4_call = NULL;
  __DMA1_Channel1_call = NULL;
  __DMA1_Channel2_call = NULL;
  __DMA1_Channel3_call = NULL;
  __DMA1_Channel4_call = NULL;
  __DMA1_Channel5_call = NULL;
  __DMA1_Channel6_call = NULL;
  __DMA1_Channel7_call = NULL;
  __ADC1_2_call = NULL;
  __CAN1_TX_call = NULL;
  __CAN1_RX0_call = NULL;
  __CAN1_RX1_call = NULL;
  __CAN1_SCE_call = NULL;
  __EXTI9_5_call = NULL;
  __TIM1_BRK_call = NULL;
  __TIM1_UP_call = NULL;
  __TIM1_TRG_COM_call = NULL;
  __TIM1_CC_call = NULL;
  __TIM2_call = NULL;
  __TIM3_call = NULL;
  __TIM4_call = NULL;
  __I2C1_EV_call = NULL;
  __I2C1_ER_call = NULL;
  __I2C2_EV_call = NULL;
  __I2C2_ER_call = NULL;
  __SPI1_call = NULL;
  __SPI2_call = NULL;
  __USART1_call = NULL;
  __USART2_call = NULL;
  __USART3_call = NULL;
  __EXTI15_10_call = NULL;
  __RTCAlarm_call = NULL;
  __OTG_FS_WKUP_call = NULL;
  __TIM5_call = NULL;
  __SPI3_call = NULL;
  __UART4_call = NULL;
  __UART5_call = NULL;
  __TIM6_call = NULL;
  __TIM7_call = NULL;
  __DMA2_Channel1_call = NULL;
  __DMA2_Channel2_call = NULL;
  __DMA2_Channel3_call = NULL;
  __DMA2_Channel4_call = NULL;
  __DMA2_Channel5_call = NULL;
  __ETH_call = NULL;
  __ETH_WKUP_call = NULL;
  __CAN2_TX_call = NULL;
  __CAN2_RX0_call = NULL;
  __CAN2_RX1_call = NULL;
  __CAN2_SCE_call = NULL;
  __OTG_FS_call = NULL;
}

void __NMI_set_handler(void *handler) {
  __NMI_call = handler;
  return;
}

void __HardFault_set_handler(void *handler) {
  __HardFault_call = handler;
  return;
}

void __MemManage_set_handler(void *handler) {
  __MemManage_call = handler;
  return;
}

void __BusFault_set_handler(void *handler) {
  __BusFault_call = handler;
  return;
}

void __UsageFault_set_handler(void *handler) {
  __UsageFault_call = handler;
  return;
}

void __SVCall_set_handler(void *handler) {
  __UsageFault_call = handler;
  return;
}

void __DebugMonitor_set_handler(void *handler) {
  __DebugMonitor_call = handler;
  return;
}

void __PendSV_set_handler(void *handler) {
  __PendSV_call = handler;
  return;
}

void __SysTick_set_handler(void *handler) {
  __SysTick_call = handler;
  return;
}

void __WWDG_set_handler(void *handler) {
  __WWDG_call = handler;
  return;
}

void __PVD_set_handler(void *handler) {
  __PVD_call = handler;
  return;
}

void __TAMPER_set_handler(void *handler) {
  __TAMPER_call = handler;
  return;
}

void __RTC_set_handler(void *handler) {
  __RTC_call = handler;
  return;
}

void __FLASH_set_handler(void *handler) {
  __FLASH_call = handler;
  return;
}

void __RCC_set_handler(void *handler) {
  __RCC_call = handler;
  return;
}

void __EXTI0_set_handler(void *handler) {
  __EXTI0_call = handler;
  return;
}

void __EXTI1_set_handler(void *handler) {
  __EXTI1_call = handler;
  return;
}

void __EXTI2_set_handler(void *handler) {
  __EXTI2_call = handler;
  return;
}

void __EXTI3_set_handler(void *handler) {
  __EXTI3_call = handler;
  return;
}

void __EXTI4_set_handler(void *handler) {
  __EXTI4_call = handler;
  return;
}

void __DMA1_Channel1_set_handler(void *handler) {
  __DMA1_Channel1_call = handler;
  return;
}

void __DMA1_Channel2_set_handler(void *handler) {
  __DMA1_Channel2_call = handler;
  return;
}

void __DMA1_Channel3_set_handler(void *handler) {
  __DMA1_Channel3_call = handler;
  return;
}

void __DMA1_Channel4_set_handler(void *handler) {
  __DMA1_Channel4_call = handler;
  return;
}

void __DMA1_Channel5_set_handler(void *handler) {
  __DMA1_Channel5_call = handler;
  return;
}

void __DMA1_Channel6_set_handler(void *handler) {
  __DMA1_Channel6_call = handler;
  return;
}

void __DMA1_Channel7_set_handler(void *handler) {
  __DMA1_Channel7_call = handler;
  return;
}

void __ADC1_2_set_handler(void *handler) {
  __ADC1_2_call = handler;
  return;
}

void __CAN1_TX_set_handler(void *handler) {
  __CAN1_TX_call = handler;
  return;
}

void __CAN1_RX0_set_handler(void *handler) {
  __CAN1_RX0_call = handler;
  return;
}

void __CAN1_RX1_set_handler(void *handler) {
  __CAN1_RX1_call = handler;
  return;
}

void __CAN1_SCE_set_handler(void *handler) {
  __CAN1_SCE_call = handler;
  return;
}

void __EXTI9_5_set_handler(void *handler) {
  __EXTI9_5_call = handler;
  return;
}

void __TIM1_BRK_set_handler(void *handler) {
  __TIM1_BRK_call = handler;
  return;
}

void __TIM1_UP_set_handler(void *handler) {
  __TIM1_UP_call = handler;
  return;
}

void __TIM1_TRG_COM_set_handler(void *handler) {
  __TIM1_TRG_COM_call = handler;
  return;
}

void __TIM1_CC_set_handler(void *handler) {
  __TIM1_CC_call = handler;
  return;
}

void __TIM2_set_handler(void *handler) {
  __TIM2_call = handler;
  return;
}

void __TIM3_set_handler(void *handler) {
  __TIM3_call = handler;
  return;
}

void __TIM4_set_handler(void *handler) {
  __TIM4_call = handler;
  return;
}

void __I2C1_EV_set_handler(void *handler) {
  __I2C1_EV_call = handler;
  return;
}

void __I2C1_ER_set_handler(void *handler) {
  __I2C1_ER_call = handler;
  return;
}

void __I2C2_EV_set_handler(void *handler) {
  __I2C2_EV_call = handler;
  return;
}

void __I2C2_ER_set_handler(void *handler) {
  __I2C2_ER_call = handler;
  return;
}

void __SPI1_set_handler(void *handler) {
  __SPI1_call = handler;
  return;
}

void __SPI2_set_handler(void *handler) {
  __SPI2_call = handler;
  return;
}

void __USART1_set_handler(void *handler) {
  __USART1_call = handler;
  return;
}

void __USART2_set_handler(void *handler) {
  __USART2_call = handler;
  return;
}

void __USART3_set_handler(void *handler) {
  __USART3_call = handler;
  return;
}

void __EXTI15_10_set_handler(void *handler) {
  __EXTI15_10_call = handler;
  return;
}

void __RTCAlarm_set_handler(void *handler) {
  __RTCAlarm_call = handler;
  return;
}

void __OTG_FS_WKUP_set_handler(void *handler) {
  __OTG_FS_WKUP_call = handler;
  return;
}

void __TIM5_set_handler(void *handler) {
  __TIM5_call = handler;
  return;
}

void __SPI3_set_handler(void *handler) {
  __SPI3_call = handler;
  return;
}

void __UART4_set_handler(void *handler) {
  __UART4_call = handler;
  return;
}

void __UART5_set_handler(void *handler) {
  __UART5_call = handler;
  return;
}

void __TIM6_set_handler(void *handler) {
  __TIM6_call = handler;
  return;
}

void __TIM7_set_handler(void *handler) {
  __TIM7_call = handler;
  return;
}

void __DMA2_Channel1_set_handler(void *handler) {
  __DMA2_Channel1_call = handler;
  return;
}

void __DMA2_Channel2_set_handler(void *handler) {
  __DMA2_Channel2_call = handler;
  return;
}

void __DMA2_Channel3_set_handler(void *handler) {
  __DMA2_Channel3_call = handler;
  return;
}

void __DMA2_Channel4_set_handler(void *handler) {
  __DMA2_Channel4_call = handler;
  return;
}

void __DMA2_Channel5_set_handler(void *handler) {
  __DMA2_Channel5_call = handler;
  return;
}

void __ETH_set_handler(void *handler) {
  __ETH_call = handler;
  return;
}

void __ETH_WKUP_set_handler(void *handler) {
  __ETH_WKUP_call = handler;
  return;
}

void __CAN2_TX_set_handler(void *handler) {
  __CAN2_TX_call = handler;
  return;
}

void __CAN2_RX0_set_handler(void *handler) {
  __CAN2_RX0_call = handler;
  return;
}

void __CAN2_RX1_set_handler(void *handler) {
  __CAN2_RX1_call = handler;
  return;
}

void __CAN2_SCE_set_handler(void *handler) {
  __CAN2_SCE_call = handler;
  return;
}

void __OTG_FS_set_handler(void *handler) {
  __OTG_FS_call = handler;
  return;
}

void __NMI_handler() {
  if(__NMI_call != NULL) __NMI_call();
  return;
}

void __HardFault_handler() {
  if(__HardFault_call != NULL) __HardFault_call();
  return;
}

void __MemManage_handler() {
  if(__MemManage_call != NULL) __MemManage_call();
  return;
}

void __BusFault_handler() {
  if(__BusFault_call != NULL) __BusFault_call();
  return;
}

void __UsageFault_handler() {
  if(__UsageFault_call != NULL) __UsageFault_call();
  return;
}

void __SVCall_handler() {
  if(__UsageFault_call != NULL) __UsageFault_call();
  return;
}

void __DebugMonitor_handler() {
  if(__DebugMonitor_call != NULL) __DebugMonitor_call();
  return;
}

void __PendSV_handler() {
  if(__PendSV_call != NULL) __PendSV_call();
  return;
}

void __SysTick_handler() {
  if(__SysTick_call != NULL) __SysTick_call();
  return;
}

void __WWDG_handler() {
  if(__WWDG_call != NULL) __WWDG_call();
  return;
}

void __PVD_handler() {
  if(__PVD_call != NULL) __PVD_call();
  return;
}

void __TAMPER_handler() {
  if(__TAMPER_call != NULL) __TAMPER_call();
  return;
}

void __RTC_handler() {
  if(__RTC_call != NULL) __RTC_call();
  return;
}

void __FLASH_handler() {
  if(__FLASH_call != NULL) __FLASH_call();
  return;
}

void __RCC_handler() {
  if(__RCC_call != NULL) __RCC_call();
  return;
}

void __EXTI0_handler() {
  if(__EXTI0_call != NULL) __EXTI0_call();
  return;
}

void __EXTI1_handler() {
  if(__EXTI1_call != NULL) __EXTI1_call();
  return;
}

void __EXTI2_handler() {
  if(__EXTI2_call != NULL) __EXTI2_call();
  return;
}

void __EXTI3_handler() {
  if(__EXTI3_call != NULL) __EXTI3_call();
  return;
}

void __EXTI4_handler() {
  if(__EXTI4_call != NULL) __EXTI4_call();
  return;
}

void __DMA1_Channel1_handler() {
  if(__DMA1_Channel1_call != NULL) __DMA1_Channel1_call();
  return;
}

void __DMA1_Channel2_handler() {
  if(__DMA1_Channel2_call != NULL) __DMA1_Channel2_call();
  return;
}

void __DMA1_Channel3_handler() {
  if(__DMA1_Channel3_call != NULL) __DMA1_Channel3_call();
  return;
}

void __DMA1_Channel4_handler() {
  if(__DMA1_Channel4_call != NULL) __DMA1_Channel4_call();
  return;
}

void __DMA1_Channel5_handler() {
  if(__DMA1_Channel5_call != NULL) __DMA1_Channel5_call();
  return;
}

void __DMA1_Channel6_handler() {
  if(__DMA1_Channel6_call != NULL) __DMA1_Channel6_call();
  return;
}

void __DMA1_Channel7_handler() {
  if(__DMA1_Channel7_call != NULL) __DMA1_Channel7_call();
  return;
}

void __ADC1_2_handler() {
  if(__ADC1_2_call != NULL) __ADC1_2_call();
  return;
}

void __CAN1_TX_handler() {
  if(__CAN1_TX_call != NULL) __CAN1_TX_call();
  return;
}

void __CAN1_RX0_handler() {
  if(__CAN1_RX0_call != NULL) __CAN1_RX0_call();
  return;
}

void __CAN1_RX1_handler() {
  if(__CAN1_RX1_call != NULL) __CAN1_RX1_call();
  return;
}

void __CAN1_SCE_handler() {
  if(__CAN1_SCE_call != NULL) __CAN1_SCE_call();
  return;
}

void __EXTI9_5_handler() {
  if(__EXTI9_5_call != NULL) __EXTI9_5_call();
  return;
}

void __TIM1_BRK_handler() {
  if(__TIM1_BRK_call != NULL) __TIM1_BRK_call();
  return;
}

void __TIM1_UP_handler() {
  if(__TIM1_UP_call != NULL) __TIM1_UP_call();
  return;
}

void __TIM1_TRG_COM_handler() {
  if(__TIM1_TRG_COM_call != NULL) __TIM1_TRG_COM_call();
  return;
}

void __TIM1_CC_handler() {
  if(__TIM1_CC_call != NULL) __TIM1_CC_call();
  return;
}

void __TIM2_handler() {
  if(__TIM2_call != NULL) __TIM2_call();
  return;
}

void __TIM3_handler() {
  if(__TIM3_call != NULL) __TIM3_call();
  return;
}

void __TIM4_handler() {
  if(__TIM4_call != NULL) __TIM4_call();
  return;
}

void __I2C1_EV_handler() {
  if(__I2C1_EV_call != NULL) __I2C1_EV_call();
  return;
}

void __I2C1_ER_handler() {
  if(__I2C1_ER_call != NULL) __I2C1_ER_call();
  return;
}

void __I2C2_EV_handler() {
  if(__I2C2_EV_call != NULL) __I2C2_EV_call();
  return;
}

void __I2C2_ER_handler() {
  if(__I2C2_ER_call != NULL) __I2C2_ER_call();
  return;
}

void __SPI1_handler() {
  if(__SPI1_call != NULL) __SPI1_call();
  return;
}

void __SPI2_handler() {
  if(__SPI2_call != NULL) __SPI2_call();
  return;
}

void __USART1_handler() {
  if(__USART1_call != NULL) __USART1_call();
  return;
}

void __USART2_handler() {
  if(__USART2_call != NULL) __USART2_call();
  return;
}

void __USART3_handler() {
  if(__USART3_call != NULL) __USART3_call();
  return;
}

void __EXTI15_10_handler() {
  if(__EXTI15_10_call != NULL) __EXTI15_10_call();
  return;
}

void __RTCAlarm_handler() {
  if(__RTCAlarm_call != NULL) __RTCAlarm_call();
  return;
}

void __OTG_FS_WKUP_handler() {
  if(__OTG_FS_WKUP_call != NULL) __OTG_FS_WKUP_call();
  return;
}

void __TIM5_handler() {
  if(__TIM5_call != NULL) __TIM5_call();
  return;
}

void __SPI3_handler() {
  if(__SPI3_call != NULL) __SPI3_call();
  return;
}

void __UART4_handler() {
  if(__UART4_call != NULL) __UART4_call();
  return;
}

void __UART5_handler() {
  if(__UART5_call != NULL) __UART5_call();
  return;
}

void __TIM6_handler() {
  if(__TIM6_call != NULL) __TIM6_call();
  return;
}

void __TIM7_handler() {
  if(__TIM7_call != NULL) __TIM7_call();
  return;
}

void __DMA2_Channel1_handler() {
  if(__DMA2_Channel1_call != NULL) __DMA2_Channel1_call();
  return;
}

void __DMA2_Channel2_handler() {
  if(__DMA2_Channel2_call != NULL) __DMA2_Channel2_call();
  return;
}

void __DMA2_Channel3_handler() {
  if(__DMA2_Channel3_call != NULL) __DMA2_Channel3_call();
  return;
}

void __DMA2_Channel4_handler() {
  if(__DMA2_Channel4_call != NULL) __DMA2_Channel4_call();
  return;
}

void __DMA2_Channel5_handler() {
  if(__DMA2_Channel5_call != NULL) __DMA2_Channel5_call();
  return;
}

void __ETH_handler() {
  if(__ETH_call != NULL) __ETH_call();
  return;
}

void __ETH_WKUP_handler() {
  if(__ETH_WKUP_call != NULL) __ETH_WKUP_call();
  return;
}

void __CAN2_TX_handler() {
  if(__CAN2_TX_call != NULL) __CAN2_TX_call();
  return;
}

void __CAN2_RX0_handler() {
  if(__CAN2_RX0_call != NULL) __CAN2_RX0_call();
  return;
}

void __CAN2_RX1_handler() {
  if(__CAN2_RX1_call != NULL) __CAN2_RX1_call();
  return;
}

void __CAN2_SCE_handler() {
  if(__CAN2_SCE_call != NULL) __CAN2_SCE_call();
  return;
}

void __OTG_FS_handler() {
  if(__OTG_FS_call != NULL) __OTG_FS_call();
  return;
}

