objects = test123.o ../../utils/clock.o ../../utils/gpio.o ../../utils/extint.o
defines = -DSTM32F10X_MD
includes = -I../../CMSIS/Include -I../../CMSIS/Device/ST/STM32F10x/Include -I../..
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	$(cc) -o test123.o -nodefaultlibs -nostdlib -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb test123.c
	$(cc) -o image.elf -nodefaultlibs -nostdlib -nostartfiles -Wl,-T../../link.ld $(objects)
	$(toolchain)objcopy -O binary image.elf image.bin

clean:
	rm -f *.elf *.bin *.o

flash:
	st-flash write image.bin 0x8000000

