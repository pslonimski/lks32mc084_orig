#include "global_variable.h"
s32 HL_PI_AntiDump(s32 InputError , stru_PIparams *pParams);

/*******************************************************************************
 �������ƣ�    s16 HL_PI_AntiDump(s32 InputError , stru_PIparams *pParams)
 ����������    PI����
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
s32 HL_PI_AntiDump(s32 InputError , stru_PIparams *pParams)
{
    s64 ProportionalPortion, PIoutput, IntegralPortion, DumpPortion;
    
    s64 dwAux;

    ProportionalPortion = (((pParams->hKp_Gain) * InputError) >> (pParams->hKp_Divisor));

    IntegralPortion = (pParams->hKi_Gain) * InputError; /* ���㱾�εĻ����� */

    dwAux = (s64) IntegralPortion + pParams->wIntegral; /* ��������Ļ����� */

    if (dwAux > pParams->wUpper_Limit_Integral)
    {
        IntegralPortion = pParams->wUpper_Limit_Integral;
    }
    else if (dwAux < pParams->wLower_Limit_Integral)
    {
        IntegralPortion = pParams->wLower_Limit_Integral;
    }
    else
    {
        IntegralPortion = (s32)(dwAux);
    }

    PIoutput = (IntegralPortion >> pParams->hKi_Divisor) + ProportionalPortion; /* �������+���ֲ��� */

    if (PIoutput > pParams->hUpper_Limit_Output)
    {
        DumpPortion = PIoutput - (pParams->hUpper_Limit_Output);
        PIoutput = pParams->hUpper_Limit_Output;
		
        if (IntegralPortion > 0)
        {
            IntegralPortion = IntegralPortion - (DumpPortion << pParams->hKi_Divisor);
        }

    }
    else if (PIoutput < pParams->hLower_Limit_Output)
    {
        DumpPortion = PIoutput - (pParams->hLower_Limit_Output);
        PIoutput = pParams->hLower_Limit_Output;
		
        if (IntegralPortion < 0)
        {
            IntegralPortion = IntegralPortion - (DumpPortion  << pParams->hKi_Divisor);
        }
    }

    pParams->wIntegral = (IntegralPortion);

    return (s16) PIoutput;
}
