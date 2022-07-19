//#include "color.h"
//#include "stm32f10x_it.h"
//#include "delay.h"
//#include "sys.h"
//#include "usart.h"


//extern char flag;
//extern int red,green,blue;
//u16 red_bace=1835,green_bace=2198,blue_bace=2185; //三色基准值，根据实际测量确定
//u16 redm,greenm,bluem;
///**********************************************************
//** 函数名:TIM2_config
//** 功能描述: 定时器2配置
//** 输入参数: 无
//** 输出参数: 无
//** 返	 回: 无
//***********************************************************/
//void TIM2_config(void)
//{

//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能TIM6时钟

//	/*基础设置*/
//	TIM_TimeBaseStructure.TIM_Period = 200-1;//计数值200 
//	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;    	//预分频,此值+1为分频的除数
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//采样分频系数0
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

//	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE); //使能更新溢出中断
//	TIM_Cmd(TIM2, DISABLE);//失能TIM2
//}

///**********************************************************
//** 函数名:TCS230_GPIO_Config
//** 功能描述: TCS230的GPIO初始化配置
//** 输入参数: 无
//** 输出参数: 无
//** 返	 回: 无
//***********************************************************/
//void TCS230_GPIO_Config(void)
//{
//	//PB10--S2,PB11--S3，推挽输出
//  	RCC->APB2ENR|=1<<3;//使能PORTB时钟							 
//	GPIOB->CRH&=0XFFFF00FF;
//	GPIOB->CRH|=0X00003300;//PB10,PB11推挽输出

//	//PA2--TCS230中断输入引脚，上拉输入
//	RCC->APB2ENR|=1<<2;//使能PORTA时钟							 
//	GPIOA->CRL&=0XFFFFF0FF;
//	GPIOA->CRL|=0X00000800;//PA0上拉输入
//	GPIOA->ODR|=1<<2;//PA2置1,上拉
//}
///**********************************************************
//** 函数名:EXTI_Config
//** 功能描述: 外部中断配置
//** 输入参数: 无
//** 输出参数: 无
//** 返	 回: 无
//***********************************************************/
//void EXTI_Config(void)
//{
//	EXTI_InitTypeDef EXTI_InitStructure;

//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);	//PA2接TCS230的中断输入
//	EXTI_ClearITPendingBit(EXTI_Line2);//外部中断线2

//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发
//	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);
//}
///**********************************************************
//** 函数名:NVIC_Config
//** 功能描述: 中断分组及优先级配置
//** 输入参数: 无
//** 输出参数: 无
//** 返	 回: 无
//***********************************************************/
//void NVIC_Config(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure; 
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
//												
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;	//外部中断线2
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	  //
//	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
//	NVIC_Init(&NVIC_InitStructure);

//  	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//定时器2中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);	 
//}

///**********************************************************
//** 函数名:RGB565
//** 功能描述: 将采集的R、G、B三种分量颜色转换为RGB565格式的16位颜色值
//** 输入参数: red--采集的红色颜色值
//			 green--采集的绿色颜色值
//			 blue--采集的蓝色颜色值
//** 输出参数: 无
//** 返	 回: 返回RGB565格式的16位颜色值
//***********************************************************/
//u16 RGB565(int red,int green,int blue)
//{
//	int R1,G1,B1;
//	unsigned char r,g,b;
//	int RGB;
//	R1=(int)(255*(float)red/red_bace); //red_bace参考值1835
//	G1=(int)(255*(float)green/green_bace); //green_bace参考值2198
//	B1=(int)(255*(float)blue/blue_bace); //blue_bace参考值2185	
//	RGB=(R1<<16)|(G1<<8)|B1;
//	b = ( RGB >> (0+3) ) & 0x1f;		// 取蓝色的高5位
//  	g = ( RGB >> (8+2) ) & 0x3f;		// 取绿色的高6位
//  	r = ( RGB >> (16+3)) & 0x1f;		// 取红色的高5位
//	return( (r<<11) + (g<<5) + (b<<0) );	
//}
///**********************************************************
//** 函数名:main
//** 功能描述: 主函数，将采集到的颜色显示到TFT上
//** 输入参数: 无
//** 输出参数: 无·                  
//** 返	 回: 无
//***********************************************************/



//u16 COLOUR()
//{	
//	
//	
//	u16 e=0,R,G,B;
//	u16 rgb_value=0;
//	


