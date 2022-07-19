#include "led.h"
#include "pwm.h"
#include "stm32f10x_tim.h"
//LED IO初始化
void LED_Init(void)
{
 
   GPIO_InitTypeDef  GPIO_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	 //使能PA,PB,PC端口时钟
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11| GPIO_Pin_12| GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
    //PA.11至15 端口配置
 GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IN_FLOATING; 		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA


 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	
 GPIO_Init(GPIOB, &GPIO_InitStructure);	  				
// PB设置	
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_3|GPIO_Pin_2|GPIO_Pin_0|GPIO_Pin_13;
GPIO_Init(GPIOC, &GPIO_InitStructure);	
//PC设置
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 //LED0-->PA.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
 GPIO_SetBits(GPIOC,GPIO_Pin_4);						 //PA.8 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	    		 //LED1-->PD.2 端口配置, 推挽输出
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_5); 						 //PD.2 输出高 
}
