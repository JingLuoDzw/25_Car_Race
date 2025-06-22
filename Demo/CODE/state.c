#include "headfile.h"
int state_lead = 0;
int Flag_Right_Angle = 0;	//直角不同阶段的指针
int Flag_Circ = 0;				//圆环不同阶段的指针
int Flag_Obstacle = 0;		//路障	
int flag_turn = 0;				//直路元素的指针
int Flag_Out = 0;					//出库元素的指针
float Sum_Distance = 0, Sum_Angle = 0;
//char state[30] = {Track, Obstacle, Track, Small_Circ_Left, Track, Ramp, Track, Track, Stop};	//2024赛道元素顺序
//char state[30] = {Track, Small_Circ_Left, Track, Small_Circ_Left, Track, Track, Track, Stop};	//赛道元素顺序

//char state[30] = {Track, Track, Track, Track, Track, Stop};	//赛道元素顺序
void state_detect(int *temp)		//状态检测
{
    adc_get(temp);
    switch (state[state_lead])		//默认值为0 进track 
    {
				case Track:
						if (Track_Jump(temp))							 		state_lead++;
						break;
//				case Left_Right_Angle:
//						if (Left_Right_Angle_Jump(&Flag_Right_Angle))			state_lead++;
//						break;
//				case Right_Right_Angle:
//						if (Right_Right_Angle_Jump(&Flag_Right_Angle))		state_lead++;
//						break;
				case Big_Circ_Left:
						if (Big_Circ_Left_Jump(&Flag_Circ)) 	state_lead++;
						break;
				case Big_Circ_Right:
						if (Big_Circ_Right_Jump(&Flag_Circ))	state_lead++;
						break;
				case Small_Circ_Left:
						if (Small_Circ_Left_Jump(&Flag_Circ))	state_lead++;
						break;
				case Small_Circ_Right:
						if (Small_Circ_Right_Jump(&Flag_Circ))state_lead++;
						break;
				case Obstacle:
						if (Obstacle_Jump(&Flag_Obstacle))		state_lead++;
						break;
				case Ramp:
						if (Ramp_Jump())      								state_lead++;
						break;
				case Out:
						if (Out_Jump())												state_lead++;
						break;
				default:
						break;
    }
}
int Track_Jump(int *temp)	//只要检测到元素就返回1
{
    switch (state[state_lead + 1])	//检测第二个元素
    {
				case Big_Circ_Left:														//检测到圆环就置位，然后返回
						if (temp[0] > 1200 && temp[3] > 1000)
						{
//								P67 = 1;
								Flag_Circ = 1;
								return 1;
						}
						break;
				case Small_Circ_Left:
						if (temp[0] > Circ_Jump_Left[0] && temp[1] > Circ_Jump_Left[1] && temp[3] > Circ_Jump_Left[2] && temp[4] > Circ_Jump_Left[3])
						{
								P67 = 1;
								Flag_Circ = 1;
								return 1;
						}
						break;
				case Big_Circ_Right:
						if (temp[0] > 1000 && temp[4] > 1200 && temp[1] < 500 && temp[3] < 500)
						{
//								P67 = 1;
								Flag_Circ = 1;
								return 1;
						}
						break;
				case Small_Circ_Right:
		//      if((temp[0]+temp[3]>3000)&&(temp[1]+temp[2]>2000))
						if (temp[0] > Circ_Jump_Right[0] && temp[3] > Circ_Jump_Right[2] && temp[4] > Circ_Jump_Right[3])
						{
//								P67 = 1;
								Flag_Circ = 1;
								return 1;
						}
						break;
				case Obstacle:
						if (dl1b_distance_mm < 700)
						{
//								P67 = 1;
								Flag_Obstacle = 1;
								return 1;
						}
						break;
				case Ramp:
						if (temp[0] > 1700)
						{
//								P67 = 1;
								return 1;
						}
						break;
				case Stop:
						return 1;
						break;
//				case Garage_In:
//						if (P26 == 0)
//						{
//								return 1;
//						}
//						break;
				case Out:
						return 1;
						break;
				default:
						break;
    }
		
    return 0;			//没有检测到元素，返回0
}

int Out_Jump()
{
//		switch ((*Flag))
//		{
//		case 1:
				Sum_Angle += Single_Angle_Get();
				if(Sum_Angle < Out_Jump_Angle)
				{
//					P67 = 1;
					Sum_Angle = 0;
//					state_lead=10;
//					(*Flag) = 0;
					return 1;
				}
//				break;
//    default:
//        break;
//		}
		return 0;
}

