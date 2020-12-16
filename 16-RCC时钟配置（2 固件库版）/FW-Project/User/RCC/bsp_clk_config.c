#if 0
#include "bsp_clk_config.h"

void User_SetSysClock(void)
{
	RCC_DeInit();
/******************************************************************************/
/*            PLL (clocked by HSE) used as System clock source                */
/******************************************************************************/
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* Enable HSE */
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* Wait till HSE is ready and if Time out is reached exit */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;//振荡器状态
		
    StartUpCounter++;
		
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }

  if (HSEStatus == (uint32_t)0x01)
  {
    /* Select regulator voltage output Scale 1 mode */
		/*选择电压调节为1 */
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    /* HCLK = SYSCLK / 1*/
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

   /* PCLK2 = HCLK / 2*/
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
    
    /* PCLK1 = HCLK / 4*/
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;


	/* Configure the main PLL */
	/*配置住PPL*/
    RCC->PLLCFGR = 25 | (336 << 6) | (((2 >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (7 << 24);   
    
    /* Enable the main PLL */
	
    RCC->CR |= RCC_CR_PLLON;
		
    /* Wait till the main PLL is ready */
		/* 等待主锁相环稳定 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }
   

    /* Configure Flash prefetch, Instruction ache, Data cache and wait state */
		/* 配置FLASH 预取 */
    FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;


    /* Select the main PLL as system clock source */
		/* 选择主PLL作为系统时钟*/
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* Wait till the main PLL is used as system clock source */
		/* 确保主PLL时钟选为系统时钟*/
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
    {
    }
  }
  else
  { /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
		/* HSE 启动失败，添加启动失败处理代码*/
  }
}

#endif

#include "bsp_clk_config.h"

void HSE_SetSysClock( uint32_t PLLM, uint32_t PLLN, uint32_t PLLP, uint32_t PLLQ)
{
	ErrorStatus HSE_ErrorStatus = ERROR;
	// 复位RCC所有寄存器
	RCC_DeInit();
	//使能HSE
	RCC_HSEConfig(RCC_HSE_ON);
	HSE_ErrorStatus = RCC_WaitForHSEStartUp();
	if (HSE_ErrorStatus == SUCCESS)
	{
		/* Select regulator voltage output Scale 1 mode */
		/*选择电压调节为1 */
		RCC->APB1ENR |= RCC_APB1ENR_PWREN;
		PWR->CR |= PWR_CR_VOS;
		//配置系统时钟
		RCC_HCLKConfig(RCC_SYSCLK_Div1);	//168MHz
		RCC_PCLK1Config(RCC_HCLK_Div4);		//42MHz
		RCC_PCLK2Config(RCC_HCLK_Div2);		//84MHz
		//配置锁相环倍频输出因子，PLL
		//固件库的方式配置
		RCC_PLLConfig(RCC_PLLSource_HSE, PLLM, PLLN, PLLP, PLLQ);
		
		//使能PLL
		RCC_PLLCmd(ENABLE);
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
				
		}
		
		/* Configure Flash prefetch, Instruction ache, Data cache and wait state */
		/* 配置FLASH 预取 */
		FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;
		//配置系统时钟来源
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		//检查当前系统时钟是否为PLLCK
		while( RCC_GetSYSCLKSource() != 0x08){}
	}
	else 
	{
		
	}
}

void MCO1_GPIO_INIT(void)	//MCO1 -> PA8
{
	//1. 开外设时钟
	//2. 定义一个GPIO初始化结构体
	//3. 配置GPIO初始化结构体的成员
	//4. 调用GPIO初始化函数，把配置好的结构体成员的参数写入寄存器
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);

}


void MCO2_GPIO_INIT(void)	//MCO2 -> PC9
{
	//1. 开外设时钟
	//2. 定义一个GPIO初始化结构体
	//3. 配置GPIO初始化结构体的成员
	//4. 调用GPIO初始化函数，把配置好的结构体成员的参数写入寄存器
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOC,&GPIO_InitStruct);

}

