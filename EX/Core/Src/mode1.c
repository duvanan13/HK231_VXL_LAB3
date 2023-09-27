/*
 * mode1.c
 *
 *  Created on: 13 Sep 2023
 *      Author: duvan
 */

#include "mode1.h"

void mode1_run(){
	if (counter0 > modred) {
		  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		  display7SEG_2(y--);
		  display7SEG(x);
		  if(x>=1){
			  if(y<0) {
				  y = 9;
				  x--;
			  }
		  }
		  else{
			  if(y<=0){
				  y = modred%10;
				  x = modred/10;
			  }
		  }
		  HAL_Delay(150);
		  if (counter0 > (modred+modamber)) {
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			  display7SEG_2(t1--);
			  display7SEG(x1);
			  if(x1>=1){
				  if(t1<0) {
					  t1 = 9;
					  x1--;
				  }
			  }
			  else{
				  if(t1<=0){
					  t1 = modgreen%10;
					  x1 = modgreen/10;
				  }
			  }
			  HAL_Delay(150);
		  } else {
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			  display7SEG_2(y2--);
			  display7SEG(x2);
			  if(x2>=1){
				  if(y2<0) {
					  y2 = 9;
					  x2--;
				  }
			  }
			  else{
				  if(y2<=0){
					  y2 = modamber%10;
					  x2 = modamber/10;
				  }
			  }
			  HAL_Delay(150);
		  }
	} else {
		  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		  display7SEG_2(y--);
		  display7SEG(x);
		  if(x>=1){
			  if(y<0) {
				  y = 9;
				  x--;
			  }
		  }
		  else{
			  if(y<=0){
				  y = modred%10;
				  x = modred/10;
			  }
		  }
		  HAL_Delay(150);
		  if (counter0 > modamber) {
			  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			  display7SEG_2(t1--);
			  display7SEG(x1);
			  if(x1>=1){
				  if(t1<0) {
					  t1 = 9;
					  x1--;
				  }
			  }
			  else{
				  if(t1<=0){
					  t1 = modgreen%10;
					  x1 = modgreen/10;
				  }
			  }
			  HAL_Delay(150);
		  } else {
			  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			  display7SEG_2(y2--);
			  display7SEG(x2);
			  if(x2>=1){
				  if(y2<0) {
					  y2 = 9;
					  x2--;
				  }
			  }
			  else{
				  if(y2<=0){
					  y2 = modamber%10;
					  x2 = modamber/10;
				  }
			  }
			  HAL_Delay(150);
		  }
  }
  counter0--;
  if (counter0 <= 0) counter0 = modamber+modgreen+modred;
  HAL_Delay(1000);
}
