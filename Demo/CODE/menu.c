/*
 * menu.c
 *
 *  Created on: 2024年8月18日
 *      Author: shuyu
 */
#include "menu.h"
int place_index_1 = 0;
int value_index_1 = 0;
int place_index_2 = 0;
int value_index_2 = 0;
int P71_Last;
int P73_Last;
int P70_Last;
int P72_Last;

int place_index = 0 ;
int value_index = 0;
int last_place_index = 0;
int allow_value_show = 0;
int allow_image_show = 0;
int key_pit_flag = 1;

/////////////////////////Menu/////////////////////

int16 write_buff[50];
int16 read_buff[50];
int16 inKd1 = 0;
int16 inKd2 = 0;

void Read_FLASH(void){
	iap_read_bytes(0x0000, read_buff, 100);
	
	Kp1[0] = read_buff[0];
	Kp2[0] = read_buff[1];
	inKd1 = read_buff[2];
	inKd2 = read_buff[3];
	Kd1[0] = (float)inKd1/10;
	Kd2[0] = (float)inKd2/10;
	SPEED = read_buff[4];
	Out_Jump_Angle = read_buff[5];
	Out_Speed_L = read_buff[6];
	Out_Speed_R = read_buff[7];
	Circ_Jump_Left[0] = read_buff[8];
	Circ_Jump_Left[1] = read_buff[9];
	Circ_Jump_Left[2] = read_buff[10];
	Circ_Jump_Left[3] = read_buff[11];
	Circ_Left_Dis_Start = read_buff[12];
	Circ_Left_Angle = read_buff[13];
	Circ_Left_Dis_Final = read_buff[14];
	Circ_Jump_Right[0] = read_buff[15];
	Circ_Jump_Right[1] = read_buff[16];
	Circ_Jump_Right[2] = read_buff[17];
	Circ_Jump_Right[3] = read_buff[18];
	Circ_Right_Dis_Start = read_buff[19];
	Circ_Right_Angle = read_buff[20];
	Circ_Right_Dis_Final = read_buff[21];
	Circ_Left_Speed_L = read_buff[22];
	Circ_Left_Speed_R = read_buff[23];
	Circ_Left_Speed_Out = read_buff[24];
	Circ_Right_Speed_L = read_buff[25];
	Circ_Right_Speed_R = read_buff[26];
	Circ_Right_Speed_Out = read_buff[27];
	delay_time = read_buff[28];
}

void Write_FLASH(void){
	iap_erase_page(0);
	
	write_buff[0]= Kp1[0];
	write_buff[1]= Kp2[0];
	write_buff[2]= inKd1;
	write_buff[3]= inKd2;
	write_buff[4]= SPEED;
	write_buff[5]= Out_Jump_Angle;
	write_buff[6]= Out_Speed_L;
	write_buff[7]= Out_Speed_R;
	write_buff[8]= Circ_Jump_Left[0];
	write_buff[9]= Circ_Jump_Left[1];
	write_buff[10]= Circ_Jump_Left[2];
	write_buff[11]= Circ_Jump_Left[3];
	write_buff[12]= Circ_Left_Dis_Start;
	write_buff[13]= Circ_Left_Angle;
	write_buff[14]= Circ_Left_Dis_Final;
	write_buff[15]= Circ_Jump_Right[0];
	write_buff[16]= Circ_Jump_Right[1];
	write_buff[17]= Circ_Jump_Right[2];
	write_buff[18]= Circ_Jump_Right[3];
	write_buff[19]= Circ_Right_Dis_Start;
	write_buff[20]= Circ_Right_Angle;
	write_buff[21]= Circ_Right_Dis_Final;
	write_buff[22]= Circ_Left_Speed_L;
	write_buff[23]= Circ_Left_Speed_R;
	write_buff[24]= Circ_Left_Speed_Out;
	write_buff[25]= Circ_Right_Speed_L;
	write_buff[26]= Circ_Right_Speed_R;
	write_buff[27]= Circ_Right_Speed_Out;
	write_buff[28]= delay_time;
	
	iap_write_bytes(0x0000, write_buff, 100);
}

void cursor_selected(int max_index) {
		int index;
    if (place_index >= max_index) {
        place_index = 0;
    } else if (place_index <= -1) {
        place_index = max_index - 1;
    }
		for(index = 0 ; index < 20 ; index ++ ){
			if (index != place_index + 1) {
				lcd_showstr(0 , index , "  ");
      }
		}
		lcd_showstr(0 , place_index + 1 , "->");
    last_place_index = place_index;
}



