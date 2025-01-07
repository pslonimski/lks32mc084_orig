/*******************************************************************************
 * ��Ȩ���� (C)2018, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_adc.h
 * �ļ���ʶ��
 * ����ժҪ�� ADC������������ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� William Zhang
 * ������ڣ� 2018��25��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2018��7��25��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�William Zhang
 * �޸����ݣ�����
 *
 * �޸ļ�¼��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/

#ifndef _CONNIE_ADC_H_
#define _CONNIE_ADC_H_


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "basic.h"
#include "lks32mc08x_lib.h"
typedef struct
{
    __IO uint32_t DAT0;   /* ADC���ݼĴ���0 */
    __IO uint32_t DAT1;   /* ADC���ݼĴ���1 */
    __IO uint32_t DAT2;   /* ADC���ݼĴ���2 */
    __IO uint32_t DAT3;   /* ADC���ݼĴ���3 */
    __IO uint32_t DAT4;   /* ADC���ݼĴ���4 */
    __IO uint32_t DAT5;   /* ADC���ݼĴ���5 */
    __IO uint32_t DAT6;   /* ADC���ݼĴ���6 */
    __IO uint32_t DAT7;   /* ADC���ݼĴ���7 */
    __IO uint32_t DAT8;   /* ADC���ݼĴ���8 */
    __IO uint32_t DAT9;   /* ADC���ݼĴ���9 */
    __IO uint32_t DAT10;  /* ADC���ݼĴ���10 */
    __IO uint32_t DAT11;  /* ADC���ݼĴ���11 */
    __IO uint32_t DAT12;  /* ADC���ݼĴ���12 */
    __IO uint32_t DAT13;  /* ADC���ݼĴ���13 */
    __IO uint32_t DAT14;  /* ADC���ݼĴ���14 */
    __IO uint32_t DAT15;  /* ADC���ݼĴ���15 */
    __IO uint32_t DAT16;  /* ADC���ݼĴ���16 */
    __IO uint32_t DAT17;  /* ADC���ݼĴ���17 */
    __IO uint32_t DAT18;  /* ADC���ݼĴ���18 */
    __IO uint32_t DAT19;  /* ADC���ݼĴ���19 */

    __IO uint32_t CHN0;   /* ADC�����ź���Դ�Ĵ���0 */
    __IO uint32_t CHN1;   /* ADC�����ź���Դ�Ĵ���1 */
    __IO uint32_t CHN2;   /* ADC�����ź���Դ�Ĵ���2 */
    __IO uint32_t CHN3;   /* ADC�����ź���Դ�Ĵ���3 */
    __IO uint32_t CHN4;   /* ADC�����ź���Դ�Ĵ���4 */
    __IO uint32_t CHN5;   /* ADC�����ź���Դ�Ĵ���5 */
    __IO uint32_t CHN6;   /* ADC�����ź���Դ�Ĵ���6 */
    __IO uint32_t CHN7;   /* ADC�����ź���Դ�Ĵ���7 */
    __IO uint32_t CHN8;   /* ADC�����ź���Դ�Ĵ���8 */
    __IO uint32_t CHN9;   /* ADC�����ź���Դ�Ĵ���9 */

    __IO uint32_t CHNT0;   /* ADC�ֶ�ͨ�����Ĵ���0 ����ÿ�β������� */
    __IO uint32_t CHNT1;   /* ADC�ֶ�ͨ�����Ĵ���1 ����ÿ�β������� */
    __IO uint32_t SD0;     /* ���� */
    __IO uint32_t SD1;     /* ���� */
    __IO uint32_t GAIN_0;  /* ADC����ѡ��Ĵ���0 */
    __IO uint32_t GAIN_1;  /* ADC����ѡ��Ĵ���1 */
		/* �������ֵ�·A��Ӧͨ����Χ�ǵ�0��2��4��ż�����ͨ�� */
    __IO uint32_t DC_A0;   /* ADCֱ��ƫ�üĴ���0 �������ֵ�·A��Ӧ2/3������ͨ��ƫ�� */
    __IO uint32_t DC_A1;   /* ADCֱ��ƫ�üĴ���1 �������ֵ�·A��Ӧ 1 ������ͨ��ƫ�� */
    __IO uint32_t AMC_A0;  /* ADC����У���Ĵ���0 �������ֵ�·A��Ӧ2/3������ͨ������У�� */
    __IO uint32_t AMC_A1;  /* ADC����У���Ĵ���0 �������ֵ�·A��Ӧ 1 ������ͨ������У�� */
		/* �������ֵ�·B��Ӧͨ����Χ�ǵ�1��3��5���������ͨ�� */
    __IO uint32_t DC_B0;   /* ADCֱ��ƫ�üĴ���0 �������ֵ�·B��Ӧ2/3������ͨ��ƫ�� */
    __IO uint32_t DC_B1;   /* ADCֱ��ƫ�üĴ���1 �������ֵ�·B��Ӧ1������ͨ��ƫ�� */
    __IO uint32_t AMC_B0;  /* ADC����У���Ĵ���0 �������ֵ�·B��Ӧ2/3������ͨ������У�� */
    __IO uint32_t AMC_B1;  /* ADC����У���Ĵ���0 �������ֵ�·B��Ӧ 1 ������ͨ������У�� */

    __IO uint32_t IE;        /* ADC�жϼĴ��� */  
    __IO uint32_t IF;        /* ADC�жϱ�־λ�Ĵ��� */ 
    __IO uint32_t CFG;       /* ADCģʽ���üĴ��� */
    __IO uint32_t TRG;       /* ADC�������ƼĴ��� */
    __IO uint32_t SWT;       /* ADC��������Ĵ��� */
    __IO uint32_t DAT0_TH;   /* ADCͨ��0��ֵ�Ĵ��� */
} ADC_TypeDef;

