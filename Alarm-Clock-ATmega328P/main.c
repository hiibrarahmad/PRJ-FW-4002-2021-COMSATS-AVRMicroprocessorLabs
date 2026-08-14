/*
 * PRJ-FW-4001-2020-ArduinoAVRAlarmClock
 *
 * Copyright (C) 2020 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. See the LICENSE file for details.
 *
 * University semester project: an ATmega328P digital alarm clock. Keeps
 * time in software via a Timer1 1Hz interrupt (no RTC module), displays
 * HH:MM:SS + alarm status on a 16x2 character LCD, reads five push
 * buttons for setting the clock/alarm and toggling the alarm on/off, and
 * drives a buzzer when the clock time matches the alarm time. An IR
 * sensor input turns the LCD backlight on for a few seconds when
 * triggered. Simulated and verified in Proteus 8 Professional.
 */

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>


void init_lcd(void);
void moveto(unsigned char, unsigned char);
void stringout(char *);
void writecommand(unsigned char);
void writedata(unsigned char);
void writenibble(unsigned char);
ISR(TIMER1_COMPA_vect);

int SEC2 = 5;//allocating integer memory for storing seconds
int SEC1 = 5;
int MIN2 = 0;// allocating integer memory for storing minutes
int MIN1 =0;
int HOU2 =0;// allocating integer memory for storing hours
int HOU1 =0;


int ALMMIN2 = 1;//  storing  alarm minutes
int ALMMIN1 =0;
int ALMHOU2 =0;//  storing alarm hours
int ALMHOU1 =0;

int ALMstatus=0;  // pass 0 or 1 for alarm status   1-> on   0-> off

void displayAlmststus(int ALMstatus); //print the alarm status to the display
void setbuzzer(int MIN1,int MIN2,int HOU1,int HOU2,int ALMMIN1,int ALMMIN2,int ALMHOU1,int AIMHOU2,int ALMstatus); // compare the time value and alarm time


int timer;
int backtime=0;


