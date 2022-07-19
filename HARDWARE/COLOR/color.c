//#include "color.h"
//#include "stm32f10x_it.h"
//#include "delay.h"
//#include "sys.h"
//#include "usart.h"


//extern char flag;
//extern int red,green,blue;
//u16 red_bace=1835,green_bace=2198,blue_bace=2185; //��ɫ��׼ֵ������ʵ�ʲ���ȷ��
//u16 redm,greenm,bluem;
///**********************************************************
//** ������:TIM2_config
//** ��������: ��ʱ��2����
//** �������: ��
//** �������: ��
//** ��	 ��: ��
//***********************************************************/
//void TIM2_config(void)
//{

//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʹ��TIM6ʱ��

//	/*��������*/
//	TIM_TimeBaseStructure.TIM_Period = 200-1;//����ֵ200 
//	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//������Ƶϵ��0
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

//	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE); //ʹ�ܸ�������ж�
//	TIM_Cmd(TIM2, DISABLE);//ʧ��TIM2
//}

///**********************************************************
//** ������:TCS230_GPIO_Config
//** ��������: TCS230��GPIO��ʼ������
//** �������: ��
//** �������: ��
//** ��	 ��: ��
//***********************************************************/
//void TCS230_GPIO_Config(void)
//{
//	//PB10--S2,PB11--S3���������
//  	RCC->APB2ENR|=1<<3;//ʹ��PORTBʱ��							 
//	GPIOB->CRH&=0XFFFF00FF;
//	GPIOB->CRH|=0X00003300;//PB10,PB11�������

//	//PA2--TCS230�ж��������ţ���������
//	RCC->APB2ENR|=1<<2;//ʹ��PORTAʱ��							 
//	GPIOA->CRL&=0XFFFFF0FF;
//	GPIOA->CRL|=0X00000800;//PA0��������
//	GPIOA->ODR|=1<<2;//PA2��1,����
//}
///**********************************************************
//** ������:EXTI_Config
//** ��������: �ⲿ�ж�����
//** �������: ��
//** �������: ��
//** ��	 ��: ��
//***********************************************************/
//void EXTI_Config(void)
//{
//	EXTI_InitTypeDef EXTI_InitStructure;

//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);	//PA2��TCS230���ж�����
//	EXTI_ClearITPendingBit(EXTI_Line2);//�ⲿ�ж���2

//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//�½��ش���
//	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);
//}
///**********************************************************
//** ������:NVIC_Config
//** ��������: �жϷ��鼰���ȼ�����
//** �������: ��
//** �������: ��
//** ��	 ��: ��
//***********************************************************/
//void NVIC_Config(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure; 
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
//												
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;	//�ⲿ�ж���2
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	  //
//	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
//	NVIC_Init(&NVIC_InitStructure);

//  	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//��ʱ��2�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);	 
//}

///**********************************************************
//** ������:RGB565
//** ��������: ���ɼ���R��G��B���ַ�����ɫת��ΪRGB565��ʽ��16λ��ɫֵ
//** �������: red--�ɼ��ĺ�ɫ��ɫֵ
//			 green--�ɼ�����ɫ��ɫֵ
//			 blue--�ɼ�����ɫ��ɫֵ
//** �������: ��
//** ��	 ��: ����RGB565��ʽ��16λ��ɫֵ
//***********************************************************/
//u16 RGB565(int red,int green,int blue)
//{
//	int R1,G1,B1;
//	unsigned char r,g,b;
//	int RGB;
//	R1=(int)(255*(float)red/red_bace); //red_bace�ο�ֵ1835
//	G1=(int)(255*(float)green/green_bace); //green_bace�ο�ֵ2198
//	B1=(int)(255*(float)blue/blue_bace); //blue_bace�ο�ֵ2185	
//	RGB=(R1<<16)|(G1<<8)|B1;
//	b = ( RGB >> (0+3) ) & 0x1f;		// ȡ��ɫ�ĸ�5λ
//  	g = ( RGB >> (8+2) ) & 0x3f;		// ȡ��ɫ�ĸ�6λ
//  	r = ( RGB >> (16+3)) & 0x1f;		// ȡ��ɫ�ĸ�5λ
//	return( (r<<11) + (g<<5) + (b<<0) );	
//}
///**********************************************************
//** ������:main
//** ��������: �����������ɼ�������ɫ��ʾ��TFT��
//** �������: ��
//** �������: �ޡ�                  
//** ��	 ��: ��
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
//	//������й�İ�ƽ����ڣ��õ���ɫ��׼ֵ��Ϊ�ɼ�������ɫ�Ļ�׼
//	//�ڲ���ǰ���Ƚ�TCS230��׼��Ϊ��׼�İ�ɫ����ȴ�����
//	delay_ms(1000);	//��ʱ���ȴ���ɫ������׼����
//	TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	TIM_Cmd(TIM2, ENABLE);//ʹ��TIM2
//	
//	do //�����ɼ�10��ȡƽ��ֵ
//	{
//		if(flag==4)//������ɫ�ɼ����
//		{
//			e++;
//					if(e>=5) //ȡ�����õ�6������
//					{
//						redm+=red;
//						greenm+=green;
//						bluem+=blue;
//					}
//			delay_ms(100);
//			flag=1;//��־��1����ʼ��һ�β���
//			red=0; //��ɫ��������ֵ��0
//		 	green=0;
//		 	blue=0;
//			TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
//			TIM_Cmd(TIM2, ENABLE); //ʹ��TIM2
//			
//		}
//	}
//	while(e<10);
//	//�õ���ƽ���������ɫ��ɫ��������Ϊ�������ʱ����ɫ��׼ֵ
//	red_bace=redm/6; //��ɫ��׼ֵ
//	green_bace=greenm/6; //��ɫ��׼ֵ
//	blue_bace=bluem/6;	  //��ɫ��׼ֵ 
//	//���������ƽ������õ�����ɫ��ɫ����
//	printf(" rb=%d  gb=%d  bb=%d\n",red_bace,green_bace,blue_bace);

