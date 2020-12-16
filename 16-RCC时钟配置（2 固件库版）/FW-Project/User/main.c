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
	HSE_SetSysClock(25, 336, 2, 7); // M=25, N=336,P=2(AHB,APBx来源),Q=7(Q输出一定为48MHz)
	
	RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_1);
	RCC_MCO2Config(RCC_MCO2Source_SYSCLK, RCC_MCO2Div_1);
	
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
		Delay(0xfffff);
		GPIO_SetBits(GPIOF,GPIO_Pin_6);
		Delay(0xfffff);
	}
}
