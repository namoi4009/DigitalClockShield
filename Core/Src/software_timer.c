/*
 * software_timer.c
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#include "software_timer.h"

#define TICK	10

int timer_counter[NO_OF_TIMERS] = {0};
int timer_flag[NO_OF_TIMERS] = {0};

void setTimer(int duration, int index)
{
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}

void timerRun()
{
	for (int i = 0; i < NO_OF_TIMERS; i++)
	{
		if (timer_counter[i] > 0)
		{
			timer_counter[i]--;
			if (timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}
