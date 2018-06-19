#include "QtControl.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>
#include <QAction>
#include "define.h"
#include "Qtxqm.h"
#include "QGetWidget.h"
QtControl::QtControl(QWidget *parent)
	: QWidget(parent)
{

	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint );
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	//this->setFixedSize(1024, 768);
	parentWidget = parent;
	connect(btn_get, SIGNAL(clicked()), this, SLOT(on_slot_Get()));
	connect(btn_save, SIGNAL(clicked()), this, SLOT(on_slot_Save()));
	
	QPixmap midPix;
	midPix.load(":/Image/Resources/Image/logo.jpg");
	midPix=midPix.scaled(QSize(40, 40), Qt::KeepAspectRatio);
	QPixmap qrPixmap = myHelper::MakeQRPixmap(gblRuntimeData->strComputerUrl, midPix, 218);
	label_QRImage->setPixmap(qrPixmap);
	gblTxqm->Start_Receive();


}


void QtControl::on_slot_Get()
{
	this->hide();
	m_pGetWidget.reset(new QGetWidget(nullptr, WIDGET_TYPE::MSGBOX_GET));
	m_pGetWidget->showMaximized();
	int res= m_pGetWidget->exec();
	if (res == WIDGET_TYPE::MSGBOX_BACK || res == WIDGET_TYPE::MSGBOX_HOME)
	{
		m_pGetWidget->close();
		this->show();
	}
;
}
void QtControl::on_slot_Save()
{
	this->hide();
	m_pGetWidget.reset(new QGetWidget(nullptr, WIDGET_TYPE::MSGBOX_SAVE));
	m_pGetWidget->showMaximized();
	int res = m_pGetWidget->exec();
	if (res == WIDGET_TYPE::MSGBOX_BACK || res == WIDGET_TYPE::MSGBOX_HOME)
	{
		m_pGetWidget->close();
		this->show();
	}

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
