#include "headfile.h"
float temp = 0;
extern char state[30];
int pid_lead = 0;

void Dir_Loop(float error, float speed_goal, int flag)
{

		if((state[state_lead]==Big_Circ_Left)||(state[state_lead]==Big_Circ_Right)||
			(state[state_lead]==Small_Circ_Left)||(state[state_lead]==Small_Circ_Left))
		{
				pid_lead = 0;
		}
		else if((state[state_lead]==Ramp))
		{
				pid_lead = 0;
		}
		else if((state[state_lead]==Obstacle))
		{
				pid_lead = 0;
		}
		else
				pid_lead = 0;
		
		dir_loop_pid.ek =  error;
		temp =  fabs(error) * Kp1[pid_lead]* dir_loop_pid.ek
						+ Kp2[pid_lead] * dir_loop_pid.ek
						- Kd1[pid_lead] * imu660ra_gyro_z / 65.6
						+ Kd2[pid_lead] * (dir_loop_pid.ek - dir_loop_pid.ek_1);

		dir_loop_pid.ek_1 = dir_loop_pid.ek;
		
    motor_L_pid.SetValue = speed_goal - temp;
    motor_R_pid.SetValue = speed_goal + temp;
		
//	  motor_L_pid.SetValue = 180 ;
//    motor_R_pid.SetValue = 180 ;
		
//		if(error < -0.4)
//		{
//			motor_L_pid.SetValue = 1.5*speed_goal - temp;
//			motor_R_pid.SetValue = 50;
//		}else	if(error > 0.4)
//		{
//			motor_L_pid.SetValue = 50;
//			motor_R_pid.SetValue = 1.5*speed_goal + temp;
//		}else	if(error < -0.3)
//		{
//			motor_L_pid.SetValue = 1.2*speed_goal - temp;
//			motor_R_pid.SetValue = 100;
//		}else	if(error > 0.3)
//		{
//			motor_L_pid.SetValue = 100;
//			motor_R_pid.SetValue = 1.2*speed_goal + temp;
//		}else
//		{
//			motor_L_pid.SetValue = speed_goal - temp;
//			motor_R_pid.SetValue = speed_goal + temp;
//		}

//		if(fabs(error)>0.4)
//		{
//			motor_L_pid.SetValue = 110 - temp;
//			motor_R_pid.SetValue = 110 + temp;
//		}else	if(fabs(error)>0.2)
//		{
//			motor_L_pid.SetValue = 135 - temp;
//			motor_R_pid.SetValue = 135 + temp;
//		}else
//		{
//			motor_L_pid.SetValue = speed_goal - temp;
//			motor_R_pid.SetValue = speed_goal + temp;
//		}
				
}




//void Dir_Loop(float error, float speed_goal, int flag)
//{
////  if(flag==0)
////  {
////
////  dir_loop_pid.KP=Kp_Select(error);
////      dir_loop_pid.ek =  error;
////   temp= dir_loop_pid.KP * dir_loop_pid.ek  +100*dir_loop_pid.ek
////  - imu660ra_gyro_z / 65.6
////  + dir_loop_pid.KD * (dir_loop_pid.ek - dir_loop_pid.ek_1)
////  ;
////  dir_loop_pid.ek_1=dir_loop_pid.ek;
//// ;
////  }
////  else
////  printf("%f\r\n",error);
//    {
//        dir_loop_pid.KP = Kp_Select(error);
//        dir_loop_pid.ek =  error;
//				temp =  fabs(error) * 500 * dir_loop_pid.ek //800 200  /600 300
//								+ 300 * dir_loop_pid.ek
//								- imu660ra_gyro_z / 65.6
//								+ dir_loop_pid.KD * (dir_loop_pid.ek - dir_loop_pid.ek_1);
////      printf("%f\r\n",error);
//        dir_loop_pid.ek_1 = dir_loop_pid.ek;
////  temp=temp;
//    }
////  printf("%f\r\n",temp);
//		
////		if(speed_goal - temp > 2*speed_goal)
////        {motor_L_pid.SetValue =2*speed_goal;}
////				else
////    if(speed_goal + temp >2*speed_goal)
////        motor_R_pid.SetValue = 2*speed_goal;
////				else
////		if(speed_goal - temp <-1*speed_goal)
////				{motor_L_pid.SetValue =-1*speed_goal;}
////				else
////    if(speed_goal + temp <-1*speed_goal)
////        motor_R_pid.SetValue = -1*speed_goal;
////				else
////				{
//					motor_L_pid.SetValue = speed_goal - temp;
//					motor_R_pid.SetValue = speed_goal + temp;
////				}

