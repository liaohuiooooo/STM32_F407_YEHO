#include "stm32f4xx.h" 	//包含了基本的寄存器映射文件

#include "bsp_led.h"
#include "exti.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main()
{
	LED_GPIO_Config();
	EXTI_Key_Config();
	while(1)
	{
		
	}
}
