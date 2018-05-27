#include "QtControl.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>
#include <QAction>
#include "define.h"
QtControl::QtControl(QWidget *parent)
	: QWidget(parent)
{

	this->setupUi(this);

//	initPort();
	parentWidget = parent;
	//InitkeyBoardDlg();
	show();
	//disPlayKeyBoard();

	connect(btn_get, SIGNAL(clicked()), this, SLOT(on_slot_Get()));
	connect(btn_setting, SIGNAL(clicked()), this, SLOT(on_slot_setting()));

	QPixmap midPix;
	QPixmap qrPixmap = myHelper::MakeQRPixmap("test", midPix, 100);

	label_QRImage->setPixmap(qrPixmap);

}
/****************************串口初始化*****************************/
void QtControl::initPort()
{
	//LOG_WARN("initPort","");
	//读取串口信息
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		qDebug() << "Name:" << info.portName();
		qDebug() << "Description:" << info.description();
		qDebug() << "Manufacturer:" << info.manufacturer();

		//这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
		QSerialPort serial;
		serial.setPort(info);
		if (serial.open(QIODevice::ReadWrite))
		{
			//将串口号添加到cmb
			//ui->cmbPortName->addItem(info.portName());

			//关闭串口等待人为(打开串口按钮)打开
			serial.close();
		}
	}

	QStringList baudList;//波特率
	QStringList parityList;//校验位
	QStringList dataBitsList;//数据位
	QStringList stopBitsList;//停止位

	baudList << "50" << "75" << "100" << "134" << "150" << "200" << "300"
		<< "600" << "1200" << "1800" << "2400" << "4800" << "9600"
		<< "14400" << "19200" << "38400" << "56000" << "57600"
		<< "76800" << "115200" << "128000" << "256000";

	//ui->cmbBaudRate->addItems(baudList);
	//ui->cmbBaudRate->setCurrentIndex(12);

	parityList << "无" << "奇" << "偶";
	parityList << "标志";
	parityList << "空格";

	//ui->cmbParity->addItems(parityList);
	//ui->cmbParity->setCurrentIndex(0);

	//dataBitsList << "5" << "6" << "7" << "8";
	//ui->cmbDataBits->addItems(dataBitsList);
	//ui->cmbDataBits->setCurrentIndex(3);

	stopBitsList << "1";
	stopBitsList << "1.5";
	stopBitsList << "2";

	//ui->cmbStopBits->addItems(stopBitsList);
//	ui->cmbStopBits->setCurrentIndex(0);

	//设置按钮可以被按下
	//ui->btnOpen->setCheckable(true);
}


void QtControl::InitkeyBoardDlg()
{
	keyBoardDlg = new KeyBoard();
	keyBoardDlg->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	connect(keyBoardDlg, SIGNAL(setvalue(QString)), this, SLOT(displayInputContent(QString)));
}

void QtControl::disPlayKeyBoard()
{
	keyBoardDlg->move(this->pos().x(), this->y() + this->frameGeometry().height());
	keyBoardDlg->show();

}
void QtControl::on_slot_Get()
{
	m_pNumKeyWidget.reset(new NumKeyBoard);
	m_pNumKeyWidget->showMaximized();
	this->hide();
}
void QtControl::on_slot_setting()
{
	m_pfrmWidget.reset(new frmComTool);
	m_pfrmWidget->showMaximized();
	this->hide();
}
void QtControl::displayInputContent(QString text)
{
	qDebug() << "TextEdit::displayInputContent";

}
