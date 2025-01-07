#include "global_variable.h"

/*******************************************************************************
 函数名称：    int main(void)
 功能描述：    主程序入口
 输入参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            创建
 *******************************************************************************/
int main(void)
{
    Hardware_init();// 硬件初始化
    sys_init();     // 软件初始化
//	printf("INITIAL OFFSETS: %d , %d , %d \n\r",
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset0,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset1,
//										struFOC_CtrProc.struFOC_CurrLoop.ADCOffset.Offset2);
    __enable_irq(); // 开中断
    //SCB->SCR = BIT1;// 配置系统休眠参数
    //GPIO_ResetBits(LEDRGPIO, LEDR);
		//GPIO_ResetBits(LEDGGPIO, LEDG);
		GPIO_ResetBits(LEDBGPIO, LEDB);
	 // __WFI();        // 主函数结束，中断函数开始运行
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
