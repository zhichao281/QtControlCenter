#include "CMessage.h"
#include <QTimer>
CMessage::CMessage(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	connect(btn_OK, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
	connect(btn_return, SIGNAL(clicked()), this, SLOT(on_btnReturn_clicked()));



	pMove = new QMovie(":/Image/Resources/Image/time.gif");
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
	widget_return->hide();
	widget_hide->hide();
	widget_hide_2->hide();
	if (types & MSGBOX_WAITSAVE)
	{
		label_title->setStyleSheet("min-width:834px;"
			"max-width:834px;"
			"min-height:72px;"
			"max-height:72px;"
			"border-image: url(:/Image/Resources/Image/箱门已打开，请及时放置物件！.png);");
		btn_back->show();
		btn_home->show();
		widget_timer->show();

	}
	if (types & MSGBOX_WAITGET)
	{
		label_title->setStyleSheet("min-width:710px;"
			"max-width:710px;"
			"min-height:72px;"
			"max-height:72px;"
			"border-image: url(:/Image/Resources/Image/箱门已打开，请及时取件！.png);");
		btn_back->show();
		btn_home->show();
		widget_timer->show();
	}
	if (types & MSGBOX_SAVEEND)
	{
		label_title->setStyleSheet("min-width:341px;"
									"max-width:341px;"
									"min-height:71px;"
									"max-height:71px;"
									"border-image: url(:/Image/Resources/Image/存件已完成！.png);");
		QTimer::singleShot(1000*30, this, SLOT(on_slot_timeout()));
		widget_timer->show();

	}
	if (types & MSGBOX_GETEND)
	{
		label_title->setStyleSheet("min-width:339px;"
			"max-width:339;"
			"min-height:71px;"
			"max-height:71px;"
			"border-image: url(:/Image/Resources/Image/取件已完成！.png);");
		QTimer::singleShot(1000 *30, this, SLOT(on_slot_timeout()));
		//widget_timer->show();	
		widget_return->show();
		widget_hide->show();
		widget_hide_2->show();

		//取完东西  送回去托盘
		gblPortControl->SuckTray();
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
		//QTimer::singleShot(1000, this, SLOT(on_slot_timeout()));
	}
	else
	{
		//done(0);
	}

}
void CMessage::on_btnReturn_clicked() {

	done(MSGBOX_RETURN);
	
}
