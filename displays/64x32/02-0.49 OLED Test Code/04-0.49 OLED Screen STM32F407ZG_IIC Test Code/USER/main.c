//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-0101
//  最近修改   : 
//  功能描述   : OLED 接口演示例程(STM32F4系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   接PG12（SCL）
//              D1   接PD5（SDA）
//              RES  PD4（SPI模块改成IIC模块需要接此引脚，IIC模块用户请忽略）
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//  生成日期   : 2018-0101
//All rights reserved
//******************************************************************************/


#include "sys.h"
#include "delay.h"
#include "led.h"
#include "oled.h"
#include "bmp.h"


int main(void)
{ 
	u8 t=' ';
	delay_init(168);
	LED_Init();					//初始化LED
 	OLED_Init();				//初始化OLED  
	LED0=0;
	while(1) 
	{
		OLED_ShowPicture(0,0,64,32,BMP1,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(8,0,0,16,1);//中
		OLED_ShowChinese(24,0,1,16,1);//景
		OLED_ShowChinese(40,0,2,16,1);//园
		OLED_ShowString(4,16,"2019/02",16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16,1);  
		OLED_ShowString(0,16,"CODE:",16,1);
		OLED_ShowChar(48,0,t,16,1);//显示ASCII字符	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(40,16,t,3,16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
	  OLED_ShowChinese(0,4,0,24,1); //24*24 中
		OLED_ShowChinese(24,0,0,32,1);//32*32 中
		OLED_Refresh();
	  delay_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"A",12,1);//6*12 “ABC”
	  OLED_ShowString(16,0,"B",16,1);//8*16 “ABC”
		OLED_ShowString(36,0,"C",24,1);//8*16 “ABC”
	  OLED_Refresh();
		delay_ms(500);
		OLED_ScrollDisplay(11,4,1);
	}
}
