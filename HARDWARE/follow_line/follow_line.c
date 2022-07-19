#include "follow_line.h"
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "catch.h"



void straight(void)
{     
//	TIM_SetCompare1(TIM3,1576); 
//	TIM_SetCompare2(TIM3,1425); 
//	TIM_SetCompare1(TIM3,1574); //左前右后//慢速
//	TIM_SetCompare2(TIM3,1421); 
  TIM_SetCompare1(TIM3,1570); //左前右后//快速
	TIM_SetCompare2(TIM3,1427); 
} 
void straight1(void)
{
  TIM_SetCompare1(TIM3,1580); //左前右后//慢速
	TIM_SetCompare2(TIM3,1418); 
}	

void turn_fleft(void)
{      
  TIM_SetCompare1(TIM3,1570); //35  62   40  65  匀速 1570 1427
	TIM_SetCompare2(TIM3,1345);

}
void turn_fleft_fast(void)
{      
   TIM_SetCompare1(TIM3,1570);
   TIM_SetCompare2(TIM3,1325);

}
void turn_fleft_fast_fast(void)
{      
   TIM_SetCompare1(TIM3,1570);
   TIM_SetCompare2(TIM3,1305);

}
void turn_fright(void)
{  
  TIM_SetCompare1(TIM3,1650); //匀速 1570 1427
	TIM_SetCompare2(TIM3,1427); 

}

void turn_fright_fast(void)
{  
   TIM_SetCompare1(TIM3,1670);
   TIM_SetCompare2(TIM3,1427);
}
void turn_fright_fast_fast(void)
{  
   TIM_SetCompare1(TIM3,1690);
   TIM_SetCompare2(TIM3,1427);
}
void gooback(void)
{    
	TIM_SetCompare1(TIM3,1430); //左前右后
  TIM_SetCompare2(TIM3,1573); 
}
void gooback1(void)
{
TIM_SetCompare1(TIM3,1400); //左前右后
      TIM_SetCompare2(TIM3,1603);
}
void turn_bleft(void)
{
  TIM_SetCompare1(TIM3,1460);  //原速 1430 1573
	TIM_SetCompare2(TIM3,1573); 

}
void turn_bleft_fast(void)
{
  TIM_SetCompare1(TIM3,1480); 
	TIM_SetCompare2(TIM3,1573);
}
void turn_bleft_fast_fast(void)
{
  TIM_SetCompare1(TIM3,1500); 
	TIM_SetCompare2(TIM3,1573);
}
void turn_bright(void)
{
  TIM_SetCompare1(TIM3,1430); 
	TIM_SetCompare2(TIM3,1543); 

}
void turn_bright_fast(void)
{   
	TIM_SetCompare1(TIM3,1430); 
	TIM_SetCompare2(TIM3,1523);

}
void turn_bright_fast_fast(void)
{   
	TIM_SetCompare1(TIM3,1430); 
	TIM_SetCompare2(TIM3,1503);

}
void turn_bleft1(void)
{
  TIM_SetCompare1(TIM3,1430);  //原速 1400 1603
	TIM_SetCompare2(TIM3,1603); 

}
void turn_bleft_fast1(void)
{
    TIM_SetCompare1(TIM3,1390); 
	TIM_SetCompare2(TIM3,1552);

}
void turn_bleft_fast1_fast(void)
{
    TIM_SetCompare1(TIM3,1360); 
	TIM_SetCompare2(TIM3,1552);

}
void turn_bright1(void)
{
    TIM_SetCompare1(TIM3,1400); //原速 1400 1603
	TIM_SetCompare2(TIM3,1573); 

}
void turn_bright_fast1(void)
{   
	TIM_SetCompare1(TIM3,1450); 
	TIM_SetCompare2(TIM3,1612);

}
void turn_bright_fast1_fast(void)
{   
	TIM_SetCompare1(TIM3,1450); 
	TIM_SetCompare2(TIM3,1642);

}

void please_stop(void)
{
   TIM_SetCompare1(TIM3,1500);
   TIM_SetCompare2(TIM3,1500);
}

 
 void follow_line(void)
 {    if(FLEFT1==1&&FRIGHT1==0)
		{ turn_fleft();
		}
	  else if(FRIGHT1==1&&FLEFT1==0)
		{ turn_fright();
		}
 
      else {
	  straight();
			} 
 }
