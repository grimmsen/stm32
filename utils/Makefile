defines = -DSTM32F10X_MD
includes = -I../CMSIS/Include -I../CMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

%.o: %.c
	${cc} -c $< -o $@ $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb

all: timer.o clock.o uart.o gpio.o extint.o iae_handlers.o

clean:
	rm -f *.o