//	
//	printf("b=%d\n",65536);
//	//下面进行光的白平衡调节，得到三色基准值作为采集其它颜色的基准
//	//在测量前，先将TCS230对准作为基准的白色物体等待测量
//	delay_ms(1000);	//延时，等待颜色传感器准备好
//	TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	TIM_Cmd(TIM2, ENABLE);//使能TIM2
//	
//	do //连续采集10次取平均值
//	{
//		if(flag==4)//三种颜色采集完成
//		{
//			e++;
//					if(e>=5) //取后面测得的6个数据
//					{
//						redm+=red;
//						greenm+=green;
//						bluem+=blue;
//					}
//			delay_ms(100);
//			flag=1;//标志置1，开始下一次测量
//			red=0; //颜色分量计数值清0
//		 	green=0;
//		 	blue=0;
//			TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
//			TIM_Cmd(TIM2, ENABLE); //使能TIM2
//			
//		}
//	}
//	while(e<10);
//	//得到白平衡调整的三色颜色分量，作为后面测量时的颜色基准值
//	red_bace=redm/6; //红色基准值
//	green_bace=greenm/6; //绿色基准值
//	blue_bace=bluem/6;	  //蓝色基准值 
//	//串口输出白平衡调整得到的三色颜色分量
//	printf(" rb=%d  gb=%d  bb=%d\n",red_bace,green_bace,blue_bace);

//  	while(1)
//	{
//		if(flag==4)	//三种颜色采集完成
//		{
//			R=red;
//			G=green;
//			B=blue;
//			
//			

//			printf(" r=%d  g=%d  b=%d\n",red,green,blue);
//			printf(" R=%d  G=%d  B=%d\n",R,G,B);
//			rgb_value=RGB565(red,green,blue);//将采集的三色颜色值分量转换为RGB565格式的16位颜色值
//			printf(" rgb_value=%d\n",rgb_value);
//			delay_ms(100);
//			
//			flag=1;//标志置1，开始下一次测量
//			red=0;	//颜色分量计数值清0
//		 	green=0;
//		 	blue=0;
//			TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
//			TIM_Cmd(TIM2, ENABLE); //使能TIM2
//           if(R<560&&G>370&&B<500)
//			{
//				return 1;
//			}
//			if(R>560&&G>600&&B>700)
//			{
//				return 2;
//			}
//			if(R>560&&G<400&&B<700)
//			{
//				return 3;
//			}
//			if(R<400&&G<300&&B<560)
//			{ 
//				return 4;
//			}
//			if(R<345&&G<330&&B>400)
//			{
//				return 5;
//			}



//			}


//	}

//			
//}
//											  						  
  
#include "color.h"
#include "stm32f10x_it.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

extern char flag;
extern int red,green,blue;
u16 red_bace=1835,green_bace=2198,blue_bace=2185; //三色基准值，根据实际测量确定
u16 redm,greenm,bluem;
int min,mid,m,n,Max;
/**********************************************************
** 函数名:TIM2_config
** 功能描述: 定时器2配置
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void TIM2_config(void)
{

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能TIM6时钟

	/*基础设置*/
	TIM_TimeBaseStructure.TIM_Period = 200-1;//计数值200 
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;    	//预分频,此值+1为分频的除数
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//采样分频系数0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE); //使能更新溢出中断
	TIM_Cmd(TIM2, DISABLE);//失能TIM2
}

