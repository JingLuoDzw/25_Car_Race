///*********************************************************************************************************************
// * COPYRIGHT NOTICE
// * Copyright (c) 2018,逐飞科技
// * All rights reserved.
// * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
// *
// * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
// * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
// *
// * @file       		IPS200_SPI
// * @company	   		成都逐飞科技有限公司
// * @author     		逐飞科技(QQ3184284598)
// * @version    		查看doc内version文件 版本说明
// * @Software 		MDK FOR C251 V5.60
// * @Target core		STC32F12K
// * @Taobao   		https://seekfree.taobao.com/
// * @date       		2019-11-15
// * @note		
//					接线定义：
//					------------------------------------ 
//					2.0寸IPS模块管脚       单片机管脚
//					SCL                 	查看SEEKFREE_IPS200_SPI.h文件内的IPS200_SCL		宏定义     硬件SPI引脚不可随意切换
//					SDA                 	查看SEEKFREE_IPS200_SPI.h文件内的IPS200_SDA		宏定义     硬件SPI引脚不可随意切换
//					RES                 	查看SEEKFREE_IPS200_SPI.h文件内的IPS200_RST_PIN 宏定义    
//					DC                  	查看SEEKFREE_IPS200_SPI.h文件内的IPS200_DC_PIN	宏定义  
//					CS                  	查看SEEKFREE_IPS200_SPI.h文件内的IPS200_CS		宏定义     硬件SPI引脚不可随意切换
//					BL  					查看SEEKFREE_IPS200_SPI.h文件内的IPS200_BL_PIN	宏定义
//					
//					电源引脚
//					VCC 3.3V电源
//					GND 电源地
//					最大分辨率320*240
//					------------------------------------ 
// ********************************************************************************************************************/


//#include "SEEKFREE_IPS200_SPI.h"
//#include "SEEKFREE_FONT.h"
//#include "SEEKFREE_FUNCTION.h"
//#include "zf_function.h"

//#pragma warning disable = 115
//#pragma warning disable = 186

//#include "zf_spi.h"
//#include "zf_delay.h"

//static uint16 ips200_pencolor = IPS200_DEFAULT_PENCOLOR;
//static uint16 ips200_bgcolor  = IPS200_DEFAULT_BGCOLOR;

//static ips200_type_enum         ips200_display_type = IPS200_TYPE_SPI;
//static ips200_dir_enum          ips200_display_dir  = IPS200_DEFAULT_DISPLAY_DIR;
//static ips200_font_size_enum    ips200_display_font = IPS200_DEFAULT_DISPLAY_FONT;

//static uint16 ips200_x_max = 240;
//static uint16 ips200_y_max = 320;

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 SPI 写 8bit 数据
//// 参数说明     data            数据
//// 返回参数     void
//// 使用示例     ips200_write_8bit_data_spi(command);
//// 备注信息     内部调用
////-------------------------------------------------------------------------------------------------------------------
//void ips200_write_8bit_data_spi(uint8 dat)    
//{
//	spi_mosi(dat);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 SPI 写 16bit 数据
//// 参数说明     data            数据
//// 返回参数     void
//// 使用示例     ips200_write_16bit_data_spi(dat);
//// 备注信息     内部调用
////-------------------------------------------------------------------------------------------------------------------
//void ips200_write_16bit_data_spi(uint16 dat)   
//{
//    uint8 dat1[2];
//    dat1[0] = dat >> 8;
//    dat1[1] = (uint8)dat;
//	
//	spi_mosi(dat1[0]);	//写入数据  高位在前  低位在后
//	spi_mosi(dat1[1]);
//}


////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 写命令
//// 参数说明     command         命令
//// 返回参数     void
//// 使用示例     ips200_write_command(0x2a);
//// 备注信息     内部调用 用户无需关心
////-------------------------------------------------------------------------------------------------------------------
//static void ips200_write_command (const uint8 command)
//{

