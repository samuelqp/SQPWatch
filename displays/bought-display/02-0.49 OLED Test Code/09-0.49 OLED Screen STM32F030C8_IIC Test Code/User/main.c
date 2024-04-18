//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-03-29
//  ����޸�   : 
//  ��������   : OLED I2C�ӿ���ʾ����(STM32F0ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��3.3v��Դ
//              D0   ��PA0��SCL��
//              D1   ��PA1��SDA��
//              RES  PA2��SPIģ��ĳ�IICģ����Ҫ�Ӵ����ţ�IICģ���û�����ԣ�
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018/3/16
//All rights reserved
//******************************************************************************/
#include "stm32f0xx.h"
#include "delay.h"
#include "oled.h"
#include "bmp.h"


int main(void)
{
	u8 t=' ';
  delay_init();
  OLED_Init();
  LED_ON;
  while (1)
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



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