//}

//void showmenu()
//{
//	if(P42 == 0)
//	{
//		position = position + 16;
//		lcd_clear(WHITE);
//		dapos++;
//		delay_ms(50);
//		if(position == 32)
//		{
//			position = 0;
//			dapos = 0;
//		}
//	}
//	if(P71 == 0)
//	{
//		position = position - 16;
//		lcd_clear(WHITE);
//		dapos--;
//		delay_ms(50);
//		if(position == -16)
//		{
//			position = 16;
//			dapos = 1;
//		}
//	}
//	if(P72 == 0)
//	{
//		da[dapos] = da[dapos] - 5;
//		delay_ms(150);
//		if(da[dapos] < 0)
//		{
//			da[dapos] = 0;
//		}
//	}
//	if(P70 == 0)
//	{
//		da[dapos] = da[dapos] + 5;
//		delay_ms(150);
//	}
//	lcd_showchar(50,position,'<');
//}

//void Dir_Loop(float error,float speed_goal,int flag)
//{

//if(flag==0)
//{
//  count++;
//  if(count<60)
//  {
//      P67=1;
//  }
//  else
//  {
//      P67=0;
//      count=0;
//  }
//
//  dir_loop_pid.KP=Kp_Select_1(error);
//}
//else
//{
//  count=0;
//  P67=0;
//      dir_loop_pid.KP=Kp_Select(error);
//}

//  dir_loop_pid.ek =  error;
//   temp= dir_loop_pid.KP* dir_loop_pid.ek
////    -imu660ra_gyro_z / 65.6
//  + dir_loop_pid.KD * (dir_loop_pid.ek - dir_loop_pid.ek_1)
//  ;
//  dir_loop_pid.ek_1=dir_loop_pid.ek;
//  motor_L_pid.SetValue=speed_goal-temp;
//  motor_R_pid.SetValue=speed_goal+temp;
//}

float  Kp_Select(float error)
{
    return fabs(error) * 50;
//    if(error < 0.05 && error > -0.05) // section1
//      return 150;
//    else if(error < 0.1 && error > -0.1) // section2
//      return 150;
//    else if(error < 0.15 && error > -0.15) //3
//          return 150;
//    else if(error <0.2 && error > -0.2)
//      return  150;
//    else if(error < 0.25 && error > -0.25)
//      return  150;
//    else if(error <0.3 && error > -0.3)
//      return 180;
//    else if(error < 0.35 && error > -0.35)
//          return 210;
//    else if(error < 0.4 && error > -0.4)
//      return 240;
//    else if(error < 0.45 && error > -0.45)
//      return 270;
//    else if(error < 0.5 && error > -0.5)
//      return 300;
//    else if(error < 0.55 && error > -0.55)
//      return 330;
//    else
//      { return 400;}
}

//void angle_loop()
//{
//  float angle_speed=0;
//  angle_speed=(motor_R_pid.SetValue-motor_L_pid.SetValue)/15.5;
//
//}

//void Dir_Loop(float error,float speed_goal)
//{

//  float inc=0;
////    dir_loop_pid.KP=Kp_Select(error)*0.6;
//      dir_loop_pid.ActValue =  error;

//      inc=PID_Control_Inc(&dir_loop_pid,1);
//  if(inc>-3&&inc<3)
//  {inc=0;}
//      temp+=inc;
//  dir_loop_pid.ek_1=dir_loop_pid.ek;
////temp=temp*0.6;
////    printf("%f\r\n",temp);
////    temp=temp>speed_goal?speed_goal:temp;
////    temp=temp<(0-speed_goal)?(0-speed_goal):temp;
//  temp=temp>100?100:temp;
//  temp=temp<(-100)?(-100):temp;
//  motor_L_pid.SetValue=speed_goal+temp;
//  motor_R_pid.SetValue=speed_goal-temp;
//}