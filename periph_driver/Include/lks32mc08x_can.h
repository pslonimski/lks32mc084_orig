#ifndef __CAN__H__
#define __CAN__H__
#include "lks32mc08x_sys.h"

typedef struct
{
	__IO uint32_t MOD;
	__IO uint32_t CMR;
	__IO uint32_t SR;
	__IO uint32_t IR;

	__IO uint32_t EIR;
	__IO uint32_t null0;
	__IO uint32_t BTR0;
	__IO uint32_t BTR1;

	__IO uint32_t null1;
	__IO uint32_t null2;
	__IO uint32_t null3;
	__IO uint32_t ALC;

	__IO uint32_t ECC;
	__IO uint32_t EWLR;
	__IO uint32_t RXERR;
	__IO uint32_t TXERR;

	__IO uint32_t TXRX0;
	__IO uint32_t TXRX1;
	__IO uint32_t TXRX2;
	__IO uint32_t TXRX3;

	__IO uint32_t TXRX4;
	__IO uint32_t TXRX5;
	__IO uint32_t TXRX6;
	__IO uint32_t TXRX7;

	__IO uint32_t TXRX8;
	__IO uint32_t TXRX9;
	__IO uint32_t TXRXA;
	__IO uint32_t TXRXB;

	__IO uint32_t TXRXC;
	__IO uint32_t RMC;
	__IO uint32_t RBSA;
} CAN_TypeDef;

#ifndef CAN
#define CAN             ((CAN_TypeDef *)CAN_BASE)
#endif

typedef struct
{
	uint32_t CAN_WorkMode;	       /*CAN����ģʽѡ�� 1���Բ�ģʽ 2������ģʽ 3;�����շ�ģʽ*/
	uint32_t CAN_DMAEn;		       /*ʹ��CAN��DMA����*/
	uint32_t CAN_ErrWarThre;       /*�����뾯������ֵ*/
	uint32_t CAN_Btr0;		       /*������ 0*/
	uint32_t CAN_Btr1;	  	       /*������ 1*/
	uint32_t IRQEna;		       /*�ж�ʹ��*/
} CAN_InitTypeDef;               
															   
															   
/*����ģʽѡ��*/                  
#define CAN_SELFTEST_MODE  BIT2    /*�Բ�ģʽ*/
#define CAN_MONITOR_MODE   BIT1    /*����ģʽ*/
#define CAN_NORMAL_MODE    0x0	   /*�����շ�ģʽ*/
															   
/*�ж�ʹ�ܶ���*/
#define CAN_IE_BUSERR       BIT7   /*���ߴ����ж�ʹ��*/
#define CAN_IE_LOSTARB      BIT6   /*��ʧ�ٲ��ж�ʹ��*/
#define CAN_IE_PASSIVEERR   BIT5   /*������������ж�ʹ��*/
#define CAN_IE_WAKE         BIT4   /*CANģ��������л����ж�ʹ��*/
#define CAN_IE_RFIFOOV      BIT3   /*RFIFO���ݷ�������ж�ʹ��*/
#define CAN_IE_WERR         BIT2   /*���󱨾��ж�ʹ��*/
#define CAN_IE_TXDONE       BIT1   /*������ϵ�ǰ֡�ж�ʹ��*/
#define CAN_IE_RFIFONOEMPTY BIT0   /*RFIFI0���µ����ݱ����յ��ж�ʹ��*/

/*�жϱ�־����,ע��CAN_IRΪ������Ĵ���,ֻ�� BIT0--RFIFO_N_EMPTY_IF �޷��������
��λֻ��ͨ����CAN_CMR BIT2 д 1 ������� RX FIFO �ж�֡���յ����ݣ�CAN_CMR BIT2
д 1 Ҳ�޷����������RX FIFO ȫ�����꣬����һ֡����д CAN_CMR BIT2������������*/
#define CAN_IF_BUSERR BIT7		   /*���ߴ����жϱ�־*/
#define CAN_IF_LOSTARB BIT6		   /*��ʧ�ٲ��жϱ�־*/
#define CAN_IF_PASSIVEERR BIT5	   /*������������жϱ�־*/
#define CAN_IF_WAKE BIT4		   /*CANģ��������л����жϱ�־*/
#define CAN_IF_RFIFOOV BIT3		   /*RFIFO���ݷ�������жϱ�־*/
#define CAN_IF_WERR BIT2		   /*���󱨾��жϱ�־*/
#define CAN_IF_TXDONE BIT1		   /*������ϵ�ǰ֡�жϱ�־*/
#define CAN_IF_RFIFONOEMPTY BIT0   /*RFIFI0���µ����ݱ����յ��жϱ�־*/

/*ѡ���ȡCAN_SR״̬����*/
#define CAN_ONBUS BIT7			   /*1��CAN ģ�飬���� BUS OFF ״̬�������ݷ��ͽ��ն��� \
									 0��CAN ģ�飬���Է������ݵ� CAN ���ߣ������ CAN ��������*/
#define CAN_ERROV BIT6			   /*1��CAN ��������Ĵ��������ﵽ�򳬹� CAN_EWL �涨ֵ \
									 0��CAN ��������Ĵ����������� CAN_EWL �涨ֵ*/
#define CAN_TXING BIT5			   /*1��CAN ģ�����ڷ���һ֡���� \
								     0��CAN ģ��û�з������ݵĶ���*/
#define CAN_RXING BIT4			   /*1��CAN ģ�����ڽ���һ֡���� \
									 0��CAN ģ��û�н������ݵĶ��� */
