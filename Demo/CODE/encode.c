#include "headfile.h"
int encoder_L_get(void)
{
	int temp;
	   if(DIR_Encoder_L == 1)
	   {
			temp = 0-ctimer_count_read(Encoder_L);
	   }	   // �����ֵ�ǰ�ٶ�
	   else
	   {
			temp = ctimer_count_read(Encoder_L);
	   }
	ctimer_count_clean(Encoder_L); // ����������

	return temp;
}


//�ɼ��ұ�����ֵ


int encoder_R_get(void)
{
int temp;
if(DIR_Encoder_R == 0)
{
    temp = 0-ctimer_count_read(Encoder_R) ; }// �����ֵ�ǰ�ٶ�
else
{
	temp = ctimer_count_read(Encoder_R);
}
//printf("%d\r\n",temp);
	ctimer_count_clean(Encoder_R); // ����������

	return temp;
}