void follow_line_fast(void)
 {
   
	     if(FLEFT1==1&&FRIGHT1==0)
		{ turn_fleft();
		}
	  else if(FRIGHT1==1&&FLEFT1==0)
		{ turn_fright();
		}
//		 else if(FLEFT2==1&&FRIGHT1==0&&FLEFT1==0)
//       {  turn_fleft_fast();} 
//        else if(FRIGHT2==1&&FRIGHT1==0&&FLEFT1==0)
//      { turn_fright_fast();	} 
//					 else if(FLEFT3==1&&FRIGHT1==0&&FLEFT1==0)
//       {  turn_fleft_fast_fast();} 
//        else if(FRIGHT3==1&&FRIGHT1==0&&FLEFT1==0)
//      { turn_fright_fast_fast();	} 
	   else 
	 straight();
		   
 }
 
 void follow_line_fast1(void)
 {
   
	     if(FLEFT1==1&&FRIGHT1==0)
		{   TIM_SetCompare1(TIM3,1525); //左前右后//慢速
	TIM_SetCompare2(TIM3,1454); 
		}
	  else if(FRIGHT1==1&&FLEFT1==0)
		{   TIM_SetCompare1(TIM3,1545); //左前右后//慢速
	TIM_SetCompare2(TIM3,1474); 
		}
		 else if(FLEFT2==1&&FRIGHT1==0&&FLEFT1==0)
       {    TIM_SetCompare1(TIM3,1525); //左前右后//慢速
	TIM_SetCompare2(TIM3,1434); } 
        else if(FRIGHT2==1&&FRIGHT1==0&&FLEFT1==0)
      {   TIM_SetCompare1(TIM3,1565); //左前右后//慢速
	TIM_SetCompare2(TIM3,1474); 	} 
	   else 
	 straight1();
		   
 }
 


  void follow_back_line_fast(void)
 {
     if(BLEFT1==1&&BRIGHT2==0)//BLEFT1==1&&BRIGHT1==0
        {  turn_bleft();
		} 
       else if(BLEFT1==0&&BRIGHT2==1)//BLEFT1==0&&BRIGHT1==1
        { turn_bright();
		} 
//		else if(BLEFT2==1&&BRIGHT1==0&&BLEFT1==0)
//		{turn_bleft_fast();
//			printf("2222");
//			}
//	   else if(BRIGHT2==1&&BRIGHT1==0&&BLEFT1==0)
//	   {turn_bright_fast();
//			 printf("3333");
//			 }
//		 else if(BLEFT3==1&&BRIGHT1==0&&BLEFT1==0)
//		{turn_bleft_fast_fast();
//			printf("4444");
//			}
//	   else if(BRIGHT3==1&&BRIGHT1==0&&BLEFT1==0)
//	   {turn_bright_fast_fast();
//			 printf("5555");
//			 }
	   else{
	   gooback1();
//		 printf("停");
		 }
 }
 
  void follow_back_line_fast1(void)
 {

     if(BLEFT1==1&&BRIGHT2==0)//BLEFT1==1&&BRIGHT1==0
        {  turn_bleft();
		} 
       else if(BLEFT1==0&&BRIGHT2==1)//BLEFT1==0&&BRIGHT1==1
        { turn_bright();
		} 
//		else if(BLEFT2==1&&BRIGHT1==0&&BLEFT1==0)
//		{turn_bleft_fast1();}
//	   else if(BRIGHT2==1&&BRIGHT1==0&&BLEFT1==0)
//	   {turn_bright_fast1();}
//		 else if(BLEFT3==1&&BRIGHT1==0&&BLEFT1==0)
//		{turn_bleft_fast1_fast();}
//	   else if(BRIGHT3==1&&BRIGHT1==0&&BLEFT1==0)
//	   {turn_bright_fast1_fast();}
	   else
		 {	gooback1(); }
		   
 }
 
 
 void follow_back_line(void)
 {
 
     
    if(BLEFT1==1&&BRIGHT2==0)//BLEFT1==1&&BRIGHT1==0
        {  turn_bleft();
		} 
       else if(BLEFT1==0&&BRIGHT2==1)//BLEFT1==0&&BRIGHT1==1
        { turn_bright();
		} 
       else{
	  gooback();
			 }
 }	 
 void follow_line_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_line();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
 void follow_line_fast_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_line_fast();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
 void follow_line_fast_delay1(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_line_fast1();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
 void follow_back_line_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_back_line();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
void follow_back_line_fast_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_back_line_fast();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}


