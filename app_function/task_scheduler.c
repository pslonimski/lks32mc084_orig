#include "global_variable.h"
#include "hardware_config.h"
#include "SMO.h"
void Sys_State_Machine(stru_FOC_CtrProcDef *this);
void StopMotorImmdly(stru_FOC_CtrProcDef *this);
void Sys_State_Run(stru_FOC_CtrProcDef *this);
void Curr_rc_fir(Stru_Curr_RC * this);

/*******************************************************************************
 �������ƣ�    void Sys_State_Machine(stru_FOC_CtrProcDef *this)
 ����������    ��ʼ��ȫ�ֱ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void Sys_State_Machine(stru_FOC_CtrProcDef *this)
{
    
//	GPIO_SetBits(LEDRGPIO, LEDR);
	GPIO_SetBits(LEDGGPIO, LEDG);
	GPIO_SetBits(LEDBGPIO, LEDB);
	  switch (this->eSysState)
    {
    case IDLE:
    {
			  GPIO_ResetBits(LEDGGPIO, LEDG);
        if ((this->bMC_RunFlg) && (this->stru_Faults.R == 0))
        {
            this->eSysState = INIT;
        }
        break;
    }

    case INIT:
    {
        MCL_Init(this);
        PWMOutputs(ENABLE);
        this->eSysState = RUN;
        break;
    }

    case RUN:
    {
        if ((this->bMC_RunFlg == 0) || (this->stru_Faults.R))
        {
            this->eSysState = STOP;
        }
        Sys_State_Run(this);
				GPIO_ResetBits(LEDBGPIO, LEDB);
        break;
    }

    case STOP:
    {
		//	  GPIO_ResetBits(LEDRGPIO, LEDR);
        StopMotorImmdly(this);
        MCL_Init(this);
        this->eSysState = IDLE;
        break;
    }
    }
}
/*******************************************************************************
 �������ƣ�    void StopMotorImmdly(stru_FOC_CtrProcDef *this)
 ����������    ͣ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void StopMotorImmdly(stru_FOC_CtrProcDef *this)
{
    PWMOutputs(DISABLE); 
    this->bMC_RunFlg = 0;
    if (this->eSysState == RUN)
    {
        this->eSysState = STOP;
    }
}
/*******************************************************************************
 �������ƣ�    void Sys_State_Run(stru_FOC_CtrProcDef *this)
 ����������    ��ʼ��ȫ�ֱ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void Sys_State_Run(stru_FOC_CtrProcDef *this)
{
    // �����ٶȴ���
    if(this->stru_SMO.variable.bAngleClosedLoop == 0)
    {
        if(this->stru_SMO.variable.wZeroSpeedCnt < this->stru_SMO.coef.wZeroSpeedTime)
        {
            this->stru_SMO.variable.wZeroSpeedCnt++;
        }
        else
        {
            if(this->stru_SMO.variable.wOpenSpeed < (100<<16))
            {
                this->stru_SMO.variable.wOpenSpeed += 800;
                this->struFOC_CurrLoop.stru_QCur.set = 12000 ;
                this->struFOC_CurrLoop.stru_DCur.set = 0;
            }
            else
            {
                this->struSpeed_loop.wIntegral = this->struFOC_CurrLoop.stru_QCur.set<<this->struSpeed_loop.hKi_Divisor;
                this->stru_SMO.variable.bAngleClosedLoop = 1;
//                this->struFOC_CurrLoop.stru_DCur.set = 0;
            }
        }
    }
    else
    {
        if(this->stru_SMO.variable.speed < 0)
        {
            this->eSysState = STOP;
					 GPIO_ResetBits(LEDRGPIO, LEDR);
        }
//        if(this->stru_SMO.variable.speed > 32767)
//        {
//            this->eSysState = STOP;
//        }
    }
    // ���ջ��л�
    if(ABS(this->stru_SMO.variable.angleopentoclose)>10)
    {
        if(this->stru_SMO.variable.angleopentoclose>0)
        {
            this->stru_SMO.variable.angleopentoclose -= 10;
        }
        else
        {
            this->stru_SMO.variable.angleopentoclose += 10;
        }
    }
    else
    {
            this->stru_SMO.variable.angleopentoclose = 0;
        this->struFOC_CurrLoop.stru_QCur.set = HL_PI_AntiDump(1000-this->stru_SMO.variable.speed, &this->struSpeed_loop);
//        this->struFOC_CurrLoop.stru_QCur.set = 5000;
    }
    // ��������
    Curr_rc_fir(&this->struFOC_CurrLoop.stru_QCur);
    Curr_rc_fir(&this->struFOC_CurrLoop.stru_DCur);
    // �ٶȼ���
    this->stru_SMO.variable.speed =(s16)( this->stru_SMO.variable.angle - this->stru_SMO.variable.SpeedCalcOldAngle);
    this->stru_SMO.variable.SpeedCalcOldAngle = this->stru_SMO.variable.angle;
}
/*******************************************************************************
 �������ƣ�    void Curr_rc_fir(Stru_Curr_RC * this)
 ����������    ��ʼ��ȫ�ֱ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void Curr_rc_fir(Stru_Curr_RC * this)
{
    s16 old;
    old = this->ref ;
    this->ref = (this->set * this->coeff + this->ref*(32768 - this->coeff) + 16384)>>15;
    if(this->ref == old)
    {
        if(this->ref < this->set)
        {
            this->ref ++;
        }
        else if(this->ref > this->set)
        {
            this->ref --;
        }
    }
}
