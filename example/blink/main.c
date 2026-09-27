/*
 * File:   main.c
 * Author: Kwabena Amoako
 *
 * Created on September 26, 2026, 3:57 PM
 */
#include "gpio.h"
#include "device.h"
#include "delay.h"

void main(void){
    pinMode(GPIO_PORTA,0,OUTPUT);

    while(1){
        digitalWrite(GPIO_PORTA,0, HIGH);
        delay(500);
        digitalWrite(GPIO_PORTA,0, LOW);
        delay(500);
    }
    
}