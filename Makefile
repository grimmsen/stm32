objects = test.o utils/clock.o utils/gpio.o utils/shift_595.o utils/uart.o utils/extint.o std/stdio.o std/time.o
defines = -DSTM32F10X_MD
includes = -ICMSIS/Include -ICMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

all:
	make -C utils/
	make -C std/
	make -C test/
	make -C examples/blinky
	$(cc) -o test.o -nodefaultlibs -nostdlib -c $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb test.c
	$(cc) -o image.elf -nodefaultlibs -nostdlib -nostartfiles -Wl,-Tlink.ld $(objects)
	$(toolchain)objcopy -O binary image.elf image.bin

clean:
	make clean -C utils/
	make clean -C std/
	make clean -C test/
	make clean -C examples/blinky
	rm -f *.elf *.bin *.o

download:
	st-flash write image.bin 0x8000000
	make clean
