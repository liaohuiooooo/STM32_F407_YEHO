
/*
	�Լ�д��ķ�������LED��
  */
#include"stm32f4xx_gpio.h"  

void Delay( uint32_t nCount); 

/**
  *   ��������ʹ�÷�װ�õĺ���������LED��
  */
int main(void)
{	
	GPIO_InitTypeDef InitStruct;
	
	/*���� GPIOF ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��*/
	RCC->AHB1ENR |= (1<<5);
														   
	InitStruct.GPIO_Pin = GPIO_Pin_6 + GPIO_Pin_7;

	InitStruct.GPIO_Mode = GPIO_Mode_OUT;


	InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
 
	InitStruct.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOF, &InitStruct);	

	

	while(1)
	{
	
	}

}

//�򵥵���ʱ��������cpuִ��������ָ�����ʱ��
//������ʱʱ�����Լ��㣬�Ժ����ǿ�ʹ�ö�ʱ����ȷ��ʱ
void Delay( uint32_t nCount)	 
{
	for(; nCount != 0; nCount--);
}


// ����Ϊ�գ�Ŀ����Ϊ��ƭ��������������
void SystemInit(void)
{	
}



///**
//  *   ������,ʹ�ýṹ��ָ�룬ֱ�ӿ��ƼĴ����ķ�ʽ�����
//			����Ȥ���Խ��ע��������һ��
//  */
//int main(void)
//{	
//	/*���� GPIOF ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��*/
//	RCC_AHB1ENR |= (1<<5);	
//	
//	/* LED �˿ڳ�ʼ�� */
//	
//	/*GPIOF MODER6���*/
//	GPIOF_MODER  &= ~( 0x03<< (2*6));	
//	/*PF6 MODER6 = 01b ���ģʽ*/
//	GPIOF_MODER |= (1<<2*6);
//	
//	/*GPIOF OTYPER6���*/
//	GPIOF_OTYPER &= ~(1<<1*6);
//	/*PF6 OTYPER6 = 0b ����ģʽ*/
//	GPIOF_OTYPER |= (0<<1*6);
//	
//	/*GPIOF OSPEEDR6���*/
//	GPIOF_OSPEEDR &= ~(0x03<<2*6);
//	/*PF6 OSPEEDR6 = 0b ����2MHz*/
//	GPIOF_OSPEEDR |= (0<<2*6);
//	
//	/*GPIOF PUPDR6���*/
//	GPIOF_PUPDR &= ~(0x03<<2*6);
//	/*PF6 PUPDR6 = 01b ����ģʽ*/
//	GPIOF_PUPDR |= (1<<2*6);
//	
//	/*PF6 BSRR�Ĵ����� BR6��1��ʹ��������͵�ƽ*/
//	GPIOF_BSRR |= (1<<16<<6);
//	
//	/*PF6 BSRR�Ĵ����� BS6��1��ʹ��������ߵ�ƽ*/
//	//GPIOF_BSRR |= (1<<6);

//	while(1);

//}


/*********************************************END OF FILE**********************/