#define CAN_TRNASDONE BIT3	       /*1�����һ�δ�������� \
									 0�����һ�δ���δ���*/
#define CAN_TFIFOEMPTY BIT2        /*1��TFIFO �գ�����д�뷢������ \
								     0��TFIFO �ǿգ��ڲ�����û�з������*/
#define CAN_RFIFOEMPTY BIT1        /*1��RFIFO �����̫֡�࣬�������������ݶ�ʧ \
								     0��RFIFO δ��*/
#define CAN_DATAAVAIL BIT0	       /*1��RFIFO ����һ֡���֡���ݣ�����ͨ�� RFIFO �Ĵ�����ȡ \
									 0��RFIFO û����Ч֡����*/
#define CAN_ALLSR 0xff			   /*��ȡȫ��״̬*/

/*��¼�����ٲö�ʧ�ľ���λ�ö���*/
typedef enum
{
	CAN_LOST_ID0,  /*ID�ĵ�һλ*/
	CAN_LOST_ID1,  /*ID�ĵڶ�λ*/
	CAN_LOST_ID2,  /*ID�ĵ���λ*/
	CAN_LOST_ID3,  /*ID�ĵ���λ*/
	CAN_LOST_ID4,  /*ID�ĵ���λ*/
	CAN_LOST_ID5,  /*ID�ĵ���λ*/
	CAN_LOST_ID6,  /*ID�ĵ���λ*/
	CAN_LOST_ID7,  /*ID�ĵڰ�λ*/
	CAN_LOST_ID8,  /*ID�ĵھ�λ*/
	CAN_LOST_ID9,  /*ID�ĵ�ʮλ*/
	CAN_LOST_IDA,  /*ID�ĵ�ʮһλ*/
	CAN_LOST_SRTR, /*ID��SRTRλ*/
	CAN_LOST_IDE,  /*ID��IDEλ*/
} enumLossposition;

/*���ߴ�������*/
typedef enum
{
	CAN_BITERROR,	 /*bit����*/
	CAN_FORMATERROR, /*��ʽ����*/
	CAN_FILLERROR,	 /*������*/
	CAN_OTHERERROR,	 /*�������ʹ���*/
} enumErrortype;

/*���ߴ�����ʱ��*/
typedef enum
{
	CAN_RECE_PROCESS, /*���ߴ������ڷ��͹�����*/
	CAN_SEND_PROCESS, /*���ߴ������ڽ��չ�����*/
} enumErrortime;

/*���ߴ�������λ�ö���*/
typedef enum
{
	null0,
	null1,
	CAN_ID28_ID21,		     /*ID.28 �� ID.21*/
	CAN_START,			     /*��ʼ֡*/
	CAN_SRTR,			     /*SRTR λ*/
	CAN_IDE,			     /*IDE λ*/
	CAN_ID20_ID18,		     /*ID.20 �� ID.18*/
	CAN_ID17_ID13,		     /*ID.17 �� ID.13*/
	CAN_CRC,			     /*CRC ���ݶ�*/
	CAN_KEEP0,			     /*����λ���̶�Ϊ 0*/
	CAN_DATA_FIELD,		     /*Data Field*/
	CAN_DATALENGTHCODE,      /*Data Length Code*/
	CAN_RTR,			     /*RTR λ*/
	CAN_KEEP1,			     /*����λ���̶�Ϊ 1*/
	CAN_ID4_ID0,		     /*ID.4 �� ID.0*/
	CAN_ID15_ID12,	     	 /*ID.12 �� ID.5*/
	null2,
	CAN_ACTIVE_ERROR_FLAG,   /*active error flag*/
	CAN_INTERMISSION,	     /*Intermission*/
	CAN_TOLERATE_DOMINANT,   /*Tolerate dominantλ*/
	null3,
	null4,
	CAN_PASSIVE_ERROR,		 /*passive error flag*/
	CAN_ERROR_DELIMITER,	 /*Error delimiter*/
	CAN_CRC_DELIMITER,		 /*CRC delimiter*/
	CAN_CONNFIRM,			 /*ȷ��λ*/
	CAN_FRAMEEND,			 /*֡����*/
	CAN_CONNFIRM_DELIMITER,  /*ȷ�� delimiter*/
	CAN_OVERLOAD_FLAG,		 /*Overload flag*/
} enumErrposition;


void CAN_StructInit(CAN_InitTypeDef *CAN_InitStruct);
void CAN_Init(CAN_TypeDef *CANx, CAN_InitTypeDef *CAN_InitStruct);
void SFF_ID_Filter(u32 acr, u32 amr, u8 rtr_acr, u8 rtr_amr, u8 Byte1_acr, u8 Byte1_amr, u8 Byte2_acr, u8 Byte2_amr);
void EFF_ID_Filter(u32 acr, u32 amr, u8 rtr_acr, u8 rtr_amr);
void ID1_Filter_Dual(u32 acr1, u32 amr1, u8 rtr_acr1, u8 rtr_amr1, u8 Byte_acr1, u8 Byte_amr1, u8 ide);
void ID2_Filter_Dual(u32 acr2, u32 amr2, u8 rtr_acr2, u8 rtr_amr2, u8 ide);
u8 My_CAN_Send_Msg(u32 id, u8 ide, u8 rtr, u8 *msg, u8 len);
u8 CAN_Receive_Msg(u32 *id, u8 *ide, u8 *rtr, u8 *buf);
uint8_t CAN_ReadState(CAN_TypeDef *CANx, uint32_t sr);
uint32_t CAN_GetIRQFlag(void);
void CAN_Sleep(u32 Baud);
void CAN_Manual_Awake(void);

#endif