int Small_Circ_Left_Jump(int *Flag)
{
    switch ((*Flag))
    {
    case 1:
				
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > Circ_Left_Dis_Start)
        {		
						P67 = 0;
            Sum_Distance = 0;
            (*Flag)++;
//						state_lead=10;
        }
        break;
    case 2:
				
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle > Circ_Left_Angle)
        {
//						P67 = 0;
            Sum_Angle = 0;
            (*Flag)++;
//						state_lead=8;
        }
        break;
    case 3:
//				P67 = 1;
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > Circ_Left_Dis_Final)
        {
//						P67 = 1;
            Sum_Distance = 0;
            (*Flag) = 0;
//						state_lead=8;
            return 1;
        }
				break;
    default:
        break;
    }
    return 0;

	
//    switch ((*Flag))
//    {
//    case 1:
//				
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//        if (Sum_Distance > 50)
//        {		
////						P67 = 0;
//            Sum_Distance = 0;
//            (*Flag)++;
////						state_lead=8;
//        }
//        break;
//    case 2:
//        Sum_Angle += Single_Angle_Get();
//        if (Sum_Angle > 60)
//        {	
////						P67 = 1;
//            Sum_Angle = 0;
//            (*Flag)++;
////						state_lead=8;
//        }
//        break;
//    case 3:
//				
//        Sum_Angle += Single_Angle_Get();
//        if (Sum_Angle > 247)
//        {
//						P67 = 0;
//            Sum_Angle = 0;
//            (*Flag)++;
////						state_lead=8;
//        }
//        break;
//    case 4:
////				P67 = 1;
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//        if (Sum_Distance > 80)
//        {
////						P67 = 1;
//            Sum_Distance = 0;
//            (*Flag) = 0;
//						state_lead=8;
//            return 1;
//        }
//				break;
//    default:
//        break;
//    }
//    return 0;
}

int Small_Circ_Right_Jump(int *Flag)
{
    switch ((*Flag))
    {
    case 1:
//      printf("00000000000000000000\r\n");
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > Circ_Right_Dis_Start)
        {
            Sum_Distance = 0;
            (*Flag)++;
        }

        break;
    case 2:

        Sum_Angle += Single_Angle_Get();
//      printf("%f\r\n",Sum_Angle);
        if (Sum_Angle < Circ_Right_Angle)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
//    case 3:
//        Sum_Angle += Single_Angle_Get();
//        if (Sum_Angle < -290)
//        {
//            Sum_Angle = 0;
//            (*Flag)++;
//        }
//        break;
    case 3:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > Circ_Right_Dis_Final)
        {
            Sum_Distance = 0;
            (*Flag) = 0;
            return 1;
        }
        break;
    default:
        break;
    }
//  printf("%d\r\n",(*Flag));
    return 0;
}


int Big_Circ_Left_Jump(int *Flag)		//走完所有阶段才会返回1，才会继续检测下一个元素
{
    switch (*Flag)
    {
    case 1:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
        if (Sum_Distance > 50)
        {

            Sum_Distance = 0;
            (*Flag)++;
        }
        break;
    case 2:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle > 35)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 3:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle > 290)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 4:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > 60)
        {
            Sum_Distance = 0;
            (*Flag) = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

int Big_Circ_Right_Jump(int *Flag)
{
    switch (*Flag)
    {
    case 1:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > 50)
        {
            Sum_Distance = 0;
            (*Flag)++;
        }
//				state_lead = 12;
        break;
    case 2:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle < -35)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 3:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle < -290)//275
        {
            Sum_Angle = 0;
            (*Flag)++;
//					state_lead=8;
        }
        break;
    case 4:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > 60)
        {
//						P67 = 0;
            Sum_Distance = 0;
            (*Flag) = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}



int Obstacle_Jump(int *Flag)
{
    switch (*Flag)
    {
    case 1:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle > 30)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 2:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//      printf("%f\r\n",Sum_Distance);
        if (Sum_Distance > 30)
        {
            Sum_Distance = 0;
            (*Flag)++;

        }
        break;
    case 3:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle < -30)
        {
            P32 = 1;
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 4:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//      printf("%f\r\n",Sum_Distance);
        if (Sum_Distance > 30)
        {
            Sum_Distance = 0;
            (*Flag)++;
        }
        break;
    case 5:
        Sum_Angle += Single_Angle_Get();
        if (Sum_Angle < -20)
        {
            Sum_Angle = 0;
            (*Flag)++;
        }
        break;
    case 6:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
        if (Sum_Distance > 30)
        {
            Sum_Distance = 0;
            (*Flag) = 0;
						return 1 ;
        }
        break;
    default:
        break;
    }
    return 0;
}


