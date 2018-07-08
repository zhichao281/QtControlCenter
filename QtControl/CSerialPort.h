#pragma once
#pragma execution_character_set("utf-8")
#include <QObject>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include "define.h"
#include <QThread>
#include <QWaitCondition>
#include "include/HSingleton/HSingleton.h"

class CSerialPort_232 : public QObject, public QThread
{
	Q_OBJECT
public:
	CSerialPort_232(QObject *parent = nullptr);

	~CSerialPort_232();
public:
	void InitSerial();			//初始化串口数据
	void close();
public:
	void AddTask(QString strSend);

	virtual  void run();

	void StopThread();

	void  setReadState(bool bRead);

signals:
	void sig_ReadData(QString strData);

public slots:
	void readData();                //读取串口数据

private slots:
	void sendData(QString data);    //发送串口数据带参数

private:

	QextSerialPort * com;        //串口通信对象
	QTimer *timer;  //用于声明定时器  
	bool comOk;                 //串口是否打开
	QWaitCondition Thread_Wait;
private:
	QMutex m_QueyeMutex;
	QQueue<QString>	 m_szSendQueue;				//上传队列
	volatile bool m_bAlive;
public:
	bool   m_bRead;
};


#define gbl232SerialPort HSingletonTemplatePtr<CSerialPort_232>::get() 




class CSerialPort_485 : public QObject, public QThread
{
	Q_OBJECT

public:
	CSerialPort_485(QObject *parent =nullptr);

	~CSerialPort_485();

	void InitSerial();			//初始化串口数据


	void close();

public:
	void AddTask(QString strSend);

	virtual  void run();

	void StopThread();
signals:
	void sig_ReadData(QString strData);

public slots:
	void readData();                //读取串口数据

private slots:
	void sendData(QString data);    //发送串口数据带参数
private:

	QextSerialPort *com;        //串口通信对象
	QTimer *timer;  //用于声明定时器  
	bool comOk;                 //串口是否打开
	QWaitCondition Thread_Wait;
private:
	QMutex m_QueyeMutex;
	QQueue<QString>	 m_szSendQueue;				//上传队列
	volatile bool m_bAlive;

};


#define gbl485SerialPort HSingletonTemplatePtr<CSerialPort_485>::get()




class CHeightPort_485 : public QObject, public QThread
{
	Q_OBJECT

public:
	CHeightPort_485(QObject *parent = nullptr);

	~CHeightPort_485();

	void InitSerial();			//初始化串口数据


	void close();

public:
	void AddTask(QString strSend);

	virtual  void run();

	void StopThread();
signals:
	void sig_ReadData(QString strData);

public slots:
	void readData();                //读取串口数据

private slots:
	void sendData(QString data);    //发送串口数据带参数
private:

	QextSerialPort * com;        //串口通信对象
	QTimer *timer;  //用于声明定时器  
	bool comOk;                 //串口是否打开
	QWaitCondition Thread_Wait;
private:
	QMutex m_QueyeMutex;
	QQueue<QString>	 m_szSendQueue;				//上传队列
	volatile bool m_bAlive;

};


#define gbl485HeightPort HSingletonTemplatePtr<CHeightPort_485>::get()
