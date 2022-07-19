#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
#include "stm32f10x.h"
#include "catch.h"
#include "follow_line.h"
#include "color.h"
#include "follow_color.h"




int main(void)
{	
//定义及初始化*****************************************************//
	
int c1,c2,c3,c4,c5;
int x[4]={0};
delay_init();
LED_Init();
TIM3_PWML_Init(19999,71);
TIM3_PWMR_Init(19999,71);
uart_init(115200);
SystemInit(); //系统初始化
TCS230_GPIO_Config();//TCS230的GPIO配置
EXTI_Config(); //外部中断配置
NVIC_Config(); //中断向量配置
TIM2_config(); //TIM2初始化
TIM4_PWM_Init1(19999,71);//mid
TIM4_PWM_Init2(19999,71);//left
TIM4_PWM_Init3(19999,71);//right
TIM8_PWML_Init(19999,71);//leftxia
TIM8_PWMR_Init(19999,71);//rightxia
TIM4_PWM_Init4(19999,71);//left_side
TIM3_PWM_Init4(19999,71);//right_side
TIM3_PWM_Init3(19999,71);//back
	
//调试**************************************************************//

//	TIM_SetCompare1(TIM3,1550); //左前右后//慢速
//	TIM_SetCompare2(TIM3,1449); 

/*gooback();
turn_fleft_fast();	
follow_line_fast();
while(1)
{
//please_stop();
//   // straight();
c1=COLOUR();	
printf("color=%d\r\n",c1);	
}
go_to_mi();
follow_stop_delay(200);//停止300ms
turn_left_delay(290);
//turn_right_delay(290);
follow_stop_delay(200);//停止300ms
go_to_xiaoquan();//去小圈
follow_stop_delay(20000);	
right_xia_down();
////任务一************************************************************/
////去米字区，停车****************************************************//

follow_stop_delay(200);
my_catch_all_up_5();	
my_catch_all_outside();
go_to_mi();
//follow_stop_delay(200);//停止300ms 

///转去A点	,识别颜色，不抓起,回到米字区域***************************//

turn_left1_num(2);	//左转弯90度,原538
//follow_stop_delay(200);//停止300ms
//go_to_xiaoquan1();//去小圈
follow_line_fast_delay(1500);
//follow_stop_delay(200);	

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1450);
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1500);
x[0]=COLOUR();
printf("color=%d\n\r",x[0]);
TIM_SetCompare1(TIM3,1550);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);

back_to_centre_2();
//follow_stop_delay(200);
//// follow_back_line_fast_delay(100);

//转去C点	,识别颜色，抓起, 回到米字区域****************************//

turn_right1_num(2);  //顺时针90度
//follow_stop_delay(100);
//go_to_xiaoquan();//去小圈
follow_line_fast_delay(1500);

//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1450);
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1500);
x[1]=COLOUR();
TIM_SetCompare1(TIM3,1550);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1500);
right_inside();
delay_ms(300);
left_xia_down();
delay_ms(300);
right_outside();
delay_ms(300);

back_to_centre_2();
//follow_stop_delay(200);

//转去E点	,识别颜色，抓起, 回到米字区域****************************//

turn_right1_num(2);  //顺时针90度
//follow_stop_delay(200);
go_to_xiaoquan();//去小圈
follow_stop_delay(200);	

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1450);
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1500);
right_inside_2();
delay_ms(300);
right_xia_down();
delay_ms(300);
right_outside();
delay_ms(300);
x[2]=COLOUR();
//x[2]=9-x[0]-x[1];
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1550);
delay_ms(300);

back_to_centre_2();
//follow_stop_delay(200);
//转回A,抓取******************************************************//

turn_left1_num(4);  //顺时针180度
//follow_stop_delay(200);
go_to_xiaoquan();//去小圈
//follow_stop_delay(200);	

mid_down();
delay_ms(300);

back_to_centre_2();
//follow_stop_delay(200);


 c1=x[0]; 
 c2=x[1];
 c3=x[2];


 
 //寻第一个颜色*****************************//绿1 白2  红3   黑4 蓝5 标准样式  C1蓝5 C2绿1 C3红3 C4白2 C5嘿4
 

