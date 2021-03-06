#ifndef FRMCOMTOOL_H
#define FRMCOMTOOL_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QWidget>
#include <QSerialPort>  
#include <QSerialPortInfo>  

#include "ui_frmcomtool.h"
#include "define.h"



class frmComTool : public QWidget,public Ui::frmComTool
{
	Q_OBJECT

public:
	explicit frmComTool(QWidget *parent = 0);
	~frmComTool();

private slots:
	void initForm();                //初始化窗体数据
    void initConfig();              //初始化配置文件
    void saveConfig();              //保存配置文件
	void readData();                //读取串口数据
	void sendData();                //发送串口数据
	void sendData(QString data);    //发送串口数据带参数
	void saveData();                //保存串口数据

	void changeEnable(bool b);      //改变状态

	void append(quint8 type, QString msg);

	//void InitSerial();			//初始化串口数据

	void InitQextSerial();			//初始化串口数据
private slots:
 

private slots:
	void on_btnOpen_clicked();
	void on_btnStopShow_clicked();
	void on_btnSendCount_clicked();
	void on_btnReceiveCount_clicked();
    void on_btnClear_clicked();
	void on_btnData_clicked();

    void on_ckAutoSave_stateChanged(int arg1);

 

private:

	//QSerialPort * m_serial ;

	QSerialPortInfo* serialInfo;

	QList<QSerialPortInfo>serialList;

	QTimer *timerSave;          //定时保存串口数据
	bool comOk;                 //串口是否打开

	int maxCount;               //最大显示行数
	int currentCount;           //当前显示行数
	int sleepTime;              //接收延时时间
	int sendCount;              //发送数据计数
	int receiveCount;           //接收数据计数
	bool isShow;                //是否显示数据

	QStringList keys;           //模拟设备回复数据key
	QStringList values;         //模拟设备回复数据value


	QextSerialPort *com;        //串口通信对象
	QTimer *timer;  //用于声明定时器  
};

#endif // FRMCOMTOOL_H
