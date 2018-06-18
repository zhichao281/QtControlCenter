#include "CSerialPort.h"

#include "Base/myhelper.h"
#include "Base/RunTime.h"


CSerialPort::CSerialPort(QObject *parent)
	: QObject(parent)
{
}

CSerialPort::~CSerialPort()
{
}

CSerialPort_232::CSerialPort_232(QObject *parent)
	: QObject(parent)
{
	gblRuntimeData->ReadConfig();
	timer = new QTimer(this);
	InitSerial();
}

CSerialPort_232::~CSerialPort_232()
{
}

void CSerialPort_232::InitSerial()
{
	com = new QextSerialPort(gblRuntimeData->com232_PortName, QextSerialPort::Polling);
	comOk = com->open(QIODevice::ReadWrite);
	if (comOk)
	{
		//清空缓冲区
		com->flush();
		//设置波特率
		com->setBaudRate((BaudRateType)BAUD9600);
		//设置数据位数  
		com->setDataBits((DataBitsType)DATA_8);
		//设置校验位
		com->setParity((ParityType)PAR_NONE);
		//设置停止位
		com->setStopBits((StopBitsType)STOP_1);

		com->setFlowControl(FLOW_OFF);

		com->setTimeout(5);
		connect(com, SIGNAL(readyRead()), this, SLOT(readData()));
		timer->start(10);
		QObject::connect(timer, SIGNAL(timeout()),
			this, SLOT(readData()));
	}
}


void CSerialPort_232::readData()
{
	int byteLen = com->bytesAvailable(); //返回串口缓冲区字节  
	if (byteLen <= 0) return;  //减小内存占用  

	QString buffer;
	QByteArray data = com->readAll();

	if (gblRuntimeData->com232_HexReceive)
	{

		buffer = myHelper::byteArrayToHexStr(data);

	}
	else
	{
		buffer = myHelper::byteArrayToAsciiStr(data);
	}
	if (buffer.isEmpty() == true)
	{
		return;
	}
	emit sig_ReadData(buffer);
	buffer.clear();
}



void CSerialPort_232::sendData(QString data)
{
	if (com == 0 || !com->isOpen()) {
		return;
	}

	QByteArray buffer;
	if (gblRuntimeData->com232_HexSend)
	{
		buffer = myHelper::hexStrToByteArray(data);
	}
	else
	{
		buffer = myHelper::asciiStrToByteArray(data);
	}
	com->write(buffer);
}




CSerialPort_485::CSerialPort_485(QObject *parent)
	: QObject(parent)
{
	gblRuntimeData->ReadConfig();
	timer = new QTimer(this);
	InitSerial();
}

CSerialPort_485::~CSerialPort_485()
{
}

void CSerialPort_485::InitSerial()
{
	//com = new QextSerialPort(gblRuntimeData->com485_PortName, QextSerialPort::Polling);
	com = new QextSerialPort("COM3", QextSerialPort::Polling);
	comOk = com->open(QIODevice::ReadWrite);
	if (comOk)
	{
		//清空缓冲区
		com->flush();
		//设置波特率
		com->setBaudRate((BaudRateType)BAUD9600);
		//设置数据位数  
		com->setDataBits((DataBitsType)DATA_8);	
		//设置校验位
		com->setParity((ParityType)PAR_NONE);
		//设置停止位
		com->setStopBits((StopBitsType)STOP_1);

		com->setFlowControl(FLOW_OFF);

		com->setTimeout(5);
		connect(com, SIGNAL(readyRead()), this, SLOT(readData()));
		timer->start(10);
		QObject::connect(timer, SIGNAL(timeout()),
			this, SLOT(readData()));
	}	
}


void CSerialPort_485::readData()
{
 	int byteLen = com->bytesAvailable(); //返回串口缓冲区字节  
	if (byteLen <= 0) return;  //减小内存占用  

	QString buffer;
	QByteArray data = com->readAll();

	if (gblRuntimeData->com485_HexReceive)
	{

		buffer = myHelper::byteArrayToHexStr(data);

	}
	else
	{
		buffer = myHelper::byteArrayToAsciiStr(data);
	}
	if (buffer.isEmpty() == true)
	{
		return;
	}
	emit sig_ReadData(buffer);
	gblRuntimeData->Recevice_485 = buffer;
	buffer.clear();
	com->flush();
}



void CSerialPort_485::sendData(QString data)
{
	if (com == 0 || !com->isOpen()) {
		return;
	}

	QByteArray buffer;

	if (gblRuntimeData->com485_HexSend)
	{
		buffer = myHelper::hexStrToByteArray(data);
	}
	else
	{
		buffer = myHelper::asciiStrToByteArray(data);
	}
	com->write(buffer);
	
}