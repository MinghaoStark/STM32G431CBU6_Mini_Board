#ifndef __INTERRUPT_H
#define __INTERRUPT_H

#include "main.h"
#include "stm32g4xx_hal.h"
#include "stdio.h" 
#include "stdbool.h" 

struct keys
{
	unsigned char judge_sta;
	bool key_sta;
	bool l_flag;
	bool s_flag;
	uint16_t key_time;
};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif