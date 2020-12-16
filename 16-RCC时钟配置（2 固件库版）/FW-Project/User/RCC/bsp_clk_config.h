#ifndef __BSP_CLK_CONFIG_H__
#define __BSP_CLK_CONFIG_H__

#include "stm32f4xx.h"

void User_SetSysClock(void);
void HSE_SetSysClock( uint32_t PLLM, uint32_t PLLN, uint32_t PLLP, uint32_t PLLQ);
void MCO1_GPIO_INIT(void);
void MCO2_GPIO_INIT(void);
#endif