//  	while(1)
//	{
//		if(flag==4)	//������ɫ�ɼ����
//		{
//			R=red;
//			G=green;
//			B=blue;
//			
//			

//			printf(" r=%d  g=%d  b=%d\n",red,green,blue);
//			printf(" R=%d  G=%d  B=%d\n",R,G,B);
//			rgb_value=RGB565(red,green,blue);//���ɼ�����ɫ��ɫֵ����ת��ΪRGB565��ʽ��16λ��ɫֵ
//			printf(" rgb_value=%d\n",rgb_value);
//			delay_ms(100);
//			
//			flag=1;//��־��1����ʼ��һ�β���
//			red=0;	//��ɫ��������ֵ��0
//		 	green=0;
//		 	blue=0;
//			TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
//			TIM_Cmd(TIM2, ENABLE); //ʹ��TIM2
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
u16 red_bace=1835,green_bace=2198,blue_bace=2185; //��ɫ��׼ֵ������ʵ�ʲ���ȷ��
u16 redm,greenm,bluem;
int min,mid,m,n,Max;
/**********************************************************
** ������:TIM2_config
** ��������: ��ʱ��2����
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void TIM2_config(void)
{

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʹ��TIM6ʱ��

	/*��������*/
	TIM_TimeBaseStructure.TIM_Period = 200-1;//����ֵ200 
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//������Ƶϵ��0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE); //ʹ�ܸ�������ж�
	TIM_Cmd(TIM2, DISABLE);//ʧ��TIM2
}

/**********************************************************
** ������:TCS230_GPIO_Config
** ��������: TCS230��GPIO��ʼ������
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void TCS230_GPIO_Config(void)
{
	//PB10--S2,PB11--S3���������
  RCC->APB2ENR|=1<<3;//ʹ��PORTBʱ��							 
	GPIOB->CRH&=0XFFFF00FF;
	GPIOB->CRH|=0X00003300;//PB10,PB11�������

	//PA2--TCS230�ж��������ţ���������
	RCC->APB2ENR|=1<<2;//ʹ��PORTAʱ��							 
	GPIOA->CRL&=0XFFFFF0FF;
	GPIOA->CRL|=0X00000800;//PA0��������
	GPIOA->ODR|=1<<2;//PA2��1,����
}
/**********************************************************
** ������:EXTI_Config
** ��������: �ⲿ�ж�����
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);	//PA2��TCS230���ж�����
	EXTI_ClearITPendingBit(EXTI_Line2);//�ⲿ�ж���2

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//�½��ش���
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}
/**********************************************************
** ������:NVIC_Config
** ��������: �жϷ��鼰���ȼ�����
** �������: ��
** �������: ��
** ��	 ��: ��
***********************************************************/
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
												
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;	//�ⲿ�ж���2
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	  //
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
	NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//��ʱ��2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	 
}

