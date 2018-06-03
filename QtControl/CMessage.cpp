#include "CMessage.h"
#include <QTimer>
CMessage::CMessage(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	connect(btn_OK, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
	
	pMove = new QMovie(":/Image/Resources/Image/hourglass.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	nTime = 30;

}

CMessage::~CMessage()
{
}
void CMessage::Init(MSGBOX_TYPE types)
{
	widget_timer->hide();
	btn_back->hide();
	btn_home->hide();
	if (types & MSGBOX_WAITSAVE)
	{
		label_title->setText("箱门已打开，\n请放置物品后，按确认键进行存件");
		btn_back->show();
		btn_home->show();
	}
	if (types & MSGBOX_WAITGET)
	{
		label_title->setText("箱门已打开，请取出快件");
		btn_back->show();
		btn_home->show();
	}
	if (types & MSGBOX_SAVEEND)
	{
		label_title->setText("存件已完成");
		QTimer::singleShot(1000, this, SLOT(on_slot_timeout()));
		widget_timer->show();
	}
	if (types & MSGBOX_GETEND)
	{
		label_title->setText("取件已完成");
		QTimer::singleShot(1000 , this, SLOT(on_slot_timeout()));
		widget_timer->show();	
	}



}

int CMessage::WaitSave(QWidget * parent)
{
	CMessage      pMsg;
	pMsg.Init(MSGBOX_TYPE::MSGBOX_WAITSAVE);
	pMsg.showMaximized();
	return pMsg.exec();
}

int CMessage::WaitGet(QWidget * parent)
{
	CMessage      pMsg;
	pMsg.Init(MSGBOX_TYPE::MSGBOX_WAITGET);
	pMsg.showMaximized();
	return pMsg.exec();
}

int CMessage::SaveEnd(QWidget * parent)
{
	CMessage      pMsg;
	pMsg.Init(MSGBOX_TYPE::MSGBOX_SAVEEND);
	pMsg.showMaximized();
	return pMsg.exec();
}

int CMessage::GetEnd(QWidget * parent)
{
	CMessage      pMsg;
	pMsg.Init(MSGBOX_TYPE::MSGBOX_GETEND);
	pMsg.showMaximized();
	return pMsg.exec();
}



void CMessage::on_btnBack_clicked()
{
	done(MSGBOX_BACK);
}
void CMessage::on_btnHome_clicked()
{
	done(MSGBOX_HOME);

}

void CMessage::on_btnOk_clicked()
{
	done(MSGBOX_OK);

}

void CMessage::on_slot_timeout()
{


	nTime = nTime - 1;
	if (nTime >1)
	{
		QString strLabel = QString("%1S").arg(nTime);
		label_timer->setText(strLabel);
		QTimer::singleShot(1000, this, SLOT(on_slot_timeout()));
	}
	else
	{
		done(0);
	}

}