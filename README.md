# PIC16F84A Bare-Metal GPIO Driver
A bare-metal GPIO driver for the PIC16F84A microcontroller written in C, featuring direct register access and Arduino-style APIs for configuring, reading, writing, and toggling GPIO pins. 
Tested in Proteus, with XC8-specific functions used only for delay support. No high-level GPIO libraries are used.

## Features
- Configure individual GPIO pins as input or output
- Set GPIO pins HIGH or LOW
- Read GPIO pin state
- Toggle GPIO pins
- Support for PORTA and PORTB
- Register-level implementation
- Configurable oscillator frequency
- Proteus simulation support

## Toolchain
- MPLAB X IDE
- XC8 Compiler
- Proteus for simulation

## Future Improvements
- External interrupt driver
- Timer0 driver
- Interrupt-based GPIO
- Debounced digital input
- Error/status handling
- Additional PIC16 peripherals


## Author
Kwabena Amokao
- LinkedIn: [Kwabena E. Amoako](https://www.linkedin.com/in/kwabena-e-amoako/)

