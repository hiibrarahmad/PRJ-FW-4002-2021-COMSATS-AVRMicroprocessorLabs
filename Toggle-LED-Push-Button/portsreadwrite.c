/*
 * portsreadwrite.c — part of PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Toggle-LED-Push-Button
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Created: 10/23/2021 9:51:28 PM
 */


#include <avr/io.h>  


void configure_ports(){
	
	DDRD&=~(1<<PD0);		//PORTD pin0 as input for push button;
	PORTD|=(1<<PD0);		//Pullup the pin0 of portd
	DDRB|=(1<<PB0);		    //PORTB pin0 as output for push button;
	
}

char button_pressed()
{
			return((PIND&0x01)&0x01);		//Invert of current status because pin pulled
									//Multiple masks because invert will set other bits 1	
}


void toggle_LED(){
	               
	               /*XOR operation with 00000001. All other pins remain unchanged
	              but pin0 toggles*/
				   
				   //HERE WE WRITE THAT XOR CODE SEPARATELY AND PUT A IF AND ELSE CONDITION ON IT 
	if ( button_pressed())      //IF BOTTON IS PRESSED IS THEN STATMENT TRUE OTHERWISE WISE FALSE
	{   
		PORTB&=0b11111110;      //IF BUTTON IS PRESSED IT MEANS IT STATMENT TRUE SO THIS CODE WILL EXECUTE
	}
	else
	{
		PORTB|=0b00000001;      //IF BUTTON IS NOT PRESSED IT MEAN ITS STATMENT FALSE THEN THIS CODE WILL EXCUTE
	}
}