/*
 * mode4.c
 *
 *  Created on: 15 Sep 2023
 *      Author: duvan
 */
#include "mode4.h"

void ToggleLedRed4(){
	HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, 0);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, 0);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, 0);
	HAL_Delay(500);
}
void mode_led4(){
	int x = modgreen/10;
	int y = modgreen%10;

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	display7SEG(0);
	display7SEG_2(4);
	HAL_Delay(150);

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
	display7SEG(x);
	display7SEG_2(y);
	HAL_Delay(150);

}
void mod_duration4(){
	if(isButtonPressed(1)==1&&status==4){
		modgreen++;
		int x = modgreen/10;
		int y = modgreen%10;
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		display7SEG(x);
		display7SEG_2(y);
	}
	if(isButtonPressed(2)==1&&status==4){
		x2 = modgreen/10;
		y2 = modgreen%10;
	}
}
void mode4_run(){
	mode_led4();
	ToggleLedRed4();
	mod_duration4();
}
