defines = -DSTM32F10X_MD
includes = -I../core-common-lib/CMSIS/Include -I../core-common-lib/CMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	$(cc) -O3 -o stdio.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb stdio.c
	$(cc) -O3 -o time.o -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb time.c
clean:
	rm -f *.o
