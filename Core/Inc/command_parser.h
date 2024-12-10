/*
 * command_parser.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Admin
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "timer.h"
#define MAX_BUFFER_SIZE 30
#define INIT 	1
#define INFO	2

extern int state;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE]; // Use the same size as declared in main.c
extern uint8_t index_buffer;
extern uint32_t ADC_value ;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern char str[32];
void command_parser_fsm(void);
void uart_communiation_fsm(void);

#endif /* INC_COMMAND_PARSER_H_ */