/**********************************************************
** 函数名:TCS230_GPIO_Config
** 功能描述: TCS230的GPIO初始化配置
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void TCS230_GPIO_Config(void)
{
	//PB10--S2,PB11--S3，推挽输出
  RCC->APB2ENR|=1<<3;//使能PORTB时钟							 
	GPIOB->CRH&=0XFFFF00FF;
	GPIOB->CRH|=0X00003300;//PB10,PB11推挽输出

	//PA2--TCS230中断输入引脚，上拉输入
	RCC->APB2ENR|=1<<2;//使能PORTA时钟							 
	GPIOA->CRL&=0XFFFFF0FF;
	GPIOA->CRL|=0X00000800;//PA0上拉输入
	GPIOA->ODR|=1<<2;//PA2置1,上拉
}
/**********************************************************
** 函数名:EXTI_Config
** 功能描述: 外部中断配置
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);	//PA2接TCS230的中断输入
	EXTI_ClearITPendingBit(EXTI_Line2);//外部中断线2

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}
/**********************************************************
** 函数名:NVIC_Config
** 功能描述: 中断分组及优先级配置
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
												
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;	//外部中断线2
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	  //
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
	NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//定时器2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	 
}

/**********************************************************
** 函数名:RGB565
** 功能描述: 将采集的R、G、B三种分量颜色转换为RGB565格式的16位颜色值
** 输入参数: red--采集的红色颜色值
			 green--采集的绿色颜色值
			 blue--采集的蓝色颜色值
** 输出参数: 无
** 返	 回: 返回RGB565格式的16位颜色值
***********************************************************/
u16 RGB565(int red,int green,int blue)
{
	int R1,G1,B1;
	unsigned char r,g,b;
	int RGB;
	R1=(int)(255*(float)red/red_bace); //red_bace参考值1835
	G1=(int)(255*(float)green/green_bace); //green_bace参考值2198
	B1=(int)(255*(float)blue/blue_bace); //blue_bace参考值2185	
	RGB=(R1<<16)|(G1<<8)|B1;
	b = ( RGB >> (0+3) ) & 0x1f;		// 取蓝色的高5位
  	g = ( RGB >> (8+2) ) & 0x3f;		// 取绿色的高6位
  	r = ( RGB >> (16+3)) & 0x1f;		// 取红色的高5位
	return( (r<<11) + (g<<5) + (b<<0) );	
}
u16 COLOUR()
{		
	u16 e=0,R,G,B;
   u16 rgb_value=0;	
	//printf("\rb=%d\n",65536);		//下面进行光的白平衡调节，得到三色基准值作为采集其它颜色的基准，在测量前，先将TCS230对准作为基准的白色物体等待测量
	TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
	NVIC_EnableIRQ(EXTI2_IRQn);
	TIM_Cmd(TIM2, ENABLE);//使能TIM2	
	do //连续采集10次取平均值
	{
		if(flag==4)//三种颜色采集完成
		{
			e++;
			if(e>=5) //取后面测得的6个数据
			{
				redm+=red;
				greenm+=green;
				bluem+=blue;
			}
			delay_ms(100);
			flag=1;//标志置1，开始下一次测量
			red=0; //颜色分量计数值清0
		 	green=0;
		 	blue=0;
			TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
			TIM_Cmd(TIM2, ENABLE); //使能TIM2
	
		}
	}
	while(e<10);
	//得到白平衡调整的三色颜色分量，作为后面测量时的颜色基准值
	red_bace=redm/6; //红色基准值
	green_bace=greenm/6; //绿色基准值
	blue_bace=bluem/6;	  //蓝色基准值 
	//串口输出白平衡调整得到的三色颜色分量
	//printf(" rb=%d  gb=%d  bb=%d\n",red_bace,green_bace,blue_bace);
  while(1)
	{
		n=0;
		if(flag==4)	//三种颜色采集完成
		{
			R=red;
			G=green;
			B=blue;
			//printf(" r=%d  g=%d  b=%d\n",red,green,blue);
			printf(" R=%d  G=%d  B=%d\r\n",R,G,B);
			rgb_value=RGB565(red,green,blue);//将采集的三色颜色值分量转换为RGB565格式的16位颜色值
			//printf(" rgb_value=%d\n",rgb_value);
			delay_ms(100);
			flag=1;//标志置1，开始下一次测量
			red=0;	//颜色分量计数值清0
		 	green=0;
		 	blue=0;
			TIM_SetCounter(TIM2,0);//将TIM2计数初始值设为0
			TIM_Cmd(TIM2, ENABLE); //使能TIM2
//    if(R>240&&R<380&&G>240&&G<344&&B<440&&B>330)
//				return 4;//黑
//			}	

//			else if(R>550&&R<1100&&G>290&&G<435&&B<600&&B>400)
//			{
//				return 3;//红
//			}
//			else if(((B-G<100))&&(R>260&&R<700&&G>240&&G<930&&B<700&&B>320))
//			{
//				return 1;//绿
//			}
//			else if((R>230&&R<550&&G>255&&G<550&&B<1000&&B>420))
//			{
//				return 5;//蓝
//			}	
//		  else if(R>450&&R<1250&&G>400&&G<1250&&B<1600&&B>450)
//			{
//				return 2;//白
//			}
//      if((B-G>50)&&(R-G>0)&&(R>220&&R<750&&G>210&&G<600&&B<700&&B>300))
//			{
//			return 4;//黑
//			}	
  
						 if(G>R)
			 Max=G;
		 else 
			 Max=R;
		 if(Max<B)
			 Max=B;
		  if(R>400&&G<300)
		 {
             printf("红");
             return 3;
		 }
		 else if(R>400&&G>400&&B>400)
		 {
             printf("白");
             return 2;
		 }
           else if(B-G<20)
			{
                  printf("绿");  
				return 1;//绿
			}
		 else if(G<210&&R<230&&B<210)
		 {
             printf("黑");
             return 4;
		 }
		 else if(Max==R)
		 {
             printf("黑");   
             return 4; 
		 }
       
//		 else if(Max==G)
//	 {
//             printf("绿");   
//             return 1;
//		 }
		 else if(Max==B)
		 {
             printf("蓝");
             return 5;
		 }

	
	}
		
		
	}	

}


