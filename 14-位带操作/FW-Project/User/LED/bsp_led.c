#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	//1. 开外设时钟
	//2. 定义一个GPIO初始化结构体
	//3. 配置GPIO初始化结构体的成员
	//4. 调用GPIO初始化函数，把配置好的结构体成员的参数写入寄存器
	RCC_AHB1PeriphClockCmd(LED_AHB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = LED_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;                                                    
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);
	
//	GPIO_SetBits(LED_GPIO_PORT,GPIO_Pin_6);

}