#ifndef  ADC0
#define  ADC0     ((ADC_TypeDef *) ADC0_BASE)
#endif

typedef struct
{
    u16 IE;                           /* ADC�ж�ʹ�� */
    u16 Align;                        /* �������ݶ��뷽ʽ */
    u16 Con_Sample;                   /* ��������ģʽ */
    u16 Trigger_Cnt;                  /* ����ģʽ�´�����һ�β�������Ĵ����¼��� */
    u16 FirSeg_Ch;                    /* ��һ�β�������ͨ���� */
    u16 SecSeg_Ch;                    /* �ڶ��β�������ͨ���� */
    u16 ThrSeg_Ch;                    /* �����β�������ͨ���� */
    u16 FouSeg_Ch;                    /* ���Ķβ�������ͨ���� */
    u16 Trigger_Mode;                 /* ADC ����ģʽ ���Ρ�˫�λ��Ķ� */
    u16 MCPWM_Trigger_En;             /* MCPWM��������ʹ�� */
    u16 UTIMER_Trigger_En;            /* UTIMER��������ʹ�� */
    u16 DAT0_TH_Type;                 /* ����DAT0_TH��Ϊ��1����ֵ��0����ֵ */
    u16 DAT0_TH;                      /* ͨ��0��ֵ���� */
    u16 Gain0;                        /* ADC_DAT0-ADC_DAT9�������ֵ�·���� */
    u16 Gain1;                        /* ADC_DAT10-ADC_DAT19�������ֵ�·���� */
} ADC_InitTypeDef;


#define ADC_1_TIMES_SAMPLE                ((u8)1)  /* ADC����ͨ����1�β��� */
#define ADC_2_TIMES_SAMPLE                ((u8)2)  /* ADC����ͨ����2�β��� */
#define ADC_3_TIMES_SAMPLE                ((u8)3)  /* ADC����ͨ����3�β��� */
#define ADC_4_TIMES_SAMPLE                ((u8)4)  /* ADC����ͨ����4�β��� */
#define ADC_5_TIMES_SAMPLE                ((u8)5)  /* ADC����ͨ����5�β��� */
#define ADC_6_TIMES_SAMPLE                ((u8)6)  /* ADC����ͨ����6�β��� */
#define ADC_7_TIMES_SAMPLE                ((u8)7)  /* ADC����ͨ����7�β��� */
#define ADC_8_TIMES_SAMPLE                ((u8)8)  /* ADC����ͨ����8�β��� */
#define ADC_9_TIMES_SAMPLE                ((u8)9)  /* ADC����ͨ����9�β��� */
#define ADC_10_TIMES_SAMPLE               ((u8)10) /* ADC����ͨ����10�β��� */
#define ADC_11_TIMES_SAMPLE               ((u8)11) /* ADC����ͨ����11�β��� */
#define ADC_12_TIMES_SAMPLE               ((u8)12) /* ADC����ͨ����12�β��� */
#define ADC_13_TIMES_SAMPLE               ((u8)13) /* ADC����ͨ����13�β��� */
#define ADC_14_TIMES_SAMPLE               ((u8)14) /* ADC����ͨ����14�β��� */
#define ADC_15_TIMES_SAMPLE               ((u8)15) /* ADC����ͨ����15�β��� */
#define ADC_16_TIMES_SAMPLE               ((u8)16) /* ADC����ͨ����16�β��� */
#define ADC_17_TIMES_SAMPLE               ((u8)17) /* ADC����ͨ����17�β��� */
#define ADC_18_TIMES_SAMPLE               ((u8)18) /* ADC����ͨ����18�β��� */
#define ADC_19_TIMES_SAMPLE               ((u8)19) /* ADC����ͨ����19�β��� */
#define ADC_20_TIMES_SAMPLE               ((u8)20) /* ADC����ͨ����20�β��� */

