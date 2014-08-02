## Overview
This project contains two templates for getting started with C and C++ projects
on the STM32F4-Discovery board on a Linux environment. To use them, simply copy
the template directory of your choice and go forth!

## Usage

1. Download the Arm Toolchain.
1. Add the binaries to your path such that you can call
    arm-none-eabi-gcc
without specifying the full path.
1. Download the STM32F4-Discovery base code from ST's website. (You must be
logged in with an account.)
1. Define a path variable called ST_BASE_DIR, that specifies the path to the
ST base code directory, STM32F4-Discovery_FW_V1.1.0, and add it to your .bashrc
1. source your .bashrc

### Programming
To upload the compiled binary to the Discovery, you can use stlink, from 
[Texane's repo](https://github.com/texane/stlink).
    
    st-flash write PROJECT_NAME.bin 0x8000000

Keep in mind that you need to add the udev rules as well.
