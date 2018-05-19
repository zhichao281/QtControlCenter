//#include "SerialPortSetting.h"
//
//
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
//#include <QDebug>
//#include <QMessageBox>
//#include <QStatusBar>
//#include <QPushButton>
//#include <QByteArray>
//#include <QDataStream>
//#include <QTimer>
//#include <QRegExp>
//#include <QRegExpValidator>
//#include <QFile>
//#include <QFileDialog>
//#include <QDragEnterEvent>
//#include <QDropEvent>
//#include <QMimeData>
//#include <QAction>
//
//
//SerialPortSetting::SerialPortSetting(QWidget *parent)
//	: QWidget(parent)
//{
//	this->setupUi(this);
//	setFixedSize(1074, 627);
//	receiveTextBrowser->setAcceptDrops(false);//缺省情况下，QTextEdit接受来自其他应用程序拖拽来的文本，把文件名显示出来。
//	senderTextEdit_1->setAcceptDrops(false);
//	senderTextEdit_2->setAcceptDrops(false);
//	senderTextEdit_3->setAcceptDrops(false);
//	senderTextEdit_4->setAcceptDrops(false);
//	senderTextEdit_5->setAcceptDrops(false);
//	setAcceptDrops(true);//通过禁止QTextEdit控件的drop事件，允许主窗口得到drop事件
//
//	connectButton->setIcon(QIcon(":/images/open.png"));
//	cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
//	checkAPButton->setIcon(QIcon(":/images/find.png"));
//	resetCntButton->setIcon(QIcon(":/images/to_zero.png"));
//	exitButton->setIcon(QIcon(":/images/exit.png"));
//	actionWrite_data->setIcon(QIcon(":/images/write.png"));
//	actionRead_data->setIcon(QIcon(":/images/read.png"));
//	actionChoose_file->setIcon(QIcon(":/images/select_file.png"));
//	exitAction->setIcon(QIcon(":/images/exit.png"));
//	actionAbout->setIcon(QIcon(":/images/about.png"));
//	sendButton_1->setIcon(QIcon(":/images/send.png"));
//	sendButton_2->setIcon(QIcon(":/images/send.png"));
//	sendButton_3->setIcon(QIcon(":/images/send.png"));
//	sendButton_4->setIcon(QIcon(":/images/send.png"));
//	sendButton_5->setIcon(QIcon(":/images/send.png"));
//
//	setConnections();
//	emit checkAvailablePorts();
//
//	Timer_CP = new QTimer(this);
//	Timer_UPDATE = new QTimer(this);
//	connect(Timer_UPDATE, SIGNAL(timeout()), this, SLOT(repaint()));
//	Timer_UPDATE->start(2000);
//	Timer_AS = new QTimer(this);
//}
//
//SerialPortSetting::~SerialPortSetting()
//{
//}
//void SerialPortSetting::checkAutoSendCB()
//{
//	QObject *signalSender = sender();
//	if (signalSender->objectName() == "autoSendCB_1")
//	{
//		if (autoSendCB_1->isChecked())
//		{
//			intervalSB_1->setEnabled(false);
//			autoSendCB_2->setEnabled(false);
//			autoSendCB_3->setEnabled(false);
//			autoSendCB_4->setEnabled(false);
//			autoSendCB_5->setEnabled(false);
//			startAutoSend(sendButton_1);
//		}
//		else if (!autoSendCB_1->isChecked()) {
//			Timer_AS->stop();
//			Timer_AS->disconnect();
//			intervalSB_1->setEnabled(true);
//			autoSendCB_2->setEnabled(true);
//			autoSendCB_3->setEnabled(true);
//			autoSendCB_4->setEnabled(true);
//			autoSendCB_5->setEnabled(true);
//			enabledSendButton();
//		}
//	}
//	else if (signalSender->objectName() == "autoSendCB_2") {
//		if (autoSendCB_2->isChecked())
//		{
//			intervalSB_2->setEnabled(false);
//			autoSendCB_1->setEnabled(false);
//			autoSendCB_3->setEnabled(false);
//			autoSendCB_4->setEnabled(false);
//			autoSendCB_5->setEnabled(false);
//			startAutoSend(sendButton_2);
//		}
//		else if (!autoSendCB_2->isChecked()) {
//			Timer_AS->stop();
//			Timer_AS->disconnect();
//			intervalSB_2->setEnabled(true);
//			autoSendCB_1->setEnabled(true);
//			autoSendCB_3->setEnabled(true);
//			autoSendCB_4->setEnabled(true);
//			autoSendCB_5->setEnabled(true);
//			enabledSendButton();
//		}
//	}
//	else if (signalSender->objectName() == "autoSendCB_3") {
//		if (autoSendCB_3->isChecked())
//		{
//			intervalSB_3->setEnabled(false);
//			autoSendCB_1->setEnabled(false);
//			autoSendCB_2->setEnabled(false);
//			autoSendCB_4->setEnabled(false);
//			autoSendCB_5->setEnabled(false);
//			startAutoSend(sendButton_3);
//		}
//		else if (!autoSendCB_3->isChecked()) {
//			Timer_AS->stop();
//			Timer_AS->disconnect();
//			intervalSB_3->setEnabled(true);
//			autoSendCB_1->setEnabled(true);
//			autoSendCB_2->setEnabled(true);
//			autoSendCB_4->setEnabled(true);
//			autoSendCB_5->setEnabled(true);
//			enabledSendButton();
//		}
//	}
//	else if (signalSender->objectName() == "autoSendCB_4") {
//		if (autoSendCB_4->isChecked())
//		{
//			intervalSB_4->setEnabled(false);
//			autoSendCB_1->setEnabled(false);
//			autoSendCB_2->setEnabled(false);
//			autoSendCB_3->setEnabled(false);
//			autoSendCB_5->setEnabled(false);
//			startAutoSend(sendButton_4);
//		}
//		else if (!autoSendCB_4->isChecked()) {
//			Timer_AS->stop();
//			Timer_AS->disconnect();
//			intervalSB_4->setEnabled(true);
//			autoSendCB_1->setEnabled(true);
//			autoSendCB_2->setEnabled(true);
//			autoSendCB_3->setEnabled(true);
//			autoSendCB_5->setEnabled(true);
//			enabledSendButton();
//		}
//	}
//	else if (signalSender->objectName() == "autoSendCB_5") {
//		if (autoSendCB_5->isChecked())
//		{
//			intervalSB_5->setEnabled(false);
//			autoSendCB_1->setEnabled(false);
//			autoSendCB_2->setEnabled(false);
//			autoSendCB_3->setEnabled(false);
//			autoSendCB_4->setEnabled(false);
//			startAutoSend(sendButton_5);
//		}
//		else if (!autoSendCB_5->isChecked()) {
//			Timer_AS->stop();
//			Timer_AS->disconnect();
//			intervalSB_5->setEnabled(true);
//			autoSendCB_1->setEnabled(true);
//			autoSendCB_2->setEnabled(true);
//			autoSendCB_3->setEnabled(true);
//			autoSendCB_4->setEnabled(true);
//			enabledSendButton();
//		}
//	}
//}
//
////清除接收区的内容
//void SerialPortSetting::on_cleanButton_clicked()
//{
//	if (trashFlag == true) {
//		receiveTextBrowser->clear();
//		cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
//	}
//}
//
//void SerialPortSetting::on_receiveTextBrowser_textChanged()
//{
//	QString tempStr = receiveTextBrowser->toPlainText();
//	if (!tempStr.isEmpty()) {
//		trashFlag = true;
//		if (autoClean->isChecked()) {
//			if (tempStr.size() > 6200) {
//				receiveTextBrowser->clear();
//				cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
//			}
//		}
//		else {
//			cleanButton->setIcon(QIcon(":/images/clean.png"));
//		}
//	}
//	else {
//		trashFlag = false;
//		cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
//	}
//}
//
//
//void SerialPortSetting::setBaudRate()
//{
//	if (portIsOpen) {
//		if (BAUDCB->currentText() == "115200")
//			mySerialPort->setBaudRate(QSerialPort::Baud115200);
//		else if (BAUDCB->currentText() == "9600")
//			mySerialPort->setBaudRate(QSerialPort::Baud9600);
//		else if (BAUDCB->currentText() == "1200")
//			mySerialPort->setBaudRate(QSerialPort::Baud1200);
//		else if (BAUDCB->currentText() == "2400")
//			mySerialPort->setBaudRate(QSerialPort::Baud2400);
//		else if (BAUDCB->currentText() == "4800")
//			mySerialPort->setBaudRate(QSerialPort::Baud4800);
//		else if (BAUDCB->currentText() == "19200")
//			mySerialPort->setBaudRate(QSerialPort::Baud19200);
//		else if (BAUDCB->currentText() == "38400")
//			mySerialPort->setBaudRate(QSerialPort::Baud38400);
//		else if (BAUDCB->currentText() == "57600")
//			mySerialPort->setBaudRate(QSerialPort::Baud57600);
//		emit setBaudLabel();
//		if (BaudCnt) {
//			statusBar()->showMessage("BaudRate set successfully", 2000);
//		}
//		++BaudCnt;
//	}
//}
//
//void SerialPortSetting::setParity()
//{
//	if (portIsOpen) {
//		if (ParityCB->currentText() == QString::fromLocal8Bit("无校验"))
//			mySerialPort->setParity(QSerialPort::NoParity);
//		else if (ParityCB->currentText() == QString::fromLocal8Bit("奇校验"))
//			mySerialPort->setParity(QSerialPort::OddParity);
//		else if (ParityCB->currentText() == QString::fromLocal8Bit("偶校验"))
//			mySerialPort->setParity(QSerialPort::EvenParity);
//		if (ParityCnt) {
//			statusBar()->showMessage("Parity set successfully", 2000);
//		}
//		++ParityCnt;
//	}
//}
//
//void SerialPortSetting::setDataBits()
//{
//	if (portIsOpen) {
//		if (DataBitsCB->currentText() == "8")
//			mySerialPort->setDataBits(QSerialPort::Data8);
//		else if (DataBitsCB->currentText() == "7")
//			mySerialPort->setDataBits(QSerialPort::Data7);
//		else if (DataBitsCB->currentText() == "6")
//			mySerialPort->setDataBits(QSerialPort::Data6);
//		else if (DataBitsCB->currentText() == "5")
//			mySerialPort->setDataBits(QSerialPort::Data5);
//		if (DataBitsCnt) {
//			statusBar()->showMessage("DataBits set successfully", 2000);
//		}
//		++DataBitsCnt;
//	}
//}
//
//void SerialPortSetting::setStopBits()
//{
//	if (portIsOpen) {
//		if (StopBitsCB->currentText() == "1")
//			mySerialPort->setStopBits(QSerialPort::OneStop);
//		else if (StopBitsCB->currentText() == "1.5")
//			mySerialPort->setStopBits(QSerialPort::OneAndHalfStop);
//		else if (StopBitsCB->currentText() == "2")
//			mySerialPort->setStopBits(QSerialPort::TwoStop);
//		if (StopBitsCnt) {
//			statusBar()->showMessage("StopBits set successfully", 2000);
//		}
//		++StopBitsCnt;
//	}
//}
//
//void SerialPortSetting::setFlowCtrl()
//{
//	if (portIsOpen) {
//		if (FlowCtrlCB->currentText() == "off")
//			mySerialPort->setFlowControl(QSerialPort::NoFlowControl);
//		else if (FlowCtrlCB->currentText() == "hardware")
//			mySerialPort->setFlowControl(QSerialPort::HardwareControl);
//		else if (FlowCtrlCB->currentText() == "xonxoff")
//			mySerialPort->setFlowControl(QSerialPort::SoftwareControl);
//		if (FlowCtrlCnt) {
//			statusBar()->showMessage("FlowCtrl set successfully", 2000);
//		}
//		++FlowCtrlCnt;
//	}
//}
//
//void SerialPortSetting::resetCnt()
//{
//	BaudCnt = 0;
//	ParityCnt = 0;
//	DataBitsCnt = 0;
//	StopBitsCnt = 0;
//	FlowCtrlCnt = 0;
//}
//
////打开和关闭串口
//void SerialPortSetting::on_connectButton_toggled(bool checked)
//{
//	if (checked == true) {
//		mySerialPort = new QSerialPort(this);
//		QString tempStr = COMCB->currentText();
//		tempStr.remove("  avail", Qt::CaseSensitive);
//		mySerialPort->setPortName(tempStr);
//		if (mySerialPort->open(QIODevice::ReadWrite)) {
//			portIsOpen = true;
//			emit setBaudRate();
//			emit setParity();
//			emit setDataBits();
//			emit setStopBits();
//			emit setFlowCtrl();
//			statusBar()->showMessage(mySerialPort->portName() + " is opened", 2000);
//			emit setComLabel();
//			emit enabledSendButton();
//			emit enabledAutoSend();
//			COMCB->setEnabled(false);
//			connect(Timer_CP, SIGNAL(timeout()), this, SLOT(checkPort()));
//			Timer_CP->start(1000);
//			connect(mySerialPort, SIGNAL(readyRead()), this, SLOT(readMyCom()));
//			connectButton->setText(QString::fromLocal8Bit("关闭连接"));
//			connectButton->setIcon(QIcon(":/images/close.png"));
//		}
//		else {
//			QMessageBox::warning(this,
//				QString::fromLocal8Bit("串口打开失败"),
//				QString::fromLocal8Bit("串口不存在或本串口"
//					"已经被占用，请重试！"),
//				QMessageBox::Cancel);
//			connectButton->setChecked(false);
//			return;
//		}
//	}
//	else  if (checked == false) {
//		if (Timer_AS->isActive()) {
//			Timer_AS->stop();
//			emit resetAutoSendCB();
//		}
//		if (Timer_CP->isActive()) Timer_CP->stop();
//		Timer_CP->disconnect();
//		if (mySerialPort->isOpen()) mySerialPort->close();
//		emit disabledSendButton();
//		emit disabledAutoButton();
//		emit setComLabel();
//		emit setBaudLabel();
//		resetCnt();
//		COMCB->setEnabled(true);
//		connectButton->setText(QString::fromLocal8Bit("打开连接"));
//		connectButton->setIcon(QIcon(":/images/open.png"));
//		portIsOpen = false;
//	}
//}
//
////设置显示串口号和波特率的Label
//void SerialPortSetting::setComLabel()
//{
//	if (mySerialPort->isOpen()) {
//		comLabel->setText(QString(mySerialPort->portName()));
//	}
//	else if (!mySerialPort->isOpen()) {
//		comLabel->setText(QString::fromLocal8Bit("COM：#"));
//	}
//}
//
//void SerialPortSetting::setBaudLabel()
//{
//	if (mySerialPort->isOpen()) {
//		int i_baud = mySerialPort->baudRate();
//		QString s_baud;
//		baudLabel->setText(s_baud.setNum(i_baud));
//	}
//	else if (!mySerialPort->isOpen()) {
//		baudLabel->setText(QString::fromLocal8Bit("BAUD：#"));
//	}
//}
//
//void SerialPortSetting::writeToBuf()
//{
//	QObject *signalSender = sender();
//	if (signalSender->objectName() == "sendButton_1") {
//		if (hexRB_1->isChecked()) {
//			writeHex(senderTextEdit_1);
//		}
//		else {
//			writeChr(senderTextEdit_1);
//		}
//	}
//	else if (signalSender->objectName() == "sendButton_2") {
//		if (hexRB_2->isChecked()) {
//			writeHex(senderTextEdit_2);
//		}
//		else {
//			writeChr(senderTextEdit_2);
//		}
//	}
//	else if (signalSender->objectName() == "sendButton_3") {
//		if (hexRB_3->isChecked()) {
//			writeHex(senderTextEdit_3);
//		}
//		else {
//			writeChr(senderTextEdit_3);
//		}
//	}
//	else if (signalSender->objectName() == "sendButton_4") {
//		if (hexRB_4->isChecked()) {
//			writeHex(senderTextEdit_4);
//		}
//		else {
//			writeChr(senderTextEdit_4);
//		}
//	}
//	else if (signalSender->objectName() == "sendButton_5") {
//		if (hexRB_5->isChecked()) {
//			writeHex(senderTextEdit_5);
//		}
//		else {
//			writeChr(senderTextEdit_5);
//		}
//	}
//}
//
//void SerialPortSetting::writeHex(QTextEdit *textEdit)
//{
//	QString dataStr = textEdit->toPlainText();
//	//如果发送的数据个数为奇数的，则在前面最后落单的字符前添加一个字符0
//	if (dataStr.length() % 2) {
//		dataStr.insert(dataStr.length() - 1, '0');
//	}
//	QByteArray sendData;
//	StringToHex(dataStr, sendData);
//	mySerialPort->write(sendData);
//	RxLCD->display(RxLCD->value() + sendData.size());
//}
//
//void SerialPortSetting::writeChr(QTextEdit *textEdit)
//{
//	QByteArray sendData = textEdit->toPlainText().toUtf8();
//	if (!sendData.isEmpty() && !sendData.isNull()) {
//		mySerialPort->write(sendData);
//	}
//	RxLCD->display(RxLCD->value() + sendData.size());
//}
//
//void SerialPortSetting::StringToHex(QString str, QByteArray &senddata) //字符串转换为十六进制数据0-F
//{
//	int hexdata, lowhexdata;
//	int hexdatalen = 0;
//	int len = str.length();
//	senddata.resize(len / 2);
//	char lstr, hstr;
//	for (int i = 0; i < len; ) {
//		hstr = str[i].toLatin1();
//		if (hstr == ' ') {
//			++i;
//			continue;
//		}
//		++i;
//		if (i >= len) break;
//		lstr = str[i].toLatin1();
//		hexdata = ConvertHexChar(hstr);
//		lowhexdata = ConvertHexChar(lstr);
//		if ((hexdata == 16) || (lowhexdata == 16))
//			break;
//		else
//			hexdata = hexdata * 16 + lowhexdata;
//		++i;
//		senddata[hexdatalen] = (char)hexdata;
//		++hexdatalen;
//	}
//	senddata.resize(hexdatalen);
//}
//
//char SerialPortSetting::ConvertHexChar(char ch)
//{
//	if ((ch >= '0') && (ch <= '9'))
//		return ch - 0x30;
//	else if ((ch >= 'A') && (ch <= 'F'))
//		return ch - 'A' + 10;
//	else if ((ch >= 'a') && (ch <= 'f'))
//		return ch - 'a' + 10;
//	else return ch - ch;
//}
//
//void SerialPortSetting::enabledSendButton()
//{
//	sendButton_1->setEnabled(true);
//	sendButton_2->setEnabled(true);
//	sendButton_3->setEnabled(true);
//	sendButton_4->setEnabled(true);
//	sendButton_5->setEnabled(true);
//}
//
//void SerialPortSetting::disabledSendButton()
//{
//	sendButton_1->setEnabled(false);
//	sendButton_2->setEnabled(false);
//	sendButton_3->setEnabled(false);
//	sendButton_4->setEnabled(false);
//	sendButton_5->setEnabled(false);
//}
//
//void SerialPortSetting::startAutoSend(QPushButton *sendButton)
//{
//	connect(Timer_AS, SIGNAL(timeout()), sendButton, SIGNAL(clicked()));
//	QString interval;
//	if (sendButton->objectName() == "sendButton_1") {
//		disabledSendButton();
//		Timer_AS->start(intervalSB_1->value());
//		statusBar()->showMessage(QString::fromLocal8Bit("每 ") + interval.setNum(intervalSB_1->value()) + QString::fromLocal8Bit("ms 自动发送一次"), 2000);
//	}
//	else if (sendButton->objectName() == "sendButton_2") {
//		disabledSendButton();
//		Timer_AS->start(intervalSB_2->value());
//		statusBar()->showMessage(QString::fromLocal8Bit("每 ") + interval.setNum(intervalSB_2->value()) + QString::fromLocal8Bit("ms 自动发送一次"), 2000);
//	}
//	else if (sendButton->objectName() == "sendButton_3") {
//		disabledSendButton();
//		Timer_AS->start(intervalSB_3->value());
//		statusBar()->showMessage(QString::fromLocal8Bit("每 ") + interval.setNum(intervalSB_3->value()) + QString::fromLocal8Bit("ms 自动发送一次"), 2000);
//	}
//	else if (sendButton->objectName() == "sendButton_4") {
//		disabledSendButton();
//		Timer_AS->start(intervalSB_4->value());
//		statusBar()->showMessage(QString::fromLocal8Bit("每 ") + interval.setNum(intervalSB_4->value()) + QString::fromLocal8Bit("ms 自动发送一次"), 2000);
//	}
//	else if (sendButton->objectName() == "sendButton_5") {
//		disabledSendButton();
//		Timer_AS->start(intervalSB_5->value());
//		statusBar()->showMessage(QString::fromLocal8Bit("每 ") + interval.setNum(intervalSB_5->value()) + QString::fromLocal8Bit("ms 自动发送一次"), 2000);
//	}
//}
//
//void SerialPortSetting::setConnections()
//{
//	connect(autoSendCB_1, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));
//	connect(autoSendCB_2, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));
//	connect(autoSendCB_3, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));
//	connect(autoSendCB_4, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));
//	connect(autoSendCB_5, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));
//
//	connect(actionWrite_data, SIGNAL(triggered()), this, SLOT(saveAs()));
//	connect(actionRead_data, SIGNAL(triggered()), this, SLOT(open()));
//	connect(actionChoose_file, SIGNAL(triggered()), this, SLOT(open()));
//	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
//	connect(actionAbout, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
//
//	connect(sendButton_1, SIGNAL(clicked()), this, SLOT(writeToBuf()));
//	connect(sendButton_2, SIGNAL(clicked()), this, SLOT(writeToBuf()));
//	connect(sendButton_3, SIGNAL(clicked()), this, SLOT(writeToBuf()));
//	connect(sendButton_4, SIGNAL(clicked()), this, SLOT(writeToBuf()));
//	connect(sendButton_5, SIGNAL(clicked()), this, SLOT(writeToBuf()));
//
//	connect(BAUDCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setBaudRate()));
//	connect(ParityCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setParity()));
//	connect(DataBitsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataBits()));
//	connect(StopBitsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setStopBits()));
//	connect(FlowCtrlCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setFlowCtrl()));
//}
//
//void SerialPortSetting::enabledAutoSend()
//{
//	autoSendCB_1->setEnabled(true);
//	autoSendCB_2->setEnabled(true);
//	autoSendCB_3->setEnabled(true);
//	autoSendCB_4->setEnabled(true);
//	autoSendCB_5->setEnabled(true);
//}
//
//void SerialPortSetting::disabledAutoButton()
//{
//	autoSendCB_1->setEnabled(false);
//	autoSendCB_2->setEnabled(false);
//	autoSendCB_3->setEnabled(false);
//	autoSendCB_4->setEnabled(false);
//	autoSendCB_5->setEnabled(false);
//}
//
//
//
//void SerialPortSetting::resetAutoSendCB()
//{
//	autoSendCB_1->setChecked(false);
//	autoSendCB_2->setChecked(false);
//	autoSendCB_3->setChecked(false);
//	autoSendCB_4->setChecked(false);
//	autoSendCB_5->setChecked(false);
//}
//
//void SerialPortSetting::readMyCom()
//{
//	QByteArray temp = mySerialPort->readAll();
//	QString buf;
//
//	if (actionAlways_show->isChecked()) {
//		if (!temp.isEmpty()) {
//			if (chrReceive->isChecked()) {
//				buf = temp;
//			}
//			else if (hexReceive->isChecked()) {
//				for (int i = 0; i < temp.count(); i++) {
//					QString s;
//					s.sprintf("0x%02x, ", (unsigned char)temp.at(i));
//					buf += s;
//				}
//			}
//			receiveTextBrowser->setText(receiveTextBrowser->document()->toPlainText() + buf);
//			receiveTextBrowser->moveCursor(QTextCursor::End);
//
//
//			//ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
//		}
//	}
//	TxLCD->display(TxLCD->value() + temp.size());
//}
//
////检测可用串口并在可用串口号后面加上可用标志
//void SerialPortSetting::checkAvailablePorts()
//{//找不到存在串口是不会进入到foreach内部的。。。存在不一定可用
//	foreach(const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
//		QSerialPort availablePort;
//		availablePort.setPortName(Info.portName());
//		if (availablePort.open(QIODevice::ReadWrite)) {
//			int index = COMCB->findText(Info.portName());
//			COMCB->setItemText(index, Info.portName() + "  avail");
//			COMCB->setCurrentIndex(index);
//			iVec.push_back(index);//将修改了内容的项索引添加到容器中
//			checkAPButton->setIcon(QIcon(":/images/find_it.png"));
//			availablePort.close();
//		}
//	}
//	if (iVec.size() == 0) { checkAPButton->setIcon(QIcon(":/images/find.png")); }
//	QString availPortCnt;
//	statusBar()->showMessage(availPortCnt.setNum(iVec.size()) + " available ports", 2000);
//}
////将选择串口号的checkBox重置并重新检测可用串口
//void SerialPortSetting::on_checkAPButton_clicked()
//{
//	if (!iVec.isEmpty()) {
//		for (int i = 0; i != iVec.size(); ++i) {
//			QString tempStr;
//			COMCB->setItemText(iVec[i], QString("COM") +
//				tempStr.setNum(iVec[i]));
//		}
//		COMCB->setCurrentIndex(0);
//		iVec.clear();
//	}
//	emit checkAvailablePorts();
//}
//
//void SerialPortSetting::checkPort()
//{
//	QSet<QString> portSet;
//	foreach(const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
//		portSet.insert(Info.portName());
//	}
//	if (portSet.find(mySerialPort->portName()) == portSet.end()) {
//		QMessageBox::warning(this,
//			QString::fromLocal8Bit("Application error"),
//			QString::fromLocal8Bit("Fail with the following error : \n串口访问失败\n\nPort:%1")
//			.arg(mySerialPort->portName()),
//			QMessageBox::Close);
//		emit on_connectButton_toggled(false);
//	}
//}
//
//void SerialPortSetting::on_resetCntButton_clicked()
//{
//	RxLCD->display(0);
//	TxLCD->display(0);
//}
//
//void SerialPortSetting::on_exitButton_clicked()
//{
//	qApp->quit();
//}
////另存为
//bool SerialPortSetting::saveAs()
//{
//	QString fileName = QFileDialog::getSaveFileName(this,
//		tr("Save Data"), ".",
//		tr("Text File (*.txt)"));
//	if (fileName.isEmpty()) {
//		return false;
//	}
//	return saveFile(fileName);
//}
////保存文件
//bool SerialPortSetting::saveFile(const QString &fileName)
//{
//	if (!writeFile(fileName)) {
//		statusBar()->showMessage(tr("Saving canceled"), 2000);
//		return false;
//	}
//	statusBar()->showMessage(tr("Data saved"), 2000);
//	return true;
//}
//
//bool SerialPortSetting::writeFile(const QString &fileName)
//{
//	QFile file(fileName);
//	if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
//		QMessageBox::warning(this, tr("Save Data"),
//			tr("Cannot write file %1 : \n%2")
//			.arg(file.fileName())
//			.arg(file.errorString()));
//		return false;
//	}
//	QTextStream out(&file);
//	out << receiveTextBrowser->toPlainText();
//	return true;
//}
//
////打开文件的函数
//void SerialPortSetting::open()
//{
//	QString fileName = QFileDialog::getOpenFileName(this,
//		tr("Choose Text File"), ".",
//		tr("Text File (*.txt)"));
//	if (!fileName.isEmpty()) {
//		loadFile(fileName);
//	}
//}
////加载文件
//bool SerialPortSetting::loadFile(const QString &fileName)
//{
//	if (!readFile(fileName)) {
//		statusBar()->showMessage(tr("Loading canceled"), 2000);
//		return false;
//	}
//	statusBar()->showMessage(tr("Data loaded"), 2000);
//	return true;
//}
////读取文件
//bool SerialPortSetting::readFile(const QString &fileName)
//{
//	QFile file(fileName);
//	if (!file.open(QIODevice::ReadOnly)) {
//		QMessageBox::warning(this, tr("Read failed"),
//			tr("Cannot read file %1 : \n%2.")
//			.arg(file.fileName())
//			.arg(file.errorString()));
//		return false;
//	}
//	QTextStream in(&file);
//	QObject *signalSender = sender();
//	if (signalSender->objectName() == "actionRead_data") {
//		receiveTextBrowser->setText(in.readAll());
//	}
//	else if (signalSender->objectName() == "actionChoose_file") {
//		senderTextEdit_1->setText(in.readAll());
//	}
//	return true;
//}
//
//void SerialPortSetting::dragEnterEvent(QDragEnterEvent *event)
//{
//	if (event->mimeData()->hasFormat("text/uri-list"))
//		event->acceptProposedAction();
//}
//
//void SerialPortSetting::dropEvent(QDropEvent *event)
//{
//	QList<QUrl> urls = event->mimeData()->urls();
//	if (urls.isEmpty())
//		return;
//	QString fileName = urls.first().toLocalFile();
//	if (fileName.isEmpty()) {
//		return;
//	}
//	loadFile(fileName);
//}