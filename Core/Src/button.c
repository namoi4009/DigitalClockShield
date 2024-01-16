/*
 * button.c
 *
 *  Created on: Jan 3, 2024
 *      Author: tango
 */

#include "button.h"
#include "main.h"
// we aim to work with more than one buttons
#define NO_OF_BUTTONS 	4
// timer interrupt duration is 10ms , so to pass 3 second ,
// we need to jump to the interrupt service routine 300 time
#define DURATION_FOR_LONG_PRESS 	300
#define BUTTON_IS_PRESSED 	GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 	GPIO_PIN_SET
// we define 4 buffers for debouncing
static GPIO_PinState buttonBuffer0[NO_OF_BUTTONS];
static GPIO_PinState buttonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState buttonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState buttonBuffer3[NO_OF_BUTTONS];
// we define a flag for a button pressed and a flag for button long pressed
static uint8_t flagForButtonPress[NO_OF_BUTTONS];
static uint8_t flagForButtonLongPress[NO_OF_BUTTONS];
// we define counter for automatically decreasing.
static uint16_t counterForButtonLongPress[NO_OF_BUTTONS];

void initButton(){
    for (int i = 0; i < NO_OF_BUTTONS; i++) {
        buttonBuffer0[i] = BUTTON_IS_RELEASED;
        buttonBuffer1[i] = BUTTON_IS_RELEASED;
        buttonBuffer2[i] = BUTTON_IS_RELEASED;
        buttonBuffer3[i] = BUTTON_IS_RELEASED;

        flagForButtonLongPress[i] = 0;
        flagForButtonPress[i] = 0;
        counterForButtonLongPress[i] = DURATION_FOR_LONG_PRESS;
    }
}

void button_reading(void) {
    for (int i = 0; i < NO_OF_BUTTONS; i++) {
        buttonBuffer2[i] = buttonBuffer1[i];
        buttonBuffer1[i] = buttonBuffer0[i];
        switch (i) {
            case 0:
                buttonBuffer0[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
                break;
            case 1:
                buttonBuffer0[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
                break;
            case 2:
                buttonBuffer0[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
                break;
            case 3:
				buttonBuffer0[i] = HAL_GPIO_ReadPin(BUTTON_4_GPIO_Port, BUTTON_4_Pin);
				break;
        }
        if ((buttonBuffer1[i] == buttonBuffer0[i]) && (buttonBuffer1[i] == buttonBuffer2[i])) {
            if (buttonBuffer2[i] != buttonBuffer3[i]) {
                buttonBuffer3[i] = buttonBuffer2[i];
                if (buttonBuffer3[i] == BUTTON_IS_PRESSED) {
                    counterForButtonLongPress[i] = DURATION_FOR_LONG_PRESS;
                    flagForButtonPress[i] = 1;
                }
            } else {
                counterForButtonLongPress[i]--;
                if (counterForButtonLongPress[i] == 0) {
                    counterForButtonLongPress[i] = DURATION_FOR_LONG_PRESS;
                    flagForButtonLongPress[i] = 1;
                }
            }
        }
    }
}

//Checking a button is pressed or not
int is_button_pressed ( int index ){
    if( index >= NO_OF_BUTTONS ) return 0;
    if(flagForButtonPress[index] == 1){
    	flagForButtonPress[index] = 0;
    	return 1;
    }
    return 0;
}
//Checking a button is long pressed
int is_button_long_pressed( int index ){
    if( index >= NO_OF_BUTTONS ) return 0;
    if(flagForButtonLongPress[index] == 1){
    	flagForButtonLongPress[index] = 0;
    	return 1;
    }
    return 0;
}
