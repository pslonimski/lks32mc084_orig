#include "SMO.h" // Device header
#include "math.h"
void SMO_init(stru_SMODef *this);
void SMO_clear(stru_SMODef *this);
s16 SMO_CalcElAngle(stru_SMODef * this,stru_CurrAlphBeta Ialfa_beta, stru_VoltAlphBeta Valfa_beta);

/*******************************************************************************
 �������ƣ�    void SMO_init(stru_SMODef *this)
 ����������    ��Ĥ�۲�����ʼ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void SMO_init(stru_SMODef *this)
{
	this->coef.Fsmopos = (s32)(exp((-RS/LS)/PWM_FREQ) * 32768);
	this->coef.Gsmopos = (s32)(U_RATED_VOLTAGE / 2 / ADC_SUPPLY_VOLTAGE / PHASE_RSHUNT / AMPLIFICATION_GAIN / RS *(1-exp((-RS/LS)/PWM_FREQ))*32768);
	this->coef.Kslide = 20000 ;
	this->coef.Kslf =20000;
	this->coef.E0= 32670 ;
    this->coef.wZeroSpeedTime = 1000;
}

/*******************************************************************************
 �������ƣ�    void SMO_clear(stru_SMODef *this)
 ����������    ��Ĥ�۲�����λ
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void SMO_clear(stru_SMODef *this)
{
    memset(&this->variable, 0, sizeof(this->variable));
}

/*******************************************************************************
 �������ƣ�    s16 SMO_CalcElAngle(stru_SMODef * this,stru_CurrAlphBeta Ialfa_beta, stru_VoltAlphBeta Valfa_beta)
 ����������    ������Ĥ�۲������㲢�õ��Ƕ�
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/

s16 SMO_CalcElAngle(stru_SMODef * this,stru_CurrAlphBeta Ialfa_beta, stru_VoltAlphBeta Valfa_beta)
{
    s16 EstIalpha,EstIbeta,Ealpha ,Ebeta,Zalpha,Zbeta ;
    
    
    // ��Ĥ�۲���
    Zalpha      = (sat(this->variable.EstIalpha - Ialfa_beta.nAlph,-this->coef.E0,this->coef.E0)*this->coef.Kslide)>>15;
    Zbeta       = (sat(this->variable.EstIbeta  - Ialfa_beta.nBeta ,-this->coef.E0,this->coef.E0)*this->coef.Kslide)>>15;
    Ealpha      = this->variable.Ealpha + ((this->coef.Kslf * (this->variable.Zalpha-this->variable.Ealpha))>>15);
    Ebeta       = this->variable.Ebeta  + ((this->coef.Kslf * (this->variable.Zbeta -this->variable.Ebeta))>>15);
    EstIalpha   = (this->coef.Fsmopos * this->variable.EstIalpha + this->coef.Gsmopos * (Valfa_beta.nAlph-this->variable.Ealpha-this->variable.Zalpha))>>15;
    EstIbeta    = (this->coef.Fsmopos * this->variable.EstIbeta + this->coef.Gsmopos * (Valfa_beta.nBeta -this->variable.Ebeta -this->variable.Zbeta ))>>15;

    this->variable.EstIalpha = EstIalpha;
    this->variable.EstIbeta  = EstIbeta;
    this->variable.Ealpha    = Ealpha;
    this->variable.Ebeta     = Ebeta;
    this->variable.Zalpha    = Zalpha;
    this->variable.Zbeta     = Zbeta;
    
    
    // �����еõ��Ƕ�
    this->variable.angle = -lks08x_dsp_arctan(this->variable.Ebeta,this->variable.Ealpha);

    // �����Ƕȴ���
    if(this->variable.bAngleClosedLoop == 0)
    {
        s16 angle;
        this->variable.wOpenAngle += this->variable.wOpenSpeed;
        angle = this->variable.wOpenAngle>>16;
        this->variable.angleopentoclose = angle - this->variable.angle;
        return angle;
    }
    else
    {
        s16 angle;
        angle = this->variable.angle + this->variable.angleopentoclose;
        return angle;
    }
}
