/*
 * PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Lab-01-Development-Tools
 *
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Lab 1, Task 2: toggles PORTB bit 5 on/off with a 100ms delay, direct
 * register I/O (no Arduino framework) — first exercise in AVR Studio /
 * Atmel Studio, part of the COMSATS "Microprocessor Systems and
 * Interfacing" course.
 *
 * lab1 task 2.c
 * Created: 12/12/2021 2:07:54 PM
 * Author : AEGON
 */
// thsi is our main file here we will do code things 
//now lets build the code

#include <avr/io.h>// this header file is responsible for input output port on chip
#define F_CPU 16000000 // we are using atmega328p with 16 mhz frequency 
#include <util/delay.h>// for delay we need this header file cause we need to blink the led so for blinking we need some delay


int main(void)

	{

		DDRB=0b11111111;

		while(1)

		{

			PORTB=0b00100000; // we are making bit5 as high count to left from like this this  0 0 1 0 0 0 0 0
																					//		   7 6 5 4 3 2 1 0 bits
			_delay_ms(100);

			PORTB=0b00000000;

			_delay_ms(100);

		}

	}
	
	//just to save time and you can find very detail tutoiral on my blog    https://mendupmindcode.blogspot.com/2021/12/introduction-to-development-tools-and.html ///

