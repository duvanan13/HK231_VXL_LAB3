/*
 * mode3.c
 *
 *  Created on: 15 Sep 2023
 *      Author: duvan
 */
#include "mode3.h"

void ToggleLedRed3(){
	HAL_GPIO_TogglePin(AMBER_GPIO_Port, AMBER_Pin);
	HAL_GPIO_TogglePin(AMBER2_GPIO_Port, AMBER2_Pin);
	HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, 0);
	HAL_Delay(500);
}
void mode_led3(){
	int x = modamber/10;
	int y = modamber%10;

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	display7SEG(0);
	display7SEG_2(3);
	HAL_Delay(150);

	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
	display7SEG(x);
	display7SEG_2(y);
	HAL_Delay(150);

}
void mod_duration3(){
	if(isButtonPressed(1)==1&&status==3){
		modamber++;
		int x = modamber/10;
		int y = modamber%10;
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		display7SEG(x);
		display7SEG_2(y);
	}
	if(isButtonPressed(2)==1&&status==3){
		x1 = modamber/10;
		t1 = modamber%10;
	}
}
void mode3_run(){
	mode_led3();
	ToggleLedRed3();
	mod_duration3();
}
