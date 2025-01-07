#include "global_variable.h"
#include "hardware_config.h"
void Hardware_init(void);
void SystemInit(void);
void PGA_init(void);
void DAC_init(void);
void ADC_init(void);
void ADC_NormalModeCFG(void);
void GPIO_init(void);
void MCPWM_init(void);
void MCPWM0_RegUpdate(stru_VoltPhaseUVW VoltPhaseUVW);
void SoftDelay(u32 cnt);
void UART_init(void);
/*******************************************************************************
 º¯ÊıÃû³Æ£º    void Hardware_init(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯ÍâÉè
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void Hardware_init(void)
{
	DSP_Init();                       	/* DSPÄ£¿é³õÊ¼»¯*/
	ADC_init();    						/* ADC³õÊ¼»¯ */
	MCPWM_init();   					/* PWM³õÊ¼»¯ */
    
	  GPIO_init();    					/* GPIO³õÊ¼»¯ */
    PGA_init();                       	/* PGA ³õÊ¼»¯ */
    UART_init();                /* UART??'?? */
	  SoftDelay(100);                   	/* ÑÓÊ±µÈ´ıÓ²¼ş³õÊ¼»¯ÎÈ¶¨ */
    
    NVIC_SetPriority(ADC0_IRQn, 1);
    NVIC_EnableIRQ(ADC0_IRQn);
    NVIC_SetPriority(PendSV_IRQn,3);
    NVIC_EnableIRQ(PendSV_IRQn);
	
	
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void SystemInit(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯Ê±ÖÓ£¬ÉÏµçºóÔÚMAINº¯ÊıÖ®Ç°ÔËĞĞ
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void SystemInit(void)
{
    SYS_WR_PROTECT = 0x7a83;    // ½â³ıÏµÍ³¼Ä´æÆ÷Ğ´±£»¤
    SYS_AFE_REG5 = BIT15;       // BIT15:PLLPDN ¿ªPLL
    SoftDelay(100);             // ÑÓÊ±100us, µÈ´ıPLLÎÈ¶¨ 21.4.17
    SYS_CLK_CFG = 0x000001ff;   // Ğ¾Æ¬Ê±ÖÓ96Mhz
    FLASH_CFG = BIT19;          // ¿ªÆôÔ¤È¡¼ÓËÙ
}
/*******************************************************************************
 º¯ÊıÃû³Æ£º    void PGA_init(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯ÔË·Å
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void PGA_init(void)
{
	//SYS_AFE_REG5 |= 0x20ff;
  //  SYS_AFE_REG0 = PGA_GAIN_20 | PGA_GAIN_20<<2;
	
	
	
	OPA_InitTypeDef OPA_InitStruct;
	OPA_StructInit(&OPA_InitStruct);
	
	OPA_InitStruct.OPA_CLEna = ENABLE;
	OPA_InitStruct.OPA_Gain = PGA_GAIN_20;
	OPA_Init(OPA0 ,&OPA_InitStruct);
	
	OPA_InitStruct.OPA_CLEna = ENABLE;
	OPA_InitStruct.OPA_Gain = PGA_GAIN_20;
	OPA_Init(OPA2 ,&OPA_InitStruct);
	
	OPA_InitStruct.OPA_CLEna = ENABLE;
	OPA_InitStruct.OPA_Gain = PGA_GAIN_20;
	OPA_Init(OPA3 ,&OPA_InitStruct);
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void ADC_init(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯ADC
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void ADC_init(void) 
{
   
	
	 ADC_InitTypeDef ADC_InitStructure;
    ADC_StructInit(&ADC_InitStructure);                          //??'??????
    ADC_InitStructure.IE = ADC_EOS0_IRQ_EN ; //??h???????????'???ADC_DAT0????????
    ADC_InitStructure.Align = ADC_LEFT_ALIGN;                    //ADC????????????
    ADC_InitStructure.UTIMER_Trigger_En = DISABLE;               //UTIMER_T0???????ADC????
    ADC_InitStructure.MCPWM_Trigger_En = ADC_MCPWM_T0_TRG;       //???MCPWM????????
    ADC_InitStructure.FirSeg_Ch = ADC_5_TIMES_SAMPLE;            //??h?ß????????????: 1~20
    ADC_InitStructure.Trigger_Cnt = 0;                           /*???d???g??´???h?ß???????????¼???:0~15 0??????h?d?????15??????16??*/
    ADC_InitStructure.Trigger_Mode = ADC_1SEG_TRG;               /*ADC????1??g?*/                                        //????ADC0_DARA0????ADC0_DAT0_TH????????ADC?????????
    ADC_Init(ADC0, &ADC_InitStructure);
    ADC0_IF = 0xff;                                   //????????
	  SYS_AFE_REG1 |= 1 << 3;
    ADC0_GAIN0 = 0x1;                                 //????2/3????
	  ADC0_GAIN1 = 0x1;                                 //????2/3????
    //ADC0_CHN0 = ADC_CHANNEL_9 | (ADC_CHANNEL_9 << 8); //??????????1??2
    //	  ADC0_TRIG=0x4010;//??'????????g?

    ADC_NormalModeCFG();
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void ADC_NormalModeCFG(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯ADC²ÉÑùÍ¨µÀ
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void ADC_NormalModeCFG(void)
{
    ADC0_CHN0 = ADC0_CURRETN_A_CHANNEL | ADC0_CURRETN_B_CHANNEL<<8;
    ADC0_CHN1 = ADC0_CURRETN_C_CHANNEL | ADC0_BUS_VOL_MSK << 8;
	  ADC0_CHN2 =  ADC0_TEMP_MSK;
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void GPIO_init(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯GPIO
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void GPIO_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    /* MCPWM P1.4~P1.9 */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_Init(GPIO1, &GPIO_InitStruct);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_4, AF3_MCPWM);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_5, AF3_MCPWM);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_6, AF3_MCPWM);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_7, AF3_MCPWM);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_8, AF3_MCPWM);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_9, AF3_MCPWM);
    /* start  */
	
 
    GPIO1_POE |= GPIO_Pin_12 | GPIO_Pin_15;
    GPIO3_POE |= GPIO_Pin_13;
    
	
	  GPIO_StructInit(&GPIO_InitStruct);         //??'??????
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //GPIO???g?
    GPIO_InitStruct.GPIO_Pin = LEDR;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LEDRGPIO, &GPIO_InitStruct);

	  GPIO_StructInit(&GPIO_InitStruct);         //??'??????
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //GPIO???g?
    GPIO_InitStruct.GPIO_Pin = LEDG;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LEDGGPIO, &GPIO_InitStruct);
		 
	  GPIO_StructInit(&GPIO_InitStruct);         //??'??????
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //GPIO???g?
    GPIO_InitStruct.GPIO_Pin = LEDB;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LEDBGPIO, &GPIO_InitStruct);
		GPIO_SetBits(LEDRGPIO, LEDR);
		GPIO_SetBits(LEDGGPIO, LEDG);
		GPIO_SetBits(LEDBGPIO, LEDB);
		
		GPIO_PinAFConfig(GPIO0, GPIO_PinSource_15, AF4_UART);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_0, AF4_UART);	
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void MCPWM_init(void)
 ¹¦ÄÜÃèÊö£º    ³õÊ¼»¯MCPWM
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void MCPWM_init(void)
{
    MCPWM_InitTypeDef MCPWM_InitStructure;

    MCPWM_StructInit(&MCPWM_InitStructure);

    MCPWM_InitStructure.CLK_DIV = 0;
    MCPWM_InitStructure.MCLK_EN = ENABLE;
    MCPWM_InitStructure.MCPWM_Cnt_EN = ENABLE; 					
    MCPWM_InitStructure.MCPWM_WorkModeCH0 = CENTRAL_PWM_MODE;
    MCPWM_InitStructure.MCPWM_WorkModeCH1 = CENTRAL_PWM_MODE;
    MCPWM_InitStructure.MCPWM_WorkModeCH2 = CENTRAL_PWM_MODE;
    MCPWM_InitStructure.MCPWM_WorkModeCH3 = CENTRAL_PWM_MODE; 	

    MCPWM_InitStructure.GPIO_BKIN_Filter = 12;
    MCPWM_InitStructure.CMP_BKIN_Filter = 12; 					

    MCPWM_InitStructure.MCPWM_PERIOD = PWM_PERIOD;
    MCPWM_InitStructure.TriggerPoint0 = (u16)(10 - PWM_PERIOD);
    MCPWM_InitStructure.TriggerPoint1 = (u16)(PWM_PERIOD - 1);
    MCPWM_InitStructure.DeadTimeCH0N = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH0P = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH1N = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH1P = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH2N = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH2P = DEADTIME; 		
    MCPWM_InitStructure.DeadTimeCH3N = DEADTIME;
    MCPWM_InitStructure.DeadTimeCH3P = DEADTIME;
		
    MCPWM_InitStructure.CH0N_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH0P_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH1N_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH1P_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH2N_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH2P_Polarity_INV = DISABLE; 	
    MCPWM_InitStructure.CH3N_Polarity_INV = DISABLE;
    MCPWM_InitStructure.CH3P_Polarity_INV = DISABLE; 
		
    MCPWM_InitStructure.Switch_CH0N_CH0P = DISABLE; 	
    MCPWM_InitStructure.Switch_CH1N_CH1P = DISABLE; 	
    MCPWM_InitStructure.Switch_CH2N_CH2P = DISABLE; 	
    MCPWM_InitStructure.Switch_CH3N_CH3P = DISABLE;
		
    MCPWM_InitStructure.CH0P_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH0N_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH1P_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH1N_default_output = LOW_LEVEL; 
    MCPWM_InitStructure.CH2P_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH2N_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH3P_default_output = LOW_LEVEL;
    MCPWM_InitStructure.CH3N_default_output = LOW_LEVEL;

    MCPWM_InitStructure.DebugMode_PWM_out = ENABLE;

    MCPWM_InitStructure.MCPWM_T0_UpdateEN = ENABLE;
    MCPWM_InitStructure.MCPWM_T1_UpdateEN = DISABLE;

    MCPWM_InitStructure.T0_Update_INT_EN = DISABLE;

    MCPWM_Init(&MCPWM_InitStructure);
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void MCPWM0_RegUpdate(stru_VoltPhaseUVW VoltPhaseUVW)
 ¹¦ÄÜÃèÊö£º    ¸üĞÂPWMÕ¼¿Õ±È
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void MCPWM0_RegUpdate(stru_VoltPhaseUVW VoltPhaseUVW)
{
	//VoltPhaseUVW.nPhaseU = 0;
	//VoltPhaseUVW.nPhaseV = 00;
	//VoltPhaseUVW.nPhaseW  =0;
	MCPWM_TH20 = -VoltPhaseUVW.nPhaseU;
	MCPWM_TH21 = VoltPhaseUVW.nPhaseU;

	MCPWM_TH10=  -VoltPhaseUVW.nPhaseV;
	MCPWM_TH11 = VoltPhaseUVW.nPhaseV;

	MCPWM_TH00 = -VoltPhaseUVW.nPhaseW;
	MCPWM_TH01 = VoltPhaseUVW.nPhaseW;
}

/*******************************************************************************
 º¯ÊıÃû³Æ£º    void SoftDelay(u32 cnt)
 ¹¦ÄÜÃèÊö£º    Èí¼şÑÓÊ±
 ÊäÈë²ÎÊı£º    ÎŞ
 ·µ »Ø Öµ£º    ÎŞ
 ÆäËüËµÃ÷£º
 ĞŞ¸ÄÈÕÆÚ      °æ±¾ºÅ          ĞŞ¸ÄÈË            ĞŞ¸ÄÄÚÈİ
 -----------------------------------------------------------------------------
 2022/06/23    V1.0           YangZJ            ´´½¨
 *******************************************************************************/
void SoftDelay(u32 cnt)
{
    volatile u32 t_cnt;

    for(t_cnt = 0; t_cnt < cnt; t_cnt++)
    {
        __NOP();
    }
}
void UART_init(void)
{
    UART_InitTypeDef UART_InitStruct;

    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.BaudRate = 115200;                /* ???ò?????38400 */
    UART_InitStruct.WordLength = UART_WORDLENGTH_8b; /* ???????????8? */
    UART_InitStruct.StopBits = UART_STOPBITS_1b;     /* ???1? */
    UART_InitStruct.FirstSend = UART_FIRSTSEND_LSB;  /* ?????LSB */
    UART_InitStruct.ParityMode = UART_Parity_NO;     /* ????z??? */
    //UART_InitStruct.IRQEna = UART_IRQEna_SendOver;   /* ???????'?? */
    UART_Init(UART0, &UART_InitStruct);
	  UART0_IF = 0xff;
}
int fputc(int ch, FILE *f)
{
    /* ????h?????????????? */
    UART_SendData(UART0, (uint8_t)ch);
    /* ?????????? */
    while ((UART0->STT & BIT0) == FALSE)
        ; // UART0->STT????????????

    return (ch);
}


FILE __stdout;