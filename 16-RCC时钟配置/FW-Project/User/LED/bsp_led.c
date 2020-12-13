#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	//1. ������ʱ��
	//2. ����һ��GPIO��ʼ���ṹ��
	//3. ����GPIO��ʼ���ṹ��ĳ�Ա
	//4. ����GPIO��ʼ�������������úõĽṹ���Ա�Ĳ���д��Ĵ���
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 + GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOF,&GPIO_InitStruct);
	
	GPIO_SetBits(GPIOF,GPIO_Pin_6);
	GPIO_SetBits(GPIOF,GPIO_Pin_7);
}
