/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_dsp.h
 * �ļ���ʶ��
 * ����ժҪ�� DSP����ͷ�ļ�
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
 
#ifndef __lks32mc08x_DSP_H
#define __lks32mc08x_DSP_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc08x.h"
#include "lks32mc08x_sys.h"
#include "basic.h"

typedef struct
{
    s16 hCos;
    s16 hSin;
} stru_Dsp_sincos;
stru_Dsp_sincos lks08x_dsp_sin_cos(s16 val);
s16 lks08x_dsp_sin(s16 val);
s16 lks08x_dsp_cos(s16 val);
u16 lks08x_dsp_rms(s16 a, s16 b);
u16 lks08x_dsp_arctan(s16 x, s16 y);
s32 lks08x_dsp_div(s32 a, s16 b);
s32 lks08x_dsp_mod(s32 a, s16 b);
u16 lks08x_dsp_sqrt(u32 val);


#endif 



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
