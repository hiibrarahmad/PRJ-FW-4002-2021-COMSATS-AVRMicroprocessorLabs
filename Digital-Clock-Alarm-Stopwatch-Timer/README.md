# Digital Clock / Alarm / Stopwatch / Timer

A second, menu-driven take on the alarm-clock idea: a 3-button interface (enter/increment/decrement on `PORTC0-2`) cycles through clock display, clock set, alarm set, stopwatch, and countdown timer modes on a character LCD (`PORTB`/`PORTD`). A Timer1 CTC interrupt ticks the seconds counter.
