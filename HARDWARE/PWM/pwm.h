#ifndef __PWM_H
#define __PWM_H
#include "sys.h"



void TIM3_PWML_Init(u16 arr,u16 psc);//cheer1      PA6
void TIM3_PWMR_Init(u16 arr,u16 psc);//cheer2      PA7




void TIM4_PWM_Init1(u16 arr,u16 psc);//mid         PB6
void TIM4_PWM_Init2(u16 arr,u16 psc);//left        PB7
void TIM4_PWM_Init3(u16 arr,u16 psc);//right       PB8
void TIM8_PWML_Init(u16 arr,u16 psc);//leftxia     PC8
void TIM8_PWMR_Init(u16 arr,u16 psc);//rightxia    PC9
void TIM4_PWM_Init4(u16 arr,u16 psc);//left_side   PB9
void TIM3_PWM_Init4(u16 arr,u16 psc);//right_side  PB1
void TIM3_PWM_Init3(u16 arr,u16 psc);//teeth       PB0

#endif
