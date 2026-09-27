/*
 * File:   main.c
 * Author: Kwabena Amoako
 *
 * Created on September 24, 2026, 3:57 PM
 */

#include <stdint.h>
#include "gpio.h"
 
#define BIT(n) (1U << (n))
#define BIT_FIELD(value,bit_position) ((value) << (bit_position))

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
                    BANK0->PORTA |= mask;
                }
                else if(state == LOW){
                    BANK0->PORTA &= (uint8_t)~mask;
                }   
            }
            break;
            
        case GPIO_PORTB:
            if (pin <= 7){
                if(state == HIGH){
                    BANK0->PORTB |= mask;
                }
                else if(state == LOW){
                    BANK0->PORTB &= (uint8_t)~mask;
                }   
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
                BANK0->PORTA ^= mask;
            }
            break;
            
        case GPIO_PORTB:
            if(pin <= 7){
                BANK0->PORTB ^= mask;
            }
            break;
            
        default:
            break;
    }
}

