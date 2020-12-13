#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

#include "stm32f4xx.h"
#define KEY_ON 1
#define KEY_OFF 0
void KEY_GPIO_Config(void);
uint8_t KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif /* __BSP_KEY_H__ */
