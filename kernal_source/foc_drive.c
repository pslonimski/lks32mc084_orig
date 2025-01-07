#include "global_variable.h"
#include "hardware_config.h"
#include "SMO.h"
void FOC_InitstruParama(stru_FOC_CtrProcDef *this);
stru_CurrPhaseUVW get_adc_curr(stru_ADCOffset offset);
void FOC_Model(stru_FOC_CtrProcDef *this);
void MCL_Init(stru_FOC_CtrProcDef *this);

/*******************************************************************************
 �������ƣ�    stru_TrigComponents Trig_Functions(s16 hAngle)
 ����������    ��������
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
void FOC_InitstruParama(stru_FOC_CtrProcDef *this)
{
		/* Q��PI��ʼ�� */
	this->struFOC_CurrLoop.struPI_Q_Torque.hKp_Gain = PID_TORQUE_KP_DEFAULT;
    this->struFOC_CurrLoop.struPI_Q_Torque.hKp_Divisor = TF_KPDIV;
    this->struFOC_CurrLoop.struPI_Q_Torque.hKi_Gain = PID_TORQUE_KI_DEFAULT;
    this->struFOC_CurrLoop.struPI_Q_Torque.hKi_Divisor = TF_KIDIV;
    this->struFOC_CurrLoop.struPI_Q_Torque.hLower_Limit_Output = -MAX_VQ_LIM; /* Lower Limit for Output limitation */
    this->struFOC_CurrLoop.struPI_Q_Torque.hUpper_Limit_Output = MAX_VQ_LIM; /* Upper Limit for Output limitation */
    this->struFOC_CurrLoop.struPI_Q_Torque.wLower_Limit_Integral = -(MAX_VQ_LIM << TF_KIDIV);
    this->struFOC_CurrLoop.struPI_Q_Torque.wUpper_Limit_Integral = MAX_VQ_LIM << TF_KIDIV;
    this->struFOC_CurrLoop.struPI_Q_Torque.wIntegral = 0;

		/* D��PI��ʼ�� */	
    this->struFOC_CurrLoop.struPI_D_Flux.hKp_Gain = PID_FLUX_KP_DEFAULT;
    this->struFOC_CurrLoop.struPI_D_Flux.hKp_Divisor = FLUX_KPDIV;
    this->struFOC_CurrLoop.struPI_D_Flux.hKi_Gain = PID_FLUX_KI_DEFAULT;
    this->struFOC_CurrLoop.struPI_D_Flux.hKi_Divisor = FLUX_KIDIV;
    this->struFOC_CurrLoop.struPI_D_Flux.hLower_Limit_Output = -MAX_VD_LIM; /* Lower Limit for Output limitation */
    this->struFOC_CurrLoop.struPI_D_Flux.hUpper_Limit_Output = MAX_VD_LIM; /* Upper Limit for Output limitation */
    this->struFOC_CurrLoop.struPI_D_Flux.wLower_Limit_Integral = -(MAX_VD_LIM << FLUX_KIDIV);
    this->struFOC_CurrLoop.struPI_D_Flux.wUpper_Limit_Integral = MAX_VD_LIM << FLUX_KIDIV;
    this->struFOC_CurrLoop.struPI_D_Flux.wIntegral = 0;

    this->struFOC_CurrLoop.stru_QCur.coeff = 200;
    this->struFOC_CurrLoop.stru_DCur.coeff = 200;
    
	this->eSysState = IDLE;/* ϵͳ״̬������ */

    this->bMC_RunFlg = 0;
    
		/* �ٶȻ�PI��ʼ�� */	
    this->struSpeed_loop.hKp_Gain                 = PID_SPEED_KP_DEFAULT;
    this->struSpeed_loop.hKp_Divisor              = SP_KPDIV;
    this->struSpeed_loop.hKi_Gain                 = PID_SPEED_KI_DEFAULT;
    this->struSpeed_loop.hKi_Divisor              = SP_KIDIV;
    this->struSpeed_loop.hLower_Limit_Output      = -20000; /* Lower Limit for Output limitation */
    this->struSpeed_loop.hUpper_Limit_Output      = 20000; /* Upper Limit for Output limitation */
    this->struSpeed_loop.wLower_Limit_Integral    = -(20000 << SP_KIDIV);
    this->struSpeed_loop.wUpper_Limit_Integral    = 20000 << SP_KIDIV;
    this->struSpeed_loop.wIntegral                = 0;

    SMO_init(&this->stru_SMO);                               /* ��Ĥ�۲�����ʼ�� */ 
}
/*******************************************************************************
 �������ƣ�    stru_TrigComponents Trig_Functions(s16 hAngle)
 ����������    ��������
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
stru_CurrPhaseUVW get_adc_curr(stru_ADCOffset offset)
{
    stru_CurrPhaseUVW curr;
    curr.nPhaseW = ADC0_DAT0 - offset.Offset0;
    curr.nPhaseV = ADC0_DAT1 - offset.Offset1;
    curr.nPhaseU = ADC0_DAT2 - offset.Offset2;//-curr.nPhaseU - curr.nPhaseV;
    return curr;
}

/*******************************************************************************
 �������ƣ�    void FOC_Model(stru_FOC_CtrProcDef *this)
 ����������    FOC��·
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/
    
void FOC_Model(stru_FOC_CtrProcDef *this)
{
   //s16 theatae;
    
    stru_CurrAlphBeta   CurrAlphBeta;       // ��ֹ����ϵ����
    stru_CurrVoctorDQ   CurrVoctorDQ;       // ��ת����ϵ����
    stru_VoltVoctorDQ   VoltVoctorDQ;       // ��ת����ϵ��ѹ
    stru_VoltPhaseUVW   VoltPhaseUVW;       // �����ѹ
    stru_TrigComponents struTrigSinCos;     // ת�ӽǶ����Ǽ���ֵ
		if(struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0 ==0)
		{ 
				FOC_InitstruParama(&struFOC_CtrProc);
				currentOffsetRead();  
		}
	
    /* �����120�ȵĻ���3����������任��2��Ķ��Ӿ�ֹ����ϵ�� */
	this->stru_SMO.variable.CurrPhaseUVW = get_adc_curr(this->struFOC_CurrLoop.ADCOffset);
	
    CurrAlphBeta = Clarke(this->stru_SMO.variable.CurrPhaseUVW);
    
    /* ��Ĥ�۲�������õ���ǰ�Ƕ� */
    this->stru_SMO.variable.theatae = SMO_CalcElAngle(&this->stru_SMO,
                                        CurrAlphBeta,
                                        this->struFOC_CurrLoop.VoltAlphBeta);
