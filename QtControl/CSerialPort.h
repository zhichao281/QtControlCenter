#pragma once
#pragma execution_character_set("utf-8")
#include <QObject>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include "define.h"
#include "include/HSingleton/HSingleton.h"
class CSerialPort : public QObject
{
	Q_OBJECT

public:
	CSerialPort(QObject *parent);


	~CSerialPort();
};


class CSerialPort_232 : public QObject
{
	Q_OBJECT

public:
	CSerialPort_232(QObject *parent);


	~CSerialPort_232();


	void InitSerial();			//初始化串口数据
	void InitQextSerial();			//初始化串口数据
signals: 
	void sig_ReadData(QString strData);

private slots:
	void readData();                //读取串口数据

	void QextreadData();                //读取串口数据

	void sendData(QString data);    //发送串口数据带参数

	void QextsendData(QString data);    //发送串口数据带参数
private:

	QextSerialPort * com;        //串口通信对象

	QSerialPort * m_serial;

	bool comOk;                 //串口是否打开
};


#define gbl232SerialPort HSingletonTemplatePtr<CSerialPort_232>::get() ;




class CSerialPort_485 : public QObject
{
	Q_OBJECT

public:
	CSerialPort_485(QObject *parent);


	~CSerialPort_485();


	void InitSerial();			//初始化串口数据

signals:
	void sig_ReadData(QString strData);

private slots:
	void readData();                //读取串口数据
	void sendData(QString data);    //发送串口数据带参数
private:
	QSerialPort * m_serial;
};


#define gbl232SerialPort HSingletonTemplatePtr<CSerialPort_485>::get();