#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f4xx.h"

#define LED_AHB		RCC_AHB1Periph_GPIOD
#define LED_PIN		GPIO_Pin_6
#define LED_GPIO_PORT	GPIOD

void LED_GPIO_Config(void);

#endif /* __BSP_LED_H__ */
