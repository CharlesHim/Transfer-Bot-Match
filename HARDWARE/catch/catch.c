#include "catch.h"
#include "pwm.h"
#include "delay.h"
#include "led.h"
#include "follow_line.h"
   
//Y1是推第一个物块的距离
//Y2是推第二个物块的距离
//Y3是推第三个物块的距离 
//这个是用后部推得
#define Y1 300
#define Y2 500
#define Y3 600

//up与down的值
#define UP 2400//原1300现已确认
#define DOWN 1900//原1200现已确认

void mid_up(void)
{
   TIM_SetCompare1(TIM4,700);
}

void mid_down(void)
{
   TIM_SetCompare1(TIM4,1400);
}
void left_up(void)
{
    TIM_SetCompare2(TIM4,2000);
}

void left_down(void)
{
    TIM_SetCompare2(TIM4,2400);
}


void right_up(void)
{
    TIM_SetCompare3(TIM4,2050);
}

void right_down(void)
{
    TIM_SetCompare3(TIM4,1700);
}
void left_xia_up(void)
{
    TIM_SetCompare3(TIM8,2050);
}

void left_xia_down(void)
{
    TIM_SetCompare3(TIM8,1300);
}
void right_xia_up(void)
{
    TIM_SetCompare4(TIM8,300);
}

void right_xia_down(void)
{
    TIM_SetCompare4(TIM8,1850);
}
void left_inside(void)
{
    TIM_SetCompare4(TIM4,1600);
}

void left_outside(void)
{
    TIM_SetCompare4(TIM4,2200);
}

void right_inside(void)
{

    TIM_SetCompare4(TIM3,1100);

}
void right_inside_2(void)
{

    TIM_SetCompare4(TIM3,800);

}

void right_outside(void)
{
    TIM_SetCompare4(TIM3,400);
}
void my_catch_all_up(void)
{
    mid_up();
	left_up();
	right_up();

}
void my_catch_all_outside(void)
{
  left_outside();
   right_outside();

}

void my_catch_all_down(void)
{
    mid_down();
	left_down();
	right_down();
}

void my_catch_all_up_5(void)
{
    mid_up();
	left_up();
	right_up();
	left_xia_up();
	right_xia_up();
	
}
void my_catch_all_down_5(void)
{
    mid_down();
	left_down();
	right_down();
	left_xia_down();
	right_xia_down();
}
void block_open(void)
{
  TIM_SetCompare3(TIM3,1160);
}
void block_open1(void)//small
{
  TIM_SetCompare3(TIM3,1350);
}
void block_open2(void)//big
{
  TIM_SetCompare3(TIM3,1300);
}
void block_close(void)
{
  TIM_SetCompare3(TIM3,1800);
}
void block_close1(void)
{
  TIM_SetCompare3(TIM3,1700);
}
void block_close2(void)
{
TIM_SetCompare3(TIM3,1700);
}
void my_catch_all_inside(void)
{  right_inside();
   left_inside();

}

void block_pack2(void)
{
       follow_back_line_fast_delay(900);

	while(1)
		
	{
         follow_back_line_fast();
		 
          if((BLEFT1==0&&BRIGHT1==0)&&(BRIGHT2==1||BLEFT2==1))
		  {  follow_stop_delay(200); 
				follow_back_line_fast_delay1(Y1);	//到达木块1
			    please_stop();   
			  break;
		  }
	  }					   
		
block_open2();
delay_ms(300);
//down_delay(DOWN);
//block_stop();
//delay_ms(300);
block_close1();
delay_ms(300);
up_delay(UP);
block_stop();
delay_ms(300);

follow_back_line_fast_delay1(Y2);//到达木块2
follow_stop_delay(200);
block_open1();
delay_ms(300);

down_delay(DOWN);
block_stop();
delay_ms(300);
block_close1();
delay_ms(300);

			 		 
  while(1)
  {
//		follow_back_line_fast_delay(400);
  		  follow_back_line_fast1();
	   if(LEFT==1&&RIGHT==1)
	   {  
	     follow_stop_delay(500);
       follow_line_fast_delay1(50);//倒退使其对准 原200
		   follow_stop_delay(500);
			 
//			 TIM_SetCompare1(TIM3,1540);//车身向右
//TIM_SetCompare2(TIM3,1500);
//delay_ms(70);//300
			 
block_open1();
delay_ms(300);
block_open2();
delay_ms(300);
			 
//			 TIM_SetCompare1(TIM3,1460);//车身向左
//TIM_SetCompare2(TIM3,1500);
//delay_ms(70);//300
	 follow_stop_delay(100);

//up_delay(UP);
//block_stop();			 
		   		  
		   
		   break;
	   }
	   
  }
 }
					 
void block_pack3(void)
{

       follow_back_line_fast_delay(900);

	while(1)
		
	{
         follow_back_line_fast();
		 
          //if((BLEFT1==0&&BRIGHT1==0)&&(BRIGHT2==1||BLEFT2==1))
						if((BLEFT1==0&&BRIGHT1==0)&&(BLEFT2==1))
		  {  
				

        
       follow_stop_delay(200);
				follow_back_line_fast_delay1(Y1);//到达物块1	
			  please_stop();   
			  break;
		  }
	  }					   
		


block_open2();
delay_ms(300);
//down_delay(DOWN);
//block_stop();
//delay_ms(300);
block_close1();
delay_ms(300);
up_delay(UP);
block_stop();
delay_ms(300);

follow_back_line_fast_delay1(Y2);//到达物块2  yuan Y2-Y1
follow_stop_delay(200);
block_open1();
delay_ms(300);

down_delay(DOWN);
block_stop();
delay_ms(300);
block_close1();
delay_ms(300);
up_delay(UP);
block_stop();
delay_ms(300);

follow_back_line_fast_delay1(Y3);//到达物块3    yuan Y3-Y2
follow_stop_delay(200);
block_open1();
delay_ms(300);

down_delay(DOWN);
block_stop();
delay_ms(300);
block_close1();
delay_ms(300);
			 		 
  while(1)
  {
//		follow_back_line_fast_delay(450);
  		  follow_back_line_fast1();
	   if(LEFT==1&&RIGHT==1)
	   {  
	      follow_stop_delay(500);
        follow_line_fast_delay1(50);//原200
		   follow_stop_delay(500);
			 
			 
//TIM_SetCompare1(TIM3,1540);//车身向右
//TIM_SetCompare2(TIM3,1500);
//delay_ms(70);//300
//			 
block_open1();
delay_ms(300);
block_open2();
delay_ms(300);			

//			 TIM_SetCompare1(TIM3,1460);//车身向左
//TIM_SetCompare2(TIM3,1500);
//delay_ms(70);//300
			 		 follow_stop_delay(100);

//up_delay(UP);
//block_stop();		 
		   		  
		   
		   break;
	   
	   
  
  
  }
  
  
}
}
void block_stop(void)
{
      LED0=1;
	    LED1=1;
}





