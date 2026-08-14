/*
 * readkeypadinc.h — part of PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs / Matrix-Keypad
 * Copyright (C) 2021 Ibrar Ahmad
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Created: 10/20/2021 3:34:34 PM
 *  Author: IBRAR AHMAD
 */


#ifndef READKEYPADINC_H_
#define READKEYPADINC_H_


void setrowoutcolin();
void setcoloutrowin();
void waitforpress();
void waitforrelease();
char readport();

#endif /* READKEYPADINC_H_ */