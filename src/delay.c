/*
 * File:   main.c
 * Author: Kwabena Amoako
 *
 * Created on September 25, 2026, 3:57 PM
 */
#include "PIC_CONFIG.h"
#include <xc.h>
#include <stdint.h>
#include "delay.h"

void delay(uint32_t duration){
    while (duration--){
        __delay_ms(1);
    }
}

void delay_Microseconds(uint32_t duration){
    while (duration--){
        __delay_us(1);
    }
}

void delay_onesec(void){
    delay(1000);
}