//	IPS200_CS(1);
//	IPS200_CS(0);
//	IPS200_DC(0);
//	ips200_write_8bit_data_spi(command);
//	IPS200_DC(1);
//	IPS200_CS(1);
//	IPS200_CS(0);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 向液晶屏写 8bit 数据
//// 参数说明     dat             数据
//// 返回参数     void
//// 使用示例     ips200_write_8bit_data(0x0C);
//// 备注信息     内部调用 用户无需关心
////-------------------------------------------------------------------------------------------------------------------
//static void ips200_write_8bit_data (const uint8 dat)
//{
//	IPS200_CS(0);
//    IPS200_DC(1);
//	ips200_write_8bit_data_spi(dat);
//	IPS200_CS(1);
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 向液晶屏写 16bit 数据
//// 参数说明     dat             数据
//// 返回参数     void
//// 使用示例     ips200_write_16bit_data(x1);
//// 备注信息     内部调用 用户无需关心
////-------------------------------------------------------------------------------------------------------------------
//static void ips200_write_16bit_data (const uint16 dat)
//{
//	IPS200_CS(0);
//    IPS200_DC(1);
//	ips200_write_16bit_data_spi(dat);
//	IPS200_CS(1);
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     设置显示区域
//// 参数说明     x1              起始x轴坐标
//// 参数说明     y1              起始y轴坐标
//// 参数说明     x2              结束x轴坐标
//// 参数说明     y2              结束y轴坐标
//// 返回参数     void
//// 使用示例     ips200_set_region(0, 0, ips200_x_max - 1, ips200_y_max - 1);
//// 备注信息     内部调用 用户无需关心
////-------------------------------------------------------------------------------------------------------------------
//static void ips200_set_region (uint16 x1, uint16 y1, uint16 x2, uint16 y2)
//{


//    ips200_write_command(0x2a);
//    ips200_write_16bit_data(x1);
//    ips200_write_16bit_data(x2);
//    
//    ips200_write_command(0x2b);
//    ips200_write_16bit_data(y1);
//    ips200_write_16bit_data(y2);
//    
//    ips200_write_command(0x2c);
//}


////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 清屏函数
//// 参数说明     void
//// 返回参数     void
//// 使用示例     ips200_clear();
//// 备注信息     将屏幕清空成背景颜色
////-------------------------------------------------------------------------------------------------------------------
//void ips200_clear (void)
//{
//    uint16 i, j;
//	IPS200_CS(0);

//    ips200_set_region(0, 0, ips200_x_max - 1, ips200_y_max - 1);
//    for(i = 0; i < ips200_x_max; i ++)
//    {
//        for (j = 0; j < ips200_y_max; j ++)
//        {
//            ips200_write_16bit_data(ips200_bgcolor);                 
//        }
//    }

//	IPS200_CS(1);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 屏幕填充函数
//// 参数说明     color           颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 返回参数     void
//// 使用示例     ips200_full(RGB565_BLACK);
//// 备注信息     将屏幕填充成指定颜色
////-------------------------------------------------------------------------------------------------------------------
//void ips200_full (const uint16 color)
//{
//    uint16 i, j;

//	IPS200_CS(0);

//    ips200_set_region(0, 0, ips200_x_max - 1, ips200_y_max - 1);
//    for(i = 0; i < ips200_x_max; i ++)
//    {
//        for (j = 0; j < ips200_y_max; j ++)
//        {
//            ips200_write_16bit_data(color);                 
//        }
//    }

//	IPS200_CS(1);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     设置显示方向
//// 参数说明     dir             显示方向  参照 zf_device_ips200.h 内 ips200_dir_enum 枚举体定义
//// 返回参数     void
//// 使用示例     ips200_set_dir(IPS200_PORTAIT);
//// 备注信息     这个函数只有在初始化屏幕之前调用才生效
////-------------------------------------------------------------------------------------------------------------------
//void ips200_set_dir (ips200_dir_enum dir)
//{
//    ips200_display_dir = dir;
//    if(dir < 2)
//    {
//        ips200_x_max = 240;
//        ips200_y_max = 320;
//    }
//    else
//    {
//        ips200_x_max = 320;
//        ips200_y_max = 240;
//    }
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     设置显示字体
//// 参数说明     dir             显示方向  参照 zf_device_ips200.h 内 ips200_font_size_enum 枚举体定义
//// 返回参数     void
//// 使用示例     ips200_set_font(IPS200_8x16_FONT);
//// 备注信息     字体可以随时自由设置 设置后生效 后续显示就是新的字体大小
////-------------------------------------------------------------------------------------------------------------------
//void ips200_set_font (ips200_font_size_enum font)
//{
//    ips200_display_font = font;
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     设置显示颜色
//// 参数说明     pen             颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 参数说明     bgcolor         颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 返回参数     void
//// 使用示例     ips200_set_color(RGB565_RED, RGB565_GRAY);
//// 备注信息     字体颜色和背景颜色也可以随时自由设置 设置后生效
////-------------------------------------------------------------------------------------------------------------------
//void ips200_set_color (const uint16 pen, const uint16 bgcolor)
//{
//    ips200_pencolor = pen;
//    ips200_bgcolor = bgcolor;
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 画点
//// 参数说明     x               坐标x方向的起点 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 [0, ips200_y_max-1]
//// 参数说明     color           颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 返回参数     void
//// 使用示例     ips200_draw_point(0, 0, RGB565_RED);            //坐标0,0画一个红色的点
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_draw_point (uint16 x, uint16 y, const uint16 color)
//{

