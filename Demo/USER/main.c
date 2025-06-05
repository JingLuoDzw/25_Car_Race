#include "headfile.h"
int adc_value[8] = {0};		//八个电感值
uint8 uart_delay = 0;		//while循环五次串口发送一次数据
extern uint16 dl1b_distance_mm;
extern float Sum_Distance;
//	Track		Out		Small_Circ_Right	Small_Circ_Left
char state[30] = {Track, Out, Track, Small_Circ_Left, Track, Small_Circ_Left, Track, Track, Track, Stop};	//2025赛道元素顺序
//速度
int SPEED = 150;
//转向环
int Kp1[5]={ 350 , 0 , 0 , 0 , 0 };	//280.350		350.250		350.200.0.5一米二330稳定		350.220.0.7	360还好
int Kp2[5]={ 200 , 0 , 0 , 0 , 0 };
float Kd1[5]={ 0.5 , 0 , 0 , 0 , 0 };
float Kd2[5]={ 0 , 0 , 0 , 0 , 0 };
//左环电感判断条件
int Circ_Jump_Left[4] = { 1000 , 1000 , 0 , 1000 };
//左环状态判断条件
int Circ_Left_Dis_Start = 10 ;
int Circ_Left_Angle = 340 ;
int Circ_Left_Dis_Final = 80 ;
//左环行为
int Circ_Left_Speed_L = 150 ;
int Circ_Left_Speed_R = 250 ;
int Circ_Left_Speed_Out = 150 ;
//出库
float Out_Jump_Angle = - 70 ;
int Out_Speed_L = 250 ;
int Out_Speed_R = 50 ;

int Circ_Jump_Right[4] = { 1000 , 0 , 1000 , 1000 };
int Circ_Right_Dis_Start = 10 ;
int Circ_Right_Angle = - 340 ;
int Circ_Right_Dis_Final = 80 ;
int Circ_Right_Speed_L = 250 ;
int Circ_Right_Speed_R = 150 ;
int Circ_Right_Speed_Out = 150 ;

int main()
{
    board_init();
    pit_timer_ms(TIM_1, 5);
    printf("pit init\r\n");
    pit_timer_ms(TIM_4, 5);
    NVIC_SetPriority(TIMER1_IRQn, 2);
    NVIC_SetPriority(UART4_IRQn, 3);
    InitPID();
    EnableGlobalIRQ(); // 开启总中断
    printf("all init\r\n");
    printf("motor pid set value\r\n");
	
//		pwm_duty(PWMA_CH4P_P66, 3000 );		//			引脚校正
//		pwm_duty(PWMA_CH1P_P60, 3000 );		//右负
//		pwm_duty(PWMA_CH3P_P64, 3000 );		//左正
//		pwm_duty(PWMA_CH2P_P62, 3000 );	
	
//		motor_L_pid.SetValue = 0 ;
//    motor_R_pid.SetValue = 0 ;
		
		delay_ms(7000);
		start_0 = 1;
		
    while (1)			//正常循迹
    {
        if (TIM1_Flag)
        {
            uart_delay++;
            if (uart_delay > 4)
            {
                uart_delay = 0;
							
//								printf("%d,%d,%d,%d\r\n", adc_value[0], adc_value[1],
//																					adc_value[3], adc_value[4]);
							
//                printf("%f,%f,%f,%f\r\n", motor_L_pid.ActValue, motor_R_pid.ActValue,
//																					motor_L_pid.SetValueTmp, motor_R_pid.SetValueTmp);
							
            }
						
            P52 = 0;		//LED亮
            imu660ra_get_gyro();		//陀螺仪
						dl1b_get_distance();
					
            state_detect(adc_value);
					
						switch (state[state_lead])
						{
								case Track:
										Track_Action(adc_value);
										break;
								case Out:
										Out_Action();
								case Big_Circ_Left:
								case Small_Circ_Left:
										Circ_Left_Action(adc_value);
										break;
								case Big_Circ_Right:
								case Small_Circ_Right:
										Circ_Right_Action(adc_value);
										break;
								case Obstacle:
										Obstacle_Action();
										break;
								case Ramp:
										Track_Action(adc_value);
										break;
								case Stop:
										Stop_Action();
//								case Left_Right_Angle:
//										Left_Right_Angle_Action(adc_value);
//								case Right_Right_Angle:
//										Right_Right_Angle_Action(adc_value);
						}
										
//						lcd_showint32(0,0,adc_value[0],4);
//						lcd_showint32(0,1,adc_value[1],4);
//						lcd_showint32(0,2,adc_value[3],4);
//						lcd_showint32(0,3,adc_value[4],4);
						
//						lcd_showint16(0,5,imu660ra_gyro_z);
//						lcd_showfloat(0,6,error,1,6);
						
//						lcd_showint32(0,4,adc_value[2],4);
//						lcd_showint32(0,5,Flag_Circ,4);
//						lcd_showint32(0,6,Sum_Distance,4);
//						lcd_showint32(0,7,(int)state_lead,4);
//						lcd_showint32(0,8,(int)dl1b_distance_mm,4);

            TIM1_Flag = 0;
            P52 = 1;
        }
    }
}
