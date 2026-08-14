/*
 * PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Matrix-Keypad
 *
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Scans a 3x4 matrix keypad (readkeypadalgo.c) and writes the decoded
 * digit out to PORTC (writetoport.c), driving 4 indicator LEDs.
 * Originally "Lab 6" per the Proteus project title. Simulated on an
 * Arduino Uno (ATmega328P) in Proteus 8 Professional.
 *
 * keypadreusable.c
 * Created: 10/20/2021 2:05:17 PM
 * Author : IBRAR AHMAD
 */

#include "maininc.h"
#include "keypadtable.h"
#include <avr/io.h>

int main(void)
{
    /* Replace with your application code */
    
	unsigned char ch;
	UCSR0B&=~(1<<TXEN0);
	UCSR0B&=~(1<<RXEN0);
	while (1) 
    {
    ch=readkeypad();
    //if (ch==0b01111110)
		//{DDRB=0xff;	PORTB=1;}
	
	switch(ch){
		
		case one:				writetoport(1); break;
		case 0b10111110:		writetoport(2);	break;
		case 0b11011110:		writetoport(3);	break;
		case 0b01111101:		writetoport(4);	break;
		case 0b10111101:		writetoport(5);	break;
		case 0b11011101:		writetoport(6);	break;
		case 0b01111011:		writetoport(7);	break;
		case 0b10111011:		writetoport(8);	break;
		case 0b11011011:		writetoport(9); break;
		case 0b10110111:		writetoport(0);	break;
		default:		writetoport(ch);
	}
	//writetoport(1);
	
	}
}

