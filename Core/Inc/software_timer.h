/*
 * software_timer.h
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NO_OF_TIMERS	6

extern int timer_flag[NO_OF_TIMERS];

void setTimer(int duration, int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
