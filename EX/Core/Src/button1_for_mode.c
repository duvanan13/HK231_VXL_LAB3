/*
 * button1_for_mode.c
 *
 *  Created on: 13 Sep 2023
 *      Author: duvan
 */
#include "button1_for_mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "mode4.h"
void mode_run(){
	switch(status){
		case 0:
			if(isButtonPressed(0)){
				status = 1;
				modamber = 2;
				modgreen= 3;
				modred= 5;
				counter0 = modamber + modgreen + modred;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				x = modred/10;
				y = modred%10;
				x1 = modgreen/10;
				t1 = modgreen%10;
				x2 = modamber/10;
				y2 = modamber%10;
			}
			break;
		case 1:
			mode1_run();
			if(isButtonPressed(0)){
				status = 2;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 2:
			mode2_run();
			if(isButtonPressed(0)){
				status = 3;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 3:
			mode3_run();
			if(isButtonPressed(0)){
				status = 4;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 4:
			mode4_run();
			if(isButtonPressed(0)){
				x = modred/10;
				y = modred%10;
				x1 = modgreen/10;
				t1 = modgreen%10;
				x2 = modamber/10;
				y2 = modamber%10;
				counter0 = modamber+modgreen+modred;
				status = 1;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		default:
			break;
	}
}