//	IPS200_CS(0);

//    ips200_set_region(x, y, x, y);
//    ips200_write_16bit_data(color);

//	IPS200_CS(1);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 画线
//// 参数说明     x_start         坐标x方向的起点 [0, ips200_x_max-1]
//// 参数说明     y_start         坐标y方向的起点 [0, ips200_y_max-1]
//// 参数说明     x_end           坐标x方向的终点 [0, ips200_x_max-1]
//// 参数说明     y_end           坐标y方向的终点 [0, ips200_y_max-1]
//// 参数说明     color           颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 返回参数     void
//// 使用示例     ips200_draw_line(0, 0, 10, 10, RGB565_RED);     // 坐标 0,0 到 10,10 画一条红色的线
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_draw_line (uint16 x_start, uint16 y_start, uint16 x_end, uint16 y_end, const uint16 color)
//{
//    int16 dx,dy,sx,sy,err,e2;
//	
////    // 参数检查
////    if (x_start >= ips200_x_max || y_start >= ips200_y_max || x_end >= ips200_x_max || y_end >= ips200_y_max) return;
//        
//	// 计算绝对差值和步进方向
//	dx = (x_end > x_start) ? (x_end - x_start) : (x_start - x_end);
//	dy = (y_end > y_start) ? (y_end - y_start) : (y_start - y_end);
//	sx = (x_start < x_end) ? 1 : -1;
//	sy = (y_start < y_end) ? 1 : -1;
//	err = dx - dy;

//    // 主绘制循环
//    while (1) 
//	{
//		
//        // 绘制当前点（确保在屏幕范围内）
////        if (x_start < ips200_x_max && y_start < ips200_y_max) 
//		{
//            ips200_draw_point(x_start, y_start, color);
//        }

//        // 到达终点时退出
//        if (x_start == x_end && y_start == y_end) break;

//        // 误差决策
//        e2 = 2 * err;
//		
//        if (e2 > -dy) 
//		{  // X轴步进条件
//            err -= dy;
//            x_start += sx;
//        }
//		
//        if (e2 < dx) 
//		{   // Y轴步进条件
//            err += dx;
//            y_start += sy;
//        }
//    }
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示字符
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     dat             需要显示的字符
//// 返回参数     void
//// 使用示例     ips200_show_char(0, 0, 'x');                     // 坐标0,0写一个字符x
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_char (uint16 x, uint16 y, const char dat)
//{
//    uint8 i, j;
//	uint8 temp_top;
//	uint8 temp_bottom;

//	IPS200_CS(0);

//    switch(ips200_display_font)
//    {

//        case IPS200_8X16_FONT:
//            for(i = 0; i < 8; i ++)
//            {
//                ips200_set_region(x + i, y, x + i, y + 15);
//                // 减 32 因为是取模是从空格开始取得 空格在 ascii 中序号是 32
//                temp_top = ascii_font_8x16[dat - 32][i];
//                temp_bottom = ascii_font_8x16[dat - 32][i + 8];
//                for(j = 0; j < 8; j ++)
//                {
//                    if(temp_top & 0x01)
//                    {
//                        ips200_write_16bit_data(ips200_pencolor);
//                    }
//                    else
//                    {
//                        ips200_write_16bit_data(ips200_bgcolor);
//                    }
//                    temp_top >>= 1;
//                }
//                for(j = 0; j < 8; j ++)
//                {
//                    if(temp_bottom & 0x01)
//                    {
//                        ips200_write_16bit_data(ips200_pencolor);
//                    }
//                    else
//                    {
//                        ips200_write_16bit_data(ips200_bgcolor);
//                    }
//                    temp_bottom >>= 1;
//                }
//            }
//            break;
//        case IPS200_16X16_FONT:
//            // 暂不支持
//            break;
//    }

