/*
 * clock_display.c
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#include "clock_display.h"
#include "main.h"
#include "software_timer.h"
uint16_t pins[12] = {LED_0_Pin, LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin,
					 LED_6_Pin, LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin};
uint16_t ports[12] = {LED_0_GPIO_Port, LED_1_GPIO_Port, LED_2_GPIO_Port, LED_3_GPIO_Port,
					  LED_4_GPIO_Port, LED_5_GPIO_Port, LED_6_GPIO_Port, LED_7_GPIO_Port,
					  LED_8_GPIO_Port, LED_9_GPIO_Port, LED_10_GPIO_Port, LED_11_GPIO_Port};

void clearAllClock()
{
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, SET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, SET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, SET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, SET);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, SET);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, SET);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, SET);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, SET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, SET);
}

void setNum(int num)
{
	clearAllClock();
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
		break;
	default:
		break;
	}
}