void show_string_value(uint16 base_y, uint32 value, uint8 num_digits, const char* str) {
    lcd_showstr(16, base_y, str);
    lcd_showint32(70,base_y, value, num_digits); // 假设x坐标为0，你可以根据需要调整
}

void adjust_menu(void)
{
//    Read_FLASH();
//    pit_ms_init(CCU61_CH0, 115);
    int value_number = 6;
    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 20){
        value_index = 0;
        control_menu();
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 20){
        value_index = 0;
        adc_value_menu();
        }
    }
    else if (place_index == 2 ) {
        if(value_index >= 20){
        value_index = 0;
        Circ_Left_Jump_menu();
        }
    }
    else if (place_index == 3 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Jump_menu();
        }
		}
    else if (place_index == 4 ) {
        if(value_index >= 20){
        value_index = 0;
				Action_menu();
        }
		}
    else if (place_index == 5 ) {
        if(value_index >= 20){
        key_pit_flag = 0;
				lcd_clear(BLACK);
        value_index = 0;
        place_index = 0;
        allow_value_show = 1;
        allow_image_show = 1;
        Write_FLASH();
        break;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 20){
        key_pit_flag = 0;
				lcd_clear(BLACK);
        value_index = 0;
        place_index = 0;
        allow_value_show = 0;
        allow_image_show = 0;
        Write_FLASH();
				menu_flag = 0;
        break;
        }
    }

    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <   Menu   >   ");
    lcd_showstr(16, 1, "Control");
    lcd_showstr(16, 2, "Adc_value");
    lcd_showstr(16, 3, "Circ_Jump_L");
    lcd_showstr(16, 4, "Circ_Jump_R");
    lcd_showstr(16, 5, "Action");
    lcd_showstr(16, 6, "observer");
    lcd_showstr(16, value_number+1, "go");
    }
}


void control_menu(void)
{
    int value_number = 8;
		lcd_clear(BLACK);

    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 20)
        {
        value_index = 0;
				Kp1[0] += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Kp1[0] -= 5;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 20){
            value_index = 0;
				Kp2[0] += 5;
        }
        if(value_index <= -20){
            value_index = 0;
				Kp2[0] -= 5;
        }
    }
    else if (place_index == 2 ) {
        if(value_index >= 20){
            value_index = 0;
				inKd1 += 1;
				Kd1[0] = (float)inKd1/10;
        }
        if(value_index <= -20){
            value_index = 0;
				inKd1 -= 1;
				Kd1[0] = (float)inKd1/10;
        }
    }
    else if (place_index == 3 ) {
        if(value_index >= 20){
        value_index = 0;
				inKd2 += 1;
				Kd2[0] = (float)inKd2/10;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				inKd2 -= 1;
				Kd2[0] = (float)inKd2/10;
        }
    }
    else if (place_index == 4 ) {
        if(value_index >= 20){
        value_index = 0;
				SPEED += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				SPEED -= 5;
        }
    }
    else if (place_index == 5 ) {
        if(value_index >= 20){
        value_index = 0;
				Out_Jump_Angle += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Out_Jump_Angle -= 5;
        }
    }
    else if (place_index == 6 ) {
        if(value_index >= 20){
        value_index = 0;
				Out_Speed_L += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Out_Speed_L -= 5;
        }
    }
    else if (place_index == 7 ) {
        if(value_index >= 20){
        value_index = 0;
				Out_Speed_R += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Out_Speed_R -= 5;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 20)
        {
						lcd_clear(BLACK);
            value_index = 0;
            place_index = 0;
						Write_FLASH();
            break;
        }
    }
    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <  Control  >  ");
    show_string_value(1,Kp1[0],4,"Kp1");
    show_string_value(2,Kp2[0],4,"Kp2");
//		lcd_showstr(16,3,"Kd1");
//    lcd_showfloat(70,3,Kd1[0],1,2);
//		lcd_showstr(16,4,"Kd2");
//    lcd_showfloat(70,4,Kd2[0],1,2);
		show_string_value(3,inKd1,4,"inKd1");
		show_string_value(4,inKd2,4,"inKd2");
    show_string_value(5,SPEED,4,"SPEED");
    show_string_value(6,Out_Jump_Angle,4,"Out_A");
    show_string_value(7,Out_Speed_L,4,"Out_L");
    show_string_value(8,Out_Speed_R,4,"Out_R");
    lcd_showstr(16,value_number+1, "EXIT");
    }
}

