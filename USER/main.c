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
//���弰��ʼ��*****************************************************//
	
int c1,c2,c3,c4,c5;
int x[4]={0};
delay_init();
LED_Init();
TIM3_PWML_Init(19999,71);
TIM3_PWMR_Init(19999,71);
uart_init(115200);
SystemInit(); //ϵͳ��ʼ��
TCS230_GPIO_Config();//TCS230��GPIO����
EXTI_Config(); //�ⲿ�ж�����
NVIC_Config(); //�ж���������
TIM2_config(); //TIM2��ʼ��
TIM4_PWM_Init1(19999,71);//mid
TIM4_PWM_Init2(19999,71);//left
TIM4_PWM_Init3(19999,71);//right
TIM8_PWML_Init(19999,71);//leftxia
TIM8_PWMR_Init(19999,71);//rightxia
TIM4_PWM_Init4(19999,71);//left_side
TIM3_PWM_Init4(19999,71);//right_side
TIM3_PWM_Init3(19999,71);//back
	
//����**************************************************************//

//	TIM_SetCompare1(TIM3,1550); //��ǰ�Һ�//����
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
follow_stop_delay(200);//ֹͣ300ms
turn_left_delay(290);
//turn_right_delay(290);
follow_stop_delay(200);//ֹͣ300ms
go_to_xiaoquan();//ȥСȦ
follow_stop_delay(20000);	
right_xia_down();
////����һ************************************************************/
////ȥ��������ͣ��****************************************************//

follow_stop_delay(200);
my_catch_all_up_5();	
my_catch_all_outside();
go_to_mi();
//follow_stop_delay(200);//ֹͣ300ms 

///תȥA��	,ʶ����ɫ����ץ��,�ص���������***************************//

turn_left1_num(2);	//��ת��90��,ԭ538
//follow_stop_delay(200);//ֹͣ300ms
//go_to_xiaoquan1();//ȥСȦ
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

//תȥC��	,ʶ����ɫ��ץ��, �ص���������****************************//

turn_right1_num(2);  //˳ʱ��90��
//follow_stop_delay(100);
//go_to_xiaoquan();//ȥСȦ
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

//תȥE��	,ʶ����ɫ��ץ��, �ص���������****************************//

turn_right1_num(2);  //˳ʱ��90��
//follow_stop_delay(200);
go_to_xiaoquan();//ȥСȦ
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
//ת��A,ץȡ******************************************************//

turn_left1_num(4);  //˳ʱ��180��
//follow_stop_delay(200);
go_to_xiaoquan();//ȥСȦ
//follow_stop_delay(200);	

mid_down();
delay_ms(300);

back_to_centre_2();
//follow_stop_delay(200);


 c1=x[0]; 
 c2=x[1];
 c3=x[2];


 
 //Ѱ��һ����ɫ*****************************//��1 ��2  ��3   ��4 ��5 ��׼��ʽ  C1��5 C2��1 C3��3 C4��2 C5��4
 

follow_color_right(c1);

please_stop();
mid_up();//�ŵ�һ����ɫ   
delay_ms(300);

//follow_back_line_delay(100);
back_to_centre_3(); //Ѳ�ߵ��ص�������   origin:3
//follow_stop_delay(200);

//Ѱ�ڶ�����ɫ ****************************************************//


if(c1-c2>0)
follow_color(c1-c2+1);
else if (c1-c2<0)
follow_color_right(c2-c1+1);
//follow_stop_delay(200); 

please_stop();
left_xia_up();//�ŵڶ�����ɫ  //ԭ��ǰ
delay_ms(300);

TIM_SetCompare1(TIM3,1540);//��������
TIM_SetCompare2(TIM3,1500);
delay_ms(500);//300
please_stop();

TIM_SetCompare1(TIM3,1460);//��������
TIM_SetCompare2(TIM3,1500);
delay_ms(500);//300

follow_back_line_delay(300);
back_to_centre_3();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ��������ɫ****************************************************//


if(c2-c3>0)               //Ѱ��������ɫ
follow_color(c2-c3+1);
else if (c2-c3<0)
follow_color_right(c3-c2+1);
follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//��������
TIM_SetCompare2(TIM3,1460);
delay_ms(300);

please_stop();
right_xia_up();//�ŵ�������ɫ   
delay_ms(300);
TIM_SetCompare1(TIM3,1500);//��������
TIM_SetCompare2(TIM3,1540);
delay_ms(300);

follow_back_line_delay(300);
back_to_centre_3();//Ѳ�߻ص�������     yuan 3
//follow_stop_delay(200);


////����� ************************************************************//

/////////////////////////////////////////////////////////GGGGGGGGGGGGGGGGGGGGGGGGGGG//////////////////////////////////

////ȥG��ץ���Ͱ*****************************************************// C1��5 C2��1 C3��3 C4��2 C5��4

if(c3==1)
follow_color0(4);
else 
follow_color0_right(7-c3);

follow_stop_delay(100);

my_catch_all_down_5();
//delay_ms(300);
x[3]=COLOUR();
c4=x[3];// �������B��ľ��  Ĭ�ϰ�
c5=15-c1-c2-c3-c4;  //5 1 3 2�������C��ľ��  Ĭ�Ϻ�

back_to_centre_4();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ��һ����c5��һ***************************************************//