void follow_back_line_fast_delay1(int nms)
	{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_back_line_fast1();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}


  void follow_a_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_a();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
  void follow_c_e_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
       follow_c_e();
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}

void turn_left_delay(int nms)
{  
	follow_a_delay(nms);
}
void turn_right_delay(int nms)
{
  follow_c_e_delay(nms);
}
void turn_left1_num(int num)
{
	int o=1,e=0;
  follow_a_delay(200);//原150
  while(o)
  { 
  follow_a();
  if(FLEFT1==1&&FRIGHT1==1)
  { e=e+1;
		if(e==num)
    {
		follow_a_delay(20);//原30
    o=0;
		break;
		}
		else
			follow_a_delay(200);//原150
		
	}
}
	
}
void turn_right1_num(int num)
{
int o=1,e=0;
  follow_c_e_delay(200);//原150
  while(o)
  { 
  follow_c_e();
    if(FRIGHT1==1&&FLEFT1==1)
  { e=e+1;
		if(e==num)
    {
		follow_c_e_delay(20);//原30
    o=0;
		break;
		}
		else
			follow_c_e_delay(200);//原150
		
	}
}
}
void turn_right2_num(int num)
{
int o=1;
  follow_c_e_delay(200);
  while(o)
  { 
       follow_c_e1();

  if(FRIGHT1==1&&FLEFT1==1)
  { 

		//follow_c_e_delay(30);
    o=0;
		break;
	
	}
}
}
void turn_right3_num(int num)
	{
int o=1,e=0;
  follow_c_e_delay(200);
  while(o)
  { 
  follow_c_e();
  if(FRIGHT1==1&&FLEFT1==1)
  { e=e+1;
		if(e==num)
    {
		//follow_c_e_delay(30);
    o=0;
		break;
		}
		else
			follow_c_e_delay(200);
		
	}
}
}
void turn_left_num(int num)
{
int e=0,o=1,time;
follow_a_delay(150);
while(o)
{ 
follow_a();
if(MRIGHT==1)
{ 
e=e+1;
if(e==num)
{
while(1)
{
follow_a_delay(1);
please_stop();
o=0;
break;
}
}
else
{ 
time=150;
	follow_a_delay(150);
while(time)
{ follow_a_delay(2);
if(MRIGHT==0)
{
time=0;
break;
}
time=time-1;
}
}
}
}
}
void turn_right_num(int num)
{
int e=0,o=1,time;
follow_c_e_delay(150);
while(o)
{ 
follow_c_e();
if(MRIGHT==1)
{ 
e=e+1;
if(e==num)
{
while(1)
{
follow_c_e_delay(80);
please_stop();
o=0;
break;
}
}
else
{ 
time=150;
follow_c_e_delay(150);
while(time)
{ 
	follow_c_e_delay(4);
if(MRIGHT==0)
{
time=0;
break;
}
time=time-1;
}
}
}
}
}
void follow_stop_delay(int nms)
{
	// int while_flag=1;
	 while(1)
	 {
       TIM_SetCompare1(TIM3,1500); 
	   TIM_SetCompare2 (TIM3,1500);
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		  // while_flag=0;
			 break;
		 }
		  
	 }
}

void follow_c_e(void)
{    TIM_SetCompare1(TIM3,1610); 
	 TIM_SetCompare2 (TIM3,1600);
}

void follow_c_e1(void)
{    TIM_SetCompare1(TIM3,1555); 
	 TIM_SetCompare2 (TIM3,1550);
}

void follow_a(void)
{    TIM_SetCompare1(TIM3,1390); 
	 TIM_SetCompare2 (TIM3,1400);
}