int Ramp_jump(void)
{
	Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//	P67 = 1;
	if (Sum_Distance > 360)
	{
//			P67 = 0;
//			state_lead = 10;
			return 1;	
	}
	else 
			return 0;
}


uint32 stop_flag = 0;
uint8 stop_jump(void)
{
	if(adc_value[0]<50&&adc_value[1]<50&&adc_value[3]<50&adc_value[4]<50)
	{
			stop_flag++;
			if(stop_flag>100)
			{
				return 1;
			}
			return 0;
	}
	else
	{
			stop_flag = 0;
			return 0;
	}
}



//int Ramp_Jump(int *Flag)
//{
//
//}


//    switch (flag_turn)				//没检测到元素，就根据直道元素指针执行操作							
//    {
//				case cross:						//十字
//						Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//						if (Sum_Distance > 40)
//						{
//								Sum_Distance = 0;
//								flag_turn = 0;
//						}
//						return 0;
//						break;
//				case right_angle:
//						break;
//				case normal:
//						break;
//				default :
//						break;
//    }

//  if(max_count(temp[5],temp[6])>600&&min_count(temp[5],temp[6])>600&&temp[4]>800&&temp[7]>800)
//  {
//      flag_turn=cross;
//      printf("%d,%d,%d,%d,%d,%d,%d,%d\r\n",adc_value[0],adc_value[1],adc_value[2],
//									adc_value[3],adc_value[4],adc_value[5],adc_value[6],adc_value[7]);
//  }
		
//    if (abs(temp[5] - temp[6]) > 400)
//    {
//        flag_turn = right_angle;
//    }
//    else
//    {
//        flag_turn = normal;
//    }


//				case Left_Right_Angle:														
//						if (temp[0] < 650 && temp[4] < 650 && temp[1] >440 && temp[3] >110
//							&& temp[1] - temp[3] >300 && abs(temp[0] - temp[4]) < 120)
//						{
////								P67 = 1;
////								delay_ms(100);
//								beep_on();
//								Flag_Right_Angle = 1;
//								return 1;
//						}
//						break;
//				case Right_Right_Angle:														
//						if (temp[0] < 800 && temp[4] < 800 && temp[1] >190 && temp[3] >60
//							&& temp[3] - temp[1] >300 && abs(temp[0] - temp[4]) < 120)
//						{
//								beep_on();
//								Flag_Right_Angle = 1;
//								return 1;
//						}
//						break;

int Left_Right_Angle_Jump(int *Flag)
{
	switch (*Flag)
    {
    case 1:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
					Sum_Angle += Single_Angle_Get();
					if (Sum_Angle > 90)
					{
						Sum_Angle = 0;
						(*Flag) = 0;
						return 1;
					}
//        if (Sum_Distance > 200)
//        {
//            Sum_Distance = 0;
//            (*Flag)++;
//					  state_lead = 6;
//        }
        break;
//    case 2:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
//		
//        if (Sum_Distance > 160)
//        {
//            Sum_Distance = 0;
//            (*Flag)++;
//					  state_lead = 6;
//        }
//    case 3:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
//		
//        if (Sum_Distance > 200)
//        {
//            Sum_Distance = 0;
//            (*Flag)++;
//					  state_lead = 6;
//        }
//    case 4:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//        if (Sum_Distance > 40)
//        {
//            Sum_Distance = 0;
//            (*Flag) = 0;
//            return 1;
//        }
    default:
        break;
    }
    return 0;
}

int Right_Right_Angle_Jump(int *Flag)
{
	switch (*Flag)
    {
    case 1:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
		
        if (Sum_Distance > 200)
        {
            Sum_Distance = 0;
            (*Flag)++;
//					  state_lead = 6;
        }
        break;
    case 2:
        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
		
        if (Sum_Distance > 160)
        {
            Sum_Distance = 0;
            (*Flag)++;
					  state_lead = 6;
        }
        break;
//    case 3:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;//计算实例里程数
//		
//        if (Sum_Distance > 200)
//        {
//            Sum_Distance = 0;
//            (*Flag)++;
//					  state_lead = 6;
//        }
//    case 4:
//        Sum_Distance += (motor_L_pid.ActValue + motor_R_pid.ActValue) * isr_time * 0.5;
//        if (Sum_Distance > 40)
//        {
//            Sum_Distance = 0;
//            (*Flag) = 0;
//            return 1;
//        }
    default:
        break;
    }
    return 0;
}
