# HC-SR04 Ultrasonic Sensor

Interfaces an HC-SR04 ultrasonic distance sensor with the ATmega328P — trigger/echo on `PORTC0`/`PORTC1`, distance measured via a Timer1 pulse-width capture and printed in centimeters to a bit-banged 16x2 character LCD on `PORTD`. Also drives 5 indicator LEDs.

Simulated in Proteus 8 Professional; the same approach works unmodified on ATmega8/ATmega32.
