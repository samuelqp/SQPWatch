//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-0101
//  ����޸�   : 
//  ��������   : OLED �ӿ���ʾ����(STM32F4ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              D0   ��PG12��SCL��
//              D1   ��PD5��SDA��
//              RES  PD4��SPIģ��ĳ�IICģ����Ҫ�Ӵ����ţ�IICģ���û�����ԣ�
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//  ��������   : 2018-0101
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
	LED_Init();					//��ʼ��LED
 	OLED_Init();				//��ʼ��OLED  
	LED0=0;
	while(1) 
	{
		OLED_ShowPicture(0,0,64,32,BMP1,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(8,0,0,16,1);//��
		OLED_ShowChinese(24,0,1,16,1);//��
		OLED_ShowChinese(40,0,2,16,1);//԰
		OLED_ShowString(4,16,"2019/02",16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16,1);  
		OLED_ShowString(0,16,"CODE:",16,1);
		OLED_ShowChar(48,0,t,16,1);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(40,16,t,3,16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
	  OLED_ShowChinese(0,4,0,24,1); //24*24 ��
		OLED_ShowChinese(24,0,0,32,1);//32*32 ��
		OLED_Refresh();
	  delay_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"A",12,1);//6*12 ��ABC��
	  OLED_ShowString(16,0,"B",16,1);//8*16 ��ABC��
		OLED_ShowString(36,0,"C",24,1);//8*16 ��ABC��
	  OLED_Refresh();
		delay_ms(500);
		OLED_ScrollDisplay(11,4,1);
	}
}
