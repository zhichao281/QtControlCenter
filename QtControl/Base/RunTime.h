/* $Copyright (c) 2006-2016 Green Net World
*
* Author	:	Maga  version 1.0
* DateTime	:	2016-7-8 9:39:22
*
* http://www.gwchina.cn/
*
* CRunTime  运行时缓存数据
*/




#ifndef CRunTime_H
#define CRunTime_H
#include "../include/HSingleton/HSingleton.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


enum WIDGET_TYPE
{
	MSGBOX_GET = 0x0001,
	MSGBOX_SAVE = 0x0002,
	MSGBOX_CLOSE = 0x0004,
	MSGBOX_BACK = 0x0008,
	MSGBOX_HOME = 0x00010,
	MSGBOX_OK = 0x00020,
	MSGBOX_RETURN = 0x00040
};

class QString;
/** 单例模式类 CRunTime */
class CRunTime
{
public:

	/** 默认构造函数（使用私有，不允许外部直接构造） */
	CRunTime();

public:

	/** 默认析构函数 */
	~CRunTime();

	// 清空
	void		Clear();
public:
    QString PortName;            //串口号
    int BaudRate;                //波特率
    int DataBit;                 //数据位
    QString Parity;				 //校验位
    double StopBit;              //停止位

    bool HexSend;                //16进制发送
    bool HexReceive;             //16进制接收

	QString com232_PortName;            //串口号
	int com232_BaudRate;                //波特率
	int com232_DataBit;                 //数据位
	QString com232_Parity;				 //校验位
	double com232_StopBit;              //停止位
	bool com232_HexSend;                //16进制发送
	bool com232_HexReceive;             //16进制接收

	QString com485_PortName;            //串口号
	int com485_BaudRate;                //波特率
	int com485_DataBit;                 //数据位
	QString com485_Parity;				 //校验位
	double com485_StopBit;              //停止位
	bool com485_HexSend;                //16进制发送
	bool com485_HexReceive;             //16进制接收


    bool Debug;                  //模拟设备
    bool AutoClear;              //自动清空

    bool AutoSend;               //自动发送
    int SendInterval;            //自动发送间隔
    bool AutoSave;               //自动保存
    int SaveInterval;            //自动保存间隔

    QString SendFileName;        //发送配置文件名
    QString DeviceFileName;      //模拟设备数据文件名

    QString Mode;                //转换模式
    QString ServerIP;            //服务器IP
	QString strComputerUrl;     //公司的网址
    int ServerPort;              //服务器端口
    int ListenPort;              //监听端口
    int SleepTime;               //延时时间
    bool AutoConnect;            //自动重连

    void ReadConfig();           //读取配置文件,在main函数最开始加载程序载入
    void WriteConfig();          //写入配置文件,在更改配置文件程序关闭时调用
    void NewConfig();            //以初始值新建配置文件
    bool CheckConfig();          //校验配置文件
    void WriteError(QString str);//写入错误信息
    void NewDir(QString dirName);//新建目录


	QString  Recevice_485;
	QString  Recevice_232;

	QString   strWeight;
	int  InputNum;
	WIDGET_TYPE  m_type;

};


#define gblRuntimeData HSingletonTemplatePtr<CRunTime>::get()

#endif // CRunTime_H
