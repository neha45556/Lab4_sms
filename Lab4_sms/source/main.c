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

	enum STATES { START, INIT, INCREMENT, RESET, DECREMENT } state;
	unsigned char holder = 0x00;

void tick() {
switch(state) {
case START:
state = INIT;
break;
case INIT:
if (PINA == 0) {
state = RESET;
} else if (PINA == 1) {
state = INCREMENT;
} else if (PINA == 2) {
state = DECREMENT;
} else {
state = INIT;
}
break;
case INCREMENT:
state = INIT;
break;
case RESET:
state = INIT;
break;
case DECREMENT:
state = INIT;
break;
}

switch(state) {
case START:
break;
case INIT:
break;
case INCREMENT:
if (holder < 9) {
holder++;
}
break;
case RESET:
holder = 0;
break;
case DECREMENT:
if (holder > 0) {
holder--;
}
break;
}



}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; DDRC = 0xFF; PORTA = 0xFF; PORTC = 0x00;
state = START;
holder = 7;
    while (1) {
//	holder = 7;
	tick();
	PORTC = holder;
    }
    return 1;
}