void adc_value_menu(void)
{
    int value_number = 4;
		lcd_clear(BLACK);
		place_index = 0;

    while(1)
    {
		state_detect(adc_value);
    if (place_index == value_number ) {
        if(value_index >= 20)
        {
						lcd_clear(BLACK);
            value_index = 0;
            place_index = 0;
						Write_FLASH();
            break;
        }
    }
    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <    Adc    >  ");
    show_string_value(1,adc_value[0],4,"adc_1");
    show_string_value(2,adc_value[1],4,"adc_2");
		show_string_value(3,adc_value[3],4,"adc_3");
		show_string_value(4,adc_value[4],4,"adc_4");
    lcd_showstr(16,value_number+1, "EXIT");
    }
}

void Circ_Left_Jump_menu(void)
{
    int value_number = 8;
		lcd_clear(BLACK);
		place_index = 0;

    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 20)
        {
        value_index = 0;
				Circ_Jump_Left[0] += 50;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Jump_Left[0] -= 50;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Left[1] += 50;
        }
        if(value_index <= -20){
        value_index = 0;
				Circ_Jump_Left[1] -= 50;
        }
    }
    else if (place_index == 2 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Left[2] += 50;
        }
        if(value_index <= -20){
        value_index = 0;
				Circ_Jump_Left[2] -= 50;
        }
    }
    else if (place_index == 3 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Left[3] += 50;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Jump_Left[3] -= 50;
        }
    }
    else if (place_index == 4 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Left_Dis_Start += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Left_Dis_Start -= 5;
        }
    }
    else if (place_index == 5 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Left_Angle += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Left_Angle -= 5;
        }
    }
    else if (place_index == 6 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Left_Dis_Final += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Left_Dis_Final -= 5;
        }
    }
    else if (place_index == 7 ) {
        if(value_index >= 20){
        value_index = 0;
				delay_time += 1000;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				delay_time -= 1000;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 20)
        {
						lcd_clear(BLACK);
            value_index = 0;
            place_index = 0;
						Write_FLASH();
            break;
        }
    }
    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <Circ_Jump_L>  ");
    show_string_value(1,Circ_Jump_Left[0],4,"L_J_1");
    show_string_value(2,Circ_Jump_Left[1],4,"L_J_2");
		show_string_value(3,Circ_Jump_Left[2],4,"L_J_3");
		show_string_value(4,Circ_Jump_Left[3],4,"L_J_4");
    show_string_value(5,Circ_Left_Dis_Start,4,"L_Sta");
    show_string_value(6,Circ_Left_Angle,4,"L_Ang");
    show_string_value(7,Circ_Left_Dis_Final,4,"L_Fin");
    show_string_value(8,delay_time,5,"de_ti");
    lcd_showstr(16,value_number+1, "EXIT");
    }
}

void Circ_Right_Jump_menu(void)
{
    int value_number = 7;
		lcd_clear(BLACK);
		place_index = 0;

    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 20)
        {
        value_index = 0;
				Circ_Jump_Right[0] += 50;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Jump_Right[0] -= 50;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Right[1] += 50;
        }
        if(value_index <= -20){
        value_index = 0;
				Circ_Jump_Right[1] -= 50;
        }
    }
    else if (place_index == 2 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Right[2] += 50;
        }
        if(value_index <= -20){
        value_index = 0;
				Circ_Jump_Right[2] -= 50;
        }
    }
    else if (place_index == 3 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Jump_Right[3] += 50;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Jump_Right[3] -= 50;
        }
    }
    else if (place_index == 4 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Dis_Start += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Dis_Start -= 5;
        }
    }
    else if (place_index == 5 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Angle += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Angle -= 5;
        }
    }
    else if (place_index == 6 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Dis_Final += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Dis_Final -= 5;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 20)
        {
						lcd_clear(BLACK);
            value_index = 0;
            place_index = 0;
						Write_FLASH();
            break;
        }
    }
    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <Circ_Jump_R>  ");
    show_string_value(1,Circ_Jump_Right[0],4,"R_J_1");
    show_string_value(2,Circ_Jump_Right[1],4,"R_J_2");
		show_string_value(3,Circ_Jump_Right[2],4,"R_J_3");
		show_string_value(4,Circ_Jump_Right[3],4,"R_J_4");
    show_string_value(5,Circ_Right_Dis_Start,4,"R_Sta");
    show_string_value(6,Circ_Right_Angle,4,"R_Ang");
    show_string_value(7,Circ_Right_Dis_Final,4,"R_Fin");
    lcd_showstr(16,value_number+1, "EXIT");
    }
}

