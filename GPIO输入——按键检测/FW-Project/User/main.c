#include "stm32f4xx.h" 	//包含了基本的寄存器映射文件

#include "bsp_led.h"
#include "bsp_key.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main()
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	while(1)
	{
		if(KEY_Scan(GPIOA,GPIO_Pin_0) == KEY_ON)		
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_6);	
		}			
		if(KEY_Scan(GPIOC,GPIO_Pin_13) == KEY_ON)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_7);
		}
	}
}
