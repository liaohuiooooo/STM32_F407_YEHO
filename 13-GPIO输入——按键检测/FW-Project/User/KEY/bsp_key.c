#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	//1. 开外设时钟
	//2. 定义一个GPIO初始化结构体
	//3. 配置GPIO初始化结构体的成员
	//4. 调用GPIO初始化函数，把配置好的结构体成员的参数写入寄存器
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_KeyStruct_1;
	
	GPIO_KeyStruct_1.GPIO_Pin = GPIO_Pin_0;
	GPIO_KeyStruct_1.GPIO_Mode = GPIO_Mode_IN;
	//GPIO_KeyStruct.GPIO_Speed = GPIO_Low_Speed;
	//GPIO_KeyStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_KeyStruct_1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&GPIO_KeyStruct_1);
	
	GPIO_InitTypeDef GPIO_KeyStruct_2;
	
	GPIO_KeyStruct_2.GPIO_Pin = GPIO_Pin_13;
	GPIO_KeyStruct_2.GPIO_Mode = GPIO_Mode_IN;
	//GPIO_KeyStruct.GPIO_Speed = GPIO_Low_Speed;
	//GPIO_KeyStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_KeyStruct_2.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&GPIO_KeyStruct_2);

}

uint8_t KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin));
		return KEY_ON;
	}
	else return KEY_OFF;
}
