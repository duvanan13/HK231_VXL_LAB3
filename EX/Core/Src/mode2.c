/*
 * mode2.c
 *
 *  Created on: Sep 13, 2023
 *      Author: duvan
 */

#include "mode2.h"

void ToggleLedRed2(){
	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
	HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, 0);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, 0);
	HAL_Delay(500);
}
void mode_led2(){
	int x = modred/10;
	int y = modred%10;

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	display7SEG(0);
	display7SEG_2(2);
	HAL_Delay(150);

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
	display7SEG(x);
	display7SEG_2(y);
	HAL_Delay(150);

}
void mod_duration2(){
	if(isButtonPressed(1)==1&&status==2){
		modred++;
		int x = modred/10;
		int y = modred%10;
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		display7SEG(x);
		display7SEG_2(y);
	}
	if(isButtonPressed(2)==1&&status==2){
		x = modred/10;
		y = modred%10;
	}
}
void mode2_run(){
	mode_led2();
	ToggleLedRed2();
	mod_duration2();
}