/**********************************************************
** ������:RGB565
** ��������: ���ɼ���R��G��B���ַ�����ɫת��ΪRGB565��ʽ��16λ��ɫֵ
** �������: red--�ɼ��ĺ�ɫ��ɫֵ
			 green--�ɼ�����ɫ��ɫֵ
			 blue--�ɼ�����ɫ��ɫֵ
** �������: ��
** ��	 ��: ����RGB565��ʽ��16λ��ɫֵ
***********************************************************/
u16 RGB565(int red,int green,int blue)
{
	int R1,G1,B1;
	unsigned char r,g,b;
	int RGB;
	R1=(int)(255*(float)red/red_bace); //red_bace�ο�ֵ1835
	G1=(int)(255*(float)green/green_bace); //green_bace�ο�ֵ2198
	B1=(int)(255*(float)blue/blue_bace); //blue_bace�ο�ֵ2185	
	RGB=(R1<<16)|(G1<<8)|B1;
	b = ( RGB >> (0+3) ) & 0x1f;		// ȡ��ɫ�ĸ�5λ
  	g = ( RGB >> (8+2) ) & 0x3f;		// ȡ��ɫ�ĸ�6λ
  	r = ( RGB >> (16+3)) & 0x1f;		// ȡ��ɫ�ĸ�5λ
	return( (r<<11) + (g<<5) + (b<<0) );	
}
u16 COLOUR()
{		
	u16 e=0,R,G,B;
   u16 rgb_value=0;	
	//printf("\rb=%d\n",65536);		//������й�İ�ƽ����ڣ��õ���ɫ��׼ֵ��Ϊ�ɼ�������ɫ�Ļ�׼���ڲ���ǰ���Ƚ�TCS230��׼��Ϊ��׼�İ�ɫ����ȴ�����
	TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
	NVIC_EnableIRQ(EXTI2_IRQn);
	TIM_Cmd(TIM2, ENABLE);//ʹ��TIM2	
	do //�����ɼ�10��ȡƽ��ֵ
	{
		if(flag==4)//������ɫ�ɼ����
		{
			e++;
			if(e>=5) //ȡ�����õ�6������
			{
				redm+=red;
				greenm+=green;
				bluem+=blue;
			}
			delay_ms(100);
			flag=1;//��־��1����ʼ��һ�β���
			red=0; //��ɫ��������ֵ��0
		 	green=0;
		 	blue=0;
			TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
			TIM_Cmd(TIM2, ENABLE); //ʹ��TIM2
	
		}
	}
	while(e<10);
	//�õ���ƽ���������ɫ��ɫ��������Ϊ�������ʱ����ɫ��׼ֵ
	red_bace=redm/6; //��ɫ��׼ֵ
	green_bace=greenm/6; //��ɫ��׼ֵ
	blue_bace=bluem/6;	  //��ɫ��׼ֵ 
	//���������ƽ������õ�����ɫ��ɫ����
	//printf(" rb=%d  gb=%d  bb=%d\n",red_bace,green_bace,blue_bace);
  while(1)
	{
		n=0;
		if(flag==4)	//������ɫ�ɼ����
		{
			R=red;
			G=green;
			B=blue;
			//printf(" r=%d  g=%d  b=%d\n",red,green,blue);
			printf(" R=%d  G=%d  B=%d\r\n",R,G,B);
			rgb_value=RGB565(red,green,blue);//���ɼ�����ɫ��ɫֵ����ת��ΪRGB565��ʽ��16λ��ɫֵ
			//printf(" rgb_value=%d\n",rgb_value);
			delay_ms(100);
			flag=1;//��־��1����ʼ��һ�β���
			red=0;	//��ɫ��������ֵ��0
		 	green=0;
		 	blue=0;
			TIM_SetCounter(TIM2,0);//��TIM2������ʼֵ��Ϊ0
			TIM_Cmd(TIM2, ENABLE); //ʹ��TIM2
//    if(R>240&&R<380&&G>240&&G<344&&B<440&&B>330)
//				return 4;//��
//			}	

//			else if(R>550&&R<1100&&G>290&&G<435&&B<600&&B>400)
//			{
//				return 3;//��
//			}
//			else if(((B-G<100))&&(R>260&&R<700&&G>240&&G<930&&B<700&&B>320))
//			{
//				return 1;//��
//			}
//			else if((R>230&&R<550&&G>255&&G<550&&B<1000&&B>420))
//			{
//				return 5;//��
//			}	
//		  else if(R>450&&R<1250&&G>400&&G<1250&&B<1600&&B>450)
//			{
//				return 2;//��
//			}
//      if((B-G>50)&&(R-G>0)&&(R>220&&R<750&&G>210&&G<600&&B<700&&B>300))
//			{
//			return 4;//��
//			}	
  
						 if(G>R)
			 Max=G;
		 else 
			 Max=R;
		 if(Max<B)
			 Max=B;
		  if(R>400&&G<300)
		 {
             printf("��");
             return 3;
		 }
		 else if(R>400&&G>400&&B>400)
		 {
             printf("��");
             return 2;
		 }
           else if(B-G<20)
			{
                  printf("��");  
				return 1;//��
			}
		 else if(G<210&&R<230&&B<210)
		 {
             printf("��");
             return 4;
		 }
		 else if(Max==R)
		 {
             printf("��");   
             return 4; 
		 }
       
//		 else if(Max==G)
//	 {
//             printf("��");   
//             return 1;
//		 }
		 else if(Max==B)
		 {
             printf("��");
             return 5;
		 }

	
	}
		
		
	}	

}