int main(void) {



init_lcd();
char str[80];
char str1[80];
char ALM[80];

DDRC |=0b00000001; //set output to buzzer

DDRC &= ~(1<<PCINT9);  //set A1 as a  input 

// new add
DDRC &= ~(1<<PCINT10);  //set A2 as a  input
DDRC &= ~(1<<PCINT11);  //set A3 as a  input
DDRC &= ~(1<<PCINT12);  //set A4 as a  input
DDRC &= ~(1<<PCINT13);  //set A4 as a  input   //for the IR senser 

// alarm status button and backlight button

DDRB &= ~(1<<PCINT3);  //set 11 as a  input
DDRB &= ~(1<<PCINT4);  //set 12 as a  input

DDRB |= (1<<PCINT2);  //pin 10 output to the Backlight 




					DDRD |=0b00000100;
					PORTD |=0b00000100;
					_delay_ms(10000);
					

TCCR1B=(1<<WGM12);
OCR1A = 15625;
TIMSK1=(1<<OCIE1A);

sei();

TCCR1B |=(1<<CS12)|(1<<CS10);


sprintf(str1, "IBRAR");
stringout(str1);


_delay_ms(10000);
	
while (1) {               
	
	// Loop forever
	
	moveto(0,0);
	
	sprintf(str, "%d%d:%d%d:%d%d",HOU1,HOU2,MIN1,MIN2,SEC1,SEC2);//send data to display
	stringout(str);
	moveto(0,9);
	sprintf(ALM, "ALM:");
	stringout(ALM);
			
			
			if((PINC & 0x02)== 0x02 ) //If switch is pressed change min of Clock
			
			{			
				MIN2++; 
				
				_delay_ms(3000); 
		
				if (MIN2 == 10)
				{
					MIN2 = 0;
					MIN1= MIN1 + 1;
					
					if (MIN1 == 6)
					{
						MIN1 =0;
						MIN2 =0;
					}
					
				}
				
			}
			
			
			if((PINC & 0x04)== 0x04 ) //If switch is pressed change hou of CLock
			
			{			
				HOU2=HOU2+1;
				
			
				_delay_ms(3000);
			
				
				if (HOU1 ==2 && HOU2 == 4 )
				{
					HOU2 = 0;
					HOU1 = 0;
				
				}
				else {
			
					
					if (HOU2==10)
					{	
						HOU2=0;
						HOU1=HOU1+1;
					}
					
				}
				
				
				
				
			}

			
			// set the alarm mode
			
			if((PINC & 0x02)== 0x02 && (PINC & 0x04)== 0x04 )
			
			{			
				moveto(1,0);
				
				sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
				stringout(str1);
				ALMstatus =1;
					
				_delay_ms(3000);
			}
			
			
				//	IR senser ditect
			
			if((PINC & 0b00100000)== 0b00100000 )
				{
					
					backtime=SEC2;
					if(backtime < 5)
					{
						backtime+5;
					}
					
					if (backtime >= 5)
					{
						backtime-5;
					}
					
					_delay_ms(250);
					PORTB |= (1<<PCINT2); // ON backlight
					_delay_ms(250);
				
				
				}		
			
			
			if((PINC & 0x08)== 0x08 ) //If switch is pressed change ALMmin 
			
			{			
				ALMMIN2++;
				ALMstatus=1;
			
				_delay_ms(3000);
			
				moveto(1,0);
				
				sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
				stringout(str1);
				
				if (ALMMIN2 == 10)
				{
					ALMMIN2 = 0;
					ALMMIN1= ALMMIN1 + 1;
					moveto(1,0);
					
					sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
					stringout(str1);
					
					if (ALMMIN1 == 6)
					{
						ALMMIN1 =0;
						ALMMIN2 =0;
						moveto(1,0);
						
						sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
						stringout(str1);
					}
					
				}
				
			}
			
			
			if((PINC & 0x10)== 0x10 ) //If switch is pressed change ALMHOU
			
			{			
				ALMHOU2++;
				ALMstatus=1;
				
				_delay_ms(3000);
				
				
				moveto(1,0);
				
				sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
				stringout(str1);
				
				if (ALMHOU1 ==2 && ALMHOU2 == 4 )
				{
					ALMHOU2 = 0;
					ALMHOU1 = 0;
					moveto(1,0);
					
					sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
					stringout(str1);
				}
				else {
					
					
					if (ALMHOU2==10)
					{
						ALMHOU2=0;
						ALMHOU1=ALMHOU1+1;
						moveto(1,0);
						
						sprintf(str1, "%d%d:%d%d:ALARM",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
						stringout(str1);
					}
					
				}
				
			}
			
			
				if((PINC & 0x08)== 0x08 && (PINC & 0x10)== 0x10 ) //If switch is pressed backlight on for 5 seconds	
				{		
					//backtime=SEC2;
						if(backtime < 5)
						{
							backtime+5;
						}
						
						if (backtime >= 5)
						{
							backtime-5;
						}
				
						_delay_ms(250);
						PORTB |= (1<<PCINT2); // ON backlight
						//PORTB &= ~(1<<PCINT2); // OFF backlight
					
				
				}
			
			
			
			// check the alarm button status and change the alarm mode 
			
			
				
				_delay_ms(100);
				
				if((PINB & 0x10)== 0x10 ) 			
				{		
					
					if (ALMstatus==0)
					{
						ALMstatus=1;
						
						_delay_ms(3000);
						
						setbuzzer(MIN1,MIN2,HOU1,HOU2,ALMMIN1,ALMMIN2,ALMHOU1,ALMHOU2,ALMstatus);
						
					}
					else
					{
						ALMstatus=0;	
						
						_delay_ms(3000);
						
						setbuzzer(MIN1,MIN2,HOU1,HOU2,ALMMIN1,ALMMIN2,ALMHOU1,ALMHOU2,ALMstatus);
						moveto(1,0);
						
						sprintf(str1, "              ",ALMHOU1,ALMHOU2,ALMMIN1,ALMMIN2);//send ALM data to display
						stringout(str1);
					}
				
					
					
								
				
			
				}  
			
			
			
			
	
	
	
	displayAlmststus(ALMstatus);  // calling the alarm function
	_delay_ms(200);
	moveto(0,14);
	
	setbuzzer(MIN1,MIN2,HOU1,HOU2,ALMMIN1,ALMMIN2,ALMHOU1,ALMHOU2,ALMstatus);
	
   }





    return 0; 
}

ISR(TIMER1_COMPA_vect){    //This is the interrupt request
	SEC2++;
	
	//backlight off session	
	//#################################
	if (SEC2 == backtime )	{
		
			PORTB &= ~(1<<PCINT2); // OFF backlight		
	}
	
	//###############################
		
	if (SEC2 == 10)
	{	
		
		SEC2 = 0;
		
		//backlight off session
		//#################################
		if (SEC2 == backtime )	{
		
			PORTB &= ~(1<<PCINT2); // OFF backlight
			}
		
		SEC1 = SEC1 +1;
			PORTB &= ~(1<<PCINT2); // OFF backlight		
	
		if (SEC1 == 6)
		{	
			SEC2 = 0;
			SEC1 = 0;
			MIN2 = MIN2 +1;
			
			if (MIN2 == 10)
			{	
				MIN2 = 0;
				MIN1= MIN1 + 1;
				
				if (MIN1 == 6)
				{
					MIN1 =0;
					MIN2 =0;
					HOU2 = HOU2 +1;
					
					if (HOU2 ==10 && HOU1 == 1 || HOU1==0)
					{
						HOU2 = 0;
						HOU1 = HOU1 +1;
					}
					else{
						HOU1 =0;
						HOU2 =0;
					}
				}
			}
		}
	} 
}


void displayAlmststus(int ALMstatus){  // print alarm status
	
	char ALM[80];
	
	if(ALMstatus == 0 )
	{	
		moveto(0,13);
		sprintf(ALM, "OFF");
		stringout(ALM);
		
	}
	else
	{	

		moveto(0,13);
		sprintf(ALM, " ON");
		stringout(ALM);
		
		
	}
	
	
}


void setbuzzer(int MIN1,int MIN2,int HOU1,int HOU2,int ALMMIN1,int ALMMIN2,int ALMHOU1,int ALMHOU2,int ALMstatus){
	if(ALMstatus == 1 )
	{
			
			if (MIN1==ALMMIN1 && MIN2==ALMMIN2 && HOU1==ALMHOU1 && HOU2==ALMHOU2)
			{	
		
				PORTC|=0b00000001;
				_delay_ms(1000);
					
				PORTC &= ~(0b00000001);
				_delay_ms(1000);
				
			}
	
	}else{
		
		PORTC&=0b11111110;
			
	}
	
	
	
	
}


/*
  init_lcd - Configure the I/O ports and send the initialization commands
*/
void init_lcd()
{
    /* ??? */                   // Set the DDR register bits for ports B and D
	DDRD|=0xF0;
	DDRB|=0x03;
    _delay_ms(15);              // Delay at least 15ms

	
	writecommand(0x03);
    /* ??? */                   // Use writenibble to send 0011
    _delay_ms(5);               // Delay at least 4msec
	writecommand(0x03);
    /* ??? */                   // Use writenibble to send 0011
    _delay_us(120);             // Delay at least 100usec

    /* ??? */                   // Use writenibble to send 0011, no delay needed
	writecommand(0x03);

	writecommand(0x02);
    /* ??? */                   // Use writenibble to send 0010
    _delay_ms(2);               // Delay at least 2ms
    
    writecommand(0x28);         // Function Set: 4-bit interface, 2 lines
_delay_ms(2);
    writecommand(0x0f);         // Display and cursor on
_delay_ms(25); 

writecommand(0x01); 
_delay_ms(25); 
//writecommand(1);
}

/*
  moveto - Move the cursor to the row (0 or 1) and column (0 to 15) specified
*/
void moveto(unsigned char row, unsigned char col)
{
    
	if(row==0){
		
		writecommand(0x80+col);
	}
	if(row==1){
		
		writecommand(0xc0+col);
	}
	
}

/*
  stringout - Write the string pointed to by "str" at the current position
*/
void stringout(char *str)
{
    
	do{
		
		writedata(*str);
		str++;
		
	}while(*str!= '\0');
	
	
}

/*
  writecommand - Send the 8-bit byte "cmd" to the LCD command register
*/
void writecommand(unsigned char cmd)
{
	unsigned char temp;

PORTB&=~(0x01);
temp=cmd&0xF0;
writenibble(temp);
temp=cmd&0x0F;
temp=temp<<4;
writenibble(temp);
_delay_ms(3);

}

/*
  writedata - Send the 8-bit byte "dat" to the LCD data register
*/
void writedata(unsigned char dat)
{
unsigned char temp;

PORTB|=0x01;
temp=dat&0xF0;
writenibble(temp);
temp=dat&0x0F;
temp=temp<<4;
writenibble(temp);
_delay_ms(3);

}

/*
  writenibble - Send four bits of the byte "lcdbits" to the LCD
*/
void writenibble(unsigned char lcdbits)
{
PORTD = lcdbits;//&0xF0;
//PORTB |= 0x02;
PORTB &= ~(0x02);
PORTB |= 0x02;
PORTB &= ~(0x02);
}