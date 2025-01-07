#ifndef __HARDWARE_CONFIG_H_
#define __HARDWARE_CONFIG_H_

#include "lks32mc08x_lib.h"

/* ==============================PWM Ƶ�ʼ���������=========================== */

#define MCU_MCLK							((u32)96000000uL) 										/* PWMģ��������Ƶ */
#define PWM_MCLK							((u32)MCU_MCLK) 										/* PWMģ��������Ƶ */
#define PWM_PRSC 							((u8)0) 												/* PWMģ������Ԥ��Ƶ�� */
#define PWM_FREQ 							((u16)48000) 											/* PWMն��Ƶ�� */

#define PWM_PERIOD         					((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ *(PWM_PRSC+1)))) 	/* PWM ���ڼ�����ֵ */

#define DEADTIME_NS        					((u16)800)												/* ����ʱ�� */
#define DEADTIME           					(u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS)/1000000000uL)
 
/* ============================== ����������� =========================== */

#define RS                              (double)(0.165)   // ��λ��  �����
#define LS                              (double)(0.000012 )   // ��λH   ����
#define PHASE_RSHUNT                    (double)(0.001 )   // ��λ��  �������������
#define ADC_SUPPLY_VOLTAGE              (double)(3.3 )   // ��λV   ADC����
#define AMPLIFICATION_GAIN              (200.0/(10.4+0.5))          /* �˷ŷŴ��� */   //17.543859     17.5439
#define U_RATED_VOLTAGE                 (12)               /* ��λ:V, ����������ѹ������Ϊ����������ѹ */



/* ---------------------------------PID��������------------------------------- */

//#define PLL_KP_GAIN 1000
//#define PLL_KI_GAIN 100

//#define PLL_KPDIV 15
//#define PLL_KIDIV 15


#define MAX_VQ_LIM             		(u16)10000    /* Q�����������ƣ�Q15��ʽ��ȡֵ��Χ0~32767 */
#define MAX_VD_LIM             		(u16)10000    /* D�����������ƣ�Q15��ʽ��ȡֵ��Χ0~32767 */  


#define PID_FLUX_KP_DEFAULT  		(s16)50
#define FLUX_KPDIV 					((u16)12)
#define PID_FLUX_KI_DEFAULT  		(s16)20
#define FLUX_KIDIV 					((u16)12)

#define PID_TORQUE_KP_DEFAULT  		(s16)50
#define TF_KPDIV 					((u16)12)
#define PID_TORQUE_KI_DEFAULT  		(s16)20
#define TF_KIDIV 					((u16)12)


#define PID_SPEED_KP_DEFAULT      	(s16)50
#define SP_KPDIV 					((u16)10)
#define PID_SPEED_KI_DEFAULT      	(s16)20
#define SP_KIDIV 					((u16)15)


/* ******************************ADCͨ���Ŷ���****************************************** */

#define ADC0_CURRETN_A_CHANNEL       		(ADC_CHANNEL_0)                            /* A���������ͨ�� */
#define ADC0_CURRETN_B_CHANNEL       		(ADC_CHANNEL_2)                             /* B���������ͨ�� */
#define ADC0_CURRETN_C_CHANNEL       		(ADC_CHANNEL_3)                           /* B���������ͨ�� */
#define ADC0_BUS_VOL_MSK                    (ADC_CHANNEL_11)                            /* ĸ�ߵ�ѹ����ͨ�� */
#define ADC0_TEMP_MSK                       (ADC_CHANNEL_8)                             /* �¶Ȳ���ͨ�� */

#define ADC_STATE_RESET()                 	{ADC0_CFG |= BIT2;}


#endif
 
 
