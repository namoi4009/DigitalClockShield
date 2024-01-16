/*
 * fsm_clock.h
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#ifndef INC_FSM_CLOCK_H_
#define INC_FSM_CLOCK_H_

// define buttons
#define BUTTON_MODE		0
#define BUTTON_UP		1
#define BUTTON_DOWN		2
#define BUTTON_SAVE		3

// define mode
#define INIT			4
#define AUTO			5
#define MODE_SECOND		6
#define MODE_MINUTE		7
#define MODE_HOUR		8
#define MODE_SAVE		9

// define timer for clock
#define DCLOCK			0

void fsm_clock();
void initDebug();
void auto_debug();

#endif /* INC_FSM_CLOCK_H_ */