//	IPS200_CS(1);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示字符串
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     dat             需要显示的字符串
//// 返回参数     void
//// 使用示例     ips200_show_string(0, 0, "seekfree");
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_string (uint16 x, uint16 y, const char dat[])
//{

//    uint16 j = 0;
//    while(dat[j] != '\0')
//    {
//        switch(ips200_display_font)
//        {

//            case IPS200_8X16_FONT:
//                ips200_show_char(x + 8 * j, y, dat[j]);
//                j ++;
//                break;
//            case IPS200_16X16_FONT:
//                // 暂不支持
//                break;
//        }
//    }
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示32位有符号 (去除整数部分无效的0)
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     dat             需要显示的变量 数据类型 int32
//// 参数说明     num             需要显示的位数 最高10位  不包含正负号
//// 返回参数     void
//// 使用示例     ips200_show_int(0, 0, x, 3);                    // x 可以为 int32 int16 int8 类型
//// 备注信息     负数会显示一个 ‘-’号   正数显示一个空格
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_int (uint16 x, uint16 y, const int32 dat, uint8 num)
//{


//    int32 dat_temp = dat;
//    int32 offset = 1;
//    char data_buffer[12];

//    memset(data_buffer, 0, 12);
//    memset(data_buffer, ' ', num+1);

//    if(num < 10)
//    {
//        for(; num > 0; num --)
//        {
//            offset *= 10;
//        }
//        dat_temp %= offset;
//    }
//    func_int_to_str(data_buffer, dat_temp);
//    ips200_show_string(x, y, (const char *)&data_buffer);
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示32位无符号 (去除整数部分无效的0)
//// 参数说明     x               坐标x方向的起点 参数范围 [0, IPS200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, IPS200_y_max-1]
//// 参数说明     dat             需要显示的变量 数据类型 uint32
//// 参数说明     num             需要显示的位数 最高10位  不包含正负号
//// 返回参数     void
//// 使用示例     ips200_show_uint(0, 0, x, 3);                   // x 可以为 uint32 uint16 uint8 类型
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_uint (uint16 x, uint16 y, const uint32 dat, uint8 num)
//{
//    uint32 dat_temp = dat;
//    int32 offset = 1;
//    char data_buffer[12];
//    memset(data_buffer, 0, 12);
//    memset(data_buffer, ' ', num);

//    if(num < 10)
//    {
//        for(; num > 0; num --)
//        {
//            offset *= 10;
//        }
//        dat_temp %= offset;
//    }
//    func_uint_to_str(data_buffer, dat_temp);
//    ips200_show_string(x, y, (const char *)&data_buffer);
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示浮点数(去除整数部分无效的0)
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     dat             需要显示的变量，数据类型float或double
//// 参数说明     num             整数位显示长度   最高8位
//// 参数说明     pointnum        小数位显示长度   最高6位
//// 返回参数     void
//// 使用示例     ips200_show_float(0, 0, x, 2, 3);               // 显示浮点数   整数显示2位   小数显示三位
//// 备注信息     特别注意当发现小数部分显示的值与你写入的值不一样的时候，
////              可能是由于浮点数精度丢失问题导致的，这并不是显示函数的问题，
////              有关问题的详情，请自行百度学习   浮点数精度丢失问题。
////              负数会显示一个 ‘-’号   正数显示一个空格
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_float (uint16 x, uint16 y, const double dat, uint8 num, uint8 pointnum)
//{

//    double dat_temp = dat;
//    double offset = 1.0;
//    char data_buffer[17];
//    memset(data_buffer, 0, 17);
//    memset(data_buffer, ' ', num+pointnum+2);

