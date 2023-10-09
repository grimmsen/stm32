objects = test.o std/stdio.o utils/iae_handlers.o utils/clock.o utils/gpio.o utils/timer.o peripheral/dcf77.o peripheral/shift_595.o utils/uart.o utils/extint.o std/time.o
defines = -DSTM32F10X_MD
includes = -ICMSIS/Include -ICMSIS/Device/ST/STM32F10x/Include
toolchain = arm-none-eabi-
cc = $(toolchain)gcc
debug = -g

%.o: %.c
	${cc} -c $< -o $@ $(defines) $(includes) $(debug) -mcpu=cortex-m3 -mthumb

all: test.o
	make -C utils/
	make -C peripheral/
	make -C std/
	$(cc) -o image.elf -nodefaultlibs -nostdlib -nostartfiles -Wl,-Tlink.ld $(objects)
	$(toolchain)objcopy -O binary image.elf image.bin
	chmod 755 bin/createproject.sh

clean:
	make clean -C utils/
	make clean -C std/
	make clean -C test/
	make clean -C examples/blinky
	rm -f *.elf *.bin *.o

download:
	st-flash write image.bin 0x8000000
