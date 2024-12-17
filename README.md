# STM32 Bluepill boiler plate

## About
This is a simple boilerplate, which can be used as a template for a new STM32F103
project. It contains a bunch of functions to deal with the billions of registers
of this microcontroller. Also a library for basic standard tasks (like printf)
and interfaces for common peripherals is part of this boiler plate.
The projects goal is to provide a as-vanilla-as-possible way to develop for
the STM32 bluepill. No Arduino IDE or CubeIDE. All you need is an editor of
your choice, STs flash tools and GCC. The STM32 platform is actually pretty
complex and this boiler plate is far from production ready and wouldn't be 
at a 100%, when the platform will be obsolete.
But: It's advantage to the Arduino IDE is, that you can actually organize your
project the way you are used to, despite being forced to that single sketch.
When compared to CubeIDE, it keeps the HAL as low as possible. No code generators
nor pinplanners.
This boilerplate tries to keep you as close as possible to the hardware, while
providing conveniant but low leveled wrappers to the registers. It provides a
complete interface to ARMs vector table, which you can easily connect to an
abitrary C function.
Common libc functions like printf or putc have been reprogrammed, since libc isn't
availabe.

## Getting started
### Install the toolchain

You need the STLink-executable and the ARM-GCC-toolchain installed. On Ubuntu
this is done via

    apt-get install stlink-tools binutils-arm-none-eabi gcc-arm-none-eabi

Once the toolchain is installed, you're good to go.

Check the tools folder and if you have to create the dbus rules in order
to get the ST-Link programmer recognized by the usb subsystem.
On Ubuntu/Debian or Systemd based systems in general, a non working
ST-Link programmer could be brought to life by typing:

    tools/dbus-rules.sh

### Build and flash the blinky

First of all, clone the repository by typing:

    git clone git@github.com:grimmsen/stm32f103-bluepill-boilerplate.git

Change to the repository directory and type

    make

Wait until the build is done, then connect the ST-LINK V2 to the blue pill and
type

    make -C examples/blinky flash

If everything is fine, the onboard led should blink.

## Documentation

To create a new project, type

    bin/createproject.sh mynewproject

A compilable and flashable blinky program is created in the projects folder. 

You can build and upload it by typing

    make -C projects/mynewproject flash

Put your code in the project folder, with the mynewproject.c file in this example
being your entry point, containing the main function. 

to be continued ...
