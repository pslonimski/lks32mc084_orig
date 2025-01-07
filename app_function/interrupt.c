#include "global_variable.h"
#include "hardware_config.h"
void ADC0_IRQHandler(void);
void PendSV_Handler(void);

/*******************************************************************************
 �������ƣ�    int ADC0_IRQHandler(void)
 ����������    ADC�жϺ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void ADC0_IRQHandler(void)
{
    ADC0_IF |= BIT1 | BIT0;
    struFOC_CtrProc.nBusVoltage = ADC0_DAT3; 
	
    if (struFOC_CtrProc.eSysState == RUN)
    {
		FOC_Model(&struFOC_CtrProc);
    }
    struFOC_CtrProc.nSys_TimerPWM++;        // 16��Ƶ����״̬������
    if(struFOC_CtrProc.nSys_TimerPWM >= 16)
    {
        struFOC_CtrProc.nSys_TimerPWM = 0;
        SCB->ICSR |= BIT28;
    }
}
/*******************************************************************************
 �������ƣ�    void PendSV_Handler(void)
 ����������    ADC�жϺ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void PendSV_Handler(void)
{
    Sys_State_Machine(&struFOC_CtrProc);    // ״̬��
    Key_in(&struFOC_CtrProc);    // ״̬��
}