#define ADC_DAT0_OV_IRQ_EN                ((uint16_t)0x40) /* ADC0_DAT0����ֵ�ж� */
#define ADC_H_CONFLICT_IRQ_EN             ((uint16_t)0x20) /* Ӳ��������ͻ */
#define ADC_S_CONFLICT_IRQ_EN             ((uint16_t)0x10) /* ���������ͻ */
#define ADC_EOS3_IRQ_EN                   ((uint16_t)0x08) /* ���Ķ�ɨ������ж� */
#define ADC_EOS2_IRQ_EN                   ((uint16_t)0x04) /* ������ɨ������ж� */
#define ADC_EOS1_IRQ_EN                   ((uint16_t)0x02) /* �ڶ���ɨ������ж� */
#define ADC_EOS0_IRQ_EN                   ((uint16_t)0x01) /* ��һ��ɨ������ж� */

#define ADC_DAT0_OV_IRQ_IF                ((uint16_t)0x40) /* ADC_DAT0����ֵ�жϱ�־λ */
#define ADC_H_CONFLICT_IRQ_IF             ((uint16_t)0x20) /* Ӳ��������ͻ��־ */
#define ADC_S_CONFLICT_IRQ_IF             ((uint16_t)0x10) /* ���������ͻ��־ */
#define ADC_EOS3_IRQ_IF                   ((uint16_t)0x08) /* ���Ķ�ɨ������жϱ�־ */
#define ADC_EOS2_IRQ_IF                   ((uint16_t)0x04) /* ������ɨ������жϱ�־ */
#define ADC_EOS1_IRQ_IF                   ((uint16_t)0x02) /* �ڶ���ɨ������жϱ�־ */
#define ADC_EOS0_IRQ_IF                   ((uint16_t)0x01) /* ��һ��ɨ������жϱ�־ */
#define ADC_ALL_IRQ_IF                    ((uint16_t)0x7f)   /* ADCȫ���жϱ�־λ���������ڳ�ʼ�� */

#define ADC_LEFT_ALIGN                    ((uint16_t)0x0000) /* ADC������������ */
#define ADC_RIGHT_ALIGN                   ((uint16_t)0x0001) /* ADC��������Ҷ��� */

#define ADC_DAT0_HTH                      ((uint16_t)0x0001) /* ADC_DAT0_TH��Ϊ����ֵ */
#define ADC_DAT0_LTH                      ((uint16_t)0x0000) /* ADC_DAT0_TH��Ϊ����ֵ */

#define ADC_MCPWM_T0_TRG                  ((uint16_t)0x01)   /* ADC����MCPWM T0�¼����� */
#define ADC_MCPWM_T1_TRG                  ((uint16_t)0x02)   /* ADC����MCPWM T1�¼����� */
#define ADC_MCPWM_T2_TRG                  ((uint16_t)0x04)   /* ADC����MCPWM T2�¼����� */
#define ADC_MCPWM_T3_TRG                  ((uint16_t)0x08)   /* ADC����MCPWM T3�¼����� */
#define ADC_UTIMER_T0_TRG                 ((uint16_t)0x01)   /* ADC����UTIMER T0�¼����� */
#define ADC_UTIMER_T1_TRG                 ((uint16_t)0x02)   /* ADC����UTIMER T1�¼����� */
#define ADC_UTIMER_T2_TRG                 ((uint16_t)0x04)   /* ADC����UTIMER T2�¼����� */
#define ADC_UTIMER_T3_TRG                 ((uint16_t)0x08)   /* ADC����UTIMER T3�¼����� */

