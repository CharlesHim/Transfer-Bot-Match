#ifndef _COLOR_H
#define _COLOR_H


#include "stm32f10x.h"
#include "sys.h"


u16 COLOUR(void);         //ÑÕÉ«Ê¶±ð
u16 RGB565(int red,int green,int blue);
void NVIC_Config(void);
void EXTI_Config(void);
void TCS230_GPIO_Config(void);
void TIM2_config(void);





#endif


























