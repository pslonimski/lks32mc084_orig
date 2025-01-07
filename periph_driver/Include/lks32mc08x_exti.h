/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc05x_exti.h
 * �ļ���ʶ��
 * ����ժҪ�� EXTI�ⲿ�ж�����ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� 
 * ������ڣ� 
 *
 * �޸ļ�¼1��
 * �޸����ڣ�
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
 
#ifndef __lks32mc05x_EXTI_H
#define __lks32mc05x_EXTI_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "lks32mc08x_gpio.h"
#include "basic.h"

typedef struct  
{
   __IO uint32_t CR0;
   __IO uint32_t CR1;
   __IO uint32_t IF;   
   __IO uint32_t POL;
   __IO uint32_t EN;
}EXTI_TypeDef;

#ifndef EXTI
#define EXTI             ((EXTI_TypeDef *) EXTI_BASE)
#endif
typedef enum
{
   EXTI_Trigger_None    = 0x00, // ������
   EXTI_Trigger_Negedge = 0x01, // �½��ش���
   EXTI_Trigger_Posedge = 0x02, // �����ش���
   EXTI_Trigger_Edge    = 0x03  // �����ء��½��ؾ�����
} EXTIMode_TypeDef;

void EXTI_Trigger_Config(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinSource, uint16_t EXTI_Trigger);
void EXTI_ClearIRQFlag(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinSource);
u8 EXTI_GetIRQFlag(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinSource);

#endif /*__lks32mc05x_EXTI_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
