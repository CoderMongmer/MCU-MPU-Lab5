/*
 * command_parser.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Admin
 */

#include "command_parser.h"

int state = 0 ;
int forfun = 0;

void command_parser_fsm() {
	    if (strstr((const char *)buffer, "!RST#") != NULL) {
	    	state = INFO;
	    }
	    else if (strstr((const char *)buffer, "!OK#") != NULL) {
	    	state = INIT;
	    	forfun = 0;
	    }
}

void uart_communiation_fsm (){
	switch(state){
	case INIT:
		break;
	case INFO:
		if (timer1_flag == 1){
			if (forfun == 0){
				HAL_ADC_Start(&hadc1);
				HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
				HAL_ADC_Stop(&hadc1);
				forfun = 1;
			}
		ADC_value = HAL_ADC_GetValue(&hadc1);

		int len = sprintf(str," !ADC=%lu# \r\n",ADC_value);
		HAL_UART_Transmit (& huart2 , ( void *) str , len, 1000);

         memset(buffer, 0, sizeof(buffer));
         index_buffer = 0;
         setTimer_1(1000);
		}
		break;
	default:
		break;
	}
}
