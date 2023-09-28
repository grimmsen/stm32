objects = test.o utils/clock.o utils/gpio.o utils/shift_595.o utils/uart.o utils/extint.o std/stdio.o std/time.o
defines = -DSTM32F10X_MD
includes = -Icore-common-lib/CMSIS/Include -Icore-common-lib/CMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	make -C utils/
	make -C std/
	make -C test/
	$(cc) -o test.o -nodefaultlibs -nostdlib -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb test.c
	$(cc) -o image.elf -nodefaultlibs -nostdlib -nostartfiles -Wl,-Tlink.ld $(objects)
	$(toolchain)objcopy -O binary image.elf image.bin

clean:
	make clean -C utils/
	make clean -C std/
	make clean -C test/
	rm -f *.elf *.bin *.o

download:
	st-flash write image.bin 0x8000000
	make clean
