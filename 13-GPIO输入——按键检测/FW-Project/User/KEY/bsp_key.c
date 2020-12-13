#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	//1. ������ʱ��
	//2. ����һ��GPIO��ʼ���ṹ��
	//3. ����GPIO��ʼ���ṹ��ĳ�Ա
	//4. ����GPIO��ʼ�������������úõĽṹ���Ա�Ĳ���д��Ĵ���
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
