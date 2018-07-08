#include "CSerialPort.h"

#include "Base/myhelper.h"
#include "Base/RunTime.h"


CSerialPort_232::CSerialPort_232(QObject *parent)
	: QObject(parent)
{
	gblRuntimeData->ReadConfig();

	timer = new QTimer(this);
	timer->setInterval(25);
	//设置定时器每个多少毫秒发送一个timeout()信号  
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(readData()));
	//启动定时器  

	InitSerial();
	m_bAlive = TRUE;
	m_bRead = false;
}

CSerialPort_232::~CSerialPort_232()
{
}

void CSerialPort_232::InitSerial()
{
	QString strComName = gblRuntimeData->com232_PortName;
	gblRuntimeData->Recevice_232.clear();
	//com = new QextSerialPort(strComName, QextSerialPort::Polling);
	com = new QextSerialPort("COM1", QextSerialPort::Polling);
	comOk = com->open(QIODevice::ReadWrite);
	if (comOk)
	{
		gblRuntimeData->Recevice_232.clear();
		//清空缓冲区
		com->flush();
		//设置波特率
		com->setBaudRate((BaudRateType)BAUD19200);
		//设置数据位数  
		com->setDataBits((DataBitsType)DATA_8);
		//设置校验位
		com->setParity((ParityType)PAR_NONE);
		//设置停止位
		com->setStopBits((StopBitsType)STOP_1);

		com->setFlowControl(FLOW_OFF);

		com->setTimeout(10);

		if (timer->isActive() == false)
		{
			timer->start();
		}
	}
}

void CSerialPort_232::close()
{
	if (com != 0 || com->isOpen() == true)
	{
		m_szSendQueue.clear();
		com->close();
		delete com;
		com = 0;
		timer->stop();
	}
}
void  CSerialPort_232::setReadState(bool bRead)
{
	m_bRead = bRead;
	if (m_bRead)
	{
		if (timer->isActive() == false)
		{
			timer->start();
		}
	}
	else
	{
		if (timer->isActive() == true)
		{
			timer->stop();
		}
	}

}
void CSerialPort_232::readData()
{
	if (com == 0 || !com->isOpen() || m_bRead == false)
	{
		return;
	}

	int byteLen = com->bytesAvailable(); //返回串口缓冲区字节  
	if (byteLen <= 0) return;  //减小内存占用  

	QString buffer;
	QByteArray data = com->readAll();
	com->flush();
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
	
	if (gblRuntimeData->Recevice_232.length() < 1)
	{
		gblRuntimeData->Recevice_232 = gblRuntimeData->Recevice_232 + buffer;
	}
	else
	{
		gblRuntimeData->Recevice_232 = gblRuntimeData->Recevice_232  + buffer;
	}
	if (gblRuntimeData->Recevice_232.indexOf("0D") != -1)
	{
		QString strRead = gblRuntimeData->Recevice_232.section("0D", 0, 0);
		if (strRead.length() > 0)
		{
			strRead = strRead + "0D";
			gblRuntimeData->Recevice_232 = gblRuntimeData->Recevice_232.section("0D", 1);
			emit sig_ReadData(strRead);
			return;
		}
	}	
	//LOG_INFO("232readData =[%s]", buffer.toStdString().c_str());
	buffer.clear();
}


void CSerialPort_232::AddTask(QString strSend)
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

