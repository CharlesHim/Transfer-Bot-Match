#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
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
