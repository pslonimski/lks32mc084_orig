/*******************************************************************************
 * ��Ȩ���� (C)2018, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc05x_cmp.h
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
 * �޸ļ�¼2��
 * �޸����ڣ�20220426
 * �� �� �ţ�V2.0
 * �� �� �ˣ�YangZJ
 * �޸����ݣ����ӿ������á����ӱȽ����ж���غ���
 *
 *******************************************************************************/
#ifndef __LKS32MC08x_CMP_H
#define __LKS32MC08x_CMP_H
/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "lks32mc08x_sys.h"
#include "string.h"
 
// �Ƚ����ز�ѡ��
#define CMP_HYS_20mV            0
#define CMP_HYS_0mV             1
//�Ƚ���N��
#define CMP_SELN_IN             0         /* N������ */
#define CMP_SELN_REF            1         /* N���ڲ��ο�REF���� */
#define CMP_SELN_DAC            2         /* N���ڲ�DAC���� */
#define CMP_SELN_HALL_MID       3         /* N�˷����ƹ����е����� */

//�Ƚ���P��
#define CMP_SELP_IP0            0        /* P��IP0���� */
#define CMP_SELP_OPA_IP         1        /* OPA IP���� OPA0_IP/OPA1_IP */
#define CMP_SELP_OPA_OUT        2        /* OPA OUT OPA0_OUT, OPA1_OUT */
#define CMP_SELP_IP1            3        /* P��IP1���� */
#define CMP_SELP_IP2            4        /* P��IP2���� */
#define CMP_SELP_IP3            5        /* P��IP3���� */
#define CMP_SELP_IP4            6        /* P��IP4���� */

// Ϊ��֤������ԣ������޸ĵĺ궨��
#define SELN_CMP_IN             0        /* N������ */
#define SELN_REF                1        /* N���ڲ��ο�REF���� */
#define SELN_DAC                2        /* N���ڲ�DAC���� */
#define SELN_HALL_MID           3        /* N�˷����ƹ����е����� */
#define SELP_CMP_OPA0IP         1        /* P��OPA0_IP���� */
#define SELP_CMP_OPA0OUT        2        /* P��OPA0_OUT���� */
#define SELP_CMP_OPA1OUT        3        /* P��OPA1_OUT���� */

#define SELP_CMP_OPA3IP         1        /* P��OPA3_IP���� */
#define SELP_CMP_OPA2OUT        2        /* P��OPA2_OUT���� */
#define SELP_CMP_OPA3OUT        3        /* P��OPA3_OUT���� */

#define SELP_CMP_IP0            0        /* P��IP0���� */
#define SELP_CMP_IP1            4        /* P��IP1���� */
#define SELP_CMP_IP2            5        /* P��IP2���� */
#define SELP_CMP_IP3            6        /* P��IP3���� */
#define SELP_CMP_IP4            7        /* P��IP4���� */

typedef struct
{
    __IO uint32_t IE;       // �Ƚ����ж�ʹ�ܼĴ���
    __IO uint32_t IF;       // �Ƚ����жϱ�־�Ĵ���
    __IO uint32_t TCLK;     // �Ƚ�����Ƶʱ�ӿ��ƼĴ���
    __IO uint32_t CFG;      // �Ƚ������ƼĴ���
    __IO uint32_t BLCWIN;   // �Ƚ����������ƼĴ���
    __IO uint32_t DATA;     // �Ƚ��������ֵ�Ĵ���
} CMP_TypeDef;
#ifndef CMP
#define CMP             ((CMP_TypeDef *) CMP_BASE)
#endif
#define CMP0            0
#define CMP1            1

typedef struct
{
    FuncState   CMP_FT;             // �Ƚ������ٱȽ�ʹ��
    FuncState   CLK10_EN;           // �Ƚ��� 1/0 �˲�ʱ��ʹ��
    FuncState   CMP0_EN;            // �Ƚ��� 0 ʹ��
    FuncState   CMP0_IE;            // �Ƚ��� 0 �ж�ʹ��
    FuncState   CMP0_IRQ_TRIG;      // �Ƚ��� 0 ���ش���ʹ��
    FuncState   CMP0_IN_EN;         // �Ƚ��� 0 �ź�����ʹ��
    FuncState   CMP0_CHN3P_WIN_EN;  // MCPWM ģ�� CHN3_P ͨ��ʹ�ܱȽ��� 0 ����
    FuncState   CMP0_CHN2P_WIN_EN;  // MCPWM ģ�� CHN2_P ͨ��ʹ�ܱȽ��� 0 ����
    FuncState   CMP0_CHN1P_WIN_EN;  // MCPWM ģ�� CHN1_P ͨ��ʹ�ܱȽ��� 0 ����
    FuncState   CMP0_CHN0P_WIN_EN;  // MCPWM ģ�� CHN0_P ͨ��ʹ�ܱȽ��� 0 ����
    FuncState   CMP1_EN;            // �Ƚ��� 1 ʹ��
    FuncState   CMP1_IE;            // �Ƚ��� 1 �ж�ʹ��
    FuncState   CMP1_IRQ_TRIG;      // �Ƚ��� 1 ���ش���ʹ��
    FuncState   CMP1_IN_EN;         // �Ƚ��� 1 �ź�����ʹ��
    FuncState   CMP1_CHN3P_WIN_EN;  // MCPWM ģ�� CHN3_P ͨ��ʹ�ܱȽ��� 1 ����
    FuncState   CMP1_CHN2P_WIN_EN;  // MCPWM ģ�� CHN2_P ͨ��ʹ�ܱȽ��� 1 ����
    FuncState   CMP1_CHN1P_WIN_EN;  // MCPWM ģ�� CHN1_P ͨ��ʹ�ܱȽ��� 1 ����
    FuncState   CMP1_CHN0P_WIN_EN;  // MCPWM ģ�� CHN0_P ͨ��ʹ�ܱȽ��� 1 ����
    u16         CMP1_W_PWM_POL;     // �Ƚ��� 1 ���� PWM �źż���ѡ��
    u16         FIL_CLK10_DIV16;    // �Ƚ��� 1/0 �˲�ϵ��
    u16         FIL_CLK10_DIV2;     // �Ƚ��� 1/0 �˲�ϵ����λ 0-3
    u16         CMP_HYS;            // �Ƚ����ز�ѡ��
    
    // �Ƚ���0
    u16         CMP0_SELP;          // �Ƚ��� 0 �ź�����ѡ��
    u16         CMP0_SELN;          // �Ƚ��� 0 �źŸ���ѡ��
    u16         CMP0_W_PWM_POL;     // �Ƚ��� 0 ���� PWM �źż���ѡ��
    u16         CMP0_POL;           // �Ƚ��� 0 ����ѡ��
    
    // �Ƚ���1
    u16         CMP1_SELP;          // �Ƚ��� 1 �ź�����ѡ��
    u16         CMP1_SELN;          // �Ƚ��� 1 �źŸ���ѡ��
    u16         CMP1_POL;           // �Ƚ��� 1 ����ѡ��
}CMP_InitTypeDef;

void CMP_Init(CMP_InitTypeDef *);           // �Ƚ�����ʼ��
void CMP_StructInit(CMP_InitTypeDef *);     // �Ƚ������ýṹ���ʼ��
void CMP_ClearIRQFlag(u8 CMPx);             // ��CMP�ж�
u8   CMP_GetIRQFlag(u8 CMPx);               // ��CMP�ж�

#endif /*__LKS32MC05x_CMP_H */
/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/