void back_to_centre(void)
 {    int e=0,o=1;
	    while(o)
	{  follow_back_line_fast();

	if(MLEFT==1)
	{  e=e+1;
	  if(e==1)
   { while(1)
	{TIM_SetCompare1(TIM3,1500); 
	 TIM_SetCompare2 (TIM3,1500);
		o=0;
	break;
		}
   }
	   else
	  {
	     follow_back_line_fast_delay(250);
	  }
	}
    }
 }void back_to_centre_2(void)
 {    int e=0,o=1;
	    while(o)
	{  follow_back_line_fast();

	if(MLEFT==1)
	{  e=e+1;
	  if(e==3)
   { while(1)
	{TIM_SetCompare1(TIM3,1500); 
	 TIM_SetCompare2 (TIM3,1500);
		o=0;
	break;
		}
   }
	   else
	  {
	     follow_back_line_fast_delay(100);
	  }
	}
    }
 }
 
  void back_to_starting_point(void)
	  {    int e=0,o=1;
	    while(o)
	{  follow_back_line_fast();

	if(MLEFT==1)
	{  e=e+1;
	  if(e==4)
   { while(1)
	{     
		if(BLEFT1==0&&BRIGHT1==0)
		{ follow_back_line_delay(160);
			while(1)
		 {   my_catch_all_inside();
			TIM_SetCompare1(TIM3,1500); 
	 TIM_SetCompare2 (TIM3,1500);}}
		else
			follow_back_line_fast();

		}
   }
	   else
	  {
	     follow_back_line_fast_delay(250);
	  }
	}
    }
 }
 void go_to_centre(void)
 { int while_flag_s=1,count_flag_s=0;
	follow_line_fast_delay(550);
	while(while_flag_s)
 {    
	 follow_line_fast();
	 if(MLEFT==1)
	{  
		count_flag_s=count_flag_s+1;
	   if(count_flag_s==3)
	   { 
 		   while(1)
			{
       please_stop();
			 while_flag_s=0;
			 break;
			}
	   }
	   else
	 { 
		
			 follow_line_fast_delay(250);
	  }
	}
 }
}
 void back_to_centre_3(void)
 {    int e=0,o=1;
	    while(o)
	{  follow_back_line();

	if(MLEFT==1)
	{  e=e+1;
	  if(e==3)
   { while(1)
	{TIM_SetCompare1(TIM3,1500); 
	 TIM_SetCompare2 (TIM3,1500);
		o=0;
	break;
		}
   }
	   else
	  {
	     follow_back_line_delay(250);
	  }
	}
    }
 }
 void back_to_centre_4(void)
{
     int e=0,o=1;
	    while(o)
	{  follow_back_line_fast();

	if(MLEFT==1)
	{  e=e+1;
	  if(e==5)//原4
   { while(1)
	{TIM_SetCompare1(TIM3,1500); 
	 TIM_SetCompare2 (TIM3,1500);
		o=0;
	break;
		}
   }
	   else
	  {
	     follow_back_line_fast_delay(250);
	  }
	}
    
 }
	}
 void up_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {    LED0=1;
	      LED1=0;
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
 void down_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
        LED0=0;
	    LED1=1;
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
void tingzhi_delay(int nms)
{
	 int while_flag=1;
	 while(while_flag)
	 {
        LED0=1;
	    LED1=1;
	   delay_ms(1);
	   nms--;
		 if(nms==0)
		 {
		   while_flag=0;
			 break;
		 }
		  
	 }
}
void left_45(void)
{
	  follow_a_delay(300);
	  follow_stop_delay(400);
}

void left_90(void)
{
		follow_a_delay(600);
       follow_stop_delay(400);

}

void right_45(void)

{   follow_c_e_delay(290);
    follow_stop_delay(400);

}


void right_90(void)
{ follow_c_e_delay(565);
  follow_stop_delay(300);
}


/*void go_to_mi(void)
{ int while_flag_s=1,count_flag_s=0;
	follow_line_delay(100);
	while(while_flag_s)
 {    
	 follow_line_fast();
	 if(MLEFT==1)
	{  
		count_flag_s=count_flag_s+1;
	   if(count_flag_s==3)
	   { 
 		   while(1)
			{
       please_stop();
			 while_flag_s=0;
			 break;
			}
	   }
	   else
	 { 
		
			 follow_line_fast_delay(250);
	  }
	}
 }
}*/
void go_to_mi(void)
{ int while_flag_s=1,count_flag_s=0;
    follow_line_delay(200);
	while(while_flag_s)
 {    
	 follow_line();
	 if(MLEFT==1)
	{  
		count_flag_s=count_flag_s+1;
        delay_ms(300);
	   if(count_flag_s==4)//扫线5次
	   { 
 		   while(1)
			{
              
       please_stop();
			 while_flag_s=0;
			 break;
			}
            
	   }
	   else
	 { 
		
			//follow_line_delay(30);//时延：每次过线只算一次  //最初删除
	  }
	}
 }
}

void go_to_xiaoquan(void)
{
//	int while_flag_s=1;
	follow_line_fast_delay(100);
	while(1)
	   {
        follow_line_fast();
        if((FLEFT1==0&&FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1||FLEFT2==1||FLEFT3==1||FLEFT4==1))
		        { 
                please_stop();
//                while_flag_s=0;
                break;
		        }

		 }
					
				 
			 }
void go_to_xiaoquan1(void)
{
//	int while_flag_s=1;
	follow_line_fast_delay(80);//400
	while(1)
	   {
        follow_line_fast();
        if((FLEFT1==0&&FRIGHT1==0)&&(FRIGHT2==1||FRIGHT3==1||FRIGHT4==1||FLEFT2==1||FLEFT3==1||FLEFT4==1))
		        { 
                please_stop();
//                while_flag_s=0;
                break;
		        }

		 }
					
				 
			 }
void back_to_xiaoquan(void)
{
	int while_flag_s=1;
	follow_back_line_fast_delay(500);
	while(while_flag_s)
	   {
        follow_back_line_fast();
        if((BLEFT1==0&&BRIGHT1==0)&&(BRIGHT2==1||BRIGHT3==1||BRIGHT4==1)&&(BLEFT2==1||BLEFT3==1||BLEFT4==1))
		        { 
                please_stop();
                while_flag_s=0;
                break;
		        }

		 }
					
				 
			 }

			 
/*void go_to_daquan(void)
{    int while_flag_s=1;
    	follow_back_line_delay(350);
	   while(while_flag_s)
	      {
			  follow_back_line_fast();
        if(LEFT==1)
		    {    
				   while(1)
	            {
	              please_stop();
                while_flag_s=0;
                break;
		        }
		    }
			}
     
}*/
			 void go_to_daquan(void)
{ int while_flag_s=1,count_flag_s=0;
    	
	while(while_flag_s)
 {    
	 follow_line();
	 if(FLEFT4==1)
	{  
		count_flag_s=count_flag_s+1;
             delay_ms(300);
	   if(count_flag_s==2)
	   { 
 		   while(1)
			{
             please_stop();
			 while_flag_s=0;
			 break;
			}
	   }  
       else
	 { 
		
			 delay_ms(50);//时延：每次过线只算一次
	  }
	   
	}
 }
}

/*void go_to_daquan2(void)
{    
	int while_flag_s=1,count_flag_s=0;
	follow_line_fast_delay(1150);
	while(while_flag_s)
 {    
	 follow_line_fast();
	 if(MLEFT==1)
	{  
		count_flag_s=count_flag_s+1;
	   if(count_flag_s==2)
	   { 
 		   while(1)
			{
       please_stop();
			 while_flag_s=0;
			 break;
			}
	   }
	   else
	 { 
		
			 follow_line_fast_delay(200);
	  }
	}
 }
}*/

void go_to_daquan2(void)
{    
	int while_flag_s=1,count_flag_s=0;
	follow_line_fast_delay(1150);
	while(while_flag_s)
 {    
	 follow_line_fast();
	 if(MLEFT==1)
	{  
		count_flag_s=count_flag_s+1;
	   if(count_flag_s==2)
	   { 
 		   while(1)
			{
       please_stop();
			 while_flag_s=0;
			 break;
			}
	   }
	   else
	 { 
		
			 follow_line_fast_delay(200);
	  }
	}
 }
}














