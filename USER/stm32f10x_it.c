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
** ������:EXTI2_IRQHandler
** ��������: �ⲿ�ж���2�жϴ������
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void EXTI2_IRQHandler(void)
{	
	if(EXTI_GetITStatus(EXTI_Line2) != RESET) //������жϲ���
	 {	 
		EXTI_ClearITPendingBit(EXTI_Line2); //����жϱ�־λ 	
		if(flag==1)	  //�����ɫͨ��
		{
		   GPIOB->BRR=GPIO_Pin_10; //PB10=0,��s2=0
		   GPIOB->BRR=GPIO_Pin_11; //PB11=0,s3=0
		   red++; //���Ӻ�ɫ����ֵ
		}
		else if(flag==2)//������ɫͨ�� 
		{
		   GPIOB->BRR=GPIO_Pin_10; //PB10=0,s2=0
		   GPIOB->BSRR=GPIO_Pin_11;//PB11=1,s3=1
		   blue++; //������ɫ����ֵ
		}
		else if(flag==3) //������ɫͨ��
		{
		   GPIOB->BSRR=GPIO_Pin_10; //PB10=1,s2=1
		   GPIOB->BSRR=GPIO_Pin_11; //PB11=1,s3=1
		   green++;	//������ɫ����ֵ
		}
		  
	 }	
	

}
/**********************************************************
** ������:TIM2_IRQHandler
** ��������: ��ʱ��2�жϴ������
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void TIM2_IRQHandler(void)
{
   if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//
	{
//		printf("hello\n");
		/*������ձ�־λ*/
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		flag++;	//��ʱʱ�䵽���л��������ɫֵ
		if(flag>3)//������ɫֵ�Ѳɼ���ɣ��رն�ʱ��������õ���ɫ
		{	
			TIM_Cmd(TIM2, DISABLE);
			flag=4;
		}
	}
}