follow_color_right(c1);

please_stop();
mid_up();//放第一个颜色   
delay_ms(300);

//follow_back_line_delay(100);
back_to_centre_3(); //巡线倒回到米字区   origin:3
//follow_stop_delay(200);

//寻第二个颜色 ****************************************************//


if(c1-c2>0)
follow_color(c1-c2+1);
else if (c1-c2<0)
follow_color_right(c2-c1+1);
//follow_stop_delay(200); 

please_stop();
left_xia_up();//放第二个颜色  //原在前
delay_ms(300);

TIM_SetCompare1(TIM3,1540);//车身向右
TIM_SetCompare2(TIM3,1500);
delay_ms(500);//300
please_stop();

TIM_SetCompare1(TIM3,1460);//车身向左
TIM_SetCompare2(TIM3,1500);
delay_ms(500);//300

follow_back_line_delay(300);
back_to_centre_3();//巡线回到米字区
//follow_stop_delay(200);

//寻第三个颜色****************************************************//


if(c2-c3>0)               //寻第三种颜色
follow_color(c2-c3+1);
else if (c2-c3<0)
follow_color_right(c3-c2+1);
follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//车身向左
TIM_SetCompare2(TIM3,1460);
delay_ms(300);

please_stop();
right_xia_up();//放第三种颜色   
delay_ms(300);
TIM_SetCompare1(TIM3,1500);//车身向右
TIM_SetCompare2(TIM3,1540);
delay_ms(300);

follow_back_line_delay(300);
back_to_centre_3();//巡线回到米字区     yuan 3
//follow_stop_delay(200);


////任务二 ************************************************************//

/////////////////////////////////////////////////////////GGGGGGGGGGGGGGGGGGGGGGGGGGG//////////////////////////////////

////去G点抓五个桶*****************************************************// C1蓝5 C2绿1 C3红3 C4白2 C5黑4

if(c3==1)
follow_color0(4);
else 
follow_color0_right(7-c3);

follow_stop_delay(100);

my_catch_all_down_5();
//delay_ms(300);
x[3]=COLOUR();
c4=x[3];// 随机放在B的木块  默认白
c5=15-c1-c2-c3-c4;  //5 1 3 2随机放在C的木块  默认黑

back_to_centre_4();//巡线回到米字区
//follow_stop_delay(200);

//寻第一个：c5第一***************************************************//

//寻c5的颜色（第一）
follow_color1(7-c5);
//follow_stop_delay(200);

please_stop();
mid_up();
delay_ms(300);
follow_back_line_delay(1000);

back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);

//寻第二个：c2第二**************************************************// 默认绿色

if(c5>c2)  //寻c2的颜色 （第二）
follow_color1(c5-c2+1);
else
follow_color1_right(c2-c5+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1440);//车身向左
delay_ms(300);

please_stop();
right_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1560);
delay_ms(300);

follow_back_line_delay(1000);

back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);
 
//寻第三个：c3第三**************************************************//

if(c2>c3)           //寻c3的颜色  （第三）
follow_color1(c2-c3+1);
else
follow_color1_right(c3-c2+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1560);         //车身向右
TIM_SetCompare2(TIM3,1500);
delay_ms(300);

please_stop();
left_up();
delay_ms(300);

TIM_SetCompare1(TIM3,1440);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);	

follow_back_line_delay(1000);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);
 
//寻第四个：c4第四**************************************************//  

if(c3>c4)           //寻c4的颜色   （第四）
follow_color1(c3-c4+1);
else
follow_color1_right(c4-c3+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//车身向左
TIM_SetCompare2(TIM3,1460);
    delay_ms(600);

please_stop();
right_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1540);
    delay_ms(600);

follow_back_line_delay(1000);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);

//寻第五个：c1第五**************************************************// 

if(c4>c1)           //寻c1的颜色    （第五）
follow_color1(c4-c1+1);
else
follow_color1_right(c1-c4+1);
//follow_stop_delay(200);


TIM_SetCompare1(TIM3,1540);//车身向右
TIM_SetCompare2(TIM3,1500);
    delay_ms(300);

please_stop();
left_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1460);
TIM_SetCompare2(TIM3,1500);
    delay_ms(300);


