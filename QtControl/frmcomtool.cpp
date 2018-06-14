#include "frmcomtool.h"

#include "Base/myhelper.h"
#include "Base/RunTime.h"


frmComTool::frmComTool(QWidget *parent) :
	QWidget(parent)
{
	this->setupUi(this);
	this->initForm();
	this->initConfig();

	myHelper::formInCenter(this);
}

frmComTool::~frmComTool()
{

}

void frmComTool::initForm()
{
	this->setWindowTitle("串口调试助手");
	
	maxCount = 50;
	currentCount = 0;
	sleepTime = 10;
	receiveCount = 0;
	sendCount = 0;
	isShow = true;
	
	connect(this->btnSend, SIGNAL(clicked()), this, SLOT(sendData()));

	//保存数据
	timerSave = new QTimer(this);
	connect(timerSave, SIGNAL(timeout()), this, SLOT(saveData()));
	connect(this->btnSave, SIGNAL(clicked()), this, SLOT(saveData()));

	changeEnable(false);

}

void frmComTool::initConfig()
{
	gblRuntimeData->ReadConfig();


	//查找可用的串口 
	serialInfo = new QSerialPortInfo();
	serialList = serialInfo->availablePorts();
	int nSerialnum = serialList.length();
	for (int i = 0; i < nSerialnum; i++)
	{
		QString serialName = serialList[i].portName();
		QString serialDesp = serialList[i].description();
		QSerialPort serial;
		serial.setPort(serialList[i]);
		if (serial.open(QIODevice::ReadWrite))
		{
			cboxPortName->addItem(serialName);
			serial.close();
		}
	}
 
	this->cboxPortName->setCurrentIndex(this->cboxPortName->findText(gblRuntimeData->PortName));
	connect(this->cboxPortName, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

	QStringList baudList;
	baudList << "50" << "75" << "100" << "134" << "150" << "200" << "300" << "600" << "1200"
	         << "1800" << "2400" << "4800" << "9600" << "14400" << "19200" << "38400"
	         << "56000" << "57600" << "76800" << "115200" << "128000" << "256000";

	this->cboxBaudRate->addItems(baudList);
	this->cboxBaudRate->setCurrentIndex(this->cboxBaudRate->findText(QString::number(gblRuntimeData->BaudRate)));
	connect(this->cboxBaudRate, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

	QStringList dataBitsList;
	dataBitsList << "5" << "6" << "7" << "8";

	this->cboxDataBit->addItems(dataBitsList);
	this->cboxDataBit->setCurrentIndex(this->cboxDataBit->findText(QString::number(gblRuntimeData->DataBit)));
	connect(this->cboxDataBit, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

	QStringList parityList;
	parityList << "无" << "奇" << "偶";
#ifdef Q_OS_WIN
	parityList << "标志";
#endif
	parityList << "空格";

	this->cboxParity->addItems(parityList);
	this->cboxParity->setCurrentIndex(this->cboxParity->findText(gblRuntimeData->Parity));
	connect(this->cboxParity, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

	QStringList stopBitsList;
	stopBitsList << "1";
#ifdef Q_OS_WIN
	stopBitsList << "1.5";
#endif
	stopBitsList << "2";

	this->cboxStopBit->addItems(stopBitsList);
	this->cboxStopBit->setCurrentIndex(this->cboxStopBit->findText(QString::number(gblRuntimeData->StopBit)));
	connect(this->cboxStopBit, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

	this->ckHexSend->setChecked(gblRuntimeData->HexSend);
	connect(this->ckHexSend, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	this->ckHexReceive->setChecked(gblRuntimeData->HexReceive);
	connect(this->ckHexReceive, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	this->ckDebug->setChecked(gblRuntimeData->Debug);
	connect(this->ckDebug, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	this->ckAutoClear->setChecked(gblRuntimeData->AutoClear);
	connect(this->ckAutoClear, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	this->ckAutoSend->setChecked(gblRuntimeData->AutoSend);
	connect(this->ckAutoSend, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	this->ckAutoSave->setChecked(gblRuntimeData->AutoSave);
	connect(this->ckAutoSave, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

	QStringList sendInterval;
	QStringList saveInterval;
	sendInterval << "100" << "300" << "500";

	for (int i = 1000; i <= 10000; i = i + 1000) {
		sendInterval << QString::number(i);
		saveInterval << QString::number(i);
	}

	this->cboxSendInterval->addItems(sendInterval);
	this->cboxSaveInterval->addItems(saveInterval);

	this->cboxSendInterval->setCurrentIndex(this->cboxSendInterval->findText(QString::number(gblRuntimeData->SendInterval)));
	connect(this->cboxSendInterval, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));
	this->cboxSaveInterval->setCurrentIndex(this->cboxSaveInterval->findText(QString::number(gblRuntimeData->SaveInterval)));
	connect(this->cboxSaveInterval, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));


}

void frmComTool::saveConfig()
{
	gblRuntimeData->PortName = this->cboxPortName->currentText();
	gblRuntimeData->BaudRate = this->cboxBaudRate->currentText().toInt();
	gblRuntimeData->DataBit = this->cboxDataBit->currentText().toInt();
	gblRuntimeData->Parity = this->cboxParity->currentText();
	gblRuntimeData->StopBit = this->cboxStopBit->currentText().toDouble();

	gblRuntimeData->HexSend = this->ckHexSend->isChecked();
	gblRuntimeData->HexReceive = this->ckHexReceive->isChecked();
	gblRuntimeData->Debug = this->ckDebug->isChecked();
	gblRuntimeData->AutoClear = this->ckAutoClear->isChecked();

	gblRuntimeData->AutoSend = this->ckAutoSend->isChecked();
	gblRuntimeData->AutoSave = this->ckAutoSave->isChecked();

	int sendInterval = this->cboxSendInterval->currentText().toInt();

	if (sendInterval != gblRuntimeData->SendInterval) {
		gblRuntimeData->SendInterval = sendInterval;
	
	}

	int saveInterval = this->cboxSaveInterval->currentText().toInt();

	if (saveInterval != gblRuntimeData->SaveInterval) {
		gblRuntimeData->SaveInterval = saveInterval;
		timerSave->setInterval(gblRuntimeData->SaveInterval);
	}

	gblRuntimeData->Mode = this->cboxMode->currentText();
	gblRuntimeData->ServerIP = this->txtServerIP->text().trimmed();
	gblRuntimeData->ServerPort = this->txtServerPort->text().toInt();
	gblRuntimeData->ListenPort = this->txtListenPort->text().toInt();
	gblRuntimeData->SleepTime = this->cboxSleepTime->currentText().toInt();
	gblRuntimeData->AutoConnect = this->ckAutoConnect->isChecked();

	gblRuntimeData->WriteConfig();
}

void frmComTool::changeEnable(bool bOpen)
{
	this->cboxBaudRate->setEnabled(!bOpen);
	this->cboxDataBit->setEnabled(!bOpen);
	this->cboxParity->setEnabled(!bOpen);
	this->cboxPortName->setEnabled(!bOpen);
	this->cboxStopBit->setEnabled(!bOpen);
	this->btnSend->setEnabled(bOpen);
	this->ckAutoSend->setEnabled(bOpen);
	this->ckAutoSave->setEnabled(bOpen);
}

void frmComTool::append(quint8 type, QString msg)
{
	if (!isShow) {
		return;
	}

	if (currentCount >= maxCount) {
		this->txtMain->clear();
		currentCount = 0;
	}

	QString str;

	if (type == 0) {
		str = ">> 串口发送 :";
		this->txtMain->setTextColor(QColor("dodgerblue"));
	} else if (type == 1) {
		str = "<< 串口接收 :";
		this->txtMain->setTextColor(QColor("red"));
	} else if (type == 2) {
		str = ">> 处理延时 :";
		this->txtMain->setTextColor(QColor("gray"));
	} else if (type == 3) {
		str = ">> 正在校验 :";
		this->txtMain->setTextColor(QColor("green"));
	} else if (type == 4) {
		str = ">> 网络发送 :";
		this->txtMain->setTextColor(QColor(24, 189, 155));
	} else if (type == 5) {
		str = "<< 网络接收 :";
		this->txtMain->setTextColor(QColor(255, 107, 107));
	} else if (type == 6) {
		str = ">> 提示信息 :";
		this->txtMain->setTextColor(QColor(100, 184, 255));
	}

	this->txtMain->append(QString("时间[%1] %2 %3").arg(TIMEMS).arg(str).arg(msg));
	currentCount++;
}

//void frmComTool::InitSerial()
//{
//	//设置串口名  
//	m_serial = new QSerialPort;
//	//设置串口名  
//	m_serial->setPortName(cboxPortName->currentText());
//	//打开串口  
//	bool bOpen=m_serial->open(QIODevice::ReadWrite);
//	if (!bOpen)
//	{
//		return;
//	}
//	//设置波特率  
//	m_serial->setBaudRate(cboxBaudRate->currentText().toInt());
//	//设置数据位数  
//	switch (cboxDataBit->currentText().toInt())
//	{
//		case 5:
//			m_serial->setDataBits(QSerialPort::Data5);
//			break;
//		case 6:
//			m_serial->setDataBits(QSerialPort::Data6);
//			break;
//		case 7:
//			m_serial->setDataBits(QSerialPort::Data7);
//			break;
//		case 8:
//			m_serial->setDataBits(QSerialPort::Data8);
//			break;
//		default:
//			m_serial->setDataBits(QSerialPort::UnknownDataBits);
//			break;
//	}
//	//设置奇偶校验  
//	if (cboxParity->currentText() == "无")
//	{
//		m_serial->setParity(QSerialPort::NoParity); 
//	}
//	if (cboxParity->currentText() == "奇")
//	{
//		m_serial->setParity(QSerialPort::OddParity); 
//	}
//	if (cboxParity->currentText() == "偶")
//	{
//		m_serial->setParity(QSerialPort::EvenParity); 
//	}	
//	if (cboxParity->currentText() == "标志")
//	{
//		m_serial->setParity(QSerialPort::MarkParity);
//	}
//	if (cboxParity->currentText() == "空格")
//	{
//		m_serial->setParity(QSerialPort::SpaceParity);
//	}
//
//	//设置停止位  
//	switch (cboxStopBit->currentText().toInt())
//	{
//		case 10: m_serial->setStopBits(QSerialPort::OneStop); break;
//		case 15: m_serial->setStopBits(QSerialPort::OneAndHalfStop); break;
//		case 20: m_serial->setStopBits(QSerialPort::TwoStop); break;
//		default: break;
//	}
//	//设置流控制  
//	m_serial->setFlowControl(QSerialPort::NoFlowControl);
//	//连接信号槽  
//	QObject::connect(m_serial, &QSerialPort::readyRead, this, &frmComTool::readData);
//}

void frmComTool::readData()
{

	QString buffer;
	QByteArray data = com->readAll();

	if (ckHexReceive->isChecked()) 
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
	append(1, buffer);
	receiveCount = receiveCount + data.size();
	btnReceiveCount->setText(QString("接收 : %1 字节").arg(receiveCount));
	buffer.clear();
}

void frmComTool::sendData()
{
	QString str = this->cboxSend->currentText();

	if (str.isEmpty()) {
		this->cboxSend->setFocus();
		return;
	}

	sendData(str);

	if (this->ckAutoClear->isChecked()) 
	{
		this->cboxSend->setCurrentIndex(-1);
		this->cboxSend->setFocus();
	}
}

void frmComTool::sendData(QString data)
{

	if (com == 0 || !com->isOpen()) {
		return;
	}
	
	QByteArray buffer;

	if (ckHexSend->isChecked())
	{
		buffer = myHelper::hexStrToByteArray(data);
	}
	else
	{
		buffer = myHelper::asciiStrToByteArray(data);
	}
	append(0, data);
	sendCount = sendCount + buffer.size();
	btnSendCount->setText(QString("发送 : %1 字节").arg(sendCount));

	com->write(buffer);
}

void frmComTool::saveData()
{
	QString tempData = this->txtMain->toPlainText();

	if (tempData == "") {
		return;
	}

	QDateTime now = QDateTime::currentDateTime();
	QString name = now.toString("yyyy-MM-dd-HH-mm-ss");
	QString fileName = QString("%1/%2.txt").arg(AppPath).arg(name);

	QFile file(fileName);
	file.open(QFile::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	out << tempData;
	file.close();

	currentCount = 0;
	this->txtMain->clear();
}

void frmComTool::on_btnOpen_clicked()
{
	
	if (btnOpen->text() == "打开串口")
	{
		com = new QextSerialPort(cboxPortName->currentText(), QextSerialPort::EventDriven);
		comOk = com->open(QIODevice::ReadWrite);
		if (comOk)
		{
			//清空缓冲区
			com->flush();
			//设置波特率
			com->setBaudRate((BaudRateType)cboxBaudRate->currentText().toInt());
			//设置数据位
			com->setDataBits((DataBitsType)cboxDataBit->currentText().toInt());
			//设置校验位
			com->setParity((ParityType)cboxParity->currentIndex());
			//设置停止位
			com->setStopBits((StopBitsType)cboxStopBit->currentIndex());
			com->setFlowControl(FLOW_OFF);
			com->setTimeout(10);
			connect(com, SIGNAL(readyRead()), this, SLOT(readData()));
			changeEnable(true);
			btnOpen->setText("关闭串口");

		}
	}
	else 
	{

		com->close();
		changeEnable(false);
		btnOpen->setText("打开串口");
		on_btnClear_clicked();
		comOk = false;
	}
}

void frmComTool::on_btnSendCount_clicked()
{
	sendCount = 0;
	this->btnSendCount->setText("发送 : 0 字节");
}

void frmComTool::on_btnReceiveCount_clicked()
{
	receiveCount = 0;
	this->btnReceiveCount->setText("接收 : 0 字节");
}

void frmComTool::on_btnStopShow_clicked()
{
	if (this->btnStopShow->text() == "停止显示") {
		isShow = false;
		this->btnStopShow->setText("开始显示");
	} else {
		isShow = true;
		this->btnStopShow->setText("停止显示");
	}
}

void frmComTool::on_btnData_clicked()
{
	QString fileName = QString("%1/%2").arg(AppPath).arg("send.txt");
	QFile file(fileName);

	if (!file.exists()) {
		return;
	}

	if (this->btnData->text() == "管理数据") {
		this->txtMain->setReadOnly(false);
		this->txtMain->clear();
		file.open(QFile::ReadOnly | QIODevice::Text);
		QTextStream in(&file);
		this->txtMain->setText(in.readAll());
		file.close();
		this->btnData->setText("保存数据");
	} else {
		this->txtMain->setReadOnly(true);
		file.open(QFile::WriteOnly | QIODevice::Text);
		QTextStream out(&file);
		out << this->txtMain->toPlainText();
		file.close();
		this->txtMain->clear();
		this->btnData->setText("管理数据");
	
	}
}

void frmComTool::on_btnClear_clicked()
{
	this->txtMain->clear();
	currentCount = 0;
}

void frmComTool::InitQextSerial()			//初始化串口数据
{
	

}

void frmComTool::on_ckAutoSave_stateChanged(int arg1)
{
	if (arg1 == 0) {
		this->cboxSaveInterval->setEnabled(false);
		timerSave->stop();
	} else {
		this->cboxSaveInterval->setEnabled(true);
		timerSave->start();
	}
}
