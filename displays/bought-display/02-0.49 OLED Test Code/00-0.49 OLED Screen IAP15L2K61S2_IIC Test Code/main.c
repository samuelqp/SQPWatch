//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : OLED 4�ӿ���ʾ����(51ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              SCL  P10��SCL��
//              SDA  P11��SDA��
//              RES  P12 ע��SPI�ӿ���ʾ���ĳ�IIC�ӿ�ʱ��Ҫ��RES����
//                           IIC�ӿ���ʾ���û������
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//******************************************************************************/
#include "REG51.h"
#include "oled.h"
#include "bmp.h"

int main(void)
{	
	u8 t=' ';
	OLED_Init();//��ʼ��OLED  
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
	while(1) 
	{		
		OLED_DrawBMP(0,0,64,32,BMP1);
		delay_ms(500);
		OLED_Clear();
		OLED_Clear();
		OLED_ShowChinese(8,0,0,16);//��
		OLED_ShowChinese(24,0,1,16);//��
		OLED_ShowChinese(40,0,2,16);//԰
		OLED_ShowString(4,2,"2019/02",16);
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,2,"CODE:",16);
		OLED_ShowChar(48,0,t,16);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(40,2,t,3,16);
		delay_ms(500);
		OLED_Clear();
	}	  
	
}