//    printf("CURRENT: %d , %d , %d T: %d\n\r",
//										CurrPhaseUVW2.nPhaseW,
//										CurrPhaseUVW2.nPhaseV,
//										CurrPhaseUVW2.nPhaseU,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2,
//										theatae);;//,ADC0_DAT3,ADC0_DAT4);
   
//		if(this->stru_SMO.variable.theatae !=0)  printf("%d\n\r",struFOC_CtrProc.stru_SMO.variable.theatae);
		/* �ԽǶ������Ǽ��� */
    struTrigSinCos = Trig_Functions(struFOC_CtrProc.stru_SMO.variable.theatae);
    
    /* ��Ialpha��Ibeta�任����ת��dq����ϵ�� */
    CurrVoctorDQ = Park(CurrAlphBeta,struTrigSinCos);

		
    /* ���������� */
    VoltVoctorDQ.nAxisD = HL_PI_AntiDump(this->struFOC_CurrLoop.stru_DCur.ref-CurrVoctorDQ.nAxisD, &this->struFOC_CurrLoop.struPI_D_Flux);
    VoltVoctorDQ.nAxisQ = HL_PI_AntiDump(this->struFOC_CurrLoop.stru_QCur.ref-CurrVoctorDQ.nAxisQ, &this->struFOC_CurrLoop.struPI_Q_Torque);
    
	/* ��ѹ����Բ����, ��ֹVd Vq���󣬳������������� */
	VoltVoctorDQ = RevPark_Circle_Limitation(VoltVoctorDQ);

	/* ����ת����ϵ�µ�Vd Vq �任����ֹ�����µ�Valpha��Vbeta */
	this->struFOC_CurrLoop.VoltAlphBeta = Rev_Park(VoltVoctorDQ,struTrigSinCos);
	
	/*Valpha Vbeta ����SVPWM�ռ�ʸ������ */
    VoltPhaseUVW = SVPWM(this->struFOC_CurrLoop.VoltAlphBeta,PWM_PERIOD);
    
	/* SVPWM���������µ��Ĵ�������CNT�ᵽ-THʱ�Զ����µ�MCPWM */
	MCPWM0_RegUpdate(VoltPhaseUVW);
}

/*******************************************************************************
 �������ƣ�    void MCL_Init(stru_FOC_CtrProcDef *this)
 ����������    ��λȫ�ֱ���
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ����
 *******************************************************************************/

void MCL_Init(stru_FOC_CtrProcDef *this)
{
    this->struFOC_CurrLoop.struPI_D_Flux.wIntegral = 0;
    this->struFOC_CurrLoop.struPI_Q_Torque.wIntegral = 0;
	
    this->struSpeed_loop.wIntegral = 0;
    this->struFOC_CurrLoop.stru_QCur.ref = 0;
    this->struFOC_CurrLoop.stru_DCur.ref = 0;
    SMO_clear(&this->stru_SMO);
}

/*****END OF FILE****/
