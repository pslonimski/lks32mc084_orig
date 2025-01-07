#ifndef __GLOBAL_VARIABLE__
#define __GLOBAL_VARIABLE__

#include "mc_type.h"
extern  stru_FOC_CtrProcDef struFOC_CtrProc;          			/* FOC�����ڻ��ṹ�� */

void Hardware_init(void); 										/* Ӳ����ʼ������ */
void sys_init(void); 										/* ϵͳ��ʼ������ */
void Task_Scheduler(void); 									/* ��ѭ������ */
void DSP_Init(void);    /* DSPģ���ʼ��*/
void ADC_init(void);    /* ADC��ʼ�� */
void MCPWM_init(void);  /* PWM��ʼ�� */
void UTimer_init(void); /* ͨ�ü�������ʼ�� */
void GPIO_init(void);   /* GPIO��ʼ�� */
void PGA_init(void);    /* PGA ��ʼ�� */
void SoftDelay(u32);    /* ��ʱ�ȴ�Ӳ����ʼ���ȶ� */
void ADC_NormalModeCFG(void);
void FOC_Model(stru_FOC_CtrProcDef *pCtrProc);
void StopMotorImmdly(stru_FOC_CtrProcDef *this);
void SetTime_TimeOut_Counter(u16 hTimeout);
void Sys_State_Run(stru_FOC_CtrProcDef *this);
stru_VoltVoctorDQ RevPark_Circle_Limitation(stru_VoltVoctorDQ VoltVoctorDQ);
void MCPWM0_RegUpdate(stru_VoltPhaseUVW VoltPhaseUVW);
void MCL_Init(stru_FOC_CtrProcDef *pCtrProc);
void Curr_rc_fir(Stru_Curr_RC * this);
void currentOffsetRead(void);
void FOC_InitstruParama(stru_FOC_CtrProcDef *this);
void Sys_State_Machine(stru_FOC_CtrProcDef *this);
void Key_in(stru_FOC_CtrProcDef *this);
void currentOffsetRead(void);

stru_VoltPhaseUVW   SVPWM(stru_VoltAlphBeta,u16 hPWM_PERIOD);
stru_CurrAlphBeta   Clarke(stru_CurrPhaseUVW uvw);
stru_CurrVoctorDQ   Park(stru_CurrAlphBeta ab, stru_TrigComponents TrigComponents);
stru_VoltAlphBeta   Rev_Park(stru_VoltVoctorDQ dq, stru_TrigComponents TrigComponents);
stru_TrigComponents Trig_Functions(s16 hAngle);
#endif

#define LEDRGPIO GPIO0
#define LEDGGPIO GPIO0
#define LEDBGPIO GPIO1
#define LEDR GPIO_Pin_14
#define LEDG GPIO_Pin_15
#define LEDB GPIO_Pin_0

/* ********************** (C) COPYRIGHT LINKO SEMICONDUCTOR ******************** */
/* ------------------------------END OF FILE------------------------------------ */
