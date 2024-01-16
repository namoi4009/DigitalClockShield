/*
 * button.h
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

void initButton();
void button_reading ( void ) ;
int is_button_pressed ( int index ) ;
int is_button_long_pressed( int index ) ;

#endif /* INC_BUTTON_H_ */
