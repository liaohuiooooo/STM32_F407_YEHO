#include "stm32f4xx.h" 	//包含了基本的寄存器映射文件

#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
//求出位带别名区地址
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr & 0x000FFFFF)<<5)+(bitnum<<2))

// 把一个地址转换成一个指针
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
	
// 把位带别名区地址转换成指针 5 
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOA_ODR_ADDR (GPIOA_BASE+0X14)
#define GPIOB_ODR_ADDR (GPIOB_BASE+0X14)
#define GPIOC_ODR_ADDR (GPIOC_BASE+0X14)
#define GPIOD_ODR_ADDR (GPIOD_BASE+0X14)
#define GPIOE_ODR_ADDR (GPIOE_BASE+0X14)
#define GPIOF_ODR_ADDR (GPIOF_BASE+0X14)
#define GPIOG_ODR_ADDR (GPIOG_BASE+0X14)
#define GPIOH_ODR_ADDR (GPIOH_BASE+0X14)

#define PAout(n)		 BIT_ADDR(GPIOA_ODR_ADDR, n)
#define PBout(n)		 BIT_ADDR(GPIOB_ODR_ADDR, n)
#define PCout(n)		 BIT_ADDR(GPIOC_ODR_ADDR, n)
#define PDout(n)		 BIT_ADDR(GPIOD_ODR_ADDR, n)
#define PEout(n)		 BIT_ADDR(GPIOE_ODR_ADDR, n)
#define PFout(n)		 BIT_ADDR(GPIOF_ODR_ADDR, n)
#define PGout(n)		 BIT_ADDR(GPIOG_ODR_ADDR, n)
#define PHout(n)		 BIT_ADDR(GPIOH_ODR_ADDR, n)

int main()
{
	LED_GPIO_Config();
	
	GPIO_SetBits(LED_GPIO_PORT,LED_PIN);
//	GPIO_ResetBits(LED_GPIO_PORT,LED_PIN);
	PDout(6) = 0;
//	PAout(6) = 1;
	while(1)
	{
		
	}
}
