#include "global_variable.h"
#include "hardware_config.h"
#include "SMO.h"                 // Device header
void sys_init(void);
void currentOffsetRead(void);

/*******************************************************************************
 函数名称：    void sys_init(void)
 功能描述：    初始化全局变量
 输入参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            创建
 *******************************************************************************/
void sys_init(void)
{	
	FOC_InitstruParama(&struFOC_CtrProc);
  //  currentOffsetRead();
}
/*******************************************************************************
 函数名称：    void currentOffsetRead(void)
 功能描述：    读电流偏置
 输入参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            创建
 *******************************************************************************/
 void currentOffsetRead(void)
{
    volatile s32 t_offset0=0,t_offset1=0, t_offset2=0;
    volatile u16 t_cnt;
	MCPWM_TH20 = 0;
	MCPWM_TH21 = 0;

	MCPWM_TH10=  0;
	MCPWM_TH11 = 0;

	MCPWM_TH00 = 0;
	MCPWM_TH01 = 0;
    for (t_cnt = 0; t_cnt < 512; t_cnt++)
    {
        ADC0_IF = 3;
        ADC0_SWT = 0x00005AA5;
        while(ADC0_IF&3);
        t_offset0 += (s16)((ADC0_DAT0));
        t_offset1 += (s16)((ADC0_DAT1));
			  t_offset2 += (s16)((ADC0_DAT2));
    }
	struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0 = (s16)(t_offset0 >> 9);
	struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1 = (s16)(t_offset1 >> 9);
	struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2 = (s16)(t_offset2 >> 9);
		printf("CALIBRATED OFFSETS: %d , %d , %d\n\r",
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2);
}
