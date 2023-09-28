# STM32 Bluepill boiler plate

## About
This is a simple boilerplate, which can be used as a template for a new STM32F103
project. It contains a bunch of functions to deal with the billions of registers
of this microcontroller. Also a library for basic standard tasks (like printf)
and interfaces for common peripherals is part of this boiler plate.

## Getting started
### Install the toolchain

You need the STLink-executable and the ARM-GCC-toolchain installed. On Ubuntu
this is done via

    apt-get install stlink-tools binutils-arm-none-eabi gcc-arm-none-eabi

Once the toolchain is installed, you're good to go.

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

to be done
