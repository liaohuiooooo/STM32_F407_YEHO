#include "exti.h"


static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 配置NVIC为优先级组1 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置中断源：按键1 */
  NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  /* 配置抢占优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 配置子优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断通道 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* 配置中断源：按键2，其他使用上面相关配置 */  
  NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Key_Config(void)
{
	//1. 初始化要链接EXTI的GPIO
	//2. 初始化EXTI用于产生中断
	//3. 初始化NVIC,处理中断
	//4. 编写中断服务函数
	//5. 编写main()函数的
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
	
	// 1
	/*开启按键GPIO口的时钟*/
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK ,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
	/* 设置引脚为输入模式 */ 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	    		
	/* 设置引脚不上拉也不下拉 */
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/* 使用上面的结构体初始化按键 */
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure); 
	/* 选择按键2的引脚 */ 
	GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN;  
	/* 其他配置与上面相同 */
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);      

	// 2 
	/* 使能 SYSCFG 时钟 ，使用GPIO外部中断时必须使能SYSCFG时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	/* 连接 EXTI 中断源 到key1引脚 */
	SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,KEY1_INT_EXTI_PINSOURCE);
	/* 连接 EXTI 中断源 到key2 引脚 */
	SYSCFG_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,KEY2_INT_EXTI_PINSOURCE);
	
	/* 选择 EXTI 中断源 */
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	/* 中断模式 */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 下降沿触发 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
	/* 使能中断/事件线 */
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* 选择 EXTI 中断源 */
	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 上升沿触发 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// 3 
	NVIC_Configuration();
}