//    if(num < 10)
//    {
//        for(; num > 0; num --)
//        {
//            offset *= 10;
//        }
//        dat_temp = dat_temp - ((int32)dat_temp / (int32)offset) * offset;
//    }
//    func_double_to_str(data_buffer, dat_temp, pointnum);
//    ips200_show_string(x, y, data_buffer);
//}




////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     IPS200 显示波形
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     *wave           波形数组指针
//// 参数说明     width           波形实际宽度
//// 参数说明     value_max       波形实际最大值
//// 参数说明     dis_width       波形显示宽度 参数范围 [0, ips200_x_max]
//// 参数说明     dis_value_max   波形显示最大值 参数范围 [0, ips200_y_max]
//// 返回参数     void
//// 使用示例     ips200_show_wave(0, 0, data, 128, 64, 64, 32);
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_wave (uint16 x, uint16 y, const uint16 *wave, uint16 width, uint16 value_max, uint16 dis_width, uint16 dis_value_max)
//{

//    uint32 i = 0, j = 0;
//    uint32 width_index = 0, value_max_index = 0;


//	IPS200_CS(0);

//    ips200_set_region(x, y, x + dis_width - 1, y + dis_value_max - 1);          // 设置显示区域
//    for(i = 0; i < dis_value_max; i ++)
//    {
//        for(j = 0; j < dis_width; j ++)
//        {
//            ips200_write_16bit_data(ips200_bgcolor); 
//        }
//    }

//	IPS200_CS(1);


//    for(i = 0; i < dis_width; i ++)
//    {
//        width_index = i * width / dis_width;
//        value_max_index = *(wave + width_index) * (dis_value_max - 1) / value_max;
//        ips200_draw_point(i + x, (dis_value_max - 1) - value_max_index + y, ips200_pencolor);
//    }
//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     汉字显示
//// 参数说明     x               坐标x方向的起点 参数范围 [0, ips200_x_max-1]
//// 参数说明     y               坐标y方向的起点 参数范围 [0, ips200_y_max-1]
//// 参数说明     size            取模的时候设置的汉字字体大小 也就是一个汉字占用的点阵长宽为多少个点 取模的时候需要长宽是一样的
//// 参数说明     *chinese_buffer 需要显示的汉字数组
//// 参数说明     number          需要显示多少位
//// 参数说明     color           颜色格式 RGB565 或者可以使用 zf_common_font.h 内 rgb565_color_enum 枚举值或者自行写入
//// 返回参数     void
//// 使用示例     ips200_show_chinese(0, 0, 16, chinese_test[0], 4, RGB565_RED);//显示font文件里面的 示例
//// 备注信息     使用PCtoLCD2002软件取模           阴码、逐行式、顺向   16*16
////-------------------------------------------------------------------------------------------------------------------
//void ips200_show_chinese (uint16 x, uint16 y, uint8 size, const uint8 *chinese_buffer, uint8 number, const uint16 color)
//{


//    int32 i, j, k;
//    uint8 temp, temp1, temp2;
//    const uint8 *p_data;
//    
//    temp2 = size / 8;
//    

//	IPS200_CS(0);

//    ips200_set_region(x, y, number * size - 1 + x, y + size - 1);
//    
//    for(i = 0; i < size; i ++)
//    {
//        temp1 = number;
//        p_data = chinese_buffer + i * temp2;
//        while(temp1 --)
//        {
//            for(k = 0; k < temp2; k ++)
//            {
//                for(j = 8; j > 0; j --)
//                {
//                    temp = (*p_data >> (j - 1)) & 0x01;
//                    if(temp)
//                    {
//                        ips200_write_16bit_data(color);
//                    }
//                    else
//                    {
//                        ips200_write_16bit_data(ips200_bgcolor);
//                    }
//                }
//                p_data ++;
//            }
//            p_data = p_data - temp2 + temp2 * size;
//        }   
//    }

//	IPS200_CS(1);

//}

////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     2寸 IPS液晶初始化
//// 参数说明     type_select     两寸屏接口类型 IPS200_TYPE_SPI 为 SPI 接口串口两寸屏 IPS200_TYPE_PARALLEL8 为 8080 协议八位并口两寸屏
//// 返回参数     void
//// 使用示例     ips200_init(IPS200_TYPE_PARALLEL8);
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//void ips200_init_spi ()
//{
//	IPS200_BL(1);
//	IPS200_DC(0);
//	IPS200_RST(0);
//	