void Action_menu(void)
{
    int value_number = 6;
		lcd_clear(BLACK);
		place_index = 0;

    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 20)
        {
        value_index = 0;
				Circ_Left_Speed_L += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Left_Speed_L -= 5;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 20){
            value_index = 0;
				Circ_Left_Speed_R += 5;
        }
        if(value_index <= -20){
            value_index = 0;
				Circ_Left_Speed_R -= 5;
        }
    }
    else if (place_index == 2 ) {
        if(value_index >= 20){
            value_index = 0;
				Circ_Left_Speed_Out += 5;
        }
        if(value_index <= -20){
            value_index = 0;
				Circ_Left_Speed_Out -= 5;
        }
    }
    else if (place_index == 3 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Speed_L += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Speed_L += 5;
        }
    }
    else if (place_index == 4 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Speed_R += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Speed_R -= 5;
        }
    }
    else if (place_index == 5 ) {
        if(value_index >= 20){
        value_index = 0;
				Circ_Right_Speed_Out += 5;
        }
        if(value_index <= -20)
        {
        value_index = 0;
				Circ_Right_Speed_Out -= 5;
        }
    }
    
    else if (place_index == value_number ) {
        if(value_index >= 20)
        {
						lcd_clear(BLACK);
            value_index = 0;
            place_index = 0;
						Write_FLASH();
            break;
        }
    }
    cursor_selected(value_number+1);
    lcd_showstr(0, 0, "  <  Action  >  ");
    show_string_value(1,Circ_Left_Speed_L,4,"L_Sp_L");
    show_string_value(2,Circ_Left_Speed_R,4,"L_Sp_R");
		show_string_value(3,Circ_Left_Speed_Out,4,"L_Out");
		show_string_value(4,Circ_Right_Speed_L,4,"R_Sp_L");
    show_string_value(5,Circ_Right_Speed_R,4,"R_Sp_R");
    show_string_value(6,Circ_Right_Speed_Out,4,"R_Out");
    lcd_showstr(16,value_number+1, "EXIT");
    }
}

void image_menu(void)
{
    int value_number = 2;
//    ips200_clear();
    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 1)
        {
        value_index = 0;
        }
        if(value_index <= -1)
        {
        value_index = 0;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 1)
        {
        value_index = 0;
        }
        if(value_index <= -1)
        {
        value_index = 0;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 3)
        {
//            ips200_clear();
            value_index = 0;
            place_index = 0;
            break;
        }
    }

    cursor_selected(value_number+1);
//    ips200_show_string(0, 0*Font_size_H, " -=  Image  =- ");
//    show_string_value(1,0,3,"XXXXXXXX");
//    show_string_value(2,0,3,"XXXXXXXX");
//    ips200_show_string(20,(value_number+1)*Font_size_H, "EXIT");

    }


}



void function_menu(void)
{
    int value_number = 2;
//    ips200_clear();
    while(1)
    {
    if (place_index == 0 ) {
        if(value_index >= 1)
        {
        value_index = 0;
//        delay_time+=1;
        }
        if(value_index <= -1)
        {
        value_index = 0;
//        delay_time-=1;
        }
    }
    else if (place_index == 1 ) {
        if(value_index >= 1)
        {
        value_index = 0;
//        run_time+=1;
        }
        if(value_index <= -1)
        {
        value_index = 0;
//        run_time-=1;
        }
    }
    else if (place_index == value_number ) {
        if(value_index >= 3)
        {
//            ips200_clear();
            value_index = 0;
            place_index = 0;
            break;
        }
    }

    cursor_selected(value_number+1);
//    ips200_show_string(0, 0*Font_size_H, " -=  Function  =- ");
//    show_string_value(1,delay_time,3,"delay_time");
//    show_string_value(2,run_time,3,"run_time");
//    ips200_show_string(20,(value_number+1)*Font_size_H, "EXIT");

    }


}

