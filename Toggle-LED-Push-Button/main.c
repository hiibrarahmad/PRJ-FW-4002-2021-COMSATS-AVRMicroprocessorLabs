/*
 * PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Toggle-LED-Push-Button
 *
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Assignment 2, Fall 2021: a single push-button toggles an LED once per
 * press regardless of how long it's held (PORTD0 in, PORTB0 out).
 *
 * Assign2FA21.c
 * Created: 10/23/2021 9:43:38 PM
 */  //Push button with LED

#include <avr/io.h>
#include "portsreadwrite.h"

int main(void)
{
    
  configure_ports();			//For input and output
     
    while (1) 
    {
		
		
		(button_pressed());
		
		{		//button_pressed returns 1 when button is pressed 
			
			toggle_LED();	}
						
   
    }
}

