/*
 * button.h
 *
 *  Created on: Sep 11, 2023
 *      Author: duvan
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0

int isButtonPressed(int index);
int isButton1sPressed(int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
