defines = -DSTM32F10X_MD
includes = -I../CMSIS/Include -I../CMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	$(cc) -o clock.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb clock.c
	$(cc) -o uart.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb uart.c
	$(cc) -o gpio.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb gpio.c
	$(cc) -o extint.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb extint.c
	$(cc) -o shift_595.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb shift_595.c
clean:
	rm -f *.o
