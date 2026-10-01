/*
 * File:   device.h
 * Author: Kwabena Amoako
 */
#ifndef DEVICE_H
#define DEVICE_H

<stdint.h>
    
typedef volatile uint8_t _IO;

typedef struct{
    _IO INDF;
    _IO TMR0;
    _IO PCL;
    _IO STATUS;
    _IO FSR;
    _IO PORTA;
    _IO PORTB;
    _IO RESERVED;
    _IO EEDATA;
    _IO EEADR;
    _IO PCLATH;
    _IO INTCON;
}BANK0_TypeDef;

typedef struct{
    _IO INDF;
    _IO OPTION_REG;
    _IO PCL;
    _IO STATUS;
    _IO FSR;
    _IO TRISA;
    _IO TRISB;
    _IO RESERVED;
    _IO EECON1;
    _IO EECON2;
    _IO PCLATH;
    _IO INTCON;
}BANK1_TypeDef;

typedef enum{
    INPUT = 1,
    OUTPUT = 0
}Pin_Mode;

typedef enum{
    GPIO_PORTA = 0,
    GPIO_PORTB = 1
}GPIO_Port;

typedef enum{
    LOW = 0,
    HIGH = 1
}GPIO_State;

#define BANK0_BASE 0x00U
#define BANK1_BASE 0x80U

#define BANK0 ((BANK0_TypeDef *)BANK0_BASE)
#define BANK1 ((BANK1_TypeDef *)BANK1_BASE)

#endif
