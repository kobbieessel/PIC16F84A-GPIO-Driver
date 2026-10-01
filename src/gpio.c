/*
 * File:   gpio.c
 * Author: Kwabena Amoako
 */

#include <stdint.h>
#include "gpio.h"
 
#define BIT(n) (1U << (n))
#define BIT_FIELD(value,bit_position) ((value) << (bit_position))

static uint8_t porta_shadow = 0U;
static uint8_t portb_shadow = 0U;

void pinMode(GPIO_Port port, uint8_t pin,Pin_Mode mode){
    uint8_t mask = (uint8_t)BIT(pin);
    switch (port){
        case GPIO_PORTA:
            if (pin <= 4){
                if(mode == INPUT){
                    BANK1->TRISA |= mask;
                }
                else if(mode == OUTPUT){
                    BANK1->TRISA &= (uint8_t)~mask;
                }   
            }
            break;
            
        case GPIO_PORTB:
            if (pin <= 7){
                if(mode == INPUT){
                    BANK1->TRISB |= mask;
                }
                else if(mode == OUTPUT){
                    BANK1->TRISB &= (uint8_t)~mask;
                }   
            }
            break;
        
        default:
            break;
    }
}

void digitalWrite(GPIO_Port port, uint8_t pin, GPIO_State state){
    
    uint8_t mask = (uint8_t)BIT(pin);
    switch (port){
        case GPIO_PORTA:
            if (pin <= 4){
                if(state == HIGH){
                    porta_shadow |= mask;
                }
                else if(state == LOW){
                    porta_shadow &= (uint8_t)~mask;
                }  
                else{
                    break;
                }
             BANK0->PORTA = porta_shadow;
            }
            break;
            
        case GPIO_PORTB:
            if (pin <= 7){
                if(state == HIGH){
                    portb_shadow |= mask;
                }
                else if(state == LOW){
                    portb_shadow &= (uint8_t)~mask;
                }
                else{
                    break;
                }
             BANK0->PORTB = portb_shadow;
            }
            break;
        
        default:
            break;
    }
}

uint8_t digitalRead(GPIO_Port port, uint8_t pin){
    uint8_t mask = (uint8_t)BIT(pin);
    switch(port){
        case GPIO_PORTA:
            if(pin <= 4){
                return (BANK0->PORTA & mask) ? 1U : 0U;
            }
            break; 
            
        case GPIO_PORTB:
            if(pin <= 7){
                return (BANK0->PORTB & mask) ? 1U : 0U;
            }
            break;
        
        default:
            break;
    }
    
    return 0U;
}

void toggle(GPIO_Port port, uint8_t pin){
    
    uint8_t mask = (uint8_t)BIT(pin);
    switch(port){
        case GPIO_PORTA:
            if(pin <= 4){
                porta_shadow ^= mask;
                BANK0->PORTA = porta_shadow;
            }
            break;
            
        case GPIO_PORTB:
            if(pin <= 7){
                portb_shadow ^= mask;
                BANK0->PORTB = portb_shadow;
            }
            break;
            
        default:
            break;
    }
}

