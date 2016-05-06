#ifndef  _PROTOCOL_Optics
#define  _PROTOCOL_Optics

#ifdef _OT_CPP_
#undef _OT_CPP_
#endif

#define FP_MAXWAITTIME 2000
#define DELAY_TIME     150
///////////////////���󷵻���////////////////////
#define FP_OK                0x00
#define FP_COMM_ERR          0x01
#define FP_NO_FINGER         0x02
#define FP_GET_IMG_ERR       0x03
#define FP_FP_TOO_DRY        0x04
#define FP_FP_TOO_WET        0x05
#define FP_FP_DISORDER       0x06
#define FP_LITTLE_FEATURE    0x07
#define FP_NOT_MATCH         0x08
#define FP_NOT_SEARCHED      0x09
#define FP_MERGE_ERR         0x0a
#define FP_ADDRESS_OVER      0x0b
#define FP_READ_ERR          0x0c
#define FP_UP_TEMP_ERR       0x0d
#define FP_RECV_ERR          0x0e
#define FP_UP_IMG_ERR        0x0f
#define FP_DEL_TEMP_ERR      0x10
#define FP_CLEAR_TEMP_ERR    0x11
#define FP_SLEEP_ERR         0x12
#define FP_INVALID_PASSWORD  0x13
#define FP_RESET_ERR         0x14
#define FP_INVALID_IMAGE     0x15
#define FP_HANGOVER_UNREMOVE 0X17
 

///////////////������//////////////////////////////
#define CHAR_BUFFER_A          0x01
#define CHAR_BUFFER_B          0x02
#define MODEL_BUFFER           0x03

//////////////////���ں�////////////////////////
#define COM1                   0x01
#define COM2                   0x02
#define COM3                   0x03

//////////////////������////////////////////////
#define BAUD_RATE_9600         0x00
#define BAUD_RATE_19200        0x01
#define BAUD_RATE_38400        0x02
#define BAUD_RATE_57600        0x03   //default
#define BAUD_RATE_115200       0x04

#ifdef _OT_CPP_
extern "C"
{
#endif
	BOOL WINAPI FPOpenDevice(int nDeviceType,int nPortNum,int nPortPara,int nPackageSize=2);
	BOOL WINAPI FPCloseDevice();
	///////////////////////////////////////////////
	//////             ָ��                  //////
	///////////////////////////////////////////////
	//�����ָ��¼ȡͼ��
	int WINAPI      FPGetImage(int nAddr);
	
	//����ԭʼͼ������ָ������
	int  WINAPI    FPGenChar(int nAddr,int iBufferID);
	
	//��ȷ�ȶ�CharBufferA��CharBufferB�е������ļ�
	int WINAPI     FPMatch(int nAddr,int* iScore);
	
	//��CharBufferA��CharBufferB�е������ļ����������򲿷�ָ�ƿ�
	int  WINAPI    FPSearch(int nAddr,int iBufferID, int iStartPage, int iPageNum, int *iMbAddress);
	
	//��CharBufferA��CharBufferB�е������ļ��ϲ�����ģ�����ModelBuffer
	int  WINAPI    FPRegModule(int nAddr);
	
	//��ModelBuffer�е��ļ����浽flashָ�ƿ���
	int  WINAPI    FPStoreChar(int nAddr,int iBufferID, int iPageID);
	
	//��flashָ�ƿ��ж�ȡһ��ģ�嵽ModelBuffer
	int  WINAPI     FPLoadChar(int nAddr,int iBufferID,int iPageID);
	
	//�������������е��ļ��ϴ�����λ��
	int WINAPI     FPUpChar(int nAddr,int iBufferID, unsigned char* pTemplet, int* iTempletLength);
	
	//����λ������һ�������ļ�������������
	int WINAPI     FPDownChar(int nAddr,int iBufferID, unsigned char* pTemplet, int iTempletLength);
	
	//�ϴ�ԭʼͼ��
	int WINAPI     FPUpImage(int nAddr,unsigned char* pImageData, int* iImageLength);
	
	//����ԭʼͼ��
	int WINAPI     FPDownImage(int nAddr,unsigned char *pImageData, int iLength);
	
	//�ϴ�ԭʼͼ��
	int  WINAPI     FPImgData2BMP(unsigned char* pImgData,const char* pImageFile);
	
	//����ԭʼͼ��
	
	int  WINAPI     FPGetImgDataFromBMP(const char *pImageFile,unsigned char *pImageData,int *pnImageLen);
	
	//ɾ��flashָ�ƿ��е�һ�������ļ�
	int WINAPI     FPDelChar(int nAddr,int iStartPageID,int nDelPageNum);
	
	//���flashָ�ƿ�
	int WINAPI     FPEmpty(int nAddr);
	
	//��������
	int WINAPI     FPReadParTable(int nAddr,unsigned char* pParTable);
	
	//����ָ��
	int WINAPI     FPPowerDown(int nAddr);
	
	//�����豸���ֿ���
	int WINAPI     FPSetPwd(int nAddr,unsigned char* pPassword);
	
	//��֤�豸���ֿ���
	int WINAPI     FPVfyPwd(int nAddr,unsigned char* pPassword);
	
	//ϵͳ��λ�������ϵ��ʼ״̬
	int WINAPI      FPReset(int nAddr);
		
	//�����±�
	int	WINAPI	    FPReadInfo(int nAddr,int nPage,unsigned char* UserContent);
	
	//д���±�
	int	WINAPI	    FPWriteInfo(int nAddr,int nPage,unsigned char* UserContent);
	
	//дģ��Ĵ���������������
	int  WINAPI     FPSetBaud(int nAddr,int nBaudNum);
	//дģ��Ĵ�������ȫ�ȼ�����
	int  WINAPI     FPSetSecurLevel(int nAddr,int nLevel);
	//дģ��Ĵ��������ݰ���С����
	int  WINAPI   FPSetPacketSize(int nAddr,int nSize);
	
	int  WINAPI    FPUpChar2File(int nAddr,int iBufferID, const char* pFileName);
	int  WINAPI     FPDownCharFromFile(int nAddr,int iBufferID, const char* pFileName);
	
	int  WINAPI FPGetRandomData(int nAddr,unsigned char* pRandom);
	int  WINAPI FPSetChipAddr(int nAddr,unsigned char* pChipAddr);
	
	int  WINAPI  FPDoUserDefine(int nAddr,int GPIO,int STATE);
	
	int  WINAPI  FPTemplateNum(int nAddr,int *iMbNum);

	//#define DEVICE_USB 0
	//#define DEVICE_COM 1
		
	//#define IMAGE_X 312
	//#define IMAGE_Y 230
	
	//���ݴ���Ż�ȡ������Ϣ
	char* WINAPI   FPErr2Str(int nErrCode);

#ifdef _OT_CPP_
}
#endif

#endif                                                     