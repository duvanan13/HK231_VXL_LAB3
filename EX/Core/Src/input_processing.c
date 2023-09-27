/*
 * input_processing.c
 *
 *  Created on: 10 Sep 2023
 *      Author: duvan
 */

#include "input_processing.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;
int num = 1;

void fsm_for_input_processing(){
	switch(buttonState){
	case BUTTON_RELEASED:
		if(isButtonPressed(1)){
			buttonState = BUTTON_PRESSED;
			display7SEG(num++);
			if(num>=10) num=0;
		}
		break;
	case BUTTON_PRESSED:
		if(!isButtonPressed(1)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(isButton1sPressed(1)){
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!isButton1sPressed(1)){
			buttonState = BUTTON_RELEASED;
		}
		//todo
		if(timer1_flag==1){
			display7SEG(num++);
			if(num>=10) num=0;
			setTimer1(50);
		}
		break;
	}
}
