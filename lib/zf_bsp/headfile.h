#ifndef __HEADFILE_H_
#define __HEADFILE_H_


#include "isr.h"
#include <string.h>
#include <stdio.h>
#include "intrins.h"
#include <math.h>
//------STC32G SDK等
#include "STC32Gxx.h"
#include "board.h"
#include "common.h"

//------逐飞科技单片机外设驱动头文件
#include "zf_uart.h"
#include "zf_gpio.h"
#include "zf_iic.h"
#include "zf_adc.h"
#include "zf_spi.h"
#include "zf_tim.h"
#include "zf_pwm.h"
#include "zf_nvic.h"
#include "zf_exti.h"
#include "zf_delay.h"
#include "zf_eeprom.h"

//------逐飞科技产品驱动头文件
#include "SEEKFREE_FONT.h"
#include "SEEKFREE_18TFT.h"
#include "SEEKFREE_ICM20602.h"
#include "SEEKFREE_TSL1401.h"
#include "SEEKFREE_IPS114_SPI.h"
#include "SEEKFREE_MPU6050.h"
#include "SEEKFREE_OLED.h"
#include "SEEKFREE_ABSOLUTE_ENCODER.h"
#include "SEEKFREE_WIRELESS.h"
#include "SEEKFREE_PRINTF.h"
#include "SEEKFREE_AT24C02.h"
#include "SEEKFREE_BLUETOOTH_CH9141.h"
#include "SEEKFREE_WIRELESS_CH573.h"
#include "SEEKFREE_CONFIG.h"
#include "SEEKFREE_IMU660RA.h"
#include "SEEKFREE_IMU963RA.h"
#include "SEEKFREE_DL1A.h"
#include "SEEKFREE_DL1B.h"

//用户头文件
#include "adc.h"
#include "main.h"
#include "state.h"
#include "pid.h"
#include "encoder.h"
#include "imu660.h"
#include "speed.h"
#include "dir.h"
#include "action.h"
#include "sys.h"
#include "menu.h"
//#include "count.h"
//extern PID motor_L_pid={0};
//extern PID motor_R_pid={0};
//extern PID speed_ctrl_pid={0};
//extern PID dir_loop_pid={0};


#endif