//Ѱc5����ɫ����һ��
follow_color1(7-c5);
//follow_stop_delay(200);

please_stop();
mid_up();
delay_ms(300);
follow_back_line_delay(1000);

back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ�ڶ�����c2�ڶ�**************************************************// Ĭ����ɫ

if(c5>c2)  //Ѱc2����ɫ ���ڶ���
follow_color1(c5-c2+1);
else
follow_color1_right(c2-c5+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1440);//��������
delay_ms(300);

please_stop();
right_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1560);
delay_ms(300);

follow_back_line_delay(1000);

back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);
 
//Ѱ��������c3����**************************************************//

if(c2>c3)           //Ѱc3����ɫ  ��������
follow_color1(c2-c3+1);
else
follow_color1_right(c3-c2+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1560);         //��������
TIM_SetCompare2(TIM3,1500);
delay_ms(300);

please_stop();
left_up();
delay_ms(300);

TIM_SetCompare1(TIM3,1440);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);	

follow_back_line_delay(1000);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);
 
//Ѱ���ĸ���c4����**************************************************//  

if(c3>c4)           //Ѱc4����ɫ   �����ģ�
follow_color1(c3-c4+1);
else
follow_color1_right(c4-c3+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//��������
TIM_SetCompare2(TIM3,1460);
    delay_ms(600);

please_stop();
right_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1540);
    delay_ms(600);

follow_back_line_delay(1000);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ�������c1����**************************************************// 

if(c4>c1)           //Ѱc1����ɫ    �����壩
follow_color1(c4-c1+1);
else
follow_color1_right(c1-c4+1);
//follow_stop_delay(200);


TIM_SetCompare1(TIM3,1540);//��������
TIM_SetCompare2(TIM3,1500);
    delay_ms(300);

please_stop();
left_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1460);
TIM_SetCompare2(TIM3,1500);
    delay_ms(300);


follow_back_line_delay(1000);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);

/////////////////////////////////////////////////////////FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF//////////////////////////////////

//ȥF��ץ���Ͱ***********************************************************//

if(c1==5) //Ĭ����5
follow_color0_right(4);
else
follow_color0(c1+1);
follow_stop_delay(100);

please_stop();
my_catch_all_down_5();
delay_ms(300);

back_to_centre_4();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ��һ����c5��һ***************************************************//

if(c5==5)//Ѱc5����ɫ    ����һ�� 
follow_color2(4);
else
follow_color2_right(c5+1);
//follow_stop_delay(200);

please_stop();
mid_up();
delay_ms(300);

follow_back_line_delay(500);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ�ڶ�����c3�ڶ�**************************************************//

if(c5>c3)  //Ѱc2����ɫ ���ڶ���
follow_color2(c5-c3+1);
else
follow_color2_right(c3-c5+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1440);//��������
delay_ms(300);

please_stop();
right_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1560);
delay_ms(300);

follow_back_line_delay(500);



back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);
 
//Ѱ��������c2����**************************************************//

if(c3>c2)           //Ѱc3����ɫ  ��������
follow_color2(c3-c2+1);
else
follow_color2_right(c2-c3+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1560);         //��������
TIM_SetCompare2(TIM3,1500);
delay_ms(300);

please_stop();
left_up();
delay_ms(300);

TIM_SetCompare1(TIM3,1440);
TIM_SetCompare2(TIM3,1500);
delay_ms(300);	

follow_back_line_delay(500);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);

//Ѱ���ĸ���c4����**************************************************//  

if(c2>c4)           //Ѱc4����ɫ   �����ģ�
follow_color2(c2-c4+1);
else
follow_color2_right(c4-c2+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1540);//��������
TIM_SetCompare2(TIM3,1500);
delay_ms(600);//300

please_stop();
left_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1460);
TIM_SetCompare2(TIM3,1500);
delay_ms(600);

	

follow_back_line_delay(500);
back_to_centre_2();//Ѳ�߻ص�������
follow_stop_delay(200);

//Ѱ�������c4����**************************************************// 

if(c4>c1)           //Ѱc1����ɫ    �����壩
follow_color2(c4-c1+1);
else
follow_color2_right(c1-c4+1);
//follow_stop_delay(200);

TIM_SetCompare1(TIM3,1500);//��������
TIM_SetCompare2(TIM3,1460);
delay_ms(300);

please_stop();
right_xia_up();
delay_ms(300);
TIM_SetCompare1(TIM3,1500);
TIM_SetCompare2(TIM3,1540);
delay_ms(300);


follow_back_line_delay(500);
back_to_centre_2();//Ѳ�߻ص�������
//follow_stop_delay(200);
//��1 ��2  ��3   ��4 ��5 ��׼��ʽ  C1��5 C2��1 C3��3 C4��2 C5��4

//////******************************�����********************************

//c1=1;c2=2;c3=3;c4=4;c5=5;

//up_delay(2100);	  	
//block_stop();
//delay_ms(300); 		 
//down_delay(1900);
//block_stop();

//block_stop();//���ͣ
block_open2();
delay_ms(300);


if(c1==5)
follow_back_line_delay(50);
else  
turn_right3_num(5-c1);

//c1=1;c2=2;c3=3;c4=4;c5=5;

if(c1==1||c2==1||c3==1)   //��3�����
block_pack3();
else
block_pack2();//��2�����
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