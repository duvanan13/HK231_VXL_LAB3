/*
 * button.c
 *
 *  Created on: Sep 11, 2023
 *      Author: duvan
 */
#include "button.h"

int button_flag[NO_OF_BUTTONS];
int button1s_flag[NO_OF_BUTTONS];

static GPIO_PinState KeyReg0[NO_OF_BUTTONS];
static GPIO_PinState KeyReg1[NO_OF_BUTTONS];
static GPIO_PinState KeyReg2[NO_OF_BUTTONS];

static GPIO_PinState KeyReg3[NO_OF_BUTTONS];

int TimeForKeyPress[NO_OF_BUTTONS];
int duration = 200;

//void subKeyProcess(){
//	//todo
//	button_flag[0] =1;
//}
int isButtonPressed(int index){
	if(button_flag[index]==1){
		button_flag[index]=0;
		return 1;
	}
	return 0;
}
int isButton1sPressed(int index){
	return (button1s_flag[index]==1);
}
void getKeyInput(){
	for(int i=0;i<NO_OF_BUTTONS;i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(buttonGpioPort[i], buttonGpioPin[i]);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i]!= KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					//TODO
					button_flag[i]=1;
//					if(button_flag[i]>=2){
//						button1s_flag[i] = 1;
//					}
					TimeForKeyPress[i] = 0;
				}
//				else {
//					button_flag[i] = 0;
//					button1s_flag[i] = 0;
//				}
			}else{
				TimeForKeyPress[i]++;
				if(TimeForKeyPress[i] == duration){
					//TODO
//					if(KeyReg2 == PRESSED_STATE){
//						button1s_flag[i]=1;
//						button_flag[i]=1;
//					}
//					TimeForKeyPress[i] = 0;
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}

