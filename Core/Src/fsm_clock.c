	/*
 * fsm_clock.c
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#include "fsm_clock.h"
#include "button.h"
#include "software_timer.h"
#include "clock_display.h"
#include "main.h"

int state = INIT;
int second = 10, minute = 4	, hour = 5;
int t_second = 0, t_minute = 0, t_hour = 0;

#define ONE_SECOND 		1000

void display(int s, int m, int h)
{
	clearAllClock();
	setNum(s / 5);
	setNum(m / 5);
	setNum(h);
}

void initDebug()
{
	clearAllClock();
	setTimer(500, 4);
	HAL_GPIO_WritePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin, RESET);
}

void auto_debug()
{
	if (timer_flag[4] == 1)
	{
		setTimer(500, 4);
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
	}
}

void inc_t_second()
{
	t_second++;
	if (t_second == 60)
	{
		t_second = 0;
	}
}

void inc_t_minute()
{
	t_minute++;
	if (t_minute == 60)
	{
		t_minute = 0;
	}
}
void inc_t_hour()
{
	t_hour++;
	if (t_hour == 12)
	{
		t_hour = 0;
	}
}

void dec_t_second()
{
	t_second--;
	if (t_second == -1)
	{
		t_second = 59;
	}
}

void dec_t_minute()
{
	t_minute--;
	if (t_minute == -1)
	{
		t_minute = 59;
	}
}

void dec_t_hour()
{
	t_hour--;
	if (t_hour == -1)
	{
		t_hour = 11;
	}
}

void fsm_clock()
{
	switch(state)
	{
	case INIT:
		clearAllClock();
		setTimer(ONE_SECOND, DCLOCK);
		display(second, minute, hour);
		state = AUTO;
		break;
	case AUTO:
		if (timer_flag[DCLOCK] == 1)
		{
			second++;
			setTimer(ONE_SECOND, DCLOCK);
			timer_flag[DCLOCK] = 0;
			if (second == 60)
			{
				second = 0;
				minute++;
				if (minute == 60)
				{
					minute = 0;
					hour++;
					if (hour == 12)
					{
						hour = 0;
					}
				}
			}
		}

		// check if mode button is pressed
		if (is_button_pressed(BUTTON_MODE))
		{
			state = MODE_SECOND;
			t_second = second;
			t_minute = minute;
			t_hour = hour;
		}

		display(second, minute, hour);
		break;
	case MODE_SECOND:
		display(t_second, t_minute, t_hour);
		if (is_button_pressed(BUTTON_UP) && !is_button_pressed(BUTTON_DOWN))
		{
			inc_t_second();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_UP) && !is_button_long_pressed(BUTTON_DOWN))
//		{
//			setTimer(300, 1);
//			if (timer_flag[1])
//			{
//				timer_flag[1] = 0;
//				inc_t_second();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_DOWN) && !is_button_pressed(BUTTON_UP))
		{
			dec_t_second();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_DOWN) && !is_button_long_pressed(BUTTON_UP))
//		{
//			setTimer(300, 2);
//			if (timer_flag[2])
//			{
//				timer_flag[2] = 0;
//				dec_t_second();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_MODE))
		{
			state = MODE_MINUTE;
		}
		if (is_button_pressed(BUTTON_SAVE))
		{
			state = MODE_SAVE;
		}
		break;
	case MODE_MINUTE:
		display(t_second, t_minute, t_hour);
		if (is_button_pressed(BUTTON_UP) && !is_button_pressed(BUTTON_DOWN))
		{
			inc_t_minute();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_UP) && !is_button_long_pressed(BUTTON_DOWN))
//		{
//			setTimer(300, 1);
//			if (timer_flag[1])
//			{
//				timer_flag[1] = 0;
//				inc_t_minute();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_DOWN) && !is_button_pressed(BUTTON_UP))
		{
			dec_t_minute();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_DOWN) && !is_button_long_pressed(BUTTON_UP))
//		{
//			setTimer(300, 2);
//			if (timer_flag[2])
//			{
//				timer_flag[2] = 0;
//				dec_t_minute();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_MODE))
		{
			state = MODE_HOUR;
		}
		if (is_button_pressed(BUTTON_SAVE))
		{
			state = MODE_SAVE;
		}
		break;
	case MODE_HOUR:
		display(t_second, t_minute, t_hour);
		if (is_button_pressed(BUTTON_UP) && !is_button_pressed(BUTTON_DOWN))
		{
			inc_t_hour();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_UP) && !is_button_long_pressed(BUTTON_DOWN))
//		{
//			setTimer(300, 1);
//			if (timer_flag[1])
//			{
//				timer_flag[1] = 0;
//				inc_t_hour();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_DOWN) && !is_button_pressed(BUTTON_UP))
		{
			dec_t_hour();
			display(t_second, t_minute, t_hour);
		}
//		if (is_button_long_pressed(BUTTON_DOWN) && !is_button_long_pressed(BUTTON_UP))
//		{
//			setTimer(300, 2);
//			if (timer_flag[2])
//			{
//				timer_flag[2] = 0;
//				dec_t_hour();
//				display(t_second, t_minute, t_hour);
//			}
//		}
		if (is_button_pressed(BUTTON_MODE))
		{
			setTimer(1000, DCLOCK);
			state = AUTO;
		}
		if (is_button_pressed(BUTTON_SAVE))
		{
			state = MODE_SAVE;
		}
		break;
	case MODE_SAVE:
		second = t_second;
		minute = t_minute;
		hour = t_hour;
		setTimer(ONE_SECOND, DCLOCK);
		state = AUTO;
		break;
	default:
		break;
	}
}