//	spi_init(IPS200_SPIN_PIN, IPS200_SCL_PIN, IPS200_SDA_PIN, IPS200_SDA_IN_PIN, 0, MASTER, SPI_SYSclk_DIV_2);


//  

//    ips200_set_dir(ips200_display_dir);
//    ips200_set_color(ips200_pencolor, ips200_bgcolor);

//    
//    IPS200_BL(1);
//    IPS200_RST(0);  
//    delay_ms(5);
//    IPS200_RST(1);      
//    delay_ms(120);
//    

//	IPS200_CS(0);

//    ips200_write_command(0x11);
//    delay_ms(120);

//    ips200_write_command(0x36);
//    if(ips200_display_dir == 0)
//    {
//        ips200_write_8bit_data(0x00);
//    }
//    else if(ips200_display_dir == 1)
//    {
//        ips200_write_8bit_data(0xC0);
//    }
//    else if(ips200_display_dir == 2)
//    {
//        ips200_write_8bit_data(0x70);
//    }
//    else
//    {
//        ips200_write_8bit_data(0xA0);
//    }

//    ips200_write_command(0x3A);            
//    ips200_write_8bit_data(0x05);
//    
//    ips200_write_command(0xB2);            
//    ips200_write_8bit_data(0x0C);
//    ips200_write_8bit_data(0x0C); 
//    ips200_write_8bit_data(0x00); 
//    ips200_write_8bit_data(0x33); 
//    ips200_write_8bit_data(0x33);           

//    ips200_write_command(0xB7);            
//    ips200_write_8bit_data(0x35);

//    ips200_write_command(0xBB);            
//    ips200_write_8bit_data(0x29);                                               // 32 Vcom=1.35V
//                                                            
//    ips200_write_command(0xC2);            
//    ips200_write_8bit_data(0x01);

//    ips200_write_command(0xC3);            
//    ips200_write_8bit_data(0x19);                                               // GVDD=4.8V 
//                                                            
//    ips200_write_command(0xC4);            
//    ips200_write_8bit_data(0x20);                                               // VDV, 0x20:0v

//    ips200_write_command(0xC5);            
//    ips200_write_8bit_data(0x1A);                                               // VCOM Offset Set

//    ips200_write_command(0xC6);            
//    ips200_write_8bit_data(0x01F);                                              // 0x0F:60Hz          

//    ips200_write_command(0xD0);            
//    ips200_write_8bit_data(0xA4);
//    ips200_write_8bit_data(0xA1);                                                                                                                                                                                           
//                
//    ips200_write_command(0xE0);     
//    ips200_write_8bit_data(0xD0);   
//    ips200_write_8bit_data(0x08);   
//    ips200_write_8bit_data(0x0E);   
//    ips200_write_8bit_data(0x09);   
//    ips200_write_8bit_data(0x09);   
//    ips200_write_8bit_data(0x05);   
//    ips200_write_8bit_data(0x31);   
//    ips200_write_8bit_data(0x33);   
//    ips200_write_8bit_data(0x48);   
//    ips200_write_8bit_data(0x17);   
//    ips200_write_8bit_data(0x14);   
//    ips200_write_8bit_data(0x15);   
//    ips200_write_8bit_data(0x31);   
//    ips200_write_8bit_data(0x34);   

//    ips200_write_command(0xE1);     
//    ips200_write_8bit_data(0xD0);   
//    ips200_write_8bit_data(0x08);   
//    ips200_write_8bit_data(0x0E);   
//    ips200_write_8bit_data(0x09);   
//    ips200_write_8bit_data(0x09); 
//    ips200_write_8bit_data(0x15);   
//    ips200_write_8bit_data(0x31);   
//    ips200_write_8bit_data(0x33);   
//    ips200_write_8bit_data(0x48);   
//    ips200_write_8bit_data(0x17);   
//    ips200_write_8bit_data(0x14);   
//    ips200_write_8bit_data(0x15);   
//    ips200_write_8bit_data(0x31);   
//    ips200_write_8bit_data(0x34);   

//    ips200_write_command(0x21);
//    
//    ips200_write_command(0x29);

//	IPS200_CS(1);


//    ips200_clear();                                                             // 初始化为白屏
//}
int abc;