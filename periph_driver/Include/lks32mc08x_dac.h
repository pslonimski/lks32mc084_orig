/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� Chanhom_dac.h
 * �ļ���ʶ��
 * ����ժҪ�� DAC������������ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Zhu Jie
 * ������ڣ� 2015��11��5��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
#ifndef __LKS08X_DAC_H
#define __LKS08X_DAC_H

/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"
#include "lks32mc08x_lib.h"
typedef struct
{
    uint8_t DAC_GAIN;                 /* DAC�����λ��0��3V��1��1.2V��2��4.85V��  */	
	  uint8_t DACOUT_EN;                /* DAC���ʹ�ܣ�0����ʹ�ܣ�1��ʹ�ܡ� */
}DAC_InitTypeDef;

/* ------------------------------DAC������ض��� ------------------------------ */
#define DAC_RANGE_3V0                  0                   /* DAC 3.0V���� */
#define DAC_RANGE_1V2                  1                   /* DAC 1.2V���� */
#define DAC_RANGE_4V85                 2                   /* DAC 4.85V���� */

void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);/* DAC�ṹ���ʼ�� */
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct);      /* DAC��ʼ�� */
void DAC_OutputValue(uint32_t DACValue);             /* DAC�����ֵ����--������ */
void DAC_OutputVoltage(uint16_t DACVoltage);         /* DAC���ģ������ֵ����--ģ���� */

#endif