follow_back_line_delay(1000);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);

/////////////////////////////////////////////////////////FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF//////////////////////////////////

//去F点抓五个桶***********************************************************//

if(c1==5) //默认蓝5
follow_color0_right(4);
else
follow_color0(c1+1);
follow_stop_delay(100);

please_stop();
my_catch_all_down_5();
delay_ms(300);

back_to_centre_4();//巡线回到米字区
//follow_stop_delay(200);

//寻第一个：c5第一***************************************************//

if(c5==5)//寻c5的颜色    （第一） 
follow_color2(4);
else
follow_color2_right(c5+1);
//follow_stop_delay(200);

please_stop();
mid_up();
delay_ms(300);

follow_back_line_delay(500);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);

//寻第二个：c3第二**************************************************//

if(c5>c3)  //寻c2的颜色 （第二）
follow_color2(c5-c3+1);
else
follow_color2_right(c3-c5+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1440);//车身向左
delay_ms(300);

please_stop();
right_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1560);
delay_ms(300);

follow_back_line_delay(500);



back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);
 
//寻第三个：c2第三**************************************************//

if(c3>c2)           //寻c3的颜色  （第三）
follow_color2(c3-c2+1);
else
follow_color2_right(c2-c3+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1560);         //车身向右
TIM_SetCompare2(TIM3,1500);
delay_ms(300);

please_stop();
left_up();
delay_ms(300);

TIM_SetCompare1(TIM3,1440);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);	

follow_back_line_delay(500);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);

//寻第四个：c4第四**************************************************//  

if(c2>c4)           //寻c4的颜色   （第四）
follow_color2(c2-c4+1);
else
follow_color2_right(c4-c2+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1540);//车身向右
TIM_SetCompare2(TIM3,1500);
delay_ms(600);//300

please_stop();
left_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1460);
TIM_SetCompare2(TIM3,1500);
delay_ms(600);

	

follow_back_line_delay(500);
back_to_centre_2();//巡线回到米字区
follow_stop_delay(200);

//寻第五个：c4第五**************************************************// 

if(c4>c1)           //寻c1的颜色    （第五）
follow_color2(c4-c1+1);
else
follow_color2_right(c1-c4+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//车身向左
TIM_SetCompare2(TIM3,1460);
delay_ms(300);

please_stop();
right_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1540);
delay_ms(300);


follow_back_line_delay(500);
back_to_centre_2();//巡线回到米字区
//follow_stop_delay(200);
//绿1 白2  红3   黑4 蓝5 标准样式  C1蓝5 C2绿1 C3红3 C4白2 C5嘿4

//////******************************堆物块********************************

//c1=1;c2=2;c3=3;c4=4;c5=5;

//up_delay(2100);	  	
//block_stop();
//delay_ms(300); 		 
//down_delay(1900);
//block_stop();

//block_stop();//电机停
block_open2();
delay_ms(300);


if(c1==5)
follow_back_line_delay(50);
else  
turn_right3_num(5-c1);

//c1=1;c2=2;c3=3;c4=4;c5=5;

if(c1==1||c2==1||c3==1)   //堆3个物块
block_pack3();
else
block_pack2();//堆2个物块
go_to_centre();
//follow_stop_delay(100);
turn_right3_num(1);
//follow_stop_delay(100);

if(c1==2||c2==2||c3==2)
block_pack3();
else
block_pack2();
go_to_centre();
//follow_stop_delay(100);
turn_right3_num(1);
//follow_stop_delay(100);

if(c1==3||c2==3||c3==3)
block_pack3();
else
block_pack2();
go_to_centre();
//follow_stop_delay(100);
turn_right3_num(1);
//follow_stop_delay(100);

if(c1==4||c2==4||c3==4)
block_pack3();
else
block_pack2();
go_to_centre();
//follow_stop_delay(100);
turn_right3_num(1);
//follow_stop_delay(100);

if(c1==5||c2==5||c3==5)
block_pack3();
else
block_pack2();
go_to_centre();
//follow_stop_delay(100);


turn_left1_num(2);
//follow_stop_delay(400);
go_to_mi();
follow_stop_delay(10000);

}