#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

#define FLEFT4 PCin(10)//1
#define FLEFT3 PBin(3)//2
#define FLEFT2 PAin(13)//3
#define FLEFT1 PCin(6)//4
#define FRIGHT1 PCin(7)//5
#define FRIGHT2 PAin(15)//6
#define FRIGHT3 PBin(4)//7
#define FRIGHT4 PBin(5)//8

#define BLEFT4 PCin(3)//1
#define BLEFT3 PCin(2)//2
#define BLEFT2 PBin(12)//3
#define BLEFT1 PBin(14)//4
#define BRIGHT1 PBin(13)//5
#define BRIGHT2 PBin(15)//6
#define BRIGHT3 PCin(0)//7
#define BRIGHT4 PCin(13)//8

#define MLEFT  PCin(11)
#define MRIGHT PAin(11)
#define LEFT  PAin(12)
#define RIGHT PCin(12)

#define LED0 PCout(4)
#define LED1 PCout(5)



void LED_Init(void);


		 				    
#endif
