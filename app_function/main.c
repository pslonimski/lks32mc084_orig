#include "global_variable.h"

/*******************************************************************************
 �������ƣ�    int main(void)
 ����������    ���������
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
int main(void)
{
    Hardware_init();// Ӳ����ʼ��
    sys_init();     // �����ʼ��
//	printf("INITIAL OFFSETS: %d , %d , %d \n\r",
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2);
    __enable_irq(); // ���ж�
    //SCB->SCR = BIT1;// ����ϵͳ���߲���
    //GPIO_ResetBits(LEDRGPIO, LEDR);
		//GPIO_ResetBits(LEDGGPIO, LEDG);
		GPIO_ResetBits(LEDBGPIO, LEDB);
	 // __WFI();        // �������������жϺ�����ʼ����
   //	printf("STARTED\n");
	//printf("OFFSETS: %d , %d , %d TH\n\r",
	//									struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
	//									struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
	//									struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2);
	  for(;;)
	{
		printf("SPEED: %d CURRENT: %d , %d , %d OFFS: %d %d %d T: %d\n\r",
										struFOC_CtrProc.stru_SMO.variable.speed,
										struFOC_CtrProc.stru_SMO.variable.CurrPhaseUVW.nPhaseW,
										struFOC_CtrProc.stru_SMO.variable.CurrPhaseUVW.nPhaseV,
										struFOC_CtrProc.stru_SMO.variable.CurrPhaseUVW.nPhaseU,
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2,
										struFOC_CtrProc.stru_SMO.variable.theatae);;//,ADC0_DAT3,ADC0_DAT4);
	}
	;
}
