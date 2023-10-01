defines = -DSTM32F10X_MD
includes = -I../CMSIS/Include -I../CMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	$(cc) -o shift_595.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb shift_595.c
	$(cc) -o dcf77.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb dcf77.c
clean:
	rm -f *.o
