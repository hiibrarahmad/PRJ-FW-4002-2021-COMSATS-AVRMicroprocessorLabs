/*
 * readkeypadalgo.c — part of PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Matrix-Keypad
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Row/column scan of the 3x4 matrix keypad with debounce delays.
 */

#include "readkeypadinc.h"
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#define rlength 4	//Number of row pins
#define clength 3

char readkeypad(){
	
	char row,col,in;
	//TWCR=0x00;
	DDRC=0xff;
	setrowoutcolin();
	
	waitforpress();
	_delay_ms(80);//For debouncing
	col=readport();
	_delay_ms(10);
	setcoloutrowin();
	_delay_us(5);//If this delay is less than 4us, correct value is not updated in PIND
	row=readport();
	waitforrelease();
	_delay_ms(80);// For debouncing
	
	in=(col+row);
	
	return (in);
}
	
	
	
	