#define ADC_1SEG_TRG                      ((uint16_t)0x00)   /* ADC���õ���ģʽ */
#define ADC_2SEG_TRG                      ((uint16_t)0x01)   /* ADC����2��ģʽ */
#define ADC_4SEG_TRG                      ((uint16_t)0x03)   /* ADC����4��ģʽ */

#define ADC_CHANNEL_0                     ((uint16_t)0x00)   /* ADCͨ��0-OPA0_OUT */
#define ADC_CHANNEL_1                     ((uint16_t)0x01)   /* ADCͨ��1-OPA1_OUT */
#define ADC_CHANNEL_2                     ((uint16_t)0x02)   /* ADCͨ��2-OPA2_OUT */
#define ADC_CHANNEL_3                     ((uint16_t)0x03)   /* ADCͨ��3-OPA3_OUT */
#define ADC_CHANNEL_4                     ((uint16_t)0x04)   /* ADCͨ��4 */
#define ADC_CHANNEL_5                     ((uint16_t)0x05)   /* ADCͨ��5 */
#define ADC_CHANNEL_6                     ((uint16_t)0x06)   /* ADCͨ��6 */
#define ADC_CHANNEL_7                     ((uint16_t)0x07)   /* ADCͨ��7 */
#define ADC_CHANNEL_8                     ((uint16_t)0x08)   /* ADCͨ��8 */
#define ADC_CHANNEL_9                     ((uint16_t)0x09)   /* ADCͨ��9 */
#define ADC_CHANNEL_10                    ((uint16_t)0x0a)   /* ADCͨ��10 */
#define ADC_CHANNEL_11                    ((uint16_t)0x0b)   /* ADCͨ��11 */
#define ADC_CHANNEL_12                    ((uint16_t)0x0c)   /* ADCͨ��12 */
#define ADC_CHANNEL_13                    ((uint16_t)0x0d)   /* ADCͨ��13 */
#define ADC_CHANNEL_14                    ((uint16_t)0x0e)   /* ADCͨ��14 */
#define ADC_CHANNEL_15                    ((uint16_t)0x0f)   /* ADCͨ��15 */
#define ADC_CHANNEL_16                    ((uint16_t)0x10)   /* ADCͨ��16 */
#define ADC_CHANNEL_17                    ((uint16_t)0x11)   /* ADCͨ��17 */
#define ADC_CHANNEL_18                    ((uint16_t)0x12)   /* ADCͨ��18-Temp */
#define ADC_CHANNEL_19                    ((uint16_t)0x13)   /* ADCͨ��19-VSS */


#define ADC_HARDWARE_T0_TRG               ((uint16_t)0x01)   /* ADC����Ӳ��T0�¼����� */
#define ADC_HARDWARE_T1_TRG               ((uint16_t)0x02)   /* ADC����Ӳ��T1�¼����� */
#define ADC_HARDWARE_T2_TRG               ((uint16_t)0x04)   /* ADC����Ӳ��T2�¼����� */
#define ADC_HARDWARE_T3_TRG               ((uint16_t)0x08)   /* ADC����Ӳ��T3�¼����� */

/* ADC�����ź���Դ�Ĵ������ */
typedef enum {
	CHN0 = 0, CHN1, CHN2, CHN3, CHN4, CHN5, CHN6, CHN7, CHN8, CHN9,\
	CHN10, CHN11, CHN12, CHN13, CHN14, CHN15, CHN16, CHN17, CHN18, CHN19,
} CHNx;

/* ADC���ݼĴ������ */
typedef enum {DAT0 = 0, DAT1, DAT2, DAT3, DAT4, DAT5, DAT6, DAT7, DAT8, DAT9,\
DAT10, DAT11, DAT12, DAT13, DAT14, DAT15, DAT16, DAT17, DAT18, DAT19,
} DATx;

void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_ClearIRQFlag(ADC_TypeDef* ADCx, uint16_t INT_flag);
void ADC_ChannelConfig(ADC_TypeDef* ADCx,CHNx CHNum, uint16_t nChannel);
u16 ADC_GetIRQFlag(ADC_TypeDef* ADCx, uint16_t INT_flag);
s16 ADC_GetConversionValue(DATx DATNum);/* ȡ��Ӧ���ADC���ݼĴ�����ֵ */
void ADC_SoftTrgEN(ADC_TypeDef* ADCx, FuncState state);
#endif /*_CONNIE_ADC_H_ */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
