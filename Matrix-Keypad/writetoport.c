/*
 * writetoport.c — part of PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Matrix-Keypad
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Created: 10/20/2021 3:18:01 PM
 *  Author: IBRAR AHMAD
 */
#include <avr/io.h>

void writetoport(char ch){
	
	


PORTC=ch;	
	
}