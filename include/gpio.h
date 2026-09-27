/*
 * File:   main.c
 * Author: Kwabena Amoako
 *
 * Created on September 24, 2026, 3:57 PM
 */
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "device.h"

void pinMode(
  GPIO_Port port, 
  uint8_t pin,
  Pin_Mode mode
);

void digitalWrite(
  GPIO_Port port, 
  uint8_t pin, 
  GPIO_State state
);

uint8_t digitalRead(
  GPIO_Port port, 
  uint8_t pin
);

void toggle(
  GPIO_Port port, 
  uint8_t pin
);

#endif
