/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "stm32f10x.h"
 
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/


int red,green,blue;
char flag=1;

/**********************************************************
** 函数名:EXTI2_IRQHandler
** 功能描述: 外部中断线2中断处理程序
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void EXTI2_IRQHandler(void)
{	
	if(EXTI_GetITStatus(EXTI_Line2) != RESET) //如果有中断产生
	 {	 
		EXTI_ClearITPendingBit(EXTI_Line2); //清除中断标志位 	
		if(flag==1)	  //允许红色通过
		{
		   GPIOB->BRR=GPIO_Pin_10; //PB10=0,即s2=0
		   GPIOB->BRR=GPIO_Pin_11; //PB11=0,s3=0
		   red++; //增加红色分量值
		}
		else if(flag==2)//允许蓝色通过 
		{
		   GPIOB->BRR=GPIO_Pin_10; //PB10=0,s2=0
		   GPIOB->BSRR=GPIO_Pin_11;//PB11=1,s3=1
		   blue++; //增加蓝色分量值
		}
		else if(flag==3) //允许绿色通过
		{
		   GPIOB->BSRR=GPIO_Pin_10; //PB10=1,s2=1
		   GPIOB->BSRR=GPIO_Pin_11; //PB11=1,s3=1
		   green++;	//增加绿色分量值
		}
		  
	 }	
	

}
/**********************************************************
** 函数名:TIM2_IRQHandler
** 功能描述: 定时器2中断处理程序
** 输入参数: 无
** 输出参数: 无
** 返	 回: 无
***********************************************************/
void TIM2_IRQHandler(void)
{
   if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//
	{
//		printf("hello\n");
		/*必须清空标志位*/
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		flag++;	//定时时间到，切换允许的颜色值
		if(flag>3)//三种颜色值已采集完成，关闭定时器，计算得到颜色
		{	
			TIM_Cmd(TIM2, DISABLE);
			flag=4;
		}
	}
}
