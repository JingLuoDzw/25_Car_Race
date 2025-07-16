#include "headfile.h"
int adc_value[8] = {0};		//�˸����ֵ
uint8 uart_delay = 0;		//whileѭ����δ��ڷ���һ������
extern uint16 dl1b_distance_mm;
extern float Sum_Distance;
int press_flag = 0;
//	Track		Out		Small_Circ_Right	Small_Circ_Left		Out, Track, 
//char state[30] = {Track, Track, Track, Track, Track, Track, Stop};	
char state[30] = {Track, Small_Circ_Left, Track, Small_Circ_Left, Track, Small_Circ_Left, Track, Small_Circ_Left, Track, Track, Track, Stop};	//2025����Ԫ��˳��

////�ٶ�200
//int SPEED = 200 ;
////ת��
//int Kp1[5]=  { 350 , 0 , 0 , 0 , 0 };		//320	290	0.3�������仹��		300	320	0.4�����仹���ԣ�������ǿ
//int Kp2[5]=  { 370 , 0 , 0 , 0 , 0 };
//float Kd1[5]={ 0.63 , 0 , 0 , 0 , 0 };
//float Kd2[5]={ 30 , 0 , 0 , 0 , 0 };
////�󻷵���ж�����
//int Circ_Jump_Left[4] = { 1900 , 1000 , 500 , 1900 };
////��״̬�ж�����
//int Circ_Left_Dis_Start = 15 ;
//int Circ_Left_Angle = 335 ;
//int Circ_Left_Dis_Final = 50 ;
////����Ϊ
//int Circ_Left_Speed_L = 180 ;
//int Circ_Left_Speed_R = 300 ;
//int Circ_Left_Speed_Out = 180 ;
////����
//float Out_Jump_Angle = - 70 ;
//int Out_Speed_L = 280 ;
//int Out_Speed_R = 80 ;
////�һ�
//int Circ_Jump_Right[4] = { 1200 , 0 , 200 , 1000 };
//int Circ_Right_Dis_Start = 10 ;
//int Circ_Right_Angle = - 340 ;
//int Circ_Right_Dis_Final = 80 ;
//int Circ_Right_Speed_L = 250 ;
//int Circ_Right_Speed_R = 150 ;
//int Circ_Right_Speed_Out = 150 ;

////�ٶ�180
//int SPEED = 180 ;
////ת��
//int Kp1[5]=  { 300 , 0 , 0 , 0 , 0 };		//320	290	0.3�������仹��		300	320	0.4�����仹���ԣ�������ǿ
//int Kp2[5]=  { 320 , 0 , 0 , 0 , 0 };
//float Kd1[5]={ 0.42 , 0 , 0 , 0 , 0 };
//float Kd2[5]={ 15 , 0 , 0 , 0 , 0 };
////�󻷵���ж�����
//int Circ_Jump_Left[4] = { 1900 , 1000 , 500 , 1900 };
////��״̬�ж�����
//int Circ_Left_Dis_Start = 15 ;
//int Circ_Left_Angle = 335 ;
//int Circ_Left_Dis_Final = 50 ;
////����Ϊ
//int Circ_Left_Speed_L = 180 ;
//int Circ_Left_Speed_R = 300 ;
//int Circ_Left_Speed_Out = 180 ;
////����
//float Out_Jump_Angle = - 70 ;
//int Out_Speed_L = 280 ;
//int Out_Speed_R = 80 ;
////�һ�
//int Circ_Jump_Right[4] = { 1200 , 0 , 200 , 1000 };
//int Circ_Right_Dis_Start = 10 ;
//int Circ_Right_Angle = - 340 ;
//int Circ_Right_Dis_Final = 80 ;
//int Circ_Right_Speed_L = 250 ;
//int Circ_Right_Speed_R = 150 ;
//int Circ_Right_Speed_Out = 150 ;

//�ٶ�150
int SPEED = 150 ;
//ת��
int Kp1[5]=  { 200 , 0 , 0 , 0 , 0 };		//
int Kp2[5]=  { 150 , 0 , 0 , 0 , 0 };
float Kd1[5]={ 0.2 , 0 , 0 , 0 , 0 };
float Kd2[5]={ 0 , 0 , 0 , 0 , 0 };
//�󻷵���ж�����
int Circ_Jump_Left[4] = { 2000 , 1000 , 500 , 2000 };
//��״̬�ж�����
int Circ_Left_Dis_Start = 20 ;
int Circ_Left_Angle = 345 ;
int Circ_Left_Dis_Final = 50 ;
//����Ϊ
int Circ_Left_Speed_L = 150 ;
int Circ_Left_Speed_R = 240 ;
int Circ_Left_Speed_Out = 150 ;
//����
int Out_Jump_Angle = - 70 ;
int Out_Speed_L = 250 ;
int Out_Speed_R = 50 ;
//�һ�
int Circ_Jump_Right[4] = { 2000 , 500 , 1000 , 2000 };
int Circ_Right_Dis_Start = 10 ;
int Circ_Right_Angle = - 340 ;
int Circ_Right_Dis_Final = 80 ;
int Circ_Right_Speed_L = 250 ;
int Circ_Right_Speed_R = 150 ;
int Circ_Right_Speed_Out = 150 ;

//�ٶȻ�PID	
int KP_SPEED_L = 100 ;
int KP_SPEED_R = 100 ;
int KI_SPEED_L = 19 ;
int KI_SPEED_R = 19 ;
int KD_SPEED_L = 0 ;
int KD_SPEED_R = 0 ;

int main()
{
    board_init();
    pit_timer_ms(TIM_1, 5);
    printf("pit init\r\n");
    pit_timer_ms(TIM_4, 5);
    NVIC_SetPriority(TIMER1_IRQn, 2);
    NVIC_SetPriority(UART4_IRQn, 3);
    InitPID();
		iap_init();
    EnableGlobalIRQ(); // �������ж�
    printf("all init\r\n");
    printf("motor pid set value\r\n");
		Read_FLASH();
	
//		pwm_duty(PWMA_CH4P_P66, 3000 );		//			����У��
//		pwm_duty(PWMA_CH1P_P60, 3000 );		//�Ҹ�
//		pwm_duty(PWMA_CH3P_P64, 3000 );		//����
//		pwm_duty(PWMA_CH2P_P62, 3000 );	
//		P42		//����
//		P70		//��
//		P72		//��
//		P71		//��
//		P73		//��
	
//		motor_L_pid.SetValue = 0 ;
//    motor_R_pid.SetValue = 0 ;
		
//		delay_ms(7000);
		start_0 = 1;
		
    while (1)			//����ѭ��
    {
				if(!P42){
				sum_menu_flag += 1;
					if(sum_menu_flag >= 100){
						menu_flag += 1;
						if(menu_flag >= 2){
							menu_flag = 0;
						}
					}
				}
				if(menu_flag){
				adjust_menu();
				}
        if (TIM1_Flag)        {
            uart_delay++;
            if (uart_delay > 4)
            {
                uart_delay = 0;
							
								printf("%d,%d,%d,%d\r\n", adc_value[0], adc_value[1],
																					adc_value[3], adc_value[4]);
							
//                printf("%f,%f,%f,%f\r\n", motor_L_pid.ActValue, motor_R_pid.ActValue,
//																					motor_L_pid.SetValueTmp, motor_R_pid.SetValueTmp);
							
            }
						
            P52 = 0;		//LED��
            imu660ra_get_gyro();		//������
						
//						dl1b_get_distance();		//2024����
					
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
