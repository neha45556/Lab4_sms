/*	Author: ngupt009
 *  Partner(s) Name: Surya singh
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    enum LedStates { init, wait1, wait2, on1, on2} LedState ;

    /* Insert your solution below */
    while (1) {
        switch(LedState){
            case init:
                LedState = wait1;
                break;
            case wait1:
                if((PINA & 0x01) == 1){
                    LedState = on1;
                }
                else{
                    LedState = wait1;
                }
                break;
            case on1:
                if((PINA & 0x01) == 0){
                    LedState = wait2;
                }
                else{
                    LedState = on1;
                }
                break;
            case wait2:
                if((PINA & 0x01) == 1){
                    LedState = on2;
                }
                else{
                    LedState = wait2;
                }
                break;
            case on2:
                if((PINA & 0x01) == 0){
                    LedState = wait1;
                }
                else{
                    LedState = on2;
                }
                break;
        }
        switch(LedState){
            case init:
                PINB = 0x01;
                break;
            case wait1:
                break;
            case on1:
                PINB = 0x02;
                break;
            case wait2:
                break;
            case on2:
                PINB = 0x01;
                break;
        }
     
    }
    return 1;
}
