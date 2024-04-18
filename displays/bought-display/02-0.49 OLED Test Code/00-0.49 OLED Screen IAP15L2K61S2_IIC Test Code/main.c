//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2014-0101
//  最近修改   : 
//  功能描述   : OLED 4接口演示例程(51系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              SCL  P10（SCL）
//              SDA  P11（SDA）
//              RES  P12 注：SPI接口显示屏改成IIC接口时需要接RES引脚
//                           IIC接口显示屏用户请忽略
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2014/3/16
//All rights reserved
//******************************************************************************/
#include "REG51.h"
#include "oled.h"
#include "bmp.h"

int main(void)
{	
	u8 t=' ';
	OLED_Init();//初始化OLED  
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
	while(1) 
	{		
		OLED_DrawBMP(0,0,64,32,BMP1);
		delay_ms(500);
		OLED_Clear();
		OLED_Clear();
		OLED_ShowChinese(8,0,0,16);//中
		OLED_ShowChinese(24,0,1,16);//景
		OLED_ShowChinese(40,0,2,16);//园
		OLED_ShowString(4,2,"2019/02",16);
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,2,"CODE:",16);
		OLED_ShowChar(48,0,t,16);//显示ASCII字符	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(40,2,t,3,16);
		delay_ms(500);
		OLED_Clear();
	}	  
	
}






