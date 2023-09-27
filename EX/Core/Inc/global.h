/*
 * global.h
 *
 *  Created on: 11 Sep 2023
 *      Author: duvan
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "timer.h"
#include "button.h"
#define NO_OF_BUTTONS 3

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN	3
#define AUTO_AMBER	4

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_AMBER 14

extern int status ;

extern int counter0;

extern int modred;
extern int modamber;
extern int modgreen;

extern int x;
extern int y;

extern int x1;
extern int t1;

extern int x2;
extern int y2;
#endif /* INC_GLOBAL_H_ */
