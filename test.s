	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"test.c"
	.text
	.comm	__NMI_call,4,4
	.comm	__HardFault_call,4,4
	.comm	__MemManage_call,4,4
	.comm	__BusFault_call,4,4
	.comm	__UsageFault_call,4,4
	.comm	__SVCall_call,4,4
	.comm	__DebugMonitor_call,4,4
	.comm	__PendSV_call,4,4
	.comm	__SysTick_call,4,4
	.comm	__WWDG_call,4,4
	.comm	__PVD_call,4,4
	.comm	__TAMPER_call,4,4
	.comm	__RTC_call,4,4
	.comm	__FLASH_call,4,4
	.comm	__RCC_call,4,4
	.comm	__EXTI0_call,4,4
	.comm	__EXTI1_call,4,4
	.comm	__EXTI2_call,4,4
	.comm	__EXTI3_call,4,4
	.comm	__EXTI4_call,4,4
	.comm	__DMA1_Channel1_call,4,4
	.comm	__DMA1_Channel2_call,4,4
	.comm	__DMA1_Channel3_call,4,4
	.comm	__DMA1_Channel4_call,4,4
	.comm	__DMA1_Channel5_call,4,4
	.comm	__DMA1_Channel6_call,4,4
	.comm	__DMA1_Channel7_call,4,4
	.comm	__ADC1_2_call,4,4
	.comm	__CAN1_TX_call,4,4
	.comm	__CAN1_RX0_call,4,4
	.comm	__CAN1_RX1_call,4,4
	.comm	__CAN1_SCE_call,4,4
	.comm	__EXTI9_5_call,4,4
	.comm	__TIM1_BRK_call,4,4
	.comm	__TIM1_UP_call,4,4
	.comm	__TIM1_TRG_COM_call,4,4
	.comm	__TIM1_CC_call,4,4
	.comm	__TIM2_call,4,4
	.comm	__TIM3_call,4,4
	.comm	__TIM4_call,4,4
	.comm	__I2C1_EV_call,4,4
	.comm	__I2C1_ER_call,4,4
	.comm	__I2C2_EV_call,4,4
	.comm	__I2C2_ER_call,4,4
	.comm	__SPI1_call,4,4
	.comm	__SPI2_call,4,4
	.comm	__USART1_call,4,4
	.comm	__USART2_call,4,4
	.comm	__USART3_call,4,4
	.comm	__EXTI15_10_call,4,4
	.comm	__RTCAlarm_call,4,4
	.comm	__OTG_FS_WKUP_call,4,4
	.comm	__TIM5_call,4,4
	.comm	__SPI3_call,4,4
	.comm	__UART4_call,4,4
	.comm	__UART5_call,4,4
	.comm	__TIM6_call,4,4
	.comm	__TIM7_call,4,4
	.comm	__DMA2_Channel1_call,4,4
	.comm	__DMA2_Channel2_call,4,4
	.comm	__DMA2_Channel3_call,4,4
	.comm	__DMA2_Channel4_call,4,4
	.comm	__DMA2_Channel5_call,4,4
	.comm	__ETH_call,4,4
	.comm	__ETH_WKUP_call,4,4
	.comm	__CAN2_TX_call,4,4
	.comm	__CAN2_RX0_call,4,4
	.comm	__CAN2_RX1_call,4,4
	.comm	__CAN2_SCE_call,4,4
	.comm	__OTG_FS_call,4,4
	.align	2
	.global	delay
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	delay, %function
delay:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	.syntax divided
@ 288 "CMSIS/Include/core_cmInstr.h" 1
	nop
@ 0 "" 2
	.arm
	.syntax unified
	nop
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r2, [fp, #-16]
	mov	r3, r2
	lsl	r3, r3, #5
	sub	r3, r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-8]
	cmp	r3, r2
	bcc	.L3
	nop
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	delay, .-delay
	.comm	onoff,4,4
	.comm	onoff2,4,4
	.global	count
	.bss
	.type	count, %object
	.size	count, 1
count:
	.space	1
	.text
	.align	2
	.global	test
	.syntax unified
	.arm
	.fpu softvfp
	.type	test, %function
test:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L8
	ldr	r3, [r3]
	cmp	r3, #0
	bne	.L5
	mov	r2, #0
	mov	r1, #0
	ldr	r0, .L8+4
	bl	gpio_pin_write
	ldr	r3, .L8
	mov	r2, #1
	str	r2, [r3]
	b	.L4
.L5:
	mov	r2, #1
	mov	r1, #0
	ldr	r0, .L8+4
	bl	gpio_pin_write
	ldr	r3, .L8
	mov	r2, #0
	str	r2, [r3]
	nop
.L4:
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L9:
	.align	2
.L8:
	.word	onoff2
	.word	1073809408
	.size	test, .-test
	.section	.rodata
	.align	2
