#include "follow_color.h"
#include "stm32f10x_it.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "follow_line.h"
#include "led.h"

//X1是放第一个物块的距离
//X2是放第二个物块的距离
//X3是放第三个物块的距离
#define X1 800
#define X2 200
#define X3 1000

void follow_color(int dd)
{   
	 int ff=1; 
	if(dd==2)
  turn_left1_num(1);
	if(dd==3)
	turn_left1_num(2);
	if(dd==4)
	turn_left1_num(3);
	if(dd==5)
	turn_left1_num(4);
	
	follow_stop_delay(100);
	
  follow_line_fast_delay(500);
while(ff)
{
 follow_line_fast();
 if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
{ 
while(1)
{
follow_line_fast_delay(X3);
TIM_SetCompare1(TIM3,1500); 
TIM_SetCompare2 (TIM3,1500);
ff=0;
break;
}
}


}
}



  void follow_color_right(int dd)
{   
	 int ff=1;
	if(dd==2)
	turn_right1_num(1);
	if(dd==3)
  turn_right1_num(2);
	if(dd==4)
  turn_right1_num(3);	
	if(dd==5)
	turn_right1_num(4);
	
//	follow_stop_delay(100);
	
	follow_line_delay(500);	
while(ff)
{
follow_line_fast();
if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
{ while(1)
{follow_line_delay(X3);
TIM_SetCompare1(TIM3,1500); 
TIM_SetCompare2 (TIM3,1500);

ff=0;
break;
}
}

}
}



void follow_color0(int dd)
{   
	 int ff=1,flag1=0;
   
	if(dd==2)
  turn_left1_num(1);
	if(dd==3)
	turn_left1_num(2);
	if(dd==4)
	turn_left1_num(3);
	if(dd==5)
	turn_left1_num(4);
	follow_stop_delay(100);
	
	follow_line_fast_delay(1000);
				while(ff)
	             {    
                      follow_line_fast();

	 if(MLEFT==1)
	{  
		flag1=flag1+1;
	   if(flag1==3)//原2 改过3
 	   {   follow_line_fast_delay(100);
       
           
		   ff=0;
		    break;
		   
	   }
	   else
	 { 
		
			 follow_line_fast_delay(200);
	  }
	}
                 }
	        }
	  







void follow_color0_right(int dd)
{   
	 int ff=1,flag1=0;
	if(dd==2)
	turn_right1_num(1);
	if(dd==3)
  turn_right1_num(2);
	if(dd==4)
  turn_right1_num(3);	
	if(dd==5)
	turn_right1_num(4);
//	follow_stop_delay(100);
	
   follow_line_fast_delay(1000);
				while(ff)
	             {   
                      follow_line_fast(); 
           
	 if(MLEFT==1)
	{  
		flag1=flag1+1;
	   if(flag1==3)//原2 改过3
	   {   follow_line_fast_delay(100);
       
            
		   ff=0;
		    break;
		   
	   }
	   else
	 { 
		
			 follow_line_fast_delay(200);
	  }
	}
                 }
	        }


void follow_color1(int dd)
{   
	 int ff=1; 
	
	if(dd==2)
  turn_left1_num(1);
	if(dd==3)
	turn_left1_num(2);
	if(dd==4)
	turn_left1_num(3);
	if(dd==5)
	turn_left1_num(4);
//	if(dd==6)
//	turn_right1_num(3);
	
//	follow_stop_delay(100);
	
  follow_line_fast_delay(500);
while(ff)
{
 follow_line_fast();
 if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
{ 
while(1)
{
follow_line_fast_delay(X2);
TIM_SetCompare1(TIM3,1500); 
TIM_SetCompare2 (TIM3,1500);
ff=0;
break;
}
}


}
}



void follow_color1_right(int dd)
{   
	 int ff=1;
	if(dd==2)
	turn_right1_num(1);
	if(dd==3)
  turn_right1_num(2);
	if(dd==4)
  turn_right1_num(3);	
	if(dd==5)
	turn_right1_num(4);
	
//	follow_stop_delay(100);
	
	follow_line_fast_delay(500);	
while(ff)
{
follow_line_fast();
if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
{ while(1)
{follow_line_fast_delay(X2);
TIM_SetCompare1(TIM3,1500); 
TIM_SetCompare2 (TIM3,1500);

ff=0;
break;
}
}

}
}




void follow_color2(int dd)
{   
	 int ff=1; 
	
	if(dd==2)
  turn_left1_num(1);
	if(dd==3)
	turn_left1_num(2);
	if(dd==4)
	turn_left1_num(3);
	if(dd==5)
	turn_left1_num(4);
    follow_line_fast_delay(X1);
	
//	follow_stop_delay(100);
	
//  follow_line_fast_delay(500);
//while(ff)
//{
// follow_line_fast();
// if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
//{ 
//while(1)
//{
//follow_line_fast_delay(X1);
//TIM_SetCompare1(TIM3,1500); 
//TIM_SetCompare2 (TIM3,1500);
//ff=0;
//break;
//}
//}


//}
}



void follow_color2_right(int dd)
{   
	 int ff=1;
	if(dd==2)
	turn_right1_num(1);
	if(dd==3)
  turn_right1_num(2);
	if(dd==4)
  turn_right1_num(3);	
	if(dd==5)
	turn_right1_num(4);
    follow_line_fast_delay(X1);
	
//	follow_stop_delay(100);
//	
//	follow_line_fast_delay(500);	
//while(ff)
//{
//follow_line_fast();
//if((FLEFT1==0||FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1)&&(FLEFT2==1||FLEFT3==1||FLEFT4==1))
//{ while(1)
//{follow_line_fast_delay(X1);
//TIM_SetCompare1(TIM3,1500); 
//TIM_SetCompare2 (TIM3,1500);

//ff=0;
//break;
//}
//}

//}
}









