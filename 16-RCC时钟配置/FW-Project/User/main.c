#include "stm32f4xx.h" 	//包含了基本的寄存器映射文件

#include "bsp_led.h"
#include "bsp_clk_config.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main()
{
	LED_GPIO_Config();
	User_SetSysClock();
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
		Delay(0xfffff);
		GPIO_SetBits(GPIOF,GPIO_Pin_6);
		Delay(0xfffff);
//		GPIO_ResetBits(GPIOF,GPIO_Pin_7);
//		Delay(0xfffff);
//		GPIO_SetBits(GPIOF,GPIO_Pin_7);
//		Delay(0xfffff);
	}
}
