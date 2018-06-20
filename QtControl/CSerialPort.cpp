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
	timer->setInterval(30);
	//设置定时器每个多少毫秒发送一个timeout()信号  
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(readData()));
	//启动定时器  

	InitSerial();
	m_bAlive = TRUE;
}

CSerialPort_485::~CSerialPort_485()
{
}

void CSerialPort_485::InitSerial()
{
	QString strComName = gblRuntimeData->com485_PortName;
	//com = new QextSerialPort(strComName, QextSerialPort::Polling);
	com = new QextSerialPort("COM2", QextSerialPort::Polling);
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

		com->setTimeout(10);
		//QObject::connect(com, SIGNAL(readyRead()), this, SLOT(readData()));
		if (timer->isActive() == false)
		{
			timer->start();
		}
	}	
}

void CSerialPort_485::close()
{
	com->close();
	delete com;
	com = 0;
	timer->stop();
}
void CSerialPort_485::readData()
{
	if (com == 0 || !com->isOpen())
	{
		return;
	}

 	int byteLen = com->bytesAvailable(); //返回串口缓冲区字节  
	if (byteLen <= 0) return;  //减小内存占用  

	QString buffer;
	QByteArray data = com->readAll();
	com->flush();
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

	//gblRuntimeData->Recevice_485 = buffer;
	emit sig_ReadData(buffer);
	LOG_INFO("readData =[%s]", buffer.toStdString().c_str());
	buffer.clear();
}


void CSerialPort_485::AddTask(QString strSend)
{
	m_QueyeMutex.lock();
	m_szSendQueue.enqueue(strSend);
	m_QueyeMutex.unlock();
	if (this->isRunning() == TRUE)
	{
		Thread_Wait.wakeAll();
	}
	else
	{
		this->start();
	}

}

void CSerialPort_485::run()
{
	while (m_bAlive)
	{
		m_QueyeMutex.lock();
		int nSize = m_szSendQueue.size();
		if (nSize > 0)
		{
			QString strSend = m_szSendQueue.dequeue();
			m_QueyeMutex.unlock();
			sendData(strSend);
			this->msleep(70);
			continue;
		}
		else
		{
			Thread_Wait.wait(&m_QueyeMutex);
			m_QueyeMutex.unlock();
		}
	}
}
void CSerialPort_485::sendData(QString strSendData)
{
	if (com == 0 || !com->isOpen()) 
	{
		return;
	}
	LOG_INFO("sendData =[%s]", strSendData.toStdString().c_str());
	QByteArray buffer;

	if (gblRuntimeData->com485_HexSend)
	{
		buffer = myHelper::hexStrToByteArray(strSendData);
	}
	else
	{
		buffer = myHelper::asciiStrToByteArray(strSendData);
	}
	com->write(buffer);
	com->flush();
}