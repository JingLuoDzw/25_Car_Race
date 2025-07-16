/*
 * menu.h
 *
 *  Created on: 2024年8月18日
 *      Author: shuyu
 */

#ifndef CODE_MENU_H_
#define CODE_MENU_H_
#include "headfile.h"
extern int place_index_1;
extern int value_index_1;
extern int place_index_2;
extern int value_index_2;
extern int P71_Last;
extern int P73_Last;
extern int P70_Last;
extern int P72_Last;
extern int place_index;
extern int value_index;
extern int last_place_index;
extern int allow_value_show ;
extern int allow_image_show ;
extern int key_pit_flag;
extern int16 write_buff[50];
extern int16 read_buff[50];
#define Font_size_H 10
#define Font_size_W 8
void adjust_menu(void);
void control_menu(void);
void image_menu(void);
void function_menu(void);
void cursor_selected(int max_index);
void Read_FLASH(void);
void Write_FLASH(void);
void adc_value_menu(void);
void Circ_Left_Jump_menu(void);
void Circ_Right_Jump_menu(void);
void Action_menu(void);
#endif /* CODE_MENU_H_ */
