#include "headfile.h"
//float cs_motor_l_pid[3]={50,10.5,15};//float cs_motor_r_pid[3]={50,10,0};
//float cs_motor_r_pid[3]={50,10.5,15};
//float cs_dir_loop_pid[3]={160,0,300};
int adc_value[8] = {0};		//�˸����ֵ
int i = 0;		//��ʱѭ��
float sum = 0;		//Ŀǰû�з�����ʲô��
uint8 uart_delay = 0;		//whileѭ����δ��ڷ���һ������
//extern da[2];
extern uint16 dl1b_distance_mm;
extern float Sum_Distance;
//extern float error;

int main()
{
    board_init(); 
    pit_timer_ms(TIM_1, 5);
    printf("pit init\r\n");
    pit_timer_ms(TIM_4, 5);
    NVIC_SetPriority(TIMER1_IRQn, 2);
    NVIC_SetPriority(UART4_IRQn, 3);
    InitPID();
//    for (i = 0; i < 10; i++)
//    {
//        delay_ms(100);
//    }
    EnableGlobalIRQ(); // �������ж�
    printf("all init\r\n");
    printf("motor pid set value\r\n");
//		pwm_duty(PWMA_CH4P_P66, 3000);		//����У��
//		pwm_duty(PWMA_CH1P_P60, 3000);		//�Ҹ�
//		pwm_duty(PWMA_CH3P_P64, 3000);		//����
//		pwm_duty(PWMA_CH2P_P62, 3000);		
//		lcd_set_region(10,10,0,0);
//		motor_L_pid.SetValue = 0;
//    motor_R_pid.SetValue = 0;
		
		delay_ms(7000);
		start_0 = 1;
//		motor_L_pid.SetValue = 330; //����Ҫ����speed.c�е��ٶ�
//		motor_R_pid.SetValue = 330;

//		while(1)		//�����
//		{
//			state_detect(adc_value);		//��ȡ���ֵ
//			lcd_showint32(0,5,adc_value[2],4);
//			if(adc_value[2]>850)
//			{
//				motor_L_pid.SetValue = 300; //����Ҫ����speed.c�е��ٶ�
//				motor_R_pid.SetValue = 300;
//				lcd_clear(WHITE);		//��Ļ����
//				break;
//			}
//		}
		
    while (1)			//����ѭ��
    {
//			beep_on();
//			delay_ms(100);
//			showmenu();
//			lcd_showint32(0,0,da[0],4);
//			lcd_showint32(0,1,da[1],4);

        if (TIM1_Flag)
        {
//						lcd_showint32(0,0,adc_value[0],4);
//						lcd_showint32(0,1,adc_value[1],4);
//						lcd_showint32(0,2,adc_value[3],4);
//						lcd_showint32(0,3,adc_value[4],4);
//						lcd_showint16(0,5,imu660ra_gyro_z);
//						lcd_showfloat(0,6,error,1,6);

            P52 = 0;		//LED
//          dl1b_get_distance();
            imu660ra_get_gyro();		//������
						dl1b_get_distance();
//            if (dl1b_distance_mm < 300 && Flag_Obstacle == 0)
//            {
//                state_lead = 12;
//                Stop_Action();
//            }
//            else
//            {
                state_detect(adc_value);		//��ȡ���ֵ
//					      if (stop_jump() == 1)
//								{
//										state_lead = 6;
//										Stop_Action();
//								}
//								else
//								{
										switch (state[state_lead])
										{
												case Track:
														Track_Action(adc_value);
														break;
//												case Left_Right_Angle:
//														Left_Right_Angle_Action(adc_value);
//												case Right_Right_Angle:
//														Right_Right_Angle_Action(adc_value);
												case Out:
														Out_Action();
												case Big_Circ_Left:
												case Small_Circ_Left:
														Circ_Left_Action(adc_value);
														break;
												case Big_Circ_Right:
												case Small_Circ_Right:
//														P67 = 0;
														Circ_Right_Action(adc_value);
														break;
												case Obstacle:
//														printf(".....\r\n");
														Obstacle_Action();
														break;
												case Ramp:
														Track_Action(adc_value);
														break;
												case Stop:
														Stop_Action();
										}
//								}
            //}
            //i+=1;
            ////if(i%400==0)
            ////{
            ////motor_R_pid.SetValue=0;
            ////motor_L_pid.SetValue=0;
            ////}
            ////else
            //  if(i%200==0)
            //{
            //  motor_L_pid.SetValue+=15;
            //  motor_R_pid.SetValue+=15; 
            //}
            //else if(i>1800)
            //{
            //motor_R_pid.SetValue=0;
            //motor_L_pid.SetValue=0;
            //}
//						lcd_showint32(0,0,motor_L_pid.ActValue,4);
//						lcd_showint32(0,1,motor_R_pid.ActValue,4);
//						lcd_showint32(0,2,motor_L_pid.SetValueTmp,4);
//						lcd_showint32(0,3,motor_R_pid.SetValueTmp,4);

//						lcd_showint32(0,0,adc_value[0],4);
//						lcd_showint32(0,1,adc_value[1],4);
//						lcd_showint32(0,2,adc_value[3],4);
//						lcd_showint32(0,3,adc_value[4],4);

//						lcd_showint32(0,4,adc_value[2],4);
//						lcd_showint32(0,5,Flag_Circ,4);
//						lcd_showint32(0,6,Sum_Distance,4);
//						lcd_showint32(0,5,(int)dl1b_distance_mm,4);
//						lcd_showint32(0,4,(int)state_lead,4);
            uart_delay++;
            if (uart_delay > 4)
            {
                uart_delay = 0;
//                printf("%f,%f,%f,%f\r\n", motor_L_pid.ActValue, motor_R_pid.ActValue,
//																					motor_L_pid.SetValueTmp, motor_R_pid.SetValueTmp);
//								printf("%d,%d,%d,%d\r\n", adc_value[0], adc_value[1],
//																					adc_value[3], adc_value[4]);
            }
//					printf("%d\r\n",flag_turn);
            TIM1_Flag = 0;
            P52 = 1;
        }

    }
}
