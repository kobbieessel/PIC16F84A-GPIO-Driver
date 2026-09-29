# PIC16F84A Bare-Metal GPIO Driver
A bare-metal GPIO driver for the PIC16F84A microcontroller written in C, featuring direct register access and Arduino-style APIs for configuring, reading, writing, and toggling GPIO pins. 
Tested in Proteus, with XC8-specific functions used only for delay support. No high-level GPIO libraries are used.

## Project Structure

```test
PIC16F84A-GPIO-Driver/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── include/
│   ├── device.h
│   ├── gpio.h
│   ├── PIC_CONFIG.h
│   └── delay.h
│
├── src/
│   ├── gpio.c
│   └── delay.c
│
├── example/
│   └── blink/
│       └── main.c
│
├── simulation/
│   ├── proteus/
│   │   └── Blink.pdsprj
│   └── images/
│       └── blink_test.png
│
└── datasheet/
    └── PIC16F84A
```
## Features
- Configure individual GPIO pins as input or output
- Set GPIO pins HIGH or LOW
- Read GPIO pin state
- Toggle GPIO pins
- Support for PORTA and PORTB
- Register-level implementation
- Configurable oscillator frequency
- Proteus simulation support

## Supported Microcontroller
- PIC16F84A

## Toolchain
- MPLAB X IDE
- XC8 Compiler
- Proteus for simulation

## API
### Configure a Pin
### Set Pin Mode (OUTPUT or INPUT)
```c
pinMode(GPIO_PORT, PIN, MODE);
```
### Set a Pin HIGH
```c
digitalWrite(GPIO_PORTA, 2, HIGH);
```
### Set a Pin LOW
```c
digitalWrite(GPIO_PORTA, 2, LOW);
```
### Read Pin
```c
uint8_t state = digitalRead(GPIO_PORTA, 2);
```
### Toggle Pin
```c
toggle(GPIO_PORTA, 2);
```
## Oscillator Configuration
The default oscillator frequency is:
```c
#define _XTAL_FREQ 4000000UL
```
The frequency can be overridden by the user before including the configuration header.
```c
// Example:
#define _XTAL_FREQ 8000000UL
```

## Code Example: toggle API
```c
#include "gpio.h"
#include "delay.h"

void main(void)
{
    // Sets the mode of RA0
    pinMode(GPIO_PORTA, 0, OUTPUT); 

    // toggle RA0 every half a second
    while (1)
    {
        toggle(GPIO_PORTA, 0); 
        delay(500);
    }
}
```
## Simulation result (Proteus)
![toggling led connected to RA0](/simulation/images/blink.gif)

## Hardware Test
The driver was tested on a PIC16F84A microcontroller to verify GPIO output control and toggle behavior.

![PIC16F84A GPIO Driver Test](/simulation/assets/pic16f84a_gpio_driver_test.gif)

## Future Improvements
- External interrupt driver
- Timer0 driver
- Interrupt-based GPIO
- Debounced digital input
- Error/status handling
- Additional PIC16 peripherals

## Author
Kwabena Amoako
- LinkedIn: [Kwabena E. Amoako](https://www.linkedin.com/in/kwabena-e-amoako/)