void CSerialPort_232::run()
{
	while (m_bAlive)
	{
		m_QueyeMutex.lock();
		int nSize = m_szSendQueue.size();
		if (nSize > 0)
		{
			QString strSend = m_szSendQueue.dequeue();
			m_QueyeMutex.unlock();
			this->msleep(50);
			sendData(strSend);
			continue;
		}
		else
		{
			Thread_Wait.wait(&m_QueyeMutex);
			m_QueyeMutex.unlock();
		}
	}
}
void CSerialPort_232::sendData(QString strSendData)
{
	if (com == 0 || !com->isOpen())
	{
		return;
	}
	LOG_INFO("232sendData =[%s]", strSendData.toStdString().c_str());
	QByteArray buffer;

	if (gblRuntimeData->com232_HexSend)
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



CSerialPort_485::CSerialPort_485(QObject *parent)
	: QObject(parent)
{
	gblRuntimeData->ReadConfig();

	timer = new QTimer(this);
	timer->setInterval(25);
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
	gblRuntimeData->Recevice_485.clear();
	//com = new QextSerialPort(strComName, QextSerialPort::Polling);
	com = new QextSerialPort("COM2", QextSerialPort::Polling);
	comOk = com->open(QIODevice::ReadWrite);
	if (comOk)
	{
		gblRuntimeData->Recevice_485.clear();
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

		if (timer->isActive() == false)
		{
			timer->start();
		}
		
	}	
}

void CSerialPort_485::close()
{
	if (com != 0 || com->isOpen() == true)
	{
		m_szSendQueue.clear();
		com->close();
		delete com;
		com = 0;
		timer->stop();
	}
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
	if (gblRuntimeData->Recevice_485.length()<1)
	{
		gblRuntimeData->Recevice_485 = gblRuntimeData->Recevice_485 +buffer;
	}
	else
	{
		gblRuntimeData->Recevice_485 = gblRuntimeData->Recevice_485 +" "+ buffer;
	}
	if (gblRuntimeData->Recevice_485.indexOf("0D 0A")!=-1)
	{
		QString strRead = gblRuntimeData->Recevice_485.section("0D 0A", 0, 0);
		if (strRead.length() > 0)
		{
			strRead = strRead + "0D 0A";
			gblRuntimeData->Recevice_485 = gblRuntimeData->Recevice_485.section("0D 0A", 1);
			emit sig_ReadData(strRead);
			return;
		}

	}
	else if (gblRuntimeData->Recevice_485.indexOf("0D0A") != -1)
	{
		QString strRead = gblRuntimeData->Recevice_485.section("0D0A", 0, 0);
		if (strRead.length() > 0)
		{
			strRead = strRead + "0D0A";
			gblRuntimeData->Recevice_485 = gblRuntimeData->Recevice_485.section("0D0A", 1);
			emit sig_ReadData(strRead);
			return;
		}
	}
	
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
			this->msleep(50);
			sendData(strSend);		
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

CHeightPort_485::CHeightPort_485(QObject *parent)
	: QObject(parent)
{
	gblRuntimeData->ReadConfig();

	timer = new QTimer(this);
	timer->setInterval(25);
	//设置定时器每个多少毫秒发送一个timeout()信号  
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(readData()));
	//启动定时器  

	InitSerial();
	m_bAlive = TRUE;
}

CHeightPort_485::~CHeightPort_485()
{
}

void CHeightPort_485::InitSerial()
{
	com = new QextSerialPort("COM5", QextSerialPort::Polling);
	comOk = com->open(QIODevice::ReadWrite);
	if (comOk)
	{
		gblRuntimeData->Recevice_Height.clear();
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

		if (timer->isActive() == false)
		{
			timer->start();
		}

	}
}

void CHeightPort_485::close()
{
	if (com != 0 || com->isOpen() == true)
	{
		m_szSendQueue.clear();
		com->close();
		delete com;
		com = 0;
		timer->stop();
	}
}

void CHeightPort_485::readData()
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
	if (true)
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

	gblRuntimeData->Recevice_Height = gblRuntimeData->Recevice_Height + buffer;

	if (gblRuntimeData->Recevice_Height.indexOf("01 03 04") != -1 && gblRuntimeData->Recevice_Height.length()>24)
	{
		int nIndex = gblRuntimeData->Recevice_Height.indexOf("01 03 04");
		QString strRead = gblRuntimeData->Recevice_Height.mid(nIndex, 26);
		if (strRead.length() == 26 )
		{
			emit sig_ReadData(strRead);			
			gblRuntimeData->Recevice_Height.replace(strRead, "");
			return;
		}

	}
	

	LOG_INFO("readData =[%s]", buffer.toStdString().c_str());
	buffer.clear();
}

void CHeightPort_485::AddTask(QString strSend)
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

void CHeightPort_485::run()
{
	while (m_bAlive)
	{
		this->msleep(50);
		m_QueyeMutex.lock();
		int nSize = m_szSendQueue.size();
		if (nSize > 0)
		{
			QString strSend = m_szSendQueue.dequeue();
			m_QueyeMutex.unlock();			
			sendData(strSend);
			continue;
		}
		else
		{
			Thread_Wait.wait(&m_QueyeMutex);
			m_QueyeMutex.unlock();
		}
	}
}

void CHeightPort_485::sendData(QString strSendData)
{
	if (com == 0 || !com->isOpen())
	{
		return;
	}
	LOG_INFO("sendData =[%s]", strSendData.toStdString().c_str());
	QByteArray buffer;

	if (true)
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