.LC0:
	.ascii	"\015\012last decoded time = %u\012\012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	ldr	r3, .L19
	ldr	r3, [r3, #28]
	ldr	r2, .L19
	orr	r3, r3, #402653184
	str	r3, [r2, #28]
	ldr	r3, .L19+4
	ldr	r3, [r3]
	ldr	r2, .L19+4
	orr	r3, r3, #256
	str	r3, [r2]
	ldr	r3, .L19
	ldr	r3, [r3, #32]
	ldr	r2, .L19
	orr	r3, r3, #1
	str	r3, [r2, #32]
	nop
.L11:
	ldr	r3, .L19
	ldr	r3, [r3, #32]
	and	r3, r3, #2
	cmp	r3, #0
	beq	.L11
	ldr	r3, .L19
	ldr	r3, [r3, #32]
	bic	r3, r3, #768
	ldr	r2, .L19
	orr	r3, r3, #256
	str	r3, [r2, #32]
	ldr	r3, .L19
	ldr	r3, [r3, #32]
	ldr	r2, .L19
	orr	r3, r3, #32768
	str	r3, [r2, #32]
	nop
.L12:
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	and	r3, r3, #8
	cmp	r3, #0
	beq	.L12
	nop
.L13:
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L13
	ldr	r3, .L19+8
	ldrh	r3, [r3]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	ldr	r2, .L19+8
	orr	r3, r3, #1
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	strh	r3, [r2]	@ movhi
	nop
.L14:
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L14
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	ldr	r2, .L19+8
	orr	r3, r3, #16
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	strh	r3, [r2, #4]	@ movhi
	ldr	r3, .L19+8
	mvn	r2, #32768
	strh	r2, [r3, #12]	@ movhi
	ldr	r3, .L19+8
	mov	r2, #0
	strh	r2, [r3, #8]	@ movhi
	ldr	r3, .L19+8
	mov	r2, #1000
	strh	r2, [r3, #28]	@ movhi
	ldr	r3, .L19+8
	mov	r2, #0
	strh	r2, [r3, #24]	@ movhi
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	ldr	r2, .L19+8
	bic	r3, r3, #16
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	strh	r3, [r2, #4]	@ movhi
	nop
.L15:
	ldr	r3, .L19+8
	ldrh	r3, [r3, #4]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L15
	ldr	r3, .L19+12
	mov	r2, #0
	str	r2, [r3]
	ldr	r3, .L19+16
	mov	r2, #0
	str	r2, [r3]
	mov	r0, #72
	bl	clock_set_speed
	bl	gpio_init_all
	mov	r0, #1
	bl	systick_enable
	mov	r3, #13
	str	r3, [fp, #-8]
	b	.L16
.L17:
	ldr	r3, [fp, #-8]
	and	r3, r3, #255
	mov	r2, #248
	mov	r1, r3
	ldr	r0, .L19+20
	bl	gpio_pin_mode
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L16:
	ldr	r3, [fp, #-8]
	cmp	r3, #15
	ble	.L17
	bl	uart2_init
	ldr	r3, .L19+24
	ldr	r2, .L19+28
	str	r2, [r3]
	mov	r2, #0
	mov	r1, #0
	ldr	r0, .L19+32
	bl	dcf77_init
.L18:
	bl	dcf77_get_time
	mov	r3, r0
	mov	r1, r3
	ldr	r0, .L19+36
	bl	_printf
	ldr	r0, .L19+40
	bl	delay
	b	.L18
.L20:
	.align	2
.L19:
	.word	1073876992
	.word	1073770496
	.word	1073752064
	.word	onoff
	.word	onoff2
	.word	1073811456
	.word	_putchar
	.word	uart2_send_char
	.word	1073809408
	.word	.LC0
	.word	16383
	.size	main, .-main
	.align	2
	.global	T1Irr
	.syntax unified
	.arm
	.fpu softvfp
	.type	T1Irr, %function
T1Irr:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	.syntax divided
@ 328 "CMSIS/Include/core_cmFunc.h" 1
	cpsid i
@ 0 "" 2
	.arm
	.syntax unified
	nop
	ldr	r3, .L25
	ldrb	r3, [r3]	@ zero_extendqisi2
	add	r3, r3, #1
	and	r2, r3, #255
	ldr	r3, .L25
	strb	r2, [r3]
	ldr	r3, .L25+4
	ldr	r3, [r3]
	cmp	r3, #0
	bne	.L22
	mov	r2, #1
	mov	r1, #13
	ldr	r0, .L25+8
	bl	gpio_pin_write
	ldr	r3, .L25+4
	mov	r2, #1
	str	r2, [r3]
	b	.L23
.L22:
	mov	r2, #0
	mov	r1, #13
	ldr	r0, .L25+8
	bl	gpio_pin_write
	ldr	r3, .L25+4
	mov	r2, #0
	str	r2, [r3]
.L23:
	mov	r3, #1073741824
	ldrh	r3, [r3, #16]	@ movhi
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	mov	r2, #1073741824
	bic	r3, r3, #1
	lsl	r3, r3, #16
	lsr	r3, r3, #16
	strh	r3, [r2, #16]	@ movhi
	.syntax divided
@ 317 "CMSIS/Include/core_cmFunc.h" 1
	cpsie i
@ 0 "" 2
	.arm
	.syntax unified
	nop
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L26:
	.align	2
.L25:
	.word	count
	.word	onoff
	.word	1073811456
	.size	T1Irr, .-T1Irr
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
