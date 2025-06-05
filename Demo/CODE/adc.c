#include "headfile.h"

void adc_get(int *temp)
{
    int a1[4], a2[4], a3[4], a4[4], a5[4];

    a1[0] = (adc_once(ADC_P17, ADC_12BIT));
    a2[0] = (adc_once(ADC_P16, ADC_12BIT));
    a3[0] = (adc_once(ADC_P13, ADC_12BIT));
    a4[0] = (adc_once(ADC_P15, ADC_12BIT));
		a5[0] = (adc_once(ADC_P14, ADC_12BIT));

    a1[1] = (adc_once(ADC_P17, ADC_12BIT));
    a2[1] = (adc_once(ADC_P16, ADC_12BIT));
    a3[1] = (adc_once(ADC_P13, ADC_12BIT));
    a4[1] = (adc_once(ADC_P15, ADC_12BIT));
		a5[1] = (adc_once(ADC_P14, ADC_12BIT));

    a1[2] = (adc_once(ADC_P17, ADC_12BIT));
    a2[2] = (adc_once(ADC_P16, ADC_12BIT));
    a3[2] = (adc_once(ADC_P13, ADC_12BIT));
    a4[2] = (adc_once(ADC_P15, ADC_12BIT));
		a5[2] = (adc_once(ADC_P14, ADC_12BIT));
	
    a1[3] = (adc_once(ADC_P17, ADC_12BIT));
    a2[3] = (adc_once(ADC_P16, ADC_12BIT));
    a3[3] = (adc_once(ADC_P13, ADC_12BIT));
    a4[3] = (adc_once(ADC_P15, ADC_12BIT));
		a5[3] = (adc_once(ADC_P14, ADC_12BIT));

    temp[0] = MeanFilter(a1, 4);
    temp[1] = MeanFilter(a2, 4);
    temp[2] = MeanFilter(a3, 4);
    temp[3] = MeanFilter(a4, 4);
    temp[4] = MeanFilter(a5, 4);

    temp[0] = temp[0] < 1 ? 1 : temp[0];
    temp[1] = temp[1] < 1 ? 1 : temp[1];
    temp[2] = temp[2] < 1 ? 1 : temp[2];
    temp[3] = temp[3] < 1 ? 1 : temp[3];
    temp[4] = temp[4] < 1 ? 1 : temp[4];
		
//		temp[0]=temp[0]>1500?1500:temp[0];
//		temp[1]=temp[1]>1500?1500:temp[1];
//		temp[2]=temp[2]>1500?1500:temp[2];
//		temp[3]=temp[3]>1500?1500:temp[3];

//		temp[0]=MeanFilter((adc_once(ADC_P00, ADC_12BIT)),5);
//		temp[1]=(adc_once(ADC_P01, ADC_12BIT));
//		temp[2]=(adc_once(ADC_P05, ADC_12BIT));
//		temp[3]=(adc_once(ADC_P06, ADC_12BIT));
//    temp[4] = (adc_once(ADC_P10, ADC_12BIT));
//    temp[5] = (adc_once(ADC_P11, ADC_12BIT));
//    temp[6] = (adc_once(ADC_P13, ADC_12BIT));
//    temp[7] = (adc_once(ADC_P14, ADC_12BIT));
}
//int MeanFilter(int *arr, int n)		//中值滤波
//{
//    int temp;
//    int i, j;
//    int buf[100];   // 假设最大长度不超过100，可根据实际调整

//    // 拷贝原数组到buf，避免修改原数组
//    for (i = 0; i < n; i++)
//    {
//        buf[i] = arr[i];
//    }

//    // 简单冒泡排序
//    for (i = 0; i < n - 1; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            if (buf[j] > buf[j + 1])
//            {
//                temp = buf[j];
//                buf[j] = buf[j + 1];
//                buf[j + 1] = temp;
//            }
//        }
//    }

//    // 返回中值
//    if (n % 2 == 0)
//        return (buf[n / 2 - 1] + buf[n / 2]) / 2;
//    else
//        return buf[n / 2];
//}

int MeanFilter(int *arr, int n)		//均值滤波
{
    int i = 0;
    float Sum = 0;
    float result;

    for (i = 0; i < n; i++)
    {
        Sum += arr[i];
    }
    result = Sum / n;
    return (int)result;
}

int max_count(int a, int b)
{
    int temp_max;

//  temp_max=a>b?a:b;
//  temp=(temp_max-100)*10/1100;
//  temp=(temp>10)?10:temp;
//  return temp;
    temp_max = a > b ? a : b;
    return temp_max;
//    temp_min=a>b?b:a;
//    if(temp_max>200)
//    {return 1;}
//    else
//    {return 0;}

}
int min_count(int a, int b)
{
    int temp_min;

//  temp_max=a>b?a:b;
//  temp=(temp_max-100)*10/1100;
//  temp=(temp>10)?10:temp;
//  return temp;
    temp_min = a < b ? a : b;
    return temp_min;
//  temp_min=a>b?b:a;
//  if(temp_max>200)
//  {return 1;}
//  else
//  {return 0;}

}

float error_get(int *temp, int flag)
{
    float L, R, awm;
//  int A=1,B=0;

//  A=(int)abs(temp[5]-temp[6])/100;
//  printf("%d\r\n",sizeof(temp[5]));
//  printf("%d,%d\r\n",abs(temp[5]-temp[6]),A);
    if (flag == cross)
    {
        awm = (float)(temp[0] - temp[4]) / (float)(temp[0] + temp[4]);
    }
    else if (flag == right_angle)
    {
        L = sqrt((double)temp[0] * (double)temp[0] + (double)temp[1] * (double)temp[1]);
        R = sqrt((double)temp[3] * (double)temp[3] + (double)temp[4] * (double)temp[4]);
        awm = (L - R) / (L + R);
    }
    else
    {
        L = sqrt((double)temp[0] * (double)temp[0] + (double)temp[1] * (double)temp[1]);
        R = sqrt((double)temp[3] * (double)temp[3] + (double)temp[4] * (double)temp[4]);
        awm = (L - R) / (L + R);
    }
		
//		ADC_error = awm;
    return awm;

}
