/*
 * buttonpressed.h — part of PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Toggle-LED-Push-Button
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Created: 10/23/2021 9:53:15 PM
 */


#ifndef PORTSREADWRITE_H_
#define PORTSREADWRITE_H_

void configure_ports();
char button_pressed();
void toggle_LED();

#endif /* BUTTONPRESSED_H